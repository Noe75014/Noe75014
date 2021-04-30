#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"
#define taille 100


//Fonction permettant d'ajouter un client au tableau de clients
void ajouter(struct Client tab[], int position)
{

                        fflush(stdin);
                        printf("Saisir nom et prenom\n");
                        fgets(tab[position].nom, 30, stdin);
                        fflush(stdin);
                        fgets(tab[position].prenom, 30, stdin);
                        printf("Saisir votre age :\t");
                        scanf("%d",&tab[position].age);
                        fflush(stdin);
                        printf("De quel genre etes vous ? -M ou -F");
                        fgets(tab[position].sexe, 30, stdin);
                        fflush(stdin);
                        printf("Chosis ton nom d'utilisateur");
                        fgets(tab[position].nom_utilisateur, 30, stdin);
                        fflush(stdin);
                        printf("Chosis ton mot de passe : ");
                        scanf("%d",&tab[position].mdp);
                        fflush(stdin);
                        printf("Mail et Numero de telephone svp\n");
                        fflush(stdin);
                        fgets(tab[position].mail, 30, stdin);
                        fflush(stdin);
                        fgets(tab[position].num_de_tel, 30, stdin);
                    }

//Ajoutes et enregistres le client dans un fichier client
void enregistre(struct Client tab [], int position)
{
    FILE *fichier;
    int i;
    fichier = fopen("clients.dat", "w");
    for(i=0; i<position; i++)
        fwrite(&tab[i], sizeof (struct Client), 1, fichier);
    fclose(fichier);
}

// Fonction permettant d'afficher les informations d'un client :
void afficher_client(struct Client client)
{
printf(" %s %s ", client.nom, client.prenom);
printf(" %d ", client.age);
printf(" %s ", client.sexe);
printf(" %s ", client.num_de_tel);
printf(" %s ", client.mail);
}
// Fonction permettant d'afficher les informations des clients d'un tableau :
void affiche_client(struct Client tab[], int position)
{
int i;
for(i=0; i < position; i++)
afficher_client(tab[i]);
}


// Fonction permettant de modifier les informations d'un client du tableau :
void modifie_client(struct Client tab[], int position)
{
char nom[30];
int trouve=0;
int i=0;

// Demander à l'utilisateur le nom d'utilisateur du client à modifier :
fflush(stdin);
printf("Entrez le nom d'utilisateur: ");
fgets(nom, 30, stdin);

// Recherche du client dans le tableau :
while(trouve == 0 && i < position)
{
if(strcmp(tab[i].nom_utilisateur, nom) == 0)
{
            printf("Ce client existe ! Saisissez toutes les nouvelles infos...");

            printf("Saisir nom et prenom\n");// Affectation des nouvelles infos
            fflush(stdin);
            fgets(tab[i].nom, 30, stdin);
            fflush(stdin);
            fgets(tab[i].prenom, 30, stdin);
            fflush(stdin);
            printf("Saisir votre age :");
            scanf("%d",&tab[i].age);
            printf("De quel genre etes vous ? -M ou -F");
            fflush(stdin);
            fgets(tab[i].sexe, 30, stdin);
            fflush(stdin);
            printf("Chosis ton nom d'utilisateur");
            fgets(tab[i].nom_utilisateur, 30, stdin);
            printf("Chosis ton mot de passe");
            scanf("%d",&tab[i].mdp);
            printf("Mail et Numero de telephone svp");
            fflush(stdin);
            fgets(tab[i].mail, 30, stdin);
            fflush(stdin);
            fgets(tab[i].num_de_tel,30, stdin);
trouve=1;
}
i++;
}
if(trouve == 0)
printf("Client inconnu\n");
}


// Supprimer un client du tableau
// La fonction retourne 1 si la suppression a été faite, et 0 sinon.
int supprime(struct Client tab[], int position)
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
strcpy(tab[j-1].nom, tab[j].nom);
strcpy(tab[j-1].prenom, tab[j].prenom);
strcpy(tab[j-1].nom_utilisateur, tab[j].nom_utilisateur);
strcpy(tab[j-1].sexe, tab[j].sexe);
strcpy(tab[j-1].mail, tab[j].mail);
strcpy(tab[j-1].num_de_tel, tab[j].num_de_tel);
tab[j-1].age = tab[j].age;
tab[j-1].mdp = tab[j].mdp;
}
}
i++;
}
if(trouve == 0)
printf("Client inconnu\n");

