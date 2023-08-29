#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

#include<iostream>
class T³o
{
private:
	sf::Texture textureS;
	sf::Sprite spriteS;

	void initTexture();
	void initSprite();
public:
	//Konstruktor i destruktor
	T³o();
	virtual ~T³o();


	void update();
	void render(sf::RenderTarget& target);
};