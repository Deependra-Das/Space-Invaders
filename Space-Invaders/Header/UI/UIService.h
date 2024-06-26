#pragma once

#include "MainMenu/MainMenuUIController.h"

namespace UI
{
	class UIService
	{
	private:
		MainMenu::MainMenuUIController* main_menu_controller;

		void createControllers();
		void initializeControllers();
		void destroyControllers();

	public:
		UIService();
		~UIService();

		void initialize();
		void update();
		void render();
	};
}