#include <windows.h>
#include <cassert>
#include <iostream>

//Button ID
#define IDC_SORT_BTN 100

//das ist der MessageHandler
LRESULT CALLBACK MessageHandler(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) {
	case WM_CLOSE:
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_COMMAND: //durch WM_COMAND accsesd mann LOWORD und von LOWORD wParam und wenn wParam gleich mein button ID is dann soll was asugefuehrt werden
		if (LOWORD(wParam) == IDC_SORT_BTN) {
			std::cout << "Sortiren Methode wird Aufgerufen" << std::endl;
		}
		break;
		

	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
//hauptfunktion

int main() {
	
	HINSTANCE hInstance = GetModuleHandle(0);
	
	//Create Object from the class that creats the window
	WNDCLASS wc;
	//Creat Object form the class that Handles the Window class Object
	HWND hWnd;
	//Button ist ein Handle
	HWND hButton;
	//Create Object form the class that creats the Message
	MSG msg;
	
	//init struct/Alles mit Null
	wc = {};

	//style
	wc.style = CS_HREDRAW | CS_VREDRAW; // CS_VREDRAW is for reszising
	wc.lpfnWndProc = MessageHandler; 
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);//hier wird der Icon geladen
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); // um die Scallierung von der Bildschirm groesse anzupassen
	wc.lpszClassName = "WINAPITest";

	//registrierer das Ganze
	RegisterClass(&wc);

	//erstelle Fenster
	hWnd = CreateWindow("WINAPITest", "Bubble-Sort", WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT,CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 0, 0, hInstance, 0);

	//Button erstellen
	hButton = CreateWindow("button", "SortList", WS_TABSTOP | WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON, 600, 600, 200, 50, hWnd, (HMENU) IDC_SORT_BTN, hInstance, 0);
	//output on console
	std::cout << "Created a Window" << std::endl;

	bool running = true; 
	//update Methode
	while (running) {
		while (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
			if (msg.message == WM_QUIT) {
				running == false;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		//TODO: Render Frame und Update Diagramm
	}

	

	
}
