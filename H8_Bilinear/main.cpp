#include <Windows.h>
#include<iostream>
#include "application/application.h"
#include "gpu/gpu.h"

#pragma comment(linker, "/subsystem:console /entry:wWinMainCRTStartup" )

/*
* 课程内容介绍：
* 讲授双线性插值代码 & lerp代码的独立
*/
Image* texture;
Point p1;
Point p2;
Point p3;

Point q1;
Point q2;
Point q3;

void render() {
	sgl->clear();
	sgl->setTexture(texture);

	//关闭双线性插值
	sgl->setBilinear(false);
	sgl->drawTriangle(p1, p2, p3);

	//开启双线性插值
	sgl->setBilinear(true);
	sgl->drawTriangle(q1, q2, q3);
}

void prepare() {
	texture = Image::createImage("assets/textures/goku.jpg");
	//三角形p
	p1.x = 0;
	p1.y = 0;
	p1.color = RGBA(255, 0, 0, 255);
	p1.uv = math::vec2f(0.0f, 0.0f);

	p2.x = 200;
	p2.y = 600;
	p2.color = RGBA(0, 255, 0, 255);
	p2.uv = math::vec2f(0.5f, 1.0f);

	p3.x = 400;
	p3.y = 0;
	p3.color = RGBA(0, 0, 255, 255);
	p3.uv = math::vec2f(1.0f, 0.0f);

	//三角形q
	q1.x = 400;
	q1.y = 0;
	q1.color = RGBA(255, 0, 0, 255);
	q1.uv = math::vec2f(0.0f, 0.0f);

	q2.x = 600;
	q2.y = 600;
	q2.color = RGBA(0, 255, 0, 255);
	q2.uv = math::vec2f(0.5f, 1.0f);

	q3.x = 800;
	q3.y = 0;
	q3.color = RGBA(0, 0, 255, 255);
	q3.uv = math::vec2f(1.0f, 0.0f);
}


int APIENTRY wWinMain(
	_In_ HINSTANCE hInstance,		//本应用程序实例句柄，唯一指代当前程序
	_In_opt_ HINSTANCE hPrevInstance,	//本程序前一个实例，一般是null
	_In_ LPWSTR    lpCmdLine,		//应用程序运行参数
	_In_ int       nCmdShow)		//窗口如何显示（最大化、最小化、隐藏），不需理会
{
	if (!app->initApplication(hInstance, 800, 600)) {
		return -1;
	}

	//将bmp指向的内存配置到sgl当中 
	sgl->initSurface(app->getWidth(), app->getHeight(), app->getCanvas());

	prepare();

	bool alive = true;
	while (alive) {
		alive = app->peekMessage();
		render();
		app->show();
	}

	Image::destroyImage(texture);

	return 0;
}
