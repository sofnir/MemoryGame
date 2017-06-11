#pragma once
#include <SFML\Graphics.hpp>
#include "Data.h"

class TextButton : public sf::Text
{
public:
	TextButton();
	TextButton(const sf::String &string, const sf::Font &font, unsigned int characterSize = 30);
	~TextButton();

	void update(const sf::Vector2f &mousePosition);
	bool isHover(const sf::Vector2f &mousePosition) const;
	void setCharacterSize(unsigned int size);
	void setFillColor(const sf::Color &color);
	void setHoverColor(const sf::Color &color);
	void setResizing(bool resize);

private:
	bool resizing;
	unsigned int basicCharacterSize;
	sf::Color basicColor;
	sf::Color newColor;
};

