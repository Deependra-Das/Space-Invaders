#pragma once

#include "../../Header/Graphic/GraphicService.h"
#include "../../Header/Event/EventService.h"
#include "../../Header/Player/PlayerService.h"
#include "../../Header/Time/TimeService.h"

class ServiceLocator
{
private:

    // Private Constructor and Destructor:
    ServiceLocator();
    ~ServiceLocator();

    //private member variables
    GraphicService* graphic_service;
    TimeService* time_service;
    EventService* event_service;
    PlayerService* player_service;

    // Private Methods:
    void createServices(); 
    void clearAllServices(); 		

public:

    // Public Methods:
    static ServiceLocator* getInstance();  

    void initialize(); 			
    void update(); 				
    void render(); 				

    GraphicService* getGraphicService();
    EventService* getEventService();
    PlayerService* getPlayerService();
    TimeService* getTimeService();
};