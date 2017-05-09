# MasterMindGame
Basic Implementation of mastermind game( Requirement Analysis doc can be found in the repositry)

Requirement Analysis:
Description:
Mastermind is a code-breaking game for two players. Game is played between two players, one
is codemaker and codebreaker. CodeMaker sets the code while codebreaker breaks that code
with minimum possible number of guesses .
Rules:
∑ The two players decide in advance how many games they will play, which must be an even
number.
∑
∑ One player becomes the codemaker, the other the codebreaker.
∑
∑
∑ The codebreaker tries to guess the pattern, in both order and color, within twelve turns.
∑ If there are duplicate colors in the guess, they cannot all be awarded a key code unless they
correspond to the same number of duplicate colors in the hidden code.
∑ Once feedback is provided, another guess is made; guesses and feedback continue to
alternate until either the codebreaker guesses correctly, or twelve incorrect guesses are
made.
∑ The codemaker gets one point for each guess a codebreaker makes. An extra point is
earned by the codemaker if the codebreaker doesn't guess the pattern exactly in the last
guess. The winner is the one who has the most points after the agreed-upon number of
games is played.
The codemaker chooses a pattern of four code pieces. Duplicates are allowed, so the player
could even choose four code pieces of the same color.
Each guess is made by placing a row of code pieces on the decoding board.
Once placed, the codemaker provides feedback by placing from zero to four key codes in the
small holes of the row with the guess. A code ‘X’ is placed for each code pieces from the
guess which is correct in both color and position. A code ‘0’ the existence of a correct color
code piece placed in the wrong position.


