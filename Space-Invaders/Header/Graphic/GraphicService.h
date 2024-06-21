#pragma once

#include <SFML/Graphics.hpp>

class GraphicService 
{
private:

	//private member variables
	const std::string game_window_title="Space Invaders";

	const int game_window_width = 800;
	const int game_window_height = 600;
	const int frame_rate = 60;
	const sf::Color window_color = sf::Color::Blue;
	sf::VideoMode* video_mode;
	sf::RenderWindow* game_window;

	//private member functions
	void setVideoMode();
	void onDestroy();

public:

	//public constructor & destructor
	GraphicService();
	~GraphicService();

	//public member functions
	void initialize();
	void update(); 
	void render();
	bool isGameWindowOpen();

	sf::RenderWindow* createGameWindow();
	sf::RenderWindow* getGameWindow();
	sf::Color getWindowColor();

};