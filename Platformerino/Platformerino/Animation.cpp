#include "Animation.h"





Animation::Animation(sf::Texture * texture, sf::Vector2u imageCount, float switchTime) :
	imageCount(imageCount), switchTime(switchTime), totalTime(0.0f)
{
	currentImage.x = 0;
	uvRect.width = texture->getSize().x / (float)imageCount.x;
	uvRect.height = texture->getSize().y / (float)imageCount.y;
	idleImage = sf::Vector2u(0, 0);
}

Animation::Animation()
{
}

Animation::~Animation()
{
}

void Animation::Update(int row, float deltaTime, bool faceRight, bool idle)
{
	if (idle)
	{
		currentImage.x = idleImage.x;
		currentImage.y = idleImage.y;
	}
	else
	{
		currentImage.y = row;
		totalTime += deltaTime;
		if (totalTime >= switchTime)
		{
			totalTime -= switchTime;
			currentImage.x++;
			if (currentImage.x >= imageCount.x)
			{
				currentImage.x = 0;
			}
		}
	}
	uvRect.top = currentImage.y * uvRect.height;
	if (faceRight)
	{
		uvRect.left = currentImage.x * uvRect.width;
		uvRect.width = abs(uvRect.width);
	}
	else
	{
		uvRect.left = (currentImage.x + 1) * abs(uvRect.width);
		uvRect.width = -abs(uvRect.width);
	}
}

void Animation::SetIdleImage(sf::Vector2u imageNumber)
{
	idleImage = imageNumber;
}
