#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

#include "masterMind.h"
#include "Player.h"



int main()
{
	MasterMindFactory factory;

	game_message(); //Displays instructions and menu
	string player_name1;
	string player_name2;
	int no_of_pieces;
	int no_of_games = 0;
	int roleChange = 1;
	int game_Count = 1;
	//Enter player1 information
	cout << "\nEnter Player1 name : ";
	cin >> player_name1;

	//Enter player2 information
	cout << "\nEnter Player2 name : ";
	cin >> player_name2;

	do {

		cout<< "\nPlease enter number of pieces you want to play between 1-8(Default use 4) : ";
		cin >> no_of_pieces;
	} while (!(no_of_pieces >= 1) && !(no_of_pieces <= 8));



	MasterMindGame game(factory,no_of_pieces,player_name1,player_name2);


	do
	{
		cout << "\nDecide Even Number of Games to be played: ";
		cin >> no_of_games;
	}while(no_of_games % 2 != 0);

	MasterMindPlayer* player1 = dynamic_cast<MasterMindPlayer*>(game.getPlayer(1));

	if(!player1)
		return -1;

	MasterMindPlayer* player2 = dynamic_cast<MasterMindPlayer*>(game.getPlayer(2));

	if(!player2)
		return -1;



	cout << "\n" << player1->get_name()<<" is set as CodeMaker";
	player1->set_CodeMaker();

	cout << "\n"<< player2->get_name()<<" is set as CodeBreaker";
	player2->set_CodeBreaker();


	while(game_Count <= no_of_games)
	{

		srand(time(NULL)); //seeds the random generator
		//initialize the four game pieces [of class Pieces] that will be used to store the key
		//for Player:CodeBreaker
		cout << "\nCode has been set by CodeMaker Randomly!!!!";

		cout << "\nLets start Game Number " << game_Count << "!!!!!";
		game_Count++;

		//accepts user input and compares to secret key
		game.user_input();
		roleChange = 1 - roleChange;
		if(roleChange && game_Count <= no_of_games)
		{
			cout << "\nRoleChanged";
			cout << "\n" << player1->get_name() <<" is set as CodeMaker";
			cout << "\n" << player2->get_name() <<" is set as CodeBreaker";
			player1->set_CodeMaker();
			player2->set_CodeBreaker();

		}
		else if(!roleChange && game_Count <= no_of_games)
		{
			cout << "\nRoleChanged";
			cout << "\n" << player2->get_name() <<" is set as CodeMaker";
			cout << "\n" << player1->get_name() <<" is set as CodeBreaker";
			player1->set_CodeBreaker();
			player2->set_CodeMaker();
		}
	}
	if(player1->get_PlayerPoints() > player2->get_PlayerPoints())
	{
		cout << "\n" << player1->get_name() << "has won!!!Congratulations!!!\n";
	}
	else if(player1->get_PlayerPoints() < player2->get_PlayerPoints())
	{
		cout << "\n" << player2->get_name() << "has won!!!Congratulations!!!\n";
	}
	else
	{
		cout << "\nGame ended in Draw!!!!!\n";
	}

	return 0;
}
