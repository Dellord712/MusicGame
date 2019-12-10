#define _CRT_NONSTDC_NO_DEPRECATE

#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

#define StickNum 10
#define WayNum 5
#define Hpbar 20
#define EffactNum 22

#define BufferWidth 80
#define BufferHeight 40

#define MILLION ".\\MILLION.wav"
#define TT ".\\TT.wav"

char sNum[10];
char sNum2[5];
char sNum3[5];
char sNum4[5];
char sNum5[10];
char sNum6[10];
char sNum7[10];
char sNum8[10];
char sNum9[2];

enum Color
{
	검정색,
	파란색,
	초록색,
	옥색,
	빨간색,
	자주색,
	노란색,
	흰색,
	회색,
	연한파란색,
	연한초록색,
	연한옥색,
	연한빨간색,
	연한자주색,
	진한노란색
};

enum STATE_ID
{
	LOGO,
	MENU,
	MENU2,
	STAGE,
	STAGE2,
	STAGEMENU,
	SET,
	SET2,
	EXIT
};

typedef struct Obj
{
	int x;
	int y;
	int cx;

	const char* shape;

	bool act;
}Stick1, Stick2, Stick3, Stick4, Stick5, Way, Point, StickTime, HPbar, Specialbar, Maxpoint, Arrowhead, Logotime, Stagemenu, Set, Set2, Sound, Effect, Effect2, Effect3,
Effect4, Effect5, Menu2;

Stick1* stick1[StickNum];
Stick2* stick2[StickNum];
Stick3* stick3[StickNum];
Stick4* stick4[StickNum];
Stick5* stick5[StickNum];
Way* way[WayNum];
Point* point;
StickTime* sticktime;
HPbar* hpbar[Hpbar];
Specialbar* specialbar[Hpbar];
Maxpoint* maxpoint;
Arrowhead* arrowhead;
Logotime* logotime;
Stagemenu* stagemenu;
Set* set;
Set2* set2;
Sound* sound;
Effect* effect[EffactNum];
Effect2* effect2[EffactNum];
Effect3* effect3[EffactNum];
Effect4* effect4[EffactNum];
Effect5* effect5[EffactNum];
Menu2* menu2;

void SetState();
STATE_ID state;

const char* NumImg[9];
const char* NumImg10[9];
const char* NumImg100[9];
const char* logoimg[9];
const char* menuimg1[11];
const char* menuimg2[7];
const char* menuimg3[12];
const char* exitimg[12];
const char* exitimg2[9];

void LogoImg1();
void LogoImg2();
void LogoImg3();

void MenuImg1();
void MenuImg2();
void MenuImg3();
void MenuImg4();
void MenuImg5();

void ExitImg1();
void ExitImg2();
void ExitImg3();
void ExitImg4();
void ExitImg5();
void ExitImg6();
void ExitImg7();
void ExitImg8();

void Num1();
void Num2();
void Num3();
void Num4();
void Num5();
void Num6();
void Num7();
void Num8();
void Num9();
void Num0();
void Num11();
void Num12();
void Num13();
void Num14();
void Num15();
void Num16();
void Num17();
void Num18();
void Num19();
void Num10();
void Num21();
void Num22();
void Num23();
void Num24();
void Num25();
void Num26();
void Num27();
void Num28();
void Num29();
void Num20();

bool stickcoolication1(Obj* stick1, Obj* way);
bool stickcoolication2(Obj* stick2, Obj* way);
bool stickcoolication3(Obj* stick3, Obj* way);
bool stickcoolication4(Obj* stick4, Obj* way);
bool stickcoolication5(Obj* stick5, Obj* way);

void LogoInit();
void LogoProgress();
void LogoRender();

void MenuInit();
void MenuProgress();
void MenuRender();

void MenuProgress2();
void MenuRender2();

void StageInit();
void StageProgress();
void StageRender();

void StageProgress2();
void StageRender2();

void StageMenuInit();
void StageMenuProgress();
void StageMenuRender();

void SetInit();
void SetProgress();
void SetRender();

void SetProgress2();
void SetRender2();

void ExitInit();
void ExitProgress();
void ExitRender();

void FREE();

void InitDoubleBuffer();
void WriteBuffer(int x, int y, const char* string, int color);
void FlipBuffer();
void ClearBuffer();
void DestroyBuffer();

HANDLE hBuffer[2];
int screenIndex;

int value = 1;

int main()
{
	DWORD dwTime = GetTickCount();
	InitDoubleBuffer();

	LogoInit();
	MenuInit();
	StageInit();
	StageMenuInit();
	SetInit();
	ExitInit();

	state = LOGO;
	while (value)
	{
		if (dwTime + (100 - set2->x) < GetTickCount())
		{
			dwTime = GetTickCount();
			SetState();
			FlipBuffer();
			ClearBuffer();
		}
	}
	FREE();
	DestroyBuffer();
}

void SetState()
{
	switch (state)
	{
	case LOGO:
		LogoProgress();
		LogoRender();
		break;
	case MENU:
		MenuProgress();
		MenuRender();
		break;
	case MENU2:
		MenuProgress2();
		MenuRender2();
		break;
	case STAGE:
		StageProgress();
		StageRender();
		break;
	case STAGE2:
		StageProgress2();
		StageRender2();
		break;
	case STAGEMENU:
		StageMenuProgress();
		StageMenuRender();
		break;
	case SET:
		SetProgress();
		SetRender();
		break;
	case SET2:
		SetProgress2();
		SetRender2();
		break;
	case EXIT:
		ExitProgress();
		ExitRender();
		break;
	default:
		break;
	}
}

void LogoInit()
{
	logotime = (Logotime*)malloc(sizeof(Logotime));
	logotime->x = 0;
}

void LogoProgress()
{
	logotime->x++;
	if (logotime->x >= 29)
	{
		state = MENU;
	}

	if (logotime->x >= 5)
	{
		if (GetAsyncKeyState(VK_RETURN) & 0x0001)
		{
			state = MENU;
		}
	}
	if (logotime->x < 10)
	{
		LogoImg1();
	}
	if (logotime->x >= 10 && logotime->x < 20)
	{
		LogoImg2();
	}
	if (logotime->x >= 20)
	{
		LogoImg3();
	}
}

void LogoRender()
{
	for (int i = 0; i < 8; i++)
	{
		if (logotime->x < 10)
		{
			WriteBuffer(15, 13 + i, logoimg[i], 연한자주색);
		}
		if (logotime->x >= 10 && logotime->x < 20)
		{
			WriteBuffer(15, 13 + i, logoimg[i], 연한파란색);
		}
		if (logotime->x >= 20)
		{
			WriteBuffer(15, 13 + i, logoimg[i], 흰색);
		}
	}
	WriteBuffer(15, 21, logoimg[8], 흰색);

	if (logotime->x >= 5)
	{
		WriteBuffer(60, 35, "SKIP", 흰색);
	}
}

void MenuInit()
{
	arrowhead = (Arrowhead*)malloc(sizeof(Arrowhead));
	arrowhead->x = 57;
	arrowhead->y = 26;
	arrowhead->shape = "▶";
	arrowhead->cx = 1; //munussinnum

	menu2 = (Menu2*)malloc(sizeof(Menu2));
	menu2->x = 0;
	menu2->y = 0;
}

void MenuProgress()
{
	if (GetAsyncKeyState(VK_DOWN) & 0x0001)
	{
		arrowhead->y += 2;
	}
	if (GetAsyncKeyState(VK_UP) & 0x0001)
	{
		arrowhead->y -= 2;
	}
	if (arrowhead->y < 26)
	{
		arrowhead->y = 26;
	}
	if (arrowhead->y > 32)
	{
		arrowhead->y = 32;
	}
	if (GetAsyncKeyState(VK_RETURN) & 0x0001)
	{
		if (arrowhead->y == 26)
		{
			if (set->cx == 1)
			{
				state = STAGE;
				sndPlaySoundA(MILLION, SND_ASYNC);
			}
			if (set->cx == 2)
			{
				state = STAGE2;
				sndPlaySoundA(TT, SND_ASYNC);
			}
		}
		if (arrowhead->y == 28)
		{
			state = MENU2;
		}
		if (arrowhead->y == 30)
		{
			state = SET;
		}
		if (arrowhead->y == 32)
		{
			value = 0;
		}
	}

	MenuImg1();
	MenuImg2();

	switch (arrowhead->cx)
	{
	case 1:
		MenuImg3();
		arrowhead->cx++;
		break;
	case 2:
		MenuImg4();
		arrowhead->cx++;
		break;
	case 3:
		MenuImg3();
		arrowhead->cx++;
		break;
	case 4:
		MenuImg5();
		arrowhead->cx = 1;
		break;
	}

	set2->x = 0;
}

void MenuRender()
{
	WriteBuffer(60, 26, "시작하기", 흰색);
	WriteBuffer(60, 28, "튜토리얼", 흰색);
	WriteBuffer(60, 30, "설정", 흰색);
	WriteBuffer(60, 32, "종료하기", 흰색);
	WriteBuffer(arrowhead->x, arrowhead->y, arrowhead->shape, 연한자주색);

	for (int i = 0; i < 11; i++)
	{
		WriteBuffer(3, 1 + i, menuimg1[i], 연한초록색);
	}
	for (int i = 0; i < 7; i++)
	{
		WriteBuffer(30, 13 + i, menuimg2[i], 진한노란색);
	}

	for (int i = 0; i < 12; i++)
	{
		WriteBuffer(2, 22 + i, menuimg3[i], 옥색);
	}

}

void MenuProgress2()
{
	if (GetAsyncKeyState(VK_ESCAPE) & 0x0001)
	{
		state = MENU;
		for (int i = 0; i < StickNum; i++)
		{
			stick2[i]->act = false;
			stick3[i]->act = false;
			stick4[i]->act = false;
		}
		sticktime->cx = 2;
		point->x = 0;
		point->y = 0;
		menu2->x = 0;
		stick1[0]->cx = 0;
	}
	if (GetAsyncKeyState(VK_RETURN) & 0x0001)
	{
		if (sticktime->cx == 0 || sticktime->cx == 2)
		{
			menu2->x = 1;
		}

		if (sticktime->cx >= 320 && sticktime->cx <= 400)
		{
			if (point->y >= 59)
			{
				point->y = -20;
			}
		}
	}
	if (menu2->x >= 1)
	{
		sticktime->cx++;
	}

	if (sticktime->cx == 15)
	{
		menu2->x = 2;
	}
	if (sticktime->cx == 60)
	{
		menu2->x = 3;
	}
	if (sticktime->cx == 95)
	{
		menu2->x = 4;
	}
	if (sticktime->cx == 110 && menu2->y == 0)
	{
		menu2->x = 5;
		sticktime->cx = 60;
	}
	if (sticktime->cx == 110 && menu2->y >= 1)
	{
		menu2->x = 6;
	}
	if (sticktime->cx == 155)
	{
		menu2->x = 7;
	}
	if (sticktime->cx == 180)
	{
		menu2->x = 8;
	}
	if (sticktime->cx == 240)
	{
		menu2->x = 9;
	}
	if (sticktime->cx == 300)
	{
		menu2->x = 10;
	}
	if (sticktime->cx == 315)
	{
		menu2->x = 11;
	}
	if (sticktime->cx == 430)
	{
		menu2->x = 12;
	}
	if (sticktime->cx == 460)
	{
		state = MENU;
		for (int i = 0; i < StickNum; i++)
		{
			stick2[i]->act = false;
			stick3[i]->act = false;
			stick4[i]->act = false;
		}
		sticktime->cx = 2;
		point->x = 0;
		point->y = 0;
		menu2->x = 0;
		stick1[0]->cx = 0;
	}

	if (sticktime->cx <= 15 || sticktime->cx >= 60)
	{
		//1
		for (int i = 0; i < StickNum; i++)
		{
			if (stick2[i]->act == false)
			{
				if (sticktime->cx == 10 || sticktime->cx == 185 || sticktime->cx == 245 || sticktime->cx == 320 || sticktime->cx == 329 || sticktime->cx == 334 || sticktime->cx == 369 || sticktime->cx == 375
					|| sticktime->cx == 386 || sticktime->cx == 390)
				{
					stick2[i]->x = 26;
					stick2[i]->y = 1;
					stick2[i]->act = true;
					break;
				}

				if (menu2->x == 5)
				{
					if (sticktime->cx == 60)
					{
						stick2[i]->x = 26;
						stick2[i]->y = 1;
						stick2[i]->act = true;
						break;
					}
				}
			}
		}

		for (int i = 0; i < StickNum; i++)
		{
			if (stick2[i]->act == true)
			{
				stick2[i]->y++;
				if (sticktime->cx < 240 || sticktime->cx >= 300)
				{
					if (stick2[i]->y == 38)
					{
						if (sticktime->cx >= 180)
						{
							point->x -= 2;
						}
						if (sticktime->cx >= 300)
						{
							if (point->y >= 1)
							{
								point->y -= 1;
							}
							if (point->y < 0)
							{
								point->y += 2;
							}
						}
						for (int j = 0; j < rand() % 10 + 12; j++)
						{
							WriteBuffer(effect2[j]->x, effect2[j]->y, effect2[j]->shape, 연한빨간색);
							WriteBuffer(effect2[j]->cx, effect2[j]->y, effect2[j]->shape, 연한빨간색);
						}
						WriteBuffer(2, 27, " MISS", 빨간색);
						stick2[i]->act = false;
					}
				}
				if (sticktime->cx >= 240 && sticktime->cx < 300)
				{
					if (stick2[i]->y == 35)
					{
						if (point->x <= 0)
						{
							point->x += 1;
						}
						if (point->y >= 0)
						{
							if (point->y <= 62)
							{
								point->y += 21;
							}
						}

						for (int j = 0; j < rand() % 10 + 12; j++)
						{
							WriteBuffer(effect2[j]->x, effect2[j]->y, effect2[j]->shape, 연한초록색);
							WriteBuffer(effect2[j]->cx, effect2[j]->y, effect2[j]->shape, 연한초록색);
						}
						WriteBuffer(2, 27, "PERPECT", 초록색);
						stick2[i]->act = false;
					}
				}
			}
		}
	}

	//2
	for (int i = 0; i < StickNum; i++)
	{
		if (stick3[i]->act == false)
		{
			if (sticktime->cx == 188 || sticktime->cx == 248 || sticktime->cx == 323 || sticktime->cx == 342 || sticktime->cx == 351 || sticktime->cx == 356 || sticktime->cx == 378 || sticktime->cx == 390)
			{
				stick3[i]->x = 38;
				stick3[i]->y = 1;
				stick3[i]->act = true;
				break;
			}
		}
	}

	for (int i = 0; i < StickNum; i++)
	{
		if (stick3[i]->act == true)
		{
			stick3[i]->y++;
			if (sticktime->cx < 240 || sticktime->cx >= 300)
			{
				if (stick3[i]->y == 38)
				{
					if (sticktime->cx >= 180)
					{
						point->x -= 2;
					}
					if (sticktime->cx >= 300)
					{
						if (point->y >= 1)
						{
							point->y -= 1;
						}
						if (point->y < 0)
						{
							point->y += 2;
						}
					}
					for (int j = 0; j < rand() % 10 + 12; j++)
					{
						WriteBuffer(effect3[j]->x, effect3[j]->y, effect3[j]->shape, 연한빨간색);
						WriteBuffer(effect3[j]->cx, effect3[j]->y, effect3[j]->shape, 연한빨간색);
					}
					WriteBuffer(2, 27, " MISS", 빨간색);
					stick3[i]->act = false;
				}
			}
			if (sticktime->cx >= 240 && sticktime->cx < 300)
			{
				if (stick3[i]->y == 35)
				{
					if (point->x <= 0)
					{
						point->x += 1;
					}
					if (point->y >= 0)
					{
						if (point->y <= 62)
						{
							point->y += 21;
						}
					}

					for (int j = 0; j < rand() % 10 + 12; j++)
					{
						WriteBuffer(effect3[j]->x, effect3[j]->y, effect3[j]->shape, 연한초록색);
						WriteBuffer(effect3[j]->cx, effect3[j]->y, effect3[j]->shape, 연한초록색);
					}
					WriteBuffer(2, 27, "PERPECT", 초록색);
					stick3[i]->act = false;
				}
			}
		}
	}

	//3
	for (int i = 0; i < StickNum; i++)
	{
		if (stick4[i]->act == false)
		{
			if (sticktime->cx == 191 || sticktime->cx == 251 || sticktime->cx == 326 || sticktime->cx == 341 || sticktime->cx == 346 || sticktime->cx == 361 || sticktime->cx == 380 || sticktime->cx == 385)
			{
				stick4[i]->x = 50;
				stick4[i]->y = 1;
				stick4[i]->act = true;
				break;
			}
		}
	}

	for (int i = 0; i < StickNum; i++)
	{
		if (stick4[i]->act == true)
		{
			stick4[i]->y++;
			if (sticktime->cx < 240 || sticktime->cx >= 300)
			{
				if (stick4[i]->y == 38)
				{
					if (sticktime->cx >= 180)
					{
						point->x -= 2;
					}
					if (sticktime->cx >= 300)
					{
						if (point->y >= 1)
						{
							point->y -= 1;
						}
						if (point->y < 0)
						{
							point->y += 2;
						}
					}
					for (int j = 0; j < rand() % 10 + 12; j++)
					{
						WriteBuffer(effect4[j]->x, effect4[j]->y, effect4[j]->shape, 연한빨간색);
						WriteBuffer(effect4[j]->cx, effect4[j]->y, effect4[j]->shape, 연한빨간색);
					}
					WriteBuffer(2, 27, " MISS", 빨간색);
					stick4[i]->act = false;
				}
			}
			if (sticktime->cx >= 240 && sticktime->cx < 300)
			{
				if (stick4[i]->y == 35)
				{
					if (point->x <= 0)
					{
						point->x += 1;
					}
					if (point->y >= 0)
					{
						if (point->y <= 62)
						{
							point->y += 21;
						}
					}

					for (int j = 0; j < rand() % 10 + 12; j++)
					{
						WriteBuffer(effect4[j]->x, effect4[j]->y, effect4[j]->shape, 연한초록색);
						WriteBuffer(effect4[j]->cx, effect4[j]->y, effect4[j]->shape, 연한초록색);
					}
					WriteBuffer(2, 27, "PERPECT", 초록색);
					stick4[i]->act = false;
				}
			}
		}
	}
}

void MenuRender2()
{
	WriteBuffer(28, 36, "←", 초록색);
	WriteBuffer(40, 36, "↑", 초록색);
	WriteBuffer(52, 36, "→", 초록색);
	for (int i = 1; i < WayNum - 1; i++)
	{
		WriteBuffer(way[i]->x, way[i]->y, way[i]->shape, 빨간색);
	}
	if (point->y >= 59)
	{
		WriteBuffer(2, 23, "ENTER", 192);
	}
	if (point->y < 59)
	{
		WriteBuffer(2, 23, "      ", 0);
	}
	//HP Bar
	for (int i = 0; i < Hpbar; i++)
	{
		if (point->x >= (-2)*i)
		{
			WriteBuffer(hpbar[i]->x, hpbar[i]->y, hpbar[i]->shape, 연한파란색);
		}
		WriteBuffer(hpbar[i]->x - 2, hpbar[i]->y, "Ι", 연한파란색);
		WriteBuffer(hpbar[i]->x + 2, hpbar[i]->y, "Ι", 연한파란색);
	}

	//Special Bar
	for (int i = 0; i < Hpbar; i++)
	{
		if (point->y >= 3 * i + 1)
		{
			WriteBuffer(specialbar[i]->x, specialbar[i]->y, specialbar[i]->shape, 연한빨간색);
		}
		WriteBuffer(specialbar[i]->x - 2, specialbar[i]->y, "Ι", 연한빨간색);
		WriteBuffer(specialbar[i]->x + 2, specialbar[i]->y, "Ι", 연한빨간색);
	}

	WriteBuffer(70, 34, "ESC", 회색);
	WriteBuffer(68, 35, "뒤로가기", 회색);

	if (menu2->x == 0)
	{
		WriteBuffer(27, 15, "리듬세계에 온걸 환영합니다.", 흰색);
		WriteBuffer(20, 17, "튜토리얼을 시작할려면 ENTER키를 눌러주세요.", 흰색);
	}
	// 1
	for (int i = 0; i < StickNum; i++)
	{
		if (stick2[i]->act == true)
		{
			if (point->y < 0)
			{
				WriteBuffer(stick2[i]->x, stick2[i]->y, point->shape, 진한노란색);
			}
			if (point->y >= 0)
			{
				WriteBuffer(stick2[i]->x, stick2[i]->y, stick2[i]->shape, 자주색);
			}
			if (sticktime->cx <= 180 || sticktime->cx > 300)
			{
				if (GetAsyncKeyState(VK_LEFT) & 0x8000)
				{
					if (stickcoolication2(stick2[i], way[1]) == true)
					{
						stick2[i]->act = false;
						if (stick2[i]->y == 35)
						{
							for (int j = 0; j < rand() % 10 + 12; j++)
							{
								WriteBuffer(effect2[j]->x, effect2[j]->y, effect2[j]->shape, 연한초록색);
								WriteBuffer(effect2[j]->cx, effect2[j]->y, effect2[j]->shape, 연한초록색);
							}
							WriteBuffer(2, 27, "PERPECT", 초록색);
							menu2->y = 2;
						}
						if (stick2[i]->y == 34 || stick2[i]->y == 36)
						{
							for (int j = 0; j < rand() % 10 + 12; j++)
							{
								WriteBuffer(effect2[j]->x, effect2[j]->y, effect2[j]->shape, 진한노란색);
								WriteBuffer(effect2[j]->cx, effect2[j]->y, effect2[j]->shape, 진한노란색);
							}
							WriteBuffer(2, 27, " GREAT", 노란색);
							menu2->y = 1;
						}
						if (sticktime->cx >= 300)
						{
							if (point->x <= 0)
							{
								point->x += 1;
							}
							if (point->y >= 0)
							{
								if (point->y <= 62)
								{
									point->y += 2;
								}
							}
							if (point->y < 0)
							{
								point->y += 2;
							}
						}
					}
				}
			}
		}
	}

	// 2
	for (int i = 0; i < StickNum; i++)
	{
		if (stick3[i]->act == true)
		{
			if (point->y < 0)
			{
				WriteBuffer(stick3[i]->x, stick3[i]->y, point->shape, 진한노란색);
			}
			if (point->y >= 0)
			{
				WriteBuffer(stick3[i]->x, stick3[i]->y, stick3[i]->shape, 자주색);
			}
			if (sticktime->cx <= 180 || sticktime->cx > 300)
			{
				if (GetAsyncKeyState(VK_UP) & 0x8000)
				{
					if (stickcoolication3(stick3[i], way[2]) == true)
					{
						stick3[i]->act = false;
						if (stick3[i]->y == 35)
						{
							for (int j = 0; j < rand() % 10 + 12; j++)
							{
								WriteBuffer(effect3[j]->x, effect3[j]->y, effect3[j]->shape, 연한초록색);
								WriteBuffer(effect3[j]->cx, effect3[j]->y, effect3[j]->shape, 연한초록색);
							}
							WriteBuffer(2, 27, "PERPECT", 초록색);
						}
						if (stick3[i]->y == 34 || stick3[i]->y == 36)
						{
							for (int j = 0; j < rand() % 10 + 12; j++)
							{
								WriteBuffer(effect3[j]->x, effect3[j]->y, effect3[j]->shape, 진한노란색);
								WriteBuffer(effect3[j]->cx, effect3[j]->y, effect3[j]->shape, 진한노란색);
							}
							WriteBuffer(2, 27, " GREAT", 노란색);
						}
						if (sticktime->cx >= 300)
						{
							if (point->x <= 0)
							{
								point->x += 1;
							}
							if (point->y >= 0)
							{
								if (point->y <= 62)
								{
									point->y += 2;
								}
							}
							if (point->y < 0)
							{
								point->y += 2;
							}
						}
					}
				}
			}
		}
	}

	// 3
	for (int i = 0; i < StickNum; i++)
	{
		if (stick4[i]->act == true)
		{
			if (point->y < 0)
			{
				WriteBuffer(stick4[i]->x, stick4[i]->y, point->shape, 진한노란색);
			}
			if (point->y >= 0)
			{
				WriteBuffer(stick4[i]->x, stick4[i]->y, stick4[i]->shape, 자주색);
			}
			if (sticktime->cx <= 180 || sticktime->cx > 300)
			{
				if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
				{
					if (stickcoolication4(stick4[i], way[3]) == true)
					{
						stick4[i]->act = false;
						if (stick4[i]->y == 35)
						{
							for (int j = 0; j < rand() % 10 + 12; j++)
							{
								WriteBuffer(effect4[j]->x, effect4[j]->y, effect4[j]->shape, 연한초록색);
								WriteBuffer(effect4[j]->cx, effect4[j]->y, effect4[j]->shape, 연한초록색);
							}
							WriteBuffer(2, 27, "PERPECT", 초록색);
						}
						if (stick4[i]->y == 34 || stick4[i]->y == 36)
						{
							for (int j = 0; j < rand() % 10 + 12; j++)
							{
								WriteBuffer(effect4[j]->x, effect4[j]->y, effect4[j]->shape, 진한노란색);
								WriteBuffer(effect4[j]->cx, effect4[j]->y, effect4[j]->shape, 진한노란색);
							}
							WriteBuffer(2, 27, " GREAT", 노란색);
						}
						if (sticktime->cx >= 300)
						{
							if (point->x <= 0)
							{
								point->x += 1;
							}
							if (point->y >= 0)
							{
								if (point->y <= 62)
								{
									point->y += 2;
								}
							}
							if (point->y < 0)
							{
								point->y += 2;
							}
						}
					}
				}
			}
		}
	}

	if (menu2->x == 2)
	{
		WriteBuffer(22, 15, "첫번째 줄에서 보라색 막대기가 내려오네요", 흰색);
		WriteBuffer(5, 17, "이제 막대기가 밑에 빨간색칸         에 도달하면 왼쪽화살표키를 누르세요", 흰색);
		WriteBuffer(33, 17, "[      ]", 빨간색);
	}
	if (menu2->x == 4)
	{
		if (menu2->y == 0)
		{
			WriteBuffer(18, 15, "이런 타이밍이 안 맞았네요 한번더 도전해볼까요", 흰색);
		}
		if (menu2->y == 1)
		{
			WriteBuffer(17, 15, "와우 GREAT네요 좀만 더 잘 맞추면 PERPECT이예요", 흰색);
		}
		if (menu2->y == 2)
		{
			WriteBuffer(28, 15, "대단해요!! PERPECT이예요", 흰색);
		}
	}
	if (menu2->x == 6)
	{
		WriteBuffer(20, 36, "☞", 진한노란색);
		WriteBuffer(60, 36, "☜", 진한노란색);
		WriteBuffer(22, 15, "아래쪽에 보시면 방향키가 보이네요", 흰색);
		WriteBuffer(17, 17, "보이시는 것과 같이 두번째 줄은 위쪽화살표키", 흰색);
		WriteBuffer(11, 18, "세번째 줄은 아래족화살표키를 타이밍에 맞춰 누르시면됩니다", 흰색);
		WriteBuffer(19, 20, "실전에서는 5개의 키가 있으니 유의해주세요", 흰색);
	}
	if (menu2->x == 7)
	{
		WriteBuffer(14, 15, "이제 체력 게이지바와 스폐셜 게이지바에 대해 설명할게요", 흰색);
	}
	if (menu2->x == 8)
	{
		for (int i = 0; i < 3; i++)
		{
			WriteBuffer(68, 4 + i * 2, "☞", 진한노란색);
		}
		WriteBuffer(24, 15, "오른쪽에 보이는게 체력바 입니다", 흰색);
		WriteBuffer(1, 17, "'MISS'가 뜨게되면 체력바가 줄어들고 체력바가 모두 없어지면 게임이 끝나게됩니다", 흰색);
		WriteBuffer(17, 19, "체력바가 없어져도 점수를 올리면 다시 생깁니다", 흰색);
	}
	if (menu2->x == 9)
	{
		for (int i = 0; i < 3; i++)
		{
			WriteBuffer(9, 4 + i * 2, "☜", 진한노란색);
		}
		WriteBuffer(22, 15, "다음으로 왼쪽에 보이는게 스폐셜바 입니다", 흰색);
		WriteBuffer(10, 17, "'GREAT' 또는 'PERPECT'로 점수를 올리면 스폐셜바가 올라갑니다", 흰색);
		WriteBuffer(1, 19, "스폐셜바가 끝까지 올라갔을때 'ENTER'키를 누르면 보라색 막대기가 별로 변환됩니다", 흰색);
		WriteBuffer(16, 20, "이때 점수를 많이 올릴 수 있으니 하나도 놓치지마세요★", 흰색);
	}
	if (menu2->x == 10)
	{
		WriteBuffer(23, 15, "이제 마지막 간단하게 한번 해볼까요?", 흰색);
	}
	if (menu2->x == 12)
	{
		WriteBuffer(22, 15, "훌륭합니다 이제 실전에서 도전해보세요", 흰색);
	}
}

