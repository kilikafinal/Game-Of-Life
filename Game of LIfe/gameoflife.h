#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

class GameOfLife 
{	
private :
	int rows;
	int columns;
	int inputModeChoice; 
	int boardModeChoice; 
	int classicBoard;
	int doughnutBoard;
	int mirrorBoard;
	int waitChoice;
	bool alive;
	bool dead;
	bool** board;
	bool** shadowBoard;
	int selectInput();
	int selectMode();
	int shouldWait();
	void initEmptyBoard(int tmpRow, int tmpColumn);
	void updateBoundary();
	void copyToShadowBoard();
	void copyShadowToMainBoard();
	bool checkLifeStatus();
	int checkNeighbors(int tmpRow, int tmpColumn);
	void updateShadowBoard(int tmpRow, int tmpColumn, int neighbors);
	void populateBoard();
	void printBoard();
	void printShadow();
	bool checkChange();
	
public :
	void test();
	void runSimulation();
	GameOfLife();
};

#endif
