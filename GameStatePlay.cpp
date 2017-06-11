#include "GameStatePlay.h"
#include "GameState.h"

GameStatePlay::GameStatePlay(Game * game)
{
	this->game = game;
}

void GameStatePlay::draw()
{
	game->window.clear(sf::Color::Black);
	game->window.display();
}

void GameStatePlay::update()
{
	;
}

void GameStatePlay::handleInput()
{
	sf::Event event;

	while (game->window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
		{
			game->window.close();
			break;
		}
		case sf::Event::KeyPressed:
		{						
			if (event.key.code == sf::Keyboard::Escape)
			{
				game->popState();
				return;
			}
			break;
		}
		case sf::Event::MouseButtonPressed:
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{				
				;
			}
		}
		default: break;
		}
	}

	return;
}
