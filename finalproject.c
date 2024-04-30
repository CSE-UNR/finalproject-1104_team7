//Authors: Andrew Huck and Bella Picasso-Kennedy
//Purpose: 
//Class: CS 135-1104

#define READ_FILE_NAME "numbers.txt"
#define ROWS 5
#define COLUMNS 5
#include <stdio.h>

int getMenuChoice();

int brightnessConversion();
void readFile(int rows, int columns, int photo2DArray[ROWS][COLUMNS]);//edit prototype to work with a 2d array pointer.

int main() {
	int photo2DArray[ROWS][COLUMNS];
	getMenuChoice();
	brightnessConversion();
	readFile(ROWS,COLUMNS, photo2DArray);
	return 0;
}

int getMenuChoice(){
	int userInput;
	
	printf("0. Load New Image\n");
	printf("1. Display current image\n");
	printf("2. Edit the current image\n");
	printf("3. Exit\n");
	printf("Enter your choice: " );

	scanf("%d", &userInput);

	return userInput;
}

int brightnessConversion(){
	char brightnessArray[ROWS][COLUMNS] = {0};
	int photo2DArray[ROWS][COLUMNS] = {0};
	for(int iRows = 0; iRows < ROWS; iRows++){
		for(int iCols = 0; iCols < COLUMNS; iCols++){
		photo2DArray[iRows][iCols] = 1;
		}
	}
	for(int iRows = 0; iRows < ROWS; iRows++){
		for(int iCols = 0; iCols < COLUMNS; iCols++){
			if (photo2DArray[iRows][iCols] == 0){
				brightnessArray[iRows][iCols] = ' ';
			}
			else if (photo2DArray[iRows][iCols] == 1){
				brightnessArray[iRows][iCols] = '.';
			}
			else if (photo2DArray[iRows][iCols] == 2){
				brightnessArray[iRows][iCols] = 'o';
			}
			else if (photo2DArray[iRows][iCols] == 3){
				brightnessArray[iRows][iCols] = 'O';
			}
			else if (photo2DArray[iRows][iCols] == 4){
				brightnessArray[iRows][iCols] = '0';
			}
		}
		
	}
	for(int iRows = 0; iRows < ROWS; iRows++){
		for(int iCols = 0; iCols < COLUMNS; iCols++){
		printf("%c", brightnessArray[iRows][iCols]);
		}
		printf("\n");
	}	
}
void readFile(int rows, int columns, int photo2DArray[rows][columns]){//need to add pointers to be able to add the photo2DArray variable to others functions
		int inFuncArray[ROWS][COLUMNS];
		FILE* fp;
		fp = fopen(READ_FILE_NAME, "r");
		if (fp == NULL){
			printf("File did not open\n");
		}
		else{
			for(int iRows = 0; iRows < ROWS; iRows++){
				for(int iCols = 0; iCols < COLUMNS; iCols++){
					fscanf(fp, "%d", &inFuncArray[iRows][iCols]);
					photo2DArray[iRows][iCols] = inFuncArray[iRows][iCols];
				}
			}
			for(int iRows = 0; iRows < ROWS; iRows++){
				for(int iCols = 0; iCols < COLUMNS; iCols++){
					printf("%d", photo2DArray[iRows][iCols]);
				}
				printf("\n");
			}
			}
		fclose(fp);
}
