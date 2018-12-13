#include "Entity.h"



Entity::Entity(sf::Vector2f size, sf::Vector2f position, bool isDynamic)
{
	body->setSize(size);
	body->setPosition(position);
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
	return Collider(*body);
}
