#include <stdio.h>
#include <stdlib.h>

int * t1;
int * t2;
int meret = 5;

int main()
{
    t1 = (int*)malloc(meret * sizeof(int));
    t2 = (int*)malloc(meret * sizeof(int));
    for(int i = 0; i < meret; i++)
    {
        t1[i] = i;
    }
    for(int i = 0; i < meret; i++)
    {
        t2[i] = meret - i;
    }
    listazas(t1);
    listazas(t2);
    torles(t1);
    torles(t2);
    meret = 4;
    listazas(t1);
    listazas(t2);

    return 0;
}


void torles(int t[])
{
    //int * tmp_t = (int*)malloc(meret * sizeof(int));

    t[2] = t[4];

    t = realloc(t, 4 * sizeof(int));
}

void listazas(int t[])
{
    printf("Listaaa\n");
    for(int i = 0; i < meret; i++)
    {
        printf("%d\n", t[i]);
    }
}
