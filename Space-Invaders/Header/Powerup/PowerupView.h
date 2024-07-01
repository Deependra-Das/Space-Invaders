#pragma once

#include <SFML/Graphics.hpp>

namespace Powerup
{
	class PowerupController;
	enum class PowerupType;

	class PowerupView
	{
	private:
		const float powerup_sprite_width = 30.0f;
		const float powerup_sprite_height = 30.0f;

		PowerupController* powerup_controller;

		sf::RenderWindow* game_window;
		sf::Texture powerup_texture;
		sf::Sprite powerup_sprite;

		void initializeImage(PowerupType type);
		void scaleImage();

		void destroy();

	public:
		PowerupView();
		~PowerupView();

		void initialize(PowerupController* controller);
		void update();
		void render();

	};
}