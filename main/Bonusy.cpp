#include "Bonusy.h"

Bonusy::Bonusy()
{
	//bonusPoints = 5;
}

Bonusy::~Bonusy()
{
}

bool Bonusy::bonusCollision(sf::Vector2f playerPos)
{
	if (abs(this->shape.getPosition().x - playerPos.x) < 15 || abs(this->shape.getPosition().y - playerPos.y) < 15)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Bonusy::initShape(float sizeX, float sizeY, sf::Color color)
{
	this->shape.setSize(sf::Vector2f(sizeX, sizeY));
	this->shape.setFillColor(color);
	
}

void Bonusy::init(int x, int y)
{
	this->x = x;
	this->y = y;
	this->shape.setPosition(this->x, this->y);
}

void Bonusy::bonusSetHeight(float height)
{
	this->shape.setPosition(this->shape.getPosition().x, height);
}

sf::FloatRect Bonusy::shapeGetBounds()
{
	return shape.getGlobalBounds();
}

sf::Vector2f Bonusy::bonusGetPos()
{
	return shape.getPosition();
}

void Bonusy::shapeSetPos(int x, int y)
{
	this->shape.setPosition(x, y);
}



void Bonusy::update()
{
}

void Bonusy::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}

/*int Bonusy::getBonusPoints() {
	return bonusPoints;
}

void Bonusy::setBonusPoints(int value) {
	bonusPoints = value;
}*/