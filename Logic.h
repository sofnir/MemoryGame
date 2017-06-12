#pragma once

class Logic
{
public:
	Logic();
	~Logic();

	bool canDiscover() const { return state == DISCOVERING; }
	void update();

private:
	enum gameStates { DISCOVERING, WAITING, END_GAME };
	gameStates state = DISCOVERING;
	int discoveredCards = 0;
};

