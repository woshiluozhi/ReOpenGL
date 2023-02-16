#include "defaultShader.h"


DefaultShader::DefaultShader() {}
DefaultShader::~DefaultShader() {}

VsOutput DefaultShader::vertexShader(
	const std::map<uint32_t, BindingDescription>& bindingMap,
	const std::map<uint32_t, BufferObject*>& bufferMap,
	const uint32_t& index
) {
	VsOutput output;

	//ȡ��Attribute��ֵ
	math::vec4f position = getVector(bindingMap, bufferMap, 0, index);

	//�仯Ϊ������� 
	position.w = 1.0f;
	math::vec4f color = getVector(bindingMap, bufferMap, 1, index);

	math::vec2f uv = getVector(bindingMap, bufferMap, 2, index);

	output.mPosition = mProjectionMatrix * mViewMatrix * mModelMatrix * position;
	output.mColor = color;
	output.mUV = uv;

	return output;
}

void DefaultShader::fragmentShader(const VsOutput& input, FsOutput& output, const std::map<uint32_t, Texture*>& textures) {
	output.mPixelPos.x = static_cast<int>(input.mPosition.x);
	output.mPixelPos.y = static_cast<int>(input.mPosition.y);
	output.mDepth = input.mPosition.z;
	output.mColor = vectorToRGBA(input.mColor);
}
