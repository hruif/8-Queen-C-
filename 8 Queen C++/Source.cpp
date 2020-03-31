#include <iostream>
#include <vector>
using namespace std;
const int rows = 8;
const int columns = 8;
int board[rows][columns];
const int numberOfQueens = 8;
int totalSolutions = 0;

class Position;

vector<Position> queenPositions;

class Position {
public:
	int X;
	int Y;
};


bool checkTwoQSafe(Position one, Position two) {
	if (one.X == two.X || one.Y == two.Y) {
		return false;
	}
	if (one.X - two.X == one.Y - two.Y) {
		return false;
	}
	if (two.X - one.X == one.Y - two.Y) {
		return false;
	}
	return true;
}
bool checkSafe(vector<Position> *positions) {
	int nRows = positions->size();
	if (nRows < 2) {
		return true;
	}
	for (int i = 0; i < nRows - 1; i++) {
		for (int j = i + 1; j < nRows; j++) {
			if (checkTwoQSafe((*positions)[i], (*positions)[j]) == false) {
				return false;
			}
		}
	}
	return true;
}
void placeQueen(int queenNumber) {
	for (int i = 0; i < columns; i++) {
		board[queenNumber][i] = 1;
		Position *position = new Position();
		position->X = queenNumber;
		position->Y = i;
		queenPositions.push_back(*position);
		if (checkSafe(&queenPositions) == true){
			if (queenNumber == 7) {
				for (int j = 0; j < rows; j++)
				{
					for (int k = 0; k < columns; k++) {
						cout << board[j][k] << " ";
					}
					cout << endl;
				}
				cout << endl << endl;
				totalSolutions++;
			}
			else {
				placeQueen(queenNumber + 1);
			}
		}
		board[queenNumber][i] = 0;
		queenPositions.pop_back();
	}
}

int main() {
	placeQueen(0);
	cout << (totalSolutions);
}
