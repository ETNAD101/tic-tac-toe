#include <iostream>
using namespace std;

int checkPos() {
	return 0;
}

void place(char arr[][3], int player, int pos) {
	int x = 0;
	int y = 0;
	char piece;

	if(player == 1) {
		piece = 'X';
	}
	if(player == 2) {
		piece = 'O';
	}

	for(int i = 0; i < pos; i ++) {
		x++;
		if(x > 3) {
			x = 0;
			y++;
		}
	}
	cout << x;
	cout << y;
	
}


void dispArr(char arr[][3]) {	
	cout << "-------";
	cout << endl;
	for(int x = 0; x < 3; x++) {
		cout << "|";
		for(int y = 0; y < 3; y++) {
			cout << arr[x][y] << "|";
		}
		cout << endl;
		cout << "-------" << endl;
	}
}


int main()
{
	int player = 1;
	int pos;
	bool run = true;
	
	char tut[3][3] = {
		{'1', '2', '3'}, 
		{'4', '5', '6'},
		{'7', '8', '9'}
	};
    
	char game[3][3] = {
		{'-', '-', '-'}, 
		{'-', '-', '-'},
		{'-', '-', '-'}
	};
	
	cout << "This is the game board.\n";
	dispArr(tut);
	cout << "When you are prompted to place a piece,\n";
	cout << "select the position to place it in.\n";
	
	while(run) {
		cout << "Player" << player << ", Select where to place a piece.\n";
		dispArr(game);
		
		cin >> pos;
		place(game, player, pos);

		run = !run;
	}

    return 0;
}
