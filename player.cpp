#include "all.h"
using namespace GameLib;
using namespace input;
OBJ player;
extern float screen_pos;
extern float world_pos;

void player_init()
{
	player.pos={1920/2,1080/2};
	world_pos= -100;
}

void player_update()
{
	
	if(STATE(0)&PAD_LEFT)
	{
		world_pos += 5;
		player.pos.x -= 5;
	}
	if (STATE(0)&PAD_RIGHT)
	{
		world_pos -= 5;
		player.pos.x += 5;
	}
	if (player.pos.x - 50 < area_left&&world_pos < 0) { player.pos.x = (area_left+50); }
	else if (player.pos.x - 50 < 0 && world_pos >= 0) { player.pos.x = (0 + 50); world_pos = 0; }
	if (player.pos.x + 50 > area_right&&world_pos >-1200) { player.pos.x = (area_right - 50); }
	else if (player.pos.x + 50 > 1920 && world_pos <= -1500) { player.pos.x = (1920 - 50); world_pos = -1500; }
	debug::setString("world_pos:%f", world_pos);
}

void player_draw()
{
	debug::display();
	primitive::rect(player.pos, { 100,100 }, { 50,50 });
}
	