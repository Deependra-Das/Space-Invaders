#pragma once

#include "../../Header/Collectible/ICollectible.h"
#include "../../Header/Powerup/PowerupConfig.h"

namespace Powerup
{
	class PowerupView;
	class PowerupModel;
	enum class PowerupType;

	class PowerupController:public Collectible::ICollectible
	{
	private:
		PowerupView* powerup_view;
		PowerupModel* powerup_model;

		void updatePowerupPosition();
		void handleOutOfBounds();

	public:
		PowerupController(PowerupType power_type);
		virtual ~PowerupController();

		void initialize(sf::Vector2f position) override;
		void update() override;
		void render() override;

		sf::Vector2f getCollectiblePosition() override;
		void onCollected() override;

		PowerupType getPowerupType();
	};
}