#ifndef _PLAYER_OBJ_H_
#define _PLAYER_OBJ_H_

#include <string.h>
#include "Sprite.h"
#include "ImgBuffer.h"

#define SWIM 0
#define TURN 1

#define LEFT_SWIM 0
#define RIGHT_SWIM 1
#define RTOL_TURN 2
#define LTOR_TURN 3
#define LEFT_ATTACK 4
#define RIGHT_ATTACK 5
typedef struct tagPlayerObject
{
	IMGBUFFER* IB;			// 그려질 공간
	SPRITE* Sprite[6];		// 스프라이트 이미지
	COLORREF SpriteColor;	// 칼라키값
	POINT ptPosition;		// 오브젝트 위치
	int nCurrentState;		// 어떤 상태인지
	int nMaxState;			// 최대상태
}PLAYER;

PLAYER* InitPlayerObj(IMGBUFFER* ib);

void Action(PLAYER* Object, int x, int y, bool attack);

void SetPosition(PLAYER* Object, int x, int y);

void SetState(PLAYER* Object, int State);

#endif