#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

#include<iostream>
class Platformy
{
private:
	sf::Texture textureP;
	sf::Sprite spriteP;

	float speed;

	void initTexture(std::string path);
	void initSprite(int x, int y, float xScale, float yScale);
public:
	//Konstruktor i destruktor
	Platformy(int xPos, int yPos, float xScale, float yScale, float speed, std::string filePath);
	virtual ~Platformy();


	void update();
	void render(sf::RenderTarget& target);
};