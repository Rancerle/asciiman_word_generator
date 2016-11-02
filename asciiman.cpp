//Created by: Reilly Q. Curran
//last edited: 10/31/2016
//last compiled: 10/31/2016

#include<iostream>
#include<string>
#include <stdlib.h>

std::string words[30];
int points;
void setWords();

int main()
{
	setWords();
	std::string word;
	int draw = 0;
	int prevI = -1;
	int prevII = -2;
	int prevIII = -3;
	int i = 0;
	while (i < 10)
	{
		
		while (draw == prevI || draw == prevII || draw == prevIII)
		{
			draw = rand() % 29 + 0;
			if (draw == prevI || draw == prevII || draw == prevIII)
			{
				draw = rand() % 29 + 0;
			}
		}
		word = words[draw];
		std::cout << word << std::endl;
		prevIII == prevII;
		prevII == prevI;
		prevI = draw;
		i++;
	}
	return 0;
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
	words[11] = "dark souls";
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
}
