#include <iostream>
#include "wincheck.h"

using namespace std;

int wc1[3][2] = {
	{0, 0},
	{1, 0},
	{2, 0}
};



void coords(int row, int *x, int *y) {
	*x = wc1[row][0];
	*y = wc1[row][1];
}



int checkWin(char arr[][3], int player) {
	int x;
	int y;
	int inarow = 0;
	char piece;
	if(player == 1) {
		piece = 'X';
	}
	if(player == 2) {
		piece = 'O';
	}
	
	for(int i = 0; i < 3; i++) {
		coords(i, &x, &y);
		if(arr[x][y] == piece) {
			inarow++;
			cout << inarow;
		}
	}

	if(inarow == 3) {
		return player;
	}

	return 0;
}
