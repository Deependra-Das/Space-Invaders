#include "../../Header/Powerup/PowerupService.h"
#include "../../Header/Powerup/PowerupConfig.h"
#include "../../header/Powerup/PowerupController.h"
#include "../../header/Powerup/Controllers/OutscalBombController.h"
#include "../../header/Powerup/Controllers/TripleLaserController.h"
#include "../../header/Powerup/Controllers/RapidFireController.h"
#include "../../header/Powerup/Controllers/ShieldController.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Powerup
{
	using namespace Controller;
	using namespace Collectible;

	PowerupService::PowerupService()
	{

	}

	PowerupService::~PowerupService()
	{
		destroy();
	}

	PowerupController* PowerupService::createPowerup(PowerupType type)
	{
		switch (type)
		{
		case::Powerup::PowerupType::TRIPPLE_LASER:
			return new TripleLaserController(Powerup::PowerupType::TRIPPLE_LASER);
	
		case::Powerup::PowerupType::SHIELD:
			return new ShieldController(Powerup::PowerupType::SHIELD);
			
		case::Powerup::PowerupType::RAPID_FIRE:
			return new RapidFireController(Powerup::PowerupType::RAPID_FIRE);
		
		case::Powerup::PowerupType::OUTSCAL_BOMB:
			return new OutscalBombController(Powerup::PowerupType::OUTSCAL_BOMB);
		
		}
	}

	void PowerupService::destroy()
	{
		for (int i = 0; i < powerup_list.size(); i++)
		{
			delete(powerup_list[i]);
		}
	}


	void PowerupService::initialize()
	{

	}

	void PowerupService::update()
	{
		for (int i = 0; i < powerup_list.size(); i++)
		{
			powerup_list[i]->update();
		}
	}

	void PowerupService::render()
	{
		for (int i = 0; i < powerup_list.size(); i++)
		{
			powerup_list[i]->render();
		}

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
		powerup_list.erase(std::remove(powerup_list.begin(), powerup_list.end(), powerup_controller), powerup_list.end());

		delete(powerup_controller);
	}
}