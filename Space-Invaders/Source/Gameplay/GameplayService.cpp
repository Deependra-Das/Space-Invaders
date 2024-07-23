#include "../../Header/Gameplay/GameplayService.h"
#include "../../Header/Gameplay/GameplayController.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../Header/Main/GameService.h"

namespace Gameplay
{
	using namespace Global;
	using namespace Player;
	using namespace Enemy;
	using namespace Element;
	using namespace Bullet;
	using namespace Main;
	using namespace Event;

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
		processPlayerInput();
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

	void GameplayService::pauseGameplay()
	{
		GameService::setGameState(GameState::PAUSE_MENU);
	}

	void GameplayService::processPlayerInput()
	{
		EventService* event_service = ServiceLocator::getInstance()->getEventService();

		if (event_service->pressedPKey())
		{
			pauseGameplay();
		}

	}
}
