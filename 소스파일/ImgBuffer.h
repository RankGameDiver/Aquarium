#ifndef _IMG_BUFFER_H_
#define _IMG_BUFFER_H_

#include <windows.h>

typedef struct tagIMGBUFFER
{
	HWND hWnd;
	HDC hdcFront;				//���� ����
	HDC hdcBack;             //�ĸ� ����
	HDC hdcImg;               //��µ� �̹��� ����
	HBITMAP hbmBack;   //�ĸ� ���� ���빰
	HBITMAP hbmImg;     //�̹��� ���� ���빰
	RECT BufferSize;         //���� ũ��
}IMGBUFFER;

IMGBUFFER* CreateImageBuffer(HWND hWnd);

void LoadImage(IMGBUFFER* ib, char* filename);

void DrawImage(IMGBUFFER* ib, int x, int y);

void DrawSprite(IMGBUFFER* ib, int dx, int dy, int w, int h, int hx, int hy, COLORREF color);

HBITMAP LoadImage(char* filename);

void ClearScreen(IMGBUFFER* ib,  COLORREF color);

void SwapBuffer(IMGBUFFER* ib);

void DeleteImageBuffer(IMGBUFFER* ib);

#endif

