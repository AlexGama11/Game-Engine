#include "Save.h"
#include <iostream>
#include <fstream>
#include "GameManager.h"

int linenumber = 0;

bool Save::SaveFile(const std::string* savetext)
{
	//std::string savedata[100];
	int count = 0;

	// Create and open a text file
	std::ofstream saveFile("../saves/saveFile.txt");

	for (int i = 0; i < 100; i++)
	{
		saveFile << savetext[i] << "\n";
	}

	//closes the file
	saveFile.close();

	return true;
}

bool Save::LoadFile(std::string* savetext)
{
	//std::string savedata[100];
	int count = 0;

	// Read from the text file
	std::ifstream saveFile("../saves/saveFile.txt");

	if (!saveFile)
	{
		// Create and open a text file
		std::fstream saveFile("../saves/saveFile.txt");

		while (!saveFile.eof())
		{
			std::getline(saveFile, savetext[count++]);
		}

		// Close the file
		saveFile.close();
	}

	while (!saveFile.eof())
	{
		std::getline(saveFile, savetext[count++]);
	}

	return true;
}