#include <Windows.h>
#include<iostream>
#include "application/application.h"
#include "gpu/gpu.h"

#pragma comment(linker, "/subsystem:console /entry:wWinMainCRTStartup" )

/*
* 1 ͼƬ��ȡ����
* 2 ͼƬ��ʾ����
* 3 ͼƬ͸������
*/
Image* image01 = Image::createImage("assets/textures/me.png");
Image* image02 = Image::createImage("assets/textures/goku.jpg");
void render() {
	sgl->clear();

	//����ͼƬ
	//sgl->drawImage(image01);

	//����ƵĻḲ��ǰ���
	//sgl->drawImage(image02);
	//sgl->drawImage(image01);

	//���û��
	sgl->setBlending(true);
	//�����
	sgl->drawImage(image02);
	//������image01,��Ե��alphaֵΪ��,͸��.
	sgl->drawImage(image01);

	//����alpha
	//sgl->setBlending(true);
	//sgl->drawImage(image02);
	//sgl->drawImageWidthAlpha(image01, 122);
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
