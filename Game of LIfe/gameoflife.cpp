#include "gameoflife.h"

#include <iostream>
#include <stdlib.h>
using namespace std;

 GameOfLife::GameOfLife(){
	 boardModeChoice; 
	 classicBoard = 1;
	 doughnutBoard = 2;
	 mirrorBoard = 3;
	 alive = true;
	 dead = false;
}

void GameOfLife::initEmptyBoard(int tmpRow, int tmpColumn){
	rows = tmpRow+2;
	columns = tmpColumn+2;
	
	board = new bool*[rows];
	for(int i = 0; i <rows ; ++i){
		board[i] = new bool[columns];
	}
	
	for(int i =0 ; i < rows; ++i){
		for(int j = 0; j < columns; ++j){
			board[i][j] = dead;
			
		}
		
	}
	
	

	
}
int GameOfLife::checkNeighbors(int tmpRow, int tmpColumn){
	int numNeighborsAlive = 0;
	for(int i = (tmpRow-1);i < (tmpRow+2); ++i){
		for(int j = (tmpColumn-1); j < (tmpColumn+2); ++j){
			if(i ==tmpRow && j == tmpColumn){
			}else{
				if(board[i][j]){
					numNeighborsAlive+=1;
				}
			}
			
		}
	}
	return numNeighborsAlive;
}
void GameOfLife::updateShadowBoard(int tmpRow, int tmpColumn, int neighbors){
	
	if(neighbors ==2){	
	}else if(neighbors ==3){
		shadowBoard[tmpRow][tmpColumn] = alive;
	}else{
		shadowBoard[tmpRow][tmpColumn] = dead;
	}
	
	
}

bool GameOfLife::checkLifeStatus(){
	int numOfNeighbors;
	for(int i = 1; i < rows -1; ++i){
		numOfNeighbors = 0;
		for(int j = 1; j <columns -1; ++j){
			numOfNeighbors = checkNeighbors(i,j);
			updateShadowBoard(i,j,numOfNeighbors);
		}
	}
	
	if(checkChange()){
	copyShadowToMainBoard();
	updateBoundary();
	return true;
}
return false;
}

bool GameOfLife::checkChange(){
	for(int i =0; i < rows; ++i){
		for(int j = 0; j < columns; ++j){
			if(board[i][j] != shadowBoard[i][j]){
				return true;
			}
		}
	}
	return false;
	
}

void GameOfLife::copyShadowToMainBoard(){
	for(int i =1; i < rows-1; ++i){
		for(int j = 1; j < columns-1; ++j){
			board[i][j] = shadowBoard[i][j];
			
		}
	}

}

	void GameOfLife::copyToShadowBoard(){
		shadowBoard = new bool*[rows];
	for(int i = 0; i <rows; ++i){
		shadowBoard[i] = new bool[columns];
	}
		for(int i =0 ; i < rows; ++i){
		for(int j = 0; j < columns; ++j){
			shadowBoard[i][j] = board[i][j];
			
		}
		
	}
}

void GameOfLife::populateBoard(){
	srand(time(NULL));
	int randNum = 0;
	for(int i =1; i <rows-1; ++i){
		for(int j = 1; j <columns-1; ++j){
		randNum = rand()%2;
		if(randNum ==1){
			board[i][j] = alive;
		}else{
			
			board[i][j] = dead;
		}
		}
	}
}

int GameOfLife::selectInput(){ //works

	cout <<" what height?" <<endl;
	cin >> rows;
	cout <<" what length?" <<endl;
	cin >>columns;
	return 0;
}
int GameOfLife::selectMode(){ //works
	int validInput = false;
	int input;
	while(!validInput){
	cout << "what game mode would you like?" << endl;
	cout << "1. Classic. all locations off grid are empty" <<endl;
	cout << "2. Doughnut. board wraps horizontally and vertically" <<endl;
	cout << "3. Mirror. board at edges mirrors closest board square" <<endl;
	cin >> input;
	validInput = true;
	}
	validInput = false;

	return input;
}
int GameOfLife::shouldWait(){
	int validInput = false;
		int input;
		while(!validInput){
		cout << "Would you like to press enter before going on to next cycle?" <<endl;
		cout <<"1. yes" <<endl;
		cout <<"2. no" <<endl;
		cin >> input;
	validInput = true;
	}
	return input;
}

void GameOfLife::updateBoundary(){ //done
	if(boardModeChoice == classicBoard){
		
		for(int i = 0; i < rows; ++i){
			board[i][0] = dead;
			board[i][columns-1] = dead;
		}
		for(int i = 0; i<columns; ++i){
			board[0][i] = dead;
			board[rows-1][i] = dead;
		}
		
		
	}else if(boardModeChoice == doughnutBoard){
		for(int i = 1; i <rows-1; ++i){
			board[i][0] =board[i][columns-2];
			board[i][columns-1] = board[i][1];
		}
		
		for(int i = 1; i <columns-1; ++i){
			board[0][i] = board[rows-2][i];
			board[rows-1][i] = board[1][i];
		}
		board[0][0] = board[rows-2][columns-2];
		board[0][columns-1] = board[rows-2][1];
		board[rows-1][0] = board[1][columns-2];
		board[rows-1][columns-1] = board[1][1];
		
		
	}else if(boardModeChoice == mirrorBoard){
		for(int i = 1; i < rows-1; ++i){
			board[i][0] = board[i][1];
			board[i][columns-1]= board[i][columns-2];
		}
		for(int i = 1; i <columns-1; ++i){
			board[0][i] = board[1][i];
			board[rows-1][i] = board[rows-2][i];
		}
		
	}else{
				for(int i = 0; i < rows; ++i){
			board[i][0] = dead;
			board[i][columns-1] = dead;
		}
		for(int i = 0; i<columns; ++i){
			board[0][i] = dead;
			board[rows-1][i] = dead;
		}
		
	}
	
	copyToShadowBoard();
	
}
void GameOfLife::test(){
	playGame();
}

void GameOfLife::printBoard(){  //works
	for(int i = 1; i < rows-1; ++i){
		for(int j = 1; j< columns-1; ++j){
			cout << board[i][j];
			
		}
		cout <<endl;
	}
}void GameOfLife::printShadow(){  //works
	for(int i = 0; i < rows; ++i){
		for(int j = 0; j< columns; ++j){
			cout << shadowBoard[i][j];
			
		}
		cout <<endl;
	}
}

void GameOfLife::playGame(){
	selectInput();
	boardModeChoice = selectMode();
	waitChoice = shouldWait();
	initEmptyBoard(rows,columns);
	populateBoard();
	updateBoundary();
	while(true){
	cout <<endl;
	
	if(checkLifeStatus()){
	}else{
		cout << "board is now static. exiting program" <<endl;
		break;
	}
	printBoard();
	if(waitChoice == 1){
		cout <<"press enter to continue" <<endl;
		cin.ignore();
	}
}
}
