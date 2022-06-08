#include <iostream>
#include "wincheck.h"

using namespace std;

bool checkPos(char arr[][3], int x, int y) {
  if(arr[y][x] == '-') {
    return true;
  }else {
    return false;
  }
}



int place(char arr[][3], int player, int pos) {
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
		if(x > 2) {
			x = 0;
			y++;
		}
	}
  x--;

	if(checkPos(arr, x, y)) {
		arr[y][x] = piece;
		return 0;
	}else {
		cout << "That space is not available\n";
		return 1;
  }
}



void togglePlayer(int *player) {
  if(*player == 1) {
    *player = 2;
  }else if(*player == 2) {
    *player = 1;
  }
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
		cout << "Player " << player << ", Select where to place a piece.\n";
		dispArr(game);
		
		bool wait = true;
    
    while(wait){
      cin >> pos;
      if(pos > 9 || pos < 1) {
        cout << "Invalid position\n";
      }else {
        wait = false;
      }
    }
    
	int checkPlace = place(game, player, pos);
	if(checkWin(game, player) != 0) {
		cout << "Player " << player <<" won!" << endl;
		run = false;
	}
	if(checkPlace == 0)
		togglePlayer(&player);
	}
	
    return 0;
}
