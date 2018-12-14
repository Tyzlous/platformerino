#pragma once
#include <SFML/Graphics.hpp>
class Animation
{
public:
	Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	Animation();
	~Animation();
	void Update(int row, float deltaTime);
	sf::IntRect uvRect;
private:
	sf::Vector2u imageCount, currentImage;
	float totalTime, switchTime;

};

