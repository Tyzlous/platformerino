#include "Player.h"



Player::Player(sf::Vector2f size, sf::Vector2f position, bool isDynamic) :
	Entity(size, position, isDynamic)
{
	if (texture->loadFromFile(sheetPath + sheetName))
	{
		std::cout << "successfully loaded texture " + sheetPath + " " + sheetName + "\n";
	}
	else
	{
		std::cout << "failed to load texture " + sheetPath + " " + sheetName + "\n";
	}
	animation = new Animation(texture, sf::Vector2u(4, 1), 0.25);
	faceRight = true;
	speed = size.x;
}


Player::~Player()
{
	delete animation;
}

void Player::Update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		movement.y = -(speed * deltaTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		movement.x = -(speed * deltaTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		movement.y = speed * deltaTime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		movement.x = speed * deltaTime;
	}
	if (movement.x == 0.0f && movement.y == 0.0f)
	{
		idle = true;
	}
	else
	{
		idle = false;
		if (movement.x > 0.0f)
		{
			faceRight = true;
		}
		if (movement.x < 0.0f)
		{
			faceRight = false;
		}

	}
	animation->Update(0, deltaTime, faceRight, idle);
	body->setTextureRect(animation->uvRect);
	body->move(movement);
}
