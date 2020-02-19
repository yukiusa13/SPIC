#include "all.h"
using namespace GameLib;
using namespace input;
OBJ player;
VOLCANO volcano;

extern float world_pos;

namespace Pjump
{
 int state;
 float pos;
 float speed;
 void init(float pos);
 void update();
}

//èÛë‘ëJà⁄ópenumÉNÉâÉX
enum
{
	Wait=0,
	Move,
	Jump,
	Atk
};

void player_init()
{
	player.pos={1920/2,1080/2};
	world_pos = -300;
	Pjump::state = 0;
}

void Pjump::init(float pos)
{
	Pjump::state = 2;
	Pjump::pos = pos;
	Pjump::speed = 15;
}
void Pjump::update()
{
	switch (Pjump::state)
	{
	case 1:
		Pjump::init(player.pos.x);
		break;
	case 2:
		Pjump::speed -= 0.5;
		player.pos.x -= Pjump::speed;
		if (Pjump::speed <= 0)Pjump::state = 3;
		break;
	case 3:
		Pjump::speed -= 0.5;
		player.pos.x -= Pjump::speed;
		if (player.pos.x>=Pjump::pos)Pjump::state = 0;
		break;
	}

}

void player_update()
{
	
	switch (player.get_state())
	{
	case Wait:
		break;
	case Move:
		break;
	case Jump:
		break;
	case Atk:
		break;
	}
	volcano.update();
	if(LEFT)
	{
	//	if(world_pos<0)world_pos += 5;
		
		player.pos.y += 5;
	}
	if (RIGHT)
	{
		//if (world_pos > -scrollarea)world_pos -= 5;
		player.pos.y -= 5;
	}
#if (debug)
	if (TRG(0)&PAD_TRG1&&volcano.get_state()>1) { volcano.init(player.pos.y,(player.pos.x-50)); }
	//if (UP) { player.pos.x -= 5; }
	//if (DOWN) { player.pos.x += 5; }
	if (Pjump::state == 0 &&JUMP) { Pjump::state = 1; }
	Pjump::update();
#endif
	if (player.pos.x < 50) { player.pos.x = 50; }
	if (player.pos.x > 1820) { player.pos.x = 1820; }
	if (player.pos.y < 50) { player.pos.y = 50; }
	if (player.pos.y > 1030) { player.pos.y = 1030; }
#if(0)
	if (player.pos.x - 50 < area_left&&world_pos < -300) { player.pos.x = (area_left+50); world_pos += 5;}
	else if (player.pos.x - 50 < 0) { player.pos.x = (0 + 50);}
	if (player.pos.x + 50 > area_right&&world_pos >-(scrollarea-300)) { player.pos.x = (area_right - 50); world_pos -= 5;}
	else if (player.pos.x + 50 > 1920) { player.pos.x = (1920 - 50);}
#endif
	//debug::setString("world_pos:%f", world_pos);
}

void player_draw()
{
	switch (player.get_state())
	{
	case Wait:
		break;
	case Move:
		break;
	case Jump:
		break;
	case Atk:
		break;
	}
	//debug::display();
	volcano.draw();
	primitive::rect(player.pos, { 100,100 }, { 50,50 });
}
	