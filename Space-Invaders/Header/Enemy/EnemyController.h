#pragma once

#include <SFML/Graphics.hpp>

namespace Enemy
{
	class EnemyView;
	class EnemyModel;

	class EnemyController
	{
	private:
		EnemyModel* enemy_model;
		EnemyView* enemy_view;

		void virtual move()=0;
		void moveLeft();
		void moveRight();
		void moveDown();

	public:
		EnemyController();
		virtual ~EnemyController();

		void virtual initialize();
		void update();
		void render();
		
		sf::Vector2f getEnemyPosition();
		void getRandomInitialPosition();
		void handleOutOfBounds();
	
	};
}