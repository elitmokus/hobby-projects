#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct bicikli
{
    char tipus[10];
    char SN[20];
    int gyartas_ev;
}bicikli;

typedef struct gyarto
{
    char gyarto_nev[21];
    char gyarto_cim[36];
    int mennyiseg;
    bicikli* biciklik;
}gyarto;

void menu();
int sorok_szama();
void felvetel();
bool ugyanolyan_SN(char tmp_SN[20]);
void string_to_lower(char tmp_string[]);
void torles();
void rendezes();
void SN_rendezes();
void gyarto_rendezes();
void listazas();
void mentes();
void betoltes();
void feltolt(char tmp_nev[21], char tmp_cim[36], char tmp_tipus[10], int tmp_gyartas_ev, char tmp_SN[21]);

int bolt_meret = 0;
gyarto* bicikli_bolt;
int last_index = 0;

int main()
{

    menu();

    free(bicikli_bolt);
    return 0;
}

void menu()
{
    int val;

    do{
        system("cls");
        printf("\n\n\n\t1. Felvetel\n");
        printf("\t2. Torles\n");
        printf("\t3. Listazas\n");
        printf("\t4. Rendezes\n");
        printf("\t5. Mentes\n");
        printf("\t6. Betoltes\n");
        printf("\t7. Mentes\n");
        printf("\t8. Beszerzes\n");
        printf("\t0. Kilepes\n\n\t");

        scanf("%d",&val);

        switch(val){
            case 1:
                felvetel();
                break;
            case 2:
                torles();
                break;
            case 3:
                listazas();
                break;
            case 4:
                rendezes();
                break;
            case 5:
                mentes();
                break;
            case 6:
                betoltes();
                break;
            case 7:
                //Eladas();
                break;
            case 8:
                //Beszerzes();
                break;
            case 0:
                printf("\n\n\n\tViszlat legkozelebb!\n\n\n\n\n");exit(1);
                break;
            default:
                printf("\n\n\n\tNincs ilyen menupont, probald meg megegyszer!");
        }
    }while(val!=0);
}

void felvetel()
{
    system("cls");
    printf("Bicikli felvetele\n");
    printf("------------------------------------------\n\n");
    getchar();

    char tmp_nev[21];
    char tmp_cim[36];
    int tmp_index = last_index;

    printf("Add meg a gyarto nevet: ");
        fgets(tmp_nev, sizeof(tmp_nev), stdin);
        tmp_nev[strlen(tmp_nev)-1] = '\0';

    bool uj_marka = true;
    ///Megnyitjuk a boltot
    if(bolt_meret == 0)
    {
        bolt_meret = 1;
        bicikli_bolt = (gyarto*)malloc( bolt_meret * sizeof(gyarto));
        printf("Add meg a gyarto cimet: ");
            fgets(tmp_cim, sizeof(tmp_cim), stdin);
            tmp_cim[strlen(tmp_cim)-1] = '\0';
        strcpy(bicikli_bolt[tmp_index].gyarto_nev, tmp_nev);
        strcpy(bicikli_bolt[tmp_index].gyarto_cim, tmp_cim);
        bicikli_bolt[tmp_index].mennyiseg = 0;
    }
    else
    {
        for(int i = 0; i < bolt_meret && uj_marka; i++)
        {
            ///Meglévõ gyártó a boltban
            if(strcmp(bicikli_bolt[i].gyarto_nev, tmp_nev) == 0)
            {
                tmp_index = i;
                uj_marka = false;
            }
        }
        ///Új gyártó
        if(uj_marka)
        {
            bolt_meret++;
            bicikli_bolt = realloc(bicikli_bolt, bolt_meret * sizeof(gyarto));
            last_index++;
            tmp_index = last_index;
            printf("Add meg a gyarto cimet: ");
                fgets(tmp_cim, sizeof(tmp_cim), stdin);
                tmp_cim[strlen(tmp_cim)-1] = '\0';
                //scanf ("%[^\n]%*c", tmp_cim);
            strcpy(bicikli_bolt[tmp_index].gyarto_nev, tmp_nev);
            strcpy(bicikli_bolt[tmp_index].gyarto_cim, tmp_cim);
            bicikli_bolt[tmp_index].mennyiseg = 0;
        }
    }
    int tmp_mennyiseg;
        printf("Add meg a biciklik szamat: ");
        scanf("%d", &tmp_mennyiseg);
        getchar(); ///Elnyeli az int utáni Enter-t
    int bicikli_index;
    if(bicikli_bolt[tmp_index].mennyiseg == 0)
    {
        bicikli_index = 0;
        bicikli_bolt[tmp_index].mennyiseg += tmp_mennyiseg;
        bicikli_bolt[tmp_index].biciklik = (bicikli*)malloc(bicikli_bolt[tmp_index].mennyiseg * sizeof(bicikli));
    }
    else
    {
        bicikli_index = bicikli_bolt[tmp_index].mennyiseg;
        bicikli_bolt[tmp_index].mennyiseg += tmp_mennyiseg;
        bicikli_bolt[tmp_index].biciklik = realloc(bicikli_bolt[tmp_index].biciklik, bicikli_bolt[tmp_index].mennyiseg * sizeof(bicikli));
    }
    ///printf("Mennyiseg: %d\n", bicikli_bolt[tmp_index].mennyiseg);
    char tmp_tipus[10];
    char tmp_SN[20];
    int tmp_gyartas_ev;

    printf("Add meg a bicikli tipusat: ");
        fgets(tmp_tipus, sizeof(tmp_tipus), stdin);
        tmp_tipus[strlen(tmp_tipus)-1] = '\0';
    printf("Add meg a bicikli gyartasi evet: ");
        scanf("%d", &tmp_gyartas_ev);
        getchar(); ///Elnyeli az int utáni Enter-t
    for(int i = 0; i < tmp_mennyiseg; i++)
    {
        ///printf("bicikli_index: %d\n", bicikli_index);
        ///itt lehetne az SN-t generálni, de az is jó, ha beírja
        do
        {
            printf("Add meg a(z) %d. bicikli sorozatszamat: ", i+1);
                fgets(tmp_SN, sizeof(tmp_SN), stdin);
                tmp_SN[strlen(tmp_SN)-1] = '\0';
        }while(ugyanolyan_SN(tmp_SN));

        strcpy(bicikli_bolt[tmp_index].biciklik[bicikli_index].tipus, tmp_tipus);
        strcpy(bicikli_bolt[tmp_index].biciklik[bicikli_index].SN, tmp_SN);
        bicikli_bolt[tmp_index].biciklik[bicikli_index].gyartas_ev = tmp_gyartas_ev;
        bicikli_index++;
    }
}

