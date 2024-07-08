#pragma once

#include "../../Header/AnimationSystem/AnimationSystemConfig.h"
#include "../../Header/UI/UIElement/ImageView.h"

namespace Animation
{
	class AnimationSystem
	{
	private:
		AnimationSystemConfig animation_system_config;
		sf::Vector2f animation_position;
		UI::UIElement::ImageView* animation_image;
		sf::Clock clock;
		sf::Time frame_time;
		int current_frame;
		
		void createUIElements();
		void initializeImage();

	public:
		AnimationSystem(AnimationSystemConfig config);
		~AnimationSystem();

		void initialize(sf::Vector2f position);
		void update();
		void render();
		void destroy();
	};
}