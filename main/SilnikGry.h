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

class SilnikGry
{
private:
	
	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	bool endGame;

	

	Bohater* bohater;
	T³o t³o;
	
	void initVariables();
	void initWindow();
	void initPlayer();
public:
	//Konstruktor i destruktor
	SilnikGry();
	~SilnikGry();

	//Funkcje
	void run();
	//const bool running() const;

	void update();
	void render();
};

