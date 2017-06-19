#pragma once
#include "Card.h"
#include "Data.h"
#include "Logic.h" 
#include <SFML\Graphics\RenderTarget.hpp> 

class Board : public sf::Drawable 
{
public:
	Board();

	void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
	Card * getCard(const sf::Vector2f & mousePosition);
	void reset();

private:
	Card cards[4][5];

	void createCards();
	void setRandomFaces();
};

