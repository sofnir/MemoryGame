#include "Data.h"

sf::Font Data::font;
sf::Texture Data::cardsTexture;

Data::Data()
{
	font.loadFromFile("Data/font.ttf");
	cardsTexture.loadFromFile("Data/cards.png");
}

Data::~Data()
{
}
