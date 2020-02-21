#include "all.h"
using namespace GameLib;
using namespace input;
extern Sprite* sprData[Spr_Max];
OBJ enemy;
extern OBJ player;

namespace Ejump
{
    int state;
    float pos;
    float speed;
    void init(float pos);
    void update();
}

//状態遷移用enumクラス
enum
{
    eWait = 0,
    eMove,
    eJump
};

void Ejump::init(float pos)
{
    Ejump::state = 2;
    Ejump::pos = pos;
    Ejump::speed = 10;
}
void Ejump::update()
{
    switch (Ejump::state)
    {
    case 1:
        Ejump::init(enemy.pos.x);
        break;
    case 2:
        Ejump::speed -= 0.5;
        enemy.pos.x -= Ejump::speed;
        if (Ejump::speed <= 0)Ejump::state = 3;
        break;
    case 3:
        Ejump::speed -= 0.5;
        enemy.pos.x -= Ejump::speed;
        if (enemy.pos.x >= Ejump::pos)Ejump::state = 0;
        break;
    }

}

void enemy_init()
{
    enemy.pos = { 500,540 / 2 };
}

void enemy_update()
{
    switch (enemy.get_state())
    {
    case eWait:
        break;
    case eMove:
        break;
    case eJump:
        break;
    }

    //プレイヤーにただ近づく場合
    if (enemy.pos.y > player.pos.y) { enemy.pos.y -= 5; }
    if (enemy.pos.y < player.pos.y) { enemy.pos.y += 5; }

    //足場があるところだけで左右に動く場合

    if (Ejump::state == 0) { Ejump::state = 1; }
    Ejump::update();

    if (enemy.pos.x < 50) { enemy.pos.x = 50; }
    if (enemy.pos.x > 1820) { enemy.pos.x = 1820; }
    if (enemy.pos.y < 50) { enemy.pos.y = 50; }
    if (enemy.pos.y > 1030) { enemy.pos.y = 1030; }
}

void enemy_draw()
{
    switch (enemy.get_state())
    {
    case eWait:
        break;
    case eMove:
        break;
    case eJump:
        break;
    }
    sprite_render(sprData[Enemy], enemy.pos.x, enemy.pos.y, 1, 1, 0, 0, 64, 64);
}