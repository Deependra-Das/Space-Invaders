#pragma once

#include <SFML/Graphics.hpp>

namespace Enemy
{
	enum class MovementDirection
	{
		LEFT,
		RIGHT,
		DOWN,
	};

	class EnemyModel
	{
	private:
		sf::Vector2f enemy_reference_position= sf::Vector2f(50.f, 50.f);
		sf::Vector2f enemy_current_position;

		MovementDirection movement_direction;

	public:

		const float enemy_movement_speed = 250.0f;

		const sf::Vector2f left_most_position = sf::Vector2f(50.f, 950.f);
		const sf::Vector2f right_most_position = sf::Vector2f(1800.f, 950.f);

		const float vertical_travel_distance = 100.0f;

		EnemyModel();
		~EnemyModel();

		void initialize();

		sf::Vector2f getEnemyReferencePostion();
		sf::Vector2f getEnemyCurrentPostion();

		void setEnemyReferencePostion(sf::Vector2f position);
		void setEnemyCurrentPostion(sf::Vector2f position);

		MovementDirection getMovementDirection();
		void setMovementDirection(MovementDirection direction);
	};
}
