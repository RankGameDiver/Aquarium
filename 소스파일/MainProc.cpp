#include "stdfx.h"

extern BOOL bIsActive;

IMGBUFFER* Buffer;
SPRITE Sprite;
MERMAIDOBJ* Mermaid;
SMALLFISH* Smallfish;
CLAMOBJ* Clam;
PLAYER* Player;

POINT ptMouse;
static int pX;
static int pY;
bool attack;
int nFPS;
int nCount;

static float nameX;

int OnCreate(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	Buffer = CreateImageBuffer(hWnd);
	LoadImage(Buffer, "background.bmp");

	Mermaid = InitMermaidObj(Buffer);
	Smallfish = InitSmallfishObj(Buffer);
	Clam = InitClamObj(Buffer);
	Player = InitPlayerObj(Buffer);

	bIsActive = true;

	pX = 300;
	pY = 200;
	attack = false;
	nameX = 300;

	SetTimer(hWnd, 0, 1000, NULL);

	return 1;
}

int OnTimer(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	nFPS = nCount;
	nCount = 0;

	return 1;
}

int OnMouseMove(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	ptMouse.x = LOWORD(lParam);
	ptMouse.y = HIWORD(lParam);

	return 1;
}

int OnKeyDown(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	switch (wParam)
	{
	case VK_LEFT:
		pX -= 2.4f;
		break;
	case VK_RIGHT:
		pX += 4.8f;
		break;
	case VK_UP:
		pY -= 2.4f;
		break;
	case VK_DOWN:
		pY += 4.8f;
		break;
	case VK_SPACE:
		attack = true;
		break;
	}
	return 0;
}

int OnDestroy(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	bIsActive = false;

	FreeSprite(&Sprite);
	DeleteImageBuffer(Buffer);
	PostQuitMessage(0);

	return 1;
}

void Run()
{
	char strBuffer[16];
	char nameBuffer[16];

	DrawImage(Buffer, 0, 0); // ¹è°æ
	//SetSpritePosition(&Sprite, ptMouse.x, ptMouse.y);

	Action(Mermaid, 0, 250);
	Action(Smallfish, 100, 100);
	Action(Clam, 260, 320);
	Action(Player, pX, pY, attack);
	attack = false;
	//NextFrameSprite(&Sprite, 10);

	sprintf(strBuffer, "FPS = %3d", nFPS);
	TextOut(Buffer->hdcBack, 0, 0, strBuffer, strlen(strBuffer)); 

	sprintf(nameBuffer, "20313 ±è°Ç");
	TextOut(Buffer->hdcBack, nameX, 0, nameBuffer, strlen(nameBuffer));

	nameX += 0.1f;
	if (nameX > 500)
		nameX -= 200;
	SwapBuffer(Buffer);

	nCount++;
}