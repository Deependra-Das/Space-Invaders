#include "../../header/Powerup/Controllers/TripleLaserController.h"
#include "../../header/Global/ServiceLocator.h"

namespace Powerup
{
    namespace Controller
    {
        using namespace Global;

        TripleLaserController::TripleLaserController(PowerupType type) : PowerupController(type)
        {
        }

        TripleLaserController::~TripleLaserController()
        {
        }

        void TripleLaserController::onCollected()
        {
        }

        void TripleLaserController::applyPowerup()
        {
            ServiceLocator::getInstance()->getEnemyService()->reset();
        }
    }
}