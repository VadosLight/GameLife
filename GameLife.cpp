#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>

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
	constexpr int CELL_SIZE = 20;
	constexpr int GRID_WIDTH = 40;
	constexpr int GRID_HEIGHT = 30;
	const sf::Vector2f CELL_VECTOR(CELL_SIZE, CELL_SIZE);

	constexpr int N_CELLS = GRID_WIDTH * GRID_HEIGHT;
	int grid[N_CELLS] = {  };
	int gridNext[N_CELLS];
	srand(time(nullptr));//нулптр вместо нулл

	//пошаговый режим
	
	//сохранить/загрузить карту

	const int DELAY_INC = 50;
	int delay = 100;

	bool isPlaying = false;
	//заготовка для инструкции
	/*
	sf::Font font;
	font.loadFromFile("./fonts/1.ttf");

	sf::Text textPause("Press P to pause", font);
	textPause.setCharacterSize(15);
	textPause.setPosition(10, CELL_SIZE * GRID_HEIGHT + 5);
	textPause.setFillColor(BLACK);

	sf::Text textPlay("Press P to start", font);
	textPlay.setCharacterSize(15);
	textPlay.setPosition(10, CELL_SIZE * GRID_HEIGHT + 5);
	textPlay.setFillColor(BLACK);

	sf::Text textToggle("Press on rectangle to change colour", font);
	textToggle.setCharacterSize(15);
	textToggle.setPosition(10, CELL_SIZE * GRID_HEIGHT + 25);
	textToggle.setFillColor(BLACK);

	sf::Text textSpeed("<- and -> change speed", font);
	textSpeed.setCharacterSize(15);
	textSpeed.setPosition(300, CELL_SIZE * GRID_HEIGHT + 5);
	textSpeed.setFillColor(BLACK);
	*/
	
	std::cout << "==================================================" << std::endl;
	std::cout << "==================================================" << std::endl;
	std::cout << "==================INSTRUCTION=====================" << std::endl;
	std::cout << "\tPress P to pause/start" << std::endl;
	std::cout << "\tPress on rectangle to change colour" << std::endl;
	std::cout << "\t<- and -> change speed" << std::endl;
	std::cout << "\tPress C to clear screen" << std::endl;
	std::cout << "==================================================" << std::endl;
	std::cout << "==================================================" << std::endl;
	

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
				if (event.key.code == sf::Keyboard::P)
					isPlaying = !isPlaying;
				//Ускорить
				else if (event.key.code == sf::Keyboard::Right)
					delay = std::max(delay - DELAY_INC, 0);
				//Замедлить
				else if (event.key.code == sf::Keyboard::Left)
					delay += DELAY_INC;
				//Заполнить рандомно
				else if (event.key.code == sf::Keyboard::R) {
					for (int i = 0; i < N_CELLS; i++)
					grid[i] = (double(rand()) / RAND_MAX < 0.2f) ? 1 : 0;
				}
				//Очистить поле
				else if (event.key.code == sf::Keyboard::C) {
					for (int i = 0; i < N_CELLS; i++)
						grid[i] = 0;
				}
				break;

			case sf::Event::MouseButtonPressed:
				if (!isPlaying && event.mouseButton.button == sf::Mouse::Left)
				{
					int x = int(event.mouseButton.x) / CELL_SIZE;
					int y = int(event.mouseButton.y) / CELL_SIZE;
					if (x >= 0 && x < GRID_WIDTH && y >= 0 && y < GRID_HEIGHT)
						grid[x + y * GRID_WIDTH] = !grid[x + y * GRID_WIDTH];
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
				if (grid[x + y * GRID_WIDTH] == 1)
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
							neighborSum += grid[xi + yj * GRID_WIDTH];
						}

					int current = x + y * GRID_WIDTH;
					neighborSum -= grid[current];
					gridNext[current] = grid[current];
					if (grid[current] == 1 && (neighborSum < 2 || neighborSum > 3))
						gridNext[current] = 0;
					else if (neighborSum == 3)
						gridNext[current] = 1;
				}
			}
		}

		// перекидываем подготовленные данные в матрицу для отображения
		if (isPlaying)
			for (int i = 0; i < N_CELLS; i++)
				grid[i] = gridNext[i];

		/*
		// Отрисовка инструкции
		window.draw(textSpeed);
		if (isPlaying)
			window.draw(textPause);
		else
		{
			window.draw(textPlay);
			window.draw(textToggle);
		}
		*/
		window.display();
		sf::sleep(sf::milliseconds(delay));
	}
}