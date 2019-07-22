#include <SFML/Graphics.hpp>
#include "field.h"
#include "snake.h"

#define COLUMNS 30 
#define ROWS 20
#define SQUARE_AREA 20
#define FOOD 1

#define SNAKELENGTH 4

int main() {

	sf::RenderWindow window;
	window.setVerticalSyncEnabled(true);

	field myField(&window, COLUMNS, ROWS, SQUARE_AREA, FOOD);
	snake mySnake(&myField, UP, SNAKELENGTH);
	myField.insertSnake(&mySnake);

	sf::Clock myClock;

	while (window.isOpen())
	{
		sf::Event event;
		sf::Time elapsed = myClock.restart();
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::Left :
					{
					mySnake.makeNextStep();
					break;
					}
				case sf::Keyboard::Right :
					{
					mySnake.makeNextStep();
					break;
					}
				case sf::Keyboard::Up :
					{
					mySnake.makeNextStep();
					break;
					}
				case sf::Keyboard::Down :
					{
					mySnake.makeNextStep();
					break;
					}
				}
			}
		}
		
		window.clear(sf::Color::Black);
		myClock.restart();

		myField.render();
		window.display();
	}

	return 0;
}
