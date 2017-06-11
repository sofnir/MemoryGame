#pragma once
#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "TextButton.h"
#include "Data.h"

class GameStateMenu : public GameState
{

public:
	GameStateMenu(Game* game);

	virtual void draw() override;
	virtual void update() override;
	virtual void handleInput() override;
	
private:
	sf::Text title;
	TextButton buttons[2];

	void playGame();
	void createTitle();
	void createButtons();
};