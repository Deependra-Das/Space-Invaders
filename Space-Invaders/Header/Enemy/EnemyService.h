#pragma once

#include <vector>

namespace Enemy
{
	class EnemyController;

	class EnemyService
	{
	private:
		std::vector<EnemyController*> enemy_list;
		const float spawn_interval=3.0f;
		float spawn_timer;

		void destroy();
		void updateSpawnTimer();
		void processEnemySpawn();

	public:
		EnemyService();
		virtual ~EnemyService();

		void initialize();
		void update();
		void render();

		void SpawnEnemy();
	};
}