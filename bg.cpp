#include "all.h"

using namespace GameLib;
using namespace input;
extern int game_timer;
extern int game_state; 
extern Sprite* sprData[Spr_Max];


void bg_init()
{


}
void bg_updata()
{

}
void bg_draw()
{
	switch (game_state)
	{
	case 0:
	case 1:
		sprite_render(sprData[Bg], 0, 0, 1, 1, 0, SCREEN_HEIGHT);
		break;
	case 2:
		
		break;
	}
}
