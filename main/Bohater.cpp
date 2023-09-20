#include "Bohater.h"

void Bohater::initVariables()
{
	this->animState = PLAYER_ANIMATION_STATES::IDLE;
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
	this->currentFrame = sf::IntRect(0, 0, 16, 16);

	
	this->spriteB.setTextureRect(this->currentFrame);
	//Resize
	this->spriteB.scale(5.f, 5.f);
}

void Bohater::initAnimations()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}

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

Bohater::~Bohater()
{
}

const bool& Bohater::getAnimSwitch()
{
	bool anim_switch = this->animationSwitch;

	if (this->animationSwitch)
		this->animationSwitch = false;

	return anim_switch;
}

const sf::Vector2f Bohater::getPosition() const
{
	return this->spriteB.getPosition();
}

sf::FloatRect Bohater::playerGetBounds()
{
	return spriteB.getGlobalBounds();
}

void Bohater::jump()
{
	this->dy = -15;
}

float Bohater::direction()
{
	return this->dy;
}

void Bohater::setInAir()
{
	this->inAir = true;
}

sf::Vector2f Bohater::playerGetPos()
{
	return this->spriteB.getPosition();
}

void Bohater::playerSetHeight(float height)
{
	this->y = height;
}

void Bohater::resetAnimationTimer()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}

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


void Bohater::updateWindowBoundsCollision(const sf::RenderTarget* target)
{
		
		//Bottom
		//if (this->spriteB.getPosition().y + this->spriteB.getGlobalBounds().height >= target->getSize().y)
			//this->spriteB.setPosition(this->spriteB.getPosition().x, target->getSize().y - this->spriteB.getGlobalBounds().height + 5.f);
}

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

void Bohater::update(const sf::RenderTarget* target)
{
	this->updateInput();
	this->updateAnimations();
	this->updateWindowBoundsCollision(target);
}

void Bohater::render(sf::RenderTarget& target)
{
	target.draw(this->spriteB);
}
