#pragma once
#include "Card.h"
#include "Data.h"
#include "Logic.h" 
 
class Board : public sf::Drawable 
{
public:
	Board();
	~Board();

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
	bool discoverCard(const sf::Vector2f & mousePosition, const Logic & logic);

private:
	Card cards[4][5];

	void createCards();
	void setRandomFaces();
};

