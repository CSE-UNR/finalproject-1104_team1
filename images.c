//Author: Sergio Jackson, Brysen Ross

#include <stdio.h>
#define MAXCOL 500
#define MAXROW 500
void loadimage(int* rowptr, int* colptr, int imagearray[][MAXCOL]);
void displayimage(int rows, int cols, int imagearray[][cols]);
void editimage();
void cropimage();
void brightenimage();
void dimimage();
void rotateimage();
void saveimage();

int main(){
	int image[MAXROW][MAXCOL];
	int row = 0;
	int col = 0;
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
		loadimage(&row, &col, image);
		break;
		default:
		printf("Invalid Option\n");
	}

	return 0;
}

void loadimage(int* rowptr, int* colptr, int imagearray[][MAXCOL]){
	int row, col;
	FILE* filepointer;
	char file[50];
	
	printf("Enter the name of the file:");
	scanf("%s", file);
	printf("%s\n", file);
	
	filepointer = fopen(file, "r");
	if(filepointer == NULL){
		printf("File does not exist.\n");
		}
	else{
		fscanf(filepointer,"%d %d", rowptr, colptr);
		for(row = 0; row < *rowptr; row++){
			for(col = 0; col < *colptr; col++){
				fscanf(filepointer,"%d", &imagearray[row][col]);
			}
		}
		fclose(filepointer);
	}
	for(row = 0; row < *rowptr; row++){
			for(col = 0; col < *colptr; col++){
				printf("%d ", imagearray[row][col]);
			}
		}
}

void displayimage(int rows, int cols, int imagearray[][cols]){
	int output_file;
	if(output_file == NULL) {
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                printf("%d ", imagearray[i][j]);
            }
            printf("\n");
        }
        } else {
       		 for(int i = 0; i < rows; i++) {
           	 for(int j = 0; j < cols; j++) {
              	  fprintf(output_file, "%d ", imagearray[i][j]);
         	   }
            fprintf(output_file, "\n");
       	 }
    }
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












