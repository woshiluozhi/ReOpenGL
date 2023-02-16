#include "lightShader.h"


LightShader::LightShader() {}
LightShader::~LightShader() {}

VsOutput LightShader::vertexShader(
	const std::map<uint32_t, BindingDescription>& bindingMap,
	const std::map<uint32_t, BufferObject*>& bufferMap,
	const uint32_t& index
) {
	VsOutput output;

	//ȡ��Attribute��ֵ
	math::vec4f position = getVector(bindingMap, bufferMap, 0, index);

	//�仯Ϊ������� 
	position.w = 1.0f;
	//math::vec4f color = getVector(bindingMap, bufferMap, 1, index);

	math::vec3f normal = getVector(bindingMap, bufferMap, 1, index);

	math::vec2f uv = getVector(bindingMap, bufferMap, 2, index);

	output.mPosition = mProjectionMatrix * mViewMatrix * mModelMatrix * position;
	output.mNormal = normal;
	output.mUV = uv;

	return output;
}

void LightShader::fragmentShader(const VsOutput& input, FsOutput& output, const std::map<uint32_t, Texture*>& textures) {
	output.mPixelPos.x = static_cast<int>(input.mPosition.x);
	output.mPixelPos.y = static_cast<int>(input.mPosition.y);
	output.mDepth = input.mPosition.z;

	//ȡ������
	auto normal = math::normalize(input.mNormal);
	auto lightDirection = math::normalize(mDirectionalLight.direction);

	//ȡ��texture
	auto iter = textures.find(mDiffuseTexture);
	Texture* texture = nullptr;
	if (iter != textures.end()) {
		texture = iter->second;
	}

	//������ɫ
	math::vec4f texColor = {1.0f, 1.0f, 1.0f, 1.0f};
	if (texture) {
		texColor = texture->getColor(input.mUV.x, input.mUV.y);
	}

	//�����������
	math::vec4f  diffuseColor;
	float diff = math::dot(normal, -lightDirection);
	diff = std::clamp(diff, 0.0f, 1.0f);
	diffuseColor = texColor * diff * math::vec4f(mDirectionalLight.color, 1.0f);

	//���㻷����
	math::vec4f  envColor; 
	envColor = texColor * math::vec4f(mEnvLight, 1.0f);

	output.mColor = vectorToRGBA(diffuseColor + envColor);
}