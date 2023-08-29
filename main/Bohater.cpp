#include "Bohater.h"

void Bohater::initVariables()
{
}

void Bohater::initTexture()
{
	if (!this->textureB.loadFromFile("Textures/bohater.png"))
	{
		std::cout << "ERROR:BOHATER:INITTEXTURE::NIE ZALADOWANO TEKSTURY." << "\n";
	}
}

void Bohater::initSprite()
{
	//Przypisanie tekstury do sprite'a
	this->spriteB.setTexture(this->textureB);
	this->spriteB.setPosition(400.f, 440.f);
	//Resize
	this->spriteB.scale(5.f, 5.f);
}


Bohater::Bohater()
{
	this->initTexture();
	this->initSprite();
}

Bohater::~Bohater()
{
}

void Bohater::updateInput()
{
		//Keyboards input
		//Left
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			this->spriteB.move(-this->speed, 0.f);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			this->spriteB.move(this->speed, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			this->spriteB.move(0.f, -this->speed);
		}
}

void Bohater::update()
{
}

void Bohater::render(sf::RenderTarget& target)
{
	target.draw(this->spriteB);
}
