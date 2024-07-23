#pragma once

#include <SFML/Graphics.hpp>
#include "../../Header/UI/Interface/IUIController.h"
#include "../../Header/UI/UIElement/ImageView.h"
#include "../../Header/UI/UIElement/ButtonView.h"

namespace UI
{
	namespace PauseMenu
	{

		class PauseMenuUIController : public Interface::IUIController
		{
		private:

			const float pause_image_width = 692.f;
			const float pause_image_height = 120.f;

			const float button_height = 72.0f;
			const float button_width = 320.0f;

			const float pause_image_y_position = 400.f;
			const float continue_button_y_position = 700.f;
			const float menu_button_y_position = 800.f;

			const float background_image_alpha = 90.0f;

			UIElement::ImageView* background_image;
			UIElement::ImageView* pause_image_view;
			UIElement::ButtonView* continue_button;
			UIElement::ButtonView* menu_button;

			void createImage();
			void createButtons();
			void initializeBackgroundImage();
			void initializePauseImage();
			void initializeButtons();
			void registerButtonCallback();

			void ContinueButtonCallback();
			void MenuButtonCallback();
			void destroy();

		public:
			PauseMenuUIController();
			~PauseMenuUIController();

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;

		};
	}
}