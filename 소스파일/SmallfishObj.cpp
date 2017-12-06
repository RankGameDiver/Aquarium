#include "SmallfishObj.h"

SMALLFISH* InitSmallfishObj(IMGBUFFER* ib)
{
	SMALLFISH* Temp;

	Temp = (SMALLFISH*)malloc(sizeof(SMALLFISH));

	Temp->IB = ib;

	Temp->SpriteColor = RGB(255, 0, 0);

	for (int i = 0; i < 4; i++)
	{
		Temp->Sprite[i] = (SPRITE*)malloc(sizeof(SPRITE));
	}

	LoadSprite(Temp->Sprite[0], "smallfish1.bmp", 80, 80, 10, Temp->SpriteColor);
	LoadSprite(Temp->Sprite[1], "smallfish2.bmp", 80, 80, 10, Temp->SpriteColor);
	LoadSprite(Temp->Sprite[2], "smallfish3.bmp", 80, 80, 10, Temp->SpriteColor);
	LoadSprite(Temp->Sprite[3], "smallfish4.bmp", 80, 80, 10, Temp->SpriteColor);

	Temp->nCurrentState = 0;
	Temp->nMaxState = 4;

	return Temp;
}

void Action(SMALLFISH* Object, int x, int y)
{
	static int anistate = LEFT_SWIM;
	static int yPosition = DOWN_SWIM;
	static float xPos = x;
	static float yPos = y;

	//Object->nCurrentState
	switch (anistate)
	{
	case LEFT_SWIM:
		xPos -= 0.1f;
		if (xPos < 0)
		{
			anistate = RTOL_TURN;
			Object->Sprite[anistate]->CurrentFrame = 10;
		}
		break;
	case RIGHT_SWIM:
		xPos += 0.1f;
		if (xPos > 300)
		{
			anistate = LTOR_TURN;
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
	}
	if (anistate != LTOR_TURN && anistate != RTOL_TURN)
	{
		switch (yPosition)
		{
		case UP_SWIM:
			yPos -= 0.04f;
			if (yPos < y)
				yPosition = DOWN_SWIM;
			break;
		case DOWN_SWIM:
			yPos += 0.04f;
			if (yPos > y + 20)
				yPosition = UP_SWIM;
			break;
		}
	}
	

	NextFrameSprite(Object->Sprite[anistate], Object->Sprite[anistate]->LastFrame);
	DrawSprite(Object->Sprite[anistate], Object->IB, xPos, yPos);
}


void SetPosition(SMALLFISH* Object, int x, int y)
{
	Object->ptPosition.x = x;
	Object->ptPosition.y = y;
}

void SetState(SMALLFISH* Object, int State)
{
	if (State < 0) Object->nCurrentState = 0;
	if (State > Object->nMaxState) Object->nCurrentState = Object->nMaxState;
	Object->nCurrentState = State;
}
