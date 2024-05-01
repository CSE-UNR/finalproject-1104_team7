//Authors: Andrew Huck and Bella Picasso-Kennedy
//Purpose: 
//Class: CS 135-1104

#define READ_FILE_NAME "numbers.txt"
#define SIZE 100
#define ROWS 5
#define COLUMNS 5

#include <stdio.h>

void getMenuChoice();

int brightnessConversion(int rows, int columns, int photo2DArray[][columns]);
void readFile(int rows, int columns, int photo2DArray[][columns], char *file);//otype to work with a 2d array pointer.

int main() {

	getMenuChoice();
	
	
	return 0;
}

void getMenuChoice(){
	int photo2DArray[ROWS][COLUMNS];
	char fileName[SIZE];
	int brightnessArray[ROWS][COLUMNS];
	int userInput;
	
	printf("**ERINSTAGRAM**\n");
	printf("0. Load New Image\n");
	printf("1. Display current image\n");
	printf("2. Edit the current image\n");
	printf("3. Exit\n");
	printf("Enter your choice: " );
	scanf("%d", &userInput);
	
	do{
		switch(userInput){
			case 0:
				printf("What is the name of the image file: ");
				scanf("%s", &fileName);
				
				readFile(ROWS, COLUMNS, photo2DArray, fileName);
				
				getMenuChoice();
				
				break;
			case 1:
				brightnessConversion(ROWS, COLUMNS, photo2DArray);
				
				break;
			case 2: 
				break;
			case 3: 
				break;
			default:
				break;
		}	
	}while(userInput != 3);

}

int brightnessConversion(int rows, int columns, int photo2DArray[][columns]){
	char brightnessArray[ROWS][COLUMNS] = {0};
	//int photo2DArray[ROWS][COLUMNS] = {0};
	
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

void readFile(int rows, int columns, int photo2DArray[][columns], char *file){ //need to add pointers to be able to add the photo2DArray variable to others functions
		int inFuncArray[ROWS][COLUMNS];
		FILE* fp; 
		fp = fopen(file, "r");
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
