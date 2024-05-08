//Authors: Andrew Huck and Bella Picasso-Kennedy
//Purpose: Final Project
//Class: CS 135-1104

#define SIZE 100
#define ROWS 500
#define COLUMNS 500

#include <stdio.h>

int getMenuChoice();
void readFile(int rows, int columns, int photo2DArray[][columns], char *file, int *rowPtr, int* colPtr);
void writeFile(int rows, int columns, int editedArray[][columns], int rowCount, int colCount);
void displayImage(int rows, int columns, int photo2DArray[][columns], int rowCount, int colCount);
int editImageMenu();
void changeBrightness(int rows, int columns, int photo2DArray[][columns], int editedArray[][columns], int rowSize, int colSize, int answer);
void cropImage(int photo2DArray[][COLUMNS], int editedArray[][COLUMNS], int startRow, int startCol, int endRow, int endCol);
void rowAndColumnDisplay();

int main() {
	int photo2DArray[ROWS][COLUMNS]={0};
	char fileName[SIZE];
	int rowCount, colCount;
	int userInput, userInputEdit;
	int editedArray[ROWS][COLUMNS];
	int answer, startRow, endRow, startCol, endCol;
	
	do{
		userInput = getMenuChoice();
		switch(userInput){
			case 1:
				printf("What is the name of the image file: ");
				scanf("%s", fileName);
				readFile(ROWS, COLUMNS, photo2DArray, fileName, &rowCount, &colCount);
				break;
			case 2:
				displayImage(ROWS, COLUMNS, photo2DArray, rowCount, colCount);
				
				break; 
			case 3: 
				userInputEdit = editImageMenu();
				switch(userInputEdit){
					case 1:	
						rowAndColumnDisplay(ROWS, COLUMNS, photo2DArray, rowCount, colCount);
						printf("The image you would like to crop is %d x %d\n", rowCount, colCount);
						printf("The row and column values start in the upper lefthand corner.\n\n");
						 
						printf("Which column do you want to be the new left side? ");
						scanf("%d", &startCol);
						while(startCol < 1 || startCol >= colCount){
							printf("Invalid column value. Choose a value between 1 and %d: ", colCount - 1);
							scanf("%d", &startCol);
						}
						
						printf("\nWhich column do you want to be the new right side? ");
						scanf("%d", &endCol);
						while(endCol < startCol || endCol >= colCount){
							printf("Invalid column value. Choose a value between %d and %d: ", startCol, colCount - 1);
							scanf("%d", &endCol);
						}
						
						printf("\nWhich row do you want to be the new top? ");
						scanf("%d", &startRow);
						while(startRow < 1 || startRow >= rowCount){
							printf("Invalid row value. Choose a value between 1 and %d: ", rowCount - 1);
							scanf("%d", &startRow);
						}
						
						printf("\nWhich row do you want to be the new bottom? ");
						scanf("%d", &endRow);
						while(endRow < startRow || endRow >= rowCount){
							printf("Invalid row value. Choose a value between %d and %d: ", startRow, rowCount - 1);
							scanf("%d", &endRow);
						}
						
						int cropRow = endRow - startRow + 1;
						int cropCol = endCol - startCol + 1;
						int editedArray[ROWS][COLUMNS];
						
						cropImage(photo2DArray, editedArray, startRow, startCol, endRow, endCol);
						displayImage(ROWS, COLUMNS, editedArray, cropRow, cropCol);
						writeFile(ROWS, COLUMNS, editedArray, cropRow, cropCol);
						
						break;
					case 2:	
						answer = 1;
						changeBrightness(ROWS, COLUMNS, photo2DArray, editedArray, rowCount, colCount, answer);
						displayImage(ROWS, COLUMNS, editedArray, rowCount, colCount);
						writeFile(ROWS, COLUMNS, editedArray, rowCount, colCount);
						
						break;
					case 3: 
						answer = 0;
						changeBrightness(ROWS, COLUMNS, photo2DArray, editedArray, rowCount, colCount, answer);
						displayImage(ROWS, COLUMNS, editedArray, rowCount, colCount);
						writeFile(ROWS, COLUMNS, editedArray, rowCount, colCount);
						
						break;
					case 0:
						printf("\n");
											
						break;
					default:
						printf("\nInvalid option, please try again.\n\n");
						
						break;
				}
			
				break;
			case 0: 
				printf("\nGoodbye!\n");
				
				break;
			
			default:
				printf("\nInvalid option, please try again.\n\n");
				
				break;
		}	
	}while(userInput != 0);

	return 0;
}
	
int getMenuChoice(){
	int userInput;
	printf("**ERINSTAGRAM**\n");
	printf("1. Load New Image\n");
	printf("2. Display current image\n");
	printf("3. Edit the current image\n");
	printf("0. Exit\n");
	printf("\nChoose from one of the options above: " );
	scanf("%d", &userInput);

	return userInput;
}

