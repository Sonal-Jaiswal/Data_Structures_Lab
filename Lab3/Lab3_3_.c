#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter maximum degree of x: ");
    scanf("%d", &n);


    int *p = (int *)malloc((n + 1) * sizeof(int));
    int *q = (int *)malloc((n + 1) * sizeof(int));
    int *r = (int *)malloc((n + 1) * sizeof(int));

    printf("Enter Polynomial-1 from lowest degree to highest degree : \n");
    for (int i = 0; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }

    printf("Enter polynomial 2:\n");
    for (int i = 0; i <= n; i++)
    {
        scanf("%d", &q[i]);
    }

    // Perform polynomial addition
    for (int i = 0; i <= n; i++)
    {
        r[i] = p[i] + q[i];
    }

    printf("Resultant Polynomial: ");
    for (int i = n; i >= 0; i--)
    {
        printf("%dx^%d", r[i], i);
        if (i > 0)
        {
            printf("+");
        }
    }


}
