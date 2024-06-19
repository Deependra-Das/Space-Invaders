#pragma once

class ServiceLocator
{
private:

    // Private Constructor and Destructor:
    ServiceLocator();
    ~ServiceLocator();

    // Private Methods:
    void createServices(); 
    void clearAllServices(); 		

public:

    // Public Methods:
    static ServiceLocator* getInstance();  

    void initialize(); 			
    void update(); 				
    void render(); 				

};