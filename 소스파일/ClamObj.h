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
	IMGBUFFER* IB;			// �׷��� ����
	SPRITE* Sprite[2];		// ��������Ʈ �̹���
	COLORREF SpriteColor;	// Į��Ű��
	POINT ptPosition;		// ������Ʈ ��ġ
	int nCurrentState;		// � ��������
	int nMaxState;			// �ִ����
}CLAMOBJ;

CLAMOBJ* InitClamObj(IMGBUFFER* ib);

void Action(CLAMOBJ* Object, int x, int y);

void SetPosition(CLAMOBJ* Object, int x, int y);

void SetState(CLAMOBJ* Object, int State);

#endif