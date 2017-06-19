#pragma once
#include "GameState.h"
#include "Board.h"
#include "Logic.h"
#include "TextButton.h"
#include <SFML\Window\Event.hpp>
#include <SFML\Graphics\Text.hpp>

class GameStatePlay : public GameState
{
public:
	GameStatePlay(Game * game);

	void draw() override;
	void update() override;
	void handleInput() override;

private:
	Board board;
	Logic logic;
	sf::Text timer;
	TextButton buttons[2];

	void createTimer();
	void createButtons();
};
