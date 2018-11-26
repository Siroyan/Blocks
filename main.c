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
	{0,1,3,4,0},
	{0,0,0,0,0}
};
int outputData[5][5] = {};
int plyrX = 1, plyrY = 2;		/* location of player */

int movePlayer(char);
int showDisplayData(void);
int integrateData(int, int);

int main(void){
	char buf;
	while(1){
		system("clear");
		integrateData(plyrX, plyrY);
		showDisplayData();
		printf("WASD Controll (q)uit>\n");		
		scanf("%c",&buf);
		     if(buf == 'w') movePlayer('w');/* move top */
		else if(buf == 'a') movePlayer('a');/* move left */
		else if(buf == 's') movePlayer('s');/* move under */
		else if(buf == 'd') movePlayer('d');/* move right */
		else if(buf == 'q') break;			/* quit */
	}	
	return 0;
}

/* Move player and Check destination */
int movePlayer(char dir){
	switch(dir) {
		case 'w':	
			if(field[plyrX-1][plyrY] == 1) plyrX--;
			break;
		case 'a':
			if(field[plyrX][plyrY-1] == 1) plyrY--;
			break;
		case 's':
			if(field[plyrX+1][plyrY] == 1) plyrX++;
			break;
		case 'd':
			if(field[plyrX][plyrY+1] == 1) plyrY++;
			break;
	}
}
/* Make output data from field and player data */
int integrateData(int plyrX, int plyrY){
	/* copy field data */
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			outputData[i][j] = field[i][j];
		}
	}
	outputData[plyrX][plyrY] = PLYR;
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
			printf("%d", field[i][j]);
		}
		printf("\n");
	}
	return 0;
}
