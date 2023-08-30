#include "Platformy.h"

void Platformy::initTexture(std::string path)
{
	if (!this->textureP.loadFromFile(path))
	{
		std::cout << "ERROR:PLATFORMY:INITTEXTURE::NIE ZALADOWANO TEKSTURY." << "\n";
	}
}

void Platformy::initSprite(int x, int y, float xScale, float yScale)
{
	//Przypisanie tekstury do sprite'a
	this->spriteP.setTexture(this->textureP);
	this->spriteP.setPosition(x, y);

	//Resize
	this->spriteP.scale(xScale, yScale);
}

Platformy::Platformy(int xPos, int yPos, float xScale, float yScale, float speed, std::string filePath)
{
	this->initTexture(filePath);
	this->initSprite(xPos, yPos, xScale, yScale);

	this->speed = speed;
}

Platformy::~Platformy()
{

}

void Platformy::update()
{
}

void Platformy::render(sf::RenderTarget& target)
{
	target.draw(this->spriteP);
}
