#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

#include"Bohater.h"
#include"Bonusy.h"
#include"Platformy.h"
#include"T³o.h"

#include<vector>

class SilnikGry
{
private:
	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	bool endGame;
	sf::View gameView;
	
	int h = 700;

	std::vector<Platformy*> platformy;
	

	Bohater* bohater;
	T³o t³o;
	
	void initVariables();
	void initWindow();
	void initPlayer();
	void initPlatform();
	void movingScreen();
public:
	//Konstruktor i destruktor
	SilnikGry();
	~SilnikGry();

	//Funkcje
	void run();


	void onCollision();

	void update();
	void render();
};

