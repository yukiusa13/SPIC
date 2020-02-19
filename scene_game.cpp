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
int play;
void game_init()
{
	spr_load();
	bg_init();
	player_init();
	game_state = 0;
    game_timer = 0;
	fadeOut = 0;
	play = 0;
}
void common()
{
	bg_update();
	player_update();
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
		 switch (play)
		 {
		 case 0:
			 if(TRG(0)&PAD_TRG2)
			 {
				 play = 1;
			 }
			 common();
			 if (TRG(0) & PAD_START)
			 {
				 fadeOut = 0.0f;
				 game_state++;
			 }
			 break;
		 case 1:
			 if (TRG(0)&PAD_TRG2)
			 {
				 play = 0;
			 }
			 break;
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
	player_draw();
	if(play)
	{
		primitive::rect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0, 0,0,0,0,0.5); 
		primitive::rect(1920 / 2, 1080 / 2, 500, 500, 250, 250);
	}
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



