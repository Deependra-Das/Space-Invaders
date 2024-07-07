#include "../../Header/Gameplay/GameplayService.h"

namespace Gameplay
{
	GameplayService::GameplayService()
	{
		gameplay_Controller = new GameplayController();
	}

	GameplayService::~GameplayService()
	{
		delete(gameplay_Controller);
		gameplay_Controller = nullptr;
	}

	void GameplayService::initialize()
	{
		gameplay_Controller->initialize();
	}

	void GameplayService::update()
	{
		gameplay_Controller->update();
	}

	void GameplayService::render()
	{
		gameplay_Controller->render();
	}

	void GameplayService::restart()
	{
		ServiceLocator::getInstance()->getPlayerService()->reset();
		ServiceLocator::getInstance()->getEnemyService()->reset();
		ServiceLocator::getInstance()->getBulletService()->reset();
		ServiceLocator::getInstance()->getElementService()->reset();
	}
}
