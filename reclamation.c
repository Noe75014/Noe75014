#include<stdio.h>
#include"reclamation.h"

void creation_fichier()//initialisation de int position=0
{
    position=0;

    FILE *Dico;//Stockage des réclamations
    Dico=fopen("reclamations.dat","a");
    if(Dico==NULL)
        puts("Problème d'ouverture.");
    else
    {
        fwrite(&position,sizeof(position),1,Dico);
        fclose(Dico);
    }
}



void donner_les_avis()
{

    FILE *Dico;//Stockage des réclamations
    Dico=fopen("reclamations.dat","r");
    if(Dico==NULL)
        puts("Problème d'ouverture.");
    else
    {
        fread(&position,sizeof(position),1,Dico);
        fclose(Dico);
    }

    struct Reclamation re[30];
    printf("Entrez si vous êtes satisfait ou pas: 1. satisfait  2.non satisfait");
    scanf("%d",&re[position].choix);
    printf("Entrez la situation precises.");
    fflush(stdin);
    fgets(re[position].preci,300,stdin);

    FILE *Dic;//Stockage des réclamations
    Dico=fopen("reclamations.dat","w");
    if(Dico==NULL)
        puts("Problème d'ouverture.");
    else
    {
        fwrite(&re,sizeof(re),1,Dic);
        fclose(Dic);
    }
}

void consulter_des_avis()
{
    struct Reclamation re[30];
    int i,position;

    FILE *Dico;//Stockage des réclamations
    Dico=fopen("reclamations.dat","r");
    if(Dico==NULL)
        puts("Problème d'ouverture.");
    else
    {
        fread(&re,sizeof(re),1,Dico);
        fread(&position,sizeof(position),1,Dico);
        fclose(Dico);
    }

    for(i=0;i<=position;i++)
    {
        if(re[i].choix==1)
            printf("Satisfed\n");
        else
            printf("Non satisfed\n");
        printf("%c \n\n",re[i].preci);
    }
}
