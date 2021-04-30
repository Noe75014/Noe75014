#ifndef MENU_ADMIN
#define MENU_ADMIN

struct Client
{
    char nom [30];
    char prenom [30];
    int age;
    char num_de_tel [30];
    char mail [30];
    char sexe [30];
    int mdp;
    char nom_utilisateur [30];
} ;

struct Employe
{
    char nom_utilisateur [30];
    int password;
};


struct Vehicule
{
    char modele [30];
    int nb_places;
    char couleur [30];
    char immatriculation [10];


};

#endif

