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
};
void spr_load()
{
	for (int i = 0; i < Spr_Max; i++)
	{
		sprite_load(&sprData[i], sprName[i]);
	}
}
void title_init()
{
	spr_load();
	sprite_load(&obj, L"./Data/Images/bg.png");
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
	/*	sprite_render(sprData[Bg],
			0, 0,
			1, 1,
			0, 0,
			SCREEN_WIDTH, SCREEN_HEIGHT);*/
		sprite_render(obj, 0, 0,
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
	SAFE_DELETE(obj);
}



