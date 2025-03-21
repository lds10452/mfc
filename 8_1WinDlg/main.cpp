#include <windows.h>
#include "resource.h"
HINSTANCE g_hInstance = 0;
INT CALLBACK DlgProc(HWND hwndlg, UINT msgID, WPARAM wParam, LPARAM lParam) {
	switch (msgID) {
	case WM_DESTROY:
		MessageBox(NULL, "我要死了", "Infor", MB_OK);
		break;
	case WM_SYSCOMMAND:
		if (wParam == SC_CLOSE) {
			HWND hWnd = GetParent(hwndlg);
			EnableWindow(hWnd, TRUE);//无模态转模态需要两点，第二点销毁前使能父窗口
			DestroyWindow(hwndlg);//销毁无模式对话框, 切忌不能EndDialog
//			EndDialog( hwndlg, 1001 );//只能隐藏无模式对话框, 可以销毁模式对话框
		}
		break;
	}
	return FALSE;//对话框的消息交给真正对话框窗口处理函数处理。
}
void OnNoModel(HWND hWnd) {
	EnableWindow(hWnd, FALSE);//无模态转模态需要两点，第一点创建前失能父窗口
	//	HWND hDlg = CreateDialog( g_hInstance, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, DlgProc );//创建无模式对话框方式一，直接创建

	HRSRC hRs = FindResource(g_hInstance, MAKEINTRESOURCE(IDD_DIALOG1), RT_DIALOG);//创建无模式对话框方式二，间接创建
	HGLOBAL hGl = LoadResource(g_hInstance, hRs);
	LPCDLGTEMPLATE pTemplate = (LPCDLGTEMPLATE)LockResource(hGl);
	HWND hDlg = CreateDialogIndirect(g_hInstance, pTemplate, hWnd, (DLGPROC)DlgProc);

	ShowWindow(hDlg, SW_SHOW);
}
void OnCommand(HWND hWnd, WPARAM wParam) {
	switch (LOWORD(wParam)) {
	case ID_NOMODEL:
		OnNoModel(hWnd);
		break;
	}
}
//窗口处理函数( 自定义，处理消息)
LRESULT CALLBACK WndProc(HWND hWnd, UINT msgID, WPARAM wParam, LPARAM lParam) {
	switch (msgID) {
	case WM_COMMAND:
		OnCommand(hWnd, wParam);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hWnd, msgID, wParam, lParam);
}
//入口函数
int CALLBACK WinMain(HINSTANCE hIns, HINSTANCE hPreIns, LPSTR lpCmdLine, int nCmdShow) {
	g_hInstance = hIns;
	//注册窗口类
	WNDCLASS wc = { 0 };
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.hCursor = NULL;
	wc.hIcon = NULL;
	wc.hInstance = hIns;
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = "Main";
	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);//(CHAR*)IDR_MENU1;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&wc);//将以上所有赋值全部写入操作系统。
	//在内存创建窗口
	HWND hWnd = CreateWindowEx(0, "Main", "window", WS_OVERLAPPEDWINDOW,
		100, 100, 500, 500, NULL, NULL, hIns, NULL);
	//显示窗口
	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);
	//消息循环
	MSG nMsg = { 0 };
	while (GetMessage(&nMsg, NULL, 0, 0)) {
		TranslateMessage(&nMsg);
		DispatchMessage(&nMsg);//将消息交给窗口处理函数来处理。
	}
	return 0;
}