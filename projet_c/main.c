#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "myconio.h"
#include <stdbool.h>
#include "membre/membre.h"
#include "authentification/login.h"
#include "affichageEcran/affichageEcran.h"

int main()
{
    membre l,l1,m1,m;
    formation f;
    char numero[2];
    char nom[20];
    char prenom[20];
    char adresse[50];

    char code[10];
    char intitule[50];
    char annee[10];

    char numModif[2];

    l = creerListeMembreLC();

    int nb,i;
    char chaine[10];

    _Bool reussie;
    int choix;
    system("mode con LINES=45 COLS=150");
    splash();
    int cas = 3;
    do {
        reussie = authentification();
        if(reussie == false){
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            textcolor(7);
            textbackground(4);
            Sleep(2000);
            printf("\t\t\t\t\t\t\t Authentification echouee\n");
            printf("\t\t\t\t\t\t\tLogin ou Mot de passe invalide\n");
            Sleep(1000);
            textcolor(7);
            textbackground(0);
        }
        cas--;
    }while(reussie == false && cas>0);

    if(cas == 0) {
        clrscr();
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        Sleep(2000);
        textcolor(7);
        textbackground(4);
        printf("\t\t\t\t\t Vous avez atteint le nombre maximum d'essais.\n");
        printf("\t\t\t\t\t\t Veuillez reesayer plutard!");
        textcolor(7);
        textbackground(0);
        Sleep(2000);
        system("cls");
    }

    if(reussie == true) {
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        textcolor(7);
        textbackground(2);
        printf("\t\t\t\t\t\t\tAuthentification reussie\n");
        l = getDataFromFile();
        Sleep(1000);
        textcolor(7);
        textbackground(0);
        clrscr();

        do {
            choix = menu();
            switch(choix) {
                case 1:
                        printf("\n");
                        printf("\n");
                        textcolor(1);
                        textbackground(1);
                        printf("\t\t\t\t--------------------------------------------------------------------------\n");
                        textcolor(7);
                        printf("\t\t\t\t\t\t\t    Inscription de membre    \n");
                        textcolor(1);
                        printf("\t\t\t\t--------------------------------------------------------------------------\n");
                        textcolor(7);
                        textbackground(0);
                        printf("\n");
                        printf("\n");
                        membre check = NULL;
                        do {
                            printf("\t\t\t\t\t\t Saisir numero: ");
                            scanf("%s",numero);
                            check = rechercherMembreLC(l,numero);
                            if(check != NULL)
                                printf("\t\t\t\t\t\t Ce numero est deja utilise.\n");
                            printf("\n");

                        } while(check != NULL);
                        printf("\t\t\t\t\t\t Saisir nom: ");
                        scanf("%s",nom);
                        printf("\n");
                        printf("\t\t\t\t\t\t Saisir prenom: ");
                        scanf("%s",prenom);
                        printf("\n");
                        printf("\t\t\t\t\t\t Saisir adresse: ");
                        scanf("%s",adresse);
                        printf("\n");

                        m = creerMembreLC(numero,nom,prenom,adresse);

                        printf("\t\t\t\t\t\t Entrer le nombre d'annee passee a l ESP : ");
                        scanf("%d", &nb);
                        printf("\n");
                        for(i=0;i<nb;i++) {
                            printf("\t\t\t\t\t\t Informations de la formation de l'annee %d \n",i+1);
                            printf("\t\t\t\t\t\t Saisir code: ");
                            scanf("%s",code);
                            printf("\n");
                            printf("\t\t\t\t\t\t Saisir intitule: ");
                            scanf("%s",intitule);
                            printf("\n");
                            printf("\t\t\t\t\t\t Saisir annee: ");
                            scanf("%s",annee);
                            printf("\n");
                            f = creerFormationLC(code, intitule, annee);
                            printf("%s %s %s \n", f->code,f->intitule,f->annee);
                            m = insererClasseLC(m, f);

                        }
                        textcolor(7);
                        textbackground(3);
                        int c;
                        printf("\t\t\t\t\t\t 1 Pour valider - Autre pour annuler :");
                        scanf("%d",&c);
                        textcolor(7);
                        textbackground(0);
                        if (c == 1){
                            l = insererMembreLC(l,m);

                        }
                        printf("\n");
                        clrscr();
                        break;
                    case 2:

                        printf("\n");
                        printf("\n");
                        textcolor(1);
                        textbackground(1);
                        printf("\t\t\t\t--------------------------------------------------------------------------\n");
                        textcolor(7);
                        printf("\t\t\t\t\t\t\t    Modification de membre    \n");
                        textcolor(1);
                        printf("\t\t\t\t--------------------------------------------------------------------------\n");
                        textcolor(7);
                        textbackground(0);
                        printf("\n");
                        printf("\n");
                        textcolor(7);
					    textbackground(4);
                        printf("\t\t\t\t\t\t Entrer le numero a modifier: ");
                        textcolor(7);
					    textbackground(0);
                        scanf("%s", numModif);
                        printf("\n");
                        printf("\n");
                        l = modifierMembreLC(l, numModif);
                        printf("\n");
                        printf("\n");
                        textcolor(7);
                        textbackground(2);
                        printf("\t\t\t\t\t\tContinuer");
                        textcolor(7);
                        textbackground(0);
                        if(getch()) {
                            clrscr();
                        }
                        break;
                    case 3:

                        printf("\n");
                        printf("\n");
                        textcolor(1);
                        textbackground(1);
                        printf("\t\t\t\t--------------------------------------------------------------------------\n");
                        textcolor(7);
                        printf("\t\t\t\t\t\t\t    Suppression de membre    \n");
                        textcolor(1);
                        printf("\t\t\t\t--------------------------------------------------------------------------\n");
                        textcolor(7);
                        textbackground(0);
                        printf("\n");
                        printf("\n");
                        textcolor(7);
					    textbackground(4);
                        printf("\t\t\t\t\t\t Entrer le numero a supprimer: ");
                        textcolor(7);
					    textbackground(0);
                        scanf("%s", numModif);
                        printf("\n");
                        printf("\n");
                        textcolor(7);
					    textbackground(3);
                        printf("\t\t\t\t\t Voulez-vous vraiment supprimer ce membre ? (o ou n) : ");
                        textcolor(7);
					    textbackground(0);
                        getchar();
                        if ('o'==getchar()) {
                            l = supprimerMembreLC(l, numModif);
                        }
                        clrscr();
                        break;
                    case 4:
                        afficherListe(l);
                        printf("\n");
                        printf("\n");
                        textcolor(7);
                        textbackground(2);
                        printf("\t\t\t\t\t\tContinuer");
                        textcolor(7);
                        textbackground(0);
                        if(getch()) {
                            clrscr();
                        }
                        break;
                    case 5:
                        printf("\n");
                        printf("\n");
                        textcolor(1);
                        textbackground(1);
                        printf("\t\t\t\t--------------------------------------------------------------------------\n");
                        textcolor(7);
                        printf("\t\t\t\t\t\t\t    Recherche de membre    \n");
                        textcolor(1);
                        printf("\t\t\t\t--------------------------------------------------------------------------\n");
                        textcolor(7);
                        textbackground(0);
                        printf("\n");
                        printf("\n");

                        printf("\t\t\t\t\t\t Entrer le numero du membre a recherche: ");
                        scanf("%s", numModif);
                        l1 = rechercherMembreLC(l,numModif);
                        afficherMembre(l1);
                        printf("\n");
                        printf("\n");
                        textcolor(7);
                        textbackground(2);
                        printf("\t\t\t\t\t\tContinuer");
                        textcolor(7);
                        textbackground(0);
                        if(getch()) {
                            clrscr();
                        }
                        break;
                    case 6:
                        deconnexion();
                        saveListe(l);

                    default :
                        break;
            }
        }while(choix != 6);


    }

   return 0;
}
