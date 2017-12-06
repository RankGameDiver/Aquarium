#ifndef _SPRITE_H_
#define _SPRITE_H_

#include <windows.h>
#include "ImgBuffer.h"

typedef struct tagSPRITE
{
	HBITMAP hBitmap;	 //이미지
	COLORREF color;    //배경색
	POINT Position;		//위치 좌표
	int CurrentFrame;		//현재 출력되는 이미지	
	int LastFrame;			//전체 이미지 수	
	int Width;					//이미지 폭
	int Height;					//이미지 높이
	float lastTime; // 마지막 시간
	float elapsedTime; // 경과 시간
}SPRITE;

void LoadSprite(SPRITE *pSP, LPSTR szFileName, int width, int height, int lastframe, COLORREF color);

void SetSpritePosition(SPRITE *pSP, int x, int y);

void FreeSprite(SPRITE *pSP);

void NextFrameSprite(SPRITE* pSP, int FrameRate);

void DrawSprite(SPRITE *pSP, IMGBUFFER* pIB, int xPos, int yPos);

void ReverseDrawSprite(SPRITE* pSP, IMGBUFFER* pIB);

#endif