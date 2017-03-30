#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <stdbool.h>
#include "../myconio.h"



void deconnexion() {
    clrscr();
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t\t\t\t\tAu revoir!!!!!");
    Sleep(1000);
    system("cls");
}
int verifier(char *chaine){
    int i;
    for (i=0; i<strlen(chaine); i++) {
        if (chaine[i] > 57 || chaine[i] < 48) {
            return 0;
        }
    }
    return 1;
}

void barreDeProgression(){
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    int i,j;
    textcolor(1);
    printf("\t\t\t\t\t\t\t\t   Chargement en cours...   \n\n");
    printf("\t\t\t");
    for(i=0;i<100;i++) {
        textcolor(1);
        textbackground(1);
        printf("=");
        Sleep(5);
        for(j=1;j<150;j++) {
            printf("-\b");
        }
    }
    Sleep(2000);
    textbackground(0);
    printf("\n\n\n");
}

void splash(){
    clrscr();
    printf("\n\n\n");
    textcolor(4);
    printf("\t\tEcole Superieure Polytechnique (ESP) \t\t\t\t\t\t\t\t\t 2017/2018");
    printf("\n\n\n\n\n\n\n");
    textcolor(2);
    printf("\t\t\t         '''                       '''             ''''''''''''''''    ''''''''''''''''   \n");
    Sleep(200);
    textcolor(2);
    printf("\t\t\t        '''''                     '''''            ''''''''''''''''    ''''''''''''''''   \n");
    Sleep(200);
    textcolor(2);
    printf("\t\t\t       ''''''''                  ''''''''          ''''                ''''  \n");
    Sleep(200);
    textcolor(2);
    printf("\t\t\t      ''''   '''                ''''   '''         ''''                ''''        \n");
    Sleep(200);
    textcolor(3);
    printf("\t\t\t     ''''     '''              ''''     '''        ''''''''''''''''    ''''''''''''''''           \n");
    Sleep(200);
    textcolor(3);
    printf("\t\t\t    ''''''''''''''            ''''''''''''''       ''''''''''''''''    '''''''''''''''' \n");
    Sleep(200);
    textcolor(3);
    printf("\t\t\t   ''''''''''''''''          ''''''''''''''''      ''''                ''''\n");
    Sleep(200);
    textcolor(3);
    printf("\t\t\t  ''''          ''''        ''''          ''''     ''''                ''''   \n");
    Sleep(200);
    textcolor(4);
    printf("\t\t\t ''''            '''''     ''''            '''''   ''''''''''''''''    ''''''''''''''''  \n");
    Sleep(200);
    textcolor(4);
    printf("\t\t\t'''''             '''''   '''''             '''''  ''''''''''''''''    ''''''''''''''''    \n\n");
    textcolor(10);
    printf("\t\t\t\t\t\t\t ASSOCIATION DES ANCIENS ETUDIANTS DE L ESP\n");
    printf("\n\n\n");
    textcolor(4);
    textbackground(8);
    printf("\t\t\t\t\t\t\t\t\tPowered By:\n\n");
    printf("\t\t\t\t\t@Papa Ousmane NDIAYE - @Babacar NIANG - @Mame Astou GASSAMA - @Pape Semou DIOUF");
    textbackground(0);
    barreDeProgression();
}

_Bool authentification() {
    clrscr();
    char login[40];
    char str[40],c=' ';
    char reussie[10];


    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");


    textcolor(2);
    textbackground(7);
    printf("\t\t\t\t\t\t\t\t CONNEXION \n");

    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");

    textcolor(3);
    printf("\t\t\t\t\t\t Veuillez entrer votre login et mot de passe! \n");
    printf("\n");
    printf("\n");
    printf("\n");
    textbackground(0);
    textcolor(4);
    printf("\t\t\t\t\t\t\t Login : ");
    textbackground(7);
    scanf("%s", login);
    textbackground(0);
     printf("\n");
    printf("\t\t\t\t\t\t\t Mot de passe : ");
    int i=0;
    while (i<6){
        textbackground(7);
        textcolor(8);
        str[i]=getch();
        if(c==13) break;
        else printf("*");
        i++;
    }
    str[i]='\0';
    i=0;

    textbackground(0);

    return checklogin(login, str);
}

int entete() {
    char a[10];
    int chiffre;
    do{
        printf("\n");
        printf("\n");
        textcolor(1);
        textbackground(1);
        printf("------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        Sleep(500);
        textcolor(7);
        textbackground(4);
        printf("\n");
        printf("\t\t\t\t\t\t\t\tMENU PRINCIPAL\n");
        Sleep(500);
        printf("\n");
        textcolor(1);
        textbackground(1);
        printf("------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        Sleep(500);
        textcolor(7);
        textbackground(0);
        textcolor(7);
        textbackground(1);
        printf("1-Inscription de membres    ");
        printf("2-modification de membres    ");
        printf("3-Suppression de membres    ");
        printf("4-Affichage des membres    ");
        printf("5-Recherche de membre    ");
        printf("6-Deconnexion\n");
        textcolor(1);
        printf("------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        textcolor(7);
        textbackground(0);
        printf("\n");
        printf("\n");
        Sleep(500);
        textcolor(7);
        textbackground(4);
        printf("\t\t\t\t\t\t\t\tQue voulez-vous faire: ");
        textcolor(7);
        textbackground(0);
        scanf("%10s",a);
        if (!verifier(a)) {
            printf("\n");
            printf("\n");
            textcolor(7);
            textbackground(5);
            printf("\t\t\t\t\t\t\t Veuillez entrer un caractere valide!");
            textcolor(7);
            textbackground(0);
            Sleep(2000);
            clrscr();
        }
    }while(!verifier(a));

    chiffre = atoi(a);
}

int menu(){
    char a[10];
    int choix,nbre;
    do {
        choix = entete();
    } while (choix<1 || choix>6);
    //choix = atoi(a);
    return choix;
}
