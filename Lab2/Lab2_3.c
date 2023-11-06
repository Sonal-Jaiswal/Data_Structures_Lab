#include <stdio.h>
#include <stdlib.h>

int main()
 {

	int r,c;

	printf("Enter size of the sparse matrix: ");
	scanf("%d %d", &r, &c );

	int **p;
	int count=0;
	printf("Enter elements of sparse matrix:");

	for(int i = 0; i < r; i++)
	 {
		for(int j = 0; j < c; j++)
		 {
			int val;
			scanf("%d", &val);
			if(val != 0)
			{
				count++;

				p = realloc(p,count*sizeof(int*));
				p[count - 1] = (int*) malloc(3 * sizeof(int));

				*(p[count - 1] + 0) = i;
				*(p[count - 1] + 1) = j;
				*(p[count - 1] + 2) = val;
			}
		}
	}
   printf("Sparse Matrix in 3-tuple format\n%d	%d	%d\n",r,c,(count-1));
	for(int i = 0; i < count; i++)
		printf("%d	%d	%d\n", *(p[i] + 0), *(p[i] + 1), *(p[i] + 2));
}