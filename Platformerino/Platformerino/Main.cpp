#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(900, 900), "SFML works!");
	window.setVerticalSyncEnabled(true);
	sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));
	sf::RectangleShape shape(sf::Vector2f(100.0f, 100.0f));
	shape.setPosition(sf::Vector2f(200.0f, 200.0f));
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				{
					player.move(sf::Vector2f(0.0f, -0.3f));
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				{
					player.move(sf::Vector2f(-0.3f, 0.00f));
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				{
					player.move(sf::Vector2f(0.0f, 0.3f));
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				{
					player.move(sf::Vector2f(0.3f, 0.0f));
				}
			}
		}

		window.clear();
		window.draw(player);
		window.draw(shape);
		window.display();
	}
}