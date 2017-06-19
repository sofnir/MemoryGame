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
