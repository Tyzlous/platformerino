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
	void Dynamic(bool onoroff);
private:
	sf::RectangleShape& body;
	sf::RectangleShape debug;
	bool isDynamic;
};

