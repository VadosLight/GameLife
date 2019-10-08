#include "UserInterface.h"

void UserInterface::showHelp()
{
	std::cout << "==================================================" << std::endl;
	std::cout << "==================================================" << std::endl;
	std::cout << "==================INSTRUCTION=====================" << std::endl;
	std::cout << "\tPress P to pause/start" << std::endl;
	std::cout << "\tPress on rectan gle to change colour" << std::endl;
	std::cout << "\t<- and -> change speed" << std::endl;
	std::cout << "\tPress C to clear screen" << std::endl;
	std::cout << "==================================================" << std::endl;
	std::cout << "==================================================" << std::endl;
}

UserInterface::UserInterface()
{
	this->showHelp();
}

void UserInterface::saveWorld()
{
}

void UserInterface::loadWorld()
{
}

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