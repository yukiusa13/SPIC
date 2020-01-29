#include "all.h"
using namespace GameLib;
using namespace input;
int game_state;    // ���
int game_timer;    // �^�C�}�[
int game_score;
extern int nextScene;
extern float fadeOut;
extern Sprite* sprData[Spr_Max];
extern wchar_t* sprName[];
void game_init()
{
	spr_load();
	sprite_load(&obj, L"./Data/Images/bg.png");
	bg_init();
    game_state = 0;
    game_timer = 0;
	fadeOut = 0;
}
void common()
{
	bg_updata();
}
void game_update()
{
	static const int game_max = 3;//�Q�[����ʂ̍ő吔
    switch (game_state)
    {
     case 0:
         game_state++;
         break;
     
     case 1:
		 common();
         if (TRG(0) & PAD_START)
         {
             fadeOut = 0.0f;
             game_state++;
         }
    break;
     
     case 2:
         fadeOut += 0.0167f;
         if (fadeOut >= 1.0f)
         {
             game_state++;
         }
         break;
    }
    if (game_state == game_max) 
    {
        nextScene = SCENE_TITLE;
    }
    game_timer++;
}

void game_draw()
{
    bg_draw();
    ui_draw(game_state, game_score);
	if (fadeOut > 0.0f)
	{
		primitive::rect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0, 0, 1-fadeOut, 1 - fadeOut, 1-fadeOut, fadeOut);
	}
}

void game_end()//�摜�̔j��
{
	for (int i = 0; i < Spr_Max; i++)
	{
		SAFE_DELETE(sprData[i]);
	}
}



