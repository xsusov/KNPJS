#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char *Hlaska[] =
{
  [0] = "Nuzky",
  [1] = "Papir",
  [2] = "Kamen",
  [3] = "Jester",
  [4] = "Spock",
};


int main()
{
    int x;

     printf("0 = %s \n", Hlaska[0]);
        printf("1 = %s \n", Hlaska[1]);
         printf("2 = %s \n", Hlaska[2]);
          printf("3 = %s \n", Hlaska[3]);
           printf("4 = %s \n", Hlaska[4]);

    printf("Prepare for battle!\n");
    printf("Start!\n");

    while (42)
    {
        x =  volba();

        souboj(x);
    }




    return 0;
}


int volba()
{
    int x;

    x = getchar();

    if (x == '0' || x == '1' || x == '2'  || x == '3'  || x == '4')
    {
    x = x - '0';
    printf("Hrac voli: %s\n", Hlaska[x]);
    return x;
    }
    else
    volba();
}


int souboj(int x)
{
    int y;
    srand ( time(NULL) );
    y = rand()%5;
    printf("Oponent voli: %s\n", Hlaska[y]);
    if (x == y)
    {
        printf("Remiza! Start over!\n");
        souboj(volba());
    }

    else if ((x == y - 1) || (x == y + 4) || (x < y) && (x == y - 3) || (x > y) && (x == y + 2))
    {
        printf("Win!\n");
        return 1;
    }
    else
    {
        printf("Lose!\n");
        return 0;
    }
}
