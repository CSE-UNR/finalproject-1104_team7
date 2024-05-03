//Authors: Andrew Huck and Bella Picasso-Kennedy
//Purpose: 
//Class: CS 135-1104

#define READ_FILE_NAME "numbers.txt"
#define ROWS 5
#define COLUMNS 5
#include <stdio.h>

void getMenuChoice();
void changeBrightness(int rows, int columns, int photo2DArray[][columns]);
int brightnessConversion();
int readFile(FILE* fin, int rows, int columns, int photo2DArray[][columns]);//edit prototype to work with a 2d array pointer.

int main() {
	int originalPicture[ROWS][COLUMNS];
	int run;
	FILE* fp;
	
	fp = fopen(READ_FILE_NAME, "r");
	if (fp == NULL){
		printf("File did not open\n");
	}
	else{
		run = readFile(fp, ROWS, COLUMNS, originalPicture);
		
		fclose(fp);
	//getMenuChoice();
	}
	
	return 0;
}

void getMenuChoice(){
	int userInput;
	int photo2DArray[ROWS][COLUMNS];
	
	printf("0. Load New Image\n");
	printf("1. Display current image\n");
	printf("2. Edit the current image\n");
	printf("3. Exit\n");
	printf("Enter your choice: " );

	scanf("%d", &userInput);
	
	switch(userInput){
	
	case 0: 
		  //readFile(ROWS,COLUMNS,photo2DArray);
		  break;
	case 1: 
		  brightnessConversion();
		  break;
		  
	case 2: 
		  break;
	
	case 3: 
		  break;
	}

}

int brightnessConversion(int rows, int columns, int photo2DArray[][columns]){
	//char brightnessArray[ROWS][COLUMNS] = {0};
	//int photo2DArray[ROWS][COLUMNS] = {0};
	//for(int iRows = 0; iRows < ROWS; iRows++){
		//for(int iCols = 0; iCols < COLUMNS; iCols++){
		//photo2DArray[iRows][iCols] = 1;
		//}
	//}
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
int readFile(FILE* fin,int rows, int columns, int photo2DArray[][columns]){//need to add pointers to be able to add the photo2DArray variable to others functions
		int inFuncArray[ROWS][COLUMNS];
		
			for(int iRows = 0; iRows < ROWS; iRows++){
				for(int iCols = 0; iCols < COLUMNS; iCols++){
					fscanf(fin, "%d", &inFuncArray[iRows][iCols]);
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
		

void changeBrightness(int rows, int columns, int photo2DArray[][columns]){
	int inFuncArray[ROWS][COLUMNS];
	int answer;
	printf("Would you like to dim or brighten this image (1 = dim, 0 = brighten)";
	scanf("&d", &answer);
	if (answer == 1){
		for(int iRows = 0; iRows < ROWS; iRows++){
				for(int iCols = 0; iCols < COLUMNS; iCols++){
					if (photo2DArray[iRows][iCols] == 0){
						photo2DArray[iRows][iCols] = 0;
					}
					else if (photo2DArray[iRows][iCols] == 1){
						photo2DArray[iRows][iCols] = 0;
					}
					else if (photo2DArray[iRows][iCols] == 2){
						photo2DArray[iRows][iCols] = 1;
					}
					else if (photo2DArray[iRows][iCols] == 3){
						photo2DArray[iRows][iCols] = 2;
					}
					else if (photo2DArray[iRows][iCols] == 4){
						photo2DArray[iRows][iCols] = 3;
					}
				}
			}
	}
	else{
		for(int iRows = 0; iRows < ROWS; iRows++){
				for(int iCols = 0; iCols < COLUMNS; iCols++){
					if (photo2DArray[iRows][iCols] == 0){
						photo2DArray[iRows][iCols] = 1;
					}
					else if (photo2DArray[iRows][iCols] == 1){
						photo2DArray[iRows][iCols] = 2;
					}
					else if (photo2DArray[iRows][iCols] == 2){
						photo2DArray[iRows][iCols] = 3;
					}
					else if (photo2DArray[iRows][iCols] == 3){
						photo2DArray[iRows][iCols] = 4;
					}
					else if (photo2DArray[iRows][iCols] == 4){
						photo2DArray[iRows][iCols] = 4;
					}
				}
			}
	}
	
}