void StageInit()
{
	for (int i = 0; i < StickNum; i++)
	{
		stick1[i] = (Stick1*)malloc(sizeof(Stick1));
		stick1[i]->x = 0;
		stick1[i]->y = 0;
		stick1[i]->shape = "■■■";
		stick1[i]->act = false;
	}

	for (int i = 0; i < StickNum; i++)
	{
		stick2[i] = (Stick2*)malloc(sizeof(Stick2));
		stick2[i]->x = 0;
		stick2[i]->y = 0;
		stick2[i]->shape = "■■■";
		stick2[i]->act = false;
	}

	for (int i = 0; i < StickNum; i++)
	{
		stick3[i] = (Stick3*)malloc(sizeof(Stick3));
		stick3[i]->x = 0;
		stick3[i]->y = 0;
		stick3[i]->shape = "■■■";
		stick3[i]->act = false;
	}

	for (int i = 0; i < StickNum; i++)
	{
		stick4[i] = (Stick4*)malloc(sizeof(Stick4));
		stick4[i]->x = 0;
		stick4[i]->y = 0;
		stick4[i]->shape = "■■■";
		stick4[i]->act = false;
	}

	for (int i = 0; i < StickNum; i++)
	{
		stick5[i] = (Stick5*)malloc(sizeof(Stick5));
		stick5[i]->x = 0;
		stick5[i]->y = 0;
		stick5[i]->shape = "■■■";
		stick5[i]->act = false;
	}

	for (int i = 0; i < WayNum; i++)
	{
		way[i] = (Way*)malloc(sizeof(Way));
		way[i]->x = 12 + i * 12;
		way[i]->y = 35;
		way[i]->shape = "［      ］";
	}

	point = (Point*)malloc(sizeof(Point));
	point->cx = 1; //콤보점수
	point->x = 0; //HpBar
	point->y = 0; //SpecialBar
	point->shape = "★★★";

	sticktime = (StickTime*)malloc(sizeof(StickTime));
	sticktime->cx = 0; // 스틱시간
	sticktime->x = 0; // 보너스점수
	sticktime->y = 0; // 보너스콤보점수

	stick1[0]->cx = 0; //일반점수
	stick1[1]->cx = rand() % 10 + 11;
	stick1[2]->cx = rand() % 10 + 14;
	stick1[3]->cx = 0; //최고점수(챌린지)
	stick1[5]->cx = 0;

	for (int i = 0; i < Hpbar; i++)
	{
		hpbar[i] = (HPbar*)malloc(sizeof(HPbar));
		hpbar[i]->x = BufferWidth - 6;
		hpbar[i]->y = 2 + i;
		hpbar[i]->shape = "■";
	}

	for (int i = 0; i < Hpbar; i++)
	{
		specialbar[i] = (Specialbar*)malloc(sizeof(Specialbar));
		specialbar[i]->x = 4;
		specialbar[i]->y = 1 + Hpbar - i;
		specialbar[i]->shape = "■";
	}

	for (int i = 0; i < EffactNum; i++)
	{
		effect[i] = (Effect*)malloc(sizeof(Effect));
		effect[i]->x = 11;
		effect[i]->cx = 21;
		effect[i]->y = 35 - i;
		effect[i]->shape = "■";
	}

	for (int i = 0; i < EffactNum; i++)
	{
		effect2[i] = (Effect2*)malloc(sizeof(Effect2));
		effect2[i]->x = 23;
		effect2[i]->cx = 33;
		effect2[i]->y = 35 - i;
		effect2[i]->shape = "■";
	}

	for (int i = 0; i < EffactNum; i++)
	{
		effect3[i] = (Effect3*)malloc(sizeof(Effect3));
		effect3[i]->x = 35;
		effect3[i]->cx = 45;
		effect3[i]->y = 35 - i;
		effect3[i]->shape = "■";
	}

	for (int i = 0; i < EffactNum; i++)
	{
		effect4[i] = (Effect4*)malloc(sizeof(Effect4));
		effect4[i]->x = 47;
		effect4[i]->cx = 57;
		effect4[i]->y = 35 - i;
		effect4[i]->shape = "■";
	}

	for (int i = 0; i < EffactNum; i++)
	{
		effect5[i] = (Effect5*)malloc(sizeof(Effect5));
		effect5[i]->x = 59;
		effect5[i]->cx = 69;
		effect5[i]->y = 35 - i;
		effect5[i]->shape = "■";
	}
}

void StageProgress()
{
	if (set2->y == 1)
	{
		if (sticktime->cx == 44 || sticktime->cx == 78 || sticktime->cx == 93 || sticktime->cx == 99 || sticktime->cx == 139 || sticktime->cx == 154
			|| sticktime->cx == 71 || sticktime->cx == 74 || sticktime->cx == 87 || sticktime->cx == 120 || sticktime->cx == 123 || sticktime->cx == 136
			|| sticktime->cx == 179 || sticktime->cx == 200 || sticktime->cx == 206 || sticktime->cx == 227 || sticktime->cx == 230 || sticktime->cx == 236
			|| sticktime->cx == 266 || sticktime->cx == 277 || sticktime->cx == 298 || sticktime->cx == 322 || sticktime->cx == 334 || sticktime->cx == 450
			|| sticktime->cx == 352 || sticktime->cx == 391 || sticktime->cx == 398 || sticktime->cx == 412 || sticktime->cx == 194 || sticktime->cx == 197
			|| sticktime->cx == 438 || sticktime->cx == 441 || sticktime->cx == 447 || sticktime->cx == 182 || sticktime->cx == 191 || sticktime->cx == 203
			|| sticktime->cx == 221 || sticktime->cx == 242 || sticktime->cx == 252 || sticktime->cx == 246 || sticktime->cx == 258 || sticktime->cx == 274
			|| sticktime->cx == 270 || sticktime->cx == 282 || sticktime->cx == 288 || sticktime->cx == 318 || sticktime->cx == 325 || sticktime->cx == 330
			|| sticktime->cx == 349 || sticktime->cx == 367 || sticktime->cx == 395 || sticktime->cx == 416 || sticktime->cx == 430 || sticktime->cx == 172
			|| sticktime->cx == 22 || sticktime->cx == 84 || sticktime->cx == 102 || sticktime->cx == 126 || sticktime->cx == 145 || sticktime->cx == 151
			|| sticktime->cx == 176 || sticktime->cx == 208 || sticktime->cx == 218 || sticktime->cx == 239 || sticktime->cx == 249 || sticktime->cx == 268
			|| sticktime->cx == 292 || sticktime->cx == 300 || sticktime->cx == 306 || sticktime->cx == 320 || sticktime->cx == 337 || sticktime->cx == 355
			|| sticktime->cx == 361 || sticktime->cx == 380 || sticktime->cx == 407 || sticktime->cx == 414 || sticktime->cx == 423 || sticktime->cx == 435
			|| sticktime->cx == 454 || sticktime->cx == 295 || sticktime->cx == 314 || sticktime->cx == 340 || sticktime->cx == 346 || sticktime->cx == 349
			|| sticktime->cx == 56 || sticktime->cx == 90 || sticktime->cx == 96 || sticktime->cx == 130 || sticktime->cx == 142 || sticktime->cx == 160
			|| sticktime->cx == 163 || sticktime->cx == 169 || sticktime->cx == 187 || sticktime->cx == 211 || sticktime->cx == 224 || sticktime->cx == 272
			|| sticktime->cx == 285 || sticktime->cx == 303 || sticktime->cx == 316 || sticktime->cx == 332 || sticktime->cx == 343 || sticktime->cx == 283
			|| sticktime->cx == 385 || sticktime->cx == 404 || sticktime->cx == 418 || sticktime->cx == 429 || sticktime->cx == 444 || sticktime->cx == 374
			|| sticktime->cx == 32 || sticktime->cx == 81 || sticktime->cx == 105 || sticktime->cx == 111 || sticktime->cx == 133 || sticktime->cx == 148
			|| sticktime->cx == 166 || sticktime->cx == 388 || sticktime->cx == 401 || sticktime->cx == 420 || sticktime->cx == 432 || sticktime->cx == 510
			|| sticktime->cx == 513 || sticktime->cx == 516 || sticktime->cx == 519 || sticktime->cx == 522 || sticktime->cx == 525 || sticktime->cx == 529
			|| sticktime->cx == 532 || sticktime->cx == 535 || sticktime->cx == 538 || sticktime->cx == 541 || sticktime->cx == 544 || sticktime->cx == 550
			|| sticktime->cx == 558 || sticktime->cx == 561 || sticktime->cx == 564 || sticktime->cx == 568 || sticktime->cx == 571 || sticktime->cx == 574
			|| sticktime->cx == 577 || sticktime->cx == 581 || sticktime->cx == 583 || sticktime->cx == 586 || sticktime->cx == 590 || sticktime->cx == 593
			|| sticktime->cx == 598 || sticktime->cx == 602 || sticktime->cx == 605 || sticktime->cx == 609 || sticktime->cx == 614 || sticktime->cx == 617
			|| sticktime->cx == 621 || sticktime->cx == 626 || sticktime->cx == 629 || sticktime->cx == 634 || sticktime->cx == 638 || sticktime->cx == 641
			|| sticktime->cx == 646 || sticktime->cx == 656 || sticktime->cx == 659 || sticktime->cx == 664 || sticktime->cx == 666 || sticktime->cx == 670
			|| sticktime->cx == 672 || sticktime->cx == 675 || sticktime->cx == 678 || sticktime->cx == 681 || sticktime->cx == 685 || sticktime->cx == 688
			|| sticktime->cx == 691 || sticktime->cx == 697 || sticktime->cx == 705 || sticktime->cx == 707 || sticktime->cx == 709 || sticktime->cx == 710
			|| sticktime->cx == 712 || sticktime->cx == 715 || sticktime->cx == 720 || sticktime->cx == 722 || sticktime->cx == 723 || sticktime->cx == 725
			|| sticktime->cx == 728 || sticktime->cx == 730 || sticktime->cx == 733 || sticktime->cx == 736 || sticktime->cx == 739 || sticktime->cx == 742
			|| sticktime->cx == 745 || sticktime->cx == 753 || sticktime->cx == 755 || sticktime->cx == 756 || sticktime->cx == 758 || sticktime->cx == 759
			|| sticktime->cx == 763 || sticktime->cx == 769 || sticktime->cx == 771 || sticktime->cx == 772 || sticktime->cx == 776 || sticktime->cx == 779
			|| sticktime->cx == 782 || sticktime->cx == 785 || sticktime->cx == 787 || sticktime->cx == 791 || sticktime->cx == 794 || sticktime->cx == 800
			|| sticktime->cx == 806 || sticktime->cx == 812 || sticktime->cx == 818 || sticktime->cx == 824 || sticktime->cx == 827 || sticktime->cx == 830
			|| sticktime->cx == 833 || sticktime->cx == 837 || sticktime->cx == 840 || sticktime->cx == 843 || sticktime->cx == 846 || sticktime->cx == 851
			|| sticktime->cx == 853 || sticktime->cx == 854 || sticktime->cx == 856 || sticktime->cx == 857 || sticktime->cx == 861 || sticktime->cx == 867
			|| sticktime->cx == 869 || sticktime->cx == 870 || sticktime->cx == 872 || sticktime->cx == 874 || sticktime->cx == 877 || sticktime->cx == 880
			|| sticktime->cx == 882 || sticktime->cx == 886 || sticktime->cx == 888 || sticktime->cx == 892 || sticktime->cx == 897 || sticktime->cx == 903
			|| sticktime->cx == 910 || sticktime->cx == 916 || sticktime->cx == 922 || sticktime->cx == 928 || sticktime->cx == 934 || sticktime->cx == 940
			|| sticktime->cx == 946 || sticktime->cx == 952 || sticktime->cx == 958 || sticktime->cx == 964 || sticktime->cx == 970 || sticktime->cx == 976
			|| sticktime->cx == 982 || sticktime->cx == 988 || sticktime->cx == 995 || sticktime->cx == 1001 || sticktime->cx == 1007 || sticktime->cx == 1013
			|| sticktime->cx == 1019 || sticktime->cx == 1025 || sticktime->cx == 1032 || sticktime->cx == 1037 || sticktime->cx == 1043 || sticktime->cx == 1090
			|| sticktime->cx == 1049 || sticktime->cx == 1056 || sticktime->cx == 1062 || sticktime->cx == 1068 || sticktime->cx == 1074 || sticktime->cx == 1080
			|| sticktime->cx == 1118 || sticktime->cx == 1120 || sticktime->cx == 1122 || sticktime->cx == 1125 || sticktime->cx == 1129 || sticktime->cx == 1135
			|| sticktime->cx == 1137 || sticktime->cx == 1138 || sticktime->cx == 1141 || sticktime->cx == 1144 || sticktime->cx == 1147 || sticktime->cx == 1150
			|| sticktime->cx == 1154 || sticktime->cx == 1156 || sticktime->cx == 1160 || sticktime->cx == 1168 || sticktime->cx == 1170 || sticktime->cx == 1171
			|| sticktime->cx == 1173 || sticktime->cx == 1174 || sticktime->cx == 1178 || sticktime->cx == 1183 || sticktime->cx == 1185 || sticktime->cx == 1187
			|| sticktime->cx == 1188 || sticktime->cx == 1191 || sticktime->cx == 1193 || sticktime->cx == 1196 || sticktime->cx == 1199 || sticktime->cx == 1202
			|| sticktime->cx == 1205 || sticktime->cx == 1208 || sticktime->cx == 1215 || sticktime->cx == 1220 || sticktime->cx == 1226 || sticktime->cx == 1232
			|| sticktime->cx == 1238 || sticktime->cx == 1241 || sticktime->cx == 1244 || sticktime->cx == 1248 || sticktime->cx == 1251 || sticktime->cx == 1254
			|| sticktime->cx == 1257 || sticktime->cx == 1260 || sticktime->cx == 1265 || sticktime->cx == 1267 || sticktime->cx == 1269 || sticktime->cx == 1270
			|| sticktime->cx == 1272 || sticktime->cx == 1275 || sticktime->cx == 1282 || sticktime->cx == 1283 || sticktime->cx == 1285 || sticktime->cx == 1306
			|| sticktime->cx == 1288 || sticktime->cx == 1291 || sticktime->cx == 1294 || sticktime->cx == 1297 || sticktime->cx == 1300 || sticktime->cx == 1303
			|| sticktime->cx == 1312 || sticktime->cx == 1318 || sticktime->cx == 1324 || sticktime->cx == 1330 || sticktime->cx == 1336 || sticktime->cx == 1342
			|| sticktime->cx == 1348 || sticktime->cx == 1354 || sticktime->cx == 1361 || sticktime->cx == 1367 || sticktime->cx == 1373 || sticktime->cx == 1378
			|| sticktime->cx == 1384 || sticktime->cx == 1388 || sticktime->cx == 1391 || sticktime->cx == 1394 || sticktime->cx == 1398 || sticktime->cx == 1406
			|| sticktime->cx == 1412 || sticktime->cx == 1416 || sticktime->cx == 1419 || sticktime->cx == 1422 || sticktime->cx == 1425 || sticktime->cx == 1428
			|| sticktime->cx == 1431 || sticktime->cx == 1434 || sticktime->cx == 1437 || sticktime->cx == 1440 || sticktime->cx == 1444 || sticktime->cx == 1446
			|| sticktime->cx == 1452 || sticktime->cx == 1458 || sticktime->cx == 1461 || sticktime->cx == 1464 || sticktime->cx == 1467 || sticktime->cx == 1470
			|| sticktime->cx == 1474 || sticktime->cx == 1477 || sticktime->cx == 1483 || sticktime->cx == 1489 || sticktime->cx == 1495)
		{
			if (sticktime->cx % 5 == 0)
			{
				stick1[5]->cx = 1;
			}
			else if (sticktime->cx % 5 == 1)
			{
				stick1[5]->cx = 2;
			}
			else if (sticktime->cx % 5 == 2)
			{
				stick1[5]->cx = 3;
			}
			else if (sticktime->cx % 5 == 3)
			{
				stick1[5]->cx = 4;
			}
			else if (sticktime->cx % 5 == 4)
			{
				stick1[5]->cx = 5;
			}
		}
	}

	if (set2->y == 2)
	{
		if (sticktime->cx == 64 || sticktime->cx == 495 || sticktime->cx == 923 || sticktime->cx == 1309 || sticktime->cx == 1724 || sticktime->cx == 2221 || sticktime->cx == 2503
			|| sticktime->cx == 81 || sticktime->cx == 497 || sticktime->cx == 929 || sticktime->cx == 1314 || sticktime->cx == 1735 || sticktime->cx == 2226 || sticktime->cx == 2509
			|| sticktime->cx == 102 || sticktime->cx == 500 || sticktime->cx == 935 || sticktime->cx == 1319 || sticktime->cx == 1746 || sticktime->cx == 2232 || sticktime->cx == 2512
			|| sticktime->cx == 123 || sticktime->cx == 504 || sticktime->cx == 939 || sticktime->cx == 1324 || sticktime->cx == 1757 || sticktime->cx == 2241 || sticktime->cx == 2505
			|| sticktime->cx == 145 || sticktime->cx == 512 || sticktime->cx == 946 || sticktime->cx == 1330 || sticktime->cx == 1768 || sticktime->cx == 2244 || sticktime->cx == 2520
			|| sticktime->cx == 154 || sticktime->cx == 520 || sticktime->cx == 952 || sticktime->cx == 1346 || sticktime->cx == 1779 || sticktime->cx == 2246 || sticktime->cx == 2523
			|| sticktime->cx == 165 || sticktime->cx == 523 || sticktime->cx == 957 || sticktime->cx == 1348 || sticktime->cx == 1790 || sticktime->cx == 2249 || sticktime->cx == 2526
			|| sticktime->cx == 176 || sticktime->cx == 525 || sticktime->cx == 961 || sticktime->cx == 1351 || sticktime->cx == 1800 || sticktime->cx == 2252 || sticktime->cx == 2528
			|| sticktime->cx == 184 || sticktime->cx == 531 || sticktime->cx == 966 || sticktime->cx == 1354 || sticktime->cx == 1810 || sticktime->cx == 2258 || sticktime->cx == 2535
			|| sticktime->cx == 189 || sticktime->cx == 536 || sticktime->cx == 973 || sticktime->cx == 1356 || sticktime->cx == 1821 || sticktime->cx == 2268 || sticktime->cx == 2541
			|| sticktime->cx == 193 || sticktime->cx == 542 || sticktime->cx == 979 || sticktime->cx == 1362 || sticktime->cx == 1831 || sticktime->cx == 2271 || sticktime->cx == 2547
			|| sticktime->cx == 199 || sticktime->cx == 547 || sticktime->cx == 1004 || sticktime->cx == 1373 || sticktime->cx == 1842 || sticktime->cx == 2274 || sticktime->cx == 2552
			|| sticktime->cx == 205 || sticktime->cx == 552 || sticktime->cx == 1009 || sticktime->cx == 1376 || sticktime->cx == 1853 || sticktime->cx == 2280 || sticktime->cx == 2558
			|| sticktime->cx == 211 || sticktime->cx == 557 || sticktime->cx == 1013 || sticktime->cx == 1379 || sticktime->cx == 1864 || sticktime->cx == 2286 || sticktime->cx == 2567
			|| sticktime->cx == 221 || sticktime->cx == 563 || sticktime->cx == 1020 || sticktime->cx == 1384 || sticktime->cx == 1875 || sticktime->cx == 2292 || sticktime->cx == 2581
			|| sticktime->cx == 237 || sticktime->cx == 576 || sticktime->cx == 1025 || sticktime->cx == 1388 || sticktime->cx == 1885 || sticktime->cx == 2296 || sticktime->cx == 2584
			|| sticktime->cx == 242 || sticktime->cx == 579 || sticktime->cx == 1031 || sticktime->cx == 1395 || sticktime->cx == 1895 || sticktime->cx == 2300 || sticktime->cx == 2586
			|| sticktime->cx == 246 || sticktime->cx == 582 || sticktime->cx == 1037 || sticktime->cx == 1400 || sticktime->cx == 1906 || sticktime->cx == 2306 || sticktime->cx == 2594
			|| sticktime->cx == 252 || sticktime->cx == 585 || sticktime->cx == 1041 || sticktime->cx == 1406 || sticktime->cx == 1917 || sticktime->cx == 2312 || sticktime->cx == 2596
			|| sticktime->cx == 258 || sticktime->cx == 588 || sticktime->cx == 1048 || sticktime->cx == 1409 || sticktime->cx == 1933 || sticktime->cx == 2324 || sticktime->cx == 2600
			|| sticktime->cx == 264 || sticktime->cx == 591 || sticktime->cx == 1052 || sticktime->cx == 1416 || sticktime->cx == 1982 || sticktime->cx == 2327 || sticktime->cx == 2605
			|| sticktime->cx == 268 || sticktime->cx == 597 || sticktime->cx == 1058 || sticktime->cx == 1425 || sticktime->cx == 1987 || sticktime->cx == 2329 || sticktime->cx == 2608
			|| sticktime->cx == 273 || sticktime->cx == 605 || sticktime->cx == 1063 || sticktime->cx == 1434 || sticktime->cx == 1989 || sticktime->cx == 2332 || sticktime->cx == 2611
			|| sticktime->cx == 279 || sticktime->cx == 607 || sticktime->cx == 1073 || sticktime->cx == 1446 || sticktime->cx == 1992 || sticktime->cx == 2338 || sticktime->cx == 2614
			|| sticktime->cx == 285 || sticktime->cx == 611 || sticktime->cx == 1079 || sticktime->cx == 1456 || sticktime->cx == 1995 || sticktime->cx == 2341 || sticktime->cx == 2616
			|| sticktime->cx == 290 || sticktime->cx == 616 || sticktime->cx == 1084 || sticktime->cx == 1467 || sticktime->cx == 2002 || sticktime->cx == 2344 || sticktime->cx == 2626
			|| sticktime->cx == 294 || sticktime->cx == 621 || sticktime->cx == 1092 || sticktime->cx == 1501 || sticktime->cx == 2013 || sticktime->cx == 2349
			|| sticktime->cx == 305 || sticktime->cx == 627 || sticktime->cx == 1099 || sticktime->cx == 1473 || sticktime->cx == 2015 || sticktime->cx == 2352
			|| sticktime->cx == 312 || sticktime->cx == 632 || sticktime->cx == 1105 || sticktime->cx == 1479 || sticktime->cx == 2018 || sticktime->cx == 2355
			|| sticktime->cx == 316 || sticktime->cx == 638 || sticktime->cx == 1114 || sticktime->cx == 1484 || sticktime->cx == 2024 || sticktime->cx == 2358
			|| sticktime->cx == 322 || sticktime->cx == 643 || sticktime->cx == 1120 || sticktime->cx == 1490 || sticktime->cx == 2030 || sticktime->cx == 2368
			|| sticktime->cx == 328 || sticktime->cx == 648 || sticktime->cx == 1126 || sticktime->cx == 1495 || sticktime->cx == 2035 || sticktime->cx == 2371
			|| sticktime->cx == 333 || sticktime->cx == 657 || sticktime->cx == 1135 || sticktime->cx == 1507 || sticktime->cx == 2039 || sticktime->cx == 2374
			|| sticktime->cx == 337 || sticktime->cx == 668 || sticktime->cx == 1142 || sticktime->cx == 1515 || sticktime->cx == 2046 || sticktime->cx == 2376
			|| sticktime->cx == 344 || sticktime->cx == 679 || sticktime->cx == 1148 || sticktime->cx == 1518 || sticktime->cx == 2049 || sticktime->cx == 2381
			|| sticktime->cx == 352 || sticktime->cx == 689 || sticktime->cx == 1156 || sticktime->cx == 1521 || sticktime->cx == 2055 || sticktime->cx == 2384
			|| sticktime->cx == 355 || sticktime->cx == 698 || sticktime->cx == 1172 || sticktime->cx == 1523 || sticktime->cx == 2071 || sticktime->cx == 2387
			|| sticktime->cx == 359 || sticktime->cx == 704 || sticktime->cx == 1179 || sticktime->cx == 1526 || sticktime->cx == 2073 || sticktime->cx == 2393
			|| sticktime->cx == 365 || sticktime->cx == 710 || sticktime->cx == 1185 || sticktime->cx == 1533 || sticktime->cx == 2076 || sticktime->cx == 2395
			|| sticktime->cx == 368 || sticktime->cx == 716 || sticktime->cx == 1196 || sticktime->cx == 1543 || sticktime->cx == 2079 || sticktime->cx == 2398
			|| sticktime->cx == 371 || sticktime->cx == 722 || sticktime->cx == 1202 || sticktime->cx == 1546 || sticktime->cx == 2082 || sticktime->cx == 2403
			|| sticktime->cx == 376 || sticktime->cx == 726 || sticktime->cx == 1208 || sticktime->cx == 1549 || sticktime->cx == 2089 || sticktime->cx == 2406
			|| sticktime->cx == 378 || sticktime->cx == 732 || sticktime->cx == 1210 || sticktime->cx == 1554 || sticktime->cx == 2098 || sticktime->cx == 2408
			|| sticktime->cx == 381 || sticktime->cx == 738 || sticktime->cx == 1213 || sticktime->cx == 1560 || sticktime->cx == 2101 || sticktime->cx == 2414
			|| sticktime->cx == 387 || sticktime->cx == 747 || sticktime->cx == 1218 || sticktime->cx == 1566 || sticktime->cx == 2104 || sticktime->cx == 2416
			|| sticktime->cx == 392 || sticktime->cx == 751 || sticktime->cx == 1222 || sticktime->cx == 1571 || sticktime->cx == 2109 || sticktime->cx == 2423
			|| sticktime->cx == 396 || sticktime->cx == 754 || sticktime->cx == 1229 || sticktime->cx == 1576 || sticktime->cx == 2114 || sticktime->cx == 2425
			|| sticktime->cx == 406 || sticktime->cx == 757 || sticktime->cx == 1191 || sticktime->cx == 1582 || sticktime->cx == 2120 || sticktime->cx == 2429
			|| sticktime->cx == 413 || sticktime->cx == 760 || sticktime->cx == 1234 || sticktime->cx == 1587 || sticktime->cx == 2124 || sticktime->cx == 2434
			|| sticktime->cx == 417 || sticktime->cx == 765 || sticktime->cx == 1245 || sticktime->cx == 1598 || sticktime->cx == 2130 || sticktime->cx == 2437
			|| sticktime->cx == 422 || sticktime->cx == 775 || sticktime->cx == 1259 || sticktime->cx == 1607 || sticktime->cx == 2135 || sticktime->cx == 2440
			|| sticktime->cx == 428 || sticktime->cx == 778 || sticktime->cx == 1262 || sticktime->cx == 1618 || sticktime->cx == 2142 || sticktime->cx == 2442
			|| sticktime->cx == 431 || sticktime->cx == 781 || sticktime->cx == 1264 || sticktime->cx == 1628 || sticktime->cx == 2151 || sticktime->cx == 2445
			|| sticktime->cx == 438 || sticktime->cx == 786 || sticktime->cx == 1267 || sticktime->cx == 1639 || sticktime->cx == 2160 || sticktime->cx == 2450
			|| sticktime->cx == 444 || sticktime->cx == 792 || sticktime->cx == 1270 || sticktime->cx == 1650 || sticktime->cx == 2172 || sticktime->cx == 2456
			|| sticktime->cx == 450 || sticktime->cx == 796 || sticktime->cx == 1277 || sticktime->cx == 1660 || sticktime->cx == 2182 || sticktime->cx == 2461
			|| sticktime->cx == 456 || sticktime->cx == 803 || sticktime->cx == 1286 || sticktime->cx == 1671 || sticktime->cx == 2193 || sticktime->cx == 2466
			|| sticktime->cx == 461 || sticktime->cx == 809 || sticktime->cx == 1289 || sticktime->cx == 1682 || sticktime->cx == 2197 || sticktime->cx == 2472
			|| sticktime->cx == 467 || sticktime->cx == 813 || sticktime->cx == 1292 || sticktime->cx == 1691 || sticktime->cx == 2204 || sticktime->cx == 2485
			|| sticktime->cx == 476 || sticktime->cx == 819 || sticktime->cx == 1298 || sticktime->cx == 1702 || sticktime->cx == 2210 || sticktime->cx == 2497
			|| sticktime->cx == 492 || sticktime->cx == 915 || sticktime->cx == 1304 || sticktime->cx == 1713 || sticktime->cx == 2215 || sticktime->cx == 2499
			)
		{
			if (sticktime->cx % 5 == 0)
			{
				stick1[5]->cx = 1;
			}
			else if (sticktime->cx % 5 == 1)
			{
				stick1[5]->cx = 2;
			}
			else if (sticktime->cx % 5 == 2)
			{
				stick1[5]->cx = 3;
			}
			else if (sticktime->cx % 5 == 3)
			{
				stick1[5]->cx = 4;
			}
			else if (sticktime->cx % 5 == 4)
			{
				stick1[5]->cx = 5;
			}
		}
	}

	if (set2->y == 3)
	{
		if (sticktime->cx == 98 || sticktime->cx == 648 || sticktime->cx == 1119 || sticktime->cx == 1743 || sticktime->cx == 2282 || sticktime->cx == 2956 || sticktime->cx == 3357
			|| sticktime->cx == 120 || sticktime->cx == 668 || sticktime->cx == 1237 || sticktime->cx == 1750 || sticktime->cx == 2296 || sticktime->cx == 2964 || sticktime->cx == 3361
			|| sticktime->cx == 150 || sticktime->cx == 671 || sticktime->cx == 1244 || sticktime->cx == 1757 || sticktime->cx == 2310 || sticktime->cx == 2970 || sticktime->cx == 3364
			|| sticktime->cx == 176 || sticktime->cx == 675 || sticktime->cx == 1251 || sticktime->cx == 1765 || sticktime->cx == 2325 || sticktime->cx == 2976 || sticktime->cx == 3371
			|| sticktime->cx == 212 || sticktime->cx == 680 || sticktime->cx == 1259 || sticktime->cx == 1772 || sticktime->cx == 2340 || sticktime->cx == 2984 || sticktime->cx == 3375
			|| sticktime->cx == 219 || sticktime->cx == 683 || sticktime->cx == 1265 || sticktime->cx == 1779 || sticktime->cx == 2354 || sticktime->cx == 2999 || sticktime->cx == 3379
			|| sticktime->cx == 226 || sticktime->cx == 692 || sticktime->cx == 1272 || sticktime->cx == 1786 || sticktime->cx == 2368 || sticktime->cx == 3003 || sticktime->cx == 3382
			|| sticktime->cx == 234 || sticktime->cx == 705 || sticktime->cx == 1279 || sticktime->cx == 1804 || sticktime->cx == 2382 || sticktime->cx == 3007 || sticktime->cx == 3385
			|| sticktime->cx == 241 || sticktime->cx == 708 || sticktime->cx == 1286 || sticktime->cx == 1808 || sticktime->cx == 2397 || sticktime->cx == 3011 || sticktime->cx == 3398
			|| sticktime->cx == 249 || sticktime->cx == 712 || sticktime->cx == 1293 || sticktime->cx == 1811 || sticktime->cx == 2411 || sticktime->cx == 3014 || sticktime->cx == 3401
			|| sticktime->cx == 256 || sticktime->cx == 720 || sticktime->cx == 1300 || sticktime->cx == 1815 || sticktime->cx == 2425 || sticktime->cx == 3023 || sticktime->cx == 3404
			|| sticktime->cx == 264 || sticktime->cx == 727 || sticktime->cx == 1308 || sticktime->cx == 1819 || sticktime->cx == 2439 || sticktime->cx == 3036 || sticktime->cx == 3411
			|| sticktime->cx == 270 || sticktime->cx == 734 || sticktime->cx == 1316 || sticktime->cx == 1829 || sticktime->cx == 2453 || sticktime->cx == 3039 || sticktime->cx == 3420
			|| sticktime->cx == 278 || sticktime->cx == 740 || sticktime->cx == 1328 || sticktime->cx == 1842 || sticktime->cx == 2468 || sticktime->cx == 3043 || sticktime->cx == 3436
			|| sticktime->cx == 285 || sticktime->cx == 747 || sticktime->cx == 1348 || sticktime->cx == 1846 || sticktime->cx == 2482 || sticktime->cx == 3051 || sticktime->cx == 3454
			|| sticktime->cx == 293 || sticktime->cx == 754 || sticktime->cx == 1354 || sticktime->cx == 1849 || sticktime->cx == 2496 || sticktime->cx == 3058 || sticktime->cx == 3458
			|| sticktime->cx == 306 || sticktime->cx == 761 || sticktime->cx == 1362 || sticktime->cx == 1856 || sticktime->cx == 2511 || sticktime->cx == 3065 || sticktime->cx == 3461
			|| sticktime->cx == 324 || sticktime->cx == 780 || sticktime->cx == 1371 || sticktime->cx == 1864 || sticktime->cx == 2525 || sticktime->cx == 3071 || sticktime->cx == 3467
			|| sticktime->cx == 331 || sticktime->cx == 784 || sticktime->cx == 1379 || sticktime->cx == 1871 || sticktime->cx == 2539 || sticktime->cx == 3079 || sticktime->cx == 3476
			|| sticktime->cx == 340 || sticktime->cx == 787 || sticktime->cx == 1386 || sticktime->cx == 1878 || sticktime->cx == 2553 || sticktime->cx == 3086 || sticktime->cx == 3484
			|| sticktime->cx == 348 || sticktime->cx == 791 || sticktime->cx == 1393 || sticktime->cx == 1885 || sticktime->cx == 2568 || sticktime->cx == 3093 || sticktime->cx == 3488
			|| sticktime->cx == 355 || sticktime->cx == 795 || sticktime->cx == 1400 || sticktime->cx == 1892 || sticktime->cx == 2590 || sticktime->cx == 3111 || sticktime->cx == 3492
			|| sticktime->cx == 363 || sticktime->cx == 804 || sticktime->cx == 1407 || sticktime->cx == 1899 || sticktime->cx == 2659 || sticktime->cx == 3115 || sticktime->cx == 3495
			|| sticktime->cx == 370 || sticktime->cx == 819 || sticktime->cx == 1414 || sticktime->cx == 1912 || sticktime->cx == 2662 || sticktime->cx == 3119 || sticktime->cx == 3499
			|| sticktime->cx == 377 || sticktime->cx == 822 || sticktime->cx == 1421 || sticktime->cx == 1925 || sticktime->cx == 2666 || sticktime->cx == 3128 || sticktime->cx == 3508
			|| sticktime->cx == 384 || sticktime->cx == 826 || sticktime->cx == 1428 || sticktime->cx == 1939 || sticktime->cx == 2669 || sticktime->cx == 3133
			|| sticktime->cx == 391 || sticktime->cx == 834 || sticktime->cx == 1442 || sticktime->cx == 1954 || sticktime->cx == 2673 || sticktime->cx == 3137
			|| sticktime->cx == 398 || sticktime->cx == 840 || sticktime->cx == 1450 || sticktime->cx == 1968 || sticktime->cx == 2682 || sticktime->cx == 3145
			|| sticktime->cx == 405 || sticktime->cx == 847 || sticktime->cx == 1457 || sticktime->cx == 1975 || sticktime->cx == 2695 || sticktime->cx == 3148
			|| sticktime->cx == 419 || sticktime->cx == 854 || sticktime->cx == 1467 || sticktime->cx == 1983 || sticktime->cx == 2699 || sticktime->cx == 3152
			|| sticktime->cx == 428 || sticktime->cx == 860 || sticktime->cx == 1476 || sticktime->cx == 1990 || sticktime->cx == 2703 || sticktime->cx == 3156
			|| sticktime->cx == 434 || sticktime->cx == 868 || sticktime->cx == 1484 || sticktime->cx == 1997 || sticktime->cx == 2710 || sticktime->cx == 3169
			|| sticktime->cx == 441 || sticktime->cx == 875 || sticktime->cx == 1495 || sticktime->cx == 2004 || sticktime->cx == 2717 || sticktime->cx == 3173
			|| sticktime->cx == 447 || sticktime->cx == 889 || sticktime->cx == 1505 || sticktime->cx == 2011 || sticktime->cx == 2724 || sticktime->cx == 3176
			|| sticktime->cx == 455 || sticktime->cx == 902 || sticktime->cx == 1513 || sticktime->cx == 2018 || sticktime->cx == 2731 || sticktime->cx == 3180
			|| sticktime->cx == 462 || sticktime->cx == 916 || sticktime->cx == 1523 || sticktime->cx == 2032 || sticktime->cx == 2739 || sticktime->cx == 3187
			|| sticktime->cx == 469 || sticktime->cx == 929 || sticktime->cx == 1534 || sticktime->cx == 2036 || sticktime->cx == 2745 || sticktime->cx == 3194
			|| sticktime->cx == 481 || sticktime->cx == 944 || sticktime->cx == 1541 || sticktime->cx == 2040 || sticktime->cx == 2753 || sticktime->cx == 3201
			|| sticktime->cx == 484 || sticktime->cx == 951 || sticktime->cx == 1552 || sticktime->cx == 2043 || sticktime->cx == 2773 || sticktime->cx == 3205
			|| sticktime->cx == 492 || sticktime->cx == 958 || sticktime->cx == 1577 || sticktime->cx == 2047 || sticktime->cx == 2777 || sticktime->cx == 3209
			|| sticktime->cx == 499 || sticktime->cx == 966 || sticktime->cx == 1584 || sticktime->cx == 2055 || sticktime->cx == 2781 || sticktime->cx == 3216
			|| sticktime->cx == 502 || sticktime->cx == 974 || sticktime->cx == 1591 || sticktime->cx == 2069 || sticktime->cx == 2785 || sticktime->cx == 3219
			|| sticktime->cx == 506 || sticktime->cx == 981 || sticktime->cx == 1599 || sticktime->cx == 2073 || sticktime->cx == 2788 || sticktime->cx == 3227
			|| sticktime->cx == 513 || sticktime->cx == 988 || sticktime->cx == 1606 || sticktime->cx == 2077 || sticktime->cx == 2796 || sticktime->cx == 3231
			|| sticktime->cx == 517 || sticktime->cx == 995 || sticktime->cx == 1614 || sticktime->cx == 2083 || sticktime->cx == 2809 || sticktime->cx == 3234
			|| sticktime->cx == 520 || sticktime->cx == 1009 || sticktime->cx == 1621 || sticktime->cx == 2091 || sticktime->cx == 2813 || sticktime->cx == 3242
			|| sticktime->cx == 527 || sticktime->cx == 1012 || sticktime->cx == 1628 || sticktime->cx == 2098 || sticktime->cx == 2816 || sticktime->cx == 3246
			|| sticktime->cx == 534 || sticktime->cx == 1016 || sticktime->cx == 1635 || sticktime->cx == 2105 || sticktime->cx == 2823 || sticktime->cx == 3250
			|| sticktime->cx == 541 || sticktime->cx == 1020 || sticktime->cx == 1643 || sticktime->cx == 2112 || sticktime->cx == 2830 || sticktime->cx == 3258
			|| sticktime->cx == 554 || sticktime->cx == 1024 || sticktime->cx == 1650 || sticktime->cx == 2120 || sticktime->cx == 2837 || sticktime->cx == 3261
			|| sticktime->cx == 562 || sticktime->cx == 1031 || sticktime->cx == 1657 || sticktime->cx == 2127 || sticktime->cx == 2843 || sticktime->cx == 3265
			|| sticktime->cx == 569 || sticktime->cx == 1046 || sticktime->cx == 1671 || sticktime->cx == 2141 || sticktime->cx == 2849 || sticktime->cx == 3268
			|| sticktime->cx == 576 || sticktime->cx == 1049 || sticktime->cx == 1691 || sticktime->cx == 2154 || sticktime->cx == 2857 || sticktime->cx == 3272
			|| sticktime->cx == 584 || sticktime->cx == 1053 || sticktime->cx == 1695 || sticktime->cx == 2168 || sticktime->cx == 2864 || sticktime->cx == 3279
			|| sticktime->cx == 587 || sticktime->cx == 1060 || sticktime->cx == 1699 || sticktime->cx == 2182 || sticktime->cx == 2879 || sticktime->cx == 3286
			|| sticktime->cx == 597 || sticktime->cx == 1067 || sticktime->cx == 1703 || sticktime->cx == 2197 || sticktime->cx == 2892 || sticktime->cx == 3293
			|| sticktime->cx == 605 || sticktime->cx == 1074 || sticktime->cx == 1706 || sticktime->cx == 2211 || sticktime->cx == 2907 || sticktime->cx == 3300
			|| sticktime->cx == 611 || sticktime->cx == 1081 || sticktime->cx == 1715 || sticktime->cx == 2225 || sticktime->cx == 2922 || sticktime->cx == 3307
			|| sticktime->cx == 619 || sticktime->cx == 1088 || sticktime->cx == 1728 || sticktime->cx == 2239 || sticktime->cx == 2935 || sticktime->cx == 3326
			|| sticktime->cx == 626 || sticktime->cx == 1095 || sticktime->cx == 1731 || sticktime->cx == 2253 || sticktime->cx == 2943 || sticktime->cx == 3342
			|| sticktime->cx == 634 || sticktime->cx == 1102 || sticktime->cx == 1735 || sticktime->cx == 2268 || sticktime->cx == 2950 || sticktime->cx == 3350
			)
		{
			if (sticktime->cx % 5 == 0)
			{
				stick1[5]->cx = 1;
			}
			else if (sticktime->cx % 5 == 1)
			{
				stick1[5]->cx = 2;
			}
			else if (sticktime->cx % 5 == 2)
			{
				stick1[5]->cx = 3;
			}
			else if (sticktime->cx % 5 == 3)
			{
				stick1[5]->cx = 4;
			}
			else if (sticktime->cx % 5 == 4)
			{
				stick1[5]->cx = 5;
			}
		}
	}

	//3
	for (int i = 0; i < StickNum; i++)
	{
		if (stick3[i]->act == false)
		{
			if (stick1[5]->cx == 3)
			{
				stick3[i]->x = 38;
				stick3[i]->y = 1;
				stick3[i]->act = true;
				stick1[5]->cx = 0;
				break;
			}

		}
	}

	for (int i = 0; i < StickNum; i++)
	{
		if (stick3[i]->act == true)
		{
			stick3[i]->y++;
			if (stick3[i]->y == 38)
			{
				point->cx = 1;
				point->x -= 6;
				if (point->y >= 1)
				{
					point->y -= 1;
				}
				if (point->y < 0)
				{
					point->y += 2;
				}
				for (int j = 0; j < rand() % 10 + 12; j++)
				{
					WriteBuffer(effect3[j]->x, effect3[j]->y, effect3[j]->shape, 연한빨간색);
					WriteBuffer(effect3[j]->cx, effect3[j]->y, effect3[j]->shape, 연한빨간색);
				}
				WriteBuffer(2, 27, " MISS", 빨간색);
				stick3[i]->act = false;
			}
		}
	}

	// 1
	for (int i = 0; i < StickNum; i++)
	{
		if (stick1[i]->act == false)
		{
			if (stick1[5]->cx == 1)
			{
				stick1[i]->x = 14;
				stick1[i]->y = 1;
				stick1[i]->act = true;
				stick1[5]->cx = 0;
				break;
			}
		}
	}

	for (int i = 0; i < StickNum; i++)
	{
		if (stick1[i]->act == true)
		{
			stick1[i]->y++;
			if (stick1[i]->y == 38)
			{
				point->cx = 1;
				point->x -= 6;
				if (point->y >= 1)
				{
					point->y -= 1;
				}
				if (point->y < 0)
				{
					point->y += 2;
				}
				for (int j = 0; j < rand() % 10 + 12; j++)
				{
					WriteBuffer(effect[j]->x, effect[j]->y, effect[j]->shape, 연한빨간색);
					WriteBuffer(effect[j]->cx, effect[j]->y, effect[j]->shape, 연한빨간색);
				}
				WriteBuffer(2, 27, " MISS", 빨간색);
				stick1[i]->act = false;
			}
		}
	}

	//2
	for (int i = 0; i < StickNum; i++)
	{
		if (stick2[i]->act == false)
		{
			if (stick1[5]->cx == 2)
			{
				stick2[i]->x = 26;
				stick2[i]->y = 1;
				stick2[i]->act = true;
				stick1[5]->cx = 0;
				break;
			}
		}
	}

	for (int i = 0; i < StickNum; i++)
	{
		if (stick2[i]->act == true)
		{
			stick2[i]->y++;
			if (stick2[i]->y == 38)
			{
				point->cx = 1;
				point->x -= 6;
				if (point->y >= 1)
				{
					point->y -= 1;
				}
				if (point->y < 0)
				{
					point->y += 2;
				}
				for (int j = 0; j < rand() % 10 + 12; j++)
				{
					WriteBuffer(effect2[j]->x, effect2[j]->y, effect2[j]->shape, 연한빨간색);
					WriteBuffer(effect2[j]->cx, effect2[j]->y, effect2[j]->shape, 연한빨간색);
				}
				WriteBuffer(2, 27, " MISS", 빨간색);
				stick2[i]->act = false;
			}
		}
	}

	//4
	for (int i = 0; i < StickNum; i++)
	{
		if (stick4[i]->act == false)
		{
			if (stick1[5]->cx == 4)
			{
				stick4[i]->x = 50;
				stick4[i]->y = 1;
				stick4[i]->act = true;
				stick1[5]->cx = 0;
				break;
			}
		}
	}

	for (int i = 0; i < StickNum; i++)
	{
		if (stick4[i]->act == true)
		{
			stick4[i]->y++;
			if (stick4[i]->y == 38)
			{
				point->cx = 1;
				point->x -= 6;
				if (point->y >= 1)
				{
					point->y -= 1;
				}
				if (point->y < 0)
				{
					point->y += 2;
				}
				for (int j = 0; j < rand() % 10 + 12; j++)
				{
					WriteBuffer(effect4[j]->x, effect4[j]->y, effect4[j]->shape, 연한빨간색);
					WriteBuffer(effect4[j]->cx, effect4[j]->y, effect4[j]->shape, 연한빨간색);
				}
				WriteBuffer(2, 27, " MISS", 빨간색);
				stick4[i]->act = false;
			}
		}
	}

	//5
	for (int i = 0; i < StickNum; i++)
	{
		if (stick5[i]->act == false)
		{
			if (stick1[5]->cx == 5)
			{
				stick5[i]->x = 62;
				stick5[i]->y = 1;
				stick5[i]->act = true;
				stick1[5]->cx = 0;
				break;
			}
		}
	}

	for (int i = 0; i < StickNum; i++)
	{
		if (stick5[i]->act == true)
		{
			stick5[i]->y++;
			if (stick5[i]->y == 38)
			{
				point->cx = 1;
				point->x -= 6;
				if (point->y >= 1)
				{
					point->y -= 1;
				}
				if (point->y < 0)
				{
					point->y += 2;
				}
				for (int j = 0; j < rand() % 10 + 12; j++)
				{
					WriteBuffer(effect5[j]->x, effect5[j]->y, effect5[j]->shape, 연한빨간색);
					WriteBuffer(effect5[j]->cx, effect5[j]->y, effect5[j]->shape, 연한빨간색);
				}
				WriteBuffer(2, 27, " MISS", 빨간색);
				stick5[i]->act = false;
			}
		}
	}

	if (point->y >= 59)
	{
		if (GetAsyncKeyState(VK_RETURN) & 0x0001)
		{
			point->y = -20;
		}
	}

	sticktime->cx++;
	stick1[0]->cx++;

	if (point->cx % 10 == 1)
	{
		Num1();
	}
	if (point->cx % 10 == 2)
	{
		Num2();
	}
	if (point->cx % 10 == 3)
	{
		Num3();
	}
	if (point->cx % 10 == 4)
	{
		Num4();
	}
	if (point->cx % 10 == 5)
	{
		Num5();
	}
	if (point->cx % 10 == 6)
	{
		Num6();
	}
	if (point->cx % 10 == 7)
	{
		Num7();
	}
	if (point->cx % 10 == 8)
	{
		Num8();
	}
	if (point->cx % 10 == 9)
	{
		Num9();
	}
	if (point->cx % 10 == 0)
	{
		Num0();
	}
	if ((point->cx / 10) % 10 == 1)
	{
		Num11();
	}
	if ((point->cx / 10) % 10 == 2)
	{
		Num12();
	}
	if ((point->cx / 10) % 10 == 3)
	{
		Num13();
	}
	if ((point->cx / 10) % 10 == 4)
	{
		Num14();
	}
	if ((point->cx / 10) % 10 == 5)
	{
		Num15();
	}
	if ((point->cx / 10) % 10 == 6)
	{
		Num16();
	}
	if ((point->cx / 10) % 10 == 7)
	{
		Num17();
	}
	if ((point->cx / 10) % 10 == 8)
	{
		Num18();
	}
	if ((point->cx / 10) % 10 == 9)
	{
		Num19();
	}
	if ((point->cx / 10) % 10 == 0)
	{
		Num10();
	}

	if (point->cx / 100 == 1)
	{
		Num21();
	}
	if (point->cx / 100 == 2)
	{
		Num22();
	}
	if (point->cx / 100 == 3)
	{
		Num23();
	}
	if (point->cx / 100 == 4)
	{
		Num24();
	}
	if (point->cx / 100 == 5)
	{
		Num25();
	}
	if (point->cx / 100 == 6)
	{
		Num26();
	}
	if (point->cx / 100 == 7)
	{
		Num27();
	}
	if (point->cx / 100 == 8)
	{
		Num28();
	}
	if (point->cx / 100 == 9)
	{
		Num29();
	}
	if (point->cx / 100 == 0)
	{
		Num20();
	}

	if (point->x <= -80)
	{
		arrowhead->y = 27;
		state = EXIT;
		sndPlaySoundA(NULL, SND_ASYNC);
	}

	if (set2->y == 1)
	{
		if (stick1[0]->cx == 1600)
		{
			arrowhead->y = 27;
			state = EXIT;
			sndPlaySoundA(NULL, SND_ASYNC);
		}
	}
	if (set2->y == 2)
	{
		if (stick1[0]->cx == 2800)
		{
			arrowhead->y = 27;
			state = EXIT;
			sndPlaySoundA(NULL, SND_ASYNC);
		}
	}
	if (set2->y == 3)
	{
		if (stick1[0]->cx == 3726)
		{
			arrowhead->y = 27;
			state = EXIT;
			sndPlaySoundA(NULL, SND_ASYNC);
		}
	}

	if (GetAsyncKeyState(VK_ESCAPE) & 0x0001)
	{
		state = STAGEMENU;
		sndPlaySoundA(NULL, SND_ASYNC);
	}

	if (set2->y == 1)
	{
		set2->x = 0;
	}
	if (set2->y == 2)
	{
		set2->x = 50;
	}
	if (set2->y == 3)
	{
		set2->x = 67;
	}

	srand((unsigned)time(NULL));
}

