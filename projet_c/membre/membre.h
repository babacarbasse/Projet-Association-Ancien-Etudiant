#include "membre.c"

formation creerFormationLC (char * code, char * intitule, char * annee);
membre creerListeMembreLC();
membre insererClasseLC(membre m, formation f);
membre creerMembreLC (char * numero, char * nom, char * prenom, char * adresse);
membre insererMembreLC(membre l, membre m);
membre rechercherMembreLC(membre mb, char * numero);
membre supprimerMembreLC(membre mb, char *numero);
membre modifierMembreLC(membre mb, char *numero);
void afficherMembre(membre m);
void saveListe(membre m);
membre deserialize(char * chaine);
membre getDataFromFile();
void afficherListe(membre l);
void afficherFormation(membre l);
void afficherFormationbis(membre l);

