#include "all.h"
#include "volcano.h"
using namespace GameLib;
using namespace input;
VOLCANO volcano;
extern OBJ player;
void VOLCANO::init(float begin_posy, float fin_posx,float speed)
{
	set_state(0);
	this->speed.x = speed;
	pos = {1920,begin_posy};
	fin_pos = fin_posx;
	timer = 20;
}
VOLCANO obsidian;
void VOLCANO::update()
{
	int next = get_state() + 1;
	switch (get_state())
	{
	case 0:
		if (fin_pos <= pos.x) { pos.x -= speed.x; }
		else { timer--; }
		if (timer <= 0) { set_state(next); }
		break;
	case 1:
		if (pos.x < 2000) { pos.x += speed.x; }
		else { set_state(next); }
		break;
	}
}

void VOLCANO::draw()
{
	primitive::rect(pos.x, pos.y, 1920, 300, 0, 150, 0, 1, 0, 0, 0.6);
}

void volcano_update()
{
	if (TRG(0)&PAD_TRG3&&volcano.get_state() > 1) { volcano.init(player.pos.y, (player.pos.x - 50), 10); }
	volcano.update();
}
void volcano_draw()
{
 volcano.draw();
}

