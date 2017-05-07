#include <string>

using namespace std;

#ifndef Player_HEADER
#define Player_HEADER

class Player {
public:
	virtual void set_CodeMaker() = 0;
	virtual void set_CodeBreaker() = 0;
	virtual ~Player() { };
};

class MasterMindPlayer : public Player {
		public:
			MasterMindPlayer(string player_name);
			const string& get_name();
			virtual void set_CodeMaker();
			virtual void set_CodeBreaker();
			void set_PlayerPoints(const int &point);
			const int& get_PlayerCode() const;
			const int& get_PlayerPoints() const;
			~MasterMindPlayer() { }
		private:
			int codeMaker;
			int codeBreaker;
			int total_points;
			string name;

};

#endif
