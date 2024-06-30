#pragma once

#include <SFML/Graphics.hpp>

namespace Bullet
{
	enum class BulletType;
	class BulletController;

	class BulletView
	{
	private:
		const float bullet_sprite_height = 18.0f;
		const float bullet_sprite_width = 18.0f;

		BulletController* bullet_controller;
		sf::RenderWindow* game_window;

		sf::Texture bullet_texture;
		sf::Sprite bullet_sprite;

		void initializeImage(BulletType type);
		void scaleImage();

	public:
		BulletView();
		~BulletView();

		void initialize(BulletController* controller);
		void update();
		void render();
	};

}


