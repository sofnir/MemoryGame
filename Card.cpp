#include "Card.h"

Card::Card(const sf::IntRect & faceRect) : face(faceRect)
{
	setTextureRect(reverse);
}

void Card::changeState()
{
	if (getTextureRect() == reverse)
	{
		setTextureRect(face);
	}		
	else
	{
		setTextureRect(reverse);
	}		
}
