#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100
/*typedef struct Joueur
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


int Ajouterjoueur(joueur joueurs[],int counter)
{
    static int idJoueur=10;

    printf("entrer le nom du joueur : ");
    fgets(joueurs[counter].nom,sizeof(joueurs[counter].nom),stdin);
    joueurs[counter].nom[strcspn(joueurs[counter].nom, "\n")] = '\0';//supprimer le retour a la ligne

    printf("entrer le prenom du joueur : ");
    fgets(joueurs[counter].prenom,sizeof(joueurs[counter].prenom),stdin);
    joueurs[counter].prenom[strcspn(joueurs[counter].prenom, "\n")] = '\0';//supprimer le retour a la ligne


    printf("entrer le numeroMaillot du joueur : ");
    scanf("%d",&joueurs[counter].numeroMaillot);
    getchar();

    printf("entrer le poste  du joueur : ");
    fgets(joueurs[counter].poste,sizeof(joueurs[counter].poste),stdin);
    joueurs[counter].poste[strcspn(joueurs[counter].poste, "\n")] = '\0';//supprimer le retour a la ligne

    printf("entrer l'age  du joueur : ");
    scanf("%d",&joueurs[counter].age);
    getchar();

    printf("entrer le nombre de buts marques par le joueur. : ");
    scanf("%d",&joueurs[counter].buts);
    getchar();
    //le status
    int choixStatus;
    do
    {

        printf("entrer le statut dun joueur : \n");
        printf("1 - titulaire\n");
        printf("2 - remplaçant\n");
        scanf("%d",&choixStatus);
        getchar();

        switch(choixStatus)
        {
        case 1:
            strcpy(joueurs[counter].statut,"titulaire");
            break;
        case 2:
            strcpy(joueurs[counter].statut,"remplaçant");
            break;
        default:
            printf("entrer un choix valide.\n");
        }
    }
    while(choixStatus != 1 && choixStatus !=2);

    joueurs[counter].id = ++idJoueur;

    //counter ++;
    //return counter;

    //joueurs[counter].id = ++idJoueur;

    return (counter+1);
}
void AffichierJoueur(joueur joueurs[],int counter)
{
    for(int i=0; i<counter; i++)
    {
        printf("Id : %d - la nom du joueur : %s - le prenom : %s - numeroMaillot : %d - poste :%s - age : %d - le nombre de buts : %d - le status : %s\n",joueurs[i].id,joueurs[i].nom,joueurs[i].prenom,joueurs[i].numeroMaillot,joueurs[i].poste,joueurs[i].age,joueurs[i].buts,joueurs[i].statut);
        //printf("%d",counter);
        if(joueurs[i].buts>20)
        {
            printf("---------------- félicitation ----------------\n");
            printf("Bravo %s %s \n",joueurs[i].prenom,joueurs[i].nom);
            printf("avec %d des buts, tues une star de l'equipe !\n",joueurs[i].buts);
            printf("----------------               ----------------\n");
        }
    }
}
void TrierJoueurParNom(joueur joueurs[],int counter)
{
    //int index_i=0;
    joueur temp;

    for(int i=0; i<counter; i++)
    {
        for(int j=i+1; j<counter; j++)
        {
            if(strcasecmp(joueurs[i].nom,joueurs[j].nom)>0)
            {
                //index_i=j
                temp=joueurs[i];
                joueurs[i]=joueurs[j];
                joueurs[j]=temp;
            }
        }
    }
    printf("voici les joueur trier par nom : \n");
    AffichierJoueur(joueurs,counter);
}
void TrierJoueurParAge(joueur joueurs[],int count)
{
    joueur temp;
    for(int i=0; i<count; i++)
    {
        for(int j=i+1; j<count; j++)
        {
            if(joueurs[i].age>joueurs[j].age)
            {
                temp=joueurs[i];
                joueurs[i]=joueurs[j];
                joueurs[j]=temp;
            }
        }
    }
    printf("voici les joueur trier par age : \n");
    AffichierJoueur(joueurs,count);
}
void TrierJoueurParPoste(joueur joueurs[],int counter)
{
    printf("les gardien sont : \n");

    for(int i=0; i<counter; i++)
    {
        if(strcasecmp(joueurs[i].poste,"gardien")==0)
        {
            printf("ID : %d - la nom du joueur : %s - le prenom : %s - numeroMaillot : %d - poste :%s - age : %d - le nombre de buts : %d\n",joueurs[i].id,joueurs[i].nom,joueurs[i].prenom,joueurs[i].numeroMaillot,joueurs[i].poste,joueurs[i].age,joueurs[i].buts);
        }
    }

    printf("les defenseur sont : \n");
    for(int i=0; i<counter; i++)
    {
        if(strcasecmp(joueurs[i].poste,"defenseur")==0)
        {
            printf("ID : %d - la nom du joueur : %s - le prenom : %s - numeroMaillot : %d - poste :%s - age : %d - le nombre de buts : %d\n",joueurs[i].id,joueurs[i].nom,joueurs[i].prenom,joueurs[i].numeroMaillot,joueurs[i].poste,joueurs[i].age,joueurs[i].buts);
        }
    }
    printf("les milieu sont : \n");
    for(int i=0; i<counter; i++)
    {
        if(strcasecmp(joueurs[i].poste,"milieu")==0)
        {
            printf("ID : %d - la nom du joueur : %s - le prenom : %s - numeroMaillot : %d - poste :%s - age : %d - le nombre de buts : %d\n",joueurs[i].id,joueurs[i].nom,joueurs[i].prenom,joueurs[i].numeroMaillot,joueurs[i].poste,joueurs[i].age,joueurs[i].buts);
        }
    }
    printf("les attaquant sont : \n");
    for(int i=0; i<counter; i++)
    {
        if(strcasecmp(joueurs[i].poste,"attaquant")==0)
        {
            printf("ID : %d - la nom du joueur : %s - le prenom : %s - numeroMaillot : %d - poste :%s - age : %d - le nombre de buts : %d\n",joueurs[i].id,joueurs[i].nom,joueurs[i].prenom,joueurs[i].numeroMaillot,joueurs[i].poste,joueurs[i].age,joueurs[i].buts);
        }
    }
}

int rechercheJoueurParId(joueur joueurs[],int counter,int id)
{
    for(int i=0; i<counter; i++)
    {
        if(joueurs[i].id==id)
        {
            return i;
            break;
        }
    }
    return -1;
}
int rechercheJoueurParNom(joueur joueurs[],int counter,char Nom[MAX_SIZE])
{
    for(int i=0; i<counter; i++)
    {
        if(strcasecmp(joueurs[i].nom,Nom)==0)
        {
            return i;
            break;
        }
    }
    return -1;
}
void AfficherRecherche(joueur joueurs[],int indice)
{

    printf("ID : %d - la nom du joueur : %s - le prenom : %s - numeroMaillot : %d - poste :%s - age : %d - le nombre de buts : %d\n",joueurs[indice].id,joueurs[indice].nom,joueurs[indice].prenom,joueurs[indice].numeroMaillot,joueurs[indice].poste,
           joueurs[indice].age,joueurs[indice].buts);

}
void ModifierPoste(int idJoueurModified,joueur joueurs[],int counter)
{
    int indice_joueur=rechercheJoueurParId(joueurs,counter,idJoueurModified);
    char nouvelPost [MAX_SIZE];
    if(indice_joueur!=-1)
    {
        printf("entrer le nouvelle post pour se joueur :\n");
        fgets(nouvelPost,sizeof(nouvelPost),stdin);
        nouvelPost[strcspn(nouvelPost, "\n")] = '\0';

        strcpy(joueurs[indice_joueur].poste,nouvelPost);
        printf("le  post modifier avce succes \n");
    }
    else
    {
        printf("le joueur n'exist pas.");
    }
}
void ModifierAge(int idJoueurModified,joueur joueurs[],int counter)
{
    int indice_joueur=rechercheJoueurParId(joueurs,counter,idJoueurModified);
    int nouvelAge;
    if(indice_joueur!=-1)
    {
        printf("entrer le nouvelle Age pour se joueur :\n");
        scanf("%d",&nouvelAge);
        getchar();

        joueurs[indice_joueur].age=nouvelAge;
        printf("l'age modifier avce succes \n");
    }
    else
    {
        printf("le joueur n'exist pas.");
    }
}

void ModifierNombreButs(int idJoueurModified,joueur joueurs[],int counter)
{
    int indice_joueur=rechercheJoueurParId(joueurs,counter,idJoueurModified);
    int nouvelNembreBut;
    if(indice_joueur!=-1)
    {
        printf("entrer le nouvelle nombre de buts pour se joueur :\n");
        scanf("%d",&nouvelNembreBut);
        getchar();

        joueurs[indice_joueur].buts=nouvelNembreBut;
        printf("le nombre de buts modifier avce succes \n");
    }
    else
    {
        printf("le joueur n'exist pas.");
    }
}
//la supprission
int SupprimerJoueur(joueur joueurs[],int counter,int idJoueur)
{
    int indice_joueur=rechercheJoueurParId(joueurs,counter,idJoueur);
    if(indice_joueur!=-1)
    {
        for(int i=indice_joueur; i<counter; i++)
        {
            joueurs[i]=joueurs[i+1];
        }
        counter--;
        printf("le nombre et supprimer avce succes \n");
    }
    else
    {
        printf("le joueur n'exist pas.");
    }
    return counter;
}
int AgeMoyenne(joueur joueurs[],int counter)
{
    int agemoyenne,Somme=0;
    for(int i=0; i<counter; i++)
    {
        Somme+=joueurs[i].age;
    }
    agemoyenne=Somme/counter;
    return agemoyenne;
}
void AfficherJoueursMarquePlusXBut(joueur joueurs[],int counter)
{

    joueur ButPlusX[counter];
    int nbJoueursTrouves = 0;
    int nbrBut;
    printf("entre le nombre des buts :");
    scanf("%d",&nbrBut);
    getchar();
    for(int i=0; i<counter; i++)
    {
        if(joueurs[i].buts>nbrBut)
        {
            ButPlusX[nbJoueursTrouves]=joueurs[i];
            nbJoueursTrouves++;
        }
    }
    printf("voici les joueur qui plus de %d buts \n.",nbrBut);
    for(int i=0; i<nbJoueursTrouves; i++)
    {
        printf("id : %d - la nom du joueur : %s - le prenom : %s - numeroMaillot : %d - poste :%s - age : %d - le nombre de buts : %d\n",ButPlusX[i].id,ButPlusX[i].nom,ButPlusX[i].prenom,ButPlusX[i].numeroMaillot,ButPlusX[i].poste,ButPlusX[i].age,ButPlusX[i].buts);

    }


}
void AfficherMeilleurButeur(joueur joueurs[],int count)
{
    int MaxBut;
    int indice;
    MaxBut=joueurs[0].buts;
    for(int i=0; i<count; i++)
    {
        if(joueurs[i].buts>MaxBut)
        {
            MaxBut=joueurs[i].buts;
            indice=i;
        }
    }
    printf("id : %d - la nom du joueur : %s - le prenom : %s - numeroMaillot : %d - poste :%s - age : %d - le nombre de buts : %d\n",joueurs[indice].id,joueurs[indice].nom,joueurs[indice].prenom,joueurs[indice].numeroMaillot,joueurs[indice].poste,joueurs[indice].age,joueurs[indice].buts);


}
void AfficherPlusJeunePlusAge(joueur joueurs[],int count)
{
    int MaxPlusAge=joueurs[0].age;
    int indicePlusAge=0;
    int indicePlusJeune=0;
    int MinPlusJeune=joueurs[0].age;
    for(int i=0; i<count; i++)
    {
        if(MaxPlusAge<joueurs[i].age)
        {
            MaxPlusAge=joueurs[i].age;
            indicePlusAge=i;
        }
        if(MinPlusJeune>joueurs[i].age)
        {
            MinPlusJeune=joueurs[i].age;
            indicePlusJeune=i;
        }
    }
    printf("le joueur le plus jeune est :\n");
    printf("id : %d - la nom du joueur : %s - le prenom : %s - numeroMaillot : %d - poste :%s - age : %d - le nombre de buts : %d\n",joueurs[indicePlusJeune].id,joueurs[indicePlusJeune].nom,joueurs[indicePlusJeune].prenom,joueurs[indicePlusJeune].numeroMaillot,
           joueurs[indicePlusJeune].poste,joueurs[indicePlusJeune].age,joueurs[indicePlusJeune].buts);

    printf("le joueur le plus Age est :\n");
    printf("id : %d - la nom du joueur : %s - le prenom : %s - numeroMaillot : %d - poste :%s - age : %d - le nombre de buts : %d\n",joueurs[indicePlusAge].id,joueurs[indicePlusAge].nom,joueurs[indicePlusAge].prenom,joueurs[indicePlusAge].numeroMaillot
           ,joueurs[indicePlusAge].poste,joueurs[indicePlusAge].age,joueurs[indicePlusAge].buts);

}
int main()
{
    joueur joueurs [MAX_SIZE]=
    {
        {1,  "zidane",    "Zinedine", 10, "Milieu",    38, 125, "2000-06-15", "Actif"},
        {2,  "Ronaldo",   "Cristiano", 7, "Attaquant", 36, 750, "2003-08-12", "Actif"},
        {3,  "messi",     "Lionel",   30, "Attaquant", 34, 700, "2004-07-05", "Actif"},
        {4,  "Neymar",    "Junior",   11, "Attaquant", 29, 350, "2010-05-20", "Actif"},
        {5,  "Mbappe",    "Kylian",    7, "Attaquant", 22, 150, "2017-11-01", "Actif"},
        {6,  "Hakimi",    "Achraf",    2, "Defenseur", 25,  40, "2018-09-14", "Actif"},
        {7,  "Kante",     "N'Golo",   13, "Milieu",    32,  30, "2016-07-03", "Actif"},
        {8,  "Modric",    "Luka",     10, "Milieu",    37,  90, "2008-08-15", "Actif"},
        {9,  "Benzema",   "Karim",     9, "Attaquant", 35, 450, "2009-07-01", "Retraité"},
        {10, "TerStegen", "Marc",      1, "Gardien",   31,   0, "2014-06-22", "Actif"},

    };
    int choix;
    int counter=10;

    //joueur joueurs [30];
    //int choix;
    //int counter=0;

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
                printf("1 - Trier les joueurs par ordre alphabetique (Nom).\n");
                printf("2 - Trier les joueurs par age.\n");
                printf("3 - Afficher les joueurs par poste.\n");
                scanf("%d",&choixAffiche);
                getchar();

                switch(choixAffiche)
                {
                case 1:
                    TrierJoueurParNom(joueurs,counter);
                    break;
                case 2:
                    TrierJoueurParAge(joueurs,counter);
                    break;
                case 3:
                    TrierJoueurParPoste(joueurs,counter);
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
            break;
        case 3:
            int choixModifierJoueur;

            do
            {
                printf("------------Menu De Modification------------ \n");
                printf("1 - Modifier le poste dun joueur.\n");
                printf("2 - Modifier lage dun joueur.\n");
                printf("3 - Modifier le nombre de buts marqués par un joueur.\n");
                scanf("%d",&choixModifierJoueur);
                getchar();
                int idJoueurModified;
                printf("entrer le id du joueurs que tu veux modifier :");
                scanf("%d",&idJoueurModified);
                getchar();

                switch(choixModifierJoueur)
                {
                case 1:
                    ModifierPoste(idJoueurModified,joueurs,counter);
                    break;
                case 2:
                    ModifierAge(idJoueurModified,joueurs,counter);
                    break;
                case 3:
                    ModifierNombreButs(idJoueurModified,joueurs,counter);
                    break;
                }
                printf("vous voulez continuer dans le menu de modification ? y/n : ");
                scanf("%c",&choixContinuer);
                getchar();
            }
            while(choixContinuer == 'y');
            break;
        case 4:
            do
            {
                int idJoueur;
                printf("entrer id du joueur :");
                scanf("%d",&idJoueur);
                getchar();

                counter=SupprimerJoueur(joueurs,counter,idJoueur);
                printf("vous voulez continuer la supprission ? y/n : ");
                scanf("%c",&choixContinuer);
                getchar();
            }
            while(choixContinuer == 'y');
            break;
        case 5:

            int choixRecherche;
            int idJoueur,indice;
            char NomJoueur [MAX_SIZE];
            do
            {
                printf("------------Menu De Recherche------------ \n");
                printf("1 - Rechercher un joueur par Identifiant.\n");
                printf("2 - Rechercher un joueur par Nom.\n");
                scanf("%d",&choixRecherche);
                getchar();
                switch(choixRecherche)
                {
                case 1:
                    printf("entrer id du joueur que tu veux chercher :");
                    scanf("%d",&idJoueur);
                    getchar();
                    indice=rechercheJoueurParId(joueurs,counter,idJoueur);
                    AfficherRecherche(joueurs,indice);
                    break;
                case 2:
                    printf("entrer le nom du joueur que tu veux chercher :");
                    fgets(NomJoueur,sizeof(NomJoueur),stdin);
                    NomJoueur[strcspn(NomJoueur, "\n")]='\0';

                    indice=rechercheJoueurParNom(joueurs,counter,NomJoueur);
                    AfficherRecherche(joueurs,indice);

                    break;
                default:
                    printf("entrer un choix valide.\n");
                    break;
                }
                //le choix de continuer
                printf("vous voulez continuer ? y/n : ");
                scanf("%c",&choixContinuer);
                getchar();
            }
            while(choixContinuer == 'y');

            break;
        case 6:
            do
            {
                int choixStatistique;
                printf("------------Menu De statistique------------ \n");
                printf("1 - Afficher le nombre total de joueurs dans l’équipe.\n");
                printf("2 - Afficher l’âge moyen des joueurs.\n");
                printf("3 - Afficher les joueurs ayant marqué plus de X buts \n");
                printf("4 - Afficher le meilleur buteur.\n");
                printf("5 - Afficher le joueur le plus jeune et le plus âgé.\n");
                scanf("%d",&choixStatistique);
                getchar();
                switch(choixStatistique)
                {
                case 1:
                    printf("le nombre tootale de joueur dans l’équipe est : %d\n",counter);
                    break;
                case 2:
                    int ageMoyenne=AgeMoyenne(joueurs,counter);
                    printf("l’âge moyen des joueurs est : %d\n",ageMoyenne);
                    break;
                case 3:
                    AfficherJoueursMarquePlusXBut(joueurs,counter);
                    break;
                case 4:
                    AfficherMeilleurButeur(joueurs,counter);
                    break;
                case 5:
                    AfficherPlusJeunePlusAge(joueurs,counter);
                    break;


                }

                //le choix de continuer
                printf("vous voulez continuer ? y/n : ");
                scanf("%c",&choixContinuer);
                getchar();
            }
            while(choixContinuer == 'y');
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
}*/







