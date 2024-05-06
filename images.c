//Author: Sergio Jackson, Brysen Ross

#include <stdio.h>
#define MAXCOL 500
#define MAXROW 500
#define MAXSIZE 500
void loadimage(FILE* fptr, char filename[], int imagearray[][MAXCOL], int *rownumptr, int *colnumptr);
void save(FILE* fptr, char filename[], int rows, int cols, int imagearray[][MAXCOL]);
void displayimage(int rows, int cols, int imagearray[][MAXCOL]);
void editimage(FILE* fptr, char filename[], int choice, int imagearray[][MAXCOL], int rownum, int colnum, int croppedArray[][MAXCOL], int *croppedRows, int *croppedCols);
void cropimage(int imagearray[][MAXCOL], int rownum, int colnum, FILE *fptr, char filename[], int *croppedRows, int *croppedCols, int croppedArray[][MAXCOL]);
void displaycropimage(int croppedRows, int croppedcols, int croppedArray[][MAXCOL]);
void dimimage(int rownum, int colnum, int imagearray[][MAXCOL]);
void brightenimage(int rownum, int colnum, int imagearray[][MAXCOL]);
void saveimagefile(FILE* fptr, char filename[], int rows, int cols, int imagearray[][MAXCOL]);
void savecropimage(FILE* fptr, char filename[], int croppedRows, int croppedCols, int croppedArray[][MAXCOL]);

int main(){
	int image[MAXROW][MAXCOL];
	FILE* fileptr;
	char filename[MAXSIZE];
	int row, col, croprows, cropcols;
	int user_choice, edit_choice;
	int croparray[MAXROW][MAXCOL];
	
	do{
		printf("**ERINSTAGRAM**\n");
		printf("1: Load Image\n");
		printf("2: Display Image\n");
		printf("3: Edit Image\n");
		printf("0: Exit\n");
		printf("\nChoose from one of the options above:");
		scanf("%d", &user_choice);
		printf("\n\n");

		switch(user_choice){
			case 1:
				loadimage(fileptr, filename, image, &row, &col);
				save(fileptr, filename, row, col, image);
				break;
			case 2:
				displayimage(row, col, image);
				break;
			case 3:
				editimage(fileptr, filename, edit_choice, image, row, col, croparray, &croprows, &cropcols);
				break;
			case 0:
				printf("\nGoodbye!\n\n");
				return 0;
			default:
				printf("Invalid Option\n\n");
		}
	}while(user_choice != '0');
	return 0;
}

void loadimage(FILE* fptr, char filename[], int imagearray[][MAXCOL], int *rownumptr, int *colnumptr){
	
	int rownum = 0;
	int colnum = 0;
	char num;
 
	printf("What is the name of the image file? ");
    	scanf("%s", filename);

    	fptr = fopen(filename, "r");
   	if (fptr == NULL){
        	printf("Could not find an image with that filename.\n");
        	return;
    	}
    	while(fscanf(fptr, "%c", &num) == 1){
    		if(num >= '0' && num <= '4'){
    			imagearray[rownum][colnum++] = num;
    		}else if (num == '\n'){
    			if(rownum == 0){
				*colnumptr = colnum;
			}
			rownum++;
		}
	}
   	
  	*rownumptr = rownum;
    	fclose(fptr);
    	printf("\nImage successfully loaded!\n\n");
}

void save(FILE* fptr, char filename[], int rows, int cols, int imagearray[][MAXCOL]){

	fptr = fopen(filename, "r");
	if(fptr == NULL){
		printf("ERROR\n");
	} 
	else{
		for(int rowI = 0; rowI < rows; rowI++){
			for(int colI = 0; colI < cols; colI++){
				fscanf(fptr, "%1d", &imagearray[rowI][colI]);
			}
		}
		fclose(fptr);
	}
}

void displayimage(int rows, int cols, int imagearray[][MAXCOL]){

	for(int rowI = 0; rowI < rows; rowI++){
		for(int colI = 0; colI < cols; colI++){
			switch(imagearray[rowI][colI]){
				case 0:
					printf(" ");
					break;
				case 1:
					printf(".");
					break;
				case 2:
					printf("o");
					break;
				case 3:
					printf("O");
					break;
				case 4:
					printf("0");
					break;
			}
			if(colI == cols - 1){
				printf("\n");
			}
		}
	}
	printf("\n");
}

void editimage(FILE* fptr, char filename[], int choice, int imagearray[][MAXCOL], int rownum, int colnum, int croppedArray[][MAXCOL], int *croppedRows, int *croppedCols){

	printf("**EDITING**\n");
	printf("1: Crop image\n");
	printf("2: Dim image\n");
	printf("3: Brighten image\n");
	printf("0: Return to main menu\n");
	printf("\nChoose from one of the options above:");
	scanf("%d", &choice);
	switch(choice){
		case 1:
			cropimage(imagearray, rownum, colnum, fptr, filename, croppedRows,croppedCols, croppedArray);
			savecropimage(fptr, filename, *croppedRows, *croppedCols, croppedArray);
			break;
		case 2:
			dimimage(rownum, colnum, imagearray);
			displayimage(rownum, colnum, imagearray);
			saveimagefile(fptr, filename, rownum, colnum, imagearray);
			break;
		case 3:
			brightenimage(rownum, colnum, imagearray);
			displayimage(rownum, colnum, imagearray);
			saveimagefile(fptr, filename, rownum, colnum, imagearray);
			break;
		case 0:
			return;
	}
}

