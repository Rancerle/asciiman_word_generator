//Created by: Reilly Q. Curran
//last edited: 11/23/2016
//last compiled: 11/23/2016

#include<iostream>
#include<string>
#include <stdlib.h>
#include <time.h>

struct randWord
{
	std::string word;
	std::string hint;
};

randWord words[30];
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
	std::string wordChosen;
	std::string guessWord = "";
	wordChosen = words[draw].word;
	std::string mystery = wordChosen;
	char guess;
	int risk = 0;
	int win = 0;
	int lose = 0;
    size_t i = 0;
	int continueGame;
	int chances = 6;
	int failCheck = 0;
	int wrongGuess;
	//*************************


	std::cout << "Games Won: " << score << std::endl;
	
	while (i < wordChosen.length())
	{
		mystery[i] = '?';
		i++;
	}

	while (win != 1 && lose != 1)
	{
		wrongGuess = 0;
		std::cout << wordChosen/*mystery*/ << std::endl;
		std::cout << "You have " << chances << " guesses left." << std::endl;
		std::cout << "Would you like to guess a letter or try to guess the word?" << std::endl;
		std::cout << "(1: guess a letter, 2: guess the word): ";
		std::cin >> risk;
		while (risk != 1 && risk != 2)
		{
			if (risk != 1 && risk != 2) 
			{
				std::cout << "That was not an acceptable option please choose one of the given options." << std::endl;
				std::cout << "(1: guess a letter, 2: guess the word): ";
				std::cin >> risk;
			}
			
		}
		switch (risk) //lets the user choose between playing normally, or risking the game on trying to guess the whole word
		{
		case 1: //Plays game as usual
			std::cout << "Guess a letter: ";
			std::cin >> guess;
			for (size_t j = 0; j < mystery.length(); j++)
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
			if (mystery == wordChosen)//if the user has completed the word
			{
				std::cout << "Correct!  The word was " << wordChosen << ". " << std::endl;
				score++;
				win++;
			}
			else if (failCheck == mystery.length())//if the user guessed a wrong letter
			{
				std::cout << "That was not a correct letter." << std::endl;
				chances--;

				switch (chances)
				{
				case 3:// if the user is struggling
					std::cout << "You seem to be having trouble, here's a hint!" << std::endl;
					std::cout << words[draw].hint << std::endl;
					break;

				case -1:// if the user lost
					std::cout << "Sorry, but the correct word was " << wordChosen << std::endl;
					lose++;
					break;
				default:
					std::cout << "Place holder statement." << std::endl;
					break;
				}
			}
			break;
		case 2: //prompts the user to guess the full word 
			std::cout << "Alright, what's the word?: ";
			std::cin >> guessWord;
			if (guessWord == wordChosen)
			{
				std::cout << "That is correct!  You Win!" << std::endl;
				score++;
				win++;
			}
			else
			{
				std::cout << "Nope!  You Lose!" << std::endl;
				lose++;
			}
			break;
		default:
			std::cout << "I am sorry, this was not one of the given choices." << std::endl;
			break;
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

		playGame(draw, prevI, prevII, prevIII, score);
	}

	else
	{
		std::cout << "okay, thanks for playing!" << std::endl;
	}
}

void setWords() //establsihes the random words and hints
{
	words[0] = { "google", "Have a question, try searching it!" };
	words[1] = { "twitter", "Sounds like a bird."};
	words[2] = { "facebook", "Where you likely get all of your news" };
	words[3] = { "reddit", "There's a thread for everyone!" };
	words[4] = { "youtube", "COMMENTS!" };
	words[5] = { "tumblr", "Think, 'Not 4-chan'..." };
	words[6] = { "github", "Open Source FTW" };
	words[7] = { "javascript", "Programming language known for web based gaming" };
	words[8] = { "python", "Programming Language good for making a database search engine" };
	words[9] = { "pearl", "Programming Language, Everyone hates it" };
	words[10] = { "minecraft", "BLOCKS EVERYWHERE!" };
	words[11] = { "darksouls", "Prepare to Die..." };
	words[12] = { "warcraft", "World of..." };
	words[13] = { "starcraft", "Zerg Rush!" };
	words[14] = { "bloodborne", "kinda like darksouls" };
	words[15] = { "playstation", "There's four of them." };
	words[16] = { "nintendo", "Plumbers, monsters, and heroes oh my!" };
	words[17] = { "microsoft", "Word, Excel, Powerpoint, etc..." };
	words[18] = { "windows", "Wait, doesn't 9 come before 10?" };
	words[19] = { "pokemon", "Sun and Moon" };
	words[20] = { "mario", "It's a me!" };
	words[21] = { "halo", "spartan" };
	words[22] = { "kirby", "Surprisingly dark for a pink marshmallow..." };
	words[23] = { "zelda", "The legend of..." };
	words[24] = { "link", "No, his name is not zelda." };
	words[25] = { "Bowser", "King koopa" };
	words[26] = { "ganon", "triforce of power" };
	words[27] = { "saitama", "ONE PUUUUUUUUUUUNCH!!!" };
	words[28] = { "goku", "The super saiyan" };
	words[29] = { "superman", "Faster than a speeding bullet..." };
}
