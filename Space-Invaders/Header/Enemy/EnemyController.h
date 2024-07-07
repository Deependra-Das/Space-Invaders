#pragma once

#include <SFML/Graphics.hpp>
#include "../../Header/Enemy/EnemyConfig.h"

namespace Enemy
{
	class EnemyView;
	class EnemyModel;

	enum class EnemyType;
	enum class EnemyState;

	class EnemyController
	{
	protected:
		EnemyModel* enemy_model;
		EnemyView* enemy_view;

		float rate_of_fire=3.0f;
		float elapsed_fire_duration=0.0f;

		void virtual move()=0;
		void moveLeft();
		void moveRight();
		void moveDown();

		void updateFireTimer();
		void processBulletFire();
		virtual void fireBullet()=0;

	public:
		EnemyController(EnemyType type);
		virtual ~EnemyController();

		void virtual initialize();
		void update();
		void render();
		
		sf::Vector2f getEnemyPosition();
		sf::Vector2f getRandomInitialPosition();
		void handleOutOfBounds();

		EnemyType getEnemyType();
		EnemyState getEnemyState();
	
	};
}