bool ugyanolyan_SN(char tmp_SN[20])
{
    bool ugyanolyan = false;
    for(int i = 0; i < bolt_meret && !ugyanolyan; i++)
    {
        for(int j = 0; j < bicikli_bolt[i].mennyiseg && !ugyanolyan; j++)
        {
            if(strcmp(bicikli_bolt[i].biciklik[j].SN, tmp_SN) == 0)
            {
                ugyanolyan = true;
            }
        }
    }
    return ugyanolyan;
}

void torles()
{
    /// CSAK SN ALAPJÁN LEHET TÖRÖLNI
    getchar(); ///Elnyeli az Entert
    system("cls");
    printf("Torles");
    printf("------------------------------------------\n\n");
    char tmp_SN[20];
    printf("Add meg a torolni kivant bicikli sorozatszamat (SN): ");
        fgets(tmp_SN, sizeof(tmp_SN), stdin);
        tmp_SN[strlen(tmp_SN)-1] = '\0';
    ///Megkeressük a beírt SN-t
    bool talalt = false;
    int gyarto_index;
    int bicikli_index;
    int biciklik_szama;
    for(int i = 0; i < bolt_meret && !talalt; i++)
    {
        for(int j = 0; j < bicikli_bolt[i].mennyiseg && !talalt; j++)
        {
            if(strcmp(bicikli_bolt[i].biciklik[j].SN, tmp_SN) == 0)
            {
                biciklik_szama = bicikli_bolt[i].mennyiseg - 1;
                gyarto_index = i;
                bicikli_index = j;
                talalt = true;
            }
        }
    }
    if(talalt)
    {
        /// Az utolsó helyen lévő bicikli adatait betesszük a törölni kívánt bicikli helyére
        strcpy(bicikli_bolt[gyarto_index].biciklik[bicikli_index].tipus, bicikli_bolt[gyarto_index].biciklik[biciklik_szama].tipus);
        strcpy(bicikli_bolt[gyarto_index].biciklik[bicikli_index].SN, bicikli_bolt[gyarto_index].biciklik[biciklik_szama].SN);
        bicikli_bolt[gyarto_index].biciklik[bicikli_index].gyartas_ev = bicikli_bolt[gyarto_index].biciklik[biciklik_szama].gyartas_ev;
        /// Csökkentjük a biciklik tömb méretét
        bicikli_bolt[gyarto_index].mennyiseg--;
        if(bicikli_bolt[gyarto_index].mennyiseg > 0)
        {
            /// Csökkentem a lefoglalt memóriát
            bicikli_bolt[gyarto_index].biciklik = realloc(bicikli_bolt[gyarto_index].biciklik, bicikli_bolt[gyarto_index].mennyiseg * sizeof(bicikli));
        }
        else
        {
            /// Megszűntetem a lefoglalt memóriát
            free(bicikli_bolt[gyarto_index].biciklik);
        }

        printf("\n\nKeresett bicikli torolve. Nyomj egy Entert");
        getchar();
    }
    else
    {
        printf("\n\nNincs ilyen sorozatszamu bicikli. Nyomj egy Entert!");
        getchar();
    }
}

