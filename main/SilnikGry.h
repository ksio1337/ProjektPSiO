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
#include<sstream>
#include<cmath>

class SilnikGry
{
private:
	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	bool endGame;

	int points;

	sf::Font font;
	sf::Text guiText;
	sf::Text endGameText;

	int h = 500;

	std::vector<Platformy*> platformy;
	

	Bohater* bohater;
	T³o t³o;
	
	void initVariables();
	void initWindow();
	void initPlayer();
	void initPlatform();
	void initFonts();
	void initText();
	void movingScreen();
	void makePlatform(float height);
public:
	//Konstruktor i destruktor
	SilnikGry();
	~SilnikGry();

	const bool& getEndGame() const;

	//Funkcje
	void run();

	void onCollision();

	void updateGui();
	void updatePlayer();
	void update();
	void renderGui(sf::RenderTarget* target);
	void render();
};

