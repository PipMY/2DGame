#include <SFML/Graphics.hpp>

void movePlayer(sf::Sprite& playerSprite, sf::Vector2f offset) {
    sf::Vector2f pos = playerSprite.getPosition();
    playerSprite.setPosition({ pos.x + offset.x, pos.y + offset.y });
}

int main()
{
    // create the window

	sf::ContextSettings settings;
	settings.antiAliasingLevel = 8; // Set anti-aliasing level to 8
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "My window", sf::Style::Default, sf::State::Windowed, settings);
    sf::CircleShape circle(50.0f);
    sf::CircleShape octagon(80.0f, 8);
	circle.setFillColor(sf::Color(150,50, 250, 40));
	circle.setPosition({ 375.0f, 275.0f });
	octagon.setFillColor(sf::Color::Red);
	sf::Texture playerTexture("Assets/Player/sheep.png");
    sf::Sprite playerSprite(playerTexture);
	playerSprite.setPosition({ 100.0f, 100.0f });
	playerSprite.setScale({ 2.5f, 2.5f });
	// This means it takes a rectangle starting at (0,0) with width 32 and height 32 of the image later on this will let us choose a different sprite on the sprite sheet in the case that the player would turn left or right
	playerSprite.setTextureRect(sf::IntRect({ 0, 0 }, { 32, 32 }));
	bool isMoving = false;

    
    


    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent())
        {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        // clear the window with black colour
        window.clear(sf::Color::Black);

        isMoving = false;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {
            playerSprite.setTextureRect(sf::IntRect({ 96, 96 }, { 32, 32 }));
			movePlayer(playerSprite, { 1.0f, 0.0f });
			isMoving = true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        {
            playerSprite.setTextureRect(sf::IntRect({ 64, 64 }, { 32, 32 }));
            movePlayer(playerSprite, { -1.0f, 0.0f });
            isMoving = true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        {
            playerSprite.setTextureRect(sf::IntRect({ 32, 32 }, { 32, 32 }));
            movePlayer(playerSprite, { 0.0f, -1.0f });
            isMoving = true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        {
            playerSprite.setTextureRect(sf::IntRect({ 0, 0 }, { 32, 32 }));
            movePlayer(playerSprite, { 0.0f, 1.0f });
            isMoving = true;
        }
        if (!isMoving) {
            playerSprite.setTextureRect(sf::IntRect({ 0, 0 }, { 32, 32 }));
        }
        
        

		// ---------- DRAWING CODE GOES HERE ---------- //

        window.draw(circle);
		window.draw(octagon);
		window.draw(playerSprite);

        // end the current frame
        window.display();
    }
}
