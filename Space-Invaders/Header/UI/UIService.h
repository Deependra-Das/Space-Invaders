#pragma once

#include "../../Header/UI/MainMenu/MainMenuUIController.h"
#include "../../Header/UI/Interface/IUIController.h"
#include "../../Header/UI/GameplayUI/GameplayUIController.h"
#include "../../Header/UI/SplashScreen/SplashScreenUIController.h"
#include "../../Header/UI/PauseMenu/PauseMenuUIController.h"
#include "../../Header/UI/GameOverMenu/GameOverUIController.h"
#include "../../Header/UI/Instructions/InstructionsUIController.h"

namespace UI
{
	class UIService
	{
	private:
		MainMenu::MainMenuUIController* main_menu_controller;
		GameplayUI::GameplayUIController* gameplay_ui_controller;
		SplashScreen::SplashScreenUIController* splash_screen_ui_controller;
		PauseMenu::PauseMenuUIController* pause_menu_ui_controller;
		GameOverMenu::GameOverUIController* game_over_ui_controller;
		InstructionsUI::InstructionsUIController* instructions_ui_controller;

		void createControllers();
		void initializeControllers();
		void destroyControllers();

		Interface::IUIController* getCurrentUIController();
	

	public:
		UIService();
		~UIService();

		void initialize();
		void update();
		void render();
		void showScreen();
	};
}