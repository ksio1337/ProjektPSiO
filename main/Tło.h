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
	//Tektura i sprite backgroundu
	sf::Texture textureS;
	sf::Sprite spriteS;

	//Inicjalizacja tekstury i sprita
	void initTexture();
	void initSprite();
public:
	//Konstruktor i destruktor
	T³o();
	virtual ~T³o();

	//Render t³a
	void render(sf::RenderTarget& target);
};

