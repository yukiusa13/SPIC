#include "all.h"
using namespace GameLib;
using namespace input;
extern Sprite* sprData[Spr_Max];
<<<<<<< HEAD
ENEMY enemy;
extern OBJ player;
extern int map[MAP_Y][MAP_X];
namespace Ejump
{
    bool isflg[2];
=======
OBJ enemy;
extern OBJ player;

namespace Ejump
{
>>>>>>> b67f318d7eaccf63255085195747a7064621b348
    int state;
    float pos;
    float speed;
    void init(float pos);
<<<<<<< HEAD
    bool get_flg();
=======
>>>>>>> b67f318d7eaccf63255085195747a7064621b348
    void update();
}

//��ԑJ�ڗpenum�N���X
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
<<<<<<< HEAD
bool Ejump::get_flg()
{
    if (isflg[0] || isflg[1]) { return true; }
    return false;
}
=======
>>>>>>> b67f318d7eaccf63255085195747a7064621b348
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
<<<<<<< HEAD
void ENEMY::init()
{
    enemy.pos = { 500,540 / 2 };
}
void ENEMY::update()
{
    Ejump::isflg[0] = false;
    Ejump::isflg[1] = false;
    if (Ejump::state == 0) { enemy.pos.x += 5; }
    for (int y = 0; y < MAP_Y; y++)
    {
        for (int x = 0; x < MAP_X; x++)
        {
#if 1
            if (Judge.rect(64 * y, 64 * (y + 1), 64 * x, 64 * (x + 1), enemy.pos.x + 32, enemy.pos.y + 32))
            {
                switch (map[y][x])
                {
                case 0:
                    Ejump::isflg[0] = false;
                    break;
                case 1:
                    Ejump::isflg[0] = true;
                    if (Ejump::state != 2)
                    {
                        enemy.pos.x = 64 * (x)-32;
                        if (Ejump::state == 3)
                        {
                            Ejump::state = 0;
                        }
                    }
                    break;
                }
            }
            if (Judge.rect(64 * y, 64 * (y + 1), 64 * x, 64 * (x + 1), enemy.pos.x + 32, enemy.pos.y - 32))
            {
                switch (map[y][x])
                {
                case 0:
                    Ejump::isflg[0] = false;
                    break;
                case 1:
                    Ejump::isflg[1] = true;
                    if (Ejump::state != 2)
                    {
                        enemy.pos.x = 64 * (x)-32;
                        if (Ejump::state == 3)
                        {
                            Ejump::state = 0;
                        }
                    }
                    break;
                }
            }
        }
    }
#endif
=======

void enemy_init()
{
    enemy.pos = { 500,540 / 2 };
}

void enemy_update()
{
>>>>>>> b67f318d7eaccf63255085195747a7064621b348
    switch (enemy.get_state())
    {
    case eWait:
        break;
    case eMove:
        break;
    case eJump:
        break;
    }

    //�v���C���[�ɂ����߂Â��ꍇ
    if (enemy.pos.y > player.pos.y) { enemy.pos.y -= 5; }
    if (enemy.pos.y < player.pos.y) { enemy.pos.y += 5; }

    //���ꂪ����Ƃ��낾���ō��E�ɓ����ꍇ

<<<<<<< HEAD
    if (Ejump::state == 0  && Ejump::get_flg()) { Ejump::state = 1; }
=======
    if (Ejump::state == 0) { Ejump::state = 1; }
>>>>>>> b67f318d7eaccf63255085195747a7064621b348
    Ejump::update();

    if (enemy.pos.x < 50) { enemy.pos.x = 50; }
    if (enemy.pos.x > 1820) { enemy.pos.x = 1820; }
    if (enemy.pos.y < 50) { enemy.pos.y = 50; }
    if (enemy.pos.y > 1030) { enemy.pos.y = 1030; }
}
<<<<<<< HEAD
    

void ENEMY::draw()
=======

void enemy_draw()
>>>>>>> b67f318d7eaccf63255085195747a7064621b348
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
<<<<<<< HEAD
    sprite_render(sprData[Enemy], enemy.pos.x, enemy.pos.y, 1, 1, 0, 0, 64, 64,32,32);
}

void enemy_init()
{
    enemy.init();
}

void enemy_update()
{
    enemy.update();
}
void enemy_draw()
{
    enemy.draw();
=======
    sprite_render(sprData[Enemy], enemy.pos.x, enemy.pos.y, 1, 1, 0, 0, 64, 64);
>>>>>>> b67f318d7eaccf63255085195747a7064621b348
}