#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"
#define taille 100



//Fonction permettant d'ajouter un employé au tableau d'employés
void ajoute_employe(struct Employe tab[], int position)
{

                        fflush(stdin);
                        printf("Chosis ton nom d'utilisateur");
                        fgets(tab[position].nom_utilisateur, 30, stdin);
                        fflush(stdin);
                        printf("Chosis ton mot de passe : ");
                        scanf("%d",&tab[position].password);
                    }

//Ajoute et enregistres l'employé dans un fichier employé
void enregistrer(struct Employe tab [], int position)
{
    FILE *fichier;
    int i;
    fichier = fopen("employes.dat", "w");
    for(i=0; i<position; i++)
        fwrite(&tab[i], sizeof (struct Employe), 1, fichier);
    fclose(fichier);
}

// Fonction permettant d'afficher les informations d'un employé :
void afficher_employe(struct Employe employe)
{
printf(" %s ", employe.nom_utilisateur);
printf(" %d ", employe.password);

}
// Fonction permettant d'afficher les informations des employes d'un tableau :
void affiche_employe(struct Employe tab[], int position)
{
int i;
for(i=0; i < position; i++)
afficher_employe(tab[i]);
}


// Fonction permettant de modifier les informations d'un client du tableau :
void modifie_employe(struct Employe tab[], int position)
{
char nom[30];
int trouve=0;
int i=0;

//  Modifier le mot de passe d'un employé
fflush(stdin);
printf("Entrez le nom d'utilisateur: ");
fgets(nom, 30, stdin);

// Recherche du client dans le tableau :
while(trouve == 0 && i < position)
{
if(strcmp(tab[i].nom_utilisateur, nom) == 0)
{
            fflush(stdin);
            printf("Cet employe existe ! Saisissez le nouveau mot de passe...");
            scanf("%d",&tab[i].password);
trouve=1;
}
i++;
}
if(trouve == 0)
printf("Employe inconnu\n");
}


// Supprimer un employé du tableau
// La fonction retourne 1 si la suppression a été faite, et 0 sinon.
int supprimer(struct Employe tab[], int position)
{
char nom[30];
int trouve=0;
int i=0;
int j;
fflush(stdin);
printf("Entrez le nom d'utilisateur : ");
fgets(nom, 25, stdin);
while(trouve == 0 && i < position)
{
if(strcmp(tab[i].nom_utilisateur, nom))
{
trouve=1;
// Supprimer le contenu de la case en décalant:
for(j=i+1; j < position; j++)
{
strcpy(tab[j-1].nom_utilisateur, tab[j].nom_utilisateur);
tab[j-1].password = tab[j].password;
}
}
i++;
}
    if(trouve == 0)
    printf("Employe inconnu\n");

    else
    printf("Employe supprime\n");
    return trouve;
}


// Lecture du fichier eleves.dat et écriture dans le tableau
int lire(struct Employe tab[])
{
int i=0;
FILE *fichier=fopen("employes.dat", "r");
while(fread(&tab[i], sizeof(struct Employe), 1, fichier) && !feof(fichier))
i++;
return i;
}





// Fonction permettant de vérfier que l'employé existe dans le tableau :
int connexion(struct Employe tab[], int position)
{
struct Employe tableau[taille];
char nom[30];
int trouve=0,indice=0, choix2, resultat, tape = 0;
int i=0;

// Demande à l'employé son nom d'utilisateur :
fflush(stdin);
printf("Entrez le nom d'utilisateur: ");
fgets(nom, 30, stdin);

// Recherche de l'employé dans le tableau :
while(trouve == 0 && i < position)
    {
    if(strcmp(tab[i].nom_utilisateur, nom) == 0)
        {
            printf("Vous etes maintenant connecte ! Que souhaitez vous faire ?\n\n");
            trouve=1;
            printf("1. Ajouter et supprimer des vehicules\n");
            printf("2. Modifier les infos d un client\n");
            printf("3. Supprimer un client du fichier\n");
            printf("4. Consulter des factures \n");
            printf("5. Gerer des reclamations\n");
            printf("0. Retour\n");

        scanf("%d", &choix2);
        switch(choix2) // Traitement des choix possibles :
            {
             case 1 : printf("Voici la liste des vehicules en stock\n");
                      affiche_vehicules(tableau, indice);
                      printf("Tapez (1) pour continuer\n");
                      scanf("%d",&tape);
                      if (tape == 1)
                      {
                          modifie();
                      }
                      break;

            case 2 : printf("Voici la liste des clients\n");
                     afficher_client(tableau, indice);
                     printf("Tapez (1) pour continuer\n");
                     scanf("%d",&tape);
                     if(tape == 1)
                     {
                         modifie_client(tableau, indice);
                     }
                     break;

            case 3 : printf("Voici la liste des clients\n");
                     afficher_client(tableau, indice);
                     printf("Tapez (1) pour continuer\n");
                     scanf("%d", &tape);
                     if (tape == 1)
                     {
                         supprime(tableau, indice);
                     }
                     break;

            case 4 : printf("Tu affiches les factures !!!\n");
                     break;

            case 5 : printf("Tu affiches les reclamations faites par un client !!!\n");
                     break;

            case 0 : printf("Quitter");
                     break;

            default : printf("Choix invalide !\n");




            case 50 : // Menu admin
                    printf("Liste des clients :\n");
                    affiche_client(tableau, indice);
                    break;
            case 51 : // Pareil
                    modifie_client(tableau, indice);
                    break;
            case 52 : // Pareil
                    resultat = supprimer(tableau, indice);
                    if(resultat == 1)
                    indice--;
                    break;

            case 54 :
                    printf("Fin du programme, enregistrement dans le fichier\n");
                    enregistrer(tableau, indice);
                    break;

            }
        }
        i++;
    }
    if(trouve == 0)
    {
    printf("Employe inconnu\n");
    int connexion_reussie = 2;
    return connexion_reussie;
    }
}


void menu_employe()
{
struct Employe tableau[taille];
int indice=0;
int choix1;
indice = lire(tableau);
    do // Affichage du menu :
    {
    printf("**************************************************\n");
    printf("* 1.Connectez vous !                             *\n");
    printf("* 2. Nouveau ? Creez votre compte employe !      *\n");
    printf("* 0. Retour menu princicpal                      *\n");
    printf("**************************************************\n\n");
    scanf("%d",&choix1);
    if (choix1 == 1)
        {
        connexion (tableau, indice);

        }


    if (choix1 == 2)
        {
        if(indice < taille-1)
            {
            ajouter(tableau, indice);
            indice++;
            }
             else
            printf("Impossible de creer un profil (espace dans le tableau insuffisant\n");

        }

    /*printf("3. Afficher la liste des clients\n");
    printf("4. Changer les infos d'un client\n");
    printf("5. Supprimer un client\n");
    printf("6. Enregistrer dans le fichier\n");*/

    }while(choix1 != 0);

}


