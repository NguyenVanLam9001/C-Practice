#include<iostream>
#include<string>
using namespace std;

int checkGame(char AA[3][3], int steps)
{
	//check row and collumn
	for (int i = 0; i < 3; i++)
	{
		if ((AA[i][0] == AA[i][1] && AA[i][1] == AA[i][2]) && AA[i][0] == 'O') {
			return 1;
		}
		else if (AA[0][i] == AA[1][i] && AA[1][i] == AA[2][i] && AA[0][i] == 'O') {
			return 1;
		}
		if ((AA[i][0] == AA[i][1] && AA[i][1] == AA[i][2]) && AA[i][0] == 'X') {
			return 2;
		}
		else if (AA[0][i] == AA[1][i] && AA[1][i] == AA[2][i] && AA[0][i] == 'X') {
			return 2;
		}
	}
	//check duong cheo
	if (AA[0][0] == AA[1][1] && AA[2][2] == AA[1][1] && AA[1][1] == 'O') {
		return 1;
	}
	else if (AA[0][2] == AA[1][1] && AA[2][0] == AA[1][1] && AA[1][1] == 'O') {
		return 1;
	}
	else if (AA[0][0] == AA[1][1] && AA[2][2] == AA[1][1] && AA[1][1] == 'X') {
		return 2;
	}
	else if (AA[0][2] == AA[1][1] && AA[2][0] == AA[1][1] && AA[1][1] == 'X') {
		return 2;
	}
	else if (steps == 9) {
		return 0;
	}
	else {
		return -1;
	}
}

void show(char A[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		cout << endl << "--------------------------" << endl;
		for (int j = 0; j < 3; j++)
		{
			cout << "|   " << A[i][j] << "   |";
		}
		cout << endl << "--------------------------" << endl;
	}

}

bool checkInput(char A[3][3], int value)
{
	int row = value / 10,
		col = value % 10;
	if (row < 1 || row > 3 || col < 1 || col > 3) {
		cout << "Your row and collumn is not correct !!!" << endl << "Please input again !!!" << endl;
		return false;
	}
	else if (A[row - 1][col - 1] == 'X' || A[row - 1][col - 1] == 'O') {
		cout << "Row " << row << " and collumn " << col << " has checked, please input again !!!" << endl;
		return false;
	}
	return true;
}

int main()
{
start: system("cls");
	char player1[9], player2[9];
	int mode;

	cout << "Welcome To Tic-tac-toe game! Play with your way!" << endl;
	cout << "If you find any problem, please contact nguyenvanlamqn1997@gmail.com" << endl;
	cout << "------------------------------------------------------------------" << endl;
	cout << "SELECT YOUR MODE (1 - PLAY GAME, OTHERS - EXIT GAME):" << endl;
	cin >> mode;

	if (mode == 1) {
		cout << "Enter Player 1 Name: ";
		cin >> player1;
		cout << "Enter Player 2 Name: ";
		cin >> player2;

		char A[3][3] = { ' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
		int steps = 0, value;
		bool turn = true;

		while (true) {
			show(A);
			int t = checkGame(A, steps);
			if (t == 1) {
				cout << "Player " << player1 << " win !!!" << endl;
				break;
			}
			else if (t == 2) {
				cout << "Player " << player2 << " win !!!" << endl;
				break;
			}
			else if (t == 0) {
				cout << "Draw !!!" << endl;
				break;
			}
			else {

			input: value = -1;
				if (turn) {
					cout << "Your Turn Fly - O: ";
				}
				else {
					cout << "Your Turn Fly - X: ";
				}
				cin >> value;
				if (!checkInput(A, value)) goto input;

				int row = value / 10,
					col = value % 10;
				A[row - 1][col - 1] = turn == true ? 'O' : 'X';

				steps++;
				turn = !turn;
			}
		}
		int replay = 0;
		cout << " ============================= " << endl;
		cout << "Do you want to play again ? (1 - Yes | others - No): ";
		cin >> replay;
		if (replay == 1) goto start;
	}
	else {
		cout << "Exit game ! See you again!" << endl;
	}
	system("pause");
}
