#include "Sprite.h"

void LoadSprite(SPRITE* pSP, LPSTR szFileName, int width, int height, int lastframe, COLORREF color)
{
		pSP->LastFrame = lastframe - 1;
		pSP->CurrentFrame = 0;
		SetSpritePosition(pSP, 0, 0);

		pSP->hBitmap = LoadImage(szFileName);
		if(pSP->hBitmap == NULL) 
		{
			MessageBox(NULL, "이미지가 없습니다.", "에러!!!", MB_OK);
			exit(0);
		}
		pSP->color = color;

		pSP->Width = width;
		pSP->Height = height;
		pSP->lastTime = GetTickCount() * 0.001f;
		pSP->elapsedTime = 0.0f;
}

void SetSpritePosition(SPRITE* pSP, int x, int y)
{
		pSP->Position.x = x;
		pSP->Position.y = y;
}

void FreeSprite(SPRITE* pSP)
{
		if(pSP->hBitmap)
		{
			DeleteObject(pSP->hBitmap);			
		}
}

void NextFrameSprite(SPRITE* pSP, int FrameRate)
{
	/*pSP->lastTime = GetTickCount() * 0.001f;
	pSP->elapsedTime = 0.0f;*/

	float currentTime = GetTickCount() * 0.001f;
	float deltaTime = currentTime - pSP->lastTime;
	float desiredFPS = 1.0f / FrameRate;

	pSP->elapsedTime += deltaTime;
	pSP->lastTime = currentTime;
	 
	if (pSP->elapsedTime > desiredFPS)
	{
		pSP->elapsedTime -= desiredFPS;
		pSP->CurrentFrame++;
		if (pSP->CurrentFrame >= pSP->LastFrame+1)
		{
			pSP->CurrentFrame = 0;
			pSP->elapsedTime = 0.0f;
			pSP->lastTime = GetTickCount() * 0.001f;
		}
	}
}

#pragma comment (lib, "Msimg32.lib")

void DrawSprite(SPRITE* pSP, IMGBUFFER* pIB, int xPos, int yPos)
{
		RECT screen; // 한번에 출력되는 이미지 크기

		screen.left = pSP->CurrentFrame * pSP->Width;
		screen.top = 0;
		screen.right = screen.left + pSP->Width;
		screen.bottom = screen.top + pSP->Height;

		SelectObject(pIB->hdcImg, pSP->hBitmap);

		int width = pSP->Width;
		int height = pSP->Height;

		TransparentBlt(pIB->hdcBack, xPos, yPos, width, height,
			pIB->hdcImg, screen.left, screen.top, width, height, pSP->color);	
}

void ReverseDrawSprite(SPRITE* pSP, IMGBUFFER* pIB)
{
		RECT screen;

		screen.left = (pSP->LastFrame - pSP->CurrentFrame) * pSP->Width;
		screen.top = 0;
		screen.right = screen.left + pSP->Width;
		screen.bottom = screen.top + pSP->Height;

		SelectObject(pIB->hdcImg, pSP->hBitmap);

		int width = pSP->Width;
		int height = pSP->Height;

		TransparentBlt(pIB->hdcBack, pSP->Position.x, pSP->Position.y, width, height, 
			pIB->hdcImg, screen.left, screen.top, width, height, pSP->color);	
}
