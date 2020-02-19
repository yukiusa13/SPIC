#include "all.h"

using namespace GameLib;
using namespace input;
extern int game_timer;
extern int game_state; 
extern Sprite* sprData[Spr_Max];

OBJ bg[2];
float world_pos;


void scroll()
{
	
}

void bg_init()
{


}

void bg_update()
{


}

void bg_draw()
{
	switch (game_state)
	{
	case 0:
	case 1:
		sprite_render(sprData[Bg], world_pos, 0, 1, 1, 0, SCREEN_HEIGHT*2,3840,1080);
		sprite_render(sprData[Bg], world_pos+3840, 0, 1, 1, 0, SCREEN_HEIGHT * 2, 3840, 1080);
		break;
	case 2:
		
		break;
	}
}


