#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "field.h"
#include "key.h"
#define EMPT 0
#define WALL 1
#define PLYR 2
#define BAGG 3
#define GOUL 4

#define FINI 7

/* FIELD DATA */
extern int field[10][10];
int outputData[10][10];
int plyrX = 1, plyrY = 2;	/* location of player */
/* PREAMBLE */
int checkDestOne(char);
int checkDestTwo(char);
int checkClear();
void move(char);
void movePlayer(char);
void moveBaggage(char);
void showDisplayData(void);
void cpData(void);
extern char getch(void);

int main(void){
	cpData();
	while(1){
		system("clear");
		showDisplayData();
		if(checkClear()){
			printf("Cleard the game!\n");
			break;
		}
		move(getch());
	}
	return 0;
}

void move(char dir){
	if(checkDestOne(dir) == BAGG){
		if(checkDestTwo(dir) != WALL && checkDestTwo(dir) != FINI){
			moveBaggage(dir);
			movePlayer(dir);
		}
	}else{
		if(checkDestOne(dir) != WALL){
			movePlayer(dir);
		}
	}
}

void moveBaggage(char dir){
	if(dir == 'w'){
		outputData[plyrX-2][plyrY] += outputData[plyrX-1][plyrY];
		outputData[plyrX-1][plyrY] = 0;
	}
	if(dir == 'a'){
		outputData[plyrX][plyrY-2] += outputData[plyrX][plyrY-1];
		outputData[plyrX][plyrY-1] = 0;
	}
	if(dir == 's'){
		outputData[plyrX+2][plyrY] += outputData[plyrX+1][plyrY];
		outputData[plyrX+1][plyrY] = 0;

	}
	if(dir == 'd'){
		outputData[plyrX][plyrY+2] += outputData[plyrX][plyrY+1];
		outputData[plyrX][plyrY+1] = 0;
	}
}

void movePlayer(char dir){
	//outputData[plyrX][plyrY] = 0;
	if(dir == 'w') plyrX--;
	if(dir == 'a') plyrY--;
	if(dir == 's') plyrX++;
	if(dir == 'd') plyrY++;
}

int checkDestOne(char dir){
	if(dir == 'w') return outputData[plyrX-1][plyrY];
	if(dir == 'a') return outputData[plyrX][plyrY-1];
	if(dir == 's') return outputData[plyrX+1][plyrY];
	if(dir == 'd') return outputData[plyrX][plyrY+1];
}

int checkDestTwo(char dir){
	if(dir == 'w') return outputData[plyrX-2][plyrY];
	if(dir == 'a') return outputData[plyrX][plyrY-2];
	if(dir == 's') return outputData[plyrX+2][plyrY];
	if(dir == 'd') return outputData[plyrX][plyrY+2];
}

void cpData(){
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			outputData[i][j] = field[i][j];
		}
	}
}

void showDisplayData(){

	//outputData[plyrX][plyrY] = PLYR;
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			if(i == plyrX && j == plyrY){
				printf("● ");
			}else if(outputData[i][j] == WALL){
				printf("■ ");
			}else if(outputData[i][j] == EMPT){
				printf("  ");
			}else if(outputData[i][j] == BAGG){
				printf("□ ");
			}else if(outputData[i][j] == GOUL){
				printf("☆ ");
			}else if(outputData[i][j] == FINI){
				printf("★ ");
			}
		}
		printf("\n");
	}
}

int checkClear(){
	
}

/*
void showDisplayData(){
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			printf(" %d",outputData[i][j]);			
		}
		printf("\n");
	}
}
*/
