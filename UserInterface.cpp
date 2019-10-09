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
	std::cout << "\tPress N to go to next step (while pause)" << std::endl;
	std::cout << "==================================================" << std::endl;
	std::cout << "==================================================" << std::endl;
}

UserInterface::UserInterface()
{
	showHelp();
}

void UserInterface::saveWorld()
{

}

void UserInterface::loadWorld()
{

}