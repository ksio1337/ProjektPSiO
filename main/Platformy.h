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

	//Funkcja returnuj¹ca globalbounds z platform
	sf::FloatRect platformGetBounds();
	
	//Funkcja zmieniaj¹ca kierunek poruszania siê dla drewnianych platform
	void changeDirection();
	//Bool sprawdzaj¹cy czy platforma jest z piasku
	bool isPlatformSand();
	//Funkcje sprawdzaj¹ce czy gracz wczeœniej kolidowa³ z tymi platformami
	bool hasCollided() const;
	void setCollided(bool value);
	//Funkcja returnuj¹ca pozycje platformy
	sf::Vector2f platformGetPos();
	//Funkcja ustawiaj¹ca pozycje platformy na konkretnej wysokoœci
	void platformSetHeight(float height);

	//Funkcja do updatowania platform
	void update();
	//Render platform
	void render(sf::RenderTarget& target);
};