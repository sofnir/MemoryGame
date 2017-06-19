#include "GameStatePlay.h"
#include "GameState.h"

GameStatePlay::GameStatePlay(Game * game)
{
	this->game = game;

	game->clock.restart();
	createTimer();
	createButtons();
}

void GameStatePlay::draw()
{
	game->window.clear(sf::Color::White);
	game->window.draw(Data::background);
	game->window.draw(board);
	game->window.draw(timer);

	for (auto & button : buttons)
	{
		game->window.draw(button);
	}

	game->window.display();
}

void GameStatePlay::update()
{
	logic.checkWaitingTime(game->clock.getElapsedTime());	

	if (logic.getState() != Logic::gameStates::END_GAME)
	{
		sf::Time time = game->clock.getElapsedTime();
		timer.setString(std::to_string(time.asSeconds()));
	}	

	for (auto & button : buttons)
	{
		button.update(game->mousePosition);
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
			game->window.close();
			break;		
		case sf::Event::KeyPressed:					
			if (event.key.code == sf::Keyboard::Escape)
			{
				game->popState();
				return;
			}
			break;		
		case sf::Event::MouseButtonPressed:		
			if (event.mouseButton.button == sf::Mouse::Left)
			{								
				if (logic.canDiscover())
				{
					logic.setCard(board.getCard(game->mousePosition), game->clock.getElapsedTime()); //discover card	
				}					

				if (buttons[0].isHover(game->mousePosition))
				{
					board.reset();
					logic.reset();
					game->clock.restart();
				}
				else if (buttons[1].isHover(game->mousePosition))
				{
					game->popState();
					return;
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
	timer.setCharacterSize(60);
	timer.setFillColor(Color::Brown);
	timer.setString("00.000000");
	timer.setOrigin(timer.getGlobalBounds().width / 2.0f, timer.getGlobalBounds().height / 2.0f);
	timer.setPosition(sf::Vector2f(Config::windowSize.x / 2.0f, 35));
}

void GameStatePlay::createButtons()
{
	buttons[0] = TextButton("Play again", Data::font, 55);
	buttons[1] = TextButton("Back", Data::font, 55);

	for (int i = 0; i < 2; i++)
	{		
		buttons[i].setFillColor(Color::Grey);
		buttons[i].setHoverColor(Color::Brown);
		buttons[i].setOrigin(sf::Vector2f(buttons[i].getGlobalBounds().width / 2.0f, buttons[i].getGlobalBounds().height / 2.0f));
		buttons[i].setPosition(sf::Vector2f(Config::windowSize.x / 4.0f + Config::windowSize.x / 2.0f * i, Config::windowSize.y - 60.0f));
	}
}
