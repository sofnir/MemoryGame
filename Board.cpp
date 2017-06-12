#include "Board.h"

Board::Board()
{
	createCards();
}

Board::~Board()
{
	;
}

void Board::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (auto & row : cards)
		for (auto & card : row)
		{
			if(card.isVisible())
				target.draw(card);
		}			
}

Card * Board::getCard(const sf::Vector2f & mousePosition)
{
	for (auto & row : cards)
		for (auto & card : row)
		{
			if (card.isHover(mousePosition) && card.isVisible())
				return & card;
		}
}

void Board::createCards()
{
	for (int y = 0; y < 4; y++)
		for (int x = 0; x < 5; x++)
		{
			cards[y][x].setTexture(Data::cardsTexture);			
			cards[y][x].setPosition(sf::Vector2f(100 + x * 115, 70 + y * 115));
		}

	setRandomFaces();
}

void Board::setRandomFaces()
{
	srand(time(NULL));

	int tab_check[10] = { 0 };

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int number = rand() % 10 + 1;

			if (tab_check[number - 1] < 2)
			{
				cards[i][j].setFaceRect(sf::IntRect(0, number * 100, 100, 100));
				tab_check[number - 1]++;
			}
			else j--;
		}
	}
}
