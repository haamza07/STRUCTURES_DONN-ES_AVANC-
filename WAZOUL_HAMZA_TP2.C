#include <stdio.h>
#include <string.h>
#define TAILLE_NOM 30
#define TAILLE_CNE 10
#define MAX_ETUDIANTS 20

struct Etudiant {
char nom[TAILLE_NOM];
char prenom[TAILLE_NOM];
char cne[TAILLE_CNE];
float moyenne;
};

void saisirPromo(struct Etudiant promo[],int *nb){
    int i;
    do{
            printf("donner le nombre d'etudiant a saisir:");
            scanf("%d",nb);

    }while(*nb<=0 || *nb > MAX_ETUDIANTS);

    for(i=0 ; i<*nb ; i++){

        printf("\nLes information de l'etudiant numero %d\n",i+1);

        printf("\nDonner le nom de l'etudiant  : ");
        scanf("%s", promo[i].nom);

        printf("Donner le prenom de l'etudiant: ");
        scanf("%s", promo[i].prenom);

        printf("Donner le cne de l'etudiant: ");
        scanf("%s", promo[i].cne);

        printf("Donner la moyenne  de l'etudiant: ");
        scanf("%f", &promo[i].moyenne);

    }

}


void afficherPromo(struct Etudiant promo[], int nb) {
int i;

for (i = 0; i < nb; i++) {
printf("%d. %s %s (%s) - Moyenne : %.2f\n",i, promo[i].nom, promo[i].prenom,promo[i].cne, promo[i].moyenne);
}
}


int insererEtudiant(struct Etudiant promo[], int *nb, int position,struct Etudiant nouveau) {
int i;
   if (*nb >= MAX_ETUDIANTS) {
        return 0;
    }

    if (position < 0 || position > *nb) {
    return 0;
}

    for (i = *nb; i > position; i--) {

        promo[i] = promo[i - 1];

    }
    promo[position]=nouveau;
    (*nb)++;
    return 1;
}


int supprimerEtudiant(struct Etudiant promo[], int *nb, int position) {
int i;
   if (position < 0 || position >= *nb) {
        return 0;
    }

   for (i = position; i < *nb - 1; i++) {
   promo[i] = promo[i + 1];
  }

  (*nb)--;
  return 1;
}

int chercherEtudiant(struct Etudiant promo[], int *nb, char cne_chercher[]){
    int i;
    for ( i = 0; i < *nb; i++){

        if(strcmp(promo[i].cne,cne_chercher)== 0){
         return i;
        }
    }

    return -1;
}

int main(void) {
struct Etudiant promo[MAX_ETUDIANTS];
int nb_etudiants = 0, choix, position;
char CNE_cherche [10];
struct Etudiant nouveau;
   do {
      printf("\n1.Afficher 2.Inserer 3.Supprimer 4.chercher_par_CNE 5.Quitter\nChoix : ");
      scanf("%d", &choix);
      switch (choix)
      {
      case 1:
        afficherPromo(promo,nb_etudiants);
        break;
      case 2:

        printf("\nLes information de l'etudiant a inserer \n");

        printf("\nDonner le nom de l'etudiant  : ");
        scanf("%s", nouveau.nom);

        printf("Donner le prenom de l'etudiant: ");
        scanf("%s", nouveau.prenom);

        printf("Donner le cne de l'etudiant: ");
        scanf("%s", nouveau.cne);

        printf("Donner la moyenne  de l'etudiant: ");
        scanf("%f", &nouveau.moyenne);

         printf("Donner la position souhaite a  l'etudiant: ");
         scanf("%d", &position);

         if (insererEtudiant(promo, &nb_etudiants, position, nouveau)) {
           printf("Insertion reussie.\n");
         } else {
              printf("Insertion impossible.\n");
         }
        break;
       case 3:
        printf("Donner la position de l'etudiant a supprimer:");
        scanf("%d",&position);
       if (supprimerEtudiant(promo, &nb_etudiants, position)) {
           printf("Suppression reussie.\n");
        } else {
           printf("Suppression impossible : position invalide.\n");
        } 

        break;
       case 4:
        printf("Donner le CNE de l'etudiant a chercher: ");
        scanf("%s" , CNE_cherche);
        position=chercherEtudiant(promo,&nb_etudiants,CNE_cherche);
        if (position != -1)
        {
            printf("Les information de l'etudiant a chercher sont :\n");
            printf("%d. %s %s (%s) - Moyenne : %.2f\n",position, promo[position].nom, promo[position].prenom,promo[position].cne, promo[position].moyenne);
        }else{

            printf("Etudiant non trouver ou n'existe pas !");
        }
        break;
        case 5:
          printf("Fin du programme");
          break;




      default:
      printf("Choix invalide !");
        break;
      }



    } while (choix != 5);

    return 0;
}