void StageRender()
{
	for (int y = 0; y < BufferHeight - 1; y++)
	{
		for (int x = 0; x < BufferWidth; x += 2)
		{
			if (x == 0)
			{
				WriteBuffer(0, y, "ㅁ", 노란색);
			}
			if (y == 0)
			{
				WriteBuffer(x, 0, "ㅁ", 노란색);
			}
			if (y == BufferHeight - 2)
			{
				WriteBuffer(x, BufferHeight - 2, "ㅁ", 노란색);
			}
			if (x == BufferWidth - 2)
			{
				WriteBuffer(BufferWidth - 2, y, "ㅁ", 노란색);
			}
		}
	}

	WriteBuffer(14, 36, "SPACE.", 초록색);
	WriteBuffer(28, 36, "←", 초록색);
	WriteBuffer(40, 36, "↑", 초록색);
	WriteBuffer(52, 36, "↓", 초록색);
	WriteBuffer(64, 36, "→", 초록색);

	for (int i = 0; i < WayNum; i++)
	{
		WriteBuffer(way[i]->x, way[i]->y, way[i]->shape, 빨간색);
	}

	//HP Bar
	for (int i = 0; i < Hpbar; i++)
	{
		if (point->x >= (-4)*i)
		{
			WriteBuffer(hpbar[i]->x, hpbar[i]->y, hpbar[i]->shape, 연한파란색);
		}
		WriteBuffer(hpbar[i]->x - 2, hpbar[i]->y, "Ι", 연한파란색);
		WriteBuffer(hpbar[i]->x + 2, hpbar[i]->y, "Ι", 연한파란색);
	}

	//Special Bar
	for (int i = 0; i < Hpbar; i++)
	{
		if (point->y >= 3 * i + 1)
		{
			WriteBuffer(specialbar[i]->x, specialbar[i]->y, specialbar[i]->shape, 연한빨간색);
		}
		WriteBuffer(specialbar[i]->x - 2, specialbar[i]->y, "Ι", 연한빨간색);
		WriteBuffer(specialbar[i]->x + 2, specialbar[i]->y, "Ι", 연한빨간색);
	}

	if (point->y >= 59)
	{
		WriteBuffer(2, 23, "ENTER", 192);
	}
	if (point->y < 59)
	{
		WriteBuffer(2, 23, "      ", 0);
	}

	//3
	for (int i = 0; i < StickNum; i++)
	{
		if (stick3[i]->act == true)
		{
			if (GetAsyncKeyState(VK_UP) & 0x8000)
			{
				if (stickcoolication3(stick3[i], way[2]) == true)
				{
					stick3[i]->act = false;
					for (int j = 0; j < 9; j++)
					{
						if (point->cx < 100)
						{
							WriteBuffer(40, 9 + j, NumImg[j], 연한옥색);
							WriteBuffer(25, 9 + j, NumImg10[j], 연한옥색);
						}
						if (point->cx >= 100)
						{
							WriteBuffer(48, 9 + j, NumImg[j], 연한옥색);
							WriteBuffer(33, 9 + j, NumImg10[j], 연한옥색);
							WriteBuffer(18, 9 + j, NumImg100[j], 연한옥색);
						}
					}
					if (stick3[i]->y == 35)
					{
						for (int j = 0; j < rand() % 10 + 12; j++)
						{
							WriteBuffer(effect3[j]->x, effect3[j]->y, effect3[j]->shape, 연한초록색);
							WriteBuffer(effect3[j]->cx, effect3[j]->y, effect3[j]->shape, 연한초록색);
						}
						WriteBuffer(2, 27, "PERPECT", 초록색);
						sticktime->x += 10;
					}
					if (stick3[i]->y == 34 || stick3[i]->y == 36)
					{
						for (int j = 0; j < rand() % 10 + 12; j++)
						{
							WriteBuffer(effect3[j]->x, effect3[j]->y, effect3[j]->shape, 진한노란색);
							WriteBuffer(effect3[j]->cx, effect3[j]->y, effect3[j]->shape, 진한노란색);
						}
						WriteBuffer(2, 27, " GREAT", 노란색);
					}
					point->cx++;
					if (point->cx > maxpoint->x)
					{
						maxpoint->x++;
					}
					if (point->x <= 0)
					{
						point->x += 1;
					}
					if (point->y >= 0)
					{
						if (point->y <= 62)
						{
							point->y += 2;
						}
						sticktime->x += 21;
					}
					if (point->y < 0)
					{
						point->y += 1;
						sticktime->x += 63;
					}
				}
			}

			if (point->y < 0)
			{
				WriteBuffer(stick3[i]->x, stick3[i]->y, point->shape, 진한노란색);
			}
			if (point->y >= 0)
			{
				WriteBuffer(stick3[i]->x, stick3[i]->y, stick3[i]->shape, 자주색);
			}
		}
	}

	//1
	for (int i = 0; i < StickNum; i++)
	{
		if (stick1[i]->act == true)
		{
			if (point->y < 0)
			{
				WriteBuffer(stick1[i]->x, stick1[i]->y, point->shape, 진한노란색);
			}
			if (point->y >= 0)
			{
				WriteBuffer(stick1[i]->x, stick1[i]->y, stick1[i]->shape, 자주색);
			}
			if (GetAsyncKeyState(VK_SPACE) & 0x8000)
			{
				if (stickcoolication1(stick1[i], way[0]) == true)
				{
					stick1[i]->act = false;
					for (int j = 0; j < 9; j++)
					{
						if (point->cx < 100)
						{
							WriteBuffer(40, 9 + j, NumImg[j], 연한옥색);
							WriteBuffer(25, 9 + j, NumImg10[j], 연한옥색);
						}
						if (point->cx >= 100)
						{
							WriteBuffer(48, 9 + j, NumImg[j], 연한옥색);
							WriteBuffer(33, 9 + j, NumImg10[j], 연한옥색);
							WriteBuffer(18, 9 + j, NumImg100[j], 연한옥색);
						}
					}
					if (stick1[i]->y == 35)
					{
						for (int j = 0; j < rand() % 10 + 12; j++)
						{
							WriteBuffer(effect[j]->x, effect[j]->y, effect[j]->shape, 연한초록색);
							WriteBuffer(effect[j]->cx, effect[j]->y, effect[j]->shape, 연한초록색);
						}
						WriteBuffer(2, 27, "PERPECT", 초록색);
						sticktime->x += 10;
					}
					if (stick1[i]->y == 34 || stick1[i]->y == 36)
					{
						for (int j = 0; j < rand() % 10 + 12; j++)
						{
							WriteBuffer(effect[j]->x, effect[j]->y, effect[j]->shape, 진한노란색);
							WriteBuffer(effect[j]->cx, effect[j]->y, effect[j]->shape, 진한노란색);
						}
						WriteBuffer(2, 27, " GREAT", 노란색);
					}
					point->cx++;
					if (point->cx > maxpoint->x)
					{
						maxpoint->x++;
					}
					if (point->x <= 0)
					{
						point->x += 1;
					}
					if (point->y >= 0)
					{
						if (point->y <= 62)
						{
							point->y += 2;
						}
						sticktime->x += 21;
					}
					if (point->y < 0)
					{
						point->y += 1;
						sticktime->x += 63;
					}
				}
			}
		}
	}

	//2
	for (int i = 0; i < StickNum; i++)
	{
		if (stick2[i]->act == true)
		{
			if (point->y < 0)
			{
				WriteBuffer(stick2[i]->x, stick2[i]->y, point->shape, 진한노란색);
			}
			if (point->y >= 0)
			{
				WriteBuffer(stick2[i]->x, stick2[i]->y, stick2[i]->shape, 자주색);
			}
			if (GetAsyncKeyState(VK_LEFT) & 0x8000)
			{
				if (stickcoolication2(stick2[i], way[1]) == true)
				{
					stick2[i]->act = false;
					for (int j = 0; j < 9; j++)
					{
						if (point->cx < 100)
						{
							WriteBuffer(40, 9 + j, NumImg[j], 연한옥색);
							WriteBuffer(25, 9 + j, NumImg10[j], 연한옥색);
						}
						if (point->cx >= 100)
						{
							WriteBuffer(48, 9 + j, NumImg[j], 연한옥색);
							WriteBuffer(33, 9 + j, NumImg10[j], 연한옥색);
							WriteBuffer(18, 9 + j, NumImg100[j], 연한옥색);
						}
					}
					if (stick2[i]->y == 35)
					{
						for (int j = 0; j < rand() % 10 + 12; j++)
						{
							WriteBuffer(effect2[j]->x, effect2[j]->y, effect2[j]->shape, 연한초록색);
							WriteBuffer(effect2[j]->cx, effect2[j]->y, effect2[j]->shape, 연한초록색);
						}
						WriteBuffer(2, 27, "PERPECT", 초록색);
						sticktime->x += 10;
					}
					if (stick2[i]->y == 34 || stick2[i]->y == 36)
					{
						for (int j = 0; j < rand() % 10 + 12; j++)
						{
							WriteBuffer(effect2[j]->x, effect2[j]->y, effect2[j]->shape, 진한노란색);
							WriteBuffer(effect2[j]->cx, effect2[j]->y, effect2[j]->shape, 진한노란색);
						}
						WriteBuffer(2, 27, " GREAT", 노란색);
					}
					point->cx++;
					if (point->cx > maxpoint->x)
					{
						maxpoint->x++;
					}
					if (point->x <= 0)
					{
						point->x += 1;
					}
					if (point->y >= 0)
					{
						if (point->y <= 62)
						{
							point->y += 2;
						}
						sticktime->x += 21;
					}
					if (point->y < 0)
					{
						point->y += 1;
						sticktime->x += 63;
					}
				}
			}
		}
	}

	//4
	for (int i = 0; i < StickNum; i++)
	{
		if (stick4[i]->act == true)
		{
			if (point->y < 0)
			{
				WriteBuffer(stick4[i]->x, stick4[i]->y, point->shape, 진한노란색);
			}
			if (point->y >= 0)
			{
				WriteBuffer(stick4[i]->x, stick4[i]->y, stick4[i]->shape, 자주색);
			}
			if (GetAsyncKeyState(VK_DOWN) & 0x8000)
			{
				if (stickcoolication4(stick4[i], way[3]) == true)
				{
					stick4[i]->act = false;
					for (int j = 0; j < 9; j++)
					{
						if (point->cx < 100)
						{
							WriteBuffer(40, 9 + j, NumImg[j], 연한옥색);
							WriteBuffer(25, 9 + j, NumImg10[j], 연한옥색);
						}
						if (point->cx >= 100)
						{
							WriteBuffer(48, 9 + j, NumImg[j], 연한옥색);
							WriteBuffer(33, 9 + j, NumImg10[j], 연한옥색);
							WriteBuffer(18, 9 + j, NumImg100[j], 연한옥색);
						}
					}
					if (stick4[i]->y == 35)
					{
						for (int j = 0; j < rand() % 10 + 12; j++)
						{
							WriteBuffer(effect4[j]->x, effect4[j]->y, effect4[j]->shape, 연한초록색);
							WriteBuffer(effect4[j]->cx, effect4[j]->y, effect4[j]->shape, 연한초록색);
						}
						WriteBuffer(2, 27, "PERPECT", 초록색);
						sticktime->x += 10;
					}
					if (stick4[i]->y == 34 || stick4[i]->y == 36)
					{
						for (int j = 0; j < rand() % 10 + 12; j++)
						{
							WriteBuffer(effect4[j]->x, effect4[j]->y, effect4[j]->shape, 진한노란색);
							WriteBuffer(effect4[j]->cx, effect4[j]->y, effect4[j]->shape, 진한노란색);
						}
						WriteBuffer(2, 27, " GREAT", 노란색);
					}
					point->cx++;
					if (point->cx > maxpoint->x)
					{
						maxpoint->x++;
					}
					if (point->x <= 0)
					{
						point->x += 1;
					}
					if (point->y >= 0)
					{
						if (point->y <= 62)
						{
							point->y += 2;
						}
						sticktime->x += 21;
					}
					if (point->y < 0)
					{
						point->y += 1;
						sticktime->x += 63;
					}
				}
			}
		}
	}

	//5
	for (int i = 0; i < StickNum; i++)
	{
		if (stick5[i]->act == true)
		{
			if (point->y < 0)
			{
				WriteBuffer(stick5[i]->x, stick5[i]->y, point->shape, 진한노란색);
			}
			if (point->y >= 0)
			{
				WriteBuffer(stick5[i]->x, stick5[i]->y, stick5[i]->shape, 자주색);
			}
			if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
			{
				if (stickcoolication5(stick5[i], way[4]) == true)
				{
					stick5[i]->act = false;
					for (int j = 0; j < 9; j++)
					{
						if (point->cx < 100)
						{
							WriteBuffer(40, 9 + j, NumImg[j], 연한옥색);
							WriteBuffer(25, 9 + j, NumImg10[j], 연한옥색);
						}
						if (point->cx >= 100)
						{
							WriteBuffer(48, 9 + j, NumImg[j], 연한옥색);
							WriteBuffer(33, 9 + j, NumImg10[j], 연한옥색);
							WriteBuffer(18, 9 + j, NumImg100[j], 연한옥색);
						}
					}
					if (stick5[i]->y == 35)
					{
						for (int j = 0; j < rand() % 10 + 12; j++)
						{
							WriteBuffer(effect5[j]->x, effect5[j]->y, effect5[j]->shape, 연한초록색);
							WriteBuffer(effect5[j]->cx, effect5[j]->y, effect5[j]->shape, 연한초록색);
						}
						WriteBuffer(2, 27, "PERPECT", 초록색);
						sticktime->x += 10;
					}
					if (stick5[i]->y == 34 || stick5[i]->y == 36)
					{
						for (int j = 0; j < rand() % 10 + 12; j++)
						{
							WriteBuffer(effect5[j]->x, effect5[j]->y, effect5[j]->shape, 진한노란색);
							WriteBuffer(effect5[j]->cx, effect5[j]->y, effect5[j]->shape, 진한노란색);
						}
						WriteBuffer(2, 27, " GREAT", 노란색);
					}
					point->cx++;
					if (point->cx > maxpoint->x)
					{
						maxpoint->x++;
					}
					if (point->x <= 0)
					{
						point->x += 1;
					}
					if (point->y >= 0)
					{
						if (point->y <= 62)
						{
							point->y += 2;
						}
						sticktime->x += 21;
					}
					if (point->y < 0)
					{
						point->y += 1;
						sticktime->x += 63;
					}
				}
			}
		}
	}

	if (set2->y == 1)
	{
		_itoa_s(sticktime->x + stick1[0]->cx, sNum, 10);
	}
	if (set2->y == 2)
	{
		_itoa_s(sticktime->x + (stick1[0]->cx / 2), sNum, 10);
	}
	if (set2->y == 3)
	{
		_itoa_s(sticktime->x + (stick1[0]->cx / 3), sNum, 10);
	}
	_itoa_s(maxpoint->cx, sNum5, 10);
	WriteBuffer(10, 2, "점수 :", 흰색);
	WriteBuffer(17, 2, sNum, 흰색);
	WriteBuffer(24, 2, "최고점수 :", 흰색);
	if (set2->y == 1)
	{
		if (stick1[0]->cx + sticktime->x > maxpoint->cx)
		{
			WriteBuffer(35, 2, sNum, 흰색);
		}
		else
		{
			WriteBuffer(35, 2, sNum5, 흰색);
		}
	}
	if (set2->y == 2)
	{
		if ((stick1[0]->cx / 2) + sticktime->x > maxpoint->cx)
		{
			WriteBuffer(35, 2, sNum, 흰색);
		}
		else
		{
			WriteBuffer(35, 2, sNum5, 흰색);
		}
	}
	if (set2->y == 3)
	{
		if ((stick1[0]->cx / 3) + sticktime->x > maxpoint->cx)
		{
			WriteBuffer(35, 2, sNum, 흰색);
		}
		else
		{
			WriteBuffer(35, 2, sNum5, 흰색);
		}
	}

	WriteBuffer(73, 36, "ESC", 회색);
	WriteBuffer(70, 37, "다시하기", 회색);
}

