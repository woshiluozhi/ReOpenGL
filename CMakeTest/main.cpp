#include "funcs/ADD.h"

//linker is a way to use windows or console
//console��CMD,windows�Ǵ���. wWinMainCRTStartup��wWinMain,mainCRTStartup��main·��
//#pragma comment(linker, "/subsystem:windows /entry:mainCRTStartup" )
//#pragma comment(linker, "/subsystem:windows /entry:wWinMainCRTStartup" )
//#pragma comment(linker, "/subsystem:console /entry:wWinMainCRTStartup" )
#pragma comment(linker, "/subsystem:console /entry:mainCRTStartup" )


int APIENTRY wWinMain(
	_In_ HINSTANCE hInstance, //��Ӧ�ó���ʵ�������Ψһָ����ǰ����
	_In_opt_ HINSTANCE hPrevInstance, //������ǰһ��ʵ����һ����null
	_In_ LPWSTR lpCmdLine, //Ӧ�ó������в���
	_In_ int nCmdShow) //���������ʾ����󻯡���С�������أ����������
{
	return 0;
}

int main()
{
	cout << "hello, world" << endl;
	cout << add(1, 99) << endl;
	return 0;
}