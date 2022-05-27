#include "GuessMyNumber.h"
#include <iostream>
#include<cstdlib>
#include <ctime>

bool numberGuessed = false;

int GuessMyNumber::PlayGMN()
{
	// generates random numbers
	srand(static_cast<unsigned int>(time(0)));
	int guessNumber = rand() % 100 + 1;
	int tries = 5;
	int guess;

	while ((tries >= 0) && (numberGuessed == false))
	{
		std::cout << "Guess the number, you can't go to the next world until you do!" << std::endl;
		std::cout << "Tries = " << tries << std::endl;
		std::cin >> guess;

		if (guess > guessNumber)
		{
			std::cout << "Your number is too high!" << std::endl;
			--tries;
		}

		else if (guess < guessNumber)
		{
			std::cout << "Your number is too low!" << std::endl;
			--tries;
		}

		else if (guess == guessNumber + 5 || guess == guessNumber - 5)
		{
			std::cout << "You were close! Have another try!" << std::endl;
			++tries;
		}

		else
		{
			std::cout << "Guessed it! You still had: " << tries << "tries!" << std::endl;
			numberGuessed = true;
			return 0;
		}

		if (tries == 0)
		{
			std::cout << "You Lost! Better luck next time!" << std::endl;
			tries = 5;
		}

	}
    return 0;
}
