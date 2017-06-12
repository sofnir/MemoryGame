#pragma once
#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "Board.h"
#include "Logic.h"
#include "TextButton.h"

class GameStatePlay : public GameState
{
public:
	GameStatePlay(Game * game);

	virtual void draw() override;
	virtual void update() override;
	virtual void handleInput() override;

private:
	Board board;
	Logic logic;
	sf::Text timer;
	TextButton buttons[2];

	void createTimer();
	void createButtons();
};
