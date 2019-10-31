#include"SFML/include/SFML/Graphics.hpp"



int main() {

	sf::RenderWindow window(sf::VideoMode(640, 480), "Bouncing Mushroom");

	sf::Texture mushroomTexture;
	mushroomTexture.loadFromFile("Deps/images/Mushroom.png");
	sf::Sprite mushroom(mushroomTexture);
	sf::Vector2u size = mushroomTexture.getSize();
	mushroom.setOrigin(size.x / 2, size.y / 2);
	sf::Vector2f increment(0.1f, 0.1f);

	//initialise game objects
	while (window.isOpen())
	{
		//handle keyboard events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		//update game objects
		

		

		if ((mushroom.getPosition().x) + (size.x / 2) > window.getSize().x && (increment.x > 0) || (mushroom.getPosition().x / 2) - (size.x / 2) < 0 && (increment.x < 0))
		{
			//reverse direction
			increment.x = -increment.x;
		}
		if ((mushroom.getPosition().y) + (size.y / 2) > window.getSize().y && (increment.y > 0) || (mushroom.getPosition().y / 2) - (size.y / 2) < 0 && (increment.y < 0))
		{
			//reverse direction
			increment.y = -increment.y;
		}
		mushroom.setPosition(mushroom.getPosition() + increment);
		window.clear(sf::Color::Magenta);
		window.draw(mushroom);

		//render game objects
		window.display();
	}

	return 0;
}