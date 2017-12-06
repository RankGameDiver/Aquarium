#ifndef _MAIN_PROC_H_
#define _MAIN_PROC_H_

#include <windows.h>

int OnCreate(HWND hWnd, WPARAM wParam, LPARAM lParam);

int OnTimer(HWND hWnd, WPARAM wParam, LPARAM lParam);

int OnMouseMove(HWND hWnd, WPARAM wParam, LPARAM lParam);

int OnKeyDown(HWND hWnd, WPARAM wParam, LPARAM lParam);

int OnDestroy(HWND hWnd, WPARAM wParam, LPARAM lParam);

void Run();

#endif