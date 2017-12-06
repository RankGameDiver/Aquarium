#include "ImgBuffer.h"
#include <windows.h>

IMGBUFFER* CreateImageBuffer(HWND hWnd)
{
	IMGBUFFER* Temp;

	Temp = (IMGBUFFER*)malloc(sizeof(IMGBUFFER));

	Temp->hWnd = hWnd;

	GetClientRect(hWnd, &(Temp->BufferSize));

	Temp->hdcFront = GetDC(hWnd); // 주버퍼 생성 // 화면 DC
	// 보조버퍼 생성
	Temp->hdcBack = CreateCompatibleDC(Temp->hdcFront);
	Temp->hbmBack = CreateCompatibleBitmap(Temp->hdcFront, 
		                          Temp->BufferSize.right - Temp->BufferSize.left, 
		                          Temp->BufferSize.bottom - Temp->BufferSize.top);
	SelectObject(Temp->hdcBack, Temp->hbmBack);
	//

	Temp->hdcImg = CreateCompatibleDC(Temp->hdcFront);

	return Temp;
}

void LoadImage(IMGBUFFER* ib, char* filename)
{
	ib->hbmImg = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

HBITMAP LoadImage(char* filename)
{
	return  (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

void DrawImage(IMGBUFFER* ib, int x, int y)
{
	SelectObject(ib->hdcImg, ib->hbmImg);

	BitBlt(ib->hdcBack, x, y, ib->BufferSize.right, ib->BufferSize.bottom, ib->hdcImg, 0, 0, SRCCOPY);
}

void DrawImage(IMGBUFFER* ib, HBITMAP img, int x, int y)
{
	SelectObject(ib->hdcImg, img);

	BitBlt(ib->hdcBack, x, y, ib->BufferSize.right, ib->BufferSize.bottom, ib->hdcImg, 0, 0, SRCCOPY);
}

void DrawSprite(IMGBUFFER* ib, int dx, int dy, int w, int h, int hx, int hy, COLORREF color)
{ //			이미지,		 이미지 시작점 x,y,	조각의 크기,	 가로 세로 자르는 횟수, 거를 색
	SelectObject(ib->hdcImg, ib->hbmImg);

	TransparentBlt(ib->hdcBack, dx, dy, w, h, ib->hdcImg, hx * w, hy * h, w, h, color);

	Sleep(300 / 10);
}

void ClearScreen(IMGBUFFER* ib,  COLORREF color)
{
	HPEN hPen, OldPen;
	HBRUSH hBrush, OldBrush;
	int x1, y1, x2, y2;

	hPen = CreatePen(PS_SOLID, 1, color);
	hBrush = CreateSolidBrush(color);

	OldPen = (HPEN)SelectObject(ib->hdcBack, hPen);
	OldBrush = (HBRUSH)SelectObject(ib->hdcBack, hBrush);

	x1 = ib->BufferSize.left;	y1 = ib->BufferSize.top;
	x2 = ib->BufferSize.right;	y2 = ib->BufferSize.bottom;

	Rectangle(ib->hdcBack, x1, y1, x2, y2);

	SelectObject(ib->hdcBack,OldPen);
	SelectObject(ib->hdcBack, OldBrush);

	DeleteObject(hBrush);
	DeleteObject(hPen);
}

void SwapBuffer(IMGBUFFER* ib)
{
	int x, y;
	int width, height;

	x = ib->BufferSize.left;	y = ib->BufferSize.top;
	width = ib->BufferSize.right -  ib->BufferSize.left;
	height = ib->BufferSize.bottom - ib->BufferSize.top;

	BitBlt(ib->hdcFront, x, y, width, height, ib->hdcBack, 0, 0, SRCCOPY);
}

void DeleteImageBuffer(IMGBUFFER* ib)
{
	if(ib->hbmImg != NULL)		DeleteObject(ib->hbmImg);
	DeleteObject(ib->hbmBack);
	DeleteDC(ib->hdcImg);
	DeleteDC(ib->hdcBack);
	DeleteDC(ib->hdcFront);
}





