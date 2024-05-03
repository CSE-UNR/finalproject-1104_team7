//Authors: Andrew Huck and Bella Picasso-Kennedy
//Purpose: 
//Class: CS 135-1104

#define READ_FILE_NAME "numbers.txt"
#define SIZE 100
#define ROWS 500
#define COLUMNS 500
#define ROW 0
#define COL 0

#include <stdio.h>

int getMenuChoice();
void readFile(int rows, int columns, int photo2DArray[][columns], char *file, int *rowPtr, int* colPtr);
void displayImage(int rows, int columns, int photo2DArray[][columns], int rowCount, int colCount);
void editImageMenu();

int main() {
	int photo2DArray[ROWS][COLUMNS]={0};
	char fileName[SIZE];
	int brightnessArray[ROWS][COLUMNS];
	int rowCount, colCount;
	int userInput;
	
	
	do{
	userInput = getMenuChoice();
	switch(userInput){
			case 0:
				printf("What is the name of the image file: ");
				scanf("%s", fileName);
				readFile(ROWS, COLUMNS, photo2DArray, fileName, &rowCount, &colCount);
				
				break;
			case 1:
				displayImage(ROWS, COLUMNS, photo2DArray, rowCount, colCount);
				
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

	return 0;
}
	//readFile(ROWS, COLUMNS, photo2DArray, fileName, &rowCount, &colCount);
	


int getMenuChoice(){
	
	int userInput;
		printf("**ERINSTAGRAM**\n");
		printf("0. Load New Image\n");
		printf("1. Display current image\n");
		printf("2. Edit the current image\n");
		printf("3. Exit\n");
		printf("Choose from one of the options above: " );
		scanf("%d", &userInput);
	return userInput;
}

void readFile(int rows, int columns, int photo2DArray[][columns], char *file, int *rowPtr, int* colPtr){ 
		char inFuncArray[rows][columns];
		int iRows = 0;
		int iCols = 0;
		int rowCount = 0, colCount = 0;

		FILE* fp; 
		fp = fopen(file, "r");
		if (fp == NULL){
			printf("File did not open\n");
		}
		else{
			
			//for(int iRows = 0; iRows < rowCount; iRows++){
			//	for(int iCols = 0; iCols < colCount; iCols++){
			//		fscanf(fp,"%d",&photo2DArray[iRows][iCols]);
					//printf("%d",photo2DArray[iRows][iCols]);
			//	}
			//printf("\n");
			
			
			while(fscanf(fp,"%c", &inFuncArray[iRows][iCols]) == 1){
			if(inFuncArray[iRows][iCols] != ' '){
				if(inFuncArray[iRows][iCols] == '\n'){
				iRows++;
				colCount = iCols - 1;
				printf("colCount is now %d. iRows is now %d.\n", colCount, iRows);
				iCols = 0;
				}
				iCols++;
				}
				
			}
			printf("colCount is now %d. iRows is now %d.\n", colCount, iRows);
			//printf("%d", rowCount);
			
		}
		//*rowPtr = iRows;
		//*colPtr = colCount;
		printf("%d------\n", colCount);
		printf("%d\n", iRows);
		//for(int iRows = 0; iRows <= rowCount; iRows++){
		//		for(int iCols = 0; iCols <= colCount; iCols++){
		//		printf("%d", photo2DArray[iRows][iCols]);
		//		}
		//		printf("\n");
		//}
		fclose(fp);
}

void displayImage(int rows, int columns, int photo2DArray[][columns], int rowCount, int colCount){
	char brightnessArray[rows][columns];
	
	for(int iRows = 0; iRows < rowCount; iRows++){
		for(int iCols = 0; iCols < colCount; iCols++){
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
	for(int iRows = 0; iRows < rowCount; iRows++){
		for(int iCols = 0; iCols < colCount; iCols++){
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