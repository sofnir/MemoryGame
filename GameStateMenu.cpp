#include "GameStateMenu.h"
#include "GameStatePlay.h"
#include "GameState.h"

GameStateMenu::GameStateMenu(Game* game) 
{
	this->game = game; 

	createButtons();
	createTitle();
}

void GameStateMenu::playGame()
{
	game->pushState(new GameStatePlay(game));
}

void GameStateMenu::createTitle()
{
	title.setString("Memory Game");
	title.setFillColor(Color::Grey);
	title.setCharacterSize(80);
	title.setFont(Data::font);
	title.setStyle(sf::Text::Bold);
	title.setPosition(Config::windowSize.x / 2.0f - title.getGlobalBounds().width / 2.0f, 50.0f);
}

void GameStateMenu::createButtons()
{
	buttons[0] = TextButton("Play", Data::font, 60);
	buttons[1] = TextButton("Exit", Data::font, 60);

	for (int i = 0; i < 2; i++)
	{	
		buttons[i].setOrigin(buttons[i].getGlobalBounds().width / 2.0f, buttons[i].getGlobalBounds().height / 2.0f);
		buttons[i].setPosition(Config::windowSize.x / 2.0, 280.0f + i * 120.0f);
	}
}

void GameStateMenu::draw()
{
	game->window.clear(sf::Color::White);
	game->window.draw(title);
	
	for (auto & button : buttons)
		game->window.draw(button);

	game->window.display();
}

void GameStateMenu::update()
{
	for (auto & button : buttons)
		button.update(game->mousePosition);
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
			break;
		}
		case sf::Event::MouseButtonPressed:
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				if (buttons[0].isHover(game->mousePosition))
					playGame();
				else if (buttons[1].isHover(game->mousePosition))
					game->window.close();
			}
		}
		default:
			break;
		}
	}

	return;
}
