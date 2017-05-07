#include "Player.h"


//MasterMindPlayer Class Begin

MasterMindPlayer::MasterMindPlayer(string player_name) {
	codeMaker = 0;
	codeBreaker = 0;
	total_points = 0;
	name = player_name;
}

void MasterMindPlayer::set_CodeMaker() {
	codeMaker = 1;
	codeBreaker = 0;
}
void MasterMindPlayer::set_CodeBreaker() {
	codeMaker = 0;
	codeBreaker = 1;

}
void MasterMindPlayer::set_PlayerPoints(const int &point) {
	total_points += point;
}

const int& MasterMindPlayer::get_PlayerCode() const {
	return codeMaker;
}

const int& MasterMindPlayer::get_PlayerPoints() const {
	return total_points;
}

const string& MasterMindPlayer::get_name()
{
	return name;
}


