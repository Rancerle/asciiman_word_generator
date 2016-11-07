//Created by: Reilly Q. Curran
//last edited: 11/7/2016
//last compiled: 11/7/2016

#include<iostream>
#include<string>
#include <stdlib.h>

std::string words[30];
int points;
void setWords();
void playGame(int, int, int, int, int);

int main()
{
	std::cout << "Let's Play!" << std::endl;
	setWords();
	
	int draw = 0;
	int prevI = -1;
	int prevII = -2;
	int prevIII = -3;
	int i = 0;
	int score = 0;
			
	while (draw == prevI || draw == prevII || draw == prevIII)
	{
		draw = rand() % 29 + 0;
		if (draw == prevI || draw == prevII || draw == prevIII)
		{
			draw = rand() % 29 + 0;
		}
	}
	
	playGame(draw, prevI, prevII, prevII, score);
		
	return 0;
}

void playGame(int draw, int prevI, int prevII, int prevIII, int score)
{
	//************************
	std::string word;
	word = words[draw];
	std::string mystery = word;
	char guess;
	int win = 0;
	int lose = 0;
	int i = 0;
	int score = 0;
	int continueGame;
	int chances = 6;
	int failCheck;
	int wrongGuess;
	//*************************


	std::cout << "Games Won: " << score << std::endl;
	
	while (i < word.length())
	{
		mystery[i] = '?';
		i++;
	}

	while (win != 1 && lose != 1)
	{
		wrongGuess = 0;
		std::cout << mystery << std::endl;
		std::cout << "Guess a letter: ";
		std::cin >> guess;
		for (int j = 0; j < mystery.length(); j++)
		{
			if (guess == mystery[j])
			{
				mystery[j] = guess;
			}

			else
			{
				failCheck++;
			}
		}
		if (mystery == word)
		{
			std::cout << "Correct!  The word was " << word << ". " << std::endl;
			score++;
			win++;
		}
		else if (failCheck == mystery.length())
		{
			std::cout << "That was not a correct letter." << std::endl;
			chances--;
		}

		if (chances == -1)
		{
			std::cout << "Sorry, but the correct word was " << word << std::endl;
			lose++;
		}
		

	}

	std::cout << "Would you like to play again (1 to play again, 2 to end the game)?" << std::endl;
	std::cout << "Play again: ";
	std::cin >> continueGame;

	if (continueGame == 1)
	{
		prevIII = prevII;
		prevII = prevI;
		prevI = draw;
		while (draw == prevI || draw == prevII || draw == prevIII)
		{
			draw = rand() % 29 + 0;
			if (draw == prevI || draw == prevII || draw == prevIII)
			{
				draw = rand() % 29 + 0;
			}
		}

		playGame(draw, prevI, prevII, prevII, score);
	}

	else
	{
		std::cout << "okay, thanks for playing!" << std::endl;
	}
}

void setWords()
{
	words[0] = "google";
	words[1] = "twitter";
	words[2] = "facebook";
	words[3] = "reddit";
	words[4] = "youtube";
	words[5] = "tumblr";
	words[6] = "github";
	words[7] = "javascript";
	words[8] = "python";
	words[9] = "pearl";
	words[10] = "minecraft";
	words[11] = "darksouls";
	words[12] = "warcraft";
	words[13] = "starcraft";
	words[14] = "bloodborne";
	words[15] = "playstation";
	words[16] = "nintendo";
	words[17] = "microsoft";
	words[18] = "windows";
	words[19] = "pokemon";
	words[20] = "mario";
	words[21] = "halo";
	words[22] = "kirby";
	words[23] = "zelda";
	words[24] = "link";
	words[25] = "hyrule";
	words[26] = "ganon";
	words[27] = "saitama";
	words[28] = "goku";
	words[29] = "superman";
