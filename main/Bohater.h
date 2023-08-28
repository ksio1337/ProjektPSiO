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
	sf::Sprite sprite;
	sf::Texture textureB;

	float speed;

	

	void initVariables();
	void initTexture();
	void initSprite();
public:
	//Konstruktor i destruktor
	Bohater();
	virtual ~Bohater();




	void updateInput();
	void update();
	void render(sf::RenderTarget& target);
};

