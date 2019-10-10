#include "UserInterface.h"
#include "GameField.h"

void UserInterface::showHelp() const noexcept
{
	
	std::cout << "\t\t\t==================================================" << std::endl;
	std::cout << "\t\t\t==================================================" << std::endl;
	std::cout << "\t\t\t==================INSTRUCTION=====================" << std::endl;
	std::cout << "\t\t\t\tPress P to pause/start" << std::endl;
	std::cout << "\t\t\t\tPress on rectan gle to change colour" << std::endl;
	std::cout << "\t\t\t\t<- and -> change speed" << std::endl;
	std::cout << "\t\t\t\tPress C to clear screen" << std::endl;
	std::cout << "\t\t\t\tPress N to go to next step (while pause)" << std::endl;
	std::cout << "\t\t\t\tPress S/O to Save/Open world" << std::endl;
	std::cout << "\t\t\t==================================================" << std::endl;	
	std::cout << "\t\t\t==================================================" << std::endl;
	std::cout << "The universe of the Game of Life is an infinite, two-dimensional orthogonal grid of square cells,\n\
each of which is in one of two possible states, alive or dead, (or populated and unpopulated, respectively).\n\
Every cell interacts with its eight neighbours, which are the cells that are horizontally, vertically,\n\
or diagonally adjacent. At each step in time, the following transitions occur:\n\
\tAny live cell with fewer than two live neighbours dies, as if by underpopulation.\n\
\tAny live cell with two or three live neighbours lives on to the next generation.\n\
\tAny live cell with more than three live neighbours dies, as if by overpopulation.\n\
\tAny dead cell with exactly three live neighbours becomes a live cell, as if by reproduction." << std::endl;
	std::cout << "==============================================================================================================" << std::endl;
}

std::string UserInterface::validOpenFilename() const 
{
	
	std::string tmpFilename;
	std::ifstream out;
	do {
		std::cout << "Input name file, where saved the file: ";
		std::cin >> tmpFilename;
		out.open(tmpFilename);
	} while (!out.is_open());

	out.close();
	return tmpFilename;
}

std::string UserInterface::validSaveFilename() const noexcept
{

	std::string tmpFilename;
	std::ofstream out;
	do {
		std::cout << "Input name file, where file would be saved: ";
		std::cin >> tmpFilename;
		out.open(tmpFilename);
	} while (!out.is_open());

	out.close();
	return tmpFilename;
}

UserInterface::UserInterface()
{
	std::cout << std::endl;
}
