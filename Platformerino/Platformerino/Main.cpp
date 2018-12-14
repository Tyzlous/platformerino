#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	sf::RenderWindow window(sf::VideoMode(900, 900), "SFML works!");
	window.setVerticalSyncEnabled(true);
	Player* player = new Player(sf::Vector2f(100.0f, 100.0f), sf::Vector2f(10.0f, 10.0f), true);
	sf::RectangleShape shape(sf::Vector2f(100.0f, 100.0f));
	shape.setPosition(sf::Vector2f(200.0f, 200.0f));
	shape.setFillColor(sf::Color::Green);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(612.f, 612.f));
	sf::Clock clock;
	while (window.isOpen())
	{
		float deltaTime = clock.restart().asSeconds();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed)
			{
				//if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				//{
				//	player->Move(sf::Vector2f(0.0f, -1.0f));
				//}
				//if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				//{
				//	player->Move(sf::Vector2f(-1.0f, 0.00f));
				//}
				//if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				//{
				//	player->Move(sf::Vector2f(0.0f, 1.0f));
				//}
				//if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				//{
				//	player->Move(sf::Vector2f(1.0f, 0.0f));
				//}

				//if (player->GetCollider().CheckCollision(col, 0.0f))
				//{
				//	std::cout << "collided\n";
				//}
			}
		}

		window.clear();
		player->Update(deltaTime);
		Collider col = Collider(shape, false);
		Collider col2 = player->GetCollider();
		if (col2.CheckCollision(col, 1.0f))
		{
			std::cout << "collided\n";
		}
		//view.setCenter(sf::Vector2f(player->GetPosition().x + 50.0f, player->GetPosition().y + 50.0f));
		//window.setView(view);
		player->Draw(window);
		window.draw(shape);
		window.display();
	}
	delete player;
}