#pragma once
#include "../global/base.h"
#include "dataStructures.h"
#include "bufferObject.h"
#include "texture.h"

class Shader {
public:
	Shader() {}
	~Shader() {}
	virtual VsOutput vertexShader(
		//VAO���е�bindingMap
		const std::map<uint32_t, BindingDescription>& bindingMap,

		//VBO���е�bindingMap
		const std::map<uint32_t,BufferObject*>& bufferMap,

		//��ǰҪ����Ķ����index
		const uint32_t& index
	) = 0;

	virtual void fragmentShader(const VsOutput& input, FsOutput& output, const std::map<uint32_t, Texture*>& textures) = 0;

	//tool functions
public:
	//��Ҫ�ȿ���VertexShader���������ʹ�ã��ٿ��߼�
	math::vec4f getVector(
		const std::map<uint32_t, BindingDescription>& bindingMap,
		const std::map<uint32_t, BufferObject*>& bufferMap,
		const uint32_t& attributeLocation,//��ǰ���Եı��
		const uint32_t& index);//��ǰ������

	RGBA vectorToRGBA(const math::vec4f& v) {
		RGBA color;
		color.mR = v.x * 255.0;
		color.mG = v.y * 255.0;
		color.mB = v.z * 255.0;
		color.mA = v.w * 255.0;

		return color;
	}
};
