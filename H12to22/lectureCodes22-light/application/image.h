#pragma once
#include "../global/base.h"

class Image {
public:
	Image(const uint32_t& width = 0, const uint32_t& height = 0, RGBA* data = nullptr);
	~Image();

	static Image* createImage(const std::string& path);
	static void destroyImage(Image* image);
	
public:
	uint32_t mWidth{ 0 };
	uint32_t mHeight{ 0 };
	RGBA* mData{ nullptr };
};