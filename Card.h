#pragma once
#include <SFML\Graphics.hpp>

class Card : public sf::Sprite
{
public:
	Card(const sf::IntRect & faceRect = sf::IntRect(0, 100, 100, 100));
	~Card();

	void setFaceRect(const sf::IntRect & f) { face = f; }
	void changeState(); //cover / discover
	bool isCover() const { return getTextureRect() == reverse; }
	bool isHover(const sf::Vector2f & mousePosition) const { return getGlobalBounds().contains(mousePosition); }

private:
	const sf::IntRect reverse = sf::IntRect(0, 0, 100, 100);
	sf::IntRect face;
};
