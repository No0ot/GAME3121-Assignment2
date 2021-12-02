#pragma once

#include "SDL_audio.h"

#include <iostream>
#include <string>
#include <map>

enum SoundType
{
	SOUND_MUSIC = 0,
	SOUND_SFX = 1
};

static Uint8* audio_pos; // global pointer to the audio buffer to be played
static Uint32 audio_len; // remaining length of the sample we have to play
void AudioCallback(void* userdata, Uint8* stream, int len);

static Uint8* musicaudio_pos; // global pointer to the audio buffer to be played
static Uint32 musicaudio_len; // remaining length of the sample we have to play
void MusicAudioCallback(void* userdata, Uint8* stream, int len);

class SoundManager
{
public: 

	bool Load(std::string filename, std::string id, SoundType type);
	void PlaySound();
	void PlayMusic();

	SoundManager();
	~SoundManager();
	
private:

	SDL_AudioSpec audioSettings;
	static Uint32 wav_length; // length of our sample
	static Uint8* wav_buffer; // buffer containing our audio file

};



