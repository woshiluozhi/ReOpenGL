#pragma once
#include "../global/base.h"
#include<Windows.h>

#define app Application::getInstance()

class Application {
public:
	static Application* getInstance();
	Application();
	~Application();

	//ע�ᴰ���࣬����һ�����壬��ʾ
	bool initApplication(HINSTANCE hInstance, const uint32_t& width = 800, const uint32_t& height = 600);

	//�й���wndProc�������Ϣ�����ҽ��д���
	void handleMessage(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	//ÿһ֡/ÿһ��ѭ����������ã������Լ��ַ�������Ϣ
	bool peekMessage();

private:
	BOOL createWindow(HINSTANCE hInstance);
	ATOM registerWindowClass(HINSTANCE hInstance);

private:
	static Application* mInstance;

	//Ϊtrue��ʾ��ǰ������Ȼ�ڼ�����ʾ������һֱ����
	//Ϊfalse��ʾ�����Ѿ�������رգ�������Ҫ�˳�
	bool		mAlive{ true };

	HINSTANCE	mWindowInst;
	WCHAR		mWindowClassName[100] = L"AppWindow";
	HWND		mHwnd;

	int			mWidth = 800;
	int			mHeight = 600;
};
