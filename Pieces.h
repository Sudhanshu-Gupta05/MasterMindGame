#include <string>

using namespace std;

#ifndef Pieces_HEADER
#define Pieces_HEADER

enum Colour {red, orange, yellow, green, blue, magenta, violet, white};

class Pieces {
public:
	virtual void setColour(Colour given_colour) = 0;
	virtual ~Pieces() { };
};


class MasterMindPieces : public Pieces {
	public:
		MasterMindPieces(); //constructor that defines the colour randomly.
		void setColour();
		virtual void setColour(Colour given_colour);
		char getColourletter() const;
		void getColour() const;
		int getValue() const;
		~MasterMindPieces() { }
	private:
		std::string string_colour;
		int value;
};

#endif
