#pragma once
#include <SFML\Graphics.hpp>

class Data
{
public:
	Data();
	~Data();

	static sf::Font font;
};

namespace Color
{
	const sf::Color Blue(69, 159, 212);
	const sf::Color Green(44, 191, 164);
	const sf::Color Grey(22, 27, 32);
	const sf::Color Red(255, 65, 54);
	const sf::Color Silver(221, 221, 221);
}

namespace Config
{
	const sf::Vector2u windowSize(800, 600);
}
