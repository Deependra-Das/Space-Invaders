#pragma once

namespace Enemy
{
	class EnemyController;

	class EnemyService
	{
	private:
		EnemyController* enemy_controller;

		void destroy();

	public:
		EnemyService();
		virtual ~EnemyService();

		void initialize();
		void update();
		void render();

		EnemyController* SpawnEnemy();
	};
}