#pragma once

#include "../../Header/UI/MainMenu/MainMenuUIController.h"
#include "../../Header/UI/Interface/IUIController.h"
#include "../../Header/UI/GameplayUI/GameplayUIController.h"

namespace UI
{
	class UIService
	{
	private:
		MainMenu::MainMenuUIController* main_menu_controller;
		GameplayUI::GameplayUIController* gameplay_ui_controller;
		void createControllers();
		void initializeControllers();
		void destroyControllers();

		Interface::IUIController* getCurrentUIController();
		void showScreen();

	public:
		UIService();
		~UIService();

		void initialize();
		void update();
		void render();
	};
}