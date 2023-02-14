#include <Windows.h>
#include<iostream>
#include "application/application.h"
#include "gpu/gpu.h"

#pragma comment(linker, "/subsystem:console /entry:wWinMainCRTStartup" )

/*
* ������ɨ���߻����㷨��ʵ��
* ���������Ĳ�ֵ��ɫ����
*/

void render() {
	sgl->clear();

	
	//Point p1{ 0, 100};
	//Point p2{ 500, 100};
	//Point p3{ 250, 500};

	//���Ĳ�ֵ
	Point p1{ 0, 100, RGBA(255, 0, 0, 255) };
	Point p2{ 500, 100, RGBA(0, 255, 0, 255) };
	Point p3{ 250, 500, RGBA(0, 0, 255, 255) };


	sgl->drawTriangle(p1, p2, p3);
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
