#pragma once
#include <SFML/Graphics.hpp>
#include "GameState.h"

class GameStatePlay : public GameState
{
public:
	GameStatePlay(Game * game);

	virtual void draw() override;
	virtual void update() override;
	virtual void handleInput() override;
};