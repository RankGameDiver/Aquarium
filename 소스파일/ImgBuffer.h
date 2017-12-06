#ifndef _IMG_BUFFER_H_
#define _IMG_BUFFER_H_

#include <windows.h>

typedef struct tagIMGBUFFER
{
	HWND hWnd;
	HDC hdcFront;				//전면 버퍼
	HDC hdcBack;             //후면 버퍼
	HDC hdcImg;               //출력될 이미지 버퍼
	HBITMAP hbmBack;   //후면 버퍼 내용물
	HBITMAP hbmImg;     //이미지 버퍼 내용물
	RECT BufferSize;         //버퍼 크기
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

