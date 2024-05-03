//Author: Sergio Jackson, Brysen Ross

#include <stdio.h>
#define MAXCOL 500
#define MAXROW 500
void loadimage(int imagearray[][MAXCOL], int *rownumptr, int *colnumptr);
void displayimage(int rows, int cols, int imagearray[][cols]);
void editimage();
void cropimage();
void brightenimage();
void dimimage();
void rotateimage();
void saveimage();

int main(){
	int image[MAXROW][MAXCOL];
	int row;
	int col;
	int user_choice;
	
	
	printf("MENU\n");
	printf("1. Load Image\n");
	printf("2. Display Image\n");
	printf("3. Edit Image\n");
	printf("4. Exit\n");
	printf("What would you like to do?");
	scanf("%d", &user_choice);
	
	switch(user_choice){
		case 1:
		loadimage(image, &row, &col);
		printf("%d %d", row, col);
		break;
		default:
		printf("Invalid Option\n");
	}

	return 0;
}

void loadimage(int imagearray[][MAXCOL], int *rownumptr, int *colnumptr){
	
	int rownum;
	int colnum;
    	char filename[50];
    	FILE *filepointer;

	printf("Enter the name of the image file: ");
    	scanf("%s", filename);

    	filepointer = fopen(filename, "r");
   	if (filepointer == NULL) {
        printf("File does not exist.\n");
    	}
    	else{
    		while(fscanf(filepointer, "%d", &imagearray[rownum][colnum]) == 1){
    			rownum++;
    			colnum++;
 
    		}
    	}
    	*rownumptr = rownum;
    	*colnumptr = colnum;
    	fclose(filepointer);
}
void displayimage(int rows, int cols, int imagearray[][cols]){
}

void editimage(){

}

void cropimage(){

}

void brightenimage(){

}

void dimimage(){

}

void rotateimage(){

}

void saveimage(){

}












