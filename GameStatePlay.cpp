#include "GameStatePlay.h"
#include "GameState.h"

GameStatePlay::GameStatePlay(Game * game)
{
	this->game = game;
	game->clock.restart();
	createTimer();
}

void GameStatePlay::draw()
{
	game->window.clear(sf::Color::White);
	game->window.draw(board);
	game->window.draw(timer);
	game->window.display();
}

void GameStatePlay::update()
{
	logic.checkWaitingTime(game->clock.getElapsedTime());	

	if (logic.getState() != Logic::END_GAME)
	{
		sf::Time time = game->clock.getElapsedTime();
		timer.setString(std::to_string(time.asSeconds()));
	}	
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
				if (logic.canDiscover())
				{					
					logic.setCard(board.getCard(game->mousePosition), game->clock.getElapsedTime()); //discover card										
				}
			}
		}
		default: break;
		}
	}

	return;
}

void GameStatePlay::createTimer()
{
	timer.setFont(Data::font);
	timer.setCharacterSize(40);
	timer.setFillColor(sf::Color::Black);
	timer.setString("0.00000");
	timer.setStyle(sf::Text::Bold);
	timer.setPosition(sf::Vector2f(880, 80));
}