//derniere version

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


int Ajouterjoueur(joueur joueurs[],int counter)
{
    static int idJoueur=10;

    printf("entrer le nom du joueur : ");
    fgets(joueurs[counter].nom,sizeof(joueurs[counter].nom),stdin);
    joueurs[counter].nom[strcspn(joueurs[counter].nom, "\n")] = '\0';//supprimer le retour a la ligne

    printf("entrer le prenom du joueur : ");
    fgets(joueurs[counter].prenom,sizeof(joueurs[counter].prenom),stdin);
    joueurs[counter].prenom[strcspn(joueurs[counter].prenom, "\n")] = '\0';//supprimer le retour a la ligne


    printf("entrer le numeroMaillot du joueur : ");
    scanf("%d",&joueurs[counter].numeroMaillot);
    getchar();

    int choixPost;
    do
    {
        printf("entrer le poste  du joueur : \n");
        printf("1 - gardien\n");
        printf("2 - defenseur\n");
        printf("3 - milieu\n");
        printf("4 - attaquant\n");
        scanf("%d",&choixPost);
        getchar();
        switch(choixPost)
        {
        case 1:
            strcpy(joueurs[counter].poste,"gardien");
            break;
        case 2:
            strcpy(joueurs[counter].poste,"defenseur");
            break;
        case 3:
            strcpy(joueurs[counter].poste,"milieu");
            break;
        case 4:
            strcpy(joueurs[counter].poste,"attaquant");
            break;
        }

    }
    while(choixPost!=1 &&  choixPost!=2  && choixPost!=3 && choixPost!=4);



    printf("entrer l'age  du joueur : ");
    scanf("%d",&joueurs[counter].age);
    getchar();

    printf("entrer le nombre de buts marques par le joueur. : ");
    scanf("%d",&joueurs[counter].buts);
    getchar();

    //le status
    int choixStatus;
    do
    {
        printf("entrer le statut dun joueur : \n");
        printf("1 - titulaire\n");
        printf("2 - remplaçant\n");
        scanf("%d",&choixStatus);
        getchar();

        switch(choixStatus)
        {
        case 1:
            strcpy(joueurs[counter].statut,"titulaire");
            break;
        case 2:
            strcpy(joueurs[counter].statut,"remplaçant");
            break;
        default:
            printf("entrer un choix valide.\n");
        }
    }
    while(choixStatus != 1 && choixStatus !=2);

    joueurs[counter].id = ++idJoueur;

    return (counter+1);
}
void AffichierJoueur(joueur joueurs[],int counter)
{
    for(int i=0; i<counter; i++)
    {
        printf("Id : %4d | la nom du joueur : %s | le prenom : %s | numeroMaillot : %4d | poste :%s | age : %4d | le nombre de buts : %4d | le status : %s\n",joueurs[i].id,joueurs[i].nom,joueurs[i].prenom,joueurs[i].numeroMaillot,joueurs[i].poste,joueurs[i].age,joueurs[i].buts,joueurs[i].statut);
        printf("\n");
        if(joueurs[i].buts>20)
        {
            printf("\n---------------- felicitation ----------------\n");
            printf("Bravo %s %s \n",joueurs[i].prenom,joueurs[i].nom);
            printf("avec %d des buts, tues une star de l'equipe !\n",joueurs[i].buts);
            printf("----------------               ----------------\n");
        }
        printf("\n");
    }
}
void TrierJoueurParNom(joueur joueurs[],int counter)
{
    //int index_i=0;
    joueur temp;

    for(int i=0; i<counter; i++)
    {
        for(int j=i+1; j<counter; j++)
        {
            if(strcasecmp(joueurs[i].nom,joueurs[j].nom)>0)
            {
                //index_i=j
                temp=joueurs[i];
                joueurs[i]=joueurs[j];
                joueurs[j]=temp;
            }
        }
    }
    printf("voici les joueur trier par nom : \n");
    AffichierJoueur(joueurs,counter);
}
void TrierJoueurParAge(joueur joueurs[],int count)
{
    joueur temp;
    for(int i=0; i<count; i++)
    {
        for(int j=i+1; j<count; j++)
        {
            if(joueurs[i].age>joueurs[j].age)
            {
                temp=joueurs[i];
                joueurs[i]=joueurs[j];
                joueurs[j]=temp;
            }
        }
    }
    printf("voici les joueur trier par age : \n");
    AffichierJoueur(joueurs,count);
}
void TrierJoueurParPoste(joueur joueurs[],int counter)
{
    printf("\t\t\t\t\t-----------les gardien sont : ----------- \n");

    for(int i=0; i<counter; i++)
    {
        if(strcasecmp(joueurs[i].poste,"gardien")==0)
        {
            printf("ID : %d | la nom du joueur : %s | le prenom : %s | numeroMaillot : %d | poste :%s | age : %d | le nombre de buts : %d\n",joueurs[i].id,joueurs[i].nom,joueurs[i].prenom,joueurs[i].numeroMaillot,joueurs[i].poste,joueurs[i].age,joueurs[i].buts);
        }
    }

    printf("\t\t\t\t\t----------- les defenseur sont : ----------- \n");
    for(int i=0; i<counter; i++)
    {
        if(strcasecmp(joueurs[i].poste,"defenseur")==0)
        {
            printf("ID : %d | la nom du joueur : %s | le prenom : %s | numeroMaillot : %d | poste :%s | age : %d | le nombre de buts : %d\n",joueurs[i].id,joueurs[i].nom,joueurs[i].prenom,joueurs[i].numeroMaillot,joueurs[i].poste,joueurs[i].age,joueurs[i].buts);
        }
    }
    printf("\t\t\t\t\t----------- les milieu sont : ----------- \n");
    for(int i=0; i<counter; i++)
    {
        if(strcasecmp(joueurs[i].poste,"milieu")==0)
        {
            printf("ID : %d | la nom du joueur : %s | le prenom : %s | numeroMaillot : %d | poste :%s | age : %d | le nombre de buts : %d\n",joueurs[i].id,joueurs[i].nom,joueurs[i].prenom,joueurs[i].numeroMaillot,joueurs[i].poste,joueurs[i].age,joueurs[i].buts);
        }
    }
    printf("\t\t\t\t\t\t----------- les attaquant sont : -----------\n");
    for(int i=0; i<counter; i++)
    {
        if(strcasecmp(joueurs[i].poste,"attaquant")==0)
        {
            printf("ID : %d | la nom du joueur : %s | le prenom : %s | numeroMaillot : %d | poste :%s | age : %d | le nombre de buts : %d\n",joueurs[i].id,joueurs[i].nom,joueurs[i].prenom,joueurs[i].numeroMaillot,joueurs[i].poste,joueurs[i].age,joueurs[i].buts);
        }
    }
}

