#pragma once
#include "SFML\Graphics.hpp"
#include "Card.h"

class Logic
{
public:
	Logic();
	~Logic();

	enum gameStates { DISCOVERING, WAITING, END_GAME };

	gameStates getState() const { return state; }
	bool canDiscover() const { return state == DISCOVERING; }
	void setState(const gameStates & s) { state = s; }
	void checkWaitingTime(const sf::Time & time);
	void setCard(Card * card, const sf::Time & time);
	void reset();

private:
	gameStates state = DISCOVERING;
	sf::Time waitingTime = sf::Time::Zero;
	Card * firstCard = nullptr;
	Card * secondCard = nullptr;
	int pairsCount = 0;

	bool compareCards();
};

