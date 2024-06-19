#pragma once

#include "../Header/GraphicService.h"

class ServiceLocator
{
private:

    // Private Constructor and Destructor:
    ServiceLocator();
    ~ServiceLocator();

    //private member variables
    GraphicService* graphic_service;

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
};