#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

_Bool checklogin(char* login,char* password){
    FILE* fichierlogin = NULL ;
    _Bool trouve = false;
    char* loginfound = malloc(40*sizeof(char));
    char* passwordfound = malloc(40*sizeof(char));
   // Adapation des informations reçues
    // On convertit le login et le mot de passe au format du fichier
    strcpy(passwordfound,login);
    strcat(passwordfound, ":");
    strcat(passwordfound,password);
    // On ouvre le fichier 
    fichierlogin = fopen("C:/Users/BassehostDroid/Documents/Projets/Projte LC Mr Fall/data/login.txt", "r");
    if (fichierlogin == NULL) {
        // On arrete le programme car il y a erreur d'ouverture
        printf("Erreur Ouverture");
        return false ;
    }
    while (!feof(fichierlogin) && trouve == false) {
        // On parcourt chaque ligne
        fscanf(fichierlogin,"%s\n",loginfound);
        // On compare chaque ligne a la combinaison entree
        if(strcmp(loginfound, passwordfound)==0) trouve = true;
    }
    // On ferme le fichier et on libere les pointeurs
    fclose(fichierlogin);
    free(loginfound);
    free(passwordfound);
    // retourne vrai si combinaison trouvée sinon faux
    return trouve;
}



int afficheMenu(){
    int* choice = malloc(sizeof(int));
    do {
        *choice=0;
        printf("1.Ajouter Membre\n");
        printf("2.Supprimer Membre\n");
        printf("3.Modifier Membre\n");
        printf("4.Chercher Membre\n");
        printf("5.Deconnexion\n");
        scanf("%d",choice);
    } while (*choice<=0 || *choice>7);
    
    return *choice;
}
