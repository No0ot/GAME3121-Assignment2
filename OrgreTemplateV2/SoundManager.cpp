#include "SoundManager.h"
#include "SDL.h"

bool SoundManager::Load(std::string filename, std::string id, SoundType type)
{
	
	return false;
}

void SoundManager::PlaySound()
{
	static Uint32 wav_length; // length of our sample
	static Uint8* wav_buffer; // buffer containing our audio file
	static SDL_AudioSpec wav_spec; // the specs of our piece of music


	/* Load the WAV */
	// the specs, length and buffer of our wav are filled
	if (SDL_LoadWAV("Jump.wav", &wav_spec, &wav_buffer, &wav_length) == NULL) {
		fprintf(stderr, "Could not open test.wav: %s\n", SDL_GetError());
	}
	
	
	// set the callback function
	wav_spec.callback = AudioCallback;
	wav_spec.userdata = NULL;
	// set our global static variables
	audio_pos = wav_buffer; // copy sound buffer
	audio_len = wav_length; // copy file length


	/* Open the audio device */
	if (SDL_OpenAudio(&wav_spec, 0) < 0) {
		fprintf(stderr, "Couldn't open audio: %s\n", SDL_GetError());
		exit(-1);
	}

	/* Start playing */
	SDL_PauseAudio(0);

	//while (audio_len > 0) {
	//	SDL_Delay(10);
	//}
}

void SoundManager::PlayMusic()
{
	static Uint32 wav_length; // length of our sample
	static Uint8* wav_buffer; // buffer containing our audio file
	//static SDL_AudioSpec wav_spec; // the specs of our piece of music


	/* Load the WAV */
	// the specs, length and buffer of our wav are filled
	if (SDL_LoadWAV("music.wav", &audioSettings, &wav_buffer, &wav_length) == NULL) {
		fprintf(stderr, "Could not open test.wav: %s\n", SDL_GetError());
	}


	// set the callback function
	//wav_spec.callback = AudioCallback;
	//wav_spec.userdata = NULL;
	// set our global static variables
	musicaudio_pos = wav_buffer; // copy sound buffer
	musicaudio_len = wav_length; // copy file length


	/* Open the audio device */
	//if (SDL_OpenAudio(&audioSettings, NULL) < 0) {
	//	fprintf(stderr, "Couldn't open audio: %s\n", SDL_GetError());
	//	exit(-1);
	//}

	/* Start playing */
	SDL_PauseAudio(0);
}

SoundManager::SoundManager()
{
	audioSettings = { 0 };

	audioSettings.freq = 22050;
	audioSettings.format = AUDIO_S16;
	audioSettings.channels = 2;
	audioSettings.samples = 2;
	audioSettings.callback = MusicAudioCallback;

	SDL_OpenAudio(&audioSettings, 0);
}

SoundManager::~SoundManager()
{
}

void AudioCallback(void* userdata, Uint8* stream, int len)
{
	if (audio_len == 0)
		return;

	len = (len > audio_len ? audio_len : len);
	//SDL_memcpy (stream, audio_pos, len); 					// simply copy from one buffer into the other
	SDL_MixAudio(stream, audio_pos, len, SDL_MIX_MAXVOLUME);// mix from one buffer into another

	audio_pos += len;
	audio_len -= len;
}

void MusicAudioCallback(void* userdata, Uint8* stream, int len)
{
	if(musicaudio_len == 0)
		return;

	len = (len > musicaudio_len ? musicaudio_len : len);
	//SDL_memcpy (stream, audio_pos, len); 					// simply copy from one buffer into the other
	SDL_MixAudio(stream, musicaudio_pos, len, 64);// mix from one buffer into another

	musicaudio_pos += len;
	musicaudio_len -= len;
}
