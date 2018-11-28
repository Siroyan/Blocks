#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "field.h"
#include "key.h"
#define WALL 0
#define EMPTY 1
#define PLYR 2
#define BLOCK 3
#define GOUL 4

/* FIELD DATA */
extern int field[10][10];
int outputData[10][10];
int plyrX = 1, plyrY = 2;	/* location of player */
int  blcX = 7,  blcY = 7;	/* location of block */
int goulX = 8, goulY = 1;	/* location of goul */

int checkDest(int,int,char);
void movePlayer(char);
void moveBlock(char);
void showDisplayData(void);
void integrateData(void);
extern char getch(void);

int main(void){
	char buf;
	while(1){
		system("clear");
		integrateData();
		showDisplayData();
		if(blcX == goulX && blcY == goulY){
			printf("Cleard the game!\n");
			break;
		}
		printf("WASD Controll (q)uit>\n");		
		buf = getch();
			 if(buf == 'w') movePlayer('w');/* move top */
		else if(buf == 'a') movePlayer('a');/* move left */
		else if(buf == 's') movePlayer('s');/* move under */
		else if(buf == 'd') movePlayer('d');/* move right */
		else if(buf == 'q') break;			/* quit */
	}
	return 0;
}

/* Move player and Check destination */
void movePlayer(char dir){
	switch(dir) {
		case 'w':	
			if(plyrX-1 == blcX && plyrY == blcY) moveBlock('w');
			if(field[plyrX-1][plyrY] == EMPTY && !(plyrX-1 == blcX && plyrY == blcY) && !(plyrX-1 == goulX && plyrY == goulY)) plyrX--;
			break;
		case 'a':
			if(plyrX == blcX && plyrY-1 == blcY) moveBlock('a');
			if(field[plyrX][plyrY-1] == EMPTY && !(plyrX == blcX && plyrY-1 == blcY) && !(plyrX == goulX && plyrY-1 == goulY)) plyrY--;
			break;
		case 's':
			if(plyrX+1 == blcX && plyrY == blcY) moveBlock('s');
			if(field[plyrX+1][plyrY] == EMPTY && !(plyrX+1 == blcX && plyrY == blcY) && !(plyrX+1 == goulX && plyrY == goulY)) plyrX++;
			break;
		case 'd':
			if(plyrX == blcX && plyrY+1 == blcY) moveBlock('d');
			if(field[plyrX][plyrY+1] == EMPTY && !(plyrX == blcX && plyrY+1 == blcY) && !(plyrX == goulX && plyrY+1 == goulY)) plyrY++;
			break;
	}
}
/* Move block and Check destination */
void moveBlock(char dir){
	switch(dir) {
		case 'w':	
			if(field[blcX-1][blcY] == EMPTY) blcX--;
			break;
		case 'a':
			if(field[blcX][blcY-1] == EMPTY) blcY--;
			break;
		case 's':
			if(field[blcX+1][blcY] == EMPTY) blcX++;
			break;
		case 'd':
			if(field[blcX][blcY+1] == EMPTY) blcY++;
			break;
	}
}

/* Check destination empty?*/
int checkDest(int x, int y, char dir){
	return 0;
}

/* Make output data from field, player and block data */
void integrateData(){
	/* copy field data */
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			outputData[i][j] = field[i][j];
		}
	}
	outputData[plyrX][plyrY] = PLYR;
	outputData[blcX][blcY] = BLOCK;
	outputData[goulX][goulY] = GOUL;
}
/* Conv num to icon and show it */
void showDisplayData(){
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			if(outputData[i][j] == WALL)  printf("■ ");	
			if(outputData[i][j] == EMPTY) printf("□ ");
			if(outputData[i][j] == PLYR)  printf("● ");
			if(outputData[i][j] == BLOCK) printf("★ ");
			if(outputData[i][j] == GOUL)  printf("☆ ");
		}
		printf("\n");
	}
}