void StageProgress2()
{
	if (point->y >= 59)
	{
		if (GetAsyncKeyState(VK_RETURN) & 0x0001)
		{
			point->y = -20;
		}
	}

	sticktime->cx++;
	stick1[0]->cx++;

	if (point->cx % 10 == 1)
	{
		Num1();
	}
	if (point->cx % 10 == 2)
	{
		Num2();
	}
	if (point->cx % 10 == 3)
	{
		Num3();
	}
	if (point->cx % 10 == 4)
	{
		Num4();
	}
	if (point->cx % 10 == 5)
	{
		Num5();
	}
	if (point->cx % 10 == 6)
	{
		Num6();
	}
	if (point->cx % 10 == 7)
	{
		Num7();
	}
	if (point->cx % 10 == 8)
	{
		Num8();
	}
	if (point->cx % 10 == 9)
	{
		Num9();
	}
	if (point->cx % 10 == 0)
	{
		Num0();
	}
	if ((point->cx / 10) % 10 == 1)
	{
		Num11();
	}
	if ((point->cx / 10) % 10 == 2)
	{
		Num12();
	}
	if ((point->cx / 10) % 10 == 3)
	{
		Num13();
	}
	if ((point->cx / 10) % 10 == 4)
	{
		Num14();
	}
	if ((point->cx / 10) % 10 == 5)
	{
		Num15();
	}
	if ((point->cx / 10) % 10 == 6)
	{
		Num16();
	}
	if ((point->cx / 10) % 10 == 7)
	{
		Num17();
	}
	if ((point->cx / 10) % 10 == 8)
	{
		Num18();
	}
	if ((point->cx / 10) % 10 == 9)
	{
		Num19();
	}
	if ((point->cx / 10) % 10 == 0)
	{
		Num10();
	}

	if (point->cx / 100 == 1)
	{
		Num21();
	}
	if (point->cx / 100 == 2)
	{
		Num22();
	}
	if (point->cx / 100 == 3)
	{
		Num23();
	}
	if (point->cx / 100 == 4)
	{
		Num24();
	}
	if (point->cx / 100 == 5)
	{
		Num25();
	}
	if (point->cx / 100 == 6)
	{
		Num26();
	}
	if (point->cx / 100 == 7)
	{
		Num27();
	}
	if (point->cx / 100 == 8)
	{
		Num28();
	}
	if (point->cx / 100 == 9)
	{
		Num29();
	}
	if (point->cx / 100 == 0)
	{
		Num20();
	}

	if (point->x <= -80)
	{
		arrowhead->y = 27;
		state = EXIT;
		sndPlaySoundA(NULL, SND_ASYNC);
	}

	if (set2->y == 1)
	{
		if (stick1[0]->cx == 1950)
		{
			arrowhead->y = 27;
			state = EXIT;
			sndPlaySoundA(NULL, SND_ASYNC);
		}
	}
	if (set2->y == 2)
	{
		if (stick1[0]->cx == 3400)
		{
			arrowhead->y = 27;
			state = EXIT;
			sndPlaySoundA(NULL, SND_ASYNC);
		}
	}
	if (set2->y == 3)
	{
		if (stick1[0]->cx == 4530)
		{
			arrowhead->y = 27;
			state = EXIT;
			sndPlaySoundA(NULL, SND_ASYNC);
		}
	}

	if (GetAsyncKeyState(VK_ESCAPE) & 0x0001)
	{
		state = STAGEMENU;
		sndPlaySoundA(NULL, SND_ASYNC);
	}

	if (set2->y == 1)
	{
		set2->x = 0;
	}
	if (set2->y == 2)
	{
		set2->x = 50;
	}
	if (set2->y == 3)
	{
		set2->x = 67;
	}

	srand((unsigned)time(NULL));

	if (set2->y == 1)
	{
		if (sticktime->cx == 3 || sticktime->cx == 374 || sticktime->cx == 652 || sticktime->cx == 983 || sticktime->cx == 1268 || sticktime->cx == 1579 || sticktime->cx == 1868
			|| sticktime->cx == 17 || sticktime->cx == 376 || sticktime->cx == 654 || sticktime->cx == 987 || sticktime->cx == 1270 || sticktime->cx == 1581 || sticktime->cx == 1870
			|| sticktime->cx == 20 || sticktime->cx == 378 || sticktime->cx == 659 || sticktime->cx == 990 || sticktime->cx == 1277 || sticktime->cx == 1583 || sticktime->cx == 1874
			|| sticktime->cx == 22 || sticktime->cx == 380 || sticktime->cx == 661 || sticktime->cx == 992 || sticktime->cx == 1281 || sticktime->cx == 1587 || sticktime->cx == 1879
			|| sticktime->cx == 32 || sticktime->cx == 382 || sticktime->cx == 663 || sticktime->cx == 997 || sticktime->cx == 1283 || sticktime->cx == 1589 || sticktime->cx == 1883
			|| sticktime->cx == 37 || sticktime->cx == 384 || sticktime->cx == 666 || sticktime->cx == 1001 || sticktime->cx == 1288 || sticktime->cx == 1591 || sticktime->cx == 1885
			|| sticktime->cx == 56 || sticktime->cx == 389 || sticktime->cx == 671 || sticktime->cx == 1004 || sticktime->cx == 1295 || sticktime->cx == 1593
			|| sticktime->cx == 66 || sticktime->cx == 393 || sticktime->cx == 676 || sticktime->cx == 1006 || sticktime->cx == 1296 || sticktime->cx == 1595
			|| sticktime->cx == 71 || sticktime->cx == 397 || sticktime->cx == 678 || sticktime->cx == 1008 || sticktime->cx == 1298 || sticktime->cx == 1597
			|| sticktime->cx == 85 || sticktime->cx == 400 || sticktime->cx == 680 || sticktime->cx == 1011 || sticktime->cx == 1300 || sticktime->cx == 1600
			|| sticktime->cx == 87 || sticktime->cx == 402 || sticktime->cx == 683 || sticktime->cx == 1014 || sticktime->cx == 1302 || sticktime->cx == 1604
			|| sticktime->cx == 90 || sticktime->cx == 404 || sticktime->cx == 687 || sticktime->cx == 1016 || sticktime->cx == 1306 || sticktime->cx == 1620
			|| sticktime->cx == 100 || sticktime->cx == 406 || sticktime->cx == 696 || sticktime->cx == 1017 || sticktime->cx == 1307 || sticktime->cx == 1622
			|| sticktime->cx == 105 || sticktime->cx == 410 || sticktime->cx == 697 || sticktime->cx == 1019 || sticktime->cx == 1309 || sticktime->cx == 1623
			|| sticktime->cx == 124 || sticktime->cx == 417 || sticktime->cx == 698 || sticktime->cx == 1021 || sticktime->cx == 1311 || sticktime->cx == 1626
			|| sticktime->cx == 132 || sticktime->cx == 419 || sticktime->cx == 701 || sticktime->cx == 1025 || sticktime->cx == 1313 || sticktime->cx == 1629
			|| sticktime->cx == 134 || sticktime->cx == 421 || sticktime->cx == 702 || sticktime->cx == 1026 || sticktime->cx == 1318 || sticktime->cx == 1630
			|| sticktime->cx == 135 || sticktime->cx == 423 || sticktime->cx == 705 || sticktime->cx == 1031 || sticktime->cx == 1320 || sticktime->cx == 1632
			|| sticktime->cx == 137 || sticktime->cx == 425 || sticktime->cx == 710 || sticktime->cx == 1032 || sticktime->cx == 1322 || sticktime->cx == 1634
			|| sticktime->cx == 138 || sticktime->cx == 428 || sticktime->cx == 711 || sticktime->cx == 1035 || sticktime->cx == 1324 || sticktime->cx == 1636
			|| sticktime->cx == 140 || sticktime->cx == 431 || sticktime->cx == 714 || sticktime->cx == 1039 || sticktime->cx == 1326 || sticktime->cx == 1638
			|| sticktime->cx == 148 || sticktime->cx == 434 || sticktime->cx == 718 || sticktime->cx == 1043 || sticktime->cx == 1328 || sticktime->cx == 1640
			|| sticktime->cx == 150 || sticktime->cx == 436 || sticktime->cx == 720 || sticktime->cx == 1047 || sticktime->cx == 1330 || sticktime->cx == 1646
			|| sticktime->cx == 151 || sticktime->cx == 438 || sticktime->cx == 722 || sticktime->cx == 1049 || sticktime->cx == 1335 || sticktime->cx == 1653
			|| sticktime->cx == 152 || sticktime->cx == 440 || sticktime->cx == 726 || sticktime->cx == 1051 || sticktime->cx == 1337 || sticktime->cx == 1655
			|| sticktime->cx == 156 || sticktime->cx == 445 || sticktime->cx == 728 || sticktime->cx == 1056 || sticktime->cx == 1339 || sticktime->cx == 1657
			|| sticktime->cx == 158 || sticktime->cx == 451 || sticktime->cx == 730 || sticktime->cx == 1058 || sticktime->cx == 1342 || sticktime->cx == 1659
			|| sticktime->cx == 166 || sticktime->cx == 453 || sticktime->cx == 732 || sticktime->cx == 1060 || sticktime->cx == 1346 || sticktime->cx == 1662
			|| sticktime->cx == 168 || sticktime->cx == 455 || sticktime->cx == 738 || sticktime->cx == 1064 || sticktime->cx == 1352 || sticktime->cx == 1664
			|| sticktime->cx == 169 || sticktime->cx == 457 || sticktime->cx == 743 || sticktime->cx == 1068 || sticktime->cx == 1353 || sticktime->cx == 1666
			|| sticktime->cx == 170 || sticktime->cx == 459 || sticktime->cx == 746 || sticktime->cx == 1072 || sticktime->cx == 1356 || sticktime->cx == 1668
			|| sticktime->cx == 172 || sticktime->cx == 461 || sticktime->cx == 748 || sticktime->cx == 1075 || sticktime->cx == 1358 || sticktime->cx == 1672
			|| sticktime->cx == 174 || sticktime->cx == 465 || sticktime->cx == 751 || sticktime->cx == 1077 || sticktime->cx == 1362 || sticktime->cx == 1673
			|| sticktime->cx == 178 || sticktime->cx == 467 || sticktime->cx == 755 || sticktime->cx == 1079 || sticktime->cx == 1371 || sticktime->cx == 1676
			|| sticktime->cx == 180 || sticktime->cx == 469 || sticktime->cx == 764 || sticktime->cx == 1081 || sticktime->cx == 1372 || sticktime->cx == 1679
			|| sticktime->cx == 182 || sticktime->cx == 471 || sticktime->cx == 766 || sticktime->cx == 1086 || sticktime->cx == 1374 || sticktime->cx == 1681
			|| sticktime->cx == 187 || sticktime->cx == 473 || sticktime->cx == 769 || sticktime->cx == 1092 || sticktime->cx == 1376 || sticktime->cx == 1683
			|| sticktime->cx == 192 || sticktime->cx == 478 || sticktime->cx == 771 || sticktime->cx == 1094 || sticktime->cx == 1379 || sticktime->cx == 1685
			|| sticktime->cx == 199 || sticktime->cx == 480 || sticktime->cx == 773 || sticktime->cx == 1096 || sticktime->cx == 1381 || sticktime->cx == 1687
			|| sticktime->cx == 201 || sticktime->cx == 482 || sticktime->cx == 778 || sticktime->cx == 1098 || sticktime->cx == 1385 || sticktime->cx == 1690
			|| sticktime->cx == 202 || sticktime->cx == 484 || sticktime->cx == 782 || sticktime->cx == 1100 || sticktime->cx == 1387 || sticktime->cx == 1692
			|| sticktime->cx == 204 || sticktime->cx == 486 || sticktime->cx == 786 || sticktime->cx == 1102 || sticktime->cx == 1389 || sticktime->cx == 1700
			|| sticktime->cx == 206 || sticktime->cx == 490 || sticktime->cx == 788 || sticktime->cx == 1105 || sticktime->cx == 1394 || sticktime->cx == 1701
			|| sticktime->cx == 209 || sticktime->cx == 495 || sticktime->cx == 790 || sticktime->cx == 1109 || sticktime->cx == 1395 || sticktime->cx == 1702
			|| sticktime->cx == 211 || sticktime->cx == 501 || sticktime->cx == 798 || sticktime->cx == 1111 || sticktime->cx == 1397 || sticktime->cx == 1705
			|| sticktime->cx == 212 || sticktime->cx == 503 || sticktime->cx == 803 || sticktime->cx == 1113 || sticktime->cx == 1402 || sticktime->cx == 1707
			|| sticktime->cx == 215 || sticktime->cx == 505 || sticktime->cx == 807 || sticktime->cx == 1115 || sticktime->cx == 1404 || sticktime->cx == 1710
			|| sticktime->cx == 218 || sticktime->cx == 507 || sticktime->cx == 811 || sticktime->cx == 1120 || sticktime->cx == 1406 || sticktime->cx == 1717
			|| sticktime->cx == 220 || sticktime->cx == 512 || sticktime->cx == 816 || sticktime->cx == 1126 || sticktime->cx == 1409 || sticktime->cx == 1718
			|| sticktime->cx == 223 || sticktime->cx == 522 || sticktime->cx == 820 || sticktime->cx == 1128 || sticktime->cx == 1413 || sticktime->cx == 1719
			|| sticktime->cx == 227 || sticktime->cx == 524 || sticktime->cx == 824 || sticktime->cx == 1130 || sticktime->cx == 1419 || sticktime->cx == 1722
			|| sticktime->cx == 235 || sticktime->cx == 526 || sticktime->cx == 828 || sticktime->cx == 1132 || sticktime->cx == 1421 || sticktime->cx == 1723
			|| sticktime->cx == 237 || sticktime->cx == 528 || sticktime->cx == 833 || sticktime->cx == 1134 || sticktime->cx == 1423 || sticktime->cx == 1727
			|| sticktime->cx == 239 || sticktime->cx == 531 || sticktime->cx == 837 || sticktime->cx == 1136 || sticktime->cx == 1425 || sticktime->cx == 1729
			|| sticktime->cx == 241 || sticktime->cx == 533 || sticktime->cx == 841 || sticktime->cx == 1140 || sticktime->cx == 1430 || sticktime->cx == 1730
			|| sticktime->cx == 243 || sticktime->cx == 535 || sticktime->cx == 845 || sticktime->cx == 1142 || sticktime->cx == 1439 || sticktime->cx == 1732
			|| sticktime->cx == 245 || sticktime->cx == 537 || sticktime->cx == 849 || sticktime->cx == 1144 || sticktime->cx == 1441 || sticktime->cx == 1734
			|| sticktime->cx == 247 || sticktime->cx == 539 || sticktime->cx == 853 || sticktime->cx == 1146 || sticktime->cx == 1443 || sticktime->cx == 1739
			|| sticktime->cx == 249 || sticktime->cx == 542 || sticktime->cx == 857 || sticktime->cx == 1148 || sticktime->cx == 1446 || sticktime->cx == 1741
			|| sticktime->cx == 254 || sticktime->cx == 544 || sticktime->cx == 862 || sticktime->cx == 1150 || sticktime->cx == 1448 || sticktime->cx == 1743
			|| sticktime->cx == 258 || sticktime->cx == 545 || sticktime->cx == 866 || sticktime->cx == 1153 || sticktime->cx == 1453 || sticktime->cx == 1745
			|| sticktime->cx == 261 || sticktime->cx == 550 || sticktime->cx == 873 || sticktime->cx == 1155 || sticktime->cx == 1457 || sticktime->cx == 1747
			|| sticktime->cx == 265 || sticktime->cx == 557 || sticktime->cx == 875 || sticktime->cx == 1157 || sticktime->cx == 1461 || sticktime->cx == 1749
			|| sticktime->cx == 267 || sticktime->cx == 558 || sticktime->cx == 877 || sticktime->cx == 1159 || sticktime->cx == 1463 || sticktime->cx == 1752
			|| sticktime->cx == 269 || sticktime->cx == 560 || sticktime->cx == 878 || sticktime->cx == 1161 || sticktime->cx == 1465 || sticktime->cx == 1757
			|| sticktime->cx == 271 || sticktime->cx == 562 || sticktime->cx == 881 || sticktime->cx == 1166 || sticktime->cx == 1474 || sticktime->cx == 1759
			|| sticktime->cx == 273 || sticktime->cx == 565 || sticktime->cx == 884 || sticktime->cx == 1170 || sticktime->cx == 1477 || sticktime->cx == 1761
			|| sticktime->cx == 276 || sticktime->cx == 566 || sticktime->cx == 886 || sticktime->cx == 1176 || sticktime->cx == 1481 || sticktime->cx == 1762
			|| sticktime->cx == 280 || sticktime->cx == 568 || sticktime->cx == 887 || sticktime->cx == 1178 || sticktime->cx == 1482 || sticktime->cx == 1765
			|| sticktime->cx == 287 || sticktime->cx == 570 || sticktime->cx == 891 || sticktime->cx == 1180 || sticktime->cx == 1485 || sticktime->cx == 1769
			|| sticktime->cx == 288 || sticktime->cx == 574 || sticktime->cx == 895 || sticktime->cx == 1182 || sticktime->cx == 1487 || sticktime->cx == 1774
			|| sticktime->cx == 290 || sticktime->cx == 576 || sticktime->cx == 899 || sticktime->cx == 1187 || sticktime->cx == 1489 || sticktime->cx == 1775
			|| sticktime->cx == 292 || sticktime->cx == 579 || sticktime->cx == 904 || sticktime->cx == 1196 || sticktime->cx == 1491 || sticktime->cx == 1777
			|| sticktime->cx == 295 || sticktime->cx == 582 || sticktime->cx == 908 || sticktime->cx == 1198 || sticktime->cx == 1495 || sticktime->cx == 1779
			|| sticktime->cx == 298 || sticktime->cx == 584 || sticktime->cx == 913 || sticktime->cx == 1200 || sticktime->cx == 1503 || sticktime->cx == 1784
			|| sticktime->cx == 300 || sticktime->cx == 586 || sticktime->cx == 914 || sticktime->cx == 1202 || sticktime->cx == 1505 || sticktime->cx == 1793
			|| sticktime->cx == 302 || sticktime->cx == 588 || sticktime->cx == 916 || sticktime->cx == 1206 || sticktime->cx == 1507 || sticktime->cx == 1794
			|| sticktime->cx == 304 || sticktime->cx == 590 || sticktime->cx == 918 || sticktime->cx == 1207 || sticktime->cx == 1509 || sticktime->cx == 1796
			|| sticktime->cx == 306 || sticktime->cx == 593 || sticktime->cx == 921 || sticktime->cx == 1210 || sticktime->cx == 1512 || sticktime->cx == 1798
			|| sticktime->cx == 307 || sticktime->cx == 595 || sticktime->cx == 923 || sticktime->cx == 1212 || sticktime->cx == 1514 || sticktime->cx == 1800
			|| sticktime->cx == 309 || sticktime->cx == 602 || sticktime->cx == 925 || sticktime->cx == 1213 || sticktime->cx == 1517 || sticktime->cx == 1803
			|| sticktime->cx == 316 || sticktime->cx == 603 || sticktime->cx == 929 || sticktime->cx == 1215 || sticktime->cx == 1518 || sticktime->cx == 1807
			|| sticktime->cx == 321 || sticktime->cx == 605 || sticktime->cx == 933 || sticktime->cx == 1217 || sticktime->cx == 1521 || sticktime->cx == 1809
			|| sticktime->cx == 323 || sticktime->cx == 607 || sticktime->cx == 936 || sticktime->cx == 1219 || sticktime->cx == 1523 || sticktime->cx == 1811
			|| sticktime->cx == 326 || sticktime->cx == 609 || sticktime->cx == 940 || sticktime->cx == 1224 || sticktime->cx == 1525 || sticktime->cx == 1816
			|| sticktime->cx == 330 || sticktime->cx == 613 || sticktime->cx == 941 || sticktime->cx == 1231 || sticktime->cx == 1533 || sticktime->cx == 1818
			|| sticktime->cx == 332 || sticktime->cx == 619 || sticktime->cx == 946 || sticktime->cx == 1233 || sticktime->cx == 1537 || sticktime->cx == 1820
			|| sticktime->cx == 334 || sticktime->cx == 621 || sticktime->cx == 950 || sticktime->cx == 1235 || sticktime->cx == 1539 || sticktime->cx == 1825
			|| sticktime->cx == 339 || sticktime->cx == 622 || sticktime->cx == 953 || sticktime->cx == 1237 || sticktime->cx == 1541 || sticktime->cx == 1827
			|| sticktime->cx == 343 || sticktime->cx == 624 || sticktime->cx == 955 || sticktime->cx == 1240 || sticktime->cx == 1545 || sticktime->cx == 1829
			|| sticktime->cx == 345 || sticktime->cx == 626 || sticktime->cx == 957 || sticktime->cx == 1242 || sticktime->cx == 1547 || sticktime->cx == 1832
			|| sticktime->cx == 347 || sticktime->cx == 630 || sticktime->cx == 959 || sticktime->cx == 1244 || sticktime->cx == 1549 || sticktime->cx == 1836
			|| sticktime->cx == 349 || sticktime->cx == 632 || sticktime->cx == 963 || sticktime->cx == 1246 || sticktime->cx == 1554 || sticktime->cx == 1841
			|| sticktime->cx == 351 || sticktime->cx == 634 || sticktime->cx == 965 || sticktime->cx == 1249 || sticktime->cx == 1558 || sticktime->cx == 1843
			|| sticktime->cx == 355 || sticktime->cx == 636 || sticktime->cx == 968 || sticktime->cx == 1251 || sticktime->cx == 1560 || sticktime->cx == 1845
			|| sticktime->cx == 359 || sticktime->cx == 638 || sticktime->cx == 969 || sticktime->cx == 1253 || sticktime->cx == 1562 || sticktime->cx == 1848
			|| sticktime->cx == 362 || sticktime->cx == 642 || sticktime->cx == 971 || sticktime->cx == 1256 || sticktime->cx == 1564 || sticktime->cx == 1852
			|| sticktime->cx == 363 || sticktime->cx == 644 || sticktime->cx == 974 || sticktime->cx == 1259 || sticktime->cx == 1567 || sticktime->cx == 1862
			|| sticktime->cx == 366 || sticktime->cx == 646 || sticktime->cx == 977 || sticktime->cx == 1261 || sticktime->cx == 1571 || sticktime->cx == 1864
			|| sticktime->cx == 368 || sticktime->cx == 648 || sticktime->cx == 979 || sticktime->cx == 1263 || sticktime->cx == 1575 || sticktime->cx == 1800
			|| sticktime->cx == 372 || sticktime->cx == 650 || sticktime->cx == 981 || sticktime->cx == 1266 || sticktime->cx == 1577 || sticktime->cx == 1866
			)
		{
			if (sticktime->cx % 5 == 0)
			{
				stick1[5]->cx = 1;
			}
			else if (sticktime->cx % 5 == 1)
			{
				stick1[5]->cx = 2;
			}
			else if (sticktime->cx % 5 == 2)
			{
				stick1[5]->cx = 3;
			}
			else if (sticktime->cx % 5 == 3)
			{
				stick1[5]->cx = 4;
			}
			else if (sticktime->cx % 5 == 4)
			{
				stick1[5]->cx = 5;
			}
		}
	}

	if (set2->y == 2)
	{
		if (sticktime->cx == 7 || sticktime->cx == 648 || sticktime->cx == 1138 || sticktime->cx == 1701 || sticktime->cx == 2168 || sticktime->cx == 2695 || sticktime->cx == 3195
			|| sticktime->cx == 23 || sticktime->cx == 655 || sticktime->cx == 1141 || sticktime->cx == 1704 || sticktime->cx == 2180 || sticktime->cx == 2703 || sticktime->cx == 3203
			|| sticktime->cx == 31 || sticktime->cx == 658 || sticktime->cx == 1145 || sticktime->cx == 1710 || sticktime->cx == 2183 || sticktime->cx == 2710 || sticktime->cx == 3206
			|| sticktime->cx == 56 || sticktime->cx == 662 || sticktime->cx == 1150 || sticktime->cx == 1713 || sticktime->cx == 2186 || sticktime->cx == 2716 || sticktime->cx == 3209
			|| sticktime->cx == 59 || sticktime->cx == 665 || sticktime->cx == 1153 || sticktime->cx == 1717 || sticktime->cx == 2190 || sticktime->cx == 2719 || sticktime->cx == 3213
			|| sticktime->cx == 64 || sticktime->cx == 668 || sticktime->cx == 1157 || sticktime->cx == 1720 || sticktime->cx == 2195 || sticktime->cx == 2723 || sticktime->cx == 3219
			|| sticktime->cx == 82 || sticktime->cx == 677 || sticktime->cx == 1160 || sticktime->cx == 1723 || sticktime->cx == 2198 || sticktime->cx == 2731 || sticktime->cx == 3222
			|| sticktime->cx == 90 || sticktime->cx == 680 || sticktime->cx == 1163 || sticktime->cx == 1726 || sticktime->cx == 2202 || sticktime->cx == 2734 || sticktime->cx == 3225
			|| sticktime->cx == 123 || sticktime->cx == 683 || sticktime->cx == 1166 || sticktime->cx == 1732 || sticktime->cx == 2205 || sticktime->cx == 2738 || sticktime->cx == 3231
			|| sticktime->cx == 142 || sticktime->cx == 687 || sticktime->cx == 1170 || sticktime->cx == 1735 || sticktime->cx == 2212 || sticktime->cx == 2745 || sticktime->cx == 3236
			|| sticktime->cx == 149 || sticktime->cx == 691 || sticktime->cx == 1173 || sticktime->cx == 1738 || sticktime->cx == 2215 || sticktime->cx == 2753 || sticktime->cx == 3248
			|| sticktime->cx == 174 || sticktime->cx == 694 || sticktime->cx == 1180 || sticktime->cx == 1741 || sticktime->cx == 2220 || sticktime->cx == 2756 || sticktime->cx == 3251
			|| sticktime->cx == 178 || sticktime->cx == 698 || sticktime->cx == 1183 || sticktime->cx == 1744 || sticktime->cx == 2224 || sticktime->cx == 2760 || sticktime->cx == 3255
			|| sticktime->cx == 182 || sticktime->cx == 707 || sticktime->cx == 1186 || sticktime->cx == 1748 || sticktime->cx == 2228 || sticktime->cx == 2764 || sticktime->cx == 3261
			|| sticktime->cx == 202 || sticktime->cx == 715 || sticktime->cx == 1192 || sticktime->cx == 1752 || sticktime->cx == 2231 || sticktime->cx == 2767 || sticktime->cx == 3267
			|| sticktime->cx == 209 || sticktime->cx == 720 || sticktime->cx == 1200 || sticktime->cx == 1755 || sticktime->cx == 2235 || sticktime->cx == 2775 || sticktime->cx == 3283
			|| sticktime->cx == 219 || sticktime->cx == 726 || sticktime->cx == 1209 || sticktime->cx == 1760 || sticktime->cx == 2239 || sticktime->cx == 2783 || sticktime->cx == 3287
			|| sticktime->cx == 227 || sticktime->cx == 729 || sticktime->cx == 1212 || sticktime->cx == 1763 || sticktime->cx == 2242 || sticktime->cx == 2786 || sticktime->cx == 3291
			|| sticktime->cx == 235 || sticktime->cx == 733 || sticktime->cx == 1215 || sticktime->cx == 1765 || sticktime->cx == 2246 || sticktime->cx == 2790 || sticktime->cx == 3294
			|| sticktime->cx == 242 || sticktime->cx == 736 || sticktime->cx == 1219 || sticktime->cx == 1771 || sticktime->cx == 2261 || sticktime->cx == 2793 || sticktime->cx == 3298
			|| sticktime->cx == 257 || sticktime->cx == 744 || sticktime->cx == 1224 || sticktime->cx == 1774 || sticktime->cx == 2263 || sticktime->cx == 2797 || sticktime->cx == 3306
			|| sticktime->cx == 260 || sticktime->cx == 756 || sticktime->cx == 1230 || sticktime->cx == 1777 || sticktime->cx == 2266 || sticktime->cx == 2804 || sticktime->cx == 3314
			|| sticktime->cx == 262 || sticktime->cx == 759 || sticktime->cx == 1244 || sticktime->cx == 1780 || sticktime->cx == 2270 || sticktime->cx == 2808 || sticktime->cx == 3322
			|| sticktime->cx == 265 || sticktime->cx == 762 || sticktime->cx == 1246 || sticktime->cx == 1784 || sticktime->cx == 2273 || sticktime->cx == 2811 || sticktime->cx == 3325
			|| sticktime->cx == 267 || sticktime->cx == 766 || sticktime->cx == 1248 || sticktime->cx == 1786 || sticktime->cx == 2280 || sticktime->cx == 2814
			|| sticktime->cx == 271 || sticktime->cx == 770 || sticktime->cx == 1252 || sticktime->cx == 1789 || sticktime->cx == 2292 || sticktime->cx == 2818
			|| sticktime->cx == 273 || sticktime->cx == 774 || sticktime->cx == 1255 || sticktime->cx == 1793 || sticktime->cx == 2294 || sticktime->cx == 2822
			|| sticktime->cx == 285 || sticktime->cx == 780 || sticktime->cx == 1258 || sticktime->cx == 1800 || sticktime->cx == 2296 || sticktime->cx == 2826
			|| sticktime->cx == 288 || sticktime->cx == 785 || sticktime->cx == 1252 || sticktime->cx == 1802 || sticktime->cx == 2300 || sticktime->cx == 2834
			|| sticktime->cx == 290 || sticktime->cx == 788 || sticktime->cx == 1258 || sticktime->cx == 1805 || sticktime->cx == 2303 || sticktime->cx == 2861
			|| sticktime->cx == 293 || sticktime->cx == 792 || sticktime->cx == 1271 || sticktime->cx == 1808 || sticktime->cx == 2309 || sticktime->cx == 2864
			|| sticktime->cx == 295 || sticktime->cx == 795 || sticktime->cx == 1275 || sticktime->cx == 1814 || sticktime->cx == 2312 || sticktime->cx == 2867
			|| sticktime->cx == 299 || sticktime->cx == 804 || sticktime->cx == 1283 || sticktime->cx == 1819 || sticktime->cx == 2316 || sticktime->cx == 2871
			|| sticktime->cx == 303 || sticktime->cx == 814 || sticktime->cx == 1286 || sticktime->cx == 1822 || sticktime->cx == 2319 || sticktime->cx == 2875
			|| sticktime->cx == 315 || sticktime->cx == 818 || sticktime->cx == 1289 || sticktime->cx == 1825 || sticktime->cx == 2323 || sticktime->cx == 2878
			|| sticktime->cx == 317 || sticktime->cx == 821 || sticktime->cx == 1298 || sticktime->cx == 1831 || sticktime->cx == 2331 || sticktime->cx == 2881
			|| sticktime->cx == 320 || sticktime->cx == 825 || sticktime->cx == 1301 || sticktime->cx == 1836 || sticktime->cx == 2334 || sticktime->cx == 2885
			|| sticktime->cx == 323 || sticktime->cx == 828 || sticktime->cx == 1306 || sticktime->cx == 1843 || sticktime->cx == 2338 || sticktime->cx == 2888
			|| sticktime->cx == 326 || sticktime->cx == 832 || sticktime->cx == 1310 || sticktime->cx == 1851 || sticktime->cx == 2342 || sticktime->cx == 2891
			|| sticktime->cx == 330 || sticktime->cx == 839 || sticktime->cx == 1318 || sticktime->cx == 1858 || sticktime->cx == 2346 || sticktime->cx == 2894
			|| sticktime->cx == 337 || sticktime->cx == 843 || sticktime->cx == 1328 || sticktime->cx == 1861 || sticktime->cx == 2349 || sticktime->cx == 2897
			|| sticktime->cx == 341 || sticktime->cx == 847 || sticktime->cx == 1331 || sticktime->cx == 1865 || sticktime->cx == 2353 || sticktime->cx == 2906
			|| sticktime->cx == 344 || sticktime->cx == 850 || sticktime->cx == 1335 || sticktime->cx == 1873 || sticktime->cx == 2361 || sticktime->cx == 2919
			|| sticktime->cx == 352 || sticktime->cx == 854 || sticktime->cx == 1339 || sticktime->cx == 1877 || sticktime->cx == 2364 || sticktime->cx == 2922
			|| sticktime->cx == 360 || sticktime->cx == 862 || sticktime->cx == 1347 || sticktime->cx == 1880 || sticktime->cx == 2368 || sticktime->cx == 2925
			|| sticktime->cx == 367 || sticktime->cx == 866 || sticktime->cx == 1363 || sticktime->cx == 1888 || sticktime->cx == 2373 || sticktime->cx == 2929
			|| sticktime->cx == 376 || sticktime->cx == 869 || sticktime->cx == 1366 || sticktime->cx == 1895 || sticktime->cx == 2381 || sticktime->cx == 2935
			|| sticktime->cx == 379 || sticktime->cx == 873 || sticktime->cx == 1370 || sticktime->cx == 1901 || sticktime->cx == 2390 || sticktime->cx == 2938
			|| sticktime->cx == 382 || sticktime->cx == 876 || sticktime->cx == 1373 || sticktime->cx == 1906 || sticktime->cx == 2394 || sticktime->cx == 2941
			|| sticktime->cx == 387 || sticktime->cx == 884 || sticktime->cx == 1376 || sticktime->cx == 1910 || sticktime->cx == 2397 || sticktime->cx == 2945
			|| sticktime->cx == 391 || sticktime->cx == 892 || sticktime->cx == 1380 || sticktime->cx == 1913 || sticktime->cx == 2403 || sticktime->cx == 2951
			|| sticktime->cx == 394 || sticktime->cx == 903 || sticktime->cx == 1387 || sticktime->cx == 1917 || sticktime->cx == 2410 || sticktime->cx == 2954
			|| sticktime->cx == 397 || sticktime->cx == 907 || sticktime->cx == 1394 || sticktime->cx == 1925 || sticktime->cx == 2426 || sticktime->cx == 2956
			|| sticktime->cx == 403 || sticktime->cx == 910 || sticktime->cx == 1401 || sticktime->cx == 1937 || sticktime->cx == 2428 || sticktime->cx == 2964
			|| sticktime->cx == 408 || sticktime->cx == 914 || sticktime->cx == 1404 || sticktime->cx == 1940 || sticktime->cx == 2432 || sticktime->cx == 2967
			|| sticktime->cx == 411 || sticktime->cx == 921 || sticktime->cx == 1408 || sticktime->cx == 1944 || sticktime->cx == 2436 || sticktime->cx == 2971
			|| sticktime->cx == 415 || sticktime->cx == 940 || sticktime->cx == 1424 || sticktime->cx == 1947 || sticktime->cx == 2439 || sticktime->cx == 2975
			|| sticktime->cx == 418 || sticktime->cx == 913 || sticktime->cx == 1431 || sticktime->cx == 1951 || sticktime->cx == 2443 || sticktime->cx == 2979
			|| sticktime->cx == 423 || sticktime->cx == 947 || sticktime->cx == 1439 || sticktime->cx == 1955 || sticktime->cx == 2449 || sticktime->cx == 2983
			|| sticktime->cx == 438 || sticktime->cx == 952 || sticktime->cx == 1446 || sticktime->cx == 1961 || sticktime->cx == 2452 || sticktime->cx == 2986
			|| sticktime->cx == 441 || sticktime->cx == 956 || sticktime->cx == 1454 || sticktime->cx == 1966 || sticktime->cx == 2456 || sticktime->cx == 3001
			|| sticktime->cx == 444 || sticktime->cx == 959 || sticktime->cx == 1461 || sticktime->cx == 1970 || sticktime->cx == 2464 || sticktime->cx == 3003
			|| sticktime->cx == 447 || sticktime->cx == 962 || sticktime->cx == 1469 || sticktime->cx == 1973 || sticktime->cx == 2467 || sticktime->cx == 3008
			|| sticktime->cx == 451 || sticktime->cx == 965 || sticktime->cx == 1476 || sticktime->cx == 1977 || sticktime->cx == 2471 || sticktime->cx == 3012
			|| sticktime->cx == 454 || sticktime->cx == 969 || sticktime->cx == 1483 || sticktime->cx == 1985 || sticktime->cx == 2479 || sticktime->cx == 3018
			|| sticktime->cx == 458 || sticktime->cx == 972 || sticktime->cx == 1490 || sticktime->cx == 1997 || sticktime->cx == 2483 || sticktime->cx == 3029
			|| sticktime->cx == 462 || sticktime->cx == 975 || sticktime->cx == 1498 || sticktime->cx == 2000 || sticktime->cx == 2487 || sticktime->cx == 3032
			|| sticktime->cx == 470 || sticktime->cx == 980 || sticktime->cx == 1505 || sticktime->cx == 2003 || sticktime->cx == 2492 || sticktime->cx == 3034
			|| sticktime->cx == 477 || sticktime->cx == 988 || sticktime->cx == 1512 || sticktime->cx == 2006 || sticktime->cx == 2499 || sticktime->cx == 3037
			|| sticktime->cx == 483 || sticktime->cx == 999 || sticktime->cx == 1518 || sticktime->cx == 2010 || sticktime->cx == 2509 || sticktime->cx == 3041
			|| sticktime->cx == 488 || sticktime->cx == 1002 || sticktime->cx == 1522 || sticktime->cx == 2013 || sticktime->cx == 2512 || sticktime->cx == 3048
			|| sticktime->cx == 492 || sticktime->cx == 1005 || sticktime->cx == 1525 || sticktime->cx == 2021 || sticktime->cx == 2516 || sticktime->cx == 3051
			|| sticktime->cx == 496 || sticktime->cx == 1010 || sticktime->cx == 1528 || sticktime->cx == 2024 || sticktime->cx == 2521 || sticktime->cx == 3055
			|| sticktime->cx == 499 || sticktime->cx == 1014 || sticktime->cx == 1534 || sticktime->cx == 2027 || sticktime->cx == 2528 || sticktime->cx == 3058
			|| sticktime->cx == 503 || sticktime->cx == 1018 || sticktime->cx == 1542 || sticktime->cx == 2031 || sticktime->cx == 2544 || sticktime->cx == 3062
			|| sticktime->cx == 508 || sticktime->cx == 1021 || sticktime->cx == 1549 || sticktime->cx == 2034 || sticktime->cx == 2548 || sticktime->cx == 3070
			|| sticktime->cx == 515 || sticktime->cx == 1024 || sticktime->cx == 1557 || sticktime->cx == 2037 || sticktime->cx == 2551 || sticktime->cx == 3073
			|| sticktime->cx == 527 || sticktime->cx == 1031 || sticktime->cx == 1564 || sticktime->cx == 2043 || sticktime->cx == 2554 || sticktime->cx == 3077
			|| sticktime->cx == 530 || sticktime->cx == 1033 || sticktime->cx == 1571 || sticktime->cx == 2047 || sticktime->cx == 2558 || sticktime->cx == 3081
			|| sticktime->cx == 533 || sticktime->cx == 1038 || sticktime->cx == 1578 || sticktime->cx == 2050 || sticktime->cx == 2567 || sticktime->cx == 3085
			|| sticktime->cx == 536 || sticktime->cx == 1044 || sticktime->cx == 1585 || sticktime->cx == 2054 || sticktime->cx == 2575 || sticktime->cx == 3089
			|| sticktime->cx == 542 || sticktime->cx == 1047 || sticktime->cx == 1592 || sticktime->cx == 2058 || sticktime->cx == 2583 || sticktime->cx == 3093
			|| sticktime->cx == 547 || sticktime->cx == 1050 || sticktime->cx == 1600 || sticktime->cx == 2065 || sticktime->cx == 2586 || sticktime->cx == 3100
			|| sticktime->cx == 552 || sticktime->cx == 1055 || sticktime->cx == 1607 || sticktime->cx == 2073 || sticktime->cx == 2589 || sticktime->cx == 3104
			|| sticktime->cx == 555 || sticktime->cx == 1058 || sticktime->cx == 1615 || sticktime->cx == 2085 || sticktime->cx == 2605 || sticktime->cx == 3107
			|| sticktime->cx == 559 || sticktime->cx == 1062 || sticktime->cx == 1624 || sticktime->cx == 2088 || sticktime->cx == 2612 || sticktime->cx == 3113
			|| sticktime->cx == 563 || sticktime->cx == 1065 || sticktime->cx == 1631 || sticktime->cx == 2091 || sticktime->cx == 2620 || sticktime->cx == 3119
			|| sticktime->cx == 566 || sticktime->cx == 1079 || sticktime->cx == 1638 || sticktime->cx == 2095 || sticktime->cx == 2628 || sticktime->cx == 3129
			|| sticktime->cx == 577 || sticktime->cx == 1081 || sticktime->cx == 1645 || sticktime->cx == 2102 || sticktime->cx == 2631 || sticktime->cx == 3133
			|| sticktime->cx == 588 || sticktime->cx == 1083 || sticktime->cx == 1652 || sticktime->cx == 2121 || sticktime->cx == 2635 || sticktime->cx == 3137
			|| sticktime->cx == 592 || sticktime->cx == 1088 || sticktime->cx == 1659 || sticktime->cx == 2125 || sticktime->cx == 2642 || sticktime->cx == 3142
			|| sticktime->cx == 595 || sticktime->cx == 1091 || sticktime->cx == 1665 || sticktime->cx == 2128 || sticktime->cx == 2656 || sticktime->cx == 3149
			|| sticktime->cx == 603 || sticktime->cx == 1098 || sticktime->cx == 1670 || sticktime->cx == 2132 || sticktime->cx == 2659 || sticktime->cx == 3162
			|| sticktime->cx == 607 || sticktime->cx == 1110 || sticktime->cx == 1673 || sticktime->cx == 2137 || sticktime->cx == 2662 || sticktime->cx == 3165
			|| sticktime->cx == 611 || sticktime->cx == 1113 || sticktime->cx == 1681 || sticktime->cx == 2140 || sticktime->cx == 2665 || sticktime->cx == 3167
			|| sticktime->cx == 618 || sticktime->cx == 1115 || sticktime->cx == 1683 || sticktime->cx == 2143 || sticktime->cx == 2671 || sticktime->cx == 3171
			|| sticktime->cx == 626 || sticktime->cx == 1119 || sticktime->cx == 1686 || sticktime->cx == 2147 || sticktime->cx == 2678 || sticktime->cx == 3174
			|| sticktime->cx == 630 || sticktime->cx == 1122 || sticktime->cx == 1688 || sticktime->cx == 2150 || sticktime->cx == 2681 || sticktime->cx == 3179
			|| sticktime->cx == 633 || sticktime->cx == 1128 || sticktime->cx == 1691 || sticktime->cx == 2154 || sticktime->cx == 2685 || sticktime->cx == 3182
			|| sticktime->cx == 636 || sticktime->cx == 1131 || sticktime->cx == 1693 || sticktime->cx == 2157 || sticktime->cx == 2688 || sticktime->cx == 3188
			|| sticktime->cx == 640 || sticktime->cx == 1135 || sticktime->cx == 1697 || sticktime->cx == 2160 || sticktime->cx == 2692 || sticktime->cx == 3192
			)
		{
			if (sticktime->cx % 5 == 0)
			{
				stick1[5]->cx = 1;
			}
			else if (sticktime->cx % 5 == 1)
			{
				stick1[5]->cx = 2;
			}
			else if (sticktime->cx % 5 == 2)
			{
				stick1[5]->cx = 3;
			}
			else if (sticktime->cx % 5 == 3)
			{
				stick1[5]->cx = 4;
			}
			else if (sticktime->cx % 5 == 4)
			{
				stick1[5]->cx = 5;
			}
		}
	}

	if (set2->y == 3)
	{
		if (sticktime->cx == 19 || sticktime->cx == 894 || sticktime->cx == 1549 || sticktime->cx == 2318 || sticktime->cx == 2964 || sticktime->cx == 3652 || sticktime->cx == 4304
			|| sticktime->cx == 43 || sticktime->cx == 898 || sticktime->cx == 1556 || sticktime->cx == 2321 || sticktime->cx == 2970 || sticktime->cx == 3657 || sticktime->cx == 4308
			|| sticktime->cx == 52 || sticktime->cx == 903 || sticktime->cx == 1560 || sticktime->cx == 2324 || sticktime->cx == 2977 || sticktime->cx == 3663 || sticktime->cx == 4313
			|| sticktime->cx == 87 || sticktime->cx == 912 || sticktime->cx == 1566 || sticktime->cx == 2328 || sticktime->cx == 2983 || sticktime->cx == 3672 || sticktime->cx == 4320
			|| sticktime->cx == 92 || sticktime->cx == 918 || sticktime->cx == 1571 || sticktime->cx == 2333 || sticktime->cx == 2987 || sticktime->cx == 3681 || sticktime->cx == 4327
			|| sticktime->cx == 98 || sticktime->cx == 922 || sticktime->cx == 1577 || sticktime->cx == 2338 || sticktime->cx == 2992 || sticktime->cx == 3687 || sticktime->cx == 4341
			|| sticktime->cx == 124 || sticktime->cx == 928 || sticktime->cx == 1585 || sticktime->cx == 2342 || sticktime->cx == 2998 || sticktime->cx == 3691 || sticktime->cx == 4345
			|| sticktime->cx == 133 || sticktime->cx == 932 || sticktime->cx == 1590 || sticktime->cx == 2349 || sticktime->cx == 3004 || sticktime->cx == 3695 || sticktime->cx == 4351
			|| sticktime->cx == 176 || sticktime->cx == 936 || sticktime->cx == 1596 || sticktime->cx == 2356 || sticktime->cx == 3008 || sticktime->cx == 3700 || sticktime->cx == 4358
			|| sticktime->cx == 201 || sticktime->cx == 940 || sticktime->cx == 1601 || sticktime->cx == 2361 || sticktime->cx == 3026 || sticktime->cx == 3711 || sticktime->cx == 4366
			|| sticktime->cx == 210 || sticktime->cx == 944 || sticktime->cx == 1610 || sticktime->cx == 2372 || sticktime->cx == 3030 || sticktime->cx == 3721 || sticktime->cx == 4388
			|| sticktime->cx == 244 || sticktime->cx == 954 || sticktime->cx == 1623 || sticktime->cx == 2376 || sticktime->cx == 3033 || sticktime->cx == 3725 || sticktime->cx == 4392
			|| sticktime->cx == 249 || sticktime->cx == 963 || sticktime->cx == 1629 || sticktime->cx == 2380 || sticktime->cx == 3039 || sticktime->cx == 3729 || sticktime->cx == 4397
			|| sticktime->cx == 255 || sticktime->cx == 969 || sticktime->cx == 1633 || sticktime->cx == 2384 || sticktime->cx == 3051 || sticktime->cx == 3735 || sticktime->cx == 4401
			|| sticktime->cx == 281 || sticktime->cx == 972 || sticktime->cx == 1641 || sticktime->cx == 2389 || sticktime->cx == 3062 || sticktime->cx == 3739 || sticktime->cx == 4407
			|| sticktime->cx == 291 || sticktime->cx == 978 || sticktime->cx == 1650 || sticktime->cx == 2393 || sticktime->cx == 3066 || sticktime->cx == 3751 || sticktime->cx == 4411
			|| sticktime->cx == 334 || sticktime->cx == 984 || sticktime->cx == 1669 || sticktime->cx == 2397 || sticktime->cx == 3070 || sticktime->cx == 3755 || sticktime->cx == 4420
			|| sticktime->cx == 354 || sticktime->cx == 987 || sticktime->cx == 1672 || sticktime->cx == 2403 || sticktime->cx == 3073 || sticktime->cx == 3760 || sticktime->cx == 4431
			|| sticktime->cx == 358 || sticktime->cx == 991 || sticktime->cx == 1675 || sticktime->cx == 2412 || sticktime->cx == 3078 || sticktime->cx == 3764 || sticktime->cx == 4439
			|| sticktime->cx == 362 || sticktime->cx == 995 || sticktime->cx == 1680 || sticktime->cx == 2415 || sticktime->cx == 3082 || sticktime->cx == 3768 || sticktime->cx == 4443
			|| sticktime->cx == 365 || sticktime->cx == 1003 || sticktime->cx == 1685 || sticktime->cx == 2419 || sticktime->cx == 3091 || sticktime->cx == 3773
			|| sticktime->cx == 369 || sticktime->cx == 1017 || sticktime->cx == 1691 || sticktime->cx == 2423 || sticktime->cx == 3095 || sticktime->cx == 3777
			|| sticktime->cx == 373 || sticktime->cx == 1022 || sticktime->cx == 1694 || sticktime->cx == 2429 || sticktime->cx == 3100 || sticktime->cx == 3789
			|| sticktime->cx == 392 || sticktime->cx == 1028 || sticktime->cx == 1703 || sticktime->cx == 2433 || sticktime->cx == 3104 || sticktime->cx == 3823
			|| sticktime->cx == 396 || sticktime->cx == 1032 || sticktime->cx == 1707 || sticktime->cx == 2439 || sticktime->cx == 3108 || sticktime->cx == 3829
			|| sticktime->cx == 399 || sticktime->cx == 1038 || sticktime->cx == 1713 || sticktime->cx == 2443 || sticktime->cx == 3119 || sticktime->cx == 3832
			|| sticktime->cx == 403 || sticktime->cx == 1044 || sticktime->cx == 1722 || sticktime->cx == 2452 || sticktime->cx == 3123 || sticktime->cx == 3836
			|| sticktime->cx == 407 || sticktime->cx == 1050 || sticktime->cx == 1727 || sticktime->cx == 2456 || sticktime->cx == 3130 || sticktime->cx == 3843
			|| sticktime->cx == 412 || sticktime->cx == 1057 || sticktime->cx == 1733 || sticktime->cx == 2463 || sticktime->cx == 3134 || sticktime->cx == 3848
			|| sticktime->cx == 432 || sticktime->cx == 1062 || sticktime->cx == 1743 || sticktime->cx == 2471 || sticktime->cx == 3140 || sticktime->cx == 3852
			|| sticktime->cx == 435 || sticktime->cx == 1068 || sticktime->cx == 1747 || sticktime->cx == 2481 || sticktime->cx == 3143 || sticktime->cx == 3856
			|| sticktime->cx == 439 || sticktime->cx == 1074 || sticktime->cx == 1752 || sticktime->cx == 2490 || sticktime->cx == 3148 || sticktime->cx == 3861
			|| sticktime->cx == 442 || sticktime->cx == 1083 || sticktime->cx == 1760 || sticktime->cx == 2496 || sticktime->cx == 3159 || sticktime->cx == 3866
			|| sticktime->cx == 446 || sticktime->cx == 1097 || sticktime->cx == 1769 || sticktime->cx == 2500 || sticktime->cx == 3163 || sticktime->cx == 3870
			|| sticktime->cx == 452 || sticktime->cx == 1102 || sticktime->cx == 1782 || sticktime->cx == 2511 || sticktime->cx == 3168 || sticktime->cx == 3874
			|| sticktime->cx == 461 || sticktime->cx == 1107 || sticktime->cx == 1788 || sticktime->cx == 2514 || sticktime->cx == 3176 || sticktime->cx == 3877
			|| sticktime->cx == 465 || sticktime->cx == 1111 || sticktime->cx == 1792 || sticktime->cx == 2520 || sticktime->cx == 3185 || sticktime->cx == 3886
			|| sticktime->cx == 469 || sticktime->cx == 1116 || sticktime->cx == 1799 || sticktime->cx == 2530 || sticktime->cx == 3199 || sticktime->cx == 3903
			|| sticktime->cx == 473 || sticktime->cx == 1122 || sticktime->cx == 1808 || sticktime->cx == 2541 || sticktime->cx == 3203 || sticktime->cx == 3907
			|| sticktime->cx == 482 || sticktime->cx == 1132 || sticktime->cx == 1829 || sticktime->cx == 2548 || sticktime->cx == 3208 || sticktime->cx == 3911
			|| sticktime->cx == 493 || sticktime->cx == 1138 || sticktime->cx == 1835 || sticktime->cx == 2555 || sticktime->cx == 3216 || sticktime->cx == 3918
			|| sticktime->cx == 508 || sticktime->cx == 1141 || sticktime->cx == 1840 || sticktime->cx == 2561 || sticktime->cx == 3224 || sticktime->cx == 3925
			|| sticktime->cx == 512 || sticktime->cx == 1147 || sticktime->cx == 1846 || sticktime->cx == 2566 || sticktime->cx == 3245 || sticktime->cx == 3929
			|| sticktime->cx == 516 || sticktime->cx == 1153 || sticktime->cx == 1852 || sticktime->cx == 2569 || sticktime->cx == 3248 || sticktime->cx == 3934
			|| sticktime->cx == 520 || sticktime->cx == 1161 || sticktime->cx == 1862 || sticktime->cx == 2579 || sticktime->cx == 3251 || sticktime->cx == 3938
			|| sticktime->cx == 525 || sticktime->cx == 1167 || sticktime->cx == 1871 || sticktime->cx == 2595 || sticktime->cx == 3256 || sticktime->cx == 3947
			|| sticktime->cx == 531 || sticktime->cx == 1173 || sticktime->cx == 1881 || sticktime->cx == 2601 || sticktime->cx == 3261 || sticktime->cx == 3950
			|| sticktime->cx == 537 || sticktime->cx == 1179 || sticktime->cx == 1885 || sticktime->cx == 2605 || sticktime->cx == 3265 || sticktime->cx == 3956
			|| sticktime->cx == 541 || sticktime->cx == 1183 || sticktime->cx == 1891 || sticktime->cx == 2611 || sticktime->cx == 3269 || sticktime->cx == 3962
			|| sticktime->cx == 548 || sticktime->cx == 1192 || sticktime->cx == 1909 || sticktime->cx == 2614 || sticktime->cx == 3278 || sticktime->cx == 3967
			|| sticktime->cx == 554 || sticktime->cx == 1202 || sticktime->cx == 1920 || sticktime->cx == 2619 || sticktime->cx == 3282 || sticktime->cx == 3973
			|| sticktime->cx == 558 || sticktime->cx == 1217 || sticktime->cx == 1930 || sticktime->cx == 2625 || sticktime->cx == 3288 || sticktime->cx == 3977
			|| sticktime->cx == 564 || sticktime->cx == 1221 || sticktime->cx == 1939 || sticktime->cx == 2634 || sticktime->cx == 3297 || sticktime->cx == 3983
			|| sticktime->cx == 569 || sticktime->cx == 1225 || sticktime->cx == 1951 || sticktime->cx == 2639 || sticktime->cx == 3303 || sticktime->cx == 3989
			|| sticktime->cx == 575 || sticktime->cx == 1231 || sticktime->cx == 1959 || sticktime->cx == 2643 || sticktime->cx == 3305 || sticktime->cx == 3994
			|| sticktime->cx == 595 || sticktime->cx == 1240 || sticktime->cx == 1969 || sticktime->cx == 2649 || sticktime->cx == 3309 || sticktime->cx == 4012
			|| sticktime->cx == 599 || sticktime->cx == 1265 || sticktime->cx == 1978 || sticktime->cx == 2659 || sticktime->cx == 3318 || sticktime->cx == 4015
			|| sticktime->cx == 602 || sticktime->cx == 1271 || sticktime->cx == 1987 || sticktime->cx == 2673 || sticktime->cx == 3322 || sticktime->cx == 4018
			|| sticktime->cx == 606 || sticktime->cx == 1274 || sticktime->cx == 1999 || sticktime->cx == 2679 || sticktime->cx == 3327 || sticktime->cx == 4024
			|| sticktime->cx == 610 || sticktime->cx == 1279 || sticktime->cx == 2008 || sticktime->cx == 2682 || sticktime->cx == 3332 || sticktime->cx == 4028
			|| sticktime->cx == 614 || sticktime->cx == 1285 || sticktime->cx == 2017 || sticktime->cx == 2686 || sticktime->cx == 3342 || sticktime->cx == 4037
			|| sticktime->cx == 619 || sticktime->cx == 1290 || sticktime->cx == 2026 || sticktime->cx == 2692 || sticktime->cx == 3356 || sticktime->cx == 4050
			|| sticktime->cx == 623 || sticktime->cx == 1296 || sticktime->cx == 2036 || sticktime->cx == 2697 || sticktime->cx == 3361 || sticktime->cx == 4056
			|| sticktime->cx == 628 || sticktime->cx == 1299 || sticktime->cx == 2041 || sticktime->cx == 2706 || sticktime->cx == 3367 || sticktime->cx == 4053
			|| sticktime->cx == 637 || sticktime->cx == 1305 || sticktime->cx == 2046 || sticktime->cx == 2710 || sticktime->cx == 3373 || sticktime->cx == 4056
			|| sticktime->cx == 648 || sticktime->cx == 1310 || sticktime->cx == 2057 || sticktime->cx == 2716 || sticktime->cx == 3381 || sticktime->cx == 4062
			|| sticktime->cx == 655 || sticktime->cx == 1316 || sticktime->cx == 2067 || sticktime->cx == 2721 || sticktime->cx == 3405 || sticktime->cx == 4066
			|| sticktime->cx == 659 || sticktime->cx == 1331 || sticktime->cx == 2075 || sticktime->cx == 2727 || sticktime->cx == 3409 || sticktime->cx == 4075
			|| sticktime->cx == 664 || sticktime->cx == 1344 || sticktime->cx == 2086 || sticktime->cx == 2736 || sticktime->cx == 3414 || sticktime->cx == 4084
			|| sticktime->cx == 668 || sticktime->cx == 1348 || sticktime->cx == 2095 || sticktime->cx == 2742 || sticktime->cx == 3418 || sticktime->cx == 4080
			|| sticktime->cx == 675 || sticktime->cx == 1354 || sticktime->cx == 2106 || sticktime->cx == 2748 || sticktime->cx == 3423 || sticktime->cx == 4088
			|| sticktime->cx == 680 || sticktime->cx == 1358 || sticktime->cx == 2104 || sticktime->cx == 2752 || sticktime->cx == 3427 || sticktime->cx == 4093
			|| sticktime->cx == 686 || sticktime->cx == 1365 || sticktime->cx == 2125 || sticktime->cx == 2757 || sticktime->cx == 3436 || sticktime->cx == 4097
			|| sticktime->cx == 697 || sticktime->cx == 1369 || sticktime->cx == 2135 || sticktime->cx == 2767 || sticktime->cx == 3445 || sticktime->cx == 4105
			|| sticktime->cx == 713 || sticktime->cx == 1375 || sticktime->cx == 2143 || sticktime->cx == 2776 || sticktime->cx == 3456 || sticktime->cx == 4109
			|| sticktime->cx == 717 || sticktime->cx == 1381 || sticktime->cx == 2154 || sticktime->cx == 2790 || sticktime->cx == 3460 || sticktime->cx == 4114
			|| sticktime->cx == 723 || sticktime->cx == 1388 || sticktime->cx == 2172 || sticktime->cx == 2797 || sticktime->cx == 3485 || sticktime->cx == 4118
			|| sticktime->cx == 727 || sticktime->cx == 1391 || sticktime->cx == 2176 || sticktime->cx == 2801 || sticktime->cx == 3492 || sticktime->cx == 4123
			|| sticktime->cx == 732 || sticktime->cx == 1397 || sticktime->cx == 2181 || sticktime->cx == 2806 || sticktime->cx == 3500 || sticktime->cx == 4127
			|| sticktime->cx == 736 || sticktime->cx == 1404 || sticktime->cx == 2187 || sticktime->cx == 2815 || sticktime->cx == 3504 || sticktime->cx == 4132
			|| sticktime->cx == 743 || sticktime->cx == 1411 || sticktime->cx == 2191 || sticktime->cx == 2839 || sticktime->cx == 3508 || sticktime->cx == 4136
			|| sticktime->cx == 747 || sticktime->cx == 1415 || sticktime->cx == 2195 || sticktime->cx == 2843 || sticktime->cx == 3514 || sticktime->cx == 4144
			|| sticktime->cx == 751 || sticktime->cx == 1420 || sticktime->cx == 2201 || sticktime->cx == 2850 || sticktime->cx == 3519 || sticktime->cx == 4149
			|| sticktime->cx == 758 || sticktime->cx == 1424 || sticktime->cx == 2205 || sticktime->cx == 2852 || sticktime->cx == 3525 || sticktime->cx == 4153
			|| sticktime->cx == 763 || sticktime->cx == 1430 || sticktime->cx == 2215 || sticktime->cx == 2861 || sticktime->cx == 3536 || sticktime->cx == 4156
			|| sticktime->cx == 767 || sticktime->cx == 1434 || sticktime->cx == 2224 || sticktime->cx == 2865 || sticktime->cx == 3550 || sticktime->cx == 4162
			|| sticktime->cx == 781 || sticktime->cx == 1451 || sticktime->cx == 2231 || sticktime->cx == 2870 || sticktime->cx == 3554 || sticktime->cx == 4170
			|| sticktime->cx == 796 || sticktime->cx == 1454 || sticktime->cx == 2239 || sticktime->cx == 2874 || sticktime->cx == 3559 || sticktime->cx == 4182
			|| sticktime->cx == 801 || sticktime->cx == 1457 || sticktime->cx == 2243 || sticktime->cx == 2880 || sticktime->cx == 3563 || sticktime->cx == 4186
			|| sticktime->cx == 805 || sticktime->cx == 1463 || sticktime->cx == 2253 || sticktime->cx == 2886 || sticktime->cx == 3572 || sticktime->cx == 4191
			|| sticktime->cx == 815 || sticktime->cx == 1469 || sticktime->cx == 2256 || sticktime->cx == 2891 || sticktime->cx == 3579 || sticktime->cx == 4200
			|| sticktime->cx == 821 || sticktime->cx == 1477 || sticktime->cx == 2260 || sticktime->cx == 2893 || sticktime->cx == 3583 || sticktime->cx == 4208
			|| sticktime->cx == 827 || sticktime->cx == 1493 || sticktime->cx == 2264 || sticktime->cx == 2903 || sticktime->cx == 3587 || sticktime->cx == 4228
			|| sticktime->cx == 836 || sticktime->cx == 1496 || sticktime->cx == 2267 || sticktime->cx == 2917 || sticktime->cx == 3592 || sticktime->cx == 4231
			|| sticktime->cx == 845 || sticktime->cx == 1499 || sticktime->cx == 2270 || sticktime->cx == 2924 || sticktime->cx == 3598 || sticktime->cx == 4234
			|| sticktime->cx == 850 || sticktime->cx == 1505 || sticktime->cx == 2273 || sticktime->cx == 2927 || sticktime->cx == 3602 || sticktime->cx == 4239
			|| sticktime->cx == 856 || sticktime->cx == 1509 || sticktime->cx == 2279 || sticktime->cx == 2931 || sticktime->cx == 3613 || sticktime->cx == 4266
			|| sticktime->cx == 860 || sticktime->cx == 1516 || sticktime->cx == 2282 || sticktime->cx == 2940 || sticktime->cx == 3618 || sticktime->cx == 4270
			|| sticktime->cx == 864 || sticktime->cx == 1520 || sticktime->cx == 2292 || sticktime->cx == 2944 || sticktime->cx == 3622 || sticktime->cx == 4280
			|| sticktime->cx == 873 || sticktime->cx == 1526 || sticktime->cx == 2303 || sticktime->cx == 2949 || sticktime->cx == 3633 || sticktime->cx == 4286
			|| sticktime->cx == 885 || sticktime->cx == 1531 || sticktime->cx == 2307 || sticktime->cx == 2953 || sticktime->cx == 3637 || sticktime->cx == 4289
			|| sticktime->cx == 889 || sticktime->cx == 1535 || sticktime->cx == 2312 || sticktime->cx == 2962 || sticktime->cx == 3641 || sticktime->cx == 4295
			)
		{
			if (sticktime->cx % 5 == 0)
			{
				stick1[5]->cx = 1;
			}
			else if (sticktime->cx % 5 == 1)
			{
				stick1[5]->cx = 2;
			}
			else if (sticktime->cx % 5 == 2)
			{
				stick1[5]->cx = 3;
			}
			else if (sticktime->cx % 5 == 3)
			{
				stick1[5]->cx = 4;
			}
			else if (sticktime->cx % 5 == 4)
			{
				stick1[5]->cx = 5;
			}
		}
	}
	// 1
	for (int i = 0; i < StickNum; i++)
	{
		if (stick1[i]->act == false)
		{
			if (stick1[5]->cx == 1)
			{
				stick1[i]->x = 14;
				stick1[i]->y = 1;
				stick1[i]->act = true;
				stick1[5]->cx = 0;
				break;
			}
		}
	}

	for (int i = 0; i < StickNum; i++)
	{
		if (stick1[i]->act == true)
		{
			stick1[i]->y++;
			if (stick1[i]->y == 38)
			{
				point->cx = 1;
				point->x -= 6;
				if (point->y >= 1)
				{
					point->y -= 1;
				}
				if (point->y < 0)
				{
					point->y += 2;
				}
				for (int j = 0; j < rand() % 10 + 12; j++)
				{
					WriteBuffer(effect[j]->x, effect[j]->y, effect[j]->shape, 연한빨간색);
					WriteBuffer(effect[j]->cx, effect[j]->y, effect[j]->shape, 연한빨간색);
				}
				WriteBuffer(2, 27, " MISS", 빨간색);
				stick1[i]->act = false;
			}
		}
	}

	// 2
	for (int i = 0; i < StickNum; i++)
	{
		if (stick2[i]->act == false)
		{
			if (stick1[5]->cx == 2)
			{
				stick2[i]->x = 26;
				stick2[i]->y = 1;
				stick2[i]->act = true;
				stick1[5]->cx = 0;
				break;
			}
		}
	}

	for (int i = 0; i < StickNum; i++)
	{
		if (stick2[i]->act == true)
		{
			stick2[i]->y++;
			if (stick2[i]->y == 38)
			{
				point->cx = 1;
				point->x -= 6;
				if (point->y >= 1)
				{
					point->y -= 1;
				}
				if (point->y < 0)
				{
					point->y += 2;
				}
				for (int j = 0; j < rand() % 10 + 12; j++)
				{
					WriteBuffer(effect2[j]->x, effect2[j]->y, effect2[j]->shape, 연한빨간색);
					WriteBuffer(effect2[j]->cx, effect2[j]->y, effect2[j]->shape, 연한빨간색);
				}
				WriteBuffer(2, 27, " MISS", 빨간색);
				stick2[i]->act = false;
			}
		}
	}

	// 3
	for (int i = 0; i < StickNum; i++)
	{
		if (stick3[i]->act == false)
		{
			if (stick1[5]->cx == 3)
			{
				stick3[i]->x = 38;
				stick3[i]->y = 1;
				stick3[i]->act = true;
				stick1[5]->cx = 0;
				break;
			}
		}
	}

	for (int i = 0; i < StickNum; i++)
	{
		if (stick3[i]->act == true)
		{
			stick3[i]->y++;
			if (stick3[i]->y == 38)
			{
				point->cx = 1;
				point->x -= 6;
				if (point->y >= 1)
				{
					point->y -= 1;
				}
				if (point->y < 0)
				{
					point->y += 2;
				}
				for (int j = 0; j < rand() % 10 + 12; j++)
				{
					WriteBuffer(effect3[j]->x, effect3[j]->y, effect3[j]->shape, 연한빨간색);
					WriteBuffer(effect3[j]->cx, effect3[j]->y, effect3[j]->shape, 연한빨간색);
				}
				WriteBuffer(2, 27, " MISS", 빨간색);
				stick3[i]->act = false;
			}
		}
	}

	// 4
	for (int i = 0; i < StickNum; i++)
	{
		if (stick4[i]->act == false)
		{
			if (stick1[5]->cx == 4)
			{
				stick4[i]->x = 50;
				stick4[i]->y = 1;
				stick4[i]->act = true;
				stick1[5]->cx = 0;
				break;
			}
		}
	}

	for (int i = 0; i < StickNum; i++)
	{
		if (stick4[i]->act == true)
		{
			stick4[i]->y++;
			if (stick4[i]->y == 38)
			{
				point->cx = 1;
				point->x -= 6;
				if (point->y >= 1)
				{
					point->y -= 1;
				}
				if (point->y < 0)
				{
					point->y += 2;
				}
				for (int j = 0; j < rand() % 10 + 12; j++)
				{
					WriteBuffer(effect4[j]->x, effect4[j]->y, effect4[j]->shape, 연한빨간색);
					WriteBuffer(effect4[j]->cx, effect4[j]->y, effect4[j]->shape, 연한빨간색);
				}
				WriteBuffer(2, 27, " MISS", 빨간색);
				stick4[i]->act = false;
			}
		}
	}

	// 5
	for (int i = 0; i < StickNum; i++)
	{
		if (stick5[i]->act == false)
		{
			if (stick1[5]->cx == 5)
			{
				stick5[i]->x = 62;
				stick5[i]->y = 1;
				stick5[i]->act = true;
				stick1[5]->cx = 0;
				break;
			}
		}

	}

	for (int i = 0; i < StickNum; i++)
	{
		if (stick5[i]->act == true)
		{
			stick5[i]->y++;
			if (stick5[i]->y == 38)
			{
				point->cx = 1;
				point->x -= 6;
				if (point->y >= 1)
				{
					point->y -= 1;
				}
				if (point->y < 0)
				{
					point->y += 2;
				}
				for (int j = 0; j < rand() % 10 + 12; j++)
				{
					WriteBuffer(effect5[j]->x, effect5[j]->y, effect5[j]->shape, 연한빨간색);
					WriteBuffer(effect5[j]->cx, effect5[j]->y, effect5[j]->shape, 연한빨간색);
				}
				WriteBuffer(2, 27, " MISS", 빨간색);
				stick5[i]->act = false;
			}
		}
	}
}

