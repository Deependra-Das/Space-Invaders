#include "../../Header/UI/UIService.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/UI/UIElement/TextView.h"

namespace UI
{
	using namespace Main;
	using namespace MainMenu;
	using namespace Interface;
	using namespace UIElement;
	using namespace GameplayUI;
	using namespace SplashScreen;
	using namespace PauseMenu;
	using namespace GameOverMenu;
	using namespace InstructionsUI;

	UIService::UIService()
	{
		main_menu_controller = nullptr;
		gameplay_ui_controller = nullptr;
		splash_screen_ui_controller = nullptr;
		pause_menu_ui_controller = nullptr;
		game_over_ui_controller = nullptr;
		instructions_ui_controller = nullptr;
		createControllers();
	}

	UIService::~UIService()
	{
		destroyControllers();
	}

	void UIService::createControllers()
	{
		main_menu_controller = new MainMenuUIController();
		gameplay_ui_controller = new GameplayUIController();
		splash_screen_ui_controller = new SplashScreenUIController();
		pause_menu_ui_controller = new PauseMenuUIController();
		game_over_ui_controller = new GameOverUIController();
		instructions_ui_controller = new InstructionsUIController();
	}

	void UIService::initialize()
	{
		TextView::initializeTextView();
		initializeControllers();
	}

	void UIService::initializeControllers()
	{
		TextView::initializeTextView();
		main_menu_controller->initialize();
		gameplay_ui_controller->initialize();
		splash_screen_ui_controller->initialize();
		pause_menu_ui_controller->initialize();
		game_over_ui_controller->initialize();
		instructions_ui_controller->initialize();
	}

	void UIService::update()
	{
		IUIController* ui_controller = getCurrentUIController();

		if (ui_controller)
		{
			ui_controller->update();
		}
			
	}

	void UIService::render()
	{
		IUIController* ui_controller = getCurrentUIController();

		if (ui_controller)
		{
			ui_controller->render();
		}
	}

	void UIService::showScreen()
	{
		IUIController* ui_controller = getCurrentUIController();

		if (ui_controller)
		{
			ui_controller->show();
		}
	}

	IUIController* UIService::getCurrentUIController()
	{
		switch (GameService::getGameState())
		{
		case GameState::SPLASH_SCREEN:
			return splash_screen_ui_controller;

		case GameState::MAIN_MENU:
			return main_menu_controller;

		case GameState::GAMEPLAY:
			return gameplay_ui_controller;

		case GameState::PAUSE_MENU:
			return pause_menu_ui_controller;

		case GameState::GAME_OVER:
			return game_over_ui_controller;

		case GameState::INSTRUCTIONS:
			return instructions_ui_controller;

		default:
			return nullptr;
		}
	}

	void UIService::destroyControllers()
	{
		delete(main_menu_controller);
		delete(instructions_ui_controller);
		delete(gameplay_ui_controller);
		delete(splash_screen_ui_controller);
		delete(pause_menu_ui_controller);
		delete(game_over_ui_controller);
	}
}