void readFile(int rows, int columns, int photo2DArray[][columns], char *file, int *rowPtr, int* colPtr){ 
	char inFuncArray[rows][columns];
	int iRows = 0, iCols = 0;
	int rowCount = 0, colCount = 0;
	int colSize = 0;
	char test;

	FILE* fp; 
	fp = fopen(file, "r");
	if (fp == NULL){
		printf("File did not open\n");
	}
	else{
		while(fscanf(fp,"%c", &test) == 1){
			if(test != '\n'){
				inFuncArray[iRows][iCols] = test;	
			}
			else if(test == '\n'){
				iRows++;
				colCount = iCols - 1;
				iCols = -1;
			}
			iCols++;	
		}
		rowCount = iRows;
		colSize = colCount;
	}
	*rowPtr = iRows;
	*colPtr = colCount + 1;
	fclose(fp);
			
	for(int inRows = 0; inRows < rowCount; inRows++){
		for(int iCols = 0; iCols < colSize-1; iCols++){
			if (inFuncArray[inRows][iCols] == '0'){
				photo2DArray[inRows][iCols] = 0;
			}
			else if (inFuncArray[inRows][iCols] == '1'){
				photo2DArray[inRows][iCols] = 1;
			}
			else if (inFuncArray[inRows][iCols] == '2'){
				photo2DArray[inRows][iCols] = 2;
			}
			else if (inFuncArray[inRows][iCols] == '3'){
				photo2DArray[inRows][iCols] = 3;
			}
			else if (inFuncArray[inRows][iCols] == '4'){
				photo2DArray[inRows][iCols] = 4;
			}
		}
	}

	printf("\nImage succesfully loaded!\n\n");
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

int editImageMenu(){
	int userChoiceEdit;
	
	printf("\n**EDITING**\n");
	printf("1. Crop image\n");
	printf("2. Dim image\n");
	printf("3. Brighten image\n");
	printf("0. Return to main menu\n");
	
	printf("\nChoose from one of the options above: ");
	scanf("%d", &userChoiceEdit);
	
	return userChoiceEdit;	
}

void changeBrightness(int rows, int columns, int photo2DArray[][columns], int editedArray[][columns], int rowCount, int colCount, int answer){
	int inFuncArray[ROWS][COLUMNS];
	for(int iRows = 0; iRows < rowCount; iRows++){
		for(int iCols = 0; iCols < colCount; iCols++){
			editedArray[iRows][iCols] = photo2DArray[iRows][iCols];
		}
	}
	
	if (answer == 1){
		for(int iRows = 0; iRows < rowCount; iRows++){
			for(int iCols = 0; iCols < colCount; iCols++){
				if (photo2DArray[iRows][iCols] == 0){
					editedArray[iRows][iCols] = 0;
				}
				else if (photo2DArray[iRows][iCols] == 1){
					editedArray[iRows][iCols] = 0;
				}
				else if (photo2DArray[iRows][iCols] == 2){
					editedArray[iRows][iCols] = 1;
				}
				else if (photo2DArray[iRows][iCols] == 3){
					editedArray[iRows][iCols] = 2;
				}
				else if (photo2DArray[iRows][iCols] == 4){
					editedArray[iRows][iCols] = 3;
				}
			}
		}
	}
	else{
		for(int iRows = 0; iRows < rowCount; iRows++){
			for(int iCols = 0; iCols < colCount; iCols++){
				if (photo2DArray[iRows][iCols] == 0){
					editedArray[iRows][iCols] = 1;
				}
				else if (photo2DArray[iRows][iCols] == 1){
					editedArray[iRows][iCols] = 2;
				}
				else if (photo2DArray[iRows][iCols] == 2){
					editedArray[iRows][iCols] = 3;
				}
				else if (photo2DArray[iRows][iCols] == 3){
					editedArray[iRows][iCols] = 4;
				}
				else if (photo2DArray[iRows][iCols] == 4){
					editedArray[iRows][iCols] = 4;
				}
			}
		}
	}
}

void writeFile(int rows, int columns, int editedArray[][columns], int rowCount, int colCount){ 
	char editAnswer = 'n';
	printf("Would you like to save the file? (y/n) ");
	scanf(" %c", &editAnswer);
	
	char fileEditName[SIZE];
	if(editAnswer == 'y'){
		printf("\nWhat do you want to name the image file? (include the extension) ");
		scanf("%s", fileEditName);
		FILE* fp; 
		fp = fopen(fileEditName, "w");
		
		if (fp == NULL){
			printf("File did not open\n");
		}
		else{
			for(int iRows = 0; iRows < rowCount; iRows++){
				for(int iCols = 0; iCols < colCount; iCols++){
					fprintf(fp, "%d", editedArray[iRows][iCols]);	
				}
				fprintf(fp,"\n");
			}
		fprintf(fp,"\n");	
		printf("\nImage successfully saved!\n\n");			
		}
	fclose(fp);
	}
	else{
		printf("\n");
	}
}

void cropImage(int photo2DArray[][COLUMNS], int editedArray[][COLUMNS], int startRow, int startCol, int endRow, int endCol){
	for(int i = startRow - 1; i < endRow; i++){
		for(int j = startCol - 1; j < endCol; j++){
			editedArray[i - startRow + 1][j - startCol + 1] = photo2DArray[i][j];
		}
	}
}

void rowAndColumnDisplay(int rows, int columns, int photo2DArray[][columns], int rowCount, int colCount){
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
	
	printf(" 1");
	for (int i = 0; i < colCount - 2; i++){
		printf(" ");
	}
	printf("%d\n", colCount);

	for(int i = 0; i < rowCount; i++){
		if(i == 0){
			printf("%d", i + 1);
		}
		else{
			printf(" ");
		}
		for(int j = 0; j < colCount; j++){
			printf("%c", brightnessArray[i][j]);
		}
		printf("\n");
	}	
	printf("%d", rowCount);
	printf("\n");
}
