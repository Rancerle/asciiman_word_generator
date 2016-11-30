//Created by: Reilly Q. Curran
//last edited: 11/29/2016
//last compiled: 11/29/2016

#include<iostream>
#include<string>
//couldn't decide what randomizer was better
#include <stdlib.h>
#include <time.h>

//allows the word and hint to be indexed in the same place
struct randWord
{
	std::string word;
	std::string hint;
};

//creates an empty array of words for the program to initialize
randWord words[30];

//function prototypes for setWords and playGame
void setWords();
void playGame(int, int, int, int, int);

int main()
{
	//tracker that allows the user to know the game is starting up
	std::cout << "Let's Play!" << std::endl;

	//sets the list of words that can be in play
	setWords();
	
	//--------------------------------
	int draw = 0; //the variable that will randomly pick the index
	//will stop the game from using indexes it has already called in the last three games
	int prevI = -1; 
	int prevII = -2;
	int prevIII = -3;
	// an initialized score for the function call
	int score = 0;
	//----------------------------------
	
	//prevents a random number call from being the same as it was in the last three games
	while (draw == prevI || draw == prevII || draw == prevIII)
	{
		draw = rand() % 29 + 0;
		if (draw == prevI || draw == prevII || draw == prevIII)
		{
			draw = rand() % 29 + 0;
		}
	}
	
	//calls the game
	playGame(draw, prevI, prevII, prevII, score);
		
	return 0;
}

void playGame(int draw, int prevI, int prevII, int prevIII, int score)
{
	//************************
	std::string wordChosen; //the indexed word
	std::string guessWord = ""; //the word the player guesses if they choose to risk it all
	wordChosen = words[draw].word;

	std::string mystery = wordChosen; // what will be displayed to the player
	//the letter by letter guess input
	char guess;
	//the user's input for if they want to risk the game to guess the whole word
	int risk = 0;
	//iterates when the user wins or looses
	int win = 0;
	int lose = 0;
	//a loop iterator that does not throw a warning if it is iterating by an undefined number (the length of a random word)
    size_t i = 0;
	//asks the user if they want to play again
	int continueGame;
	//iterates down when the user gets a letter wrong until the user looses
	int chances = 6;
	//iterates if the letter guessed does not equal the letter indexed by the checker
	int failCheck = 0;
	//*************************

	//displays the games the player has won
	std::cout << "Games Won: " << score << std::endl;
	
	while (i < wordChosen.length())
	{
		//sets the mystery word to a length of ascii characters equal in length to the word
		mystery[i] = '?';
		i++;
	}

	while (win != 1 && lose != 1)
	{
		failCheck = 0;
		//displays the mystery characters (for test purposes it displays the word right now)
		std::cout << wordChosen + mystery << std::endl;
		//displays the users remaining chances and asks what they would like to do
		std::cout << "You have " << chances + 1 << " guesses left." << std::endl;
		std::cout << "Would you like to guess a letter or try to guess the word?" << std::endl;
		std::cout << "(1: guess a letter, 2: guess the word): ";
		std::cin >> risk; // user decides if they want to guess a word or letter
	
		switch (risk) //lets the user choose between playing normally, or risking the game on trying to guess the whole word
		{
		case 1: //Plays game as usual
			std::cout << "Guess a letter: ";
			std::cin >> guess;
			//compares the user's guess to the characters in the string
			for (size_t j = 0; j < mystery.length(); j++)
			{
				if (wordChosen[j] == guess)
				{
					mystery[j] = guess;
					//the letter the user guessed is equal to the index
				}

				else
				{
					failCheck++;
					//the letter the user guessed does not equal the index
				}
			}
			//win, lose, continue conditions
			if (mystery == wordChosen)//if the user has completed the word
			{
				std::cout << "Correct!  The word was " << wordChosen << ". " << std::endl;
				score++;
				win++;
			}
			else if (failCheck == mystery.length())//if the user guessed a wrong letter
			{
				std::cout << "That was not a correct letter." << std::endl;
				if (chances == 6)
				{
					chances--;
					break;
				}
				else if (chances == 5)
				{
					chances--;
					break;
				}
				else if (chances == 4)
				{
					chances--;
					break;
				}
				else if (chances == 3)
				{
					std::cout << "You seem to be having trouble, here's a hint!" << std::endl;
					std::cout << words[draw].hint << std::endl;
					chances--;
					break;
				}
				else if (chances == 2)
				{
					chances--;
					break;
				}
				else if (chances == 1)
				{
					chances--;
					break;
				}
				else if (chances == 0)
				{
					chances--;
					break;
				}
				else if (chances == -1) // if the user lost
				{
					std::cout << "Sorry, but the correct word was " << wordChosen << std::endl;
					lose++;
				}
			}
			break;
		case 2: //prompts the user to guess the full word 
			std::cout << "Alright, what's the word?: ";
			std::cin >> guessWord;
			if (guessWord == wordChosen)
			{
				// the player gussed the correct word
				std::cout << "That is correct!  You Win!" << std::endl;
				score++;
				win++;
			}
			else
			{
				//the user guessed incorrectly
				std::cout << "Nope!  You Lose!" << std::endl;
				lose++;
			}
			break;
		default: //prevents the user from choosing outside the given options
			std::cout << "I am sorry, this was not one of the given choices." << std::endl;
			break;
		}
	}
	//asks the user if they want to play again
	std::cout << "Would you like to play again (1 to play again, 2 to end the game)?" << std::endl;
	std::cout << "Play again: ";
	std::cin >> continueGame;


	//if the user wants to play again, the randomization process from int main() is repeated with this games index stored back one
	// and the game before that moved back one and so on and so forth.
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
		//loops the game via recursion
		playGame(draw, prevI, prevII, prevIII, score);
	}
	//quits the game
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
