#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Time/TimeService.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Enemy/Controllers/SubZeroController.h"
#include "../../Header/Enemy/Controllers/ZapperController.h"
#include "../../Header/Enemy/Controllers/ThunderSnakeController.h"
#include "../../Header/Enemy/Controllers/UFOController.h"

namespace Enemy
{
	using namespace Global;
	using namespace Time;
	using namespace Controller;

	EnemyService::EnemyService()
	{
		
	}

	EnemyService::~EnemyService()
	{
		destroy();
	}

	void EnemyService::destroy()
	{
		for (int i = 0; i < enemy_list.size(); i++)
		{
			delete(enemy_list[i]);
			enemy_list[i] = nullptr;
		}
	}

	void EnemyService::initialize()
	{
		spawn_timer = spawn_interval;
	}

	void EnemyService::update()
	{
		updateSpawnTimer();
		processEnemySpawn();

		for (int i = 0; i < enemy_list.size(); i++)
		{
			enemy_list[i]->update();
		}
		
	}

	void EnemyService::render()
	{
		for (int i = 0; i < enemy_list.size(); i++)
		{
			enemy_list[i]->render();
		}
	}

	EnemyController* EnemyService::SpawnEnemy()
	{
		EnemyController* enemy_controller = createEnemy(getRandomEnemyType(), Entity::EntityType::ENEMY);
		enemy_controller->initialize();

		enemy_list.push_back(enemy_controller);

		return enemy_controller;
	}

	void EnemyService::processEnemySpawn()
	{
		if (spawn_timer >= spawn_interval)
		{
			SpawnEnemy();
			spawn_timer = 0.0f;
		}
	}

	void EnemyService::updateSpawnTimer()
	{
		spawn_timer += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
	}

	EnemyController* EnemyService::createEnemy(EnemyType enemy_type, Entity::EntityType owner_type)
	{
		switch (enemy_type)
		{
		case::Enemy::EnemyType::SUBZERO:
			return new SubZeroController(Enemy::EnemyType::SUBZERO, owner_type);

		case::Enemy::EnemyType::ZAPPER:
			return new ZapperController(Enemy::EnemyType::ZAPPER, owner_type);

		case::Enemy::EnemyType::THUNDER_SNAKE:
			return new ThunderSnakeController(Enemy::EnemyType::THUNDER_SNAKE, owner_type);

		case::Enemy::EnemyType::UFO:
			return new UFOController(Enemy::EnemyType::UFO, owner_type);

		}
	}

	EnemyType EnemyService::getRandomEnemyType()
	{
		int randomType = std::rand() % 4; 
		return static_cast<Enemy::EnemyType>(randomType);
	}

	void EnemyService::destroyEnemy(EnemyController* enemy_controller)
	{
		enemy_list.erase(std::remove(enemy_list.begin(), enemy_list.end(), enemy_controller), enemy_list.end());
		delete(enemy_controller);
	}

}
