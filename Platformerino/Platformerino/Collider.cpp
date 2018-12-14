#include "Collider.h"



Collider::Collider(sf::RectangleShape & body, bool isDynamic) :
	body(body)
{
	this->isDynamic = isDynamic;
}

Collider::Collider():
	body(*new sf::RectangleShape)
{
	isDynamic = false;
}

Collider::~Collider()
{
}

void Collider::Move(float dx, float dy)
{
	body.move(dx, dy);
}

bool Collider::CheckCollision(Collider & other, float push) //This AABB collision only works with middle origins or using middle positions
{
	sf::Vector2f otherPosition = other.GetPosition();
	sf::Vector2f otherHalfSize = other.GetHalfSize();
	sf::Vector2f otherMiddlePosition = sf::Vector2f(other.body.getGlobalBounds().left + otherHalfSize.x, other.body.getGlobalBounds().top + otherHalfSize.y);
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();
	sf::Vector2f thisMiddlePosition = sf::Vector2f(body.getGlobalBounds().left + thisHalfSize.x, body.getGlobalBounds().top + thisHalfSize.y);
	
	float deltaX = otherMiddlePosition.x - thisMiddlePosition.x; // Delta means it's that axis' distance between positions
	float deltaY = otherMiddlePosition.y - thisMiddlePosition.y;
	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x); // what value is left after taking the ABSOLUTE value of delta minus the half sizes of the rectangles?
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);
	if (intersectX < 0.0f && intersectY < 0.0f) // Check if that value is less than zero on both axises to determine an intersection
	{
		if (other.isDynamic)
		{
			push = std::min(std::max(push, 0.0f), 1.0f); // clamping the push value to be between 0 and 1
		}
		else
		{
			push = 0.0f;
		}
		if (intersectX > intersectY) // check which axis is largest to determine which axis to move by. -1 is larger than -2. So if X is intersecting with a value of -1, it has priority over the y that intersects with a value of -2.
		{
			if (deltaX > 0.0f) // check if the original delta is a positive or negative value to know whether to move positively or negatively, AKA right or left.
			{
				Move(intersectX * (1.0f - push), 0.0f); // Moves the player object by the amount it was intersecting positively, to effectively undo the intersection. Multiplied by 1 minus push, this way we can achieve a balance between the movement of both obstacle and player object to give an illusion of weight behind the obstacle.
				other.Move(-intersectX * push, 0.0f); // Moves the obstacle by the intersection value, but invertedly. This gives the effect that the player object is pushing the obstacle in the direction it is moving. Since if there is a push value, we split movement needed to undo intersection between both objects, otherwise only the player object will be pushed the opposite way it was heading.
			}
			else
			{
				Move(-intersectX * (1.0f - push), 0.0f); // Same as above, but the math is inverted because the player object was a negative value of distance from the obstacle. Which means the player is on the left side in this case.
				other.Move(intersectX * push, 0.0f);
			}
		}
		else // If the X axis intersection value isn't larger than the Y, or the values are equal, it will move by the Y axis.
		{
			if (deltaY > 0.0f) // Same as above if/else statements, except now we have determined that the player needs to be moved along the Y axis either positively or negatively, which is down and up in this case.
			{
				Move(0.0f, intersectY * (1.0f - push)); // Same as above, we determine how much to move the player to undo intersection.
				other.Move(0.0f, -intersectY * push); // And how much to move the obstacle, to undo intersection.
			}
			else
			{
				Move(0.0f, -intersectY * (1.0f - push));
				other.Move(0.0f, intersectY * push);
			}
		}
		return true;
	}
	return false;
}

sf::Vector2f Collider::GetPosition()
{
	return sf::Vector2f(body.getPosition().x, body.getPosition().y);
}

sf::Vector2f Collider::GetHalfSize()
{
	return sf::Vector2f(body.getSize().x * 0.5f, body.getSize().y * 0.5f);
}

void Collider::Dynamic(bool onoroff)
{
	isDynamic = onoroff;
}
