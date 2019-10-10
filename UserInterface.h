#pragma once
#include <iostream>
#include <filesystem>
#include <locale>
#include <fstream>

class UserInterface final
{

public:
	UserInterface();
	void showHelp() const noexcept;	

	std::string validSaveFilename() const  noexcept;
	std::string validOpenFilename() const;
	~UserInterface() = default;
};

