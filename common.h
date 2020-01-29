#ifndef INCLUDED_COMMON
#define INCLUDED_COMMON

#define SAFE_DELETE(x)  if(x){delete x;x=NULL;}    
#define ToRadian(x)     DirectX::XMConvertToRadians(x) 
#define SCREEN_WIDTH    (1920)   // 画面の幅
#define SCREEN_HEIGHT   (1080)   // 画面の高さ
#define SCENE_TITLE     (0)
#define SCENE_GAME      (1)

void spr_load();//画像読み込み関数

//// スプライト用 ////
enum 
{
	Bg = 0,
	Number,
	Spr_Max
};

#endif// ! INCLUDED_COMMON
