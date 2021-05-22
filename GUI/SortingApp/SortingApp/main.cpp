#include <windows.h>
#include <cassert>


LRESULT CALLBACK MessageHandler(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) {
	case WM_CLOSE:
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
//hauptfunktion

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance /*das ist immer null*/, LPSTR lpCmdLine, int nCmdShow) {
	
	//klasse fuer fenster
	WNDCLASS wc;
	//handel Fenster
	HWND hWnd;

	MSG msg;
	
	//init struct/Alles mit Null
	wc = {};

	//style
	wc.style = CS_HREDRAW | CS_VREDRAW; // sec is for reszising
	wc.lpfnWndProc = MessageHandler; 
	//wc.cbClsExtra = 0;
	//wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	//wc.lpszMenuName = NULL;
	wc.lpszClassName = "WINAPITest";

	//registrierer das Ganze
	RegisterClass(&wc);

	//erstelle Fenster
	hWnd = CreateWindow("WINAPITest", "Bubble-Sort", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT,CW_USEDEFAULT, 800, 600, 0, 0, hInstance, 0);

	//zeige fenster
	ShowWindow(hWnd, nCmdShow);
	SetForegroundWindow(hWnd);
	UpdateWindow(hWnd);


	//Events abfragen
	while (true)
	{
		BOOL result = GetMessage(&msg, 0, 0, 0);
		if (result > 0) { // kein fehler
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else { // fehler wird beendet
			return result;
		}
	}

	
}
