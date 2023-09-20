#include "T這.h"

//Inicjalizacja tekstury
void T這::initTexture()
{
	if (!this->textureS.loadFromFile("Textures/sky.png"))
	{
		std::cout << "ERROR:TΜ:INITTEXTURE::NIE ZALADOWANO TEKSTURY." << "\n";
	}
}

//Inicjalizacja sprita
void T這::initSprite()
{
	//Przypisanie tekstury do sprite'a
	this->spriteS.setTexture(this->textureS);

	this->spriteS.setScale(1.f, 2.f);
}

//Kontruktor
T這::T這()
{
	this->initTexture();
	this->initSprite();
}

//Desturktor
T這::~T這()
{
}



void T這::render(sf::RenderTarget& target)
{
	target.draw(this->spriteS);
}
