#include "../../Header/UI/PauseMenu/PauseMenuUIController.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Graphic/GraphicService.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Sound/SoundService.h"
#include "../../Header/Event/EventService.h"

namespace UI
{
    namespace PauseMenu
    {
        using namespace Global;
        using namespace Main;
        using namespace UIElement;
        using namespace Sound;

        PauseMenuUIController::PauseMenuUIController()
        {
            createImage();
            createButtons();
        }

        PauseMenuUIController::~PauseMenuUIController()
        {
            destroy();
        }

        void PauseMenuUIController::initialize()
        {
            initializeBackgroundImage();
            initializePauseImage();
            initializeButtons();
            registerButtonCallback();
        }

        void PauseMenuUIController::createImage()
        {
            background_image = new ImageView();
            pause_image_view = new ImageView();
        }

        void PauseMenuUIController::createButtons()
        {
            continue_button = new ButtonView();
            menu_button = new ButtonView();

        }

        void PauseMenuUIController::initializeBackgroundImage()
        {
            sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

            background_image->initialize(Config::background_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0, 0));
            background_image->setImageAlpha(background_image_alpha);
        }

        void PauseMenuUIController::initializePauseImage()
        {
            pause_image_view->initialize(Config::game_paused_texture_path, pause_image_width, pause_image_height, sf::Vector2f(0, pause_image_y_position));
            pause_image_view->setCentreAlinged();
        }


        void PauseMenuUIController::initializeButtons()
        {
            continue_button->initialize("Continue Button", Config::continue_button_texture_path, button_width, button_height, sf::Vector2f(0, continue_button_y_position));
            menu_button->initialize("Menu Button", Config::menu_button_texture_path, button_width, button_height, sf::Vector2f(0, menu_button_y_position));

            continue_button->setCentreAlinged();
            menu_button->setCentreAlinged();
        }

        void PauseMenuUIController::registerButtonCallback()
        {
            continue_button->registerCallbackFuntion(std::bind(&PauseMenuUIController::ContinueButtonCallback, this));
            menu_button->registerCallbackFuntion(std::bind(&PauseMenuUIController::MenuButtonCallback, this));

        }

        void PauseMenuUIController::ContinueButtonCallback()
        {
            ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
            GameService::setGameState(GameState::GAMEPLAY);
        }

        void PauseMenuUIController::MenuButtonCallback()
        {
            ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
            ServiceLocator::getInstance()->getGameplayService()->restart();
            GameService::setGameState(GameState::MAIN_MENU);
            ServiceLocator::getInstance()->getSoundService()->playBackgroundMusic();
        }

        void PauseMenuUIController::update()
        {
            background_image->update();
            pause_image_view->update();
            continue_button->update();
            menu_button->update();
        }

        void PauseMenuUIController::render()
        {
            background_image->render();
            pause_image_view->render();
            continue_button->render();
            menu_button->render();
        }

        void PauseMenuUIController::show()
        {
            background_image->show();
            pause_image_view->show();
            continue_button->show();
            menu_button->show();

        }

        void PauseMenuUIController::destroy()
        {
            delete (continue_button);
            delete (menu_button);
            delete (background_image);
            delete (pause_image_view);
        }
    }
}