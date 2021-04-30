#include <stdio.h>
#include "Menu_administrateur.h"
#include "Menu_clients.h"


int main ()
{

    int choix;


    do
    {
printf("                         __________________\n");
printf("                      _/ ||                ~-_\n");
printf("                    ,/   //       /~-       /  ~-_  ________----------//\n");
printf("  -----------------/-----------------\-------------------____________//\n");
printf(" O--------------  /              ~~^ |                             | ~|\n");
printf(" }======{--------\____________________|_____________________________|  |\n");
printf(" \===== / /~~~\\\\                      |         ____________________|-~\n");
printf("  \----| \\___/ ||--------------------'----------| \\____/ //\n");
printf("_____`.______.'________________________________`._______.'____________\n\n");



        printf("Tapez <1> pour une connexion Client\n");
        printf("Tapez <2> pour une connexion Administrateur\n");
        printf("Tapez <0> pour quitter\n");
        printf("Faites votre choix :");
        scanf("%d",&choix);
        printf("\n\n");

        if (choix == 1)
        {

            menu_client ();

        }
        if (choix == 2)
        {

            menu_employe();

        }

        if(choix !=1 && choix !=2 && choix != 0)
        {
            printf("Choix invalide!!\n\n");
        }
        if(choix == 0)

        {
            printf("Fin\n\n");
            return 0;

        }
    }while(choix !=1 || choix !=2);
}
