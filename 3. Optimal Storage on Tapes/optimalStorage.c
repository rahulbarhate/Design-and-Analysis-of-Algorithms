#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y){
	int temp;
	temp = *x;
	*x = *y;
	*y = temp; 
}

void bubblesort(int arr[], int n){
	int i,j;
	for (i = 0; i < n-1; i++)
	{
		for (j = 0; j < n-i-1; j++)
		{
			if (arr[j]>arr[j+1])
			{
				swap(&arr[j], &arr[j+1]);
			}
		}
	}
}

void addToOrder(int j, int fileSize) {

}

int main() {

    int fileCount;
    int tapeCount;

    int *fileSizes;
    int *tapeSizes;
    int *spaceLeftOnTapes;

    int *sum;

    printf("Enter number of files\n");
    scanf("%d", &fileCount);

    fileSizes = (int *) malloc(sizeof(int) * fileCount);

    printf("Enter the sizes of the files\n");
    for (int i = 0;i < fileCount;i++) {
        scanf("%d", fileSizes + i);
    }

    bubblesort(fileSizes, fileCount);


    printf("Enter number of tapes\n");
    scanf("%d", &tapeCount);


    tapeSizes = (int *) malloc(sizeof(int) * tapeCount);
    spaceLeftOnTapes = (int *) malloc(sizeof(int) * tapeCount);

    printf("Enter the sizes of the tapes\n");
    for (int i = 0;i < tapeCount;i++) {
        
        scanf("%d", tapeSizes + i);
        *(spaceLeftOnTapes + i) = *(tapeSizes + i);

    }

    int tapeMatrix[tapeCount][fileCount];
    int tapeIndex[tapeCount];

    for (int i = 0;i < tapeCount;i++)
        tapeIndex[i] = 0;


    int k; 
    for (int i = 0, k = 0;i < fileCount;i++) {
        int flag = 0;
        for (int j = i % tapeCount;j < tapeCount && flag != 1;j++) {
            
            if (*(fileSizes + i) <= *(spaceLeftOnTapes + j)) {
                *(spaceLeftOnTapes + j) -= *(fileSizes + i);
                tapeMatrix[j][tapeIndex[j]] = *(fileSizes + i);
                tapeIndex[j] += 1;
                printf("Placed file with size %d on tape %d\n", *(fileSizes + i), j);
                flag = 1;

            }

        }
        if (flag == 0) {
            printf("File %d could not be placed due to space storage\n", i);
        }

    }

    for (int i = 0; i < tapeCount;i++) {

        int sum = 0;
        int multiplier;
        
        for (int j = 0, multiplier = tapeIndex[i];j < tapeIndex[i];j++, multiplier--) {

            sum += tapeMatrix[i][j];
            
        }

        printf("Total Retrieval Time for Tape %d is %d\n", i,  sum);
        float mrt =  (sum /(float) tapeIndex[i]);
        printf("Mean Retrieval Time is for Tape %d is %f\n", i, mrt);

    }

}   

