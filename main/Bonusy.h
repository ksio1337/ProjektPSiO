#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

#include<iostream>
#include<vector>
#include<ctime>
#include<sstream>
#include<chrono>
#include<thread>
class Bonusy
{

public:
	//Konstruktor i destruktor
	Bonusy();
	virtual ~Bonusy();

	bool bonusCollision(sf::Vector2f playerPos);
	//int bonusPoints = 0;

	//void setBonusPoints(int value);
	//int getBonusPoints();

	int x, y;
	sf::RectangleShape shape;
	
	void initShape(float sizeX, float sizeY, sf::Color color);
	void init(int x, int y);

	void bonusSetHeight(float height);
	sf::FloatRect shapeGetBounds();
	sf::Vector2f bonusGetPos();
	void shapeSetPos(int x, int y);
	void update();
	void render(sf::RenderTarget* target);
	
};

