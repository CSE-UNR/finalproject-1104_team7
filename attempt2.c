//Authors: Andrew Huck and Bella Picasso-Kennedy
//Purpose: Final Project
//Class: CS 135-1104

#define SIZE 100
#define ROWS 500
#define COLUMNS 500

#include <stdio.h>

int getMenuChoice();
void readFile(int rows, int columns, int photo2DArray[][columns], char *file, int *rowPtr, int* colPtr);
void writeFile(int rows, int columns, int editedArray[][columns], char *file, int rowCount, int colCount);
void displayImage(int rows, int columns, int photo2DArray[][columns], int rowCount, int colCount);
int editImageMenu();
void changeBrightness(int rows, int columns, int photo2DArray[][columns], int editedArray[][columns], int rowSize, int colSize, int answer);
void cropImage(int photo2DArray[][COLUMNS], int editedArray[][COLUMNS], int startRow, int startCol, int endRow, int endCol);

int main() {
	int photo2DArray[ROWS][COLUMNS]={0};
	int pictureArray[ROWS][COLUMNS] = {0};
	char fileName[SIZE],fileEditName[SIZE];
	int brightnessArray[ROWS][COLUMNS];
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
						displayImage(ROWS, COLUMNS, photo2DArray, rowCount, colCount);
						printf("The image you would like to crop is %d x %d\n", rowCount, colCount);
						printf("The row and column values start in the upper lefthand corner.\n\n");
						 
						printf("Which column do you want to be the new left side? ");
						scanf("%d", &startCol);
						printf("\nWhich column do you want to be the new right side? ");
						scanf("%d", &endCol);
						printf("\nWhich row do you want to be the new top? ");
						scanf("%d", &startRow);
						printf("\nWhich row do you want to be the new bottom? ");
						scanf("%d", &endRow);
						
						int cropRow = endRow - startRow + 1;
						int cropCol = endCol - startCol + 1;
						int editedArray[ROWS][COLUMNS];
						
						cropImage(photo2DArray, editedArray, startRow, startCol, endRow, endCol);
						displayImage(ROWS, COLUMNS, editedArray, cropRow, cropCol);
						
						int editAnswer = 0;
						printf("Would you like to save this new image to a file? (1 - Yes, 0 - No) ");
						scanf("%d", &editAnswer);
						if(editAnswer == 1){
							printf("\nWhat do you want to name the image file? (include the extension) ");
							scanf("%s", fileEditName);
							writeFile(ROWS, COLUMNS, editedArray, fileEditName, cropRow, cropCol);
						}
						else{
							printf("\n");
						}
						break;
					case 2:	
						answer = 1;
						changeBrightness(ROWS, COLUMNS, photo2DArray, editedArray, rowCount, colCount, answer);
						displayImage(ROWS, COLUMNS, editedArray, rowCount, colCount);
						
						editAnswer = 0;
						printf("Would you like to save this new image to a file? (1 - Yes, 0 - No) ");
						scanf("%d", &editAnswer);
						if(editAnswer == 1){
							printf("\nWhat do you want to name the image file? (include the extension) ");
							scanf("%s", fileEditName);
							writeFile(ROWS, COLUMNS, editedArray, fileEditName, rowCount, colCount);
						}
						break;
					case 3: 
						answer = 0;
						changeBrightness(ROWS, COLUMNS, photo2DArray, editedArray, rowCount, colCount, answer);
						displayImage(ROWS, COLUMNS, editedArray, rowCount, colCount);
						editAnswer = 0;
						printf("Would you like to save this new image to a file? (1 - Yes, 0 - No) ");
						scanf("%d", &editAnswer);
						if(editAnswer == 1){
							printf("\nWhat do you want to name the image file? (include the extension) ");
							scanf("%s", fileEditName);
							writeFile(ROWS, COLUMNS, editedArray, fileEditName, rowCount, colCount);
						}
						break;
					case 4:
						break;
					default:
						break;
				}
			
				
			
				break;
			case 0: 
				printf("\nGoodbye!\n");
				break;
			
			default:
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
	char checkArray[rows][columns];
	int iRows = 0;
	int iCols = 0;
	int rowCount = 0, colCount = 0;
	int colSize = 0;
	
	FILE* fp; 
	fp = fopen(file, "r");
	if (fp == NULL){
		printf("File did not open\n");
	}
	else{
		while(fscanf(fp,"%c", &inFuncArray[iRows][iCols]) == 1){
				if(inFuncArray[iRows][iCols] == '\n'){
					iRows++;
					colCount = iCols-1;
					iCols = 0;
				}
				iCols++;	
			}
			rowCount = iRows;
			colSize = colCount;
		}
		*rowPtr = iRows;
		*colPtr = colCount;
		fclose(fp);
		
		FILE* fptr; 
		fptr = fopen(file, "r");
		if (fptr == NULL){
			printf("File did not open\n");
		}
		else{
		
		
		
		
		
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
						else{
							photo2DArray[inRows][iCols] = 9;
						}
						}
					}
			}
		for(int inRows = 0; inRows < rowCount; inRows++){
					for(int iCols = 0; iCols < colSize - 1; iCols++){
						printf("%d", photo2DArray[inRows][iCols]);
			
				}
				printf("\n");
				
		}


		fclose(fptr);
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
	printf("4. Rotate image\n");
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

void writeFile(int rows, int columns, int editedArray[][columns], char *fileEdit, int rowCount, int colCount){ 
		FILE* fp; 
		fp = fopen(fileEdit, "w");
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
				
		}
		fclose(fp);
		printf("\nImage successfully saved!\n\n");
}

void cropImage(int photo2DArray[][COLUMNS], int editedArray[][COLUMNS], int startRow, int startCol, int endRow, int endCol){
	for(int i = startRow - 1; i < endRow; i++){
		for(int j = startCol - 1; j < endCol; j++){
			editedArray[i - startRow + 1][j - startCol + 1] = photo2DArray[i][j];
		}
	}
}

