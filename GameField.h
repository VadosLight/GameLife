#pragma once
#include <SFML/Graphics.hpp>
#include <time.h>
#include <vector>

#define WHITE sf::Color::White
#define BLACK sf::Color::Black
#define GRAY sf::Color(153, 153, 153)

/*
	Класс "игровое поле"
	Хранит в себе:
	-Текущее и следущее состояние поля
	-Размеры ячеек и поля
	-Тайминги задержек

*/
class GameField
{
private:
	//=========================================== приватные переменные
		

	//Текущее состояние поля
	std::vector<int> grid;
	//Следующее состояние поля
	std::vector<int> gridNext;


	//Размер ячеек
	const int CELL_SIZE = 20;
	//Ширина поля в ячейках
	const int GRID_WIDTH = 40;
	//Длина поля в ячейках
	const int GRID_HEIGHT = 30;
	//Общее количество ячеек
	const size_t N_CELLS = GRID_WIDTH * GRID_HEIGHT;
	//Шаг для задержки
	const int DELAY_INC = 50;
	//Регулятор скорости
	int delay = 100;
	//Глобальная пауза приложения
	bool isPlaying = false;
	//Флаг активации приложения на 1 шаг
	bool oneStep = false;

	//=============================================приватные методы
	int wrapValue(int v, int vMax);

public:
	GameField();
	//=============================================публичные методы

	//Получить значение ячейки текущей матрицы
	int get_grid(int x, int y);
	//Получить значение ячейки текущей матрицы
	int get_grid(int i);
	//Получить значение ячейки следующей матрицы
	int get_gridNext(int x, int y);
	//Получить значение ячейки следующей матрицы
	int get_gridNext(int i);

	//Установка значения в ячейку мартицы
	void set_grid(int x, int y, int val);
	//Установка значения в ячейку мартицы
	void set_grid(int i, int val);
	//Установка значения в ячейку мартицы
	void set_gridNext(int x, int y, int val);
	//Установка значения в ячейку мартицы
	void set_gridNext(int i, int val);	
	/*Запускаем игру
	*Тут же описан весь алгоритм
	*Уменьшить не получается, т.к. 
	*не получается передать window,
	*для работы с ним
	*/
	void runGame();

	~GameField() {};
};

