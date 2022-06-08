#include <iostream>
#include "wincheck.h"

using namespace std;

//checks if chosen space is available
bool checkPos(char arr[][3], int x, int y) {
  if(arr[y][x] == '-') {
    return true;
  }else {
    return false;
  }
}


//places piece on the board by changing value in array
int place(char arr[][3], int player, int pos) {
	int x = 0;
	int y = 0;
	char piece;
	
	//sets piece depending on the player
	if(player == 1) {
		piece = 'X';
	}
	if(player == 2) {
		piece = 'O';
	}
	
	//converts a number into a position on the game board array
	for(int i = 0; i < pos; i ++) {
		x++;
		if(x > 2) {
			x = 0;
			y++;
		}
	}
	x--;
	
	//checks to see if the position in the array is available
	//if available the piece will be placed
	if(checkPos(arr, x, y)) {
		arr[y][x] = piece;
		return 0;
	}else {
		cout << "That space is not available\n";
		return 1;
  }
}


//toggles the current player
void togglePlayer(int *player) {
  if(*player == 1) {
    *player = 2;
  }else if(*player == 2) {
    *player = 1;
  }
}


//displays a 3x3 array in the console
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


//main function
int main()
{
	//initializing variables
	int player = 1;
	int pos;
	int turns = 0;
	bool run = true;
	
	//numbers on array corrospond to the game board positions
	char tut[3][3] = {
		{'1', '2', '3'}, 
		{'4', '5', '6'},
		{'7', '8', '9'}
	};
    
	//game board array
	char game[3][3] = {
		{'-', '-', '-'}, 
		{'-', '-', '-'},
		{'-', '-', '-'}
	};
	
	//explain game
	cout << "This is the game board.\n";
	dispArr(tut);
	cout << "When you are prompted to place a piece,\n";
	cout << "select the position to place it in.\n";
	
	//main game loop
	while(run) {
		//counts the number of turns
		turns ++;
		
		//player choses where to place piece
		cout << "Player " << player << ", Select where to place a piece.\n";
		dispArr(game);
		bool wait = true;
		
		while(wait){
			cin >> pos;
			//verifies piece will be placed on the board
			if(pos > 9 || pos < 1) {
				cout << "Invalid position\n";
			}else {
				wait = false;
			}
		}
		
		//places piece on the selected space if the space is free
		int checkPlace = place(game, player, pos);

		//checks to is if the last piece placed ended the game by either winning or a draw
		if(checkWin(game, player) != 0) {
			cout << "Player " << player <<" won!" << endl;
			run = false;
			dispArr(game);
		}else if(turns == 9) {
			cout << "Nobody won, Tie" << endl;
			 run = false;
		}
		
		//if the piece was succesfully placed change to the next player
		//otherwise redo the current player's turn
		if(checkPlace == 0)
			togglePlayer(&player);
		}
	
    return 0;
}
