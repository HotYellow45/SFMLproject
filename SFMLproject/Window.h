#ifndef WINDOW

#include"SFML/include/SFML/Graphics.hpp"
#include"SFML/include/SFML/Window.hpp"


class Window
{
public:
	Window();
	Window(const std::string& l_title, const sf::Vector2u& l_size);
	~Window();

	void BeginDraw(); //clear the window
	void EndDraw();  // display the window

	void Update();

	bool isDone();
	bool isFullscreen();
	sf::Vector2u GetWindowsize();

	void ToggleFullscreen();

	void Draw(sf::Drawable& l_Drawable);

private:
	void Setup(const std::string& l_title, const sf::Vector2u& l_size);
	void Destroy();
	void Create();

	sf::RenderWindow m_window;
	sf::Vector2u m_windowsize;
	std::string m_windowtitle;
	bool m_isDone;
	bool m_isFullScreen;
};













#endif