//Authors: Andrew Huck and Bella Picasso-Kennedy
//Purpose: 
//Class: CS 135-1104

#define READ_FILE_NAME "numbers.txt"
#define SIZE 100
#define ROWS 5
#define COLUMNS 5

#include <stdio.h>

void getMenuChoice();
void readFile(int rows, int columns, int photo2DArray[][columns], char *file);
void displayImage(int rows, int columns, int photo2DArray[][columns]);
void editImageMenu();

int main() {
	int rowCount, colCount;
	
	getMenuChoice();
	readFile(ROWS, COLUMNS, photo2DArray, fileName, &rowCount, &colCount);
	
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
	
	switch(userInput){
			case 0:
				printf("What is the name of the image file: ", &userInput);
				scanf("%s", fileName);
				readFile(ROWS, COLUMNS, photo2DArray);
				
				break;
			case 1:
				displayImage(ROWS, COLUMNS, photo2DArray);
				
				break;
			case 2: 
				editImageMenu();
				break;
			case 3: 
				printf("Goodbye!\n");
				break;
			
			default:
				break;
	}	
	
	}while(userInput != 3);

}

void readFile(int rows, int columns, int photo2DArray[][columns], char *file, int *rowPtr, int* colPtr){ 
		int inFuncArray[rows][columns];
		FILE* fp; 
		fp = fopen(file, "r");
		if (fp == NULL){
			printf("File did not open\n");
		}
		else{
			for(int iRows = 0; iRows < rows; iRows++){
				for(int iCols = 0; iCols < columns; iCols++){
					fscanf(fp, "%d", &inFuncArray[iRows][iCols]);
					photo2DArray[iRows][iCols] = inFuncArray[iRows][iCols];
				}
			}	
		}
		*rowPtr = iRows
		*colPtr = iCols
		
		fclose(fp);
}

void displayImage(int rows, int columns, int photo2DArray[][columns]){
	char brightnessArray[rows][columns];
	
	for(int iRows = 0; iRows < rows; iRows++){
		for(int iCols = 0; iCols < columns; iCols++){
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
	
	printf("\n");
	for(int iRows = 0; iRows < rows; iRows++){
		for(int iCols = 0; iCols < columns; iCols++){
		printf("%c", brightnessArray[iRows][iCols]);
		}
		
		printf("\n");
	}	
	printf("\n");
}

void editImageMenu(){
	int userChoice;
	
	printf("\n**EDIT MENU**\n");
	printf("1. Crop image\n");
	printf("2. Dim image\n");
	printf("3. Brighten image\n");
	printf("4. Rotate image\n");
	
	printf("Enter your choice: ");
	scanf("%d", &userChoice);
	
	switch(userChoice){
		case 1:
			break;
		case 2:
			break;
		case 3: 
			break;
		case 4:
			break;
		default:
			break;
	}	
}
