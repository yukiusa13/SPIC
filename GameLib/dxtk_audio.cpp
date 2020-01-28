//******************************************************************************
//
//
//      DirectXTKAudio
//
//
//******************************************************************************

//------< �C���N���[�h >---------------------------------------------------------
#include "dxtk_audio.h"

namespace GameLib
{
    namespace audio
    {
        using DirectX::AUDIO_ENGINE_FLAGS;
        using DirectX::AudioEngine;
        using DirectX::SoundEffect;
        using DirectX::WaveBank;

        using DirectX::AudioEngine_Default;
        using DirectX::AudioEngine_Debug;

        //--------------------------------
        //  �R���X�g���N�^
        //--------------------------------
        DXTKAudio::DXTKAudio()
        {
            // Create DirectXTK for Audio objects
            AUDIO_ENGINE_FLAGS eflags = AudioEngine_Default;
#ifdef _DEBUG
            eflags = eflags | AudioEngine_Debug;
#endif
            audioEngine.reset(new AudioEngine(eflags));
            for (auto &p : musicVolume) p = 1.0f;
            for (auto &p : soundVolume) p = 1.0f;
        }

        //--------------------------------
        //  �f�X�g���N�^
        //--------------------------------
        DXTKAudio::~DXTKAudio()
        {
            audioEngine.reset();
        }

        //--------------------------------
        //  �I�[�f�B�I�G���W���̃��Z�b�g
        //--------------------------------
        bool DXTKAudio::reset()
        {
            return audioEngine->Reset();
        }

        //--------------------------------
        //  ���y�Ǎ�
        //--------------------------------
        void DXTKAudio::musicLoad(int trackNo, const wchar_t* waveFileName, float volume)
        {
            if (musicInst[trackNo]) musicInst[trackNo].reset();
            music[trackNo].reset(new SoundEffect(audioEngine.get(), waveFileName));
            musicVolume[trackNo] = volume;
        }

        //--------------------------------
        //  ���y���
        //--------------------------------
        void DXTKAudio::musicUnload(int trackNo)
        {
            if (musicInst[trackNo]) musicInst[trackNo].reset();
            music[trackNo].reset(nullptr);
        }

        //--------------------------------
        //  ���y�Đ�
        //--------------------------------
        void DXTKAudio::musicPlay(int trackNo, bool isLoop)
        {
            if (!music[trackNo]) return;
            musicInst[trackNo] = music[trackNo]->CreateInstance();
            musicInst[trackNo]->Play(isLoop);
            musicInst[trackNo]->SetVolume(musicVolume[trackNo]);
        }

        //--------------------------------
        //  ���y��~
        //--------------------------------
        void DXTKAudio::musicStop(int trackNo)
        {
            if (!musicInst[trackNo]) return;
            musicInst[trackNo]->Stop();
        }

        //--------------------------------
        //  ���y�ꎞ��~
        //--------------------------------
        void DXTKAudio::musicPause(int trackNo)
        {
            if (!musicInst[trackNo]) return;
            musicInst[trackNo]->Pause();
        }

        //--------------------------------
        //  ���y�ĊJ
        //--------------------------------
        void DXTKAudio::musicResume(int trackNo)
        {
            if (!musicInst[trackNo]) return;
            musicInst[trackNo]->Resume();
        }

        //--------------------------------
        //  ���y�{�����[���ݒ�
        //--------------------------------
        void DXTKAudio::musicSetVolume(int trackNo, float volume)
        {
            if (!musicInst[trackNo]) return;
            musicInst[trackNo]->SetVolume(volume);
        }

        //--------------------------------
        //  ���ʉ��̓ǂݍ��݁ixwb�t�@�C���j
        //--------------------------------
        void DXTKAudio::soundLoad(const wchar_t* xwbFileName, float volume)
        {
            for (auto &p : soundInst) if (p) p.reset();
            waveBank.reset(new WaveBank(audioEngine.get(), xwbFileName));

            for (auto &p : soundVolume) p = volume;
        }

        //--------------------------------
        //  ���ʉ��̍Đ�
        //--------------------------------
        void DXTKAudio::soundPlay(int trackNo)
        {
            soundInst[trackNo] = waveBank->CreateInstance(trackNo);
            if (soundInst[trackNo])
            {
                soundInst[trackNo]->SetVolume(soundVolume[trackNo]);
                soundInst[trackNo]->Play();
            }
        }

        //--------------------------------
        //  ���ʉ��̃{�����[���ݒ�
        //--------------------------------
        void DXTKAudio::soundSetVolume(int trackNo, float vol)
        {
            soundVolume[trackNo] = vol;
        }
    }
}

//******************************************************************************