#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML\System.hpp>
#include <Windows.h>
#include <string>


int main()
{
    // Define the video mode (dimensions)
    sf::VideoMode videoMode = sf::VideoMode(800, 600);

    // Create a window object with specific dimensions and a title
    sf::RenderWindow window(videoMode, "SFML Window");

    window.setFramerateLimit(60);

    window.setPosition(sf::Vector2i(100, 100));

    //Creating a game loop to keep window from closing on its own
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Check for window closure
            if (event.type == sf::Event::Closed)
                window.close();
        }


        // Clear the window
        window.clear(sf::Color::Black);

        // Draw a circle
        sf::CircleShape circle(100); // Radius 50
        circle.setFillColor(sf::Color::Green);
        circle.setPosition(280, 50);
        //circle.setPosition(window.getSize().x / 2 - circle.getRadius(), window.getSize().y / 2 - circle.getRadius());
        window.draw(circle);

        // Draw a Rectangle
        sf::RectangleShape rectangle(sf::Vector2f(200, 200));
        rectangle.setFillColor(sf::Color::Red);
        rectangle.setPosition(50, 50);
        window.draw(rectangle);


        // Draw a Triangle
        sf::ConvexShape triangle;
        triangle.setPointCount(3);
        triangle.setFillColor(sf::Color::Blue);

        // define the points
        triangle.setPoint(0, sf::Vector2f(500, 50));
        triangle.setPoint(1, sf::Vector2f(750, 200));
        triangle.setPoint(2, sf::Vector2f(500, 200));
        window.draw(triangle);


        //Texture & Sprite
        sf::Texture outscal_texture;
        outscal_texture.loadFromFile("assets/textures/outscal_logo.png");

        sf::Sprite outscal_sprite;
        outscal_sprite.setTexture(outscal_texture);

        outscal_sprite.setPosition(500, 300); // Position
        outscal_sprite.setRotation(45); // Rotation in degrees
        outscal_sprite.setScale(0.5, 0.5); // Scale factor

        window.draw(outscal_sprite);;

        //Text
        sf::Font font;
        font.loadFromFile("assets/fonts/OpenSans.ttf");
        sf::Text text("SFML is Awesome", font, 50);
        text.setFillColor(sf::Color::White);
        text.setPosition(50, 400); // Position
        window.draw(text);

        // Display whatever you draw
        window.display();
    }

    return 0;

}