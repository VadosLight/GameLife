#pragma once
class GameField
{
private:
	int CELL_SIZE;
	int GRID_WIDTH;
	int GRID_HEIGHT;
	int N_CELLS;

	int* grid;
	int* gridNext;

public:
	GameField();
	int get_CELL_SIZE();
	int get_GRID_WIDTH();
	int get_GRID_HEIGHT();
	int get_N_CELLS();

	int get_grid(int x, int y);
	int get_grid(int i);
	int get_gridNext(int x, int y);
	int get_gridNext(int i);

	void set_grid(int x, int y, int val);
	void set_grid(int i, int val);
	void set_gridNext(int x, int y, int val);

	~GameField();
};

