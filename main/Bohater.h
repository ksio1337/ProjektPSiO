#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

#include<iostream>

class Bohater
{
private:
	sf::Sprite spriteB;
	sf::Texture textureB;
	
	float speed;
	float dx = 0.f, dy = 0.f;
	int x = 0, y = 0;
	
	

	void initVariables();
	void initTexture();
	void initSprite();
public:
	//Konstruktor i destruktor
	Bohater(float x = 400.f, float y =1100.f);
	virtual ~Bohater();

	sf::FloatRect playerGetBounds();
	void jump();
	float direction();

	void updateInput();
	void updateWindowBoundsCollision(const sf::RenderTarget* target);
	void update(const sf::RenderTarget* target);
	void render(sf::RenderTarget& target);
};

