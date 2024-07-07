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

	UIService::UIService()
	{
		main_menu_controller = nullptr;
		gameplay_ui_controller = nullptr;
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
	}

	void UIService::initialize()
	{
		initializeControllers();
	}

	void UIService::initializeControllers()
	{
		TextView::initializeTextView();
		main_menu_controller->initialize();
		gameplay_ui_controller->initialize();
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
		case GameState::MAIN_MENU:
			return main_menu_controller;

		case GameState::GAMEPLAY:
			return gameplay_ui_controller;

		default:
			return nullptr;
		}
	}

	void UIService::destroyControllers()
	{
		delete(main_menu_controller);
		delete(gameplay_ui_controller);
	
	}
}