#include "Bohater.h"

void Bohater::initVariables()
{
	this->speed = 5.f;
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
	
	//Resize
	this->spriteB.scale(5.f, 5.f);
}


Bohater::Bohater(float x, float y)
{
	this->x = x;
	this->y = y;
	this->initVariables();

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
			if (x > -40)
			{
				this->x -= this->speed;
			}
		}
		//Right
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			if (x < 690)
			{
				this->x += this->speed;
			}
		
			
		}
		//Jump
		dy += 0.4;
		y += dy;
		if (y > 1100)
		{
			dy = -15;
		}
		this->spriteB.setPosition(x, y);
}

void Bohater::updateWindowBoundsCollision(const sf::RenderTarget* target)
{
		
		//Bottom
		if (this->spriteB.getGlobalBounds().top + this->spriteB.getGlobalBounds().height >= target->getSize().y)
			this->spriteB.setPosition(this->spriteB.getGlobalBounds().left, target->getSize().y - this->spriteB.getGlobalBounds().height + 5.f);
}

void Bohater::update(const sf::RenderTarget* target)
{
	this->updateInput();

	this->updateWindowBoundsCollision(target);
}

void Bohater::render(sf::RenderTarget& target)
{
	target.draw(this->spriteB);
}
