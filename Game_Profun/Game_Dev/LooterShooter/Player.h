#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <iostream>



class Player {
public:
	Player(sf::Vector2f size) {
		player.setSize(size);
		sf::Texture playerTexture;
		playerTexture.loadFromFile("ship.png");
		player.setTexture(&playerTexture);


	}
	void move(sf::Vector2f direction)
	{
		player.move(direction);
	}

	int getX()
	{
		return player.getPosition().x;
	}

	int getY()
	{
		return player.getPosition().y;
	}

	void draw(sf::RenderWindow &window)
	{
		window.draw(player);
	}





private:
	sf::RectangleShape player;
};
