#pragma once

#include "../../header/UI/Interface/IUIController.h"
#include "../../header/UI/UIElement/ImageView.h"
#include "../../header/UI/UIElement/ButtonView.h"
#include "../../header/UI/UIElement/TextView.h"

namespace UI
{
    namespace GameplayUI
    {
        class GameplayUIController : public Interface::IUIController
        {
        private:
            const int font_size = 24;
            const float text_y_position = 5.f;
            const float enemies_killed_text_x_position = 40.f;
            const float lives_remaining_text_x_position = 1560.f;

            const float container_y_position = 0.f;
            const float score_container_x_position = 0.f;
            const float lives_container_x_position = 1520.f;

            const float player_lives_y_offset = 8.f;
            const float player_lives_x_offset = 1850.f;
            const float player_lives_spacing = 40.f;

            const float player_sprite_width = 24.f;
            const float player_sprite_height = 24.f;

            const float container_width = 400.f;
            const float container_height = 44.f;

            const sf::Color text_color = sf::Color::Color(248,206,43);

            UI::UIElement::ImageView* player_image;
            UI::UIElement::ImageView* score_container_image;
            UI::UIElement::ImageView* lives_container_image;
            UI::UIElement::TextView* enemies_killed_text;
            UI::UIElement::TextView* lives_remaining_text;

            float spacing;

            void createUIElements();
            void initializeImage();
            void initializeText();
            void destroy();

        public:
            GameplayUIController();
            ~GameplayUIController();

            void initialize() override;
            void update() override;
            void render() override;
            void show() override;

            void updateEnemiesKilledText();
            void drawPlayerLivesImage();
            void drawContainerImage();

        };
    }
}

