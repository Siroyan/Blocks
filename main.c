#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define WALL 0
#define EMPTY 1
#define PLYR 2
#define BLOCK 3
#define GOUL 4

/* FIELD DATA */
int field[5][5] = {
	{0,0,0,0,0},
	{0,1,1,1,0},
	{0,1,1,1,0},
	{0,1,1,1,0},
	{0,0,0,0,0}
};
int outputData[5][5] = {};
int plyrX = 1, plyrY = 2;	/* location of player */
int  blcX = 2,  blcY = 2;	/* location of block */
int goulX = 3, goulY = 3;	/* location of goul */

int movePlayer(char);
int moveBlock(char);
int showDisplayData(void);
int showDisplayDataNumerical(void);
int integrateData();

int main(void){
	char buf;
	while(1){
		system("clear");
		integrateData();
		showDisplayData();
		if(blcX == goulX && blcY == goulY) break;
		printf("WASD Controll (q)uit>\n");		
		scanf("%c",&buf);
		     if(buf == 'w') movePlayer('w');/* move top */
		else if(buf == 'a') movePlayer('a');/* move left */
		else if(buf == 's') movePlayer('s');/* move under */
		else if(buf == 'd') movePlayer('d');/* move right */
		else if(buf == 'q') break;			/* quit */
	}
	if(blcX == goulX && blcY == goulY) printf("Cleard the game!\n");
	return 0;
}

/* Move player and Check destination */
int movePlayer(char dir){
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
int moveBlock(char dir){
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
/* Make output data from field, player and block data */
int integrateData(){
	/* copy field data */
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			outputData[i][j] = field[i][j];
		}
	}
	outputData[plyrX][plyrY] = PLYR;
	outputData[blcX][blcY] = BLOCK;
	outputData[goulX][goulY] = GOUL;
	return 0;
}
/* Conv num to icon and show it */
int showDisplayData(){
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			if(outputData[i][j] == WALL)  printf("■ ");	
			if(outputData[i][j] == EMPTY) printf("□ ");
			if(outputData[i][j] == PLYR)  printf("● ");
			if(outputData[i][j] == BLOCK) printf("☆ ");
			if(outputData[i][j] == GOUL)  printf("★ ");
		}
		printf("\n");
	}
	return 0;
}
/* debug */
int showDisplayDataNumerical(){
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			printf("%d", outputData[i][j]);
		}
		printf("\n");
	}
	return 0;
}
