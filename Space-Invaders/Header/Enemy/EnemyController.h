#pragma once

#include <SFML/Graphics.hpp>
#include "../../Header/Enemy/EnemyConfig.h"

namespace Enemy
{
	class EnemyView;
	class EnemyModel;

	class EnemyController
	{
	protected:
		EnemyModel* enemy_model;
		EnemyView* enemy_view;

		void virtual move()=0;
		void moveLeft();
		void moveRight();
		void moveDown();

	public:
		EnemyController(EnemyType type);
		virtual ~EnemyController();

		void virtual initialize();
		void update();
		void render();
		
		sf::Vector2f getEnemyPosition();
		void getRandomInitialPosition();
		void handleOutOfBounds();

		EnemyType getEnemyType();
	
	};
}