void StageRender2()
{
	for (int y = 0; y < BufferHeight - 1; y++)
	{
		for (int x = 0; x < BufferWidth; x += 2)
		{
			if (x == 0)
			{
				WriteBuffer(0, y, "ㅁ", 노란색);
			}
			if (y == 0)
			{
				WriteBuffer(x, 0, "ㅁ", 노란색);
			}
			if (y == BufferHeight - 2)
			{
				WriteBuffer(x, BufferHeight - 2, "ㅁ", 노란색);
			}
			if (x == BufferWidth - 2)
			{
				WriteBuffer(BufferWidth - 2, y, "ㅁ", 노란색);
			}
		}
	}

	WriteBuffer(14, 36, "SPACE.", 초록색);
	WriteBuffer(28, 36, "←", 초록색);
	WriteBuffer(40, 36, "↑", 초록색);
	WriteBuffer(52, 36, "↓", 초록색);
	WriteBuffer(64, 36, "→", 초록색);

	for (int i = 0; i < WayNum; i++)
	{
		WriteBuffer(way[i]->x, way[i]->y, way[i]->shape, 빨간색);
	}

	//HP Bar
	for (int i = 0; i < Hpbar; i++)
	{
		if (point->x >= (-4)*i)
		{
			WriteBuffer(hpbar[i]->x, hpbar[i]->y, hpbar[i]->shape, 연한파란색);
		}
		WriteBuffer(hpbar[i]->x - 2, hpbar[i]->y, "Ι", 연한파란색);
		WriteBuffer(hpbar[i]->x + 2, hpbar[i]->y, "Ι", 연한파란색);
	}

	//Special Bar
	for (int i = 0; i < Hpbar; i++)
	{
		if (point->y >= 3 * i + 1)
		{
			WriteBuffer(specialbar[i]->x, specialbar[i]->y, specialbar[i]->shape, 연한빨간색);
		}
		WriteBuffer(specialbar[i]->x - 2, specialbar[i]->y, "Ι", 연한빨간색);
		WriteBuffer(specialbar[i]->x + 2, specialbar[i]->y, "Ι", 연한빨간색);
	}

	if (point->y >= 59)
	{
		WriteBuffer(2, 23, "ENTER", 192);
	}
	if (point->y < 59)
	{
		WriteBuffer(2, 23, "      ", 0);
	}

	//1
	for (int i = 0; i < StickNum; i++)
	{
		if (stick1[i]->act == true)
		{
			if (point->y < 0)
			{
				WriteBuffer(stick1[i]->x, stick1[i]->y, point->shape, 진한노란색);
			}
			if (point->y >= 0)
			{
				WriteBuffer(stick1[i]->x, stick1[i]->y, stick1[i]->shape, 자주색);
			}
			if (GetAsyncKeyState(VK_SPACE) & 0x8000)
			{
				if (stickcoolication1(stick1[i], way[0]) == true)
				{
					stick1[i]->act = false;
					for (int j = 0; j < 9; j++)
					{
						if (point->cx < 100)
						{
							WriteBuffer(40, 9 + j, NumImg[j], 연한옥색);
							WriteBuffer(25, 9 + j, NumImg10[j], 연한옥색);
						}
						if (point->cx >= 100)
						{
							WriteBuffer(48, 9 + j, NumImg[j], 연한옥색);
							WriteBuffer(33, 9 + j, NumImg10[j], 연한옥색);
							WriteBuffer(18, 9 + j, NumImg100[j], 연한옥색);
						}
					}
					if (stick1[i]->y == 35)
					{
						for (int j = 0; j < rand() % 10 + 12; j++)
						{
							WriteBuffer(effect[j]->x, effect[j]->y, effect[j]->shape, 연한초록색);
							WriteBuffer(effect[j]->cx, effect[j]->y, effect[j]->shape, 연한초록색);
						}
						WriteBuffer(2, 27, "PERPECT", 초록색);
						sticktime->x += 10;
					}
					if (stick1[i]->y == 34 || stick1[i]->y == 36)
					{
						for (int j = 0; j < rand() % 10 + 12; j++)
						{
							WriteBuffer(effect[j]->x, effect[j]->y, effect[j]->shape, 진한노란색);
							WriteBuffer(effect[j]->cx, effect[j]->y, effect[j]->shape, 진한노란색);
						}
						WriteBuffer(2, 27, " GREAT", 노란색);
					}
					point->cx++;
					if (point->cx > maxpoint->x)
					{
						maxpoint->x++;
					}
					if (point->x <= 0)
					{
						point->x += 1;
					}
					if (point->y >= 0)
					{
						if (point->y <= 62)
						{
							point->y += 2;
						}
						sticktime->x += 21;
					}
					if (point->y < 0)
					{
						point->y += 1;
						sticktime->x += 63;
					}
				}
			}
		}
	}

	//2
	for (int i = 0; i < StickNum; i++)
	{
		if (stick2[i]->act == true)
		{
			if (point->y < 0)
			{
				WriteBuffer(stick2[i]->x, stick2[i]->y, point->shape, 진한노란색);
			}
			if (point->y >= 0)
			{
				WriteBuffer(stick2[i]->x, stick2[i]->y, stick2[i]->shape, 자주색);
			}
			if (GetAsyncKeyState(VK_LEFT) & 0x8000)
			{
				if (stickcoolication2(stick2[i], way[1]) == true)
				{
					stick2[i]->act = false;
					for (int j = 0; j < 9; j++)
					{
						if (point->cx < 100)
						{
							WriteBuffer(40, 9 + j, NumImg[j], 연한옥색);
							WriteBuffer(25, 9 + j, NumImg10[j], 연한옥색);
						}
						if (point->cx >= 100)
						{
							WriteBuffer(48, 9 + j, NumImg[j], 연한옥색);
							WriteBuffer(33, 9 + j, NumImg10[j], 연한옥색);
							WriteBuffer(18, 9 + j, NumImg100[j], 연한옥색);
						}
					}
					if (stick2[i]->y == 35)
					{
						for (int j = 0; j < rand() % 10 + 12; j++)
						{
							WriteBuffer(effect2[j]->x, effect2[j]->y, effect2[j]->shape, 연한초록색);
							WriteBuffer(effect2[j]->cx, effect2[j]->y, effect2[j]->shape, 연한초록색);
						}
						WriteBuffer(2, 27, "PERPECT", 초록색);
						sticktime->x += 10;
					}
					if (stick2[i]->y == 34 || stick2[i]->y == 36)
					{
						for (int j = 0; j < rand() % 10 + 12; j++)
						{
							WriteBuffer(effect2[j]->x, effect2[j]->y, effect2[j]->shape, 진한노란색);
							WriteBuffer(effect2[j]->cx, effect2[j]->y, effect2[j]->shape, 진한노란색);
						}
						WriteBuffer(2, 27, " GREAT", 노란색);
					}
					point->cx++;
					if (point->cx > maxpoint->x)
					{
						maxpoint->x++;
					}
					if (point->x <= 0)
					{
						point->x += 1;
					}
					if (point->y >= 0)
					{
						if (point->y <= 62)
						{
							point->y += 2;
						}
						sticktime->x += 21;
					}
					if (point->y < 0)
					{
						point->y += 1;
						sticktime->x += 63;
					}
				}
			}
		}
	}

	//3
	for (int i = 0; i < StickNum; i++)
	{
		if (stick3[i]->act == true)
		{
			if (GetAsyncKeyState(VK_UP) & 0x8000)
			{
				if (stickcoolication3(stick3[i], way[2]) == true)
				{
					stick3[i]->act = false;
					for (int j = 0; j < 9; j++)
					{
						if (point->cx < 100)
						{
							WriteBuffer(40, 9 + j, NumImg[j], 연한옥색);
							WriteBuffer(25, 9 + j, NumImg10[j], 연한옥색);
						}
						if (point->cx >= 100)
						{
							WriteBuffer(48, 9 + j, NumImg[j], 연한옥색);
							WriteBuffer(33, 9 + j, NumImg10[j], 연한옥색);
							WriteBuffer(18, 9 + j, NumImg100[j], 연한옥색);
						}
					}
					if (stick3[i]->y == 35)
					{
						for (int j = 0; j < rand() % 10 + 12; j++)
						{
							WriteBuffer(effect3[j]->x, effect3[j]->y, effect3[j]->shape, 연한초록색);
							WriteBuffer(effect3[j]->cx, effect3[j]->y, effect3[j]->shape, 연한초록색);
						}
						WriteBuffer(2, 27, "PERPECT", 초록색);
						sticktime->x += 10;
					}
					if (stick3[i]->y == 34 || stick3[i]->y == 36)
					{
						for (int j = 0; j < rand() % 10 + 12; j++)
						{
							WriteBuffer(effect3[j]->x, effect3[j]->y, effect3[j]->shape, 진한노란색);
							WriteBuffer(effect3[j]->cx, effect3[j]->y, effect3[j]->shape, 진한노란색);
						}
						WriteBuffer(2, 27, " GREAT", 노란색);
					}
					point->cx++;
					if (point->cx > maxpoint->x)
					{
						maxpoint->x++;
					}
					if (point->x <= 0)
					{
						point->x += 1;
					}
					if (point->y >= 0)
					{
						if (point->y <= 62)
						{
							point->y += 2;
						}
						sticktime->x += 21;
					}
					if (point->y < 0)
					{
						point->y += 1;
						sticktime->x += 63;
					}
				}
			}

			if (point->y < 0)
			{
				WriteBuffer(stick3[i]->x, stick3[i]->y, point->shape, 진한노란색);
			}
			if (point->y >= 0)
			{
				WriteBuffer(stick3[i]->x, stick3[i]->y, stick3[i]->shape, 자주색);
			}
		}
	}

	//4
	for (int i = 0; i < StickNum; i++)
	{
		if (stick4[i]->act == true)
		{
			if (point->y < 0)
			{
				WriteBuffer(stick4[i]->x, stick4[i]->y, point->shape, 진한노란색);
			}
			if (point->y >= 0)
			{
				WriteBuffer(stick4[i]->x, stick4[i]->y, stick4[i]->shape, 자주색);
			}
			if (GetAsyncKeyState(VK_DOWN) & 0x8000)
			{
				if (stickcoolication4(stick4[i], way[3]) == true)
				{
					stick4[i]->act = false;
					for (int j = 0; j < 9; j++)
					{
						if (point->cx < 100)
						{
							WriteBuffer(40, 9 + j, NumImg[j], 연한옥색);
							WriteBuffer(25, 9 + j, NumImg10[j], 연한옥색);
						}
						if (point->cx >= 100)
						{
							WriteBuffer(48, 9 + j, NumImg[j], 연한옥색);
							WriteBuffer(33, 9 + j, NumImg10[j], 연한옥색);
							WriteBuffer(18, 9 + j, NumImg100[j], 연한옥색);
						}
					}
					if (stick4[i]->y == 35)
					{
						for (int j = 0; j < rand() % 10 + 12; j++)
						{
							WriteBuffer(effect4[j]->x, effect4[j]->y, effect4[j]->shape, 연한초록색);
							WriteBuffer(effect4[j]->cx, effect4[j]->y, effect4[j]->shape, 연한초록색);
						}
						WriteBuffer(2, 27, "PERPECT", 초록색);
						sticktime->x += 10;
					}
					if (stick4[i]->y == 34 || stick4[i]->y == 36)
					{
						for (int j = 0; j < rand() % 10 + 12; j++)
						{
							WriteBuffer(effect4[j]->x, effect4[j]->y, effect4[j]->shape, 진한노란색);
							WriteBuffer(effect4[j]->cx, effect4[j]->y, effect4[j]->shape, 진한노란색);
						}
						WriteBuffer(2, 27, " GREAT", 노란색);
					}
					point->cx++;
					if (point->cx > maxpoint->x)
					{
						maxpoint->x++;
					}
					if (point->x <= 0)
					{
						point->x += 1;
					}
					if (point->y >= 0)
					{
						if (point->y <= 62)
						{
							point->y += 2;
						}
						sticktime->x += 21;
					}
					if (point->y < 0)
					{
						point->y += 1;
						sticktime->x += 63;
					}
				}
			}
		}
	}

	//5
	for (int i = 0; i < StickNum; i++)
	{
		if (stick5[i]->act == true)
		{
			if (point->y < 0)
			{
				WriteBuffer(stick5[i]->x, stick5[i]->y, point->shape, 진한노란색);
			}
			if (point->y >= 0)
			{
				WriteBuffer(stick5[i]->x, stick5[i]->y, stick5[i]->shape, 자주색);
			}
			if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
			{
				if (stickcoolication5(stick5[i], way[4]) == true)
				{
					stick5[i]->act = false;
					for (int j = 0; j < 9; j++)
					{
						if (point->cx < 100)
						{
							WriteBuffer(40, 9 + j, NumImg[j], 연한옥색);
							WriteBuffer(25, 9 + j, NumImg10[j], 연한옥색);
						}
						if (point->cx >= 100)
						{
							WriteBuffer(48, 9 + j, NumImg[j], 연한옥색);
							WriteBuffer(33, 9 + j, NumImg10[j], 연한옥색);
							WriteBuffer(18, 9 + j, NumImg100[j], 연한옥색);
						}
					}
					if (stick5[i]->y == 35)
					{
						for (int j = 0; j < rand() % 10 + 12; j++)
						{
							WriteBuffer(effect5[j]->x, effect5[j]->y, effect5[j]->shape, 연한초록색);
							WriteBuffer(effect5[j]->cx, effect5[j]->y, effect5[j]->shape, 연한초록색);
						}
						WriteBuffer(2, 27, "PERPECT", 초록색);
						sticktime->x += 10;
					}
					if (stick5[i]->y == 34 || stick5[i]->y == 36)
					{
						for (int j = 0; j < rand() % 10 + 12; j++)
						{
							WriteBuffer(effect5[j]->x, effect5[j]->y, effect5[j]->shape, 진한노란색);
							WriteBuffer(effect5[j]->cx, effect5[j]->y, effect5[j]->shape, 진한노란색);
						}
						WriteBuffer(2, 27, " GREAT", 노란색);
					}
					point->cx++;
					if (point->cx > maxpoint->x)
					{
						maxpoint->x++;
					}
					if (point->x <= 0)
					{
						point->x += 1;
					}
					if (point->y >= 0)
					{
						if (point->y <= 62)
						{
							point->y += 2;
						}
						sticktime->x += 21;
					}
					if (point->y < 0)
					{
						point->y += 1;
						sticktime->x += 63;
					}
				}
			}
		}
	}

	if (set2->y == 1)
	{
		_itoa_s(sticktime->x + stick1[0]->cx, sNum, 10);
	}
	if (set2->y == 2)
	{
		_itoa_s(sticktime->x + (stick1[0]->cx / 2), sNum, 10);
	}
	if (set2->y == 3)
	{
		_itoa_s(sticktime->x + (stick1[0]->cx / 3), sNum, 10);
	}
	_itoa_s(stick1[3]->cx, sNum5, 10);
	WriteBuffer(10, 2, "점수 :", 흰색);
	WriteBuffer(17, 2, sNum, 흰색);
	WriteBuffer(24, 2, "최고점수 :", 흰색);
	if (set2->y == 1)
	{
		if (stick1[0]->cx + sticktime->x > stick1[3]->cx)
		{
			WriteBuffer(35, 2, sNum, 흰색);
		}
		else
		{
			WriteBuffer(35, 2, sNum5, 흰색);
		}
	}
	if (set2->y == 2)
	{
		if ((stick1[0]->cx / 2) + sticktime->x > stick1[3]->cx)
		{
			WriteBuffer(35, 2, sNum, 흰색);
		}
		else
		{
			WriteBuffer(35, 2, sNum5, 흰색);
		}
	}
	if (set2->y == 3)
	{
		if ((stick1[0]->cx / 3) + sticktime->x > stick1[3]->cx)
		{
			WriteBuffer(35, 2, sNum, 흰색);
		}
		else
		{
			WriteBuffer(35, 2, sNum5, 흰색);
		}
	}

	WriteBuffer(73, 36, "ESC", 회색);
	WriteBuffer(70, 37, "다시하기", 회색);
}

