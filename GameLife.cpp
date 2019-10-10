#include "UserInterface.h"
#include "GameField.h"

//сохранить/загрузить карту

//убрать магические переменные
//сделать final классы, const noexcept методы
//описать правила игры в хелпе

int main()
{		
	UserInterface().showHelp();
	GameField().run_Game();		
}