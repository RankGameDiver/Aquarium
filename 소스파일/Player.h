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
	IMGBUFFER* IB;			// �׷��� ����
	SPRITE* Sprite[6];		// ��������Ʈ �̹���
	COLORREF SpriteColor;	// Į��Ű��
	POINT ptPosition;		// ������Ʈ ��ġ
	int nCurrentState;		// � ��������
	int nMaxState;			// �ִ����
}PLAYER;

PLAYER* InitPlayerObj(IMGBUFFER* ib);

void Action(PLAYER* Object, int x, int y, bool attack);

void SetPosition(PLAYER* Object, int x, int y);

void SetState(PLAYER* Object, int State);

#endif