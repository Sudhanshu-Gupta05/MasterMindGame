#include "Pieces.h"

#include <cstdlib>
#include <iostream>


MasterMindPieces::MasterMindPieces() {
	string_colour = " ";
	value = -1;
	setColour();
}

void MasterMindPieces::setColour() {
	//The rand function is seeded in main
	value = rand() % 8;
	switch (value) {
	case 0:
		string_colour = "red";
		break;
	case 1:
		string_colour = "orange";
		break;
	case 2:
		string_colour = "yellow";
		break;
	case 3:
		string_colour = "green";
		break;
	case 4:
		string_colour = "blue";
		break;
	case 5:
		string_colour = "magenta";
		break;
	case 6:
		string_colour = "violet";
		break;
	case 7:
		string_colour = "white";
		break;
	}
}

void MasterMindPieces::setColour(Colour given_colour) {
	value = given_colour;
	switch (value) {
		case 0:
			string_colour = "red";
			break;
		case 1:
			string_colour = "orange";
			break;
		case 2:
			string_colour = "yellow";
			break;
		case 3:
			string_colour = "green";
			break;
		case 4:
			string_colour = "blue";
			break;
		case 5:
			string_colour = "magenta";
			break;
		case 6:
			string_colour = "violet";
			break;
		case 7:
			string_colour = "white";
			break;
	}
}

void MasterMindPieces::getColour() const {
	cout << string_colour << " ";
}

char MasterMindPieces::getColourletter() const {
	return string_colour[0];
}

int MasterMindPieces::getValue() const
{
	return value;
}

//color pieces class end
