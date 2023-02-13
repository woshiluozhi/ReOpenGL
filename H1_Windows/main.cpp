#include <Windows.h>
#include<iostream>
#include "application/application.h"

#pragma comment(linker, "/subsystem:console /entry:wWinMainCRTStartup" )

/*
* 1 ��ѭ��������winMain������
* 2 ���幹������Ϣ�������������ϸ�ڶ���װ��application������
*/
int APIENTRY wWinMain(
	_In_ HINSTANCE hInstance,		//��Ӧ�ó���ʵ�������Ψһָ����ǰ����
	_In_opt_ HINSTANCE hPrevInstance,	//������ǰһ��ʵ����һ����null
	_In_ LPWSTR    lpCmdLine,		//Ӧ�ó������в���
	_In_ int       nCmdShow)		//���������ʾ����󻯡���С�������أ����������
{
	if (!app->initApplication(hInstance,800, 600)) {
		return -1;
	}

	bool alive = true;
	while (alive) {
		alive = app->peekMessage();
	}

	return 0;
}
