#pragma once
#include <SFML\Graphics\Font.hpp>
#include <SFML\Graphics\Sprite.hpp>

class Data
{
public:
	Data();

	static sf::Font font;
	static sf::Texture cardsTexture;
	static sf::Sprite background;

private:
	sf::Texture backgroundTexture;

	void createBackground();
};

namespace Color
{
	const sf::Color Brown(139, 71, 38);
	const sf::Color Blue(69, 159, 212);
	const sf::Color Green(44, 191, 164);
	const sf::Color Grey(22, 27, 32);
	const sf::Color Red(255, 65, 54);
	const sf::Color Silver(221, 221, 221);
	const sf::Color Navy(0, 31, 63);
}

namespace Config
{
	const sf::Vector2u windowSize(660, 680);
}
