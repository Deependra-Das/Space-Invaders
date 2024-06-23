#pragma once

#include <SFML/Graphics.hpp>

namespace Enemy
{
	class EnemyModel
	{
	private:
		sf::Vector2f enemy_reference_position= sf::Vector2f(50.f, 50.f);
		sf::Vector2f enemy_current_position;

	public:

		EnemyModel();
		~EnemyModel();

		void initialize();

		sf::Vector2f getEnemyReferencePostion();
		sf::Vector2f getEnemyCurrentPostion();

		void setEnemyReferencePostion(sf::Vector2f position);
		void setEnemyCurrentPostion(sf::Vector2f position);

	};
}
