#pragma once
#include <SFML/Graphics.hpp>
#include <time.h>
#include <vector>

#include <sstream> 
#include <iterator>
#include <string> 
#include <algorithm> 
#include <iostream> 

#define WHITE sf::Color::White
#define BLACK sf::Color::Black
#define GRAY sf::Color(153, 153, 153)

class GameField final{
private:
		


	//Размер ячеек
	const size_t CELL_SIZE = 20;
	//Ширина поля в ячейках
	const size_t GRID_WIDTH = 40;
	//Длина поля в ячейках
	const size_t GRID_HEIGHT = 30;
	//Общее количество ячеек
	const size_t N_CELLS = GRID_WIDTH * GRID_HEIGHT;
	//Шаг для задержки
	const int DELAY_INC = 50;
	//Регулятор скорости
	int delay = 100;
	//Пауза приложения
	bool isPlaying = false;
	//Флаг активации приложения на 1 шаг
	bool oneStep = false;

	int wrapValue(int v, int vMax);

	void init_grid();

public:
	GameField();
	//Текущее состояние поля
	std::vector<int> grid;
	//Следующее состояние поля
	std::vector<int> gridNext;

	int get_grid(int x, int y);
	int get_grid(int i);
	int get_gridNext(int x, int y);
	int get_gridNext(int i);

	void set_grid(int x, int y, int val);
	void set_grid(int i, int val);
	void set_gridNext(int x, int y, int val);
	void set_gridNext(int i, int val);	

	void run_Game();

	~GameField() = default;
};

