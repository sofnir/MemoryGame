#include "Data.h"

sf::Font Data::font;
sf::Texture Data::cardsTexture;
sf::Sprite Data::background;

Data::Data()
{
	font.loadFromFile("Data/font.ttf");
	cardsTexture.loadFromFile("Data/cards.png");
	backgroundTexture.loadFromFile("Data/background.png");
	createBackground();
}

void Data::createBackground()
{	
	backgroundTexture.setSmooth(true);
	backgroundTexture.setRepeated(true);
	background.setTexture(backgroundTexture);
	background.setTextureRect(sf::IntRect(0, 0, Config::windowSize.x, Config::windowSize.y));
}
