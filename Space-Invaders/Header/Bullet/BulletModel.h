#pragma once

#include <SFML/Graphics.hpp>

namespace Bullet
{
	enum class MovementDirection;
	enum class BulletType;

	class BulletModel
	{
	private:
		MovementDirection movement_direction;
		sf::Vector2f bullet_position;
		BulletType bullet_type;
		float movement_speed=300.0f;

	public:
		BulletModel(BulletType type);
		~BulletModel();

		void initialize(sf::Vector2f position, MovementDirection direction);

		MovementDirection getMovementDirection();
		void setMovementDirection(MovementDirection direction);

		sf::Vector2f getBulletPosition();
		void setBulletPosition(sf::Vector2f position);

		BulletType getBulletType();
		void setBulletType(BulletType type);

		float getMovementSpeed();
		void setMovementSpeed(float speed);

	};
}