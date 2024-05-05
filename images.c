//Author: Sergio Jackson, Brysen Ross

#include <stdio.h>
#define MAXCOL 500
#define MAXROW 500
#define MAXSIZE 500
void loadimage(FILE* fptr, char filename[], int imagearray[][MAXCOL], int *rownumptr, int *colnumptr);
void save(FILE* fptr, char filename[], int rows, int cols, int imagearray[][cols]);
void displayimage(FILE* fptr, char filename[], int rows, int cols, int imagearray[][cols]);
void editimage();
void cropimage();
void brightenimage();
void dimimage();
void rotateimage();
void saveimage();

int main(){
	int image[MAXROW][MAXCOL];
	FILE* fileptr;
	char filename[MAXSIZE];
	int row, col;
	int user_choice;
	
	do{
	printf("MENU\n");
	printf("1. Load Image\n");
	printf("2. Display Image\n");
	printf("3. Edit Image\n");
	printf("4. Exit\n");
	printf("What would you like to do?");
	scanf("%d", &user_choice);
	printf("\n");
	switch(user_choice){
		case 1:
		loadimage(fileptr, filename, image, &row, &col);
		save(fileptr, filename, row, col, image);
		break;
		case 2:
		displayimage(fileptr, filename, row, col, image);
		break;
		case 3:
		//edit menu 
		break;
		case 4:
		return 0;
		default:
		printf("Invalid Option\n\n");
	}
	}while(user_choice != '4');
	return 0;
}

void loadimage(FILE* fptr, char filename[], int imagearray[][MAXCOL], int *rownumptr, int *colnumptr){
	
	int rownum = 0;
	int colnum = 0;
	char num;
 
	printf("Enter the name of the image file: ");
    	scanf("%s", filename);

    	fptr = fopen(filename, "r");
   	if (fptr == NULL){
        	printf("File does not exist.\n");
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












