#include "Save.h"
#include <iostream>
#include <fstream>
#include "GameManager.h"


bool Save::SaveFile()
{
	// Create and open a text file
	std::ofstream saveFile("../saves/saveFile.txt");

	// Write to the file
	saveFile << gamerName;

	//closes the file
	saveFile.close();

    return true;
}

bool Save::LoadFile()
{
	// Create a text string, which is used to output the text file
	std::string fromFile;

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
		while (saveFile >> fromFile && readFile >= 1) {
			// Output the text from the file
			std::cout << fromFile << std::endl;
			//increment readFile
			readFile++;
		}

		// Close the file
		saveFile.close();
	}

	// Use a while loop together with the getline() function to read the file line by line once
	while (saveFile >> fromFile && readFile >= 1) {
		// Output the text from the file
		std::cout << fromFile << std::endl;
		//increment readFile
		readFile++;
	}

	gamerName = fromFile;

	// Close the file
	saveFile.close();

	return true;
}
