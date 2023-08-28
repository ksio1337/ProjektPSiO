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
	this->sprite.setTexture(this->textureB);
	this->sprite.setPosition(0.f, 0.f);
	//Resize
	this->sprite.scale(5.f, 5.f);
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
			this->sprite.move(-this->speed, 0.f);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			this->sprite.move(this->speed, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			this->sprite.move(0.f, -this->speed);
		}
}

void Bohater::update()
{
}

void Bohater::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
