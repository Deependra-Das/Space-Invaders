#include "../../Header/UI/GameplayUI/GameplayUIController.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Gameplay/GameplayService.h"
#include "../../Header/Sound/SoundService.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Player/PlayerModel.h"

namespace UI
{
    namespace GameplayUI
    {
        using namespace Main;
        using namespace Sound;
        using namespace Global;
        using namespace Player;
        using namespace UI::UIElement;

        GameplayUIController::GameplayUIController() { createUIElements(); }

        GameplayUIController::~GameplayUIController() { destroy(); }

        void GameplayUIController::initialize()
        {
            initializeImage();
            initializeText();
        }

        void GameplayUIController::createUIElements()
        {
            player_image = new ImageView();

            enemies_killed_text = new TextView();
        }

        void GameplayUIController::initializeImage()
        {
            player_image->initialize(Config::player_texture_path, player_sprite_width, player_sprite_height, sf::Vector2f(0, 0));
        }

        void GameplayUIController::initializeText()
        {

            sf::String enemies_killed_string = "Enemies Killed  :  0";


            enemies_killed_text->initialize(enemies_killed_string, sf::Vector2f(enemies_killed_text_x_position, text_y_position), FontType::BUBBLE_BOBBLE, font_size, text_color);
        }

        void GameplayUIController::update()
        {

            updateEnemiesKilledText();
        }

        void GameplayUIController::render()
        {

            enemies_killed_text->render();
            drawPlayerLivesImage();
        }

        void GameplayUIController::show() 
        { 
            player_image->show();
            enemies_killed_text->show();
        }



        void GameplayUIController::updateEnemiesKilledText()
        {
            sf::String enemies_killed_string = "Enemies Killed  :  " + std::to_string(PlayerModel::enemies_killed);
            enemies_killed_text->setText(enemies_killed_string);
        }

        void GameplayUIController::drawPlayerLivesImage()
        {
            sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

            for (int i = 0; i < PlayerModel::player_lives; i++)
            {
                player_image->setPosition(sf::Vector2f(player_lives_x_offset - (i * player_lives_spacing), player_lives_y_offset));
                player_image->render();
            }
        }

        void GameplayUIController::destroy()
        {
            delete(player_image);

            delete(enemies_killed_text);
        }
    }
}