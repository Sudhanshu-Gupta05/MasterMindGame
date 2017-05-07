#include <string>

class Pieces;
class Player;

using namespace std;

#ifndef MASTERMIND_HEADER
#define MASTERMIND_HEADER


class MasterMindFactory {
public:
	MasterMindFactory() { }
	virtual Pieces* MakePiece() const ;
	virtual Player* MakePlayer(const string& player) const;
	virtual ~MasterMindFactory() { }
};

class MasterMindGame {
public:
	MasterMindGame (MasterMindFactory &factory,int pieces_on_board,const string &player1name,const string &player2name);
	//Driver function which allows two players to play
	virtual void user_input();
	Player* getPlayer(int playerno) const;
	virtual ~MasterMindGame();
private:
	Player *player1;
	Player *player2;
	Pieces **codeMaker;
	string *codeBreaker;
	int no_of_pieces;
	const int total_guess = 12;
};

//displays game message
void game_message();
//displays instructions
void show_instructions();
//shows additional game info
void show_info();
int getColourValue(string &colour);



#endif
