#include "../../Header/Player/PlayerService.h"
#include "../../Header/Player/PlayerController.h"
#include "../../Header/Entity/EntityConfig.h"

namespace Player
{
	PlayerService::PlayerService()
	{
		player_controller = new PlayerController(Entity::EntityType::PLAYER);
	}

	PlayerService::~PlayerService()
	{
		delete (player_controller);
	}

	void PlayerService::initialize()
	{
		player_controller->initialize();
	}

	void PlayerService::update()
	{
		player_controller->update();
	}

	void PlayerService::render()
	{
		player_controller->render();
	}

	void PlayerService::enableShield()
	{
		player_controller->enableShield();
	}

	void PlayerService::enableRapidFire()
	{
		player_controller->enableRapidFire();
	}

	void PlayerService::enableTrippleLaser()
	{
		player_controller->enableTrippleLaser();
	}

	void PlayerService::reset()
	{
		player_controller->reset();
	}
}