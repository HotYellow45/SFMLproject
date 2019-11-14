#include "Game.h"


Game::Game() : m_window("Bouncy Mushroom", sf::Vector2u(800, 700))
{
	m_mushroomTexture.loadFromFile("Deps/Mushroom.png");
	m_mushroom.setTexture(m_mushroomTexture);
	m_increment = sf::Vector2i(1, 1);
}

Game::~Game()
{
                              
}

void Game::HandleInput()
{

}

void Game::Update()
{
	m_window.Update();	//update window event
	MoveMushroom();
}

void Game::Render()
{
	m_window.BeginDraw();	//clear the window
	m_window.Draw(m_mushroom);	//draw mushroom
	m_window.EndDraw();		//display
}

Window * Game::GetWindow()
{
	return &m_window;
}



void Game::MoveMushroom()
{
	sf::Vector2u l_windSize = m_window.GetWindowsize();
	sf::Vector2u l_textSize = m_mushroomTexture.getSize();

	if ((m_mushroom.getPosition().x > l_windSize.x - l_textSize.x
		&& m_increment.x > 0) || (m_mushroom.getPosition().x < 0 && m_increment.x < 0))
	{
		m_increment.x -= m_increment.x;
	}
	if ((m_mushroom.getPosition().y > l_windSize.y - l_textSize.y
		&& m_increment.y > 0) || (m_mushroom.getPosition().y < 0 && m_increment.y < 0))
	{
		m_increment.y -= m_increment.y;
	}
		
	m_mushroom.setPosition(m_mushroom.getPosition().x + m_increment.x, m_mushroom.getPosition().y + m_increment.y);

}

