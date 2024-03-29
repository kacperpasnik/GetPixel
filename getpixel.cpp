// getpixel.cpp : definiuje punkt wejścia dla aplikacji
//

#include "stdafx.h"
#include "getpixel.h"
#include <windowsx.h>

#define MAX_LOADSTRING 100

// Zmienne globalne:
HINSTANCE hInst;                                // bieżące wystąpienie
WCHAR szTitle[MAX_LOADSTRING];                  // Tekst paska tytułu
WCHAR szWindowClass[MAX_LOADSTRING];            // nazwa klasy okna głównego

// Przekaż dalej deklaracje funkcji dołączonych w tym module kodu:
//ATOM                MyRegisterClass(HINSTANCE hInstance);
//BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: W tym miejscu umieść kod.
	HWND hWnd = GetDesktopWindow();
	HDC hdc = GetDC(GetDesktopWindow());
	int rgb = 0;
	//int xPos = GET_X_LPARAM(lParam);
	//int yPos = GET_Y_LPARAM(lParam);
	POINT p;
	//int *rgb_zmiana = &rgb,
	int i = 0;
	MessageBox(hWnd, L"Po wciśnięciu OK i odczekaniu 2 sekund zostaną\nzarejestrowane koordynaty myszki.\nProgram poinformuje, kiedy kolor piksela się zmieni.", L"Info", MB_OK | MB_ICONINFORMATION);
	Sleep(2000);
	if (GetCursorPos(&p))
	{
		rgb = GetPixel(hdc, p.x, p.y);

		while (rgb)
		{
			if (GetPixel(hdc, p.x, p.y) != rgb)
			{
				i = MessageBox(hWnd, L"Piksel zmienił kolor! \n  Kontynuować?", L"", MB_OKCANCEL | MB_ICONINFORMATION);
				switch (i)
				{
					case IDOK:
					{
						Sleep(2000);

					}
					break;
					case IDCANCEL:
					{
						DestroyWindow(hWnd);
						PostQuitMessage(0);
						return 0;
					}
					break;
				}
				GetCursorPos(&p);
				rgb = GetPixel(hdc, p.x, p.y);
			}
		}
	}

	DestroyWindow(hWnd);
	PostQuitMessage(0);
    return 0;
	
}