int rechercheJoueurParId(joueur joueurs[],int counter,int id)
{
    for(int i=0; i<counter; i++)
    {
        if(joueurs[i].id==id)
        {
            return i;
            break;
        }
    }
    return -1;
}
int rechercheJoueurParNom(joueur joueurs[],int counter,char Nom[MAX_SIZE])
{
    for(int i=0; i<counter; i++)
    {
        if(strcasecmp(joueurs[i].nom,Nom)==0)
        {
            return i;
            break;
        }
    }
    return -1;
}
void AfficherRecherche(joueur joueurs[],int indice)
{

    printf("ID : %d | la nom du joueur : %s | le prenom : %s | numeroMaillot : %d | poste :%s | age : %d | le nombre de buts : %d\n",joueurs[indice].id,joueurs[indice].nom,joueurs[indice].prenom,joueurs[indice].numeroMaillot,joueurs[indice].poste,
           joueurs[indice].age,joueurs[indice].buts);

}
void ModifierPoste(int idJoueurModified,joueur joueurs[],int counter)
{
    int indice_joueur=rechercheJoueurParId(joueurs,counter,idJoueurModified);
    char nouvelPost [MAX_SIZE];
    if(indice_joueur!=-1)
    {
        printf("entrer le nouvelle post pour se joueur :\n");
        fgets(nouvelPost,sizeof(nouvelPost),stdin);
        nouvelPost[strcspn(nouvelPost, "\n")] = '\0';

        strcpy(joueurs[indice_joueur].poste,nouvelPost);
        printf("le  post modifier avce succes \n");
    }
    else
    {
        printf("le joueur n'exist pas.\n");
    }
}
void ModifierAge(int idJoueurModified,joueur joueurs[],int counter)
{
    int indice_joueur=rechercheJoueurParId(joueurs,counter,idJoueurModified);
    int nouvelAge;
    if(indice_joueur!=-1)
    {
        printf("entrer le nouvelle Age pour se joueur :\n");
        scanf("%d",&nouvelAge);
        getchar();

        joueurs[indice_joueur].age=nouvelAge;
        printf("l'age modifier avce succes \n");
    }
    else
    {
        printf("le joueur n'exist pas.");
    }
}

