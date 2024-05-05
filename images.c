//Author: Sergio Jackson, Brysen Ross

#include <stdio.h>
#define MAXCOL 500
#define MAXROW 500
#define MAXSIZE 500
void loadimage(FILE* fptr, char filename[], int imagearray[][MAXCOL], int *rownumptr, int *colnumptr);
void save(FILE* fptr, char filename[], int rows, int cols, int imagearray[][cols]);
void displayimage(FILE* fptr, char filename[], int rows, int cols, int imagearray[][cols]);
void editimage(int choice, int imagearray[][MAXCOL], int rownum, int colnum);
void cropImage(int imagearray[][MAXCOL], int rownum, int colnum);
void brightenimage();
void dimimage();
void rotateimage();
void saveimage();

int main(){
	int image[MAXROW][MAXCOL];
	FILE* fileptr;
	char filename[MAXSIZE];
	int row, col;
	int user_choice, edit_choice;
	
	do{
	printf("MENU\n");
	printf("1: Load Image\n");
	printf("2: Display Image\n");
	printf("3: Edit Image\n");
	printf("0: Exit\n");
	printf("\nChoose from one of the options above:");
	scanf("%d", &user_choice);

	switch(user_choice){
		case 1:
		loadimage(fileptr, filename, image, &row, &col);
		save(fileptr, filename, row, col, image);
		break;
		case 2:
		displayimage(fileptr, filename, row, col, image);
		break;
		case 3:
		editimage(edit_choice, image, row, col);
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
    	}
    	else{
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
   	}
  	*rownumptr = rownum;
    	fclose(fptr);
    	printf("\n");
    	printf("Image successfully loaded!\n\n");
}
void save(FILE* fptr, char filename[], int rows, int cols, int imagearray[][cols]){

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

void displayimage(FILE* fptr, char filename[], int rows, int cols, int imagearray[][cols]){
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

void editimage(int choice, int imagearray[][MAXCOL], int rownum, int colnum){
	printf("**EDITING**\n");
	printf("1: Crop image\n");
	printf("2: Dim image\n");
	printf("3: Brighten image\n");
	printf("0: Return to main menu\n");
	printf("\nChoose from one of the options above:");
	scanf("%d", &choice);
	switch(choice){
		case 1:
		cropImage(imagearray, rownum, colnum);
		break;
		case 2:
		//dim image function
		break;
		case 3:
		//brighten image function
		break;
		case 0:
		return;
		}
}

void cropImage(int imagearray[][MAXCOL], int rownum, int colnum){
    int row1, col1, row2, col2;

    // Ask the user for two rows and two columns
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

    // Ensure the coordinates are within bounds
    if (row1 < 0 || row1 >= rownum || col1 < 0 || col1 >= colnum ||
        row2 < 0 || row2 >= rownum || col2 < 0 || col2 >= colnum) {
        printf("Invalid coordinates. Please enter coordinates within the image dimensions.\n");
        return;
    }

    // Crop the image
    for (int i = row1; i <= row2; i++) {
        for (int j = col1; j <= col2; j++) {
            printf("%d ", imagearray[i][j]); // Print the cropped pixel
        }
        printf("\n");
    }
}

void brightenimage(){

}

void dimimage(){

}

void rotateimage(){

}

void saveimage(){

}











