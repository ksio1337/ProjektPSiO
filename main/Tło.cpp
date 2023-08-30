#include "T�o.h"

void T�o::initTexture()
{
	if (!this->textureS.loadFromFile("Textures/sky.png"))
	{
		std::cout << "ERROR:T�O:INITTEXTURE::NIE ZALADOWANO TEKSTURY." << "\n";
	}
}

void T�o::initSprite()
{
	//Przypisanie tekstury do sprite'a
	this->spriteS.setTexture(this->textureS);

	this->spriteS.setScale(1.f, 2.f);
}

T�o::T�o()
{
	this->initTexture();
	this->initSprite();
}

T�o::~T�o()
{
}

void T�o::update()
{
}

void T�o::render(sf::RenderTarget& target)
{
	target.draw(this->spriteS);
}
