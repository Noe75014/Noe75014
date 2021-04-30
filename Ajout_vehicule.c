#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"
#define taille 100




// Fonction permettant d'ajouter un véhicule dans un tableau
void ajout(struct Vehicule tab[], int position)
{
fflush(stdin);
printf("Entrez le modele :  ");
fgets(tab[position].modele, 30, stdin);
fflush(stdin);
printf("Choisir la couleur : ");
fgets(tab[position].couleur, 30, stdin);
fflush(stdin);
printf("Entrez l'immatriculation du vehicule : ");
fgets(tab[position].immatriculation, 10, stdin);
printf("Nombre de places ? : ");
scanf("%d", &tab[position].nb_places);
}
// Fonction permettant d'afficher un véhicule
void affiche_vehicule(struct Vehicule v)
{
printf(" %s\n", v.modele);
printf(" %s\n", v.immatriculation);
printf(" %s\n", v.couleur);
printf(" %d\n", v.nb_places);
}
// Fonction permettant d'afficher les informations des véhicules:
void affiche_vehicules(struct Vehicule tab[], int position)
{
int i;
for(i=0; i < position; i++)
affiche_vehicule(tab[i]);
}
// Fonction permettant de modifier les informations d'un véhicule:
void modifie(struct Vehicule tab[], int position)
{
char immatriculation [30];
int trouve=0;

int i=0;
// Demander à l'employé l'immatriculation du véhicule à modifier :
fflush(stdin);
printf("Entrez l'immatriculation : ");
fgets(immatriculation, 30, stdin);

// Recherche du véhicule dans le tableau :
while(trouve == 0 && i < position)
{
if(strcmp(tab[i].immatriculation, immatriculation) == 0)
{
printf("Que souhaitez vous modifier sur ce vehicule ?....: ");

trouve=1;
}
i++;
}
if(trouve == 0)
printf("Vehicule introuvable\n");
}
