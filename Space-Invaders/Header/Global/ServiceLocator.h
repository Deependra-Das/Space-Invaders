#pragma once

#include "../../Header/Graphic/GraphicService.h"
#include "../../Header/Event/EventService.h"
#include "../../Header/Player/PlayerService.h"
#include "../../Header/Time/TimeService.h"
#include "../../Header/UI/UIService.h"
#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Gameplay/GameplayService.h"
#include "../../Header/Element/ElementService.h"
#include "../../Header/Sound/SoundService.h"
#include "../../Header/Bullet/BulletService.h"
#include "../../Header/Powerup/PowerupService.h"
#include "../../Header/Collision/CollisionService.h"

namespace Global
{
    class ServiceLocator
    {
    private:

        // Private Constructor and Destructor:
        ServiceLocator();
        ~ServiceLocator();

        //private member variables
        Graphic::GraphicService* graphic_service;
        Time::TimeService* time_service;
        Event::EventService* event_service;
        Player::PlayerService* player_service;
        UI::UIService* ui_service;
        Enemy::EnemyService* enemy_service;
        Gameplay::GameplayService* gameplay_service;
        Element::ElementService* element_service;
        Sound::SoundService* sound_service;
        Bullet::BulletService* bullet_service;
        Powerup::PowerupService* powerup_service;
        Collision::CollisionService* collision_service;

        // Private Methods:
        void createServices(); 
        void clearAllServices(); 		

    public:

        // Public Methods:
        static ServiceLocator* getInstance();  

        void initialize(); 			
        void update(); 				
        void render(); 				

        Graphic::GraphicService* getGraphicService();
        Event::EventService* getEventService();
        Player::PlayerService* getPlayerService();
        Time::TimeService* getTimeService();
        UI::UIService* getUIService();
        Enemy::EnemyService* getEnemyService();
        Gameplay::GameplayService* getGameplayService();
        Element::ElementService* getElementService();
        Sound::SoundService* getSoundService();
        Bullet::BulletService* getBulletService();
        Powerup::PowerupService* getPowerupService();
        Collision::CollisionService* getCollisionService();

        void deleteServiceLocator();
    };
}