#include "ClamObj.h"

CLAMOBJ* InitClamObj(IMGBUFFER* ib)
{
	CLAMOBJ* Temp;

	Temp = (CLAMOBJ*)malloc(sizeof(CLAMOBJ));

	Temp->IB = ib;

	Temp->SpriteColor = RGB(255, 0, 0);

	for (int i = 0; i < 2; i++)
	{
		Temp->Sprite[i] = (SPRITE*)malloc(sizeof(SPRITE));
	}

	LoadSprite(Temp->Sprite[0], "clam1.bmp", 80, 80, 20, Temp->SpriteColor);
	LoadSprite(Temp->Sprite[1], "clam2.bmp", 80, 80, 20, Temp->SpriteColor);

	Temp->nCurrentState = 0;
	Temp->nMaxState = 2;

	return Temp;
}

void Action(CLAMOBJ* Object, int x, int y)
{
	static int anistate = OPEN;
	static float xPos = x;
	static float yPos = y;

	//Object->nCurrentState
	switch (anistate)
	{
	case OPEN:
		if (Object->Sprite[anistate]->CurrentFrame >= Object->Sprite[anistate]->LastFrame)
		{
			anistate = CLOSE;
			Object->Sprite[anistate]->CurrentFrame = 20;
		}
		break;
	case CLOSE:
		if (Object->Sprite[anistate]->CurrentFrame >= Object->Sprite[anistate]->LastFrame)
		{
			anistate = OPEN;
			Object->Sprite[anistate]->CurrentFrame = 20;
		}
	}

	NextFrameSprite(Object->Sprite[anistate], Object->Sprite[anistate]->LastFrame);
	DrawSprite(Object->Sprite[anistate], Object->IB, xPos, yPos);
}


void SetPosition(CLAMOBJ* Object, int x, int y)
{
	Object->ptPosition.x = x;
	Object->ptPosition.y = y;
}

void SetState(CLAMOBJ* Object, int State)
{
	if (State < 0) Object->nCurrentState = 0;
	if (State > Object->nMaxState) Object->nCurrentState = Object->nMaxState;
	Object->nCurrentState = State;
}
