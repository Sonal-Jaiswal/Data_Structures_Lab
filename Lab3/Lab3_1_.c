
#include <stdio.h>
#include <stdlib.h>

int main() {
	int rows, cols, size;

	printf("Enter Sparse Matrix in 3 Tuple format ");
	scanf("%d %d %d", &rows, &cols, &size); 
	int** data = NULL;

	for(int i = 0; i < size; i++) {
		data = realloc(data, (i+1) * sizeof(int*));
		data[i] = (int*)malloc(3 * sizeof(int));

		scanf("%d %d %d", (data[i] + 1), (data[i] + 0) ,(data[i] + 2));
	}
    

	// sorting of the transpose, similar to lexicographic

	for(int i = 0; i < size - 1; i++) {
		int minimumIndex = i; // current i is the starting
				
		for(int j = i + 1; j < size; j++) {
			int minimumWeight = *(data[minimumIndex] + 0) * 10 + *(data[minimumIndex] + 1);
			int currentWeight = *(data[j] + 0) * 10 + *(data[j] + 1);

			if(currentWeight < minimumWeight) {
				minimumIndex = j;
			}
		}
// swap using index
		int *temp = data[i];
		data[i] = data[minimumIndex];
		data[minimumIndex] = temp;

	}
	printf("\nTranspose of sparse matrix  \n");
	printf("R C Element\n");
	for(int i = 0; i < size; i++) {
		
		printf("\n%d %d %d", *(data[i] + 0), *(data[i] + 1), *(data[i] + 2));
	}

}
