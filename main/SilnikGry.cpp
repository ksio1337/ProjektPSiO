#include "SilnikGry.h"

void SilnikGry::initVariables()
{
	//this->animState = PLAYER_ANIMATION_STATES::IDLE;
	this->endGame = false;
	this->points = 0;
}

void SilnikGry::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 1200), "ProjektSFML", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
}

void SilnikGry::initPlayer()
{
	this->bohater = new Bohater();
}

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

void SilnikGry::initFonts()
{
	if (!this->font.loadFromFile("Fonts/PixellettersFull.ttf"))
	{
		std::cout << "ERROR::GAME::INITFONT::COULD NOT LOAD PixellettersFull.ttf" << "\n";
	}
}

void SilnikGry::initText()
{
	//Gui text init
	this->guiText.setFont(this->font);
	this->guiText.setFillColor(sf::Color::Blue);
	this->guiText.setCharacterSize(45);

	//End game text
	this->endGameText.setFont(this->font);
	this->endGameText.setFillColor(sf::Color::Red);
	this->endGameText.setCharacterSize(60);
	this->endGameText.setPosition(sf::Vector2f(400, 600));
	this->endGameText.setString("Koniec gry");
}

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
				delete this->platformy[0];
				platformy.erase(this->platformy.begin());
				this->makePlatform(0.f);
				std::cout << "usuwam " << i << std::endl;
			}
		}
	}
}

void SilnikGry::makePlatform(float height)
{
	int randNumber = std::rand() % 3;
	std::cout << "Number is: " << randNumber << "\n";
	
	
	switch (randNumber)
	{
	case 0:
		this->platformy.push_back(new Platformy(std::rand() % 600 + 40, height, 0.2f, 0.2f, 0.f, "Textures/platfromDisappearing.png", true));
		break;
	case 1:
		this->platformy.push_back(new Platformy(std::rand() % 600 + 40, height, 0.2f, 0.2f, 4.f, "Textures/platfromMoving.png", false));
		break;
	case 2:
		this->platformy.push_back(new Platformy(std::rand() % 600 + 40, height, 0.2f, 0.2f, 0.f, "Textures/platfromStart.png", false));
		break;
	}
}
		
SilnikGry::SilnikGry()
{	
	this->initVariables();
	this->initWindow();
	this->initPlayer();
	this->initPlatform();
	this->initFonts();
	this->initText();
}

SilnikGry::~SilnikGry()
{
	delete this->window;
	delete this->bohater;
}

const bool& SilnikGry::getEndGame() const
{
	return this->endGame;
}


void SilnikGry::run()
{
	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}
}


void SilnikGry::onCollision()
{
	for (size_t i = 0; i < platformy.size(); i++)
	{
		if (bohater->direction() > 0)
		{
			if (bohater->playerGetBounds().intersects(platformy[i]->platformGetBounds()))
			{
				std::cout << "collision" << std::endl;
				bohater->jump();
				if (this->platformy[i]->isPlatformSand())
				{
					this->makePlatform((this->platformy[i]->platformGetPos().y)*(-1));
					delete this->platformy[i];
					platformy.erase(this->platformy.begin() + i);
				}
			}
		}
	}	
}


void SilnikGry::updateGui()
{
	std::stringstream ss;

	ss << " Punkty: " << this->points << std::endl;

	this->guiText.setString(ss.str());
}

void SilnikGry::updatePlayer()
{
	this->bohater->update(this->window);

	if(this->bohater->getPosition().y < 1200)
	this->endGame = true;
}

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

	for (size_t i = 0; i < platformy.size(); i++)
	{
		this->platformy[i]->update();
	}
	this->onCollision();
	this->updateGui();
	this->updatePlayer();
	this->movingScreen();
}

void SilnikGry::renderGui(sf::RenderTarget* target)
{
	target->draw(this->guiText);
}

void SilnikGry::render()
{
	
	this->window->clear();

	//Render

	this->t³o.render(*this->window);
	for (size_t i = 0; i < platformy.size(); i++)
	{
		this->platformy[i]->render(*this->window);
	}
	
	this->bohater->render(*this->window);

	//Render gui
	this->renderGui(this->window);

	//Render endGame text

	if (this->endGame == true)
		this->window->draw(this->endGameText);
	

	this->window->display();
}
