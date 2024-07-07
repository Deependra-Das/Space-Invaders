#pragma once

#include <vector>

namespace Enemy
{
	class EnemyController;
	enum class EnemyType;

	class EnemyService
	{
	private:
		std::vector<EnemyController*> enemy_list;
		const float spawn_interval=3.0f;
		float spawn_timer;

		void destroy();
		void updateSpawnTimer();
		void processEnemySpawn();
		EnemyType getRandomEnemyType();
		EnemyController* createEnemy(EnemyType enemy_type);

	public:
		EnemyService();
		virtual ~EnemyService();

		void initialize();
		void update();
		void render();

		EnemyController* SpawnEnemy();
		void destroyEnemy(EnemyController* enemy_controller);
	};
}