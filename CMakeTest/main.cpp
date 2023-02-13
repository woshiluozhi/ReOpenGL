#include "funcs/ADD.h"

//linker is a way to use windows or console
//console是CMD,windows是窗体. wWinMainCRTStartup走wWinMain,mainCRTStartup走main路线
//#pragma comment(linker, "/subsystem:windows /entry:mainCRTStartup" )
//#pragma comment(linker, "/subsystem:windows /entry:wWinMainCRTStartup" )
//#pragma comment(linker, "/subsystem:console /entry:wWinMainCRTStartup" )
#pragma comment(linker, "/subsystem:console /entry:mainCRTStartup" )


int APIENTRY wWinMain(
	_In_ HINSTANCE hInstance, //本应用程序实例句柄，唯一指代当前程序
	_In_opt_ HINSTANCE hPrevInstance, //本程序前一个实例，一般是null
	_In_ LPWSTR lpCmdLine, //应用程序运行参数
	_In_ int nCmdShow) //窗口如何显示（最大化、最小化、隐藏），不需理会
{
	return 0;
}

int main()
{
	cout << "hello, world" << endl;
	cout << add(1, 99) << endl;
	return 0;
}