#include "SilnikGry.h"

void SilnikGry::initVariables()
{
	this->endGame = false;
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
	this->platformy.push_back(new Platformy(0, 1180, 1.f, 0.2f, 0.f, "Textures/platfromStart.png"));
}

SilnikGry::SilnikGry()
{
	this->initVariables();
	this->initWindow();
	this->initPlayer();
	this->initPlatform();
}

SilnikGry::~SilnikGry()
{
	delete this->window;
	delete this->bohater;
}


void SilnikGry::run()
{
	while (this->window->isOpen())
	{
		
		this->update();
		this->render();
		
	}
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
	this->bohater->update(this->window);
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
	

	this->window->display();
}
