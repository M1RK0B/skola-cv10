#include <stdio.h>
#include <stdlib.h>


typedef struct student
{
    char priezvisko_meno[100];
    int rocnik;
    float priemer;
} STUDENT;


STUDENT *nacitajPole(char *subor, int *nacitane)
{
    FILE *fr;
    int pocet,i;
    STUDENT *p;

    //testovanie èi existuje subor
    if ((fr = fopen(subor, "r")) == NULL)
    {
        printf("nepodarilo sa otvorit subor na zapis\n");
        return 0;
    }

    //zistenie velkosti
    fscanf(fr, "%d", &pocet);
    p=(STUDENT *) malloc(sizeof(STUDENT));

    //naèítanie hodnôt zo subora
    for(i=0;i<pocet;i++);
    {
        fgets(fr,"%s",p->priezvisko_meno[i]);
        fscanf(fr,"%d %f",(p+i)->rocnik,(p+i)->priemer);
    }

    return p;
    *nacitane = pocet;
}

void vypis (STUDENT *studenti, int pocet)
{
    //cyklus na vypísanie premenných zo súboru
    for( int i=0;i<pocet;i++)
    {
    printf("%s;%d;%d \n", studenti[i].priezvisko_meno, studenti[i].rocnik, studenti[i].priemer);
    }
        printf("\n");
}

STUDENT *najlepsiPole (STUDENT *studenti, int pocet, int rocnik)
{
//inicializácia premenných
int naj = 0;
float priemer = 5.0, p;

if(studenti->rocnik == rocnik)
{

    for(int i=0;i<pocet;i++)
    {
        if(p=studenti[i].priemer<=priemer)
        {
         priemer = p;
         naj=i;
        }
    }
}
return naj;
}


int main()
{
  STUDENT *pole, *naj;
  int pocet;
  pole = nacitajPole("vstup.txt", &pocet);
  if (pole == NULL){
    printf("nepodarilo sa nacitat a naplnit pole");
    return -1;
  }
  vypis(pole, pocet);
  naj = najlepsiPole(pole, pocet, 3);
  if (naj == NULL) {
  printf("v rocniku nie je student");
  return -2;
  }
  printf("najlepsi student je %s", naj->priezvisko_meno);
  return 0;
}
