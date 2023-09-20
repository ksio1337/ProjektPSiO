#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

#include"Bohater.h"
#include"Bonusy.h"
#include"Platformy.h"
#include"T�o.h"
#include"BonusJump.h"
#include"BonusPoints.h"

#include<vector>
#include<sstream>
#include<cmath>

class SilnikGry
{
private:
	//Potrzebne do utworzenia okna gry
	sf::VideoMode videoMode;
	sf::RenderWindow* window;


	bool endGame;

	int points;
	//Bonusy* bonusPoints;

	//Czcionka i tekst wy�wietlaj�cy si� na ekranie
	sf::Font font;
	sf::Text guiText;
	sf::Text endGameText;

	int h = 500;

	//Obiekty klas
	std::vector<Platformy*> platformy;
	std::vector<BonusJump*> bonusyJ;
	std::vector < BonusPoints*> bonusyP;
	Bohater* bohater;
	T�o t�o;
	
	//Funkcja przypisuj�ca warto�ci do zmiennych
	void initVariables();
	//Funkcja tworz�ca okno gry
	void initWindow();
	//Funkcje inicjuj�ce gracza i platformy
	void initPlayer();
	void initPlatform();
	void initBonuses();
	//Funkcje inicjuj�ce czcionke i tekst
	void initFonts();
	void initText();
	//Funkcja poruszaj�ca ekranem
	void movingScreen();
	void makePlatform(float height);
public:
	//Konstruktor i destruktor
	SilnikGry();
	~SilnikGry();

	const bool& getEndGame() const;

	//Funkcje
	
	//Funkcja odpowiadaj�ca z uruchamianie gry
	void run();

	//Funkcja do kolizji pomi�dzy graczem a platform�
	void onCollision();
	//Kolizje gracza z bonusami
	void bonusCollision();
	//Funkcja do updatowania tekstu wy�wietlaj�cego si� ekranie
	void updateGui();
	//Funkcja do updatowania gracza
	void updatePlayer();
	//Update gry
	void update();
	//Funkcja do renderowania tekstu wy�wietlaj�cego si� ekranie
	void renderGui(sf::RenderTarget* target);
	//Render gry
	void render();
};

