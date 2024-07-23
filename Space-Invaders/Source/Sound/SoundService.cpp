#include "../../Header/Sound/SoundService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"

namespace Sound
{
	using namespace Global;

	void SoundService::initialize()
	{
		loadBackgroundMusicFromFile();
		loadSoundFromFile();
	}

	void SoundService::loadBackgroundMusicFromFile()
	{
		if (!background_music.openFromFile(Config::background_music_path))
		{
			printf("Error loading background music file.");
		}
			
	}

	void SoundService::loadSoundFromFile()
	{
		if (!buffer_button_click.loadFromFile(Config::button_click_sound_path))
		{
			printf("Error loading sound file.");
		}
		if (!buffer_explosion.loadFromFile(Config::explosion_sound_path))
		{
			printf("Error loading sound file.");
		}
		if (!buffer_bullet_fire.loadFromFile(Config::bullet_fire_sound_path))
		{
			printf("Error loading sound file.");
		}
		if (!buffer_power_enabled.loadFromFile(Config::powerup_enabled_sound_path))
		{
			printf("Error loading sound file.");
		}
		if (!buffer_power_disabled.loadFromFile(Config::powerup_disabled_sound_path))
		{
			printf("Error loading sound file.");
		}
		if (!player_damage_taken.loadFromFile(Config::player_damage_sound_path))
		{
			printf("Error loading sound file.");
		}
		if (!player_frozen.loadFromFile(Config::frozen_sound_path))
		{
			printf("Error loading sound file.");
		}
		if (!o_bomb_explosion.loadFromFile(Config::o_bomb_explosion_sound_path))
		{
			printf("Error loading sound file.");
		}
			
	}

	void SoundService::playSound(SoundType soundType)
	{
		switch (soundType)
		{
		case SoundType::BUTTON_CLICK:
			sound_effect.setBuffer(buffer_button_click);
			break;

		case SoundType::EXPLOSION:
			sound_effect.setBuffer(buffer_explosion);
			break;

		case SoundType::BULLET_FIRE:
			sound_effect.setBuffer(buffer_bullet_fire);
			break;

		case SoundType::POWERUP_ENABLED:
			sound_effect.setBuffer(buffer_power_enabled);
			break;

		case SoundType::POWERUP_DISABLED:
			sound_effect.setBuffer(buffer_power_disabled);
			break;

		case SoundType::PLAYER_DAMAGE:
			sound_effect.setBuffer(player_damage_taken);
			break;

		case SoundType::FROZEN:
			sound_effect.setBuffer(player_frozen);
			break;

		case SoundType::O_BOMB_EXPLOSION:
			sound_effect.setBuffer(o_bomb_explosion);
			break;

		default:
			printf("Invalid sound type");
			return;
		}

		sound_effect.play();
	}

	void SoundService::playBackgroundMusic()
	{
		background_music.setLoop(true);
		background_music.setVolume(background_music_volume);
		background_music.play();
	}
}