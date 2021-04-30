#include <stdio.h>
#include <string.h>
#include "structure.h"

int detection()//Détecter si on a besoin de créer des fichiers. Rentrer un entier 1 si oui, 0 si non.
{
    int i=0;
    FILE *Dico;
    Dico=fopen("Admi.dat","rb");
    if(Dico==NULL)
    {
        puts("C'est le premier fois que vous utilisez le systeme.Bienvenue!");
        i=1;
        fclose(Dico);
    }
    else
        fclose(Dico);
    return i;
}

void creaction_admi()//Creation des donnees administrateur.
{
    struct Administrateur admi [5];
    strcpy(admi[1].nom,"HUANG");
    strcpy(admi[1].prenom,"Ziyang");
    strcpy(admi[1].nom_utilisateur,"IGNB");
    admi[1].mdp=1234;

    strcpy(admi[2].nom,"ROUX");
    strcpy(admi[2].prenom,"Noé");
    strcpy(admi[2].nom_utilisateur,"toto");
    admi[2].mdp=1234;

    printf("\nBienvenue! Vous êtes entrain d'enregistrer comme administrateur!\n");
    printf("Entrez votre nom:");
    fflush(stdin);
    fgets(admi[3].nom,30,stdin);
    printf("Entrez votre prenom:");
    fflush(stdin);
    fgets(admi[3].prenom,30,stdin);
    printf("Entrez le nom d'utilisateur:");
    fflush(stdin);
    fgets(admi[3].nom_utilisateur,30,stdin);
    printf("Entrez me mot de passe:");
    scanf("%d",&admi[3].mdp);

    strcpy(admi[3].nom,"Professeur");
    strcpy(admi[3].prenom,"Monsieur");
    strcpy(admi[3].nom_utilisateur,"abc");
    admi[3].mdp=1234;

    FILE *Dico;//Stockage des données administrateur
    Dico=fopen("Admi.dat","a");
    if(Dico==NULL)
        puts("Problème d'ouverture.");
    else
    {
        fwrite(&admi,sizeof(admi),1,Dico);
        fclose(Dico);
    }
}

void creaction_clients()
{
    struct Client cli[30];
    strcpy(cli[1].nom,"Arthur");
    strcpy(cli[1].prenom,"Donarld");
    strcpy(cli[1].mail,"156165165@gmail.com");
    strcpy(cli[1].sexe,"M");
    strcpy(cli[1].nom_utilisateur,"ff");
    cli[1].age=22;
    cli[1].num_de_tel=754231568;
    cli[1].mdp=156165;

    FILE *Dico;//Stockage des données clients
    Dico=fopen("Cli.dat","a");
    if(Dico==NULL)
        puts("Problème d'ouverture.");
    else
    {
        fwrite(&cli,sizeof(cli),1,Dico);
        fclose(Dico);
    }
}


void creaction_voitures()
{
    struct Vehicule vehi[50];
    strcpy(vehi[1].modele,"Tesla");
    strcpy(vehi[1].couleur,"Jaune");
    strcpy(vehi[1].immatriculation,"DHQ9418");
    vehi[1].nb_places=2;

    strcpy(vehi[2].modele,"Renault");
    strcpy(vehi[2].couleur,"Jaune");
    strcpy(vehi[2].immatriculation,"FDF1568");
    vehi[2].nb_places=2;

    strcpy(vehi[3].modele,"Ford");
    strcpy(vehi[3].couleur,"Jaune");
    strcpy(vehi[3].immatriculation,"QFD9445");
    vehi[3].nb_places=2;

    strcpy(vehi[4].modele,"Tesla");
    strcpy(vehi[4].couleur,"Jaune");
    strcpy(vehi[4].immatriculation,"SQD1594");
    vehi[4].nb_places=2;

    strcpy(vehi[5].modele,"Renault");
    strcpy(vehi[5].couleur,"Jaune");
    strcpy(vehi[5].immatriculation,"FGD1482");
    vehi[5].nb_places=2;

    strcpy(vehi[6].modele,"Ford");
    strcpy(vehi[6].couleur,"Jaune");
    strcpy(vehi[6].immatriculation,"GGJ1564");
    vehi[6].nb_places=2;

    strcpy(vehi[7].modele,"Tesla");
    strcpy(vehi[7].couleur,"Jaune");
    strcpy(vehi[7].immatriculation,"SGF1859");
    vehi[7].nb_places=2;

    strcpy(vehi[8].modele,"Renault");
    strcpy(vehi[8].couleur,"Jaune");
    strcpy(vehi[8].immatriculation,"SGF1498");
    vehi[8].nb_places=2;

    strcpy(vehi[9].modele,"Ford");
    strcpy(vehi[9].couleur,"Jaune");
    strcpy(vehi[9].immatriculation,"SJG1972");
    vehi[9].nb_places=2;


    FILE *Dico;//Stockage des données VOITURES
    Dico=fopen("voitures.dat","a");
    if(Dico==NULL)
        puts("Problème d'ouverture.");
    else
    {
        fwrite(&vehi,sizeof(vehi),1,Dico);
        fclose(Dico);
    }
}
