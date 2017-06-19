#pragma once
#include "GameState.h"
#include "TextButton.h"
#include "Data.h"
#include <SFML\Graphics\Text.hpp>
#include <SFML\Window\Event.hpp>

class GameStateMenu : public GameState
{

public:
	GameStateMenu(Game* game);

	void draw() override;
	void update() override;
	void handleInput() override;
	
private:
	sf::Text title;
	TextButton buttons[2];

	void playGame();
	void createTitle();
	void createButtons();
};
