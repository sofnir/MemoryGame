#include "Logic.h"

Logic::Logic()
{
	;
}

void Logic::checkWaitingTime(const sf::Time & time)
{
	if (state == gameStates::WAITING && time.asSeconds() - waitingTime.asSeconds() > 0.3f)
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
		state = (pairsCount == 10) ? gameStates::END_GAME : gameStates::DISCOVERING;
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
			state = gameStates::WAITING;
		}
	}	
}

void Logic::reset()
{
	state = gameStates::DISCOVERING;
	pairsCount = 0;
}

bool Logic::compareCards()
{
	return firstCard->getTextureRect() == secondCard->getTextureRect();		
}
