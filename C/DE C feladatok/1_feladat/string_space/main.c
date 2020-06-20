#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    char str1[30];
    char str[30];
    printf("\nWrite a number:");
    scanf("%d", &n); getchar();
    printf("\tWrite something: ");
    scanf("%*c", &str1); getchar();
    //str1[strlen(str1) - 1] = '\0';
    printf("\n\t Write something: ");
    scanf("%*c", &str1); getchar();
    //str[strlen(str) - 1] = '\0';
    printf("%s", str1);
    printf("%s", str);
}
