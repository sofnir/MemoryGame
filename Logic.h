#pragma once
#include "Card.h"
#include <SFML\System\Time.hpp>

class Logic
{
public:
	Logic();

	enum class gameStates { DISCOVERING, WAITING, END_GAME };

	gameStates getState() const { return state; }
	bool canDiscover() const { return state == gameStates::DISCOVERING; }
	void setState(const gameStates & s) { state = s; }
	void checkWaitingTime(const sf::Time & time);
	void setCard(Card * card, const sf::Time & time);
	void reset();

private:
	gameStates state = gameStates::DISCOVERING;
	sf::Time waitingTime = sf::Time::Zero;
	Card * firstCard = nullptr;
	Card * secondCard = nullptr;
	int pairsCount = 0;

	bool compareCards();
};

