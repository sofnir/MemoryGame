#pragma once
#include <SFML/Graphics.hpp>
#include "GameState.h"

class GameStateMenu : public GameState
{

public:
	GameStateMenu(Game* game);

	virtual void draw() override;
	virtual void update() override;
	virtual void handleInput() override;
	
private:
	
	void playGame();
};
