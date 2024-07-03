#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Enemy/EnemyConfig.h"

namespace Enemy
{
	using namespace Global;

	EnemyController::EnemyController(EnemyType type, Entity::EntityType owner_type)
	{
		enemy_view = new EnemyView();
		enemy_model = new EnemyModel(type, owner_type);
	}

	EnemyController::~EnemyController()
	{			
		delete(enemy_view);
		delete(enemy_model);
		enemy_view = nullptr;
		enemy_model = nullptr;
	}

	void EnemyController::initialize()
	{
		enemy_model->initialize();
		enemy_view->initialize(this);
		enemy_model->setEnemyCurrentPostion(getRandomInitialPosition());
	}

	void EnemyController::update()
	{
		move();
		updateFireTimer();
		processBulletFire();
		enemy_view->update();
		handleOutOfBounds();
	}

	void EnemyController::render()
	{
		enemy_view->render();
	}

	sf::Vector2f EnemyController::getEnemyPosition()
	{
		return enemy_model->getEnemyCurrentPostion();
	}

	void EnemyController::moveLeft()
	{
		sf::Vector2f current_position = enemy_model->getEnemyCurrentPostion();
		current_position.x -= enemy_model->horizontal_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		if (current_position.x <= enemy_model->left_most_position.x)
		{
			enemy_model->setMovementDirection(MovementDirection::DOWN);
			enemy_model->setEnemyReferencePostion(current_position);
		}
		else
		{
			enemy_model->setEnemyCurrentPostion(current_position);
		}
	}

	void EnemyController::moveRight()
	{
		sf::Vector2f current_position = enemy_model->getEnemyCurrentPostion();
		current_position.x += enemy_model->horizontal_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		if (current_position.x >= enemy_model->right_most_position.x)
		{
			enemy_model->setMovementDirection(MovementDirection::DOWN);
			enemy_model->setEnemyReferencePostion(current_position);
		}
		else 
		{
			enemy_model->setEnemyCurrentPostion(current_position);
		}
	}

	void EnemyController::moveDown()
	{
		sf::Vector2f current_position = enemy_model->getEnemyCurrentPostion();
		current_position.y += enemy_model->horizontal_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		if (current_position.y >= enemy_model->getEnemyReferencePostion().y + enemy_model->vertical_travel_distance)
		{
			if (enemy_model->getEnemyReferencePostion().x <= enemy_model->left_most_position.x)
			{
				enemy_model->setMovementDirection(MovementDirection::RIGHT);
				
			}
			else if (enemy_model->getEnemyReferencePostion().x >= enemy_model->left_most_position.x)
			{
				enemy_model->setMovementDirection(MovementDirection::LEFT);
			
			}
		}
		else 
		{
			enemy_model->setEnemyCurrentPostion(current_position);

		}
	}

	sf::Vector2f EnemyController::getRandomInitialPosition()
	{
		float x_offset_distance = (std::rand() % static_cast<int>(enemy_model->right_most_position.x - enemy_model->left_most_position.x));
		float x_position = enemy_model->left_most_position.x + x_offset_distance;
		float y_position = enemy_model->left_most_position.y;
		return sf::Vector2f(x_position, y_position);
	}

	void EnemyController::handleOutOfBounds()
	{
		sf::Vector2f enemyPosition = getEnemyPosition();
		sf::Vector2u windowSize = ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->getSize();

		if (enemyPosition.x < 0 || enemyPosition.x > windowSize.x ||
			enemyPosition.y < 0 || enemyPosition.y > windowSize.y)
		{
			ServiceLocator::getInstance()->getEnemyService()->destroyEnemy(this);
		}
	}

	EnemyType EnemyController::getEnemyType()
	{
		return enemy_model->getEnemyType();
	}

	EnemyState EnemyController::getEnemyState()
	{
		return enemy_model->getEnemyState();
	}

	void EnemyController::updateFireTimer()
	{
		elapsed_fire_duration += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
	}

	void EnemyController::processBulletFire()
	{
		if (elapsed_fire_duration >= rate_of_fire)
		{
			fireBullet();
			elapsed_fire_duration = 0.f;
		}
	}

	Entity::EntityType EnemyController::getOwnerEntityType()
	{
		return enemy_model->getOwnerEntityType();
	}

}