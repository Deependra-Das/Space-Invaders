#include <iostream>
#include <SFML/Graphics.hpp>
#include "Header/GameService.h"
using namespace std;

#pragma region Old Code 1

/*
class Player 
{
    private:

    // Private Data Members
    int health = 3;
    sf::Vector2f position = sf::Vector2f(350.0f, 200.0f);
    int movement_speed = 1;
    int player_score = 0;

    public:

    // Public Data Members
    sf::Texture player_texture;
    sf::Sprite player_sprite;

    // Public Getter & Setter functions
    int getScore() {
        return player_score;
    };

    void setScore(int newScore) {
        player_score = newScore;
    };

    sf::Vector2f getPosition() {
        return position;
    };

    void setScore(sf::Vector2f newPosition) {
        position = newPosition;
    };

    int getMovementSpeed() {
        return movement_speed;
    };

    // Public Functions
    void takeDamage() 
    {
        cout << "Player took damage."<<endl;
    };

    void move(float offsetX)
    {
        position.x += offsetX;
    };

    void shootBullets() 
    {
        cout << "Player shot bullets." << endl;
    };

};
*/

#pragma endregion

int main() 
{
    // Object Instantiation
    #pragma region Old Code 2

    /*
    // For SFML Window
    sf::VideoMode videoMode = sf::VideoMode(800,600);
    sf::RenderWindow window(videoMode, "Space Invaders");

    Player player;

    player.player_texture.loadFromFile("assets/textures/player_ship.png");
    player.player_sprite.setTexture(player.player_texture);


    while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
                
        }

        // Handling keyboard input
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) 
        {
            player.move(-1.0f * player.getMovementSpeed());
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
        {
            player.move(1.0f * player.getMovementSpeed());
        }


        window.clear(sf::Color::Black);

        player.player_sprite.setPosition(player.getPosition());

        window.draw(player.player_sprite);

        window.display();
    }

    return 0;
    */

    #pragma endregion

    GameService* game_service = new GameService();

    game_service->ignite();

    while (game_service->isRunning())
    {
        game_service->update();
        game_service->render();
    }

}