#include "Logic.h"

Logic::Logic()
{
	;
}

Logic::~Logic()
{
	;
}

void Logic::update()
{
	discoveredCards++;
	
	if (discoveredCards == 2)
		state = WAITING;
}
