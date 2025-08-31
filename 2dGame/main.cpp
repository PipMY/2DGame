#include <SFML/Graphics.hpp>

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

		// ---------- DRAWING CODE GOES HERE ---------- //

        window.draw(circle);
		window.draw(octagon);

        // end the current frame
        window.display();
    }
}