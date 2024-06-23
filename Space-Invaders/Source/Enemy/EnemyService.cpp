#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Enemy
{
	using namespace Global;

	EnemyService::EnemyService()
	{
		enemy_controller = nullptr;
	}

	EnemyService::~EnemyService()
	{
		destroy();
	}

	void EnemyService::destroy()
	{
		delete(enemy_controller);
		enemy_controller = nullptr;
	}

	void EnemyService::initialize()
	{
		SpawnEnemy();
	}

	void EnemyService::update()
	{

	}

	void EnemyService::render()
	{
		enemy_controller->render();
	}

	EnemyController* EnemyService::SpawnEnemy()
	{
		enemy_controller = new EnemyController();
		enemy_controller->initialize();

		return enemy_controller;
	}
}
