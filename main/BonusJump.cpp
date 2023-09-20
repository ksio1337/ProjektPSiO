#include "BonusJump.h"



BonusJump::BonusJump(int x, int y)
{
	this->initShape(30.f, 30.f, sf::Color::Green);
	this->init(x, y);
}

BonusJump::~BonusJump()
{
}


