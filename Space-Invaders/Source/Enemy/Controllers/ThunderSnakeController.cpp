#include "../../Header/Enemy/Controllers/ThunderSnakeController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Enemy
{
	using namespace Global;
	using namespace Bullet;

	namespace Controller
	{
		ThunderSnakeController::ThunderSnakeController(EnemyType type) : EnemyController(type)
		{

		}

		ThunderSnakeController::~ThunderSnakeController()
		{

		}

		void ThunderSnakeController::initialize()
		{
			EnemyController::initialize();
			enemy_model->setMovementDirection(getInitialMovementDirection());
			enemy_model->horizontal_movement_speed = thundersnake_horizontal_movement_speed;
			rate_of_fire = thundersnake_rate_of_fire;
		}

		MovementDirection ThunderSnakeController::getInitialMovementDirection()
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

		void ThunderSnakeController::move()
		{

			switch (enemy_model->getMovementDirection())
			{
			case::Enemy::MovementDirection::LEFT:
				moveLeft();
				break;

			case::Enemy::MovementDirection::RIGHT:
				moveRight();
				break;

			case::Enemy::MovementDirection::LEFT_DOWN:
				moveDiagonalLeft();
				break;

			case::Enemy::MovementDirection::RIGHT_DOWN:
				moveDiagonalRight();
				break;
			}
		}

		void ThunderSnakeController::moveLeft()
		{
			sf::Vector2f current_position = enemy_model->getEnemyCurrentPostion();
			current_position.x -= enemy_model->horizontal_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (current_position.x <= enemy_model->left_most_position.x)
			{
				enemy_model->setMovementDirection(MovementDirection::RIGHT_DOWN);
			}
			else
			{
				enemy_model->setEnemyCurrentPostion(current_position);
			}
		}

		void ThunderSnakeController::moveRight()
		{
			sf::Vector2f current_position = enemy_model->getEnemyCurrentPostion();
			current_position.x += enemy_model->horizontal_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (current_position.x >= enemy_model->right_most_position.x)
			{
				enemy_model->setMovementDirection(MovementDirection::LEFT_DOWN);
				enemy_model->setEnemyReferencePostion(current_position);
			}
			else
			{
				enemy_model->setEnemyCurrentPostion(current_position);
			}
		}

		void ThunderSnakeController::moveDiagonalLeft()
		{
			sf::Vector2f currentPosition = enemy_model->getEnemyCurrentPostion();
			currentPosition.y += enemy_model->vertical_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
			currentPosition.x -= enemy_model->horizontal_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (currentPosition.x <= enemy_model->left_most_position.x)
			{
				enemy_model->setMovementDirection(MovementDirection::RIGHT);
			}
			else enemy_model->setEnemyCurrentPostion(currentPosition);
		}

		void ThunderSnakeController::moveDiagonalRight()
		{
			sf::Vector2f currentPosition = enemy_model->getEnemyCurrentPostion();
			currentPosition.y += enemy_model->vertical_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
			currentPosition.x += enemy_model->horizontal_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (currentPosition.x >= enemy_model->right_most_position.x)
			{
				enemy_model->setMovementDirection(MovementDirection::LEFT);
			}
			else enemy_model->setEnemyCurrentPostion(currentPosition);
		}

		void ThunderSnakeController::fireBullet()
		{
			ServiceLocator::getInstance()->getBulletService()->spawnBullet(BulletType::TORPEDO,
				enemy_model->getEnemyCurrentPostion() + enemy_model->barrel_position_offset,
				Bullet::MovementDirection::DOWN);
		}
	
	}
}