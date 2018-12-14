#include "Platform.h"



Platform::Platform(sf::Vector2f size, sf::Vector2f position) :
	Entity(size, position, false)
{
	if (texture->loadFromFile(texturePath + textureName))
	{
		body->setTextureRect(sf::IntRect(0, 0, 291, 93));
		std::cout << "successfully loaded texture " + texturePath + " " + textureName + "\n";
	}
	else
	{
		std::cout << "failed to load texture " + texturePath + " " + textureName + "\n";
	}
}

Platform::Platform()
{
}


Platform::~Platform()
{
}
