#ifndef _MERMAID_OBJ_H_
#define _MERMAID_OBJ_H_

#include <string.h>
#include "Sprite.h"
#include "ImgBuffer.h"

#define SWIM 0
#define TURN 1

#define LEFT_SWIM 0
#define RIGHT_SWIM 1
#define RTOL_TURN 2
#define LTOR_TURN 3

#define UP_SWIM 0
#define DOWN_SWIM 1
typedef struct tagMermaidObject
{
	IMGBUFFER* IB;			// �׷��� ����
	SPRITE* Sprite[4];		// ��������Ʈ �̹���
	COLORREF SpriteColor;	// Į��Ű��
	POINT ptPosition;		// ������Ʈ ��ġ
	int nCurrentState;		// � ��������
	int nMaxState;			// �ִ����
}MERMAIDOBJ;

MERMAIDOBJ* InitMermaidObj(IMGBUFFER* ib);

void Action(MERMAIDOBJ* Object, int x, int y);

void SetPosition(MERMAIDOBJ* Object, int x, int y);

void SetState(MERMAIDOBJ* Object, int State);

#endif