#pragma once
#include <SFML/Graphics.hpp>
#include <time.h>
#include <vector>

#define WHITE sf::Color::White
#define BLACK sf::Color::Black
#define GRAY sf::Color(153, 153, 153)

/*
	����� "������� ����"
	������ � ����:
	-������� � �������� ��������� ����
	-������� ����� � ����
	-�������� ��������

*/
class GameField
{
private:
	//=========================================== ��������� ����������
		

	//������� ��������� ����
	std::vector<int> grid;
	//��������� ��������� ����
	std::vector<int> gridNext;


	//������ �����
	const int CELL_SIZE = 20;
	//������ ���� � �������
	const int GRID_WIDTH = 40;
	//����� ���� � �������
	const int GRID_HEIGHT = 30;
	//����� ���������� �����
	const size_t N_CELLS = GRID_WIDTH * GRID_HEIGHT;
	//��� ��� ��������
	const int DELAY_INC = 50;
	//��������� ��������
	int delay = 100;
	//���������� ����� ����������
	bool isPlaying = false;
	//���� ��������� ���������� �� 1 ���
	bool oneStep = false;

	//=============================================��������� ������
	int wrapValue(int v, int vMax);

public:
	GameField();
	//=============================================��������� ������

	//�������� �������� ������ ������� �������
	int get_grid(int x, int y);
	//�������� �������� ������ ������� �������
	int get_grid(int i);
	//�������� �������� ������ ��������� �������
	int get_gridNext(int x, int y);
	//�������� �������� ������ ��������� �������
	int get_gridNext(int i);

	//��������� �������� � ������ �������
	void set_grid(int x, int y, int val);
	//��������� �������� � ������ �������
	void set_grid(int i, int val);
	//��������� �������� � ������ �������
	void set_gridNext(int x, int y, int val);
	//��������� �������� � ������ �������
	void set_gridNext(int i, int val);	
	/*��������� ����
	*��� �� ������ ���� ��������
	*��������� �� ����������, �.�. 
	*�� ���������� �������� window,
	*��� ������ � ���
	*/
	void runGame();

	~GameField() {};
};

