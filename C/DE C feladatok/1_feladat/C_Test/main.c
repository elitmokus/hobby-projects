#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    int a = 4, b = 4;

    if(++a == b)
        printf("%d",a);
    else
        printf("Nem");
}
