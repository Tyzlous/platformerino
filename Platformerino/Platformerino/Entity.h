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
	void SetPosition(sf::Vector2f newPos);
	sf::Vector2f GetPosition();
	void Dynamic(bool onoroff);
	void originMiddle();
protected:
	sf::RectangleShape* body;
	sf::Texture* texture = new sf::Texture();
	bool isDynamic;
	bool faceRight = true;
};

