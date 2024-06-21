#include "../../Header/Graphic/GraphicService.h"

GraphicService::GraphicService()
{
	video_mode = nullptr;
	game_window = nullptr;
}

GraphicService::~GraphicService()
{
	onDestroy();
}

void GraphicService::initialize()
{
	game_window = createGameWindow();
	game_window->setFramerateLimit(frame_rate);
}

void GraphicService::setVideoMode()
{
	video_mode = new sf::VideoMode(game_window_width, game_window_height, sf::VideoMode::getDesktopMode().bitsPerPixel);
}

void GraphicService::onDestroy()
{
	delete(video_mode);
	delete(game_window);
}

void GraphicService::update()
{
}

void GraphicService::render()
{
}

bool GraphicService::isGameWindowOpen() 
{
	return game_window->isOpen();
}

sf::RenderWindow* GraphicService::createGameWindow()
{
	setVideoMode();
	return new sf::RenderWindow(*video_mode, game_window_title);
}

sf::RenderWindow* GraphicService::getGameWindow()
{
	return game_window;
}

sf::Color GraphicService::getWindowColor()
{
	return window_color;
}