#include "../Header/ServiceLocator.h"

ServiceLocator::ServiceLocator()
{
	//Constructor
}

ServiceLocator::~ServiceLocator()
{
	//Destructor
}

void ServiceLocator::createServices()
{
	// Creates instances of all services.
}

void ServiceLocator::clearAllServices()
{
	//	Deletes and deallocates memory for all services.
}

ServiceLocator* ServiceLocator::getInstance()
{
	return nullptr;
}

void ServiceLocator ::initialize()
{
	//	Initializes the ServiceLocator.
}

void ServiceLocator::update()
{
	//	Updates all services.
}

void ServiceLocator::render()
{
	//	Renders using the services.
}