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
	{0,3,1,1,0},
	{0,1,1,1,0},
	{0,1,1,4,0},
	{0,0,0,0,0}
};

int showDisplayData(void);
int integrateData(int, int);

int main(void){
	int plyrX = 1;		/* location of player */
	int plyrY = 1;		/* location of player */
	char buf;
	while(1){
		system("clear");
		showDisplayData();
		printf("wasd Controll (q)uit>\n");		
		scanf("%c",&buf);
		     if(buf == 'w') ;		/* move top */
		else if(buf == 'a') ;		/* move left */
		else if(buf == 's') ;		/* move under */
		else if(buf == 'd') ;		/* move right */
		else if(buf == 'q') break;		/* quit */
		integrateData(plyrX, plyrY);
	}	
	return 0;
}
/* make output data from field and player data */
int integrateData(int plyrX, int plyrY){
	int outputData[5][5];
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			outputData[i][j] = field[i][j];		/* copy field data */
		}
	}
	outputData[plyrX][plyrY] = PLYR;
}

int showDisplayData(){
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			if(field[i][j] == WALL)  printf("■ ");	
			if(field[i][j] == EMPTY) printf("□ ");
			if(field[i][j] == PLYR)  printf("○ ");
			if(field[i][j] == BLOCK) printf("☆ ");
			if(field[i][j] == GOUL)  printf("★ ");
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
