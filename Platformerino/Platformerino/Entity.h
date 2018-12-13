#pragma once
#include <SFML/Graphics.hpp>
#include "Collider.h"
class Entity
{
public:
	Entity(sf::Vector2f size, sf::Vector2f position, bool isDynamic);
	Entity();
	virtual ~Entity();
	void Draw(sf::RenderWindow& window);
	virtual void Update();
	Collider GetCollider();
	void Move(sf::Vector2f offset);
	sf::Vector2f GetPosition();
protected:
	sf::RectangleShape* body = new sf::RectangleShape();
	bool isDynamic;
};

