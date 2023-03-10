#include <Windows.h>
#include<iostream>
#include "application/application.h"
#include "gpu/gpu.h"

#pragma comment(linker, "/subsystem:console /entry:wWinMainCRTStartup" )

/*
* 1 图片读取代码
* 2 图片显示代码
* 3 图片透明方案
*/
Image* image01 = Image::createImage("assets/textures/me.png");
Image* image02 = Image::createImage("assets/textures/goku.jpg");
void render() {
	sgl->clear();

	//绘制图片
	//sgl->drawImage(image01);

	//后绘制的会覆盖前面的
	//sgl->drawImage(image02);
	//sgl->drawImage(image01);

	//启用混合
	sgl->setBlending(true);
	//画悟空
	sgl->drawImage(image02);
	//画人像image01,边缘的alpha值为零,透明.
	sgl->drawImage(image01);

	//启用alpha
	//sgl->setBlending(true);
	//sgl->drawImage(image02);
	//sgl->drawImageWidthAlpha(image01, 122);
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

	bool alive = true;
	while (alive) {
		alive = app->peekMessage();
		render();
		app->show();
	}

	return 0;
}
