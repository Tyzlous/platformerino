#pragma once
#include <SFML/Graphics.hpp>
class Collider
{
public:
	Collider(sf::RectangleShape& body, bool isDynamic);
	Collider();
	~Collider();
	void Move(float dx, float dy);
	bool CheckCollision(Collider& other, float push);

	sf::Vector2f GetPosition();
	sf::Vector2f GetHalfSize();
	bool isDynamic;
private:
	sf::RectangleShape& body;
};