void rendezes()
{
    SN_rendezes();
    gyarto_rendezes();

}

void SN_rendezes()
{
    bicikli tmp[1];
    for(int i = 0; i < bolt_meret; i++)
    {
        for(int j = 0; j < bicikli_bolt[i].mennyiseg - 1; j++)
        {
            for(int k = j+1; k < bicikli_bolt[i].mennyiseg; k++)
            {
                if(strcmp(bicikli_bolt[i].biciklik[j].SN, bicikli_bolt[i].biciklik[k].SN) > 0)
                {
                    strcpy(tmp[0].SN, bicikli_bolt[i].biciklik[j].SN);
                    strcpy(tmp[0].tipus, bicikli_bolt[i].biciklik[j].tipus);
                    tmp[0].gyartas_ev = bicikli_bolt[i].biciklik[j].gyartas_ev;

                    strcpy(bicikli_bolt[i].biciklik[j].SN, bicikli_bolt[i].biciklik[k].SN);
                    strcpy(bicikli_bolt[i].biciklik[j].tipus, bicikli_bolt[i].biciklik[k].tipus);
                    bicikli_bolt[i].biciklik[j].gyartas_ev = bicikli_bolt[i].biciklik[k].gyartas_ev;

                    strcpy(bicikli_bolt[i].biciklik[k].SN, tmp[0].SN);
                    strcpy(bicikli_bolt[i].biciklik[k].tipus, tmp[0].tipus);
                    bicikli_bolt[i].biciklik[k].gyartas_ev = tmp[0].gyartas_ev;
                }
            }
        }
    }
}

void gyarto_rendezes()
{
    gyarto tmp[1];
    for(int i = 0; i < bolt_meret-1; i++)
    {
        for(int j = i+1; j < bolt_meret; j++)
        {
            if(strcmp(bicikli_bolt[i].gyarto_nev, bicikli_bolt[j].gyarto_nev) > 0)
            {
                strcpy(tmp[0].gyarto_cim, bicikli_bolt[i].gyarto_cim);
                strcpy(tmp[0].gyarto_nev, bicikli_bolt[i].gyarto_nev);
                tmp[0].mennyiseg = bicikli_bolt[i].mennyiseg;
                tmp[0].biciklik = bicikli_bolt[i].biciklik;

                strcpy(bicikli_bolt[i].gyarto_cim, bicikli_bolt[j].gyarto_cim);
                strcpy(bicikli_bolt[i].gyarto_nev, bicikli_bolt[j].gyarto_nev);
                bicikli_bolt[i].mennyiseg = bicikli_bolt[j].mennyiseg;
                bicikli_bolt[i].biciklik = bicikli_bolt[j].biciklik;

                strcpy(bicikli_bolt[j].gyarto_cim, tmp[0].gyarto_cim);
                strcpy(bicikli_bolt[j].gyarto_nev, tmp[0].gyarto_nev);
                bicikli_bolt[j].mennyiseg = tmp[0].mennyiseg;
                bicikli_bolt[j].biciklik = tmp[0].biciklik;
            }
        }
    }
}

void listazas()
{
    system("cls");
    printf("Biciklik listazasa\n");
    printf("------------------------------------------\n\n");
    for(int i = 0; i < bolt_meret; i++)
    {
        printf("Gyarto: %s\n", bicikli_bolt[i].gyarto_nev);
        printf("Cim: %s\n", bicikli_bolt[i].gyarto_cim);
        printf("Mennyiseg: %d\n\n", bicikli_bolt[i].mennyiseg);
        printf("\tTipus\tSorozatszam\tGyartas eve\n");
        for(int j = 0; j < bicikli_bolt[i].mennyiseg; j++)
        {
            printf("\t%s", bicikli_bolt[i].biciklik[j].tipus);
            printf("\t%s", bicikli_bolt[i].biciklik[j].SN);
            printf("\t\t%d\n", bicikli_bolt[i].biciklik[j].gyartas_ev);
        }
        printf("\n");
    }

    printf("\n\n");
    printf("Nyomj egy Entert!");
    getchar();
    getchar();
}

