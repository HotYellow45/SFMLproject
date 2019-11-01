#include "Window.h"

Window::Window()
{
	Setup("window", sf::Vector2u(640, 480));
}

Window::~Window()
{
	Destroy();
}

void Window::BeginDraw()
{
	m_window.clear(sf::Color::Yellow);
}

void Window::EndDraw()
{
	m_window.display();
}

void Window::Update()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_isDone = true;

		}
		else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F5)
		{
			ToggleFullscreen();
		}
	}
}

bool Window::isDone()
{
	return m_isDone;
}

bool Window::isFullscreen()
{
	return m_isFullScreen;
}

sf::Vector2u Window::GetWindowsize()
{
	return m_windowsize;
}

void Window::ToggleFullscreen()
{
	m_isFullScreen = !m_isFullScreen;
	Destroy();
	Create();
}

void Window::Draw(sf::Drawable& l_Drawable)
{
	
	m_window.draw(l_Drawable);
}

void Window::Setup(const std::string & l_title, const sf::Vector2u & l_size)
{
	m_windowtitle = l_title;
	m_windowsize = l_size;
	m_isFullScreen = false;
	m_isDone = false;
	Create();
}

void Window::Destroy()
{
	m_window.close();
}

void Window::Create()
{
	auto style = (m_isFullScreen ? sf::Style::Fullscreen : sf::Style::Default);
	m_window.create({ m_windowsize.x, m_windowsize.y, 32 },
		m_windowtitle, style);
	
}
