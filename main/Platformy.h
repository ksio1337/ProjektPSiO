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

	bool collided = false;
	bool isSand;
	float speed;
	
	void initTexture(std::string path);
	void initSprite(int x, int y, float xScale, float yScale);
public:
	//Konstruktor i destruktor
	Platformy(int xPos, int yPos, float xScale, float yScale, float speed, std::string filePath, bool isSand);
	virtual ~Platformy();

	sf::FloatRect platformGetBounds();

	void changeDirection();
	bool isPlatformSand();
	bool hasCollided() const;
	void setCollided(bool value);
	sf::Vector2f platformGetPos();
	void platformSetHeight(float height);

	void update();
	void render(sf::RenderTarget& target);
};