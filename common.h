#ifndef INCLUDED_COMMON
#define INCLUDED_COMMON

#define SAFE_DELETE(x)  if(x){delete x;x=NULL;}    
#define ToRadian(x)     DirectX::XMConvertToRadians(x) 
#define SCREEN_WIDTH    (1920)   // ��ʂ̕�
#define SCREEN_HEIGHT   (1080)   // ��ʂ̍���
#define SCENE_TITLE     (0)
#define SCENE_GAME      (1)

void spr_load();//�摜�ǂݍ��݊֐�

//// �X�v���C�g�p ////
enum 
{
	Bg = 0,
	Number,
	Spr_Max
};

#endif// ! INCLUDED_COMMON