void StageMenuInit()
{
	stagemenu = (Stagemenu*)malloc(sizeof(Stagemenu));
	stagemenu->x = 32;
	stagemenu->y = 11;
	stagemenu->shape = "▶";
}

void StageMenuProgress()
{
	if (GetAsyncKeyState(VK_ESCAPE) & 0x0001)
	{
		if (set->cx == 1)
		{
			state = STAGE;
			sndPlaySoundA(MILLION, SND_ASYNC);
			stagemenu->y = 11;
			for (int i = 0; i < StickNum; i++)
			{
				stick1[i]->act = false;
				stick2[i]->act = false;
				stick3[i]->act = false;
				stick4[i]->act = false;
				stick5[i]->act = false;
			}
			sticktime->cx = 2;
			sticktime->x = 0;
			point->cx = 1;
			point->x = 0;
			point->y = 0;
			maxpoint->x = 0;
			stick1[0]->cx = 0;
		}
		if (set->cx == 2)
		{
			state = STAGE2;
			sndPlaySoundA(TT, SND_ASYNC);
			stagemenu->y = 11;
			for (int i = 0; i < StickNum; i++)
			{
				stick1[i]->act = false;
				stick2[i]->act = false;
				stick3[i]->act = false;
				stick4[i]->act = false;
				stick5[i]->act = false;
			}
			sticktime->cx = 2;
			sticktime->x = 0;
			point->cx = 1;
			point->x = 0;
			point->y = 0;
			maxpoint->x = 0;
			stick1[0]->cx = 0;
		}
	}

	if (GetAsyncKeyState(VK_RETURN) & 0x0001)
	{
		if (stagemenu->y == 11)
		{
			if (set->cx == 1)
			{
				state = STAGE;
				sndPlaySoundA(MILLION, SND_ASYNC);
				stagemenu->y = 11;
				for (int i = 0; i < StickNum; i++)
				{
					stick1[i]->act = false;
					stick2[i]->act = false;
					stick3[i]->act = false;
					stick4[i]->act = false;
					stick5[i]->act = false;
				}
				sticktime->cx = 2;
				sticktime->x = 0;
				point->cx = 1;
				point->x = 0;
				point->y = 0;
				maxpoint->x = 0;
				stick1[0]->cx = 0;
			}
			if (set->cx == 2)
			{
				state = STAGE2;
				sndPlaySoundA(TT, SND_ASYNC);
				stagemenu->y = 11;
				for (int i = 0; i < StickNum; i++)
				{
					stick1[i]->act = false;
					stick2[i]->act = false;
					stick3[i]->act = false;
					stick4[i]->act = false;
					stick5[i]->act = false;
				}
				sticktime->cx = 2;
				sticktime->x = 0;
				point->cx = 1;
				point->x = 0;
				point->y = 0;
				maxpoint->x = 0;
				stick1[0]->cx = 0;
			}
		}
		if (stagemenu->y == 13)
		{
			state = MENU;
			sndPlaySoundA(NULL, SND_FILENAME);
			stagemenu->y = 11;
			arrowhead->y = 26;
			for (int i = 0; i < StickNum; i++)
			{
				stick1[i]->act = false;
				stick2[i]->act = false;
				stick3[i]->act = false;
				stick4[i]->act = false;
				stick5[i]->act = false;
			}
			sticktime->cx = 2;
			sticktime->x = 0;
			point->cx = 1;
			point->x = 0;
			point->y = 0;
			maxpoint->x = 0;
			stick1[0]->cx = 0;
		}
		if (stagemenu->y == 15)
		{
			state = SET2;
			stagemenu->y = 11;
		}
		if (stagemenu->y == 17)
		{
			value = 0;
		}
	}

	if (GetAsyncKeyState(VK_UP) & 0x0001)
	{
		stagemenu->y -= 2;
		if (stagemenu->y < 11)
		{
			stagemenu->y += 2;
		}
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x0001)
	{
		stagemenu->y += 2;
		if (stagemenu->y > 17)
		{
			stagemenu->y -= 2;
		}
	}
}

