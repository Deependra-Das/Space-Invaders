#include "../../Header/Powerup/PowerupService.h"
#include "../../Header/Powerup/PowerupConfig.h"
#include "../../header/Powerup/Controllers/OutscalBombController.h"
#include "../../header/Powerup/Controllers/TripleLaserController.h"
#include "../../header/Powerup/Controllers/RapidFireController.h"
#include "../../header/Powerup/Controllers/ShieldController.h"

namespace Powerup
{
	using namespace Controller;

	PowerupService::PowerupService()
	{

	}

	PowerupService::~PowerupService()
	{

	}

	PowerupController* PowerupService::createPowerup(PowerupType type)
	{
		switch (type)
		{
		case::Powerup::PowerupType::TRIPPLE_LASER:
			return new TripleLaserController(Powerup::PowerupType::TRIPPLE_LASER);
	
		//case::Powerup::PowerupType::SHIELD:
		//	
		//case::Powerup::PowerupType::RAPID_FIRE:
		//
		//case::Powerup::PowerupType::OUTSCAL_BOMB:
		
		}
	}
	void PowerupService::destroy()
	{

	}


	void PowerupService::initialize()
	{

	}
	void PowerupService::update()
	{

	}

	void PowerupService::render()
	{

	}

	PowerupController* PowerupService::spawnPowerup(PowerupType powerup_type, sf::Vector2f position)
	{
		PowerupController* powerup_controller = createPowerup(powerup_type);
		powerup_controller->initialize(position);
		powerup_list.push_back(powerup_controller);

		return powerup_controller;
	}

	void PowerupService::destroyPowerup(PowerupController* powerup_controller)
	{

	}
}