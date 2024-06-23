#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Enemy
{
	using namespace Global;

	EnemyController::EnemyController()
	{
		enemy_view = new EnemyView();
		enemy_model = new EnemyModel();
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
	}

	void EnemyController::update()
	{
		move();
		enemy_view->update();
	}

	void EnemyController::render()
	{
		enemy_view->render();
	}

	sf::Vector2f EnemyController::getEnemyPosition()
	{
		return enemy_model->getEnemyCurrentPostion();
	}

	void EnemyController::move()
	{
		switch (enemy_model->getMovementDirection())
		{
		case::Enemy::MovementDirection::LEFT :
			moveLeft();
			break;

		case::Enemy::MovementDirection::RIGHT:
			moveRight();
			break;

		case::Enemy::MovementDirection::DOWN:
			moveDown();
			break;
		}
	}

	void EnemyController::moveLeft()
	{
		sf::Vector2f current_position = enemy_model->getEnemyCurrentPostion();
		current_position.x -= enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

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
		current_position.x += enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

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
		current_position.y += enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

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

}