#include "Entity.h"



Entity::Entity(sf::Vector2f size, sf::Vector2f position, bool isDynamic) :
	body(new sf::RectangleShape(size))
{
	body->setPosition(position);
	body->setFillColor(sf::Color::White);
	body->setTexture(texture);
	this->isDynamic = isDynamic;
}

Entity::Entity()
{
	body->setSize(sf::Vector2f(10.0f, 10.0f));
	body->setPosition(sf::Vector2f(10.0f, 10.0f));
}


Entity::~Entity()
{
	delete body;
	delete texture;
}

void Entity::Draw(sf::RenderWindow & window)
{
	window.draw(*body);
}

void Entity::Update()
{
}

Collider Entity::GetCollider()
{
	return Collider(*body, isDynamic);
}

void Entity::Move(sf::Vector2f offset)
{
	body->move(offset);
}

sf::Vector2f Entity::GetPosition()
{
	return body->getPosition();
}

void Entity::Dynamic(bool onoroff)
{
	isDynamic = onoroff;
}

void Entity::originMiddle()
{
	body->setOrigin(body->getSize().x * 0.5f, body->getSize().y * 0.5f);
}
