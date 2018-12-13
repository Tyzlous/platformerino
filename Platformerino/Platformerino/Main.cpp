#include <iostream>
#include <SFML/Graphics.hpp>
bool CheckCollision(sf::RectangleShape& obstacle, sf::RectangleShape& player, float push)
{
	sf::Vector2f obstaclePosition = obstacle.getPosition();
	sf::Vector2f obstacleHalfSize = obstacle.getSize() * 0.5f;
	sf::Vector2f playerPosition = player.getPosition();
	sf::Vector2f playerHalfSize = player.getSize() * 0.5f;

	float deltaX = obstaclePosition.x - playerPosition.x; // Delta means it's that axis' distance between positions
	float deltaY = obstaclePosition.y - playerPosition.y;
	float intersectX = abs(deltaX) - (obstacleHalfSize.x + playerHalfSize.x); // what value is left after taking the ABSOLUTE value of delta minus the half sizes of the rectangles?
	float intersectY = abs(deltaY) - (obstacleHalfSize.y + playerHalfSize.y);

	if (intersectX < 0.0f && intersectY < 0.0f) // Check if that value is less than zero on both axises to determine an intersection
	{
		push = std::min(std::max(push, 0.0f), 1.0f); // clamping the push value to be between 0 and 1
		if (intersectX > intersectY) // check which axis is largest to determine which axis to move by. -1 is larger than -2. So if X is intersecting with a value of -1, it has priority over the y that intersects with a value of -2.
		{
			if (deltaX > 0.0f) // check if the original delta is a positive or negative value to know whether to move positively or negatively, AKA right or left.
			{
				player.move(intersectX * (1.0f - push), 0.0f); // Moves the player object by the amount it was intersecting positively, to effectively undo the intersection. Multiplied by 1 minus push, this way we can achieve a balance between the movement of both obstacle and player object to give an illusion of weight behind the obstacle.
				obstacle.move(-intersectX * push, 0.0f); // Moves the obstacle by the intersection value, but invertedly. This gives the effect that the player object is pushing the obstacle in the direction it is moving. Since if there is a push value, we split movement needed to undo intersection between both objects, otherwise only the player object will be pushed the opposite way it was heading.
			}
			else
			{
				player.move(-intersectX * (1.0f - push), 0.0f); // Same as above, but the math is inverted because the player object was a negative value of distance from the obstacle. Which means the player is on the left side in this case.
				obstacle.move(intersectX * push, 0.0f);
			}
		}
		else // If the X axis intersection value isn't larger than the Y, or the values are equal, it will move by the Y axis.
		{
			if (deltaY > 0.0f) // Same as above if/else statements, except now we have determined that the player needs to be moved along the Y axis either positively or negatively, which is down and up in this case.
			{
				player.move(0.0f, intersectY * (1.0f - push)); // Same as above, we determine how much to move the player to undo intersection.
				obstacle.move(0.0f, -intersectY * push);  // And how much to move the obstacle, to undo intersection.
			}
			else
			{
				player.move(0.0f, -intersectY * (1.0f - push)); 
				obstacle.move(0.0f, intersectY * push); 
			}
		}
		return true;
	}
	return false;
}
int main()
{
	sf::RenderWindow window(sf::VideoMode(900, 900), "SFML works!");
	window.setVerticalSyncEnabled(true);
	sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));
	sf::RectangleShape shape(sf::Vector2f(100.0f, 100.0f));
	shape.setPosition(sf::Vector2f(200.0f, 200.0f));
	shape.setFillColor(sf::Color::Green);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(512.f, 512.f));
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
					player.move(sf::Vector2f(0.0f, -1.0f));
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				{
					player.move(sf::Vector2f(-1.0f, 0.00f));
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				{
					player.move(sf::Vector2f(0.0f, 1.0f));
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				{
					player.move(sf::Vector2f(1.0f, 0.0f));
				}
				if(CheckCollision(shape, player, 1.0f))
				{
					std::cout << "collided\n";
				}
			}
		}

		window.clear();
		view.setCenter(sf::Vector2f(player.getPosition().x + 50.0f, player.getPosition().y + 50.0f));
		window.setView(view);
		window.draw(player);
		window.draw(shape);
		window.display();
	}
}