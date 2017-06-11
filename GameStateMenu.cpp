#include "GameStateMenu.h"
#include "GameStatePlay.h"
#include "GameState.h"

GameStateMenu::GameStateMenu(Game* game) 
{
	this->game = game; 
}

void GameStateMenu::playGame()
{
	game->pushState(new GameStatePlay(game));
}

void GameStateMenu::draw()
{
	game->window.clear(sf::Color::White);
	game->window.display();
}

void GameStateMenu::update()
{
	;
}

void GameStateMenu::handleInput()
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
				game->window.close();					
			if (event.key.code == sf::Keyboard::Space)
				playGame();
			break;
		}
		case sf::Event::MouseButtonPressed:
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				;
			}
		}
		default:
			break;
		}
	}

	return;
}
