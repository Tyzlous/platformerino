#pragma once
#include "Entity.h"
class Player : public Entity
{
public:
	Player(sf::Vector2f size, sf::Vector2f position, bool isDynamic);
	~Player();
	void Update(float deltaTime);
private:
	std::string sheetPath = "resources/spritesheets/";
	std::string sheetName = "soldiersheetfinal.png";
	float speed;
	bool idle;
	Animation* animation;
};
