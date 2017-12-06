#include "Player.h"

PLAYER* InitPlayerObj(IMGBUFFER* ib)
{
	PLAYER* Temp;

	Temp = (PLAYER*)malloc(sizeof(PLAYER));

	Temp->IB = ib;

	Temp->SpriteColor = RGB(255, 0, 0);

	for (int i = 0; i < 6; i++)
	{
		Temp->Sprite[i] = (SPRITE*)malloc(sizeof(SPRITE));
	}

	LoadSprite(Temp->Sprite[0], "Player1.bmp", 80, 80, 10, Temp->SpriteColor);
	LoadSprite(Temp->Sprite[1], "Player2.bmp", 80, 80, 10, Temp->SpriteColor);
	LoadSprite(Temp->Sprite[2], "Player3.bmp", 80, 80, 10, Temp->SpriteColor);
	LoadSprite(Temp->Sprite[3], "Player4.bmp", 80, 80, 10, Temp->SpriteColor);
	LoadSprite(Temp->Sprite[4], "Player5.bmp", 80, 80, 10, Temp->SpriteColor);
	LoadSprite(Temp->Sprite[5], "Player6.bmp", 80, 80, 10, Temp->SpriteColor);

	Temp->nCurrentState = 0;
	Temp->nMaxState = 4;

	return Temp;
}

void Action(PLAYER* Object, int x, int y, bool attack)
{
	static int anistate = LEFT_SWIM;
	static float deltaX; 
	static float deltaY; 
	static bool attack1;

	//Object->nCurrentState
	switch (anistate)
	{
	case LEFT_SWIM:
		if (deltaX < x)
		{
			anistate = RTOL_TURN;
			Object->Sprite[anistate]->CurrentFrame = 10;
		}
		if (attack == true)
		{
			anistate = LEFT_ATTACK;
			Object->Sprite[anistate]->CurrentFrame = 10;
		}
		break;
	case RIGHT_SWIM:
		if (deltaX > x)
		{
			anistate = LTOR_TURN;
			Object->Sprite[anistate]->CurrentFrame = 10;
		}
		if (attack == true)
		{
			anistate = RIGHT_ATTACK;
			Object->Sprite[anistate]->CurrentFrame = 10;
		}
		break;
	case RTOL_TURN:
		if (Object->Sprite[anistate]->CurrentFrame >= Object->Sprite[anistate]->LastFrame)
			anistate = RIGHT_SWIM;
		break;
	case LTOR_TURN:
		if (Object->Sprite[anistate]->CurrentFrame >= Object->Sprite[anistate]->LastFrame)
			anistate = LEFT_SWIM;
		break;
	case LEFT_ATTACK:
		if (Object->Sprite[anistate]->CurrentFrame >= Object->Sprite[anistate]->LastFrame)
			anistate =LEFT_SWIM;
		break;
	case RIGHT_ATTACK:
		if (Object->Sprite[anistate]->CurrentFrame >= Object->Sprite[anistate]->LastFrame)
			anistate = RIGHT_SWIM;
		break;
	}

	deltaX = x;
	deltaY = y;
	attack1 = attack;

	NextFrameSprite(Object->Sprite[anistate], Object->Sprite[anistate]->LastFrame);
	DrawSprite(Object->Sprite[anistate], Object->IB, x, y);
}


void SetPosition(PLAYER* Object, int x, int y)
{
	Object->ptPosition.x = x;
	Object->ptPosition.y = y;
}

void SetState(PLAYER* Object, int State)
{
	if (State < 0) Object->nCurrentState = 0;
	if (State > Object->nMaxState) Object->nCurrentState = Object->nMaxState;
	Object->nCurrentState = State;
}
