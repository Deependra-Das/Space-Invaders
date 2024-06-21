#include "../../Header/UI/MainMenu/MainMenuUIController.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Graphic/GraphicService.h"

namespace UI
{
    namespace MainMenu 
    {
        using namespace Global;
        using namespace Main;
        using namespace Graphic;
        using namespace Event;

        MainMenuUIController::MainMenuUIController() 
        { 
            game_window = nullptr; 
        }

        void MainMenuUIController::initialize()
        {
            game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
        }

        void MainMenuUIController::update()
        {
        }

        void MainMenuUIController::render()
        {
        }

    }
}