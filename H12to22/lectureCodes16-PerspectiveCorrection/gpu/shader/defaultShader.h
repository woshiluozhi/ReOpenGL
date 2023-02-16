#pragma once
#include "../shader.h"
#include "../../math/math.h"

class DefaultShader:public Shader {
public:
	DefaultShader();
	~DefaultShader();

	VsOutput vertexShader(
		const std::map<uint32_t, BindingDescription>& bindingMap,
		const std::map<uint32_t, BufferObject*>& bufferMap,
		const uint32_t& index
	)override;

	void fragmentShader(const VsOutput& input, FsOutput& output)override;

public:
	//uniforms
	math::mat4f mModelMatrix;
	math::mat4f mViewMatrix;
	math::mat4f mProjectionMatrix;
};