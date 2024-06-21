#pragma once

#include <SFML/Graphics.hpp>

class PlayerController;

class PlayerView
{
private:

	const sf::String player_texture_path = "assets/textures/player_ship.png";

	sf::Texture player_texture;
	sf::Sprite player_sprite;

	const float player_sprite_width = 60.f;
	const float player_sprite_height = 60.f;

	sf::RenderWindow* game_window;
	PlayerController* player_controller;

	void initializePlayerSprite();
	void scalePlayerSprite();

public:
	PlayerView();
	~PlayerView();

	void initialize(PlayerController* controller);
	void update();
	void render();
};