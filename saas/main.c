#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

typedef struct Joueur
{
    int id;
    char nom [MAX_SIZE];
    char prenom [MAX_SIZE];
    int numeroMaillot;
    char poste[MAX_SIZE];
    int age ;
    int buts ;
    char dateInscription [MAX_SIZE];
    char statut [MAX_SIZE];
} joueur;

//int idJ=0;
int Ajouterjoueur(joueur joueurs[],int counter)
{
    static int idJ = 0;
    printf("entrer le nom du joueur : ");
    fgets(joueurs[counter].nom,sizeof(joueurs[counter].nom),stdin);
    printf("entrer le prenom du joueur : ");
    fgets(joueurs[counter].prenom,sizeof(joueurs[counter].prenom),stdin);

    printf("entrer le numeroMaillot du joueur : ");
    scanf("%d",&joueurs[counter].numeroMaillot);
    getchar();

    printf("entrer le poste  du joueur : ");
    fgets(joueurs[counter].poste,sizeof(joueurs[counter].poste),stdin);
    printf("entrer l'age  du joueur : ");
    scanf("%d",&joueurs[counter].age);
    getchar();
    printf("entrer le nombre de buts marques par le joueur. : ");
    scanf("%d",&joueurs[counter].buts);
    getchar();


    joueurs[counter].id = ++idJ;
    return (counter+1);
}
void AffichierJoueur(joueur joueurs[],int counter){
    for(int i=0;i<counter;i++){
        printf("ID : %d - la nom du joueur : %s - le prenom : %s - numeroMaillot : %d - poste :%s - age : %d - le nombre de buts : %d\n",joueurs[i].id,joueurs[i].nom,joueurs[i].prenom,joueurs[i].numeroMaillot,joueurs[i].poste,joueurs[i].age,joueurs[i].buts);
    }
}
void TrierJoueurParNom(joueur joueurs[],int counter){
    //int index_i=0;
    joueur temp;

    for(int i=0;i<counter;i++){
        for(int j=i+1;j<counter;j++){
            if(strcmp(joueurs[i].nom,joueurs[j].nom)>0){
                //index_i=j
                temp=joueurs[i];
                joueurs[i]=joueurs[j];
                joueurs[j]=temp;
            }
        }
    }

}
int main()
{
    joueur joueurs [10];
    int choix;
    int counter=0;

    char choixContinuer;
    do
    {
        printf("\n ------------Menu Principal------------ \n");
        printf("1 - Ajouter un joueur :\n");
        printf("2 - Afficher la liste de tous les joueurs :\n");
        printf("3 - Modifier un joueur :\n");
        printf("4 - Supprimer un joueur :\n");
        printf("5 - Rechercher un joueur :\n");
        printf("6 - Statistiques : \n");

        scanf("%d",&choix);
        getchar();


        switch(choix)
        {
        case 1:
            //choix
            char choixAjoutJoueur;
            do
            {
                printf("\n ------------Menu D'ajout------------ \n");
                printf("a - Ajouter un nouveau joueur. \n");
                printf("b - Ajouter plusieurs joueurs.\n");
                scanf("%c",&choixAjoutJoueur);
                getchar();
                switch(choixAjoutJoueur)
                {
                case 'a':
                    counter=Ajouterjoueur(joueurs,counter);
                    printf("%d",counter);
                    break;
                case 'b':
                    int nombreJoueurs;
                    printf("Combien de joueurs vous voulez ajouter ? :");
                    scanf("%d",&nombreJoueurs);
                    getchar();
                    for(int i=0; i<nombreJoueurs; i++)
                    {
                        printf("entrer le joueur N°%d :\n",i+1);
                        counter=Ajouterjoueur(joueurs,counter);//pour modifier la valeur de lindex apres l'ajout (incrementation)
                    }
                    printf("%d",counter);

                    break;
                default:
                    printf("entrer un choix d'ajout valide.\n");
                    break;
                }
                printf("vous voulez continuer pour ajouter plus des joueurs ? y/n :");
                scanf("%c",&choixContinuer);
                getchar();
            }
            while(choixContinuer=='y');
            break;
        case 2:
            do
            {
                int choixAffiche;
                printf("------------Menu D'affichage------------ \n");
                printf("1 Trier les joueurs par ordre alphabétique (Nom).\n");
                printf("2 Trier les joueurs par âge.\n");
                printf("3 Afficher les joueurs par poste.\n");
                scanf("%d",&choixAffiche);
                getchar();

                switch(choixAffiche)
                {
                case 1:
                    TrierJoueurParNom(joueurs,counter);
                    AffichierJoueur(joueurs,counter);
                    break;
                case 2:
                    //TrierJoueurParAge();
                    break;
                case 3:
                    //TrierJoueurParPoste();
                    break;
                default:
                    printf("entrer un choix valide.");
                    break;
                }

                printf("vous voulez continuer pour afficher ? y/n :");
                scanf("%c",&choixContinuer);
                getchar();
            }
            while(choixContinuer=='y');


            //printf("voici la liste de tous les joueurs :\n");
            //for(int i=0; i<counter; i++)
            //{
            //  printf("ID : %d - la nom du joueur : %s - le prenom : %s - numeroMaillot : %d - poste :%s - age : %d - le nombre de buts : %d\n",joueurs[i].id,joueurs[i].nom,joueurs[i].prenom,joueurs[i].numeroMaillot,joueurs[i].poste,joueurs[i].age,joueurs[i].buts);
            //}

            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        default:
            printf("entrer un choix valide");
            break;
        }


        //le choix de continuer
        printf("vous voulez continuer ? y/n : ");
        scanf("%c",&choixContinuer);
        getchar();
    }
    while(choixContinuer == 'y');
    return 0;
}
