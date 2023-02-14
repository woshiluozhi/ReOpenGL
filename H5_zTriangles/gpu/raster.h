#pragma once
#include "../global/base.h"

/*
* class Raster
* 对外提供静态函数接口，传入离散的图元点，返回光栅化后的像素数组
*/
class Raster {
public:
	Raster();
	~Raster();

	//离散线条
	static void rasterizeLine(
		std::vector<Point>& results,
		const Point& v0,
		const Point& v1
	);

	static void interpolantLine(const Point& v0, const Point& v1, Point& target);

	//离散三角形
	static void rasterizeTriangle(
		std::vector<Point>& results,
		const Point& v0,
		const Point& v1,
		const Point& v2
	);

	//三角形插值
	static void interpolantTriangle(const Point& v0, const Point& v1, const Point& v2, Point& p);
};