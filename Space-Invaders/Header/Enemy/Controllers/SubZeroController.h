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

            void move() override;
            void moveDown();

        public:
            SubZeroController(EnemyType type);
            ~SubZeroController();

            void initialize() override;

        };
    }
}
