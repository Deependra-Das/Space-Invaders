#include "../../Header/UI/UIService.h"
#include "../../Header/Main/GameService.h"

namespace UI
{
	using namespace Main;
	using namespace MainMenu;

	UIService::UIService()
	{
		main_menu_controller = nullptr;

		createControllers();
	}

	UIService::~UIService()
	{
		destroyControllers();
	}

	void UIService::initialize()
	{
		initializeControllers();
	}

	void UIService::update()
	{

	}

	void UIService::render()
	{
		main_menu_controller->render();
	}

	void UIService::createControllers()
	{
		main_menu_controller = new MainMenuUIController();
	}

	void UIService::initializeControllers()
	{
		main_menu_controller->initialize();
	}

	void UIService::destroyControllers()
	{
		delete(main_menu_controller);
		main_menu_controller = nullptr;
	}
}