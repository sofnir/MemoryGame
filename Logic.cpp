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
	if (state == WAITING && time.asSeconds() - waitingTime.asSeconds() > 0.3f)
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
	if (card != nullptr)
	{
		if (firstCard == nullptr)
		{
			firstCard = card;
			firstCard->changeState(); //discover face
		}
		else if (secondCard == nullptr && card != firstCard)
		{
			secondCard = card;
			secondCard->changeState();
			waitingTime = time;
			state = WAITING;
		}
	}	
}

void Logic::reset()
{
	state = DISCOVERING;
	pairsCount = 0;
}

bool Logic::compareCards()
{
	return firstCard->getTextureRect() == secondCard->getTextureRect();		
}
