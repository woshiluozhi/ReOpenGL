#include "gpu.h"
#include "raster.h"

GPU* GPU::mInstance = nullptr;
GPU* GPU::getInstance() {
	if (!mInstance) {
		mInstance = new GPU();
	}

	return mInstance;
}

GPU::GPU() {}

GPU::~GPU() {
	if (mFrameBuffer) {
		delete mFrameBuffer;
	}
}

void GPU::initSurface(const uint32_t& width, const uint32_t& height, void* buffer) {
	mFrameBuffer = new FrameBuffer(width, height, buffer);
}

void GPU::clear() {
	size_t pixelSize = mFrameBuffer->mWidth * mFrameBuffer->mHeight;
	std::fill_n(mFrameBuffer->mColorBuffer, pixelSize, RGBA(0, 0, 0, 0));
}

void GPU::drawPoint(const uint32_t& x, const uint32_t& y, const RGBA& color) {
	if (x >= mFrameBuffer->mWidth || y >= mFrameBuffer->mHeight) {
		return;
	}

	//�Ӵ������½ǿ�ʼ����
	uint32_t pixelPos = y * mFrameBuffer->mWidth + x;


	RGBA result = color;

	if (mEnableBlending) {
		//����blending
		auto src = color;
		auto dst = mFrameBuffer->mColorBuffer[pixelPos];
		float weight = static_cast<float>(src.mA) / 255.0f;

		result.mR = static_cast<float>(src.mR) * weight + static_cast<float>(dst.mR) * (1.0f - weight);
		result.mG = static_cast<float>(src.mG) * weight + static_cast<float>(dst.mG) * (1.0f - weight);
		result.mB = static_cast<float>(src.mB) * weight + static_cast<float>(dst.mB) * (1.0f - weight);
		result.mA = static_cast<float>(src.mA) * weight + static_cast<float>(dst.mA) * (1.0f - weight);
	}
	

	mFrameBuffer->mColorBuffer[pixelPos] = result;
}

void GPU::drawLine(const Point& p1, const Point& p2) {
	std::vector<Point> pixels;
	Raster::rasterizeLine(pixels, p1, p2);

	for (auto& p : pixels) {
		drawPoint(p.x, p.y, p.color);
	}
}

void GPU::drawTriangle(const Point& p1, const Point& p2, const Point& p3) {
	std::vector<Point> pixels;
	Raster::rasterizeTriangle(pixels, p1, p2, p3);

	RGBA resultColor;
	for (auto &p : pixels) {
		if (mImage) {
			resultColor = sampleNearest(p.uv);
		}
		else {
			resultColor = p.color;
		}

		drawPoint(p.x, p.y, resultColor);
	}
}

void GPU::drawImage(const Image* image) {
	for (uint32_t i = 0; i < image->mWidth; ++i) {
		for (uint32_t j = 0; j < image->mHeight; ++j) {
			drawPoint(i, j, image->mData[j * image->mWidth + i]);
		}
	}
}

void GPU::drawImageWidthAlpha(const Image* image, const uint32_t& alpha) {
	RGBA color;
	for (uint32_t i = 0; i < image->mWidth; ++i) {
		for (uint32_t j = 0; j < image->mHeight; ++j) {
			color = image->mData[j * image->mWidth + i];
			color.mA = alpha;
			drawPoint(i, j, color);
		}
	}
}


//����״̬
void GPU::setBlending(bool enable) {
	mEnableBlending = enable;
}

void GPU::setTexture(Image* image) {
	mImage = image;
}

RGBA GPU::sampleNearest(const math::vec2f& uv) {
	auto myUV = uv;

	//�������뵽�������
	// u = 0 ��Ӧ x = 0��u = 1 ��Ӧ x = width - 1
	// v = 0 ��Ӧ y = 0��v = 1 ��Ӧ y = height - 1
	int x = std::round(myUV.x * (mImage->mWidth - 1));
	int y = std::round(myUV.y * (mImage->mHeight - 1));

	int position = y * mImage->mWidth + x;
	return mImage->mData[position];
}
