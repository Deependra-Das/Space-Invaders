#pragma once

#include "../../header/Enemy/EnemyController.h"

namespace Enemy
{
    namespace Controller
    {
        class ThunderSnakeController : public EnemyController
        {
        private:
            
            const float thundersnake_horizontal_movement_speed = 250.0f;
            float thundersnake_rate_of_fire = 5.0f;

            void move() override;
            void moveLeft();
            void moveRight();
            void moveDiagonalLeft();
            void moveDiagonalRight();

            MovementDirection getInitialMovementDirection();
            void fireBullet() override;

        public:
            ThunderSnakeController(EnemyType type);
            ~ThunderSnakeController();

            void initialize() override;


        };
    }
}

