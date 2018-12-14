#pragma once
#include "Entity.h"
class Platform : public Entity
{
public:
	Platform(sf::Vector2f size, sf::Vector2f position);
	Platform();
	~Platform();
private:
	std::string texturePath = "resources/platformtextures/";
	std::string textureName = "platform1.jpg";
};