void StageMenuRender()
{
	for (int y = 0; y < BufferHeight - 1; y++)
	{
		for (int x = 0; x < BufferWidth; x += 2)
		{
			if (x == 0)
			{
				WriteBuffer(0, y, "ㅁ", 노란색);
			}
			if (y == 0)
			{
				WriteBuffer(x, 0, "ㅁ", 노란색);
			}
			if (y == BufferHeight - 2)
			{
				WriteBuffer(x, BufferHeight - 2, "ㅁ", 노란색);
			}
			if (x == BufferWidth - 2)
			{
				WriteBuffer(BufferWidth - 2, y, "ㅁ", 노란색);
			}
		}
	}

	WriteBuffer(14, 36, "SPACE.", 초록색);
	WriteBuffer(28, 36, "←", 초록색);
	WriteBuffer(40, 36, "↑", 초록색);
	WriteBuffer(52, 36, "↓", 초록색);
	WriteBuffer(64, 36, "→", 초록색);

	for (int i = 0; i < WayNum; i++)
	{
		WriteBuffer(way[i]->x, way[i]->y, way[i]->shape, 빨간색);
	}

	//HP Bar
	for (int i = 0; i < Hpbar; i++)
	{
		if (point->x >= (-2)*i)
		{
			WriteBuffer(hpbar[i]->x, hpbar[i]->y, hpbar[i]->shape, 연한파란색);
		}
		WriteBuffer(hpbar[i]->x - 2, hpbar[i]->y, "Ι", 연한파란색);
		WriteBuffer(hpbar[i]->x + 2, hpbar[i]->y, "Ι", 연한파란색);
	}

	//Special Bar
	for (int i = 0; i < Hpbar; i++)
	{
		if (point->y >= 3 * i + 1)
		{
			WriteBuffer(specialbar[i]->x, specialbar[i]->y, specialbar[i]->shape, 연한빨간색);
		}
		WriteBuffer(specialbar[i]->x - 2, specialbar[i]->y, "Ι", 연한빨간색);
		WriteBuffer(specialbar[i]->x + 2, specialbar[i]->y, "Ι", 연한빨간색);
	}

	if (point->y >= 59)
	{
		WriteBuffer(2, 23, "ENTER", 192);
	}
	if (point->y < 59)
	{
		WriteBuffer(2, 23, "      ", 0);
	}

	WriteBuffer(73, 36, "ESC", 회색);
	WriteBuffer(70, 37, "다시하기", 회색);

	//3
	for (int i = 0; i < StickNum; i++)
	{
		if (stick3[i]->act == true)
		{
			if (point->y < 0)
			{
				WriteBuffer(stick3[i]->x, stick3[i]->y, point->shape, 진한노란색);
			}
			if (point->y >= 0)
			{
				WriteBuffer(stick3[i]->x, stick3[i]->y, stick3[i]->shape, 자주색);
			}
		}
	}

	//1
	for (int i = 0; i < StickNum; i++)
	{
		if (stick1[i]->act == true)
		{
			if (point->y < 0)
			{
				WriteBuffer(stick1[i]->x, stick1[i]->y, point->shape, 진한노란색);
			}
			if (point->y >= 0)
			{
				WriteBuffer(stick1[i]->x, stick1[i]->y, stick1[i]->shape, 자주색);
			}
		}
	}

	//2
	for (int i = 0; i < StickNum; i++)
	{
		if (stick2[i]->act == true)
		{
			if (point->y < 0)
			{
				WriteBuffer(stick2[i]->x, stick2[i]->y, point->shape, 진한노란색);
			}
			if (point->y >= 0)
			{
				WriteBuffer(stick2[i]->x, stick2[i]->y, stick2[i]->shape, 자주색);
			}
		}
	}

	//4
	for (int i = 0; i < StickNum; i++)
	{
		if (stick4[i]->act == true)
		{
			if (point->y < 0)
			{
				WriteBuffer(stick4[i]->x, stick4[i]->y, point->shape, 진한노란색);
			}
			if (point->y >= 0)
			{
				WriteBuffer(stick4[i]->x, stick4[i]->y, stick4[i]->shape, 자주색);
			}
		}
	}

	//5
	for (int i = 0; i < StickNum; i++)
	{
		if (stick5[i]->act == true)
		{
			if (point->y < 0)
			{
				WriteBuffer(stick5[i]->x, stick5[i]->y, point->shape, 진한노란색);
			}
			if (point->y >= 0)
			{
				WriteBuffer(stick5[i]->x, stick5[i]->y, stick5[i]->shape, 자주색);
			}
		}
	}

	for (int i = 0; i < 12; i++)
	{
		WriteBuffer(30, 10 + i, "│", 흰색);
		WriteBuffer(50, 10 + i, "│", 흰색);
	}

	for (int i = 0; i < 20; i += 2)
	{
		WriteBuffer(30 + i, 9, "─", 흰색);
		WriteBuffer(30 + i, 21, "─", 흰색);
	}

	WriteBuffer(30, 9, "┌", 흰색);
	WriteBuffer(50, 9, "┐", 흰색);
	WriteBuffer(30, 21, "└", 흰색);
	WriteBuffer(50, 21, "┘", 흰색);

	WriteBuffer(35, 11, "다시하기", 흰색);
	WriteBuffer(35, 13, "메뉴로 돌아가기", 흰색);
	WriteBuffer(35, 15, "설정", 흰색);
	WriteBuffer(35, 17, "종료하기", 흰색);
	WriteBuffer(stagemenu->x, stagemenu->y, stagemenu->shape, 연한옥색);
}

void SetInit()
{
	set = (Set*)malloc(sizeof(Set));
	set->x = 12;
	set->y = 10;
	set->shape = "▶";
	set->cx = 1; //모드

	set2 = (Set2*)malloc(sizeof(Set2));
	set2->x = 0; //속도
	set2->y = 1; //속도(저장)
}

void SetProgress()
{
	if (GetAsyncKeyState(VK_ESCAPE) & 0x0001)
	{
		state = MENU;
		set->y = 10;
	}

	if (set->y == 10)
	{
		if (GetAsyncKeyState(VK_LEFT) & 0x0001)
		{
			set2->y--;
			if (set2->y < 1)
			{
				set2->y++;
			}
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x0001)
		{
			set2->y++;
			if (set2->y > 3)
			{
				set2->y--;
			}
		}
	}

	if (set->y == 15)
	{
		if (GetAsyncKeyState(VK_LEFT) & 0x0001)
		{
			set->cx = 1;
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x0001)
		{
			set->cx = 2;
		}
	}

	if (GetAsyncKeyState(VK_UP) & 0x0001)
	{
		set->y = 10;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x0001)
	{
		set->y = 15;
	}
}

void SetRender()
{
	WriteBuffer(13, 7, "※ 설정 ※", 연한자주색);
	WriteBuffer(16, 10, "속도", 흰색);
	WriteBuffer(12, 12, "▶   X", 흰색);
	WriteBuffer(22, 12, "◀", 흰색);
	_itoa_s(set2->y, sNum9, 10);
	WriteBuffer(18, 12, sNum9, 흰색);
	WriteBuffer(16, 15, "모드", 흰색);
	WriteBuffer(12, 17, "▶", 흰색);
	WriteBuffer(22, 17, "◀", 흰색);
	if (set->cx == 1)
	{
		WriteBuffer(14, 17, "밀리니언", 흰색);
	}
	if (set->cx == 2)
	{
		WriteBuffer(14, 17, "  티티", 흰색);
	}
	WriteBuffer(set->x, set->y, set->shape, 연한옥색);
	WriteBuffer(23, 23, "ESC : 뒤로가기", 흰색);
}

void SetProgress2()
{
	if (GetAsyncKeyState(VK_ESCAPE) & 0x0001)
	{
		state = STAGEMENU;
		set->y = 10;
	}

	if (set->y == 10)
	{
		if (GetAsyncKeyState(VK_LEFT) & 0x0001)
		{
			set2->y--;
			if (set2->y < 1)
			{
				set2->y++;
			}
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x0001)
		{
			set2->y++;
			if (set2->y > 3)
			{
				set2->y--;
			}
		}
	}

	if (set->y == 15)
	{
		if (GetAsyncKeyState(VK_LEFT) & 0x0001)
		{
			set->cx = 1;
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x0001)
		{
			set->cx = 2;
		}
	}

	if (GetAsyncKeyState(VK_UP) & 0x0001)
	{
		set->y = 10;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x0001)
	{
		set->y = 15;
	}
}

void SetRender2()
{
	for (int y = 0; y < BufferHeight - 1; y++)
	{
		for (int x = 0; x < BufferWidth; x += 2)
		{
			if (x == 0)
			{
				WriteBuffer(0, y, "ㅁ", 노란색);
			}
			if (y == 0)
			{
				WriteBuffer(x, 0, "ㅁ", 노란색);
			}
			if (y == BufferHeight - 2)
			{
				WriteBuffer(x, BufferHeight - 2, "ㅁ", 노란색);
			}
			if (x == BufferWidth - 2)
			{
				WriteBuffer(BufferWidth - 2, y, "ㅁ", 노란색);
			}
		}
	}

	WriteBuffer(14, 36, "SPACE.", 초록색);
	WriteBuffer(28, 36, "←", 초록색);
	WriteBuffer(40, 36, "↑", 초록색);
	WriteBuffer(52, 36, "↓", 초록색);
	WriteBuffer(64, 36, "→", 초록색);

	for (int i = 0; i < WayNum; i++)
	{
		WriteBuffer(way[i]->x, way[i]->y, way[i]->shape, 빨간색);
	}

	//HP Bar
	for (int i = 0; i < Hpbar; i++)
	{
		if (point->x >= (-2)*i)
		{
			WriteBuffer(hpbar[i]->x, hpbar[i]->y, hpbar[i]->shape, 연한파란색);
		}
		WriteBuffer(hpbar[i]->x - 2, hpbar[i]->y, "Ι", 연한파란색);
		WriteBuffer(hpbar[i]->x + 2, hpbar[i]->y, "Ι", 연한파란색);
	}

	//Special Bar
	for (int i = 0; i < Hpbar; i++)
	{
		if (point->y >= 3 * i + 1)
		{
			WriteBuffer(specialbar[i]->x, specialbar[i]->y, specialbar[i]->shape, 연한빨간색);
		}
		WriteBuffer(specialbar[i]->x - 2, specialbar[i]->y, "Ι", 연한빨간색);
		WriteBuffer(specialbar[i]->x + 2, specialbar[i]->y, "Ι", 연한빨간색);
	}

	if (point->y >= 59)
	{
		WriteBuffer(2, 23, "ENTER", 192);
	}
	if (point->y < 59)
	{
		WriteBuffer(2, 23, "      ", 0);
	}

	WriteBuffer(73, 36, "ESC", 회색);
	WriteBuffer(70, 37, "뒤로가기", 회색);

	//3
	for (int i = 0; i < StickNum; i++)
	{
		if (stick3[i]->act == true)
		{
			if (point->y < 0)
			{
				WriteBuffer(stick3[i]->x, stick3[i]->y, point->shape, 진한노란색);
			}
			if (point->y >= 0)
			{
				WriteBuffer(stick3[i]->x, stick3[i]->y, stick3[i]->shape, 자주색);
			}
		}
	}

	//1
	for (int i = 0; i < StickNum; i++)
	{
		if (stick1[i]->act == true)
		{
			if (point->y < 0)
			{
				WriteBuffer(stick1[i]->x, stick1[i]->y, point->shape, 진한노란색);
			}
			if (point->y >= 0)
			{
				WriteBuffer(stick1[i]->x, stick1[i]->y, stick1[i]->shape, 자주색);
			}
		}
	}

	//2
	for (int i = 0; i < StickNum; i++)
	{
		if (stick2[i]->act == true)
		{
			if (point->y < 0)
			{
				WriteBuffer(stick2[i]->x, stick2[i]->y, point->shape, 진한노란색);
			}
			if (point->y >= 0)
			{
				WriteBuffer(stick2[i]->x, stick2[i]->y, stick2[i]->shape, 자주색);
			}
		}
	}

	//4
	for (int i = 0; i < StickNum; i++)
	{
		if (stick4[i]->act == true)
		{
			if (point->y < 0)
			{
				WriteBuffer(stick4[i]->x, stick4[i]->y, point->shape, 진한노란색);
			}
			if (point->y >= 0)
			{
				WriteBuffer(stick4[i]->x, stick4[i]->y, stick4[i]->shape, 자주색);
			}
		}
	}

	//5
	for (int i = 0; i < StickNum; i++)
	{
		if (stick5[i]->act == true)
		{
			if (point->y < 0)
			{
				WriteBuffer(stick5[i]->x, stick5[i]->y, point->shape, 진한노란색);
			}
			if (point->y >= 0)
			{
				WriteBuffer(stick5[i]->x, stick5[i]->y, stick5[i]->shape, 자주색);
			}
		}
	}

	for (int i = 0; i < 12; i++)
	{
		WriteBuffer(30, 10 + i, "│", 흰색);
		WriteBuffer(50, 10 + i, "│", 흰색);
	}

	for (int i = 0; i < 20; i += 2)
	{
		WriteBuffer(30 + i, 9, "─", 흰색);
		WriteBuffer(30 + i, 21, "─", 흰색);
	}

	WriteBuffer(30, 9, "┌", 흰색);
	WriteBuffer(50, 9, "┐", 흰색);
	WriteBuffer(30, 21, "└", 흰색);
	WriteBuffer(50, 21, "┘", 흰색);
	WriteBuffer(39, 11, "속도", 흰색);
	WriteBuffer(35, 13, "▶   X", 흰색);
	WriteBuffer(45, 13, "◀", 흰색);
	_itoa_s(set2->y, sNum9, 10);
	WriteBuffer(41, 13, sNum9, 흰색);

	WriteBuffer(39, 16, "모드", 흰색);
	WriteBuffer(35, 18, "▶", 흰색);
	WriteBuffer(45, 18, "◀", 흰색);
	if (set->cx == 1)
	{
		WriteBuffer(37, 18, "밀리니언", 흰색);
	}
	if (set->cx == 2)
	{
		WriteBuffer(37, 18, "  티티", 흰색);
	}
	WriteBuffer(set->x + 23, set->y + 1, set->shape, 연한옥색);
}

void ExitInit()
{
	maxpoint = (Maxpoint*)malloc(sizeof(Maxpoint));
	maxpoint->cx = 0; //최고점수(트와이스)
	maxpoint->x = 0; //최대콤보점수
	maxpoint->y = 1; //exitssinnum
}

void ExitProgress()
{
	sticktime->y = maxpoint->x * 9;



	if (set->cx == 1)
	{
		if (set2->y == 1)
		{
			if (stick1[0]->cx + sticktime->x + sticktime->y > maxpoint->cx)
			{
				maxpoint->cx = stick1[0]->cx + sticktime->x + sticktime->y;
			}
		}
		if (set2->y == 2)
		{
			if ((stick1[0]->cx / 2) + sticktime->x + sticktime->y > maxpoint->cx)
			{
				maxpoint->cx = (stick1[0]->cx / 2) + sticktime->x + sticktime->y;
			}
		}
		if (set2->y == 3)
		{
			if ((stick1[0]->cx / 3) + sticktime->x + sticktime->y > maxpoint->cx)
			{
				maxpoint->cx = (stick1[0]->cx / 3) + sticktime->x + sticktime->y;
			}
		}
	}

	if (set->cx == 2)
	{
		if (set2->y == 1)
		{
			if (stick1[0]->cx + sticktime->x + sticktime->y > stick1[3]->cx)
			{
				stick1[3]->cx = stick1[0]->cx + sticktime->x + sticktime->y;
			}
		}
		if (set2->y == 2)
		{
			if ((stick1[0]->cx / 2) + sticktime->x + sticktime->y > stick1[3]->cx)
			{
				stick1[3]->cx = (stick1[0]->cx / 2) + sticktime->x + sticktime->y;
			}
		}
		if (set2->y == 3)
		{
			if ((stick1[0]->cx / 3) + sticktime->x + sticktime->y > stick1[3]->cx)
			{
				stick1[3]->cx = (stick1[0]->cx / 3) + sticktime->x + sticktime->y;
			}
		}
	}

	if (GetAsyncKeyState(VK_DOWN) & 0x0001)
	{
		arrowhead->y += 2;
	}
	if (GetAsyncKeyState(VK_UP) & 0x0001)
	{
		arrowhead->y -= 2;
	}
	if (arrowhead->y < 27)
	{
		arrowhead->y = 27;
	}
	if (arrowhead->y > 31)
	{
		arrowhead->y = 31;
	}

	if (GetAsyncKeyState(VK_RETURN) & 0x0001)
	{
		if (arrowhead->y == 27)
		{
			if (set->cx == 1)
			{
				state = STAGE;
				sndPlaySoundA(MILLION, SND_ASYNC);
			}
			if (set->cx == 2)
			{
				state = STAGE2;
				sndPlaySoundA(TT, SND_ASYNC);
			}
		}
		if (arrowhead->y == 29)
		{
			arrowhead->y = 26;
			state = MENU;
		}
		if (arrowhead->y == 31)
		{
			value = 0;
		}

		for (int i = 0; i < StickNum; i++)
		{
			stick1[i]->act = false;
			stick2[i]->act = false;
			stick3[i]->act = false;
			stick4[i]->act = false;
			stick5[i]->act = false;
		}
		sticktime->cx = 2;
		sticktime->x = 0;
		point->cx = 1;
		point->x = 0;
		point->y = 0;
		maxpoint->x = 0;
		stick1[0]->cx = 0;
	}

	switch (maxpoint->y)
	{
	case 1:
		ExitImg1();
		maxpoint->y++;
		break;
	case 2:
		ExitImg2();
		maxpoint->y++;
		break;
	case 3:
		ExitImg1();
		maxpoint->y++;
		break;
	case 4:
		ExitImg3();
		maxpoint->y = 1;
		break;
	}

	set2->x = 0;

	if (set->cx == 1)
	{
		if (set2->y == 1)
		{
			if (stick1[0]->cx + sticktime->x + sticktime->y >= 16000)
			{
				ExitImg4();
			}
			else if (stick1[0]->cx + sticktime->x + sticktime->y >= 14000)
			{
				ExitImg5();
			}
			else if (stick1[0]->cx + sticktime->x + sticktime->y >= 11000)
			{
				ExitImg6();
			}
			else if (stick1[0]->cx + sticktime->x + sticktime->y < 11000)
			{
				if (point->x <= -40)
				{
					ExitImg8();
				}
				else
				{
					ExitImg7();
				}
			}
		}
		if (set2->y == 2)
		{
			if ((stick1[0]->cx) / 2 + sticktime->x + sticktime->y >= 16000)
			{
				ExitImg4();
			}
			else if ((stick1[0]->cx) / 2 + sticktime->x + sticktime->y >= 14000)
			{
				ExitImg5();
			}
			else if ((stick1[0]->cx) / 2 + sticktime->x + sticktime->y >= 11000)
			{
				ExitImg6();
			}
			else if ((stick1[0]->cx) / 2 + sticktime->x + sticktime->y < 11000)
			{
				if (point->x <= -40)
				{
					ExitImg8();
				}
				else
				{
					ExitImg7();
				}
			}
		}
		if (set2->y == 3)
		{
			if ((stick1[0]->cx) / 3 + sticktime->x + sticktime->y >= 16000)
			{
				ExitImg4();
			}
			else if ((stick1[0]->cx) / 3 + sticktime->x + sticktime->y >= 14000)
			{
				ExitImg5();
			}
			else if ((stick1[0]->cx) / 3 + sticktime->x + sticktime->y >= 11000)
			{
				ExitImg6();
			}
			else if ((stick1[0]->cx) / 3 + sticktime->x + sticktime->y < 11000)
			{
				if (point->x <= -40)
				{
					ExitImg8();
				}
				else
				{
					ExitImg7();
				}
			}
		}
	}

	if (set->cx == 2)
	{
		if (set2->y == 1)
		{
			if (stick1[0]->cx + sticktime->x + sticktime->y >= 23000)
			{
				ExitImg4();
			}
			else if (stick1[0]->cx + sticktime->x + sticktime->y >= 21000)
			{
				ExitImg5();
			}
			else if (stick1[0]->cx + sticktime->x + sticktime->y >= 17000)
			{
				ExitImg6();
			}
			else if (stick1[0]->cx + sticktime->x + sticktime->y < 17000)
			{
				if (point->x <= -40)
				{
					ExitImg8();
				}
				else
				{
					ExitImg7();
				}
			}
		}
		if (set2->y == 2)
		{
			if ((stick1[0]->cx) / 2 + sticktime->x + sticktime->y >= 23000)
			{
				ExitImg4();
			}
			else if ((stick1[0]->cx) / 2 + sticktime->x + sticktime->y >= 21000)
			{
				ExitImg5();
			}
			else if ((stick1[0]->cx) / 2 + sticktime->x + sticktime->y >= 17000)
			{
				ExitImg6();
			}
			else if ((stick1[0]->cx) / 2 + sticktime->x + sticktime->y < 17000)
			{
				if (point->x <= -40)
				{
					ExitImg8();
				}
				else
				{
					ExitImg7();
				}
			}
		}
		if (set2->y == 3)
		{
			if ((stick1[0]->cx) / 3 + sticktime->x + sticktime->y >= 23000)
			{
				ExitImg4();
			}
			else if ((stick1[0]->cx) / 3 + sticktime->x + sticktime->y >= 21000)
			{
				ExitImg5();
			}
			else if ((stick1[0]->cx) / 3 + sticktime->x + sticktime->y >= 17000)
			{
				ExitImg6();
			}
			else if ((stick1[0]->cx) / 3 + sticktime->x + sticktime->y < 17000)
			{
				if (point->x <= -40)
				{
					ExitImg8();
				}
				else
				{
					ExitImg7();
				}
			}
		}
	}
}

