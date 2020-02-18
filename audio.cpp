#include "all.h"
using namespace GameLib;
//CAT:音楽読み込み
wchar_t* MusicName[] =
{
	L"./Data/Musics/bgm1.wav",
};

void audio_init()
{
	for (int i = 0; i < Music_Max; i++)
	{
		music::load(i, MusicName[i], 0.3f);
    }
	sound::load(L"./Data/Sounds/se.xwb");//SE
}
void audio_uninit()
{
	//音楽の解放処理
	int i;
	for (i = 0; i < Music_Max; i++)
		music::unload(i);
}

