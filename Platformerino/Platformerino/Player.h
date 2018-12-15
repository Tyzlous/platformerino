#pragma once
#include "Entity.h"
class Player : public Entity
{
public:
	Player(sf::Vector2f size, sf::Vector2f position, float jumpHeight, bool isDynamic);
	~Player();
	void Update(float deltaTime);
	void OnCollision(sf::Vector2f direction);
private:
	std::string sheetPath = "resources/spritesheets/";
	std::string sheetName = "soldiersheetfinal.png";
	float speed;
	bool idle;
	Animation* animation;
	sf::Vector2f velocity;
	bool canJump;
	float jumpHeight;
};
