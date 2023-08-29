#include "SilnikGry.h"

void SilnikGry::initVariables()
{
	this->endGame = false;
}

void SilnikGry::initWindow()
{
	
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "ProjektSFML", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
}

void SilnikGry::initPlayer()
{
	this->bohater = new Bohater();
}

SilnikGry::SilnikGry()
{
	this->initVariables();
	this->initWindow();
	this->initPlayer();
}

SilnikGry::~SilnikGry()
{
	delete this->window;
	delete this->bohater;
}

/*const bool SilnikGry::running() const
{
	return this->window->isOpen();
}*/

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
}

void SilnikGry::render()
{
	this->window->clear();

	//Render
	this->t³o.render(*this->window);
	this->bohater->render(*this->window);
	

	this->window->display();
}
