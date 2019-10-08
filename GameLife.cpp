#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include "UserInterface.h"
#include "GameField.h"

#define WHITE sf::Color::White
#define BLACK sf::Color::Black
#define GRAY sf::Color(153, 153, 153)

int wrapValue(int v, int vMax)
{
	if (v == -1) return vMax - 1;
	if (v == vMax) return 0;
	return v;
}

int main()
{	
	GameField gf;
	srand(time(nullptr));
	const int CELL_SIZE		 = 20;
	const int GRID_WIDTH	 = 40;
	const int GRID_HEIGHT	 = 30;

	const int N_CELLS = GRID_WIDTH * GRID_HEIGHT;
	const sf::Vector2f CELL_VECTOR(CELL_SIZE, CELL_SIZE);

	//пошаговый режим	
	//сохранить/загрузить карту
	const int DELAY_INC = 50;
	int delay = 100;
	bool isPlaying = false;
	int oneStep = 0;
	///////////////////////
	UserInterface  ui;


	sf::RenderWindow window(sf::VideoMode(CELL_SIZE * GRID_WIDTH, CELL_SIZE * GRID_HEIGHT + 50), "GameLife");
	while (window.isOpen())
	{		
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)//обработчик событий закрыть/кнопка_клавиатуры/мышь
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				//Пауза
				if (event.key.code == sf::Keyboard::P) {
					isPlaying = !isPlaying;
				}
				//Ускорить
				else if (event.key.code == sf::Keyboard::Right) {
					delay = std::max(delay - DELAY_INC, 0);
				}
				//Замедлить
				else if (event.key.code == sf::Keyboard::Left){
					delay += DELAY_INC;
				}			
				//Заполнить рандомно
				else if (event.key.code == sf::Keyboard::R) {
					for (int i = 0; i < N_CELLS; i++) {
						int tmp = (double(rand()) / RAND_MAX < 0.2f) ? 1 : 0;
						gf.set_grid(i, tmp);
					}
						 
				}
				//Очистить поле
				else if (event.key.code == sf::Keyboard::C) {
					for (int i = 0; i < N_CELLS; i++)
						gf.set_grid(i, 0);
						//grid[i] = 0;
				}
				//Делаем один шаг
				else if (event.key.code == sf::Keyboard::N){
					oneStep++;
				}
				break;
			case sf::Event::MouseButtonPressed:
				if (!isPlaying && event.mouseButton.button == sf::Mouse::Left)
				{
					int x = int(event.mouseButton.x) / CELL_SIZE;
					int y = int(event.mouseButton.y) / CELL_SIZE;
					if (x >= 0 && x < GRID_WIDTH && y >= 0 && y < GRID_HEIGHT)
						gf.set_grid(x, y, !gf.get_grid(x, y));
				}
				break;
			}
		}

		// отображение текущего состояния и подготовка следующего
		window.clear(WHITE);
		for (int x = 0; x < GRID_WIDTH; x++)
		{
			for (int y = 0; y < GRID_HEIGHT; y++)
			{
				// отрисовка текущей страницы
				sf::RectangleShape cell;
				cell.setPosition(x * CELL_SIZE, y * CELL_SIZE);
				cell.setSize(CELL_VECTOR);
				cell.setOutlineThickness(1);
				cell.setOutlineColor(GRAY);
				if (gf.get_grid(x,y) == 1)
					cell.setFillColor(BLACK);
				else
					cell.setFillColor(WHITE);
				window.draw(cell);

				// подготовка следующей матрицы
				if (isPlaying)
				{
					int neighborSum = 0;
					for (int i = -1; i < 2; i++)
						for (int j = -1; j < 2; j++)
						{
							int xi = wrapValue(x + i, GRID_WIDTH);
							int yj = wrapValue(y + j, GRID_HEIGHT);
							neighborSum += gf.get_grid(xi, yj);
						}

					int val = gf.get_grid(x, y);
					neighborSum -= val;
					gf.set_gridNext(x, y, val);
					if (val == 1 && (neighborSum < 2 || neighborSum > 3))
						gf.set_gridNext(x, y, 0);
					else if (neighborSum == 3)
						gf.set_gridNext(x, y, 1);
				}
			}
		}

		// перекидываем подготовленные данные в матрицу для отображения
		if (isPlaying)
			for (int i = 0; i < N_CELLS; i++)
				gf.set_grid(i, gf.get_gridNext(i));
				

		window.display();
		sf::sleep(sf::milliseconds(delay));
	}
}