#pragma once
#include "../global/base.h"
#include "frameBuffer.h"
#include "../application/application.h"
#include "../application/image.h"
#include "../math/math.h"
#include "dataStructures.h"

#define sgl GPU::getInstance()

/*
* class GPU��
* ģ��GPU�Ļ�ͼ��Ϊ�Լ��㷨��
*/
class GPU {
public:
	static GPU* getInstance();
	GPU();

	~GPU();

	//������紫���bmp��Ӧ���ڴ�ָ���Լ�����Ŀ�/��
	void initSurface(const uint32_t& width, const uint32_t& height, void* buffer = nullptr);

	//�����������
	void clear();

	//��������λ�ã����Ƴ�ĳ����ɫ
	void drawPoint(const uint32_t& x, const uint32_t& y, const RGBA& color);

	void drawLine(const Point& p1, const Point& p2);

	void drawTriangle(const Point& p1, const Point& p2, const Point& p3);

	void drawImage(const Image* image);

	void drawImageWidthAlpha(const Image* image, const uint32_t& alpha);

	//����״̬
	void setBlending(bool enable);

	void setBilinear(bool enable);

	void setTexture(Image* image);

	void setTextureWrap(uint32_t wrap);

private:
	RGBA sampleNearest(const math::vec2f& uv);
	RGBA sampleBilinear(const math::vec2f& uv);
	void checkWrap(float& n);

private:
	static GPU* mInstance;

	bool mEnableBlending{ false };
	bool mEnableBilinear{ false };
	uint32_t mWrap{ TEXTURE_WRAP_REPEAT };

	FrameBuffer* mFrameBuffer{ nullptr };

	//������ͼ
	Image* mImage{ nullptr };
};