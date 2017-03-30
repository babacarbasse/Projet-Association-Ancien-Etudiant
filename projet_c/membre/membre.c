#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../myconio.h"


typedef struct formation
{
	char * code;
	char * intitule;
	char * annee;
	struct formation * suiv;
} * formation;

typedef struct membre
{
	char *numero;
	char *nom;
	char *prenom;
	char *adresse;
	int nombreClasse;
	formation classe;
	struct membre * suiv;
} * membre;


 //cette fonction nous permet de creer une liste vide des membres
membre creerListeMembreLC(){
	membre l = (membre)malloc(sizeof(struct membre));
	l = NULL;
	return l;
}

//insertion d'une classe de formation pour un mebmre
membre insererClasseLC(membre m, formation f){
    if(m->classe!=NULL)
	{
		formation tete = m->classe;
		while(tete->suiv != NULL)
			tete = tete->suiv;
		tete->suiv = f;
	}
	else
	{
		m->classe=f;
	}
	return m;
}

//creer une nouvelle formation
formation creerFormationLC (char * code, char * intitule, char * annee){
	formation f =(formation)malloc(sizeof(struct formation));

	f->code = (char *)malloc(sizeof(char)*50);
	f->intitule = (char *)malloc(sizeof(char)*50);
	f->annee = (char *)malloc(sizeof(char)*50);
	strcpy(f->code,code);
	strcpy(f->intitule,intitule);
	strcpy(f->annee,annee);
	f->suiv = NULL;
	return f;
}

//creer un nouveau membre
membre creerMembreLC (char * numero, char * nom, char * prenom, char * adresse){
	membre m = (membre)malloc(sizeof(struct membre));

	m->nom = (char *) malloc(sizeof(char)*50);
    m->prenom = (char *) malloc(sizeof(char)*50);
    m->adresse = (char *) malloc(sizeof(char)*50);
    m->numero = (char *) malloc(sizeof(char)*50);
	strcpy(m->numero,numero);
	strcpy(m->nom,nom);
	strcpy(m->prenom,prenom);
	strcpy(m->adresse,adresse);
	m->nombreClasse = 0;
	m->classe=NULL;
	m->suiv=NULL;
	return m;
}

//inserer un membre dans la liste
membre insererMembreLC(membre l, membre m){
	if(l!=NULL)
	{
		membre tete = l;
		while(tete->suiv != NULL)
			tete = tete->suiv;
		tete->suiv = m;
        m->suiv = NULL;
	}
	else
	{
		l=m;
	}
	return l;
}

//rechercher membre
membre rechercherMembreLC(membre mb, char *numero){
	struct membre * m = mb;
	struct formation * f = mb->classe;
	m->classe = f;
	if(m!=NULL)
	{
		while(m!=NULL)
		{
			if(strcmp(m->numero,numero)==0)
				{
					return m;
				}

			m=m->suiv;
		}
	}
	return NULL;
}

//modifier membre
membre modifierMembreLC(membre mb, char *numero){
	struct membre *m = mb;
	if(m!=NULL)
	{
		while(m!=NULL)
		{
			if(strcmp(m->numero,numero)==0)
				{
					int nb;
					char chaine[10];
					do
					{
					    textcolor(7);
					    textbackground(5);
						printf("\t\t\t\t\t\t Choisir le champ de modification\n");
						printf("\t\t\t\t\t\t 1 - Nom\n");
						printf("\t\t\t\t\t\t 2 - Prenom\n");
						printf("\t\t\t\t\t\t 3 - Adresse\n");
						printf("\t\t\t\t\t\t 4 - Annuler\n");
						printf("\n");
						textcolor(7);
					    textbackground(4);
					    printf("\t\t\t\t\t\t Le champ a modifier: ");
					    textcolor(7);
					    textbackground(0);
						scanf("%d",&nb);
						printf("\n");
					}
					while(nb<=0 || nb >4);
					switch (nb) {
						case 1: printf("\t\t\t\t\t\t Entrer le nouveau nom: ");
								scanf("%s",m->nom);
								return mb;
								break;
						case 2: printf("\t\t\t\t\t\t Entrer le nouveau prenom: ");
								scanf("%s",m->prenom);
								return mb;
								break;
						case 3: printf("\t\t\t\t\t\t Entrer le nouveau adresse: ");
								scanf("%s",m->adresse);
								return mb;
								break;
						case 4: return mb;
								break;
						default : printf("\t\t\t\t\t\t Pas de modification\n");
						break;

					}
					return m;
				}
			m=m->suiv;
		}
	}
	return NULL;
}

//supprimer membre
membre supprimerMembreLC(membre liste, char *numero){
	/* Liste vide, il n'y a plus rien à supprimer */
	if(liste == NULL)
		return NULL;

	/* Si l'élément en cours de traitement doit être supprimé */
	if(liste->numero == numero)
	{
		/* On le supprime en prenant soin de mémoriser
        l'adresse de l'élément suivant */
		struct membre * tmp = liste->suiv;
		free(liste);
		/* L'élément ayant été supprimé, la liste commencera à l'élément suivant
        pointant sur une liste qui ne contient plus aucun élément ayant la valeur recherchée */
		tmp = supprimerMembreLC(tmp, numero);
		return tmp;
	}
	else
	{
		/* Si l'élement en cours de traitement ne doit pas être supprimé,
        alors la liste finale commencera par cet élément et suivra une liste ne contenant
        plus d'élément ayant la valeur recherchée */
		liste->suiv = supprimerMembreLC(liste->suiv, numero);
		return liste;
	}
}

void afficherMembre(membre m){
	if(m!=NULL){
		printf("\t\t\t\t\t\t Numero: %s\n", m->numero);
		printf("\t\t\t\t\t\t Nom: %s\n", m->nom);
		printf("\t\t\t\t\t\t Prenom: %s\n", m->prenom);
		printf("\t\t\t\t\t\t Adresse: %s\n", m->adresse);
        afficherFormationbis(m);

	} else {
		printf("\t\t\t\t\t\t Ce membre n'existe pas!\n");
	}
}

void afficherFormationbis(membre l){
    int i;
	struct formation * f = l->classe;
    while(f != NULL){
        printf("\t\t\t\t\t\tCode: %s\n", f->code);
        printf("\t\t\t\t\t\tIntitule: %s\n", f->intitule);
        printf("\t\t\t\t\t\tAnnee: %s\n", f->annee);
        f = f->suiv;
    }
}

void afficherFormation(membre l){
    int i;
	struct formation * f = l->classe;
    while(f != NULL){
        printf("\t\t\t\t\t\tCode: %s ", f->code);
        printf("\t\t\t\t\t\tIntitule: %s\n", f->intitule);
        printf("\t\t\t\t\t\tAnnee: %s\n", f->annee);
		f = f->suiv;
    }
}

void afficherListe(membre m){
    int i;
	struct membre * l = m;
	if(l != NULL){
        while(l != NULL){
            printf("\t\t\t\t\t\tNumero: %s\n", l->numero);
            printf("\t\t\t\t\t\tNom: %s\n", l->nom);
            printf("\t\t\t\t\t\tPrenom: %s\n", l->prenom);
            printf("\t\t\t\t\t\tAdresse: %s\n", l->adresse);
            afficherFormation(l);
            l = l->suiv;
        }
   }
	else
	  printf("\t\t\t\t\t\tCette liste est vide!\n");
}

char * serialize(membre mb){

	char chaine [10000];

	strcat(chaine,mb->numero);
	strcat(chaine,":");
	strcat(chaine,mb->nom);
	strcat(chaine,":");
	strcat(chaine,mb->prenom);
	strcat(chaine,":");
	strcat(chaine,mb->adresse);
	while(mb->classe != NULL){

		strcat(chaine,":");
		strcat(chaine,mb->classe->code);
		strcat(chaine,":");
		strcat(chaine,mb->classe->intitule);
		strcat(chaine,":");
		strcat(chaine,mb->classe->annee);

		mb->classe = mb->classe->suiv;
	}



	return chaine;
}

//save list
void saveListe(membre mb) {
	int j;
    FILE *fichier;

	fichier = fopen("C:/Users/BassehostDroid/Documents/Projets/Projte LC Mr Fall/data/membres.txt", "w+");
	if (fichier == NULL) {
		perror("Erreur d'ouverture du fichier");
		exit(EXIT_FAILURE);
	}
	membre tmp;
	tmp = mb;
	if (mb != NULL)
	{
		while(tmp != NULL){
			char *str2 = serialize(tmp);
			char *str = (char*)malloc(strlen(str2) + 1);
			strcpy(str,str2);
			if(str[0] != "\n:") {
				if (fichier != NULL )
				{
					fprintf(fichier, "%s \n", str);
				}else{
					printf("Erreur d'ouverture du fichier \n");
					exit(0);
				}
				for(j =0 ; j<strlen(str2); j++)
					str2[j] = NULL;
			}
			tmp = tmp->suiv;
		}
	}
	fclose(fichier);
}


membre deserialize(char * chaine){
    membre m = (membre)malloc(sizeof(struct membre));
    m->nom = (char *) malloc(sizeof(char)*50);
    m->prenom = (char *) malloc(sizeof(char)*50);
    m->adresse = (char *) malloc(sizeof(char)*50);
    m->numero = (char *) malloc(sizeof(char)*50);
    int i,k=0,j;
    char * tab[1000];
    char caractere[2];
    char str[1000];
    str[0] = NULL;
    caractere[1]='\0';
    int compte = 0;
    for (i = 0; i <= (strlen(chaine)); i++)
    {
        if (chaine[i] == ':') {
            compte ++;
            tab[k] = (char *) malloc(sizeof(str) +1);
            strcpy(tab[k],str);
            for(j =0 ; j<strlen(str); j++)
                str[j] = NULL;
            k++;
        } else {
            caractere[0] = chaine[i];
            strcat(str,caractere);
            caractere[0] = NULL;
            if(i == strlen(chaine)) {
                tab[k] = (char *) malloc(sizeof(str) +1);
                strcpy(tab[k],str);
            }
        }
    }
    strcpy(m->numero,tab[0]);
    strcpy(m->nom,tab[1]);
    strcpy(m->prenom,tab[2]);
    strcpy(m->adresse,tab[3]);
    j=4;
    while (j<k)
    {
        formation f = (formation)malloc(sizeof(struct formation));
        f= creerFormationLC(tab[j],tab[j+1],tab[j+2]);
        m=insererClasseLC(m,f);
        j=j+3;
    }
    m->suiv = NULL;
    return m;
}
//get data from file
membre getDataFromFile() {
	membre liste = creerListeMembreLC();

	FILE *fichier;
    fichier = fopen("C:/Users/BassehostDroid/Documents/Projets/Projte LC Mr Fall/data/membres.txt", "r");
	if (fichier == NULL) {
		perror("Erreur d'ouverture du fichier");
		exit(EXIT_FAILURE);
	}

    while (!feof(fichier)){
		char chaine [100000] = "";
        fgets(chaine,sizeof (chaine),fichier);
        if (strlen(chaine) != 0) {
            membre  m = (membre) malloc(sizeof(struct membre));
            m = deserialize(chaine);
			if (m->numero[0] != ' ') {
				liste =  insererMembreLC(liste,m);
			}
        }
	}

	fclose(fichier);
    return liste;

}
