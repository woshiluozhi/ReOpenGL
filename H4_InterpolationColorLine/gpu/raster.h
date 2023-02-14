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

	static void rasterizeLine(
		std::vector<Point>& results,
		const Point& v0,
		const Point& v1
	);

	//���v0,�յ�v1,
	static void interpolantLine(const Point& v0, const Point& v1, Point& target);
};