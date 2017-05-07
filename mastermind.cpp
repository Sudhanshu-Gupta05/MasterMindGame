#include <iostream>
#include <map>
#include <string>
#include <utility>

#include "masterMind.h"
#include "Pieces.h"
#include "Player.h"


Pieces* MasterMindFactory::MakePiece() const
{
	return new MasterMindPieces();
}

Player* MasterMindFactory::MakePlayer(const string& playername) const
{
	return new MasterMindPlayer(playername);
}



int getColourValue(string &colour)
{
	if(colour == "red")
		return 0;
	else if(colour == "orange")
		return 1;
	else if(colour == "yellow")
		return 2;
	else if(colour == "green")
		return 3;
	else if(colour == "blue")
		return 4;
	else if(colour == "magenta")
		return 5;
	else if(colour == "violet")
		return 6;
	else if(colour == "white")
		return 7;

	return -1;
}

void game_message() {
	int choice = 0;

	cout << "Welcome to MASTERMIND! The code breaking game for two players.";

	while (choice != 3) {
		cout << "\nHit 1 for instructions.\nHit 2 to for game info.\nHit 3 to begin. ";
		cin >> choice;
		switch (choice) {
			case 1:
				show_instructions();
				break;
			case 2:
				show_info();
				break;
			case 3:
				break; //continue with game
			default:
				cout << "\nYou did not enter a valid choice, please try again.";
		}
	}
}

void show_instructions() {
	cout << "The two players decide in advance how many games they will play which has to be an even number."
			"\nOne player becomes codemaker and the other codebreaker."
			"\nCodemaker randomly chooses a pattern of 4 colors from below list."
			"\nCodeBreaker tries to guess pattern in both order and color in 12 turns."
			"\nColors are:\n\tRed\n\tOrange\n\tYellow"
			"\n\tGreen\n\tBlue\n\tMagenta\n\tViolet\n\tWhite\nNext, use the clues to determine your next guess:\n\tX means right color right place"
			"\n\tO means right color wrong place.";
	cout << "\nExample:\n\tCode:\tRed\tYellow\tBlue\tWhite\n\tGuess:\tRed\tGreen\tWhite\tOrange\n\tResult: X O";
	cout << "\nFor Detailed Instructions please read user manual.";
}

void show_info() {

	cout << "\nMastermind Game is a code-breaking game for two players."
			"\nPlayed between two players ,one CodeMaker and other CodeBreaker"
			"\nCodeMaker sets the code while CodeBreaker breaks the code with minimum guesses\n";
}

MasterMindGame::MasterMindGame (MasterMindFactory &factory,int pieces_on_board, const string &player1name, const string& player2name)
{
	player1 = factory.MakePlayer(player1name);
	player2 = factory.MakePlayer(player2name);
	no_of_pieces = pieces_on_board;
	codeMaker = new Pieces*[no_of_pieces];

	for(int i = 0; i< no_of_pieces; i++)
	{
		codeMaker[i] = factory.MakePiece();
	}

	codeBreaker = new string[no_of_pieces];

}

MasterMindGame::~MasterMindGame()
{
	delete player1;
	delete player2;
	delete[] codeBreaker;

	for(int i = 0; i< no_of_pieces; i++)
	{
		delete codeMaker[i];
	}

	delete codeMaker;

}

Player* MasterMindGame::getPlayer(int playerno) const
{
	if(playerno == 1)
		return player1;
	else
		return player2;
}


void MasterMindGame::user_input()
{
	int guess = 0;
	int counter = 0;
	int point = 1;

	// multimap of codeValue i.e. color and position
	multimap<int,int> codeMakerMap;

	MasterMindPlayer* mastermindplayer1 = dynamic_cast<MasterMindPlayer*>(player1);
	MasterMindPlayer* mastermindplayer2 = dynamic_cast<MasterMindPlayer*>(player2);


	for(int i = 0 ; i < 4 ; i++ )
	{
		MasterMindPieces* mastermindcodeMaker = dynamic_cast<MasterMindPieces*>(codeMaker[i]);
		codeMakerMap.insert(pair<int,int>(mastermindcodeMaker->getValue(),i));
	}

	while(guess < total_guess)
	{
		counter = 0;
		int valid_Colors = 1;

		do {

			valid_Colors = 1;

			if (!mastermindplayer1->get_PlayerCode()) {
				cout << "\n" << mastermindplayer1->get_name()
						<< " Please enter four colors separated by a space: ";
			}

			else {
				cout << "\n" << mastermindplayer2->get_name()
						<< " Please enter four colors separated by a space: ";
			}

			for(int i = 0; i < no_of_pieces; i++)
			{
				cin >> codeBreaker[i];
			}
			//Check if correct colors have been added

			for (int i = 0; i < 4; i++)
			{
				int value = getColourValue(codeBreaker[i]);
				if (value == -1)
				{
					valid_Colors = 0;
				}
			}
		} while (valid_Colors == 0);


		//multimap of codeValue i.e. color and position
		multimap<int,int> codeBreakerMap;

		for(int i = 0 ; i < 4 ; i++ )
		{
			int value = getColourValue(codeBreaker[i]);
			if(value == -1)
				continue;
			codeBreakerMap.insert(pair<int,int>(value,i));
		}

		for(int i = 0; i < 4 ; i++)
		{
			int value = getColourValue(codeBreaker[i]);

			if(codeMakerMap.find(value) == codeMakerMap.end())
				continue;
			else
			{
				// Exist but duplicates exist of that color and may have been removed from CodeBreaker
				if(codeBreakerMap.find(value) == codeBreakerMap.end())
					continue;

				auto retItrCodeBreaker = codeBreakerMap.equal_range(value);
				auto retItrCodeMaker = codeMakerMap.equal_range(value);
				int initial_counter = counter;

				for(auto itr_codeBreaker = retItrCodeBreaker.first ; itr_codeBreaker != retItrCodeBreaker.second ; itr_codeBreaker++)
				{
					for(auto itr_codeMaker = retItrCodeMaker.first; itr_codeMaker != retItrCodeMaker.second ; itr_codeMaker++)
					{
						if(itr_codeMaker->second == itr_codeBreaker->second)
						{
							cout << "X";
							counter++;
						}
					}
				}

				if(initial_counter == counter)
				{
					cout << "0";
				}

				codeBreakerMap.erase(value);
			}

		}

		//For each guess point is awarded to CodeMaker
		if(mastermindplayer1->get_PlayerCode() == 1)
		{
			mastermindplayer1->set_PlayerPoints(point);
		}
		else
		{
			mastermindplayer2->set_PlayerPoints(point);
		}

		if(counter == 4)
		{
			cout << "\nCongratulations!!!!!Code succesfully cracked";
			return ;
		}

		guess++;
	}

	//If all guesses expires , award extra point to CodeMaker
	if(mastermindplayer1->get_PlayerCode() == 1)
	{
		mastermindplayer1->set_PlayerPoints(point);
	}
	else
	{
		mastermindplayer2->set_PlayerPoints(point);
	}

	return;

}
