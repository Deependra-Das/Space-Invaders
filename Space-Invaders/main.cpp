#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

class Player 
{
    private:

    // Private Data Members
    int health = 3;
    sf::Vector2f position = sf::Vector2f(200.0f, 100.0f);
    int movement_speed = 5;
    int player_score = 0;

    public:

    // Public Data Members
    sf::Texture player_texture;
    sf::Sprite player_sprite;

    //Public Getter & Setter functions
    int getScore() {
        return player_score;
    };

    void setScore(int newScore) {
        player_score = newScore;
    };

    //Public Functions
    void takeDamage() 
    {
        cout << "Player took damage."<<endl;
    };

    void move() 
    {
        cout << "Player moved." << endl;
    };

    void shootBullets() 
    {
        cout << "Player shot bullets." << endl;
    };

};

int main() 
{
    //Object Instantiation
    Player player;
    cout << "Player Score: " << player.getScore() << "\n";

    player.setScore(100);
    cout << "Player Modified Score: " << player.getScore() << "\n\n";

    player.takeDamage();
    player.move();
    player.shootBullets();


    // SFML Window
    sf::VideoMode videoMode = sf::VideoMode(800, 600);
    sf::RenderWindow window(videoMode, "SFML Window");

    while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        window.display();
    }

    return 0;

}