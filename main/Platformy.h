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
	//Textura i sprite dla platform
	sf::Texture textureP;
	sf::Sprite spriteP;


	bool collided = false;
	bool isSand;
	float speed;
	
	//Inicjalizacja tekstury i sprita
	void initTexture(std::string path);
	void initSprite(int x, int y, float xScale, float yScale);
public:
	//Konstruktor i destruktor
	Platformy(int xPos, int yPos, float xScale, float yScale, float speed, std::string filePath, bool isSand);
	virtual ~Platformy();

	//Funkcja returnuj�ca globalbounds z platform
	sf::FloatRect platformGetBounds();
	
	//Funkcja zmieniaj�ca kierunek poruszania si� dla drewnianych platform
	void changeDirection();
	//Bool sprawdzaj�cy czy platforma jest z piasku
	bool isPlatformSand();
	//Funkcje sprawdzaj�ce czy gracz wcze�niej kolidowa� z tymi platformami
	bool hasCollided() const;
	void setCollided(bool value);
	//Funkcja returnuj�ca pozycje platformy
	sf::Vector2f platformGetPos();
	//Funkcja ustawiaj�ca pozycje platformy na konkretnej wysoko�ci
	void platformSetHeight(float height);

	//Funkcja do updatowania platform
	void update();
	//Render platform
	void render(sf::RenderTarget& target);
};