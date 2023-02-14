#pragma once
#include "../global/base.h"

/*
* class Raster
* �����ṩ��̬�����ӿڣ�������ɢ��ͼԪ�㣬���ع�դ�������������
*/
class Raster {
public:
	Raster();
	~Raster();

	//��ɢ����
	static void rasterizeLine(
		std::vector<Point>& results,
		const Point& v0,
		const Point& v1
	);

	static void interpolantLine(const Point& v0, const Point& v1, Point& target);

	//��ɢ������
	static void rasterizeTriangle(
		std::vector<Point>& results,
		const Point& v0,
		const Point& v1,
		const Point& v2
	);

	//�����β�ֵ
	static void interpolantTriangle(const Point& v0, const Point& v1, const Point& v2, Point& p);
};