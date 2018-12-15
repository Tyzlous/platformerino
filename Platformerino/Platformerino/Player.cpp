#include "Player.h"



Player::Player(sf::Vector2f size, sf::Vector2f position, float jumpHeight, bool isDynamic) :
	Entity(size, position, isDynamic), jumpHeight(jumpHeight)
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
	canJump = true;
}


Player::~Player()
{
	delete animation;
}

void Player::Update(float deltaTime)
{
	velocity.x = 0.0f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		velocity.y -= speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		velocity.x -= speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		velocity.y += speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		velocity.x += speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump)
	{
		canJump = false;
		velocity.y = -sqrtf(2.0f * 981.0f * jumpHeight); // initial velocity is equals to 2as squared. 2as = 2 * acceleration * speed/displacement. Square root of 2as is the initial velocity.
		// square root ( 2.0f * gravity * jumpHeight);
	}
	if (velocity.x == 0.0f && velocity.y == 0.0f)
	{
		idle = true;
	}
	else
	{
		idle = false;
		if (velocity.x > 0.0f)
		{
			faceRight = true;
		}
		if (velocity.x < 0.0f)
		{
			faceRight = false;
		}

	}
	velocity.y += 981.0f * deltaTime;
	animation->Update(0, deltaTime, faceRight, idle);
	body->setTextureRect(animation->uvRect);
	body->move(velocity  * deltaTime);
}

void Player::OnCollision(sf::Vector2f direction)
{
	if (direction.x < 0.0f)
	{
		//collision on left etc
		velocity.x = 0.0f;
	}
	else if (direction.x > 0.0f)
	{
		//collision on right
		velocity.x = 0.0f;
	}
	if (direction.y > 0.0f)
	{
		//bottom
		velocity.y = 0.0f;
		canJump = true;
	}
	if (direction.y < 0.0f)
	{
		//top
		velocity.y = 0.0f;
	}
}
