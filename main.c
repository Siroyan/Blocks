#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "field.h"
#include "key.h"
#define WALL 0
#define EMPT 1
#define PLYR 2
#define BAGG 3
#define GOUL 4

/* FIELD DATA */
extern int field[10][10];
int outputData[10][10];
int plyrX = 1, plyrY = 2;	/* location of player */
int baggX = 7, baggY = 7;	/* location of BAGG */
int goulX = 8, goulY = 1;	/* location of goul */
/* PREAMBLE */
int checkDest(int,int,char);
void move(char);
void moveElement(char,char);
void showDisplayData(void);
void integrateData(void);
extern char getch(void);

int main(void){
	while(1){
		system("clear");
		integrateData();
		showDisplayData();
		if(baggX == goulX && baggY == goulY){
			printf("Cleard the game!\n");
			break;
		}
		move(getch());
	}
	return 0;
}

void move(char dir){
	if(checkDest(plyrX, plyrY, dir) == BAGG){
		if(checkDest(baggX, baggY, dir) != WALL){
			moveElement('B', dir);
			moveElement('P', dir);
		}
	}else{
		printf("%d\n",checkDest(plyrX, plyrY, dir));
		if(checkDest(plyrX, plyrY, dir) == EMPT){
			moveElement('P', dir);
		}
	}
}

void moveElement(char element, char dir){
	if(dir == 'w') element == 'P' ? plyrX-- : baggX--;
	if(dir == 'a') element == 'P' ? plyrY-- : baggY--;
	if(dir == 's') element == 'P' ? plyrX++ : baggX++;
	if(dir == 'd') element == 'P' ? plyrY++ : baggY++;
}

int checkDest(int x, int y, char dir){
	if(dir == 'w') return outputData[x-1][y];
	if(dir == 'a') return outputData[x][y-1];
	if(dir == 's') return outputData[x+1][y];
	if(dir == 'd') return outputData[x][y+1];
}

void integrateData(){
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			outputData[i][j] = field[i][j];
		}
	}
	outputData[plyrX][plyrY] = PLYR;
	outputData[baggX][baggY] = BAGG;
	outputData[goulX][goulY] = GOUL;
}

void showDisplayData(){
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			if(outputData[i][j] == WALL) printf("■ ");	
			if(outputData[i][j] == EMPT) printf("  ");
			if(outputData[i][j] == PLYR) printf("● ");
			if(outputData[i][j] == BAGG) printf("★ ");
			if(outputData[i][j] == GOUL) printf("☆ ");
		}
		printf("\n");
	}
}
