#pragma once
#include "../global/base.h"
#include "frameBuffer.h"
#include "../application/application.h"

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

private:
	static GPU* mInstance;

	FrameBuffer* mFrameBuffer{ nullptr };
};