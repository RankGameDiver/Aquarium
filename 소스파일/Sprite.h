#ifndef _SPRITE_H_
#define _SPRITE_H_

#include <windows.h>
#include "ImgBuffer.h"

typedef struct tagSPRITE
{
	HBITMAP hBitmap;	 //�̹���
	COLORREF color;    //����
	POINT Position;		//��ġ ��ǥ
	int CurrentFrame;		//���� ��µǴ� �̹���	
	int LastFrame;			//��ü �̹��� ��	
	int Width;					//�̹��� ��
	int Height;					//�̹��� ����
	float lastTime; // ������ �ð�
	float elapsedTime; // ��� �ð�
}SPRITE;

void LoadSprite(SPRITE *pSP, LPSTR szFileName, int width, int height, int lastframe, COLORREF color);

void SetSpritePosition(SPRITE *pSP, int x, int y);

void FreeSprite(SPRITE *pSP);

void NextFrameSprite(SPRITE* pSP, int FrameRate);

void DrawSprite(SPRITE *pSP, IMGBUFFER* pIB, int xPos, int yPos);

void ReverseDrawSprite(SPRITE* pSP, IMGBUFFER* pIB);

#endif