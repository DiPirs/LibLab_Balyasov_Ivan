#include <stdlib.h>
#include <math.h>
#include <stdio.h>


int main(void)
{
    int             n, i;                                           // переменные для счета генерации и для проверки индекса
    double          max, min, part_chast, a;                        // две переменных диапозона, переменная с дробной частью и переменная для генерации
    double          temp, number, sum = 0;                          // переменная для перестановки, переменная для целой части, переменная для подсчёта суммы

    printf("Input n: ");
    scanf_s("%d", &n);
    printf("Input min: ");
    scanf_s("%lf", &min);
    printf("Input max: ");
    scanf_s("%lf", &max);
    
    if (min > max){                                                 // Если случайно были перепутаны min и max при вводе, производится перестановка данных
        temp = min;
        min = max;
        max = temp;
    }

    for (i = 0; i < n; i++)
    {
        a = (double)rand() / RAND_MAX * (max - min) + min;          // генерирует число
        part_chast = modf(a, &number);                              // находит дробную часть

        if (i >= 0 && i < 10 && i != (int)(part_chast * 10))        // Проверка на совпадение дробной части с номером этого числа
            sum += a;
        else if (i >= 10 && i < 100 && i != (int)(part_chast * 100))
            sum += a;
        else if (i >= 100 && i < 1000 && i != (int)(part_chast * 1000))
            sum += a;
        else if (i >= 1000 && i < 10000 && i != (int)(part_chast * 10000))
            sum += a;
        else if (i >= 10000 && i < 100000 && i != (int)(part_chast * 100000))
            sum += a;
    }
    printf("SUM: %f\n\n", sum);
 
    return 0;
}