void cropimage(int imagearray[][MAXCOL], int rownum, int colnum, FILE *fptr, 		char filename[], int *croppedRows, int *croppedCols, int croppedArray[][MAXCOL]){

	int row1, col1, row2, col2;
    	int croprow, cropcol;
	displayimage(rownum, colnum, imagearray);
    	printf("The image you want to crop is %d X %d.\n", rownum, colnum);
    	printf("The row and column values start in the upper lefthand corner.\n\n");
    	printf("\n Which column do you want to be the new left side?");
    	scanf("%d", &col1);
    	printf("\nWhich column do you want to be the right side?");
    	scanf("%d", &col2);
    	printf("\nWhich row do you want to be the new top?");
    	scanf("%d", &row1);
    	printf("\nWhich row do you want to be the new bottom?");
    	scanf("%d", &row2);
    	col1--;
    	col2--;
    	row1--;
    	row2--;
    	
    	if (row1 < 0 || row1 >= rownum || col1 < 0 || col1 >= colnum ||
        row2 < 0 || row2 >= rownum || col2 < 0 || col2 >= colnum ||
        row2 < row1 || col2 < col1) {
        	printf("Invalid coordinates. Please enter valid coordinates within the image dimensions.\n");
        	return;
    	}
    	*croppedRows = croprow = row2 - row1 + 1;
    	*croppedCols = cropcol = col2 - col1 + 1;
    	for (int i = 0; i < *croppedRows; i++) {
        	for (int j = 0; j < *croppedCols; j++) {
            		croppedArray[i][j] = imagearray[row1 + i][col1 + j];
        	}
    	}
    	displaycropimage(*croppedRows, *croppedCols, croppedArray);
}


void displaycropimage(int croppedRows, int croppedCols, int croppedArray[][MAXCOL]){

	for(int rowI = 0; rowI < croppedRows; rowI++){
        	for(int colI = 0; colI < croppedCols; colI++){
            		switch(croppedArray[rowI][colI]){
				case 0:
					printf(" ");
					break;
				case 1:
					printf(".");
					break;
				case 2:
					printf("o");
					break;
				case 3:
					printf("O");
					break;
				case 4:
					printf("0");
					break;
			}
			if(colI == croppedCols - 1){
				printf("\n");
			}
		}
	}
}	


void dimimage(int rownum, int colnum, int imagearray[][MAXCOL]){

	for(int rowI = 0; rowI < rownum; rowI++){
		for(int colI = 0; colI < colnum; colI++){
			if(imagearray[rowI][colI] > 0){
				imagearray[rowI][colI]--;
			}
		}
	}
}

void brightenimage(int rownum, int colnum, int imagearray[][MAXCOL]){

	for(int rowI = 0; rowI < rownum; rowI++){
		for(int colI = 0; colI < colnum; colI++){
			if(imagearray[rowI][colI] < 4){
				imagearray[rowI][colI]++;
			}
		}
	}
}

void saveimagefile(FILE* fptr, char filename[], int rows, int cols, int imagearray[][MAXCOL]){

	char choice;
	printf("Would you like to save? (y/n)");
	scanf(" %c", &choice);
	if(choice == 'y' || choice == 'Y'){
		printf("What do you want to name the image file?(include the extension)");
		scanf("%s", filename);
		fptr = fopen(filename, "w");
		for(int rowI = 0; rowI < rows; rowI++){
			for(int colI = 0; colI < cols; colI++){
				fprintf(fptr, "%1d", imagearray[rowI][colI]);
			}
			fprintf(fptr, "\n");
		}
		
		fclose(fptr);
		printf("\nImage successfully saved!\n\n");
	}
	else{
		return;
	}
}

void savecropimage(FILE* fptr, char filename[], int croppedRows, int croppedCols, int croppedArray[][MAXCOL]){

	char choice;
	printf("Would you like to save the file? (y/n)");
	scanf(" %c", &choice);
	if(choice == 'y' || choice == 'Y'){
		printf("What do you want to name the image file?(include the extension)");
		scanf("%s", filename);
		fptr = fopen(filename, "w");
		for(int rowI = 0; rowI < croppedRows; rowI++){
			for(int colI = 0; colI < croppedCols; colI++){
				fprintf(fptr, "%1d", croppedArray[rowI][colI]);
			}
			fprintf(fptr, "\n");
		}
		
		fclose(fptr);
		printf("\nImage successfully saved!\n\n");
	}
	else{
		return;
	}
}
	












