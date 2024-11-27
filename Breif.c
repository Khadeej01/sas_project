#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define max 50
   typedef struct {
   	int jour;
   	int mois;
   	int ann;
   }DateEcheance;
   typedef struct tache{
   	char titre[100];
   	char description[100];
    int priorite; // plus importante ou moins
    DateEcheance date;
   }Tache; 
   Tache T[50]; //Tableau des taches
   int nbretaches=0;
      //Ajout des taches
   void Ajoutertache(){
   	int nbreTaches;
   	printf("Ajoutter une tache\n");
   printf("\nEntrer le titre :\n ");
   getchar();
   fgets(T[nbreTaches].titre,sizeof(T[nbreTaches].titre),stdin);
   printf("Entrer la description :\n");
      fgets(T[nbreTaches].description,sizeof(T[nbreTaches].description),stdin);
   printf("Entrer la date d'echeance  :\n");
   scanf("%d %d %d",&T[nbreTaches].date.jour,&T[nbreTaches].date.mois,&T[nbreTaches].date.ann);
   int choix; 
   printf("Entrer la priorite(1:pour Haute et 2:pour Basse): \n");
   do{
   	   printf("Entrer votre choix: \n");
   	   scanf("%d",&choix);
  			 	if (choix== 1) {
  			 		T[nbreTaches].priorite=1;
                      printf("Priorite: Haute\n");
                } else if(choix== 2) {
                	T[nbreTaches].priorite=2;
                           printf("Priorite: Basse\n");
                     }else printf("priorite inconnue");
             getchar();
   }while(choix!=1 && choix!=2);
     nbreTaches++;
   if(nbretaches>=50){
   printf("Erreur: ");// limite de taches atteinte
   }
}
 // Affichage des taches 
   void AfficherlisteTaches(){
   	int nbreTaches;
   	printf("\n______Liste des taches______\n");
   	int i;
   	for(i=0;i<nbreTaches;i++){
   		printf("Titre: %s\n ",T[i].titre);
   		printf("Description: %s \n",T[i].description);
   			if(T[i].priorite==1){
   				printf(" Priorite: Tache importante\n");
			   }else printf(" Tache normale \n");
   			
   		printf("date d'echeance: %d/ %d/ %d",T[i].date.jour,T[i].date.mois,T[i].date.ann);
	   }
   }
 
 
 
 
 
 
 
 
int main(){
	int choix;
	int tache;
	//Menu//
	do{
	printf("\n    Menu    \n");
	printf("1: Ajouter \n");
		printf("2: Afficher \n");
			printf("3: Modifier \n");
				printf("4: Supprimer \n");
					printf("5: Filtrer les taches par prioriter \n");// 
						printf("6: TriCroissante \n");
					printf("7: Quitter \n");
						printf("tapez votre choix: \n");
						scanf("%d",&choix);
				switch(choix){
					case 1:Ajoutertache(); break;
					case 2:AfficherlisteTaches(); break;
				//	case 3:ModifierTache(); 	 break;
                    // case 4:SupprimerTache(); 	 break;
				//	case 5: FiltrerTache();break;
                   // case 6: TriCroissante() ; break;
					case 7: 
						printf("Au revoir! \n"); break;
				    default : printf("choix introuvable,veuillez reessayer ^-^");
				}
	}while(choix!=7);
return 0;	
}
