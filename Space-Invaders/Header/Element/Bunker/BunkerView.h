#pragma once

#include <SFML/Graphics.hpp>

namespace Element
{
    namespace Bunker
    {
        class BunkerController;

        class BunkerView
        {
        private:
            const float bunker_sprite_width = 80.f;
            const float bunker_sprite_height = 80.f;

            sf::Texture bunker_texture;
            sf::Sprite bunker_sprite;

            BunkerController* bunker_controller;
            sf::RenderWindow* game_window;

            void scaleSprite();
            void initializeImage();

        public:
            BunkerView();
            ~BunkerView();

            void initialize(BunkerController* controller);
            void update();
            void render();
        };
    }
}