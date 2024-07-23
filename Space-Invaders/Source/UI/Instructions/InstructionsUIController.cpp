#include "../../Header/UI/Instructions/InstructionsUIController.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Graphic/GraphicService.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Sound/SoundService.h"
#include "../../Header/Event/EventService.h"

namespace UI
{
    namespace InstructionsUI
    {
        using namespace Global;
        using namespace Main;
        using namespace UIElement;
        using namespace Sound;

        InstructionsUIController::InstructionsUIController()
        {
            createImage();
            createButtons();
        }

        InstructionsUIController::~InstructionsUIController()
        {
            destroy();
        }

        void InstructionsUIController::initialize()
        {
            initializeBackgroundImage();
            initializeInstructionsImage();
            initializeButtons();
            registerButtonCallback();
        }

        void InstructionsUIController::createImage()
        {
            background_image = new ImageView();
            instructions_image_view = new ImageView();
        }

        void InstructionsUIController::createButtons()
        {
            menu_button = new ButtonView();

        }

        void InstructionsUIController::initializeBackgroundImage()
        {
            sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

            background_image->initialize(Config::background_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0, 0));
            background_image->setImageAlpha(background_image_alpha);
        }

        void InstructionsUIController::initializeInstructionsImage()
        {
            instructions_image_view->initialize(Config::instructions_image_texture_path, instructions_image_width, instructions_image_height, sf::Vector2f(0, instructions_image_y_position));
            instructions_image_view->setCentreAlinged();
        }


        void InstructionsUIController::initializeButtons()
        {
            menu_button->initialize("Menu Button", Config::menu_button_texture_path, button_width, button_height, sf::Vector2f(0, menu_button_y_position));
            menu_button->setCentreAlinged();
        }

        void InstructionsUIController::registerButtonCallback()
        {
            menu_button->registerCallbackFuntion(std::bind(&InstructionsUIController::MenuButtonCallback, this));

        }


        void InstructionsUIController::MenuButtonCallback()
        {
            ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
            ServiceLocator::getInstance()->getPlayerService()->reset();
            ServiceLocator::getInstance()->getGameplayService()->restart();
            GameService::setGameState(GameState::MAIN_MENU);
            ServiceLocator::getInstance()->getSoundService()->playBackgroundMusic();
        }

        void InstructionsUIController::update()
        {
            background_image->update();
            instructions_image_view->update();
            menu_button->update();
        }

        void InstructionsUIController::render()
        {
            background_image->render();
            instructions_image_view->render();
            menu_button->render();
        }

        void InstructionsUIController::show()
        {
            background_image->show();
            instructions_image_view->show();
            menu_button->show();

        }

        void InstructionsUIController::destroy()
        {
            delete (menu_button);
            delete (background_image);
            delete (instructions_image_view);
        }
    }
}