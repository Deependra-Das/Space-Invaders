#include "../../Header/Enemy/EnemyModel.h"

namespace Enemy
{
	EnemyModel::EnemyModel()
	{

	}

	EnemyModel::~EnemyModel()
	{

	}

	void EnemyModel::initialize()
	{
		enemy_current_position = enemy_reference_position;
		movement_direction = MovementDirection::RIGHT;
	}


	sf::Vector2f EnemyModel::getEnemyReferencePostion()
	{
		return enemy_reference_position;
	}

	sf::Vector2f EnemyModel::getEnemyCurrentPostion()
	{
		return enemy_current_position;
	}

	void EnemyModel::setEnemyReferencePostion(sf::Vector2f position)
	{
		enemy_reference_position = position;
	}

	void EnemyModel::setEnemyCurrentPostion(sf::Vector2f position)
	{
		enemy_current_position = position;
	}

	MovementDirection EnemyModel::getMovementDirection()
	{
		return movement_direction;
	}

	void EnemyModel::setMovementDirection(MovementDirection direction)
	{
		movement_direction = direction;
	}
}