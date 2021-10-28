#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/Input.hpp>

#include <iostream>
#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>




int main()
{
	sf::RenderWindow window(sf::VideoMode(1080, 720), "Looter Shooter !", sf::Style::Close | sf::Style::Titlebar);
	
	
	
	
	

	
	//define object
	Player player(sf::Vector2f(50, 50));
	Enemy enemy(sf::Vector2f(50, 50));
	std::vector<Bullet> bulletVec;

	enemy.setPos(sf::Vector2f(500, 400));
	
	


	bool isFiring = false;
	bool cleanUp = false;

	
	
	
	
	//main loop
	while (window.isOpen())
	{
		sf::Event event;
		//event loop
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::TextEntered:
					if (event.text.unicode < 128)
					{
						printf("%c",event.text.unicode);
					}
			}
			int moveSpeed = 15;

			if (sf::input::isKeyDown(sf::Keyboard::Key::Left))
			{
				player.move(sf::Vector2f(-moveSpeed, 0));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
			{
				player.move(sf::Vector2f(moveSpeed, 0));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
			{
				player.move(sf::Vector2f(0, -moveSpeed));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
			{
				player.move(sf::Vector2f(0, moveSpeed));
			}
			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z))
			{
				isFiring = true;
			}
			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::X))
			{
				cleanUp = true;
			}

			



		}
		window.clear();
		if (isFiring == true)
		{
			Bullet newBullet(sf::Vector2f(50, 5));
			newBullet.setPos(sf::Vector2f(player.getX(), player.getY()));
			bulletVec.push_back(newBullet);
			isFiring = false;
		}

		if (cleanUp == true)
		{
			Bullet newBullet(sf::Vector2f(20, 500));
			newBullet.setPos(sf::Vector2f(player.getX(), player.getY()));
			bulletVec.push_back(newBullet);
			cleanUp = false;
		}




		for (int i = 0; i < bulletVec.size(); i++)
		{
			bulletVec[i].draw(window);
			bulletVec[i].fire(3);
		}
		for (int i = 0; i < bulletVec.size(); i++)
		{
			enemy.chekCollision(bulletVec[i]);
		}
		
		
		
		player.draw(window);
		enemy.draw(window);
		window.display();
		
	}
	return 0;
}