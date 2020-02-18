#include "all.h"
using namespace GameLib;
//CAT:���y�ǂݍ���
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
	//���y�̉������
	int i;
	for (i = 0; i < Music_Max; i++)
		music::unload(i);
}

