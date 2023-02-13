#include <Windows.h>
#include<iostream>
#include "application/application.h"
#include "gpu/gpu.h"

#pragma comment(linker, "/subsystem:console /entry:wWinMainCRTStartup" )

/*
* 1 GDI ���ƻ����
* 2 �ģ��GPU�Ĵ���ܹ�
* 3 ��Ļ���ʵ��
*/

void render() {
	sgl->clear();

	//����ֱ��,�߶ȵڶ�������
	//for (uint32_t i = 0; i < app->getWidth(); ++i) {
	//	sgl->drawPoint(i, 300, RGBA(255, 255, 255));
	//}


	//����forѭ��,����ÿ����
	for (uint32_t i = 0; i < app->getWidth(); ++i) {
		for (uint32_t j = 0; j < app->getHeight(); ++j) {

			//ÿ������ɫ���,ѩ��Ч��
			uint32_t v = std::rand() % 255;
			RGBA color(v, v, v, v);
			sgl->drawPoint(i, j, color);
		}
	}
}

int APIENTRY wWinMain(
	_In_ HINSTANCE hInstance,		//��Ӧ�ó���ʵ�������Ψһָ����ǰ����
	_In_opt_ HINSTANCE hPrevInstance,	//������ǰһ��ʵ����һ����null
	_In_ LPWSTR    lpCmdLine,		//Ӧ�ó������в���
	_In_ int       nCmdShow)		//���������ʾ����󻯡���С�������أ����������
{
	if (!app->initApplication(hInstance,800, 600)) {
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