void mentes(){
    system("cls");
    printf("\n\tMentes..\n");

    FILE* fp;
    fp=fopen("adatbazis.txt","w");
    int i=0,j=0;

    for(i=0;i<bolt_meret;i++){
        for(j=0;j<bicikli_bolt[i].mennyiseg;j++){
        fprintf(fp,"%s\t%s %s %d %s\n", bicikli_bolt[i].gyarto_nev,bicikli_bolt[i].gyarto_cim,bicikli_bolt[i].biciklik[j].tipus,bicikli_bolt[i].biciklik[j].gyartas_ev,bicikli_bolt[i].biciklik[j].SN);
        }
    }

    printf("Nyomj egy gombot!");
    getchar();
    getchar();
    ///A free eltünteti az elejéről a malloc-ot
    fclose(fp); printf("\n\tAz adatok mentese sikerse volt..");

}

int sorok_szama(){

    FILE *sfp;
    int cnt = 0;
    char c;

    sfp = fopen("adatbazis.txt", "r");

    if (sfp == NULL){
        printf("\tNem sikerult megnyitni a fajlt");
        return 0;
    }

    for (c = getc(sfp); c != EOF; c = getc(sfp)) {
        if (c == '\n')
            cnt = cnt + 1;
    }

    fclose(sfp);
    return cnt;
}

void betoltes()
{
    free(bicikli_bolt);
    system("cls");
    printf("\n\tBetoltes..\n");
    bolt_meret=0;
    FILE* ofp;
    ofp=fopen("adatbazis.txt","r");
    if (ofp == NULL){
        printf("\tNem sikerult megnyitni a fajlt");
        return 0;
    }
    int sor_szama = sorok_szama();
    char tmp_nev[21], tmp_cim[36];
    char tmp_tipus[10], tmp_SN[21];
    int tmp_mennyiseg = 0, tmp_gyartas_ev;

    for(int i = 0; i < sor_szama; i++)
    {
        feltolt(tmp_nev, tmp_cim, tmp_tipus, tmp_gyartas_ev, tmp_SN);
    }

    printf("Nyomj egy Enter-t!");
    getchar();
    getchar();
}

void feltolt(char tmp_nev[21], char tmp_cim[36], char tmp_tipus[10], int tmp_gyartas_ev, char tmp_SN[21])
{
    int tmp_index = last_index;
    bool uj_marka = true;

    if(bolt_meret == 0)
    {
        bolt_meret = 1;
        bicikli_bolt = (gyarto*)malloc( bolt_meret * sizeof(gyarto));
        strcpy(bicikli_bolt[tmp_index].gyarto_nev, tmp_nev);
        strcpy(bicikli_bolt[tmp_index].gyarto_cim, tmp_cim);
        bicikli_bolt[tmp_index].mennyiseg = 0;
//        printf("Uj bolt\n");
//        printf("Uj nev: %s\n", bicikli_bolt[tmp_index].gyarto_nev);
//        printf("Uj cim: %s\n", bicikli_bolt[tmp_index].gyarto_cim);
    }
    else
    {
        for(int i = 0; i < bolt_meret && uj_marka; i++)
        {
            ///Meglévõ gyártó a boltban
            if(strcmp(bicikli_bolt[i].gyarto_nev, tmp_nev) == 0)
            {
                tmp_index = i;
                uj_marka = false;
            }
        }
        ///Új gyártó
        if(uj_marka)
        {
            bolt_meret++;
            bicikli_bolt = realloc(bicikli_bolt, bolt_meret * sizeof(gyarto));
            last_index++;
            tmp_index = last_index;
            strcpy(bicikli_bolt[tmp_index].gyarto_nev, tmp_nev);
            strcpy(bicikli_bolt[tmp_index].gyarto_cim, tmp_cim);
            bicikli_bolt[tmp_index].mennyiseg = 0;
        }
    }
    int tmp_mennyiseg = 1;
    int bicikli_index;

    if(bicikli_bolt[tmp_index].mennyiseg == 0)
    {
        bicikli_index = bicikli_bolt[tmp_index].mennyiseg;
        bicikli_bolt[tmp_index].mennyiseg += tmp_mennyiseg;
        bicikli_bolt[tmp_index].biciklik = (bicikli*)malloc(bicikli_bolt[tmp_index].mennyiseg * sizeof(bicikli));
    }
    else
    {
        bicikli_index = bicikli_bolt[tmp_index].mennyiseg;
        bicikli_bolt[tmp_index].mennyiseg += tmp_mennyiseg;
        bicikli_bolt[tmp_index].biciklik = realloc(bicikli_bolt[tmp_index].biciklik, bicikli_bolt[tmp_index].mennyiseg * sizeof(bicikli));
    }

    strcpy(bicikli_bolt[tmp_index].biciklik[bicikli_index].tipus, tmp_tipus);
    strcpy(bicikli_bolt[tmp_index].biciklik[bicikli_index].SN, tmp_SN);
    bicikli_bolt[tmp_index].biciklik[bicikli_index].gyartas_ev = tmp_gyartas_ev;
    bicikli_index++;
}
