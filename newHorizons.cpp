#include <SFML/Graphics.hpp>
#include "field.h"
#include "snake.h"

#define COLUMNS 30 
#define ROWS 20
#define SQUARE_AREA 20
#define FOOD 1

#define SNAKELENGTH 4

//void tick(int& snakec, snake* s, int& dir, int b, bool& go, int quadc, int& speed, app* a) {
//	if (dir >= 0 && dir <= 3) {
//		for (int i = snakec; i > 0; i--) {
//			s[i].x = s[i - 1].x;
//			s[i].y = s[i - 1].y;
//		}
//	}
//
//	switch (dir) {
//	case 0: s->y -= b; break;
//	case 1: s->x += b; break;
//	case 2: s->y += b; break;
//	case 3: s->x -= b; break;
//	}
//
//	for (int i = 0; i < 10; i++) {
//		if (s->x == a[i].x && s->y == a[i].y) {
//			snakec++;
//			a[i].getncoord(b);
//			speed -= 1000;
//		}
//	};
//
//	for (int i = 1; i < snakec; i++) {
//		if (s[0].x == s[i].x && s[0].y == s[i].y && (dir >= 0 && dir <= 3))
//			snakec = i;
//	};
//
//	if ((s->x<0 || s->x>b * quadc) || (s->y<0 || s->y>b * quadc)) go = true;
//};

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

		//sf::RectangleShape rectangle(sf::Vector2f(SQUARE_AREA, SQUARE_AREA));
		//rectangle.setPosition(sf::Vector2f(3 * SQUARE_AREA, 2 * SQUARE_AREA));
		//rectangle.setFillColor(sf::Color::Cyan);
		//window.draw(rectangle);
		//
		//int snakeLength = 4;
		//int snakeHead[]{ 4, 5 };
		//
		//for (int i = 0; i < snakeLength; i++) {
		//	sf::RectangleShape snakePart(sf::Vector2f(SQUARE_AREA, SQUARE_AREA));
		//	snakePart.setPosition(sf::Vector2f((snakeHead[0] + i) * SQUARE_AREA, (snakeHead[1]) * SQUARE_AREA));
		//	snakePart.setFillColor(sf::Color::Green);
		//	window.draw(snakePart);
		//};
		//

		window.display();
	}

	//Clock clock;

	//int dir;
	//int speed(200000);

	//srand(time(NULL));
	//app a[10];

	//for (int i = 0; i < snakec; i++) {
	//	s[i].x = b * (quadCount / 2) - (b / 2);
	//	s[i].y = b * (quadCount / 2) - (b / 2) + i * b;
	//}

	//for (int i = 0; i < 10; i++) {
	//	a[i].getncoord(b);
	//}

	//while (window.isOpen()) {
	//
	//	//keys(dir);
	//	//float time = clock.getElapsedTime().asMicroseconds();
	//	//if (time > speed && !isGameOver) {
	//	//	tick(snakec, s, dir, b, isGameOver, quadCount, speed, a);
	//	//	clock.restart();
	//	//}
	//
	//	Event event;
	//	while (window.pollEvent(event)) {
	//		if (event.type == Event::Closed)
	//			window.close();
	//	}
	//
	//	window.clear();
	//
	//	for (int i = 0; i < 5; i++)
	//		for (int j = 0; j < 5; j++) {
	//			//for (int k = 0; k < 4; k++)
	//			//	if (s[k].x == i * b - (b / 2) && s[k].y == j * b - (b / 2))
	//			//		countGreen++;
	//			//for (int l = 0; l < 10; l++)
	//			//	if (a[l].x == i * b - (b / 2) && a[l].y == j * b - (b / 2))
	//			//		countRed++;
	//			//if (countGreen > 0) rect.setFillColor(Color::Green);
	//			//else if (countRed > 0) rect.setFillColor(Color::Red);
	//			//else 
	//			rect.setFillColor(Color::Black);
	//			rect.setPosition(i * SQUARE_AREA, j * SQUARE_AREA);
	//			window.draw(rect);
	//			//countGreen = 0;
	//			//countRed = 0;
	//		}
	//	window.display();
	//}
	return 0;
}