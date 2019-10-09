#include "GameField.h"

GameField::GameField()
{
	for (int i = 0; i < N_CELLS; i++) {
		grid.push_back(0);
		gridNext.push_back(0);
	}
}

int GameField::get_grid(int x, int y)
{
	return grid[x + y * GRID_WIDTH];
}

int GameField::get_grid(int i)
{
	return grid[i];
}

int GameField::get_gridNext(int x, int y)
{
	return gridNext[x + y * GRID_WIDTH];
}

int GameField::get_gridNext(int i)
{
	return gridNext[i];
}

void GameField::set_grid(int x, int y, int val)
{
	grid[x + y * GRID_WIDTH] = val;
}

void GameField::set_grid(int i, int val)
{
	grid[i] = val;
}

void GameField::set_gridNext(int x, int y, int val)
{
	gridNext[x + y * GRID_WIDTH] = val;
}

void GameField::set_gridNext(int i, int val)
{
	gridNext[i] = val;
}

void GameField::runGame()
{
	const sf::Vector2f CELL_VECTOR(CELL_SIZE, CELL_SIZE);
	sf::RenderWindow window(sf::VideoMode(CELL_SIZE * GRID_WIDTH, CELL_SIZE * GRID_HEIGHT + 50), "GameLife");
	srand(time(nullptr));

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
				else if (event.key.code == sf::Keyboard::Left) {
					delay += DELAY_INC;
				}
				//Заполнить рандомно
				else if (event.key.code == sf::Keyboard::R) {
					for (size_t i = 0; i < N_CELLS; i++) {
						int tmp = (double(rand()) / RAND_MAX < 0.2f) ? 1 : 0;
						set_grid(i, tmp);
					}
				}
				//Очистить поле
				else if (event.key.code == sf::Keyboard::C) {
					for (size_t i = 0; i < N_CELLS; i++)
						set_grid(i, 0);
				}
				//Делаем один шаг
				else if (event.key.code == sf::Keyboard::N) {
					oneStep = true;
				}
				break;
			case sf::Event::MouseButtonPressed:
				if (!isPlaying && event.mouseButton.button == sf::Mouse::Left)
				{
					int x = int(event.mouseButton.x) / CELL_SIZE;
					int y = int(event.mouseButton.y) / CELL_SIZE;
					if (x >= 0 && x < GRID_WIDTH && y >= 0 && y < GRID_HEIGHT)
						set_grid(x, y, !get_grid(x, y));
				}
				break;
			}
		}
		window.clear(WHITE);
		for (size_t x = 0; x < GRID_WIDTH; x++)
		{
			for (size_t y = 0; y < GRID_HEIGHT; y++)
			{
				// отрисовка текущей страницы
				sf::RectangleShape cell;
				cell.setPosition(x * CELL_SIZE, y * CELL_SIZE);
				cell.setSize(CELL_VECTOR);
				cell.setOutlineThickness(1);
				cell.setOutlineColor(GRAY);
				if (get_grid(x, y) == 1)
					cell.setFillColor(BLACK);
				else
					cell.setFillColor(WHITE);
				window.draw(cell);

				// подготовка следующей матрицы
				if (isPlaying || oneStep)
				{
					int neighborSum = 0;
					for (int i = -1; i < 2; i++)
						for (int j = -1; j < 2; j++)
						{
							int xi = wrapValue(x + i, GRID_WIDTH);
							int yj = wrapValue(y + j, GRID_HEIGHT);
							neighborSum += get_grid(xi, yj);
						}

					int val = get_grid(x, y);
					neighborSum -= val;
					set_gridNext(x, y, val);
					if (val == 1 && (neighborSum < 2 || neighborSum > 3))
						set_gridNext(x, y, 0);
					else if (neighborSum == 3)
						set_gridNext(x, y, 1);
				}
			}
		}

		// перекидываем подготовленные данные в матрицу для отображения
		if (isPlaying || oneStep)
		{
			oneStep = false;
			for (int i = 0; i < N_CELLS; i++)
				set_grid(i, get_gridNext(i));
		}

		window.display();
		sf::sleep(sf::milliseconds(delay));
	}
}

int GameField::wrapValue(int v, int vMax)
{
		if (v == -1) return vMax - 1;
		if (v == vMax) return 0;
		return v;
}
