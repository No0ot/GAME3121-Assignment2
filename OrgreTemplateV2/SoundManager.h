#pragma once
// Core Libraries
#include <iostream>
#include <string>
#include <map> 

#include <SDL_mixer.h>
/// <summary>
/// enum for different sound types
/// </summary>
enum sound_type
{
	SOUND_MUSIC = 0,
	SOUND_SFX = 1
};
/// <summary>
/// Sound Manager using a singleton design pattern that can load .wav sounds and play them back.
/// Uses SDL_mixer.h library for this.
/// </summary>
class SoundManager {
public:
	/// <summary>
	/// Static instance call acts as the singleton.
	/// </summary>
	/// <returns></returns>
	static SoundManager* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new SoundManager();
			return s_pInstance;
		}
		return s_pInstance;
	}
	/// <summary>
	/// Load a .wav (sound or music) and add it to its respective map. File should be placed in project folder.
	/// </summary>
	/// <param name="fileName">Name of the .wav file.</param>
	/// <param name="id"> String used to to grab the track from the map.</param>
	/// <param name="type"></param>
	/// <returns></returns>
	bool load(std::string fileName, std::string id, sound_type type);
	/// <summary>
	/// Plays a sound from the map. 
	/// </summary>
	/// <param name="id"></param>
	/// <param name="loop"> -1 for infinite loop otherwise its number of loops.</param>
	/// <param name="volume">Volume between 0 and 128.</param>
	void playSound(std::string id, int loop, int volume);
	/// <summary>
	/// Plays a music track from the map.
	/// </summary>
	/// <param name="id"></param>
	/// <param name="loop">-1 for infinite loop otherwise its number of loops.</param>
	/// <param name="volume">Volume between 0 and 128.</param>
	void playMusic(std::string id, int loop, int volume);
private:
	static SoundManager* s_pInstance; /**< Static instance object for singleton*/

	std::map<std::string, Mix_Chunk*> m_sfxs; /**< Map of SFXs.*/
	std::map<std::string, Mix_Music*> m_music; /**< Map of music tracks.*/

	SoundManager();
	~SoundManager();

	SoundManager(const SoundManager&);
};

typedef SoundManager TheSoundManager;
