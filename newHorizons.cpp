#include <SFML/Graphics.hpp>
#include <vector>
#include <stdlib.h>
#include <string>
#include <string>
#include "coordinates.h"
#include "baseObject.h"
#include "field.h"
#include "cell.h"

#define COLUMNS 30 
#define ROWS 20
#define SQUARE_AREA 20
#define FOOD 1

#define UP 101
#define DOWN 103
#define LEFT 100
#define RIGHT 102

#define BLACK 0, 0, 0, 255
#define GREY 128, 128, 128
#define WHITE_GRAY 102, 102, 102
#define BLUE 0, 255, 255
#define PURPLE 128, 0, 128

using namespace sf;

// управление

void keys(int& dir) {
	if (Keyboard::isKeyPressed(Keyboard::Up)) dir = 0;
	if (Keyboard::isKeyPressed(Keyboard::Right)) dir = 1;
	if (Keyboard::isKeyPressed(Keyboard::Down)) dir = 2;
	if (Keyboard::isKeyPressed(Keyboard::Left)) dir = 3;
};

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

//int size(500);
//int quadCount = 50;
//bool isGameOver(false);
//int countGreen = 0;
//int countRed = 0;

int main() {

	field myField;
	myField.setName("Snake test");
	myField.setHeight(ROWS * SQUARE_AREA);
	myField.setWidth(COLUMNS * SQUARE_AREA);
	myField.setAreaSize(SQUARE_AREA);

	RenderWindow window(VideoMode(myField.getWidth(), myField.getHeight()), myField.getName());
	//myField.window.create(VideoMode(myField.getHeight(), myField.getWidth()), myField.getName());

	myField.myWindow = &window;

	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::Black);

		myField.render();

		//for (int c = 0; c < COLUMNS; c++) {
		//	Vertex vertLine[] =
		//	{
		//		Vertex(Vector2f(c * SQUARE_AREA, 0), Color::Green),
		//		Vertex(Vector2f(c * SQUARE_AREA, myField.getHeight()), Color::Blue)
		//	};
		//	window.draw(vertLine, 2, Lines);
		//};
		//for (int r = 0; r < ROWS; r++) {
		//	Vertex horLine[] =
		//	{
		//		Vertex(Vector2f(0, r * SQUARE_AREA), Color::Red),
		//		Vertex(Vector2f(myField.getWidth(), r * SQUARE_AREA), Color::Blue)
		//	};
		//	window.draw(horLine, 2, Lines);
		//};

		RectangleShape rectangle(Vector2f(SQUARE_AREA, SQUARE_AREA));
		rectangle.setPosition(Vector2f(3 * SQUARE_AREA, 2 * SQUARE_AREA));
		rectangle.setFillColor(Color::Cyan);
		window.draw(rectangle);

		int snakeLength = 4;
		int snakeHead[]{ 4, 5 };

		for (int i = 0; i < snakeLength; i++) {
			RectangleShape snakePart(Vector2f(SQUARE_AREA, SQUARE_AREA));
			snakePart.setPosition(Vector2f((snakeHead[0] + i) * SQUARE_AREA, (snakeHead[1]) * SQUARE_AREA));
			snakePart.setFillColor(Color::Green);
			window.draw(snakePart);
		};


		window.display();
	}

	//RectangleShape rect(Vector2f(myField.getHeight(), myField.getWidth()));
	//rect.setOutlineColor(Color::Green);
	//rect.setOutlineThickness(1);

	//snake s[100];
	//int snakec = 4;

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