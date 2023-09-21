#include "SilnikGry.h"

//Funkcja przypisuj¹ca wartoœci do zmiennych
void SilnikGry::initVariables()
{
	//this->animState = PLAYER_ANIMATION_STATES::IDLE;
	this->endGame = false;
	this->points = 0;
}

//Funkcja tworz¹ca okno gry
void SilnikGry::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 1200), "ProjektSFML", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
}

//Funkcja inicjuj¹ca gracza
void SilnikGry::initPlayer()
{
	this->bohater = new Bohater();
}

//Funkcja inicjuj¹ca platformy
void SilnikGry::initPlatform()
{
	
	int ySpawn = 1150;
	this->platformy.push_back(new Platformy(0, 1180, 1.f, 0.2f, 0.f, "Textures/platfromStart.png", false));
	do
	{
		int randNumber = std::rand()%3;
		std::cout << "Number is: " << randNumber << "\n";
		
		ySpawn -= 230;
		switch (randNumber)
		{
		case 0:
			this->platformy.push_back(new Platformy(std::rand() % 600 + 40, ySpawn, 0.2f, 0.2f, 0.f, "Textures/platfromDisappearing.png", true));
			break;
		case 1:
			this->platformy.push_back(new Platformy(std::rand() % 600 + 40, ySpawn, 0.2f, 0.2f, 4.f, "Textures/platfromMoving.png", false));
			break;
		case 2:
			this->platformy.push_back(new Platformy(std::rand() % 600 + 40, ySpawn, 0.2f, 0.2f, 0.f, "Textures/platfromStart.png", false));
			break;
		}
	} while (ySpawn > 0);
	
}
void SilnikGry::initBonuses()
{
	for (int i = 0; i < 1; i++)
	{
		this->bonusy.push_back(new BonusJump(std::rand() % 770, std::rand() % 400));
	}
	for (int i = 0; i < 1; i++)
	{
		this->bonusy.push_back(new BonusPoints(std::rand() % 770, std::rand() % 400));
	}
}
//Funkcja inicjuj¹ca czcionke
void SilnikGry::initFonts()
{
	if (!this->font.loadFromFile("Fonts/PixellettersFull.ttf"))
	{
		std::cout << "ERROR::GAME::INITFONT::COULD NOT LOAD PixellettersFull.ttf" << "\n";
	}
}

//Funkcja inicjuj¹ca tekst
void SilnikGry::initText()
{
	//Gui text init
	this->guiText.setFont(this->font);
	this->guiText.setFillColor(sf::Color::Blue);
	this->guiText.setCharacterSize(45);

	//End game text
	this->endGameText.setFont(this->font);
	this->endGameText.setFillColor(sf::Color::Red);
	this->endGameText.setCharacterSize(100);
	this->endGameText.setPosition(sf::Vector2f(230, 50));
	this->endGameText.setString("Koniec gry");
}

//Funkcja poruszaj¹ca ekranem
void SilnikGry::movingScreen()
{
	if (bohater->playerGetPos().y < h)
	{
		for (int i = 0; i < platformy.size(); i++)
		{
			bohater->playerSetHeight(h);
			platformy[i]->platformSetHeight(platformy[i]->platformGetPos().y - bohater->direction());
			
			if (platformy[i]->platformGetPos().y >= 1200)
			{
				int random = std::rand() % 11;
				switch (random)
				{
				case 6:
					this->bonusy[0]->shapeSetPos(std::rand() % 770, -230);
					break;
				case 9:
					this->bonusy[1]->shapeSetPos(std::rand() % 770, -230);
					break;
				default:
					break;
				}
				delete this->platformy[0];
				platformy.erase(this->platformy.begin());
				this->makePlatform(0.f);
				std::cout << "usuwam " << i << std::endl;
			}
		}
		for (size_t i = 0; i < bonusy.size(); i++)
		{
			bonusy[i]->bonusSetHeight(bonusy[i]->bonusGetPos().y - bohater->direction());
			
		}
		/*for (size_t i = 0; i < bonusyP.size(); i++)
		{
			bonusyP[i]->bonusSetHeight(bonusyP[i]->bonusGetPos().y - bohater->direction());
		}*/
	}
}

void SilnikGry::makePlatform(float height)
{
	int randNumber = std::rand() % 3;
	std::cout << "Number is: " << randNumber << "\n";
	
	
	switch (randNumber)
	{
	case 0:
		this->platformy.push_back(new Platformy(std::rand() % 600 + 40, platformy[platformy.size()-1]->platformGetPos().y-230, 0.2f, 0.2f, 0.f, "Textures/platfromDisappearing.png", true));
		break;
	case 1:
		this->platformy.push_back(new Platformy(std::rand() % 600 + 40, platformy[platformy.size()-1]->platformGetPos().y-230, 0.2f, 0.2f, 4.f, "Textures/platfromMoving.png", false));
		break;
	case 2:
		this->platformy.push_back(new Platformy(std::rand() % 600 + 40, platformy[platformy.size()-1]->platformGetPos().y-230, 0.2f, 0.2f, 0.f, "Textures/platfromStart.png", false));
		break;
	}
}
	
//Konstruktor
SilnikGry::SilnikGry()
{	
	this->initVariables();
	this->initWindow();
	this->initPlayer();
	this->initPlatform();
	this->initFonts();
	this->initText();
	this->initBonuses();
}

//Destruktor
SilnikGry::~SilnikGry()
{
	delete this->window;
	delete this->bohater;
}

const bool& SilnikGry::getEndGame() const
{
	return this->endGame;
}

//Funkcja odpowiadaj¹ca z uruchamianie gry
void SilnikGry::run()
{
	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}
}

//Funkcja do kolizji pomiêdzy graczem a platform¹
void SilnikGry::onCollision()
{
	for (size_t i = 0; i < platformy.size(); i++)
	{
		if (bohater->direction() > 0)
		{
			if (bohater->playerGetBounds().intersects(platformy[i]->platformGetBounds()))
			{
				bohater->jump();
				if (this->platformy[i]->hasCollided() == false)
				{
					this->points++;
					if (this->points == 2)
					{
						bohater->setInAir();
					}
					platformy[i]->setCollided(true);
					if (this->platformy[i]->isPlatformSand())
					{
						this->makePlatform((this->platformy[i]->platformGetPos().y) * (-1));
						delete this->platformy[i];
						platformy.erase(this->platformy.begin() + i);
					}
				}
			}
		}
	}

}

void SilnikGry::bonusCollision()
{	
	for (size_t i = 0; i < bonusy.size(); i++)
	{
		if (this->bonusy[0]->bonusCollision(this->bohater->getPosition()))
		{
			if (bohater->direction() > 0)
			{
				if (bohater->playerGetBounds().intersects(bonusy[0]->shapeGetBounds()))
				{
					this->bonusy[0]->shapeSetPos(-100, 0);
					this->bohater->doubleJump();
					this->points += 5;
				}
			}
		}
	}
	for (size_t i = 0; i < bonusy.size(); i++)
	{
		if (this->bonusy[1]->bonusCollision(this->bohater->getPosition()))
		{
			if (bohater->direction() > 0)
			{
				if (bohater->playerGetBounds().intersects(bonusy[1]->shapeGetBounds()))
				{
					this->bonusy[1]->shapeSetPos(-100, 0);
					this->points += 10;
				}
			}
		}
	}
	
}

//Funkcja do updatowania tekstu wyœwietlaj¹cego siê ekranie
void SilnikGry::updateGui()
{
	std::stringstream ss;

	ss << " Punkty: " << this->points << std::endl;

	this->guiText.setString(ss.str());
}

//Funkcja do updatowania gracza
void SilnikGry::updatePlayer()
{
	this->bohater->update(this->window);

	if(this->bohater->getPosition().y >= 1200)
	this->endGame = true;
}

//Update gry
void SilnikGry::update()
{
	sf::Event event;
	while (this->window->pollEvent(event))
	{
		if (event.Event::type == sf::Event::Closed)
			this->window->close();
		if(event.Event::KeyPressed && event.Event::key.code == sf::Keyboard::Escape)
			this->window->close();
	}

	if (event.Event::KeyReleased &&
		(
			event.Event::key.code == sf::Keyboard::A ||
			event.Event::key.code == sf::Keyboard::D
			)
		)
	{
		this->bohater->resetAnimationTimer();
	}

	if (this->endGame == false)
	{
		for (size_t i = 0; i < platformy.size(); i++)
		{
			this->platformy[i]->update();
		}
		
		for (size_t i = 0; i < bonusy.size(); i++)
		{
			this->bonusy[i]->update();
		}
		
		this->onCollision();
		this->updateGui();
		this->updatePlayer();
		this->movingScreen();
		this->bonusCollision();
	}
}

//Funkcja do renderowania tekstu wyœwietlaj¹cego siê ekranie
void SilnikGry::renderGui(sf::RenderTarget* target)
{
	target->draw(this->guiText);
}

//Render gry
void SilnikGry::render()
{
	this->window->clear();

	//Render

	this->t³o.render(*this->window);
	for (size_t i = 0; i < platformy.size(); i++)
	{
		this->platformy[i]->render(*this->window);
	}
	
	for (size_t i = 0; i < bonusy.size(); i++)
	{
		this->bonusy[i]->render(this->window);
	}
	
	
	this->bohater->render(*this->window);

	//Render gui
	this->renderGui(this->window);

	//Render endGame text
	if (this->endGame == true)
		this->window->draw(this->endGameText);
	

	this->window->display();
}