else
printf("Client supprime\n");
return trouve;
}


// Lecture du fichier employes.dat et écriture dans le tableau
int lire_employes(struct Client tab[])
{
int i=0;
FILE *fichier=fopen("employes.dat", "r");
while(fread(&tab[i], sizeof(struct Employe), 1, fichier) && !feof(fichier))
i++;
return i;
}





// Fonction permettant de vérfier que le client existe dans le tableau :
int connexion_(struct Employe tab[], int position)
{
struct Client tableau[taille];
int indice=0;
indice = lire(tableau);
int choix2;
char nom[30];
int trouve=0, resultat;
int i=0;

// Demande au client son nom d'utilisateur :
fflush(stdin);
printf("Entrez le nom d'utilisateur: ");
fgets(nom, 30, stdin);

// Recherche du client dans le tableau :
while(trouve == 0 && i < position)
    {
    if(strcmp(tab[i].nom_utilisateur, nom) == 0)
        {
            trouve=1;
            printf("Connexion reussie ! Que souhaitez vous faire ?\n\n");
            printf("1. Consulter les vehicules.\n");
            printf("2. Mes reservations\n");
            printf("3. Mes factures.\n");
            printf("4. Mes locations.\n");
            printf("5. Mes informations\n");
            printf("6. Mes commentaires.\n");
            printf("7. Faire une reclamation.\n");
            printf("0. Retour\n");

        scanf("%d", &choix2);
        switch(choix2) // Traitement des choix possibles :
            {
             case 0 : printf("Retour\n\n");
             break;

             default : printf("Choix invalide !\n");

             case 1 : printf("1. Consulter les vehicules.\n");
                      affiche_vehicules(tableau, indice);
                      break;

            case 2 : printf("2. Mes reservations\n");
                     break;
            case 3 : printf("3. Mes factures.\n");
                     break;
            case 4 : printf("4. Mes locations.\n");
                     break;
            case 5 : printf("5. Mes informations\n");
                     break;
            case 6 : printf("6. Mes commentaires.\n");
                     break;
            case 7 : printf("7. Faire une reclamation.\n");
                     donner_les_avis();
                     break;

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
                case 53 :
                enregistrer(tableau, indice);
                break;
                case 54 : // Je peux mettre ce cas dans le menu principal pour le cas = 0 (ça enregistre à la fermeture du programme)
                printf("Fin du programme, enregistrement dans le fichier\n");
                enregistrer(tableau, indice);
                break;

            }
        }
        i++;
    }
    if(trouve == 0)
    {
    printf("Client inconnu\n");
    int connexion_reussie = 2;
    return connexion_reussie;
    }
}


void menu_client()
{
struct Client tableau[taille];
int indice=0;
int choix1;
indice = lire(tableau);
    do // Affichage du menu :
    {
    printf("**********************************\n");
    printf("* 1.Connectez vous !             *\n");
    printf("* 2. Nouveau client ?            *\n");
    printf("* 3. Retour menu princicpal      *\n");
    printf("**********************************\n\n");
    scanf("%d",&choix1);
    if (choix1 == 1)
        {
        connexion_(tableau, indice);

        }

    if (choix1 == 2)
        {
        if(indice < taille-1)
            {
            ajouter(tableau, indice);
            indice++;
            }
             else
            printf("Impossible de creer un profil (espace dans le tableau insuffisant)\n");

        }


    /*printf("3. Afficher la liste des clients\n");
    printf("4. Changer les infos d'un client\n");
    printf("5. Supprimer un client\n");
    printf("6. Enregistrer dans le fichier\n");*/

    }while(choix1 != 3);

}


/*void facture ()//Fonction permettant de créer automatiquement une facture sous la demande d'un client
{
    int indice;
    struct Vehicule tab [];
    affiche_vehicules(tableau, indice);
    printf("Entrez l'immatriculation du vehicule pour la facture : ");


}*/