void ExitRender()
{

	for (int i = 0; i < 15; i++)
	{
		WriteBuffer(3, 3 + i, "Ι", 연한파란색);
		WriteBuffer(36, 3 + i, "Ι", 연한파란색);
	}
	for (int i = 0; i < 17; i++)
	{
		WriteBuffer(4 + 2 * i, 2, "_ ", 연한파란색);
		WriteBuffer(4 + 2 * i, 18, "- ", 연한파란색);
	}

	for (int i = 0; i < 12; i++)
	{
		WriteBuffer(3, 22 + i, exitimg[i], 초록색);
	}

	for (int i = 0; i < 9; i++)
	{
		WriteBuffer(11, 6 + i, exitimg2[i], 진한노란색);
	}

	WriteBuffer(2, 23, "      ", 0);
	if (set2->y == 1)
	{
		_itoa_s(sticktime->x + stick1[0]->cx, sNum, 10);
	}
	if (set2->y == 2)
	{
		_itoa_s(sticktime->x + (stick1[0]->cx / 2), sNum, 10);
	}
	if (set2->y == 3)
	{
		_itoa_s(sticktime->x + (stick1[0]->cx / 3), sNum, 10);
	}
	if (set->cx == 1)
	{
		_itoa_s(maxpoint->cx, sNum5, 10);
	}
	if (set->cx == 2)
	{
		_itoa_s(stick1[3]->cx, sNum5, 10);
	}
	_itoa_s(maxpoint->x, sNum6, 10);
	_itoa_s(sticktime->y, sNum7, 10);
	if (set2->y == 1)
	{
		_itoa_s(stick1[0]->cx + sticktime->x + sticktime->y, sNum8, 10);
	}
	if (set2->y == 2)
	{
		_itoa_s((stick1[0]->cx / 2) + sticktime->x + sticktime->y, sNum8, 10);
	}
	if (set2->y == 3)
	{
		_itoa_s((stick1[0]->cx / 3) + sticktime->x + sticktime->y, sNum8, 10);
	}
	WriteBuffer(47, 4, "점수 :", 흰색);
	WriteBuffer(54, 4, sNum, 흰색);
	WriteBuffer(47, 7, "최대콤보 :", 흰색);
	WriteBuffer(58, 7, sNum6, 흰색);
	WriteBuffer(47, 10, "보너스점수 :", 흰색);
	WriteBuffer(60, 10, sNum7, 흰색);
	WriteBuffer(47, 13, "총점수 :", 흰색);
	WriteBuffer(56, 13, sNum8, 흰색);
	WriteBuffer(47, 16, "최고점수 :", 흰색);
	WriteBuffer(58, 16, sNum5, 흰색);

	WriteBuffer(arrowhead->x - 10, arrowhead->y, arrowhead->shape, 연한자주색);
	WriteBuffer(50, 27, "다시하기", 흰색);
	WriteBuffer(50, 29, "메뉴로 돌아가기", 흰색);
	WriteBuffer(50, 31, "종료하기", 흰색);
}

bool stickcoolication1(Obj* stick1, Obj* way)
{
	if (stick1->x == way->x + 2 && stick1->y <= way->y + 1 && stick1->y >= way->y - 1)
	{
		return true;
	}
	return false;
}

bool stickcoolication2(Obj* stick2, Obj* way)
{
	if (stick2->x == way->x + 2 && stick2->y <= way->y + 1 && stick2->y >= way->y - 1)
	{
		return true;
	}
	return false;
}

bool stickcoolication3(Obj* stick3, Obj* way)
{
	if (stick3->x == way->x + 2 && stick3->y <= way->y + 1 && stick3->y >= way->y - 1)
	{
		return true;
	}
	return false;
}

bool stickcoolication4(Obj* stick4, Obj* way)
{
	if (stick4->x == way->x + 2 && stick4->y <= way->y + 1 && stick4->y >= way->y - 1)
	{
		return true;
	}
	return false;
}

bool stickcoolication5(Obj* stick5, Obj* way)
{
	if (stick5->x == way->x + 2 && stick5->y <= way->y + 1 && stick5->y >= way->y - 1)
	{
		return true;
	}
	return false;
}

void LogoImg1()
{
	logoimg[0] = "                         ###";
	logoimg[1] = "              ###      ##  ##";
	logoimg[2] = "              ## ##  ##    ##";
	logoimg[3] = "              ##   ##      ##";
	logoimg[4] = "              ## ##  ##    ##";
	logoimg[5] = "              ###      ##  ##";
	logoimg[6] = "                         ###";
	logoimg[7] = "          ";
	logoimg[8] = "          Microsoft Visual Studio";
}

void LogoImg2()
{
	logoimg[0] = "                ##############";
	logoimg[1] = "            ################ ";
	logoimg[2] = "          ###    ### ";
	logoimg[3] = "         ##      ###       ###  #";
	logoimg[4] = "         ###    ###  ####  ## ##  ";
	logoimg[5] = "          ###   ### ##  ##  ##";
	logoimg[6] = "                ###   ##   ##";
	logoimg[7] = "                 #####  #### ";
	logoimg[8] = "                T  E  I  C  E";
}

void LogoImg3()
{
	logoimg[0] = "please be careful when opening the bins as";
	logoimg[1] = "Great power always comes with great responsibility";
	logoimg[2] = "Life isn't always what one likes.";
	logoimg[3] = "True is immortality,false is gone.";
	logoimg[4] = "the content may fall out during the play.";
	logoimg[5] = "Created by Kim Seung Il Created date 2018.";
	logoimg[6] = "What does age have to do with love.";
	logoimg[7] = "the content may fall out during the play.";
	logoimg[8] = "Created by Kim Seung Il Created date 2018.";
}

void MenuImg1()
{
	menuimg1[0] = "                        #############               #####";
	menuimg1[1] = "              ###       ###                       ###   ###";
	menuimg1[2] = "              ###       ###                       ###   ###      ####";
	menuimg1[3] = "###########   ###       #############              #######    ####";
	menuimg1[4] = "        ###   ###                           ###################";
	menuimg1[5] = "        ###   ###   ###########################";
	menuimg1[6] = "###########   ###                              ############";
	menuimg1[7] = "###         ########     ###########       ######       ###";
	menuimg1[8] = "###       ### ###  ####  ###     ###    #####     #########     ####";
	menuimg1[9] = "#####   ####  ###     ######     ###  ###         ###         ####";
	menuimg1[10] = "   #######    ###        ##############           ##############";
}

void MenuImg2()
{
	menuimg2[0] = "         ##        ########       ######";
	menuimg2[1] = "#######  ##      ####   ####     ##    ##";
	menuimg2[2] = "##       ##     ###             ##      ##";
	menuimg2[3] = "#######  ####   ###      ###### ##      ##";
	menuimg2[4] = "##       ##     ###        ##   ##      ##";
	menuimg2[5] = "###########      ####   #####    ##    ##";
	menuimg2[6] = "         ##        ######  ##     ######";
}

void MenuImg3()
{
	menuimg3[0] = "                                       ######";
	menuimg3[1] = "                                      ##  ##";
	menuimg3[2] = "                                       ####";
	menuimg3[3] = "                                        ##";
	menuimg3[4] = "                                      # ## # #";
	menuimg3[5] = "                                     #  ##";
	menuimg3[6] = "   -------    # # # # # # # # # # # # # ### # #";
	menuimg3[7] = " ---------    ##   ##      ###     ##  #  #   ##";
	menuimg3[8] = "   -------     ####    ####       ##  #    #   ##";
	menuimg3[9] = "                                   ##        ##";
	menuimg3[10] = "                                     ########";
	menuimg3[11] = "";
}

void MenuImg4()
{
	menuimg3[0] = "";
	menuimg3[1] = "                                          ######";
	menuimg3[2] = "                                         ##  ##";
	menuimg3[3] = "                                          ####";
	menuimg3[4] = "                                           ##  #";
	menuimg3[5] = "                                         # ## #";
	menuimg3[6] = "                                        #  ##  ";
	menuimg3[7] = "      -------    # # # # # # # # # # # # # ### # #";
	menuimg3[8] = "    ---------    ##   ##      ###     ##  #  #   ##";
	menuimg3[9] = "      -------     ####    ####       ##  #    #   ##";
	menuimg3[10] = "                                      ##        ##";
	menuimg3[11] = "                                        ########";
}

void MenuImg5()
{
	menuimg3[0] = "                                          ######";
	menuimg3[1] = "                                         ##  ##";
	menuimg3[2] = "                                          ####";
	menuimg3[3] = "                                           ##  #";
	menuimg3[4] = "                                         # ## #";
	menuimg3[5] = "                                        #  ##  ";
	menuimg3[6] = "      -------    # # # # # # # # # # # # # ### # #";
	menuimg3[7] = "    ---------    ##   ##      ###     ##  #  #   ##";
	menuimg3[8] = "      -------     ####    ####       ##  #    #   ##";
	menuimg3[9] = "                                      ##        ##";
	menuimg3[10] = "                                        ########";
	menuimg3[11] = "";
}

void ExitImg1()
{
	exitimg[0] = "";
	exitimg[1] = "                                 ##";
	exitimg[2] = "     ##                          # #";
	exitimg[3] = "     # #          ###            #  #";
	exitimg[4] = "     #  #         #  ##          # #";
	exitimg[5] = "     # #          ###            #";
	exitimg[6] = "     #            #  ##      #####";
	exitimg[7] = " #####            #  #      ######";
	exitimg[8] = "######        ##### #        ####";
	exitimg[9] = " ####        ######";
	exitimg[10] = "              ####";
	exitimg[11] = "";
}

void ExitImg2()
{
	exitimg[0] = "                                 ##";
	exitimg[1] = "     ##                          # #";
	exitimg[2] = "     # #                         #  #";
	exitimg[3] = "     #  #                        # #";
	exitimg[4] = "     # #          ###            #";
	exitimg[5] = "     #            #  ##      #####";
	exitimg[6] = " #####            ###       ######";
	exitimg[7] = "######            #  ##      ####";
	exitimg[8] = " ####             #  #";
	exitimg[9] = "              ##### #";
	exitimg[10] = "             ######";
	exitimg[11] = "              ####";
}

void ExitImg3()
{
	exitimg[0] = "";
	exitimg[1] = "";
	exitimg[2] = "                  ###            ##";
	exitimg[3] = "     ##           #  ##          # #";
	exitimg[4] = "     # #          ###            #  #";
	exitimg[5] = "     #  #         #  ##          # #";
	exitimg[6] = "     # #          #  #           #";
	exitimg[7] = "     #        ##### #        #####";
	exitimg[8] = " #####       ######         ######";
	exitimg[9] = "######        ####           ####";
	exitimg[10] = " ####";
	exitimg[11] = "";
}

void ExitImg4()
{
	exitimg2[0] = "      #########";
	exitimg2[1] = "     ###     ###";
	exitimg2[2] = "    ###";
	exitimg2[3] = "     ###";
	exitimg2[4] = "      #########";
	exitimg2[5] = "             ###";
	exitimg2[6] = "              ###";
	exitimg2[7] = "    ###      ###";
	exitimg2[8] = "     ########## ";
}

void ExitImg5()
{
	exitimg2[0] = "        ####";
	exitimg2[1] = "       ######";
	exitimg2[2] = "      ###  ###";
	exitimg2[3] = "     ###    ###";
	exitimg2[4] = "    ############";
	exitimg2[5] = "   ###        ###";
	exitimg2[6] = "  ###          ###";
	exitimg2[7] = " ###            ###";
	exitimg2[8] = "###              ###";
}

void ExitImg6()
{
	exitimg2[0] = "    ###########";
	exitimg2[1] = "    ###      ###";
	exitimg2[2] = "    ###       ### ";
	exitimg2[3] = "    ###      ###";
	exitimg2[4] = "    ###########";
	exitimg2[5] = "    ###      ###";
	exitimg2[6] = "    ###       ###";
	exitimg2[7] = "    ###      ###";
	exitimg2[8] = "    ###########";
}

void ExitImg7()
{
	exitimg2[0] = "      ##########";
	exitimg2[1] = "    ###       ###";
	exitimg2[2] = "   ###          ##";
	exitimg2[3] = "  ###           ##";
	exitimg2[4] = "  ###";
	exitimg2[5] = "  ###";
	exitimg2[6] = "   ###         ##";
	exitimg2[7] = "    ###       ###";
	exitimg2[8] = "     ###########";
}

void ExitImg8()
{
	exitimg2[0] = "     ############";
	exitimg2[1] = "     ############";
	exitimg2[2] = "     ###";
	exitimg2[3] = "     ###########";
	exitimg2[4] = "     ###########";
	exitimg2[5] = "     ###";
	exitimg2[6] = "     ###";
	exitimg2[7] = "     ###";
	exitimg2[8] = "     ###";
}

void Num1()
{
	NumImg[0] = "  ######";
	NumImg[1] = "###  ###";
	NumImg[2] = "     ###";
	NumImg[3] = "     ###";
	NumImg[4] = "     ###";
	NumImg[5] = "     ###";
	NumImg[6] = "     ###";
	NumImg[7] = "     ###";
	NumImg[8] = "#############";
}

void Num2()
{
	NumImg[0] = "  ########";
	NumImg[1] = "###     ####";
	NumImg[2] = "         ###";
	NumImg[3] = "        ###";
	NumImg[4] = "       ###";
	NumImg[5] = "      ###";
	NumImg[6] = "    ###";
	NumImg[7] = "  ###";
	NumImg[8] = "#############";
}

void Num3()
{
	NumImg[0] = "  ########";
	NumImg[1] = "####     ###";
	NumImg[2] = "##        ###";
	NumImg[3] = "         ###";
	NumImg[4] = "      ####";
	NumImg[5] = "         ###";
	NumImg[6] = "##        ###";
	NumImg[7] = "####     ###";
	NumImg[8] = "  ########";

}

void Num4()
{
	NumImg[0] = "    ######";
	NumImg[1] = "   ### ###";
	NumImg[2] = "  ###  ###";
	NumImg[3] = " ###   ###";
	NumImg[4] = "###    ###";
	NumImg[5] = "###    ###";
	NumImg[6] = "##############";
	NumImg[7] = "       ###";
	NumImg[8] = "       ###";
}

void Num5()
{
	NumImg[0] = "#############";
	NumImg[1] = "###";
	NumImg[2] = "###";
	NumImg[3] = "### #######";
	NumImg[4] = "##        ###";
	NumImg[5] = "           ###";
	NumImg[6] = "           ###";
	NumImg[7] = "###       ###";
	NumImg[8] = "  #########";
}

void Num6()
{
	NumImg[0] = "   ########";
	NumImg[1] = " ###      ###";
	NumImg[2] = "###";
	NumImg[3] = "###";
	NumImg[4] = "###  ######";
	NumImg[5] = "####      ###";
	NumImg[6] = "###        ###";
	NumImg[7] = " ###      ###";
	NumImg[8] = "  #########";
}

void Num7()
{
	NumImg[0] = "##############";
	NumImg[1] = " ###       ###";
	NumImg[2] = " ###       ###";
	NumImg[3] = "           ###";
	NumImg[4] = "          ###";
	NumImg[5] = "          ###";
	NumImg[6] = "         ###";
	NumImg[7] = "         ###";
	NumImg[8] = "        ###";
}

void Num8()
{
	NumImg[0] = "   ########";
	NumImg[1] = " ###      ### ";
	NumImg[2] = "###        ###";
	NumImg[3] = " ###      ###";
	NumImg[4] = "   ########";
	NumImg[5] = " ###      ###";
	NumImg[6] = "###        ###";
	NumImg[7] = " ###      ###";
	NumImg[8] = "   ########";
}

void Num9()
{
	NumImg[0] = "   ########";
	NumImg[1] = " ###      ### ";
	NumImg[2] = "###        ###";
	NumImg[3] = " ###      ###";
	NumImg[4] = "   ########";
	NumImg[5] = "        ###";
	NumImg[6] = "       ### ";
	NumImg[7] = "      ###";
	NumImg[8] = "     ###";
}

void Num0()
{
	NumImg[0] = "    ######";
	NumImg[1] = "  ###    ###";
	NumImg[2] = " ###      ###";
	NumImg[3] = "###        ###";
	NumImg[4] = "###        ###";
	NumImg[5] = "###        ###";
	NumImg[6] = " ###      ###";
	NumImg[7] = "  ###    ###";
	NumImg[8] = "    ######";
}

void Num11()
{
	NumImg10[0] = "  ######";
	NumImg10[1] = "###  ###";
	NumImg10[2] = "     ###";
	NumImg10[3] = "     ###";
	NumImg10[4] = "     ###";
	NumImg10[5] = "     ###";
	NumImg10[6] = "     ###";
	NumImg10[7] = "     ###";
	NumImg10[8] = "#############";
}

void Num12()
{
	NumImg10[0] = "  ########";
	NumImg10[1] = "###     ####";
	NumImg10[2] = "         ###";
	NumImg10[3] = "        ###";
	NumImg10[4] = "       ###";
	NumImg10[5] = "      ###";
	NumImg10[6] = "    ###";
	NumImg10[7] = "  ###";
	NumImg10[8] = "#############";
}

void Num13()
{
	NumImg10[0] = "  ########";
	NumImg10[1] = "####     ###";
	NumImg10[2] = "##        ###";
	NumImg10[3] = "         ###";
	NumImg10[4] = "      ####";
	NumImg10[5] = "         ###";
	NumImg10[6] = "##        ###";
	NumImg10[7] = "####     ###";
	NumImg10[8] = "  ########";

}

void Num14()
{
	NumImg10[0] = "    ######";
	NumImg10[1] = "   ### ###";
	NumImg10[2] = "  ###  ###";
	NumImg10[3] = " ###   ###";
	NumImg10[4] = "###    ###";
	NumImg10[5] = "###    ###";
	NumImg10[6] = "##############";
	NumImg10[7] = "       ###";
	NumImg10[8] = "       ###";
}

void Num15()
{
	NumImg10[0] = "#############";
	NumImg10[1] = "###";
	NumImg10[2] = "###";
	NumImg10[3] = "### #######";
	NumImg10[4] = "##        ###";
	NumImg10[5] = "           ###";
	NumImg10[6] = "           ###";
	NumImg10[7] = "###       ###";
	NumImg10[8] = "  #########";
}

void Num16()
{
	NumImg10[0] = "   ########";
	NumImg10[1] = " ###      ###";
	NumImg10[2] = "###";
	NumImg10[3] = "###";
	NumImg10[4] = "###  ######";
	NumImg10[5] = "####      ###";
	NumImg10[6] = "###        ###";
	NumImg10[7] = " ###      ###";
	NumImg10[8] = "  #########";
}

void Num17()
{
	NumImg10[0] = "##############";
	NumImg10[1] = " ###       ###";
	NumImg10[2] = " ###       ###";
	NumImg10[3] = "           ###";
	NumImg10[4] = "          ###";
	NumImg10[5] = "          ###";
	NumImg10[6] = "         ###";
	NumImg10[7] = "         ###";
	NumImg10[8] = "        ###";
}

void Num18()
{
	NumImg10[0] = "   ########";
	NumImg10[1] = " ###      ### ";
	NumImg10[2] = "###        ###";
	NumImg10[3] = " ###      ###";
	NumImg10[4] = "   ########";
	NumImg10[5] = " ###      ###";
	NumImg10[6] = "###        ###";
	NumImg10[7] = " ###      ###";
	NumImg10[8] = "   ########";
}

void Num19()
{
	NumImg10[0] = "   ########";
	NumImg10[1] = " ###      ### ";
	NumImg10[2] = "###        ###";
	NumImg10[3] = " ###      ###";
	NumImg10[4] = "   ########";
	NumImg10[5] = "        ###";
	NumImg10[6] = "       ### ";
	NumImg10[7] = "      ###";
	NumImg10[8] = "     ###";
}

void Num10()
{
	NumImg10[0] = "    ######";
	NumImg10[1] = "  ###    ###";
	NumImg10[2] = " ###      ###";
	NumImg10[3] = "###        ###";
	NumImg10[4] = "###        ###";
	NumImg10[5] = "###        ###";
	NumImg10[6] = " ###      ###";
	NumImg10[7] = "  ###    ###";
	NumImg10[8] = "    ######";
}

void Num21()
{
	NumImg100[0] = "  ######";
	NumImg100[1] = "###  ###";
	NumImg100[2] = "     ###";
	NumImg100[3] = "     ###";
	NumImg100[4] = "     ###";
	NumImg100[5] = "     ###";
	NumImg100[6] = "     ###";
	NumImg100[7] = "     ###";
	NumImg100[8] = "#############";
}

void Num22()
{
	NumImg100[0] = "  ########";
	NumImg100[1] = "###     ####";
	NumImg100[2] = "         ###";
	NumImg100[3] = "        ###";
	NumImg100[4] = "       ###";
	NumImg100[5] = "      ###";
	NumImg100[6] = "    ###";
	NumImg100[7] = "  ###";
	NumImg100[8] = "#############";
}

void Num23()
{
	NumImg100[0] = "  ########";
	NumImg100[1] = "####     ###";
	NumImg100[2] = "##        ###";
	NumImg100[3] = "         ###";
	NumImg100[4] = "      ####";
	NumImg100[5] = "         ###";
	NumImg100[6] = "##        ###";
	NumImg100[7] = "####     ###";
	NumImg100[8] = "  ########";

}

void Num24()
{
	NumImg100[0] = "    ######";
	NumImg100[1] = "   ### ###";
	NumImg100[2] = "  ###  ###";
	NumImg100[3] = " ###   ###";
	NumImg100[4] = "###    ###";
	NumImg100[5] = "###    ###";
	NumImg100[6] = "##############";
	NumImg100[7] = "       ###";
	NumImg100[8] = "       ###";
}

void Num25()
{
	NumImg100[0] = "#############";
	NumImg100[1] = "###";
	NumImg100[2] = "###";
	NumImg100[3] = "### #######";
	NumImg100[4] = "##        ###";
	NumImg100[5] = "           ###";
	NumImg100[6] = "           ###";
	NumImg100[7] = "###       ###";
	NumImg100[8] = "  #########";
}

void Num26()
{
	NumImg100[0] = "   ########";
	NumImg100[1] = " ###      ###";
	NumImg100[2] = "###";
	NumImg100[3] = "###";
	NumImg100[4] = "###  ######";
	NumImg100[5] = "####      ###";
	NumImg100[6] = "###        ###";
	NumImg100[7] = " ###      ###";
	NumImg100[8] = "  #########";
}

void Num27()
{
	NumImg100[0] = "##############";
	NumImg100[1] = " ###       ###";
	NumImg100[2] = " ###       ###";
	NumImg100[3] = "           ###";
	NumImg100[4] = "          ###";
	NumImg100[5] = "          ###";
	NumImg100[6] = "         ###";
	NumImg100[7] = "         ###";
	NumImg100[8] = "        ###";
}

void Num28()
{
	NumImg100[0] = "   ########";
	NumImg100[1] = " ###      ### ";
	NumImg100[2] = "###        ###";
	NumImg100[3] = " ###      ###";
	NumImg100[4] = "   ########";
	NumImg100[5] = " ###      ###";
	NumImg100[6] = "###        ###";
	NumImg100[7] = " ###      ###";
	NumImg100[8] = "   ########";
}

void Num29()
{
	NumImg100[0] = "   ########";
	NumImg100[1] = " ###      ### ";
	NumImg100[2] = "###        ###";
	NumImg100[3] = " ###      ###";
	NumImg100[4] = "   ########";
	NumImg100[5] = "        ###";
	NumImg100[6] = "       ### ";
	NumImg100[7] = "      ###";
	NumImg100[8] = "     ###";
}

void Num20()
{

}

void FREE()
{
	for (int i = 0; i < StickNum; i++)
	{
		free(stick1[i]);
		free(stick2[i]);
		free(stick3[i]);
		free(stick4[i]);
		free(stick5[i]);
	}

	for (int i = 0; i < WayNum; i++)
	{
		free(way[i]);
	}

	for (int i = 0; i < Hpbar; i++)
	{
		free(hpbar[i]);
		free(specialbar[i]);
	}

	for (int i = 0; i < EffactNum; i++)
	{
		free(effect[i]);
		free(effect2[i]);
		free(effect3[i]);
		free(effect4[i]);
		free(effect5[i]);
	}

	free(point);
	free(sticktime);
	free(maxpoint);
	free(arrowhead);
	free(logotime);
	free(stagemenu);
	free(set);
	free(set2);
	free(sound);
	free(menu2);
}

void InitDoubleBuffer()
{
	COORD size = { BufferWidth,BufferHeight };
	CONSOLE_CURSOR_INFO info;
	SMALL_RECT rect;

	rect.Left = 0;
	rect.Right = BufferWidth - 1;
	rect.Top = 0;
	rect.Bottom = BufferHeight - 1;

	hBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(hBuffer[0], size);
	SetConsoleWindowInfo(hBuffer[0], TRUE, &rect);

	hBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(hBuffer[1], size);
	SetConsoleWindowInfo(hBuffer[1], TRUE, &rect);

	info.dwSize = 1;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(hBuffer[0], &info);
	SetConsoleCursorInfo(hBuffer[1], &info);

}

void WriteBuffer(int x, int y, const char * string, int color)
{
	DWORD dw;
	COORD pos;
	pos.X = x;
	pos.Y = y;

	SetConsoleCursorPosition(hBuffer[screenIndex], pos);
	SetConsoleTextAttribute(hBuffer[screenIndex], color);

	WriteFile(hBuffer[screenIndex], string, strlen(string), &dw, NULL);
}

void FlipBuffer()
{
	SetConsoleActiveScreenBuffer(hBuffer[screenIndex]);
	screenIndex = !screenIndex;
}

void ClearBuffer()
{
	DWORD dw;
	COORD coord = { 0,0 };
	FillConsoleOutputCharacter(hBuffer[screenIndex], ' ', BufferWidth * BufferHeight, coord, &dw);
}

void DestroyBuffer()
{
	CloseHandle(hBuffer[0]);
	CloseHandle(hBuffer[1]);
}