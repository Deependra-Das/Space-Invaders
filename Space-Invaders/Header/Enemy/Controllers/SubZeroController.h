#pragma once

#include "../../header/Enemy/EnemyController.h"

namespace Enemy
{
    namespace Controller
    {
        class SubZeroController : public EnemyController
        {
        private:
            float vertical_movement_speed = 100.0f;
            float subzero_rate_of_fire = 2.0f; 

            void move() override;
            void moveDown();

            void fireBullet() override;

        public:
            SubZeroController(EnemyType type, Entity::EntityType owner_type);
            ~SubZeroController();

            void initialize() override;

        };
    }
}
