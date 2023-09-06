#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

#include<iostream>

enum PLAYER_ANIMATION_STATES {IDLE = 0, MOVING_LEFT, MOVING_RIGHT, JUMPING, FALLING};

class Bohater
{
private:
	sf::Sprite spriteB;
	sf::Texture textureB;

	sf::Clock animationTimer;

	float speed;
	float dx = 0.f, dy = 0.f;
	int x = 0, y = 0, h = 200;
	
	//Animation
	short animState;
	sf::IntRect currentFrame;
	bool animationSwitch;
	
	void initVariables();
	void initTexture();
	void initSprite();
	void initAnimations();
public:
	//Konstruktor i destruktor
	Bohater(float x = 400.f, float y =1100.f);
	virtual ~Bohater();

	const bool& getAnimSwitch();
	const sf::Vector2f getPosition()const;
	sf::FloatRect playerGetBounds();
	void jump();
	float direction();

	void playerSetHeight(float height);
	void resetAnimationTimer();
	void updateInput();
	void updateWindowBoundsCollision(const sf::RenderTarget* target);
	void updateAnimations();
	void update(const sf::RenderTarget* target);
	void render(sf::RenderTarget& target);
};

