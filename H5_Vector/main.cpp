#include <Windows.h>
#include<iostream>
#include "application/application.h"
#include "gpu/gpu.h"

#pragma comment(linker, "/subsystem:console /entry:wWinMainCRTStartup" )

/*
* �γ����ݽ��ܣ�
* ������ѧ�����������Vector����ʵ��
*/

void render() {
	sgl->clear();

	//Point p1{ 100, 100, RGBA(255, 0, 0, 255) };
	//Point p2{ 500, 600, RGBA(0, 255, 0, 255) };

	//sgl->drawLine(p1, p2);

	int r = 150;
	Point c{ 400, 300, RGBA(255, 0, 0, 255) };

	for (float i = 0; i < 360; i += 10)
	{
		float radian = DEG2RAD(i);
		int x = r * sin(radian) + c.x;
		int y = r * cos(radian) + c.y;

		Point  pt{ x, y, RGBA(rand() % 255, rand() % 255, rand() % 255, 255) };

		sgl->drawLine(c, pt);
	}
}

int APIENTRY wWinMain(
	_In_ HINSTANCE hInstance,		//��Ӧ�ó���ʵ�������Ψһָ����ǰ����
	_In_opt_ HINSTANCE hPrevInstance,	//������ǰһ��ʵ����һ����null
	_In_ LPWSTR    lpCmdLine,		//Ӧ�ó������в���
	_In_ int       nCmdShow)		//���������ʾ����󻯡���С�������أ����������
{
	if (!app->initApplication(hInstance, 800, 600)) {
		return -1;
	}

	//��bmpָ����ڴ����õ�sgl���� 
	sgl->initSurface(app->getWidth(), app->getHeight(), app->getCanvas());

	bool alive = true;
	while (alive) {
		alive = app->peekMessage();
		render();
		app->show();
	}

	return 0;
}
