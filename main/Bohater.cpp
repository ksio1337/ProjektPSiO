#include "Bohater.h"

//Inicjalizacja wartoœci
void Bohater::initVariables()
{
	this->animState = PLAYER_ANIMATION_STATES::IDLE;
	this->speed = 5.f;
}

//Inicjalizacja tekstury
void Bohater::initTexture()
{
	if (!this->textureB.loadFromFile("Textures/bohater.png"))
	{
		std::cout << "ERROR:BOHATER:INITTEXTURE::NIE ZALADOWANO TEKSTURY." << "\n";
	}
}
//Inicjalizacja sprita
void Bohater::initSprite()
{
	//Przypisanie tekstury do sprite'a
	this->spriteB.setTexture(this->textureB);
	this->currentFrame = sf::IntRect(0, 0, 16, 16);

	
	this->spriteB.setTextureRect(this->currentFrame);
	//Resize
	this->spriteB.scale(5.f, 5.f);
}

//Inicjalizacja animacji
void Bohater::initAnimations()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}

//Konstruktor
Bohater::Bohater(float x, float y)
{
	this->x = x;
	this->y = y;
	this->initVariables();
	this->inAir = false;
	this->initTexture();
	this->initSprite();
	this->initAnimations();
}

//Destruktor
Bohater::~Bohater()
{
}

//Bool do zmiany animacji
const bool& Bohater::getAnimSwitch()
{
	bool anim_switch = this->animationSwitch;

	if (this->animationSwitch)
		this->animationSwitch = false;

	return anim_switch;
}

//Funkcja returnuj¹ca pozycje bohatera
const sf::Vector2f Bohater::getPosition() const
{
	return this->spriteB.getPosition();
}

//Funkcja returnuj¹ca bounds bohatera
sf::FloatRect Bohater::playerGetBounds()
{
	return spriteB.getGlobalBounds();
}

//Funkcja do automatycznego skakania
void Bohater::jump()
{
	this->dy = -15;
}

float Bohater::direction()
{
	return this->dy;
}

//Funkcja ustawiaj¹ca bool inAir na true
void Bohater::setInAir()
{
	this->inAir = true;
}

//Funkcja returnuj¹ca pozycje bohatera
sf::Vector2f Bohater::playerGetPos()
{
	return this->spriteB.getPosition();
}

//Funkcja do ustawiania wysokoœci bohatera na konkretny y
void Bohater::playerSetHeight(float height)
{
	this->y = height;
}

//Reset timera animacji
void Bohater::resetAnimationTimer()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}

//Funkcja do sterowania
void Bohater::updateInput()
{
	this->animState = PLAYER_ANIMATION_STATES::IDLE;
	//Keyboards input
	//Left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (x > 0)
		{
			this->x -= this->speed;
			this->animState = PLAYER_ANIMATION_STATES::MOVING_LEFT;
		}
	}
	//Right
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (x < 720)
		{
			this->x += this->speed;
			this->animState = PLAYER_ANIMATION_STATES::MOVING_RIGHT;
		}


	}
	//Jump

	dy += 0.4;
	y += dy;
	if (!this->inAir)
	{
		if (y > 1100)
		{
			dy = -15;
		}
	}
		this->spriteB.setPosition(x, y);
}

//Update animacji
void Bohater::updateAnimations()
{
	if (this->animState == PLAYER_ANIMATION_STATES::IDLE)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.2f || this->getAnimSwitch())
		{
			this->currentFrame.top = 0.f;
			this->currentFrame.left += 16.f;
			if (this->currentFrame.left >= 0.f)
				this->currentFrame.left = 0;

			this->animationTimer.restart();
			this->spriteB.setTextureRect(this->currentFrame);
		}
	}
	else if (this->animState == PLAYER_ANIMATION_STATES::MOVING_RIGHT)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f || this->getAnimSwitch())
		{
			this->currentFrame.top = 16.f;
			this->currentFrame.left += 16.f;
			if (this->currentFrame.left >= 32.f)
				this->currentFrame.left = 0;

			this->animationTimer.restart();
			this->spriteB.setTextureRect(this->currentFrame);
			
		}
		this->spriteB.setScale(5.f, 5.f);
		this->spriteB.setOrigin(0.f, 0.f);
	}
	else if (this->animState == PLAYER_ANIMATION_STATES::MOVING_LEFT)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f || this->getAnimSwitch())
		{
			this->currentFrame.top = 16.f;
			this->currentFrame.left += 16.f;
			if (this->currentFrame.left >= 32.f)
				this->currentFrame.left = 0;

			this->animationTimer.restart();
			this->spriteB.setTextureRect(this->currentFrame);
			
		}
		this->spriteB.setScale(-5.f, 5.f);
		this->spriteB.setOrigin(this->spriteB.getGlobalBounds().width / 5.f, 0.f);

	}
	else 
		this->animationTimer.restart();
}

//Update bohatera
void Bohater::update(const sf::RenderTarget* target)
{
	this->updateInput();
	this->updateAnimations();
}

//Render bohatera
void Bohater::render(sf::RenderTarget& target)
{
	target.draw(this->spriteB);
}
