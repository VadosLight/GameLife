#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>

#define WHITE sf::Color::White
#define BLACK sf::Color::Black
#define GRAY sf::Color(153, 153, 153)
class GameField
{
private:
	int* grid;
	int* gridNext;

public:
	GameField();
	//переменные
	const int CELL_SIZE = 20;
	const int GRID_WIDTH = 40;
	const int GRID_HEIGHT = 30;
	const int N_CELLS = GRID_WIDTH * GRID_HEIGHT;
	const int DELAY_INC = 50;
	//
	int delay = 100;
	//
	bool isPlaying = false;
	bool oneStep = false;
	//методы
	int get_grid(int x, int y);
	int get_grid(int i);
	int get_gridNext(int x, int y);
	int get_gridNext(int i);

	void set_grid(int x, int y, int val);
	void set_grid(int i, int val);
	void set_gridNext(int x, int y, int val);
	void set_gridNext(int i, int val);

	void calcGrid();
	int wrapValue(int v, int vMax);
	
	~GameField();
};

