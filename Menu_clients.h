#ifndef MENU_ADMIN
#define MENU_ADMIN


struct Client;
void Menu_clients ();

struct Client
{
    char nom [30];
    char prenom [30];
    int age;
    int num_de_tel;
    char mail [30];
    char sexe [30];
    int mdp;
    char nom_utilisateur [30];
} ;

#endif
