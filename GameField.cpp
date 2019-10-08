#include "GameField.h"

GameField::GameField()
{
	CELL_SIZE = 20;
	GRID_WIDTH = 40;
	GRID_HEIGHT = 30;
	N_CELLS = GRID_WIDTH * GRID_HEIGHT;

	grid = new int [N_CELLS];
	gridNext = new int[N_CELLS];
}

int GameField::get_CELL_SIZE()
{
	return CELL_SIZE;
}

int GameField::get_GRID_WIDTH()
{
	return GRID_WIDTH;
}

int GameField::get_GRID_HEIGHT()
{
	return GRID_HEIGHT;
}

int GameField::get_N_CELLS()
{
	return N_CELLS;
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

GameField::~GameField()
{
	delete[] grid;
	delete[] gridNext;
}
