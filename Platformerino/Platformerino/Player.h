#pragma once
#include "Entity.h"
class Player : public Entity
{
public:
	Player(sf::Vector2f size, sf::Vector2f position, bool isDynamic);
	~Player();
	void Update();
private:
};

