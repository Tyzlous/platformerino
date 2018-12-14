#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Collider.h"
#include "Animation.h"
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
	sf::Texture* texture = new sf::Texture();
	bool isDynamic, faceRight;
};

