#pragma once

#include "../../Header/Graphic/GraphicService.h"
#include "../../Header/Event/EventService.h"
#include "../../Header/Player/PlayerService.h"
#include "../../Header/Time/TimeService.h"
#include "../../Header/UI/UIService.h"

namespace Global
{
    class ServiceLocator
    {
    private:

        // Private Constructor and Destructor:
        ServiceLocator();
        ~ServiceLocator();

        //private member variables
        Graphic::GraphicService* graphic_service;
        Time::TimeService* time_service;
        Event::EventService* event_service;
        Player::PlayerService* player_service;
        UI::UIService* ui_service;

        // Private Methods:
        void createServices(); 
        void clearAllServices(); 		

    public:

        // Public Methods:
        static ServiceLocator* getInstance();  

        void initialize(); 			
        void update(); 				
        void render(); 				

        Graphic::GraphicService* getGraphicService();
        Event::EventService* getEventService();
        Player::PlayerService* getPlayerService();
        Time::TimeService* getTimeService();
        UI::UIService* getUIService();
    };
}