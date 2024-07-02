#pragma once

#include <SFML/Graphics.hpp>
#include "../../Header/UI/Interface/IUIController.h"

namespace UI
{
	namespace MainMenu
	{
		class MainMenuUIController: public Interface::IUIController
		{
		private:
			const float button_height = 140.0f;
			const float button_width = 400.0f;

			sf::RenderWindow * game_window;

			sf::Texture background_texture;
			sf::Texture play_button_texture;
			sf::Texture instructions_button_texture;
			sf::Texture quit_button_texture;

			sf::Sprite background_sprite;
			sf::Sprite play_button_sprite;
			sf::Sprite instructions_button_sprite;
			sf::Sprite quit_button_sprite;

			void initializeBackgroundImage();
			void scaleBackgroundImage();

			void initializeButtons();
			bool loadButtonTexturesFromFile();
			void setButtonSprites();

			void scaleAllButttons();
			void scaleButton(sf::Sprite* button_to_scale);
			void positionButtons();

			void processButtonInteractions();
			bool clickedButton(sf::Sprite*, sf::Vector2f);

		public:
			MainMenuUIController();

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;

		};
	}
}