#include "T這.h"

void T這::initTexture()
{
	if (!this->textureS.loadFromFile("Textures/sky.png"))
	{
		std::cout << "ERROR:TΜ:INITTEXTURE::NIE ZALADOWANO TEKSTURY." << "\n";
	}
}

void T這::initSprite()
{
	//Przypisanie tekstury do sprite'a
	this->spriteS.setTexture(this->textureS);
}

T這::T這()
{
	this->initTexture();
	this->initSprite();
}

T這::~T這()
{
}

void T這::update()
{
}

void T這::render(sf::RenderTarget& target)
{
	target.draw(this->spriteS);
}
