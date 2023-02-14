#include <Windows.h>
#include<iostream>
#include "application/application.h"
#include "gpu/gpu.h"

#pragma comment(linker, "/subsystem:console /entry:wWinMainCRTStartup" )

/*
* �γ����ݽ��ܣ�
* ����uvϵͳʵ�ִ���
*/
Image* texture;
Point p1;
Point p2;
Point p3;

void render() {
	sgl->clear();
	sgl->setTexture(texture);
	sgl->drawTriangle(p1, p2, p3);
}

void prepare() {
	texture = Image::createImage("assets/textures/goku.jpg");

	//p1.x = 0;
	//p1.y = 0;
	//p1.color = RGBA(255, 0, 0, 255);
	//p1.uv = math::vec2f(0.0f, 0.0f);

	//p2.x = 200;
	//p2.y = 300;
	//p2.color = RGBA(0, 255, 0, 255);
	//p2.uv = math::vec2f(0.5f, 1.0f);

	//p3.x = 400;
	//p3.y = 0;
	//p3.color = RGBA(0, 0, 255, 255);
	//p3.uv = math::vec2f(1.0f, 0.0f);

	p1.x = 0;
	p1.y = 0;
	p1.color = RGBA(255, 0, 0, 255);
	p1.uv = math::vec2f(0.0f, 0.0f);

	p2.x = 400;
	p2.y = 900;
	p2.color = RGBA(0, 255, 0, 255);
	p2.uv = math::vec2f(0.5f, 1.0f);

	p3.x = 800;
	p3.y = 0;
	p3.color = RGBA(0, 0, 255, 255);
	p3.uv = math::vec2f(1.0f, 0.0f);
}

int APIENTRY wWinMain(
	_In_ HINSTANCE hInstance,		//��Ӧ�ó���ʵ�������Ψһָ����ǰ����
	_In_opt_ HINSTANCE hPrevInstance,	//������ǰһ��ʵ����һ����null
	_In_ LPWSTR    lpCmdLine,		//Ӧ�ó������в���
	_In_ int       nCmdShow)		//���������ʾ����󻯡���С�������أ����������
{
	if (!app->initApplication(hInstance, 1024, 960)) {
		return -1;
	}

	//��bmpָ����ڴ����õ�sgl���� 
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
