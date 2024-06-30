#include "../../Header/Enemy/Controllers/UFOController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../header/Enemy/EnemyConfig.h"
#include "../../Header/Global/ServiceLocator.h"


namespace Enemy
{
	using namespace Global;
	using namespace Bullet;

	namespace Controller
	{

		UFOController::UFOController(EnemyType type) : EnemyController(type) { }

		UFOController::~UFOController()
		{

		}

		void UFOController::initialize()
		{
			EnemyController::initialize();
			enemy_model->setMovementDirection(getInitialMovementDirection());
		}

		void UFOController::move()
		{

			switch (enemy_model->getMovementDirection())
			{
			case::Enemy::MovementDirection::LEFT:
				moveLeft();
				break;

			case::Enemy::MovementDirection::RIGHT:
				moveRight();
				break;

			}
		}

		MovementDirection UFOController::getInitialMovementDirection()
		{
			static MovementDirection initial_direction = MovementDirection::RIGHT;

			switch (initial_direction)
			{
			case Enemy::MovementDirection::LEFT:
				initial_direction = MovementDirection::RIGHT;
				return initial_direction;

			case Enemy::MovementDirection::RIGHT:
				initial_direction = MovementDirection::LEFT;
				return initial_direction;
			}
		}

		void UFOController::moveLeft()
		{
			sf::Vector2f current_position = enemy_model->getEnemyCurrentPostion();
			current_position.x -= enemy_model->horizontal_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (current_position.x <= enemy_model->left_most_position.x)
			{
				enemy_model->setMovementDirection(MovementDirection::RIGHT);
			}
			else
			{
				enemy_model->setEnemyCurrentPostion(current_position);
			}
		}

		void UFOController::moveRight()
		{
			sf::Vector2f current_position = enemy_model->getEnemyCurrentPostion();
			current_position.x += enemy_model->horizontal_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (current_position.x >= enemy_model->right_most_position.x)
			{
				enemy_model->setMovementDirection(MovementDirection::LEFT);
				enemy_model->setEnemyReferencePostion(current_position);
			}
			else
			{
				enemy_model->setEnemyCurrentPostion(current_position);
			}
		}

		void UFOController::fireBullet()
		{
		/*	ServiceLocator::getInstance()->getBulletService()->spawnBullet(BulletType::LASER_BULLET,
				enemy_model->getEnemyCurrentPostion() + enemy_model->barrel_position_offset,
				Bullet::MovementDirection::DOWN);*/
		}

	}
}