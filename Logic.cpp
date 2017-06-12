#include "Logic.h"

Logic::Logic()
{
	;
}

Logic::~Logic()
{
	;
}

void Logic::checkWaitingTime(const sf::Time & time)
{
	if (state == WAITING && time.asSeconds() - waitingTime.asSeconds() > 0.5f)
	{
		if (compareCards())
		{
			firstCard->setVisible(false);
			secondCard->setVisible(false);
			pairsCount++;
		}
		else
		{
			firstCard->changeState();
			secondCard->changeState();			
		}

		firstCard = nullptr;
		secondCard = nullptr;

		state = (pairsCount == 10) ? END_GAME : DISCOVERING;					
	}
}

void Logic::setCard(Card * card, const sf::Time & time)
{
	if (firstCard == nullptr)
	{
		firstCard = card;
		firstCard->changeState(); //discover face
	}
	else if (secondCard == nullptr)
	{
		secondCard = card;
		secondCard->changeState();
		waitingTime = time;
		state = WAITING;		
	}	
}

bool Logic::compareCards()
{
	return firstCard->getTextureRect() == secondCard->getTextureRect();		
}
