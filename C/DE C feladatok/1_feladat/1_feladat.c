#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a , b;
    printf("Integer value of variable a: ");
    scanf("%d", &a);
    printf("Integer value of variable b: ");
    scanf("%d", &b);
    if(a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
    printf("Value of variable a = %d \nValue of variable b = %d", a, b);
    return 0;
}
