#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <malloc.h>

#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
    int             n, i;                                           
    double          max, min, part_chast, a;                        
    double          number, sum = 0;                          
    double*         mas;

    system("chcp 1251");
    system("cls");

    printf("Input n: ");
    scanf_s("%d", &n);
    printf("Input min: ");
    scanf_s("%lf", &min);
    printf("Input max: ");
    scanf_s("%lf", &max);

    mas = (double*)malloc(n * sizeof(double));

    for (i = 0; i < n; i++)
    {
        a = (((double)rand()) / RAND_MAX) * (max - min) + min;
        mas[i] = a;
    }

    for (i = 0; i < n; i++)
    {
        part_chast = modf(mas[i], &number);

        if (i >= 0 && i < 10 && i == (int)(part_chast * 10))
            sum -= mas[i];
        else if (i >= 10 && i < 100 && i == (int)(part_chast * 100))
            sum -= mas[i];
        else if (i >= 100 && i < 1000 && i == (int)(part_chast * 1000))
            sum -= mas[i];
        else if (i >= 1000 && i < 10000 && i == (int)(part_chast * 10000))
            sum -= mas[i];
        else if (i >= 10000 && i < 100000 && i == (int)(part_chast * 100000))
            sum -= mas[i];
        else  
            sum += mas[i];
            
    }

    printf("SUM: %f\n\n", sum);

    free(mas);

    return 0;
}

