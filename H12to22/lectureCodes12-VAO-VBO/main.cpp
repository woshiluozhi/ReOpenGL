#include <Windows.h>
#include<iostream>
#include "application/application.h"
#include "gpu/gpu.h"
#include "gpu/dataStructures.h"

#pragma comment(linker, "/subsystem:console /entry:wWinMainCRTStartup" )

/*
* �γ����ݽ��ܣ�
* �����޸ģ�
* ����dataStructure�ع�
* ����math lerp����ϵͳ��
* ����VBO
* ����VAO
* ����GPU�ع�
*/
uint32_t WIDTH = 800;
uint32_t HEIGHT = 600;


void render() {
	sgl->clear();
}

uint32_t vbo = 0;
uint32_t vao = 0;

void prepare() {
	vbo = sgl->genBuffer();
	sgl->deleteBuffer(vbo);

	vao = sgl->genVertexArray();
	sgl->deleteVertexArray(vao);
}

int APIENTRY wWinMain(
	_In_ HINSTANCE hInstance,		//��Ӧ�ó���ʵ�������Ψһָ����ǰ����
	_In_opt_ HINSTANCE hPrevInstance,	//������ǰһ��ʵ����һ����null
	_In_ LPWSTR    lpCmdLine,		//Ӧ�ó������в���
	_In_ int       nCmdShow)		//���������ʾ����󻯡���С�������أ����������
{
	if (!app->initApplication(hInstance, WIDTH, HEIGHT)) {
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

	return 0;
}
