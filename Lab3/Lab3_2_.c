#include <stdio.h>

char rel(int a, int b);
void add(int m1[][3], int m2[][3], int m3[][3]);

char rel(int a, int b)
{
    if (a < b)
        return '<';
    else if (a > b)
        return '>';
    else
        return '=';
}

void add(int m1[][3], int m2[][3], int m3[][3])
{
    int i, j, k = 0, m, n;
    if ((m1[0][0] != m2[0][0]) || (m1[0][1] != m2[0][1]))
    {
        printf("*Invalid Operation*");
        return;
    }
    m3[0][0] = m1[0][0];
    m3[0][1] = m1[0][1];
    m = m1[0][2];
    n = m2[0][2];
    i = 1;
    j = 1;
    while ((i <= m) && (j <= n))
    {
        k++;
        switch (rel(m1[i][0], m2[j][0]))
        {
        case '=':
            switch (rel(m1[i][1], m2[j][1]))
            {
            case '=':
                m3[k][0] = m1[i][0];
                m3[k][1] = m1[i][1];
                m3[k][2] = m1[i][2] + m2[j][2];
                i++;
                j++;
                break;
            case '<':
                m3[k][0] = m1[i][0];
                m3[k][1] = m1[i][1];
                m3[k][2] = m1[i][2];
                i++;
                break;
            case '>':
                m3[k][0] = m2[j][0];
                m3[k][1] = m2[j][1];
                m3[k][2] = m2[j][2];
                j++;
                break;
            }
            break;
        case '<':
            m3[k][0] = m1[i][0];
            m3[k][1] = m1[i][1];
            m3[k][2] = m1[i][2];
            i++;
            break;
        case '>':
            m3[k][0] = m2[j][0];
            m3[k][1] = m2[j][1];
            m3[k][2] = m2[j][2];
            j++;
            break;
        }
    }
    while (i <= m)
    {
        k++;
        m3[k][0] = m1[i][0];
        m3[k][1] = m1[i][1];
        m3[k][2] = m1[i][2];
        i++;
    }
    while (j <= n)
    {
        k++;
        m3[k][0] = m2[j][0];
        m3[k][1] = m2[j][1];
        m3[k][2] = m2[j][2];
        j++;
    }
    m3[0][2] = k;
}

int main()
{
    int n;
    int m1[n][3], m2[n][3], m3[n][3];
    printf("Enter row number, column number, and number of non-zero elements for sparse matrix 1: \n");
    scanf("%d %d %d", &m1[0][0], &m1[0][1], &n);
    
    m1[0][2] = n;
    printf("Enter the sparse matrix 1: \n");
    for (int i = 1; i <= m1[0][2]; i++)
    {
        scanf("%d %d %d", &m1[i][0], &m1[i][1], &m1[i][2]);
    }
    printf("Sparse matrix 1: \n");
    for (int i = 0; i < (m1[0][2] + 1); i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", m1[i][j]);
        }
        printf("\n");
    }
    printf("Enter row number, column number, and number of non-zero elements for sparse matrix 2: \n");
    scanf("%d %d %d", &m2[0][0], &m2[0][1], &n);
    m2[0][2] = n;
    printf("Enter the sparse matrix 2: \n");
    for (int i = 1; i <= m2[0][2]; i++)
    {
        scanf("%d %d %d", &m2[i][0], &m2[i][1], &m2[i][2]);
    }
    printf("Sparse matrix 2: \n");
    for (int i = 0; i < (m2[0][2] + 1); i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", m2[i][j]);
        }
        printf("\n");
    }
    add(m1, m2, m3);
    printf("Sparse matrix 3: \n");
    for (int i = 0; i < (m3[0][2] + 1); i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%4d ", m3[i][j]);
        }
        printf("\n");
    }
    return 0;
}