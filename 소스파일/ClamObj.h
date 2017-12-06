#pragma once
#ifndef _CLAM_OBJ_H_
#define _CLAM_OBJ_H_

#include <string.h>
#include "Sprite.h"
#include "ImgBuffer.h"

#define OPEN 0
#define CLOSE 1

typedef struct tagClamObject
{
	IMGBUFFER* IB;			// 그려질 공간
	SPRITE* Sprite[2];		// 스프라이트 이미지
	COLORREF SpriteColor;	// 칼라키값
	POINT ptPosition;		// 오브젝트 위치
	int nCurrentState;		// 어떤 상태인지
	int nMaxState;			// 최대상태
}CLAMOBJ;

CLAMOBJ* InitClamObj(IMGBUFFER* ib);

void Action(CLAMOBJ* Object, int x, int y);

void SetPosition(CLAMOBJ* Object, int x, int y);

void SetState(CLAMOBJ* Object, int State);

#endif