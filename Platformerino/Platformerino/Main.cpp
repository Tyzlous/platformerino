#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Platform.h"
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	sf::RenderWindow window(sf::VideoMode(900, 900), "SFML works!");
	window.setVerticalSyncEnabled(true);
	Player* player = new Player(sf::Vector2f(100.0f, 100.0f), sf::Vector2f(10.0f, 10.0f), true);
	Platform* platform = new Platform(sf::Vector2f(680.0f, 50.0f), sf::Vector2f(200.0f, 400.0f));
	sf::RectangleShape background(sf::Vector2f(window.getSize()));
	background.setFillColor(sf::Color::Blue);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(612.f, 612.f));
	sf::Clock clock;
	player->Dynamic(true);
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
				//	placeholder.move(sf::Vector2f(0.0f, -3.0f));
				//}
				//if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				//{
				//	placeholder.move(sf::Vector2f(-3.0f, 0.00f));
				//}
				//if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				//{
				//	placeholder.move(sf::Vector2f(0.0f, 3.0f));
				//}
				//if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				//{
				//	placeholder.move(sf::Vector2f(3.0f, 0.0f));
				//}

				//if (player->GetCollider().CheckCollision(col, 0.0f))
				//{
				//	std::cout << "collided\n";
				//}
			}
		}

		window.clear();
		player->Update(deltaTime);
		Collider col = platform->GetCollider();
		Collider col2 = player->GetCollider();
		if (col2.CheckCollision(col, 1.0f))
		{
			std::cout << "collided\n";
		}
		//view.setCenter(sf::Vector2f(player->GetPosition().x + 50.0f, player->GetPosition().y + 50.0f));
		//window.setView(view);
		window.draw(background);
		platform->Draw(window);
		player->Draw(window);
		window.display();
	}
	delete player;
}