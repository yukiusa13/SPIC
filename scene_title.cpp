#include "all.h"
using namespace GameLib;
using namespace input;
int title_state;      // 状態
int title_timer;      // タイマー
float fadeOut;        // フェイドアウト
extern int nextScene; //シーン移行用
//CAT:画像読み込み
Sprite* sprData[Spr_Max];
wchar_t* sprName[] =
{
	L"./Data/Images/bg.png",
	L"./Data/Images/number.png",
	L"./Data/Images/mapchip.png",
    L"./Data/Images/enemy.png",
	L"./Data/Images/stage.png",

};
void spr_load()
{
	for (int i = 0; i < Spr_Max; i++)
	{
		sprite_load(&sprData[i], sprName[i]);
	}
}
enum 
{
	stage1=0,
	stage2,
	stage3,
};
namespace stage
{
	const int max = 3;
	int state;
	int num[3];
	float scl;
	float pos[3];
	int vect;
	void set();
	void init(int next);
	void update(int next);
}
void stage::set()
{
	num[0] = num[1] - 1;
	if (num[0] < 0)num[0] = max - 1;
	num[2] = num[2] + 1;
	if (num[2] >= max)num[2] = 0;
}
void stage::init(int next)
{
	if (next > num[1])vect = 1;
	else vect = -1;
}
void stage::update(int next)
{
	switch (state)
	{
	case 1:
		init(next);
		break;
	case 2:
		break;
	case 3:
		for (int i = 0; i < 3; i++)
		{
			pos[i] += (vect * 10);
		}
		if (pos[1]);
		break;
	}
}
void title_init()
{
	spr_load();
	stage::num[1] = stage1;
    title_state = 0;
    title_timer = 0;

}

void title_update()
{
	static const int title_max=3;//タイトル場面の最大数
    switch (title_state)
    {
    case 0:
		music::play(0, true);
        title_state++;
        break;
    case 1:
        if (TRG(0) & PAD_START)
        {
            fadeOut=0.0f;
            title_state++;
        }
		if (TRG(0)&PAD_TRG1)sound::play(0);
        break;
    case 2:
        fadeOut += 0.0167f;
        if (fadeOut >= 1.0f)
        {  title_state++; }
        break;
    }
    if (title_state == title_max) 
    { nextScene = SCENE_GAME; }
    title_timer++;
   }

void title_draw()
{
	switch (title_state)
	{
	case 0:
	case 1:
		sprite_render(sprData[Bg],
			0, 0,
			1, 1,
			0, 0,
			SCREEN_WIDTH, SCREEN_HEIGHT);
		break;
	case 2:
		if (fadeOut > 0.0f)
		{
			primitive::rect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0, 0, 1- fadeOut, 1 - fadeOut, 1 - fadeOut, fadeOut);
		}
		break;
	}
}

void title_end()
{
	music::unload(0);
	for (int i = 0; i < Spr_Max; i++)
	{
		SAFE_DELETE(sprData[i]);
	}
}