void ModifierNombreButs(int idJoueurModified,joueur joueurs[],int counter)
{
    int indice_joueur=rechercheJoueurParId(joueurs,counter,idJoueurModified);
    int nouvelNembreBut;
    if(indice_joueur!=-1)
    {
        printf("entrer le nouvelle nombre de buts pour se joueur :\n");
        scanf("%d",&nouvelNembreBut);
        getchar();

        joueurs[indice_joueur].buts=nouvelNembreBut;
        printf("le nombre de buts modifier avce succes \n");
    }
    else
    {
        printf("le joueur n'exist pas.");
    }
}
//la supprission
int SupprimerJoueur(joueur joueurs[],int counter,int idJoueur)
{
    int indice_joueur=rechercheJoueurParId(joueurs,counter,idJoueur);
    if(indice_joueur!=-1)
    {
        for(int i=indice_joueur; i<counter; i++)
        {
            joueurs[i]=joueurs[i+1];
        }
        counter--;
        printf("le nombre et supprimer avce succes \n");
    }
    else
    {
        printf("le joueur n'exist pas.\n");
    }
    return counter;
}
int AgeMoyenne(joueur joueurs[],int counter)
{
    int agemoyenne,Somme=0;
    for(int i=0; i<counter; i++)
    {
        Somme+=joueurs[i].age;
    }
    agemoyenne=Somme/counter;
    return agemoyenne;
}
void AfficherJoueursMarquePlusXBut(joueur joueurs[],int counter)
{

    joueur ButPlusX[counter];
    int nbJoueursTrouves = 0;
    int nbrBut;
    printf("entre le nombre des buts :");
    scanf("%d",&nbrBut);
    getchar();
    for(int i=0; i<counter; i++)
    {
        if(joueurs[i].buts>nbrBut)
        {
            ButPlusX[nbJoueursTrouves]=joueurs[i];
            nbJoueursTrouves++;
        }
    }
    printf("voici les joueur qui plus de %d buts \n.",nbrBut);
    for(int i=0; i<nbJoueursTrouves; i++)
    {
        printf("id : %d | la nom du joueur : %s | le prenom : %s | numeroMaillot : %d | poste :%s | age : %d | le nombre de buts : %d\n",ButPlusX[i].id,ButPlusX[i].nom,ButPlusX[i].prenom,ButPlusX[i].numeroMaillot,ButPlusX[i].poste,ButPlusX[i].age,ButPlusX[i].buts);

    }


}
void AfficherMeilleurButeur(joueur joueurs[],int count)
{
    int MaxBut;
    int indice;
    MaxBut=joueurs[0].buts;
    for(int i=0; i<count; i++)
    {
        if(joueurs[i].buts>MaxBut)
        {
            MaxBut=joueurs[i].buts;
            indice=i;
        }
    }
    AfficherRecherche(joueurs,indice);
    //printf("id : %d | la nom du joueur : %s | le prenom : %s - numeroMaillot : %d - poste :%s - age : %d - le nombre de buts : %d\n",joueurs[indice].id,joueurs[indice].nom,joueurs[indice].prenom,joueurs[indice].numeroMaillot,joueurs[indice].poste,joueurs[indice].age,joueurs[indice].buts);


}
void AfficherPlusJeunePlusAge(joueur joueurs[],int count)
{
    int MaxPlusAge=joueurs[0].age;
    int indicePlusAge=0;
    int indicePlusJeune=0;
    int MinPlusJeune=joueurs[0].age;
    for(int i=0; i<count; i++)
    {
        if(MaxPlusAge<joueurs[i].age)
        {
            MaxPlusAge=joueurs[i].age;
            indicePlusAge=i;
        }
        if(MinPlusJeune>joueurs[i].age)
        {
            MinPlusJeune=joueurs[i].age;
            indicePlusJeune=i;
        }
    }
    printf("le joueur le plus jeune est :\n");
    printf("id : %d - la nom du joueur : %s - le prenom : %s - numeroMaillot : %d - poste :%s - age : %d - le nombre de buts : %d\n",joueurs[indicePlusJeune].id,joueurs[indicePlusJeune].nom,joueurs[indicePlusJeune].prenom,joueurs[indicePlusJeune].numeroMaillot,
           joueurs[indicePlusJeune].poste,joueurs[indicePlusJeune].age,joueurs[indicePlusJeune].buts);

    printf("le joueur le plus Age est :\n");
    printf("id : %d - la nom du joueur : %s - le prenom : %s - numeroMaillot : %d - poste :%s - age : %d - le nombre de buts : %d\n",joueurs[indicePlusAge].id,joueurs[indicePlusAge].nom,joueurs[indicePlusAge].prenom,joueurs[indicePlusAge].numeroMaillot
           ,joueurs[indicePlusAge].poste,joueurs[indicePlusAge].age,joueurs[indicePlusAge].buts);

}
void rechercheJoueurParPoste(joueur joueurs[],int counter,char Postchercher[MAX_SIZE] )
{
    for(int i=0; i<counter; i++)
    {
        if(strcasecmp(joueurs[i].poste,Postchercher)==0)
        {
            printf("Id : %d - la nom du joueur : %s - le prenom : %s - numeroMaillot : %d - poste :%s - age : %d - le nombre de buts : %d\n",joueurs[i].id,joueurs[i].nom,joueurs[i].prenom,joueurs[i].numeroMaillot,joueurs[i].poste,joueurs[i].age,joueurs[i].buts);
        }
    }
}
void rechercheJoueurParTrancheAge(joueur joueurs[],int counter )
{
    int choixTrancheAge;
    do
    {
        printf(" -- choisi un tranche d'age -- \n");
        printf("1 - age de 17 a 23 :\n");
        printf("2 - age de 24 a 29  :\n");
        printf("3 - age de 29 a 36 :\n");
        scanf("%d",&choixTrancheAge);
        getchar();
        switch(choixTrancheAge)
    {
    case 1:
        for(int i=0; i<counter; i++)
            {
                if(joueurs[i].age>16 && joueurs[i].age<=23 )
                {
                    printf("Id : %d - la nom du joueur : %s - le prenom : %s - numeroMaillot : %d - poste :%s - age : %d - le nombre de buts : %d\n",joueurs[i].id,joueurs[i].nom,joueurs[i].prenom,joueurs[i].numeroMaillot,joueurs[i].poste,joueurs[i].age,joueurs[i].buts);
                }
            }
            break;
        case 2:
            for(int i=0; i<counter; i++)
            {
                if(joueurs[i].age>23 && joueurs[i].age<=29 )
                {
                    printf("Id : %d - la nom du joueur : %s - le prenom : %s - numeroMaillot : %d - poste :%s - age : %d - le nombre de buts : %d\n",joueurs[i].id,joueurs[i].nom,joueurs[i].prenom,joueurs[i].numeroMaillot,joueurs[i].poste,joueurs[i].age,joueurs[i].buts);
                }
            }
            break;
        case 3:
            for(int i=0; i<counter; i++)
            {
                if(joueurs[i].age>29 && joueurs[i].age<=36 )
                {
                    printf("Id : %d - la nom du joueur : %s - le prenom : %s - numeroMaillot : %d - poste :%s - age : %d - le nombre de buts : %d\n",joueurs[i].id,joueurs[i].nom,joueurs[i].prenom,joueurs[i].numeroMaillot,joueurs[i].poste,joueurs[i].age,joueurs[i].buts);
                }
            }
            break;
        }
        printf("vous voulez continuer pour voir les tranches ? y/n :");
        scanf("%c",&choixTrancheAge);
        getchar();
    }
    while(choixTrancheAge=='y');


}
int main()
{
    joueur joueurs [MAX_SIZE]=
    {
        {1,  "ziad",    "mohhammed", 10, "Milieu",    28, 15, "2000-06-15", " titulaire"},
        {2,  "Ronaldo",   "Cristiano", 7, "Attaquant", 36, 50, "2003-08-12", "remplaçant"},
        {3,  "messi",     "Lionel",   30, "Attaquant", 34, 5, "2004-07-05", "remplaçant"},
        {4,  "Neymar",    "Junior",   11, "Attaquant", 29, 0, "2010-05-20", "remplaçant"},
        {5,  "Mbappe",    "Kylian",    7, "Attaquant", 22, 11, "2017-11-01", "titulaire"},
        {6,  "Hakimi",    "Achraf",    2, "Defenseur", 25,  25, "2018-09-14", "remplaçant"},
        {7,  "Kante",     "N'Golo",   13, "Milieu",    34,  16, "2016-07-03", "titulaire"},
        {8,  "Modric",    "Luka",     10, "Milieu",    30,  3, "2008-08-15", "titulaire"},
        {9,  "Benzema",   "Karim",     9, "Attaquant", 25, 7, "2009-07-01", "remplaçant"},
        {10, "TerStegen", "Marc",      1, "Gardien",   11,   0, "2014-06-22", "titulaire"},

    };
    int choix;
    int counter=10;

    char choixContinuer;
    do
    {
        printf("\n \t\t\t\t******* Gestion d'une equipe de Football ******* \n");
        printf("\n ------------ Menu Principal------------ \n");
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
            char choixAjoutJoueur;
            int choixContinuerAjout;
            do
            {
                printf("\n ------------ Menu D'ajout ------------ \n");
                printf("a - Ajouter un nouveau joueur. \n");
                printf("b - Ajouter plusieurs joueurs.\n");
                scanf("%c",&choixAjoutJoueur);
                getchar();

                switch(choixAjoutJoueur)
                {
                case 'a':
                    counter=Ajouterjoueur(joueurs,counter);
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

                    break;
                default:
                    printf("entrer un choix d'ajout valide.\n");
                    break;
                }
                printf("vous voulez continuer dans le menu d'ajout ? y/n :");
                scanf("%c",&choixContinuerAjout);
                getchar();
            }
            while(choixContinuerAjout=='y');
            break;
        case 2:
            int choixContinuerAffichage;
            do
            {
                int choixAffiche;
                printf("------------Menu D'affichage------------ \n");
                printf("1 - Trier les joueurs par ordre alphabetique (Nom).\n");
                printf("2 - Trier les joueurs par age.\n");
                printf("3 - Afficher les joueurs par poste.\n");
                scanf("%d",&choixAffiche);
                getchar();

                switch(choixAffiche)
                {
                case 1:
                    TrierJoueurParNom(joueurs,counter);
                    break;
                case 2:
                    TrierJoueurParAge(joueurs,counter);
                    break;
                case 3:
                    TrierJoueurParPoste(joueurs,counter);
                    break;
                default:
                    printf("entrer un choix valide.");
                    break;
                }

                printf("vous voulez continuer dans le menu d'affichage ? y/n :");
                scanf("%c",&choixContinuerAffichage);
                getchar();
            }
            while(choixContinuerAffichage=='y');
            break;
        case 3:
            int choixModifierJoueur;
            int choixContinuerModification;
            do
            {
                printf("------------Menu De Modification------------ \n");
                printf("1 - Modifier le poste dun joueur.\n");
                printf("2 - Modifier lage dun joueur.\n");
                printf("3 - Modifier le nombre de buts marqués par un joueur.\n");
                scanf("%d",&choixModifierJoueur);
                getchar();
                int idJoueurModified;
                printf("entrer le id du joueurs que tu veux modifier :");
                scanf("%d",&idJoueurModified);
                getchar();

                switch(choixModifierJoueur)
                {
                case 1:
                    ModifierPoste(idJoueurModified,joueurs,counter);
                    break;
                case 2:
                    ModifierAge(idJoueurModified,joueurs,counter);
                    break;
                case 3:
                    ModifierNombreButs(idJoueurModified,joueurs,counter);
                    break;
                }
                printf("vous voulez continuer dans le menu de modification ? y/n : ");
                scanf("%c",&choixContinuerModification);
                getchar();
            }
            while(choixContinuerModification == 'y');
            break;
        case 4:
            int choixContinuerSupprimer;
            do
            {
                int idJoueur;
                printf("entrer id du joueur :");
                scanf("%d",&idJoueur);
                getchar();

                counter=SupprimerJoueur(joueurs,counter,idJoueur);
                printf("vous voulez continuer la supprission ? y/n : ");
                scanf("%c",&choixContinuer);
                getchar();
            }
            while(choixContinuerSupprimer == 'y');
            break;
        case 5:

            int choixRecherche;
            int choixContinuerRecherche;
            int idJoueur,indice;
            char NomJoueur [MAX_SIZE];
            do
            {
                printf("------------Menu De Recherche------------ \n");
                printf("1 - Rechercher un joueur par Identifiant.\n");
                printf("2 - Rechercher un joueur par Nom.\n");
                printf("3 - Rechercher un joueur par Post.\n");
                printf("4 - Rechercher un joueur par tranche d'age.\n");
                scanf("%d",&choixRecherche);
                getchar();
                switch(choixRecherche)
                {
                case 1:
                    printf("entrer id du joueur que tu veux chercher :");
                    scanf("%d",&idJoueur);
                    getchar();
                    indice=rechercheJoueurParId(joueurs,counter,idJoueur);
                    AfficherRecherche(joueurs,indice);
                    break;
                case 2:
                    printf("entrer le nom du joueur que tu veux chercher :");
                    fgets(NomJoueur,sizeof(NomJoueur),stdin);
                    NomJoueur[strcspn(NomJoueur, "\n")]='\0';

                    indice=rechercheJoueurParNom(joueurs,counter,NomJoueur);
                    AfficherRecherche(joueurs,indice);

                    break;
                case 3: //recherche par Poste
                    char Postchercher[MAX_SIZE];
                    printf("entrer le poste que tu veux chercher :");
                    fgets(Postchercher,sizeof(Postchercher),stdin);
                    Postchercher[strcspn(Postchercher,"\n")]='\0';
                    rechercheJoueurParPoste(joueurs,counter,Postchercher);

                    break;
                case 4: //recherche par tranche dage
                    rechercheJoueurParTrancheAge(joueurs,counter);
                    break;
                default:
                    printf("entrer un choix valide.\n");
                    break;
                }
                //le choix de continuer
                printf("vous voulez continuer dans le menu recherche ? y/n : ");
                scanf("%c",&choixContinuerRecherche);
                getchar();
            }
            while(choixContinuerRecherche == 'y');

            break;
        case 6:
            int choixContinuerStatistique;
            do
            {
                int choixStatistique;
                printf("------------Menu De statistique------------ \n");
                printf("1 - Afficher le nombre total de joueurs dans l'equipe.\n");
                printf("2 - Afficher l'age moyen des joueurs.\n");
                printf("3 - Afficher les joueurs ayant marque plus de X buts \n");
                printf("4 - Afficher le meilleur buteur.\n");
                printf("5 - Afficher le joueur le plus jeune et le plus age.\n");
                scanf("%d",&choixStatistique);
                getchar();
                switch(choixStatistique)
                {
                case 1:
                    printf("le nombre tootale de joueur dans l’equipe est : %d\n",counter);
                    break;
                case 2:
                    int ageMoyenne=AgeMoyenne(joueurs,counter);
                    printf("l’age moyen des joueurs est : %d\n",ageMoyenne);
                    break;
                case 3:
                    AfficherJoueursMarquePlusXBut(joueurs,counter);
                    break;
                case 4:
                    AfficherMeilleurButeur(joueurs,counter);
                    break;
                case 5:
                    AfficherPlusJeunePlusAge(joueurs,counter);
                    break;


                }

                //le choix de continuer
                printf("vous voulez continuer dans le menu statistique ? y/n : ");
                scanf("%c",&choixContinuerStatistique);
                getchar();
            }
            while(choixContinuerStatistique == 'y');
            break;
        default:
            printf("entrer un choix valide");
            break;
        }

        //le choix de continuer
        printf("vous voulez continuer dans le menu principale ? y/n : ");
        scanf("%c",&choixContinuer);
        getchar();
    }
    while(choixContinuer == 'y');
    return 0;
}
