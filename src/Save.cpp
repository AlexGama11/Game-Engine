#include "Save.h"
#include <iostream>
#include <fstream>
#include "GameManager.h"

int linenumber = 0;

bool Save::SaveFile(std::string savetext, int targetline)
{
	// Create and open a text file
	std::fstream saveFile("../saves/saveFile.txt");

	//Int to not make it loop infinitely
	int readFile = 0;

	// Write to the file
	saveFile << savetext;

	while (linenumber < targetline && getline(saveFile, savetext) && readFile >= 1)
	{
		linenumber++;
		readFile++;
	}

	if (linenumber == targetline)
	{
		// Output the text from the file
		saveFile << savetext;
	}

	//closes the file
	saveFile.close();

	return true;
}

bool Save::LoadFile(std::string savetext, int targetline)
{
	//Int to not make it loop infinitely
	int readFile = 0;

	// Read from the text file
	std::ifstream saveFile("../saves/saveFile.txt");

	if (!saveFile)
	{
		// Create and open a text file
		std::fstream saveFile("../saves/saveFile.txt");

		// Write to the file
		saveFile << gamerName;

		// Use a while loop together with the getline() function to read the file line by line once
		while (linenumber < targetline && getline(saveFile, savetext) && readFile >= 1)
		{
			linenumber++;
			readFile++;
		}

		if (linenumber == targetline)
		{
			// Output the text from the file
			std::cout << savetext << std::endl;
		}

		// Close the file
		saveFile.close();
	}

	while (linenumber < targetline && getline(saveFile, savetext) && readFile >= 1)
	{
		linenumber++;
		readFile++;
	}

	if (linenumber == targetline)
	{
		// Output the text from the file
		std::cout << savetext << std::endl;
	}

	gamerName = savetext;

	// Close the file
	saveFile.close();

	return true;
}
