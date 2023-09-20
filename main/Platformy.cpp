#include "Platformy.h"

//Inicjalizacja tekstury
void Platformy::initTexture(std::string path)
{
	if (!this->textureP.loadFromFile(path))
	{
		std::cout << "ERROR:PLATFORMY:INITTEXTURE::NIE ZALADOWANO TEKSTURY." << "\n";
	}
}
//Inicjalizacja sprita
void Platformy::initSprite(int x, int y, float xScale, float yScale)
{
	//Przypisanie tekstury do sprite'a
	this->spriteP.setTexture(this->textureP);
	this->spriteP.setPosition(x, y);

	//Resize
	this->spriteP.scale(xScale, yScale);
}

//Konstruktor
Platformy::Platformy(int xPos, int yPos, float xScale, float yScale, float speed, std::string filePath, bool isSand)
{
	
	this->initTexture(filePath);
	this->initSprite(xPos, yPos, xScale, yScale);
	this->isSand = isSand;
	this->speed = speed;
}

//Destruktor
Platformy::~Platformy()
{

}

//Funkcja returnuj�ca globalbounds z platform
sf::FloatRect Platformy::platformGetBounds()
{
	return spriteP.getGlobalBounds();
}

//Funkcja zmieniaj�ca kierunek poruszania si� dla drewnianych platform
void Platformy::changeDirection()
{
	this->speed *= -1;
}

//Bool sprawdzaj�cy czy platforma jest z piasku
bool Platformy::isPlatformSand()
{
	return this->isSand;
}

//Funkcje sprawdzaj�ce czy gracz wcze�niej kolidowa� z tymi platformami
bool Platformy::hasCollided() const
{
	return collided;
}

void Platformy::setCollided(bool value)
{
	collided = value;
}

//Funkcja returnuj�ca pozycje platformy
sf::Vector2f Platformy::platformGetPos()
{
	return spriteP.getPosition();
}

//Funkcja ustawiaj�ca pozycje platformy na konkretnej wysoko�ci
void Platformy::platformSetHeight(float height)
{
	this->spriteP.setPosition(this->spriteP.getPosition().x, height);
}


//Update platform
void Platformy::update()
{
	this->spriteP.move(this->speed, 0);
	if (this->spriteP.getPosition().x < 0 || this->spriteP.getPosition().x > 645)
	{
		this->changeDirection();
	}
}

//Render platform
void Platformy::render(sf::RenderTarget& target)
{
	target.draw(this->spriteP);
}
