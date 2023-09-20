#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

#include<iostream>

enum PLAYER_ANIMATION_STATES {IDLE = 0, MOVING_LEFT, MOVING_RIGHT};

class Bohater
{
private:
	//Tekstura i sprite bohatera
	sf::Sprite spriteB;
	sf::Texture textureB;

	sf::Clock animationTimer;

	float speed;
	float dx = 0.f, dy = 0.f;
	int x = 0, y = 0, h = 200;
	
	//Animation
	short animState;
	sf::IntRect currentFrame;
	bool animationSwitch;

	bool inAir;

	//Inicjalizacja wartoœci
	void initVariables();
	//Inicjalizacja tekstury i sprita
	void initTexture();
	void initSprite();
	//Inicjalizacja animacji
	void initAnimations();
public:
	//Konstruktor i destruktor
	Bohater(float x = 400.f, float y =1100.f);
	virtual ~Bohater();

	//Bool do zmiany animacji
	const bool& getAnimSwitch();
	//Funkcja returnuj¹ca pozycje bohatera
	const sf::Vector2f getPosition()const;
	//Funkcja returnuj¹ca bounds bohatera
	sf::FloatRect playerGetBounds();
	//Funkcja do automatycznego skakania
	void jump();
	void doubleJump();
	float direction();
	//Funkcja ustawiaj¹ca bool inAir na true
	void setInAir();
	//Funkcja returnuj¹ca pozycje bohatera
	sf::Vector2f playerGetPos();
	//Funkcja do ustawiania wysokoœci bohatera na konkretny y
	void playerSetHeight(float height);
	//Funkcja do resetowania timer animacji
	void resetAnimationTimer();
	//Funkcja do sterowania
	void updateInput();
	//Funkcja do updatowania animacji
	void updateAnimations();
	//Update bohatera
	void update(const sf::RenderTarget* target);
	//Render bohatera
	void render(sf::RenderTarget& target);
};

