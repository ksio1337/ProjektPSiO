#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

#include<iostream>
class Bonusy
{
private:
	sf::CircleShape shape;

	public:
		//Konstruktor i destruktor
		Bonusy();
		virtual ~Bonusy();
};

