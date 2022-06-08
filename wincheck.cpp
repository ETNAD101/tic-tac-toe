#include <iostream>
#include "wincheck.h"

using namespace std;

//win positions
int wc1[8][3][2] = {
	{
		{0, 0},	//X--
		{1, 0},	//X--
		{2, 0}  //X--
	},
	{
		{0, 1}, //-X-
		{1, 1}, //-X-
		{2, 1}  //-X-
	},
	{
		{0, 2}, //--X
		{1, 2}, //--X
		{2, 2}  //--X
	},
	{
		{0, 0}, //XXX
		{0, 1}, //---
		{0, 2}  //---
	},
	{
		{1, 0}, //---
		{1, 1}, //XXX
		{1, 2}  //---
	},
	{
		{2, 0}, //---
		{2, 1}, //---
		{2, 2}  //XXX
	},
	{
		{0, 0}, //X--
		{1, 1}, //-X-
		{2, 2}  //--X
	},
	{
		{0, 2}, //--X
		{1, 1}, //-X-
		{2, 2}  //X--
	}
};


//grabs the coords from the win conditions array
//and assigns the x and y values to variables
void coords(int pattern, int row, int *x, int *y) {
	*x = wc1[pattern][row][0];
	*y = wc1[pattern][row][1];
}


//checks if a player has won the game
int checkWin(char arr[][3], int player) {
	//initialize variables
	int x;
	int y;
	int inarow = 0;
	char piece;

	//sets piece depending on player
	if(player == 1) {
		piece = 'X';
	}
	if(player == 2) {
		piece = 'O';
	}
	
	//checks the specified coords of all the win positions
	//if the specified piece is found in 3 in a row
	//the function returns the player number
	//otherwise it returns a 0
	for(int pattern = 0; pattern < 8; pattern++) {
		for(int coordset = 0; coordset < 3; coordset++) {
			coords(pattern, coordset, &x, &y);
			if(arr[x][y] == piece) {
				inarow++;
			}
		}
		if(inarow == 3) {
			return player;
		}
		inarow = 0;
	}
  
	return 0;
}
