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
   	
   	printf("Ajoutter une tache\n");
   	
   printf("\nEntrer le titre :\n ");
   getchar();
   fgets(T[nbretaches].titre,sizeof(T[nbretaches].titre),stdin);
   T[nbretaches].titre[strcspn(T[nbretaches].titre, "\n")] = '\0';
   
   printf("Entrer la description :\n");
      fgets(T[nbretaches].description,sizeof(T[nbretaches].description),stdin);
      T[nbretaches].description[strcspn(T[nbretaches].description, "\n")] = '\0';
      
   printf("Entrer la date d'echeance  :\n");
   scanf("%d %d %d",&T[nbretaches].date.jour,&T[nbretaches].date.mois,&T[nbretaches].date.ann);
   
   int choix; 
   printf("Entrer la priorite(1:pour Haute et 2:pour Basse): \n");
   do{
   	   printf("Entrer votre choix: \n");
   	   scanf("%d",&choix);
  			 	if (choix== 1) {
  			 		T[nbretaches].priorite=1;
                      printf("Priorite: Haute\n");
                } else if(choix== 2) {
                	T[nbretaches].priorite=2;
                           printf("Priorite: Basse\n");
                     }else printf("priorite inconnue");
             getchar();
   }while(choix!=1 && choix!=2);
     nbretaches++;
   if(nbretaches>=50){
   printf("Erreur: ");// limite de taches atteinte
   }
}
 // Affichage des taches 
   void AfficherlisteTaches(){
   	
   	printf("\n______Liste des taches______\n");
   	int i;
   	for(i=0;i<nbretaches;i++){
   		printf("Titre: %s\n ",T[i].titre);
   		printf("Description: %s \n",T[i].description);
   			if(T[i].priorite==1){
   				printf(" Priorite: Tache importante\n");
			   }else printf(" Tache normale \n");
   			
   		printf(" Date d'echeance: %d/ %d/ %d\n",T[i].date.jour,T[i].date.mois,T[i].date.ann);
	   }
   }
  
    // Modifier les taches
   void ModifierTache(){
   	int choix;
   if(nbretaches>0){
   	int numeroTache;
   	printf("Donner le numero de tache a modifier\n");
   	scanf("%d",&numeroTache);
   	if(numeroTache>0 && numeroTache<=nbretaches){
   	
   	printf("Entrer un nouveau titre\n ");
   	scanf("%s",T[numeroTache-1].titre);
   	 
   	 printf("Entrer une nouvelle description \n");
   	 scanf("%s",T[numeroTache-1].description);
   	 
   	 int choix;
		do{
			printf("entrer priorite (1- high  2-low) : ");
			scanf("%d",&choix);
			switch(choix){
				case 1 : T[numeroTache-1].priorite = 1  ;break;
				case 2 :T[numeroTache-1].priorite = 2;break;
				default:printf("choix invalide !!");
			}
		}while(choix!=1 && choix!=2);
		printf("Entrer le nouveau jour (actuel: %d) : ",T[numeroTache-1].date.jour);
		scanf("%d",&T[numeroTache-1].date.jour);
		printf("Entrer le nouveau mois (actuel: %d) : ",T[numeroTache-1].date.mois);
		scanf("%d",&T[numeroTache-1].date.mois);
		printf("Entrer le nouvelle (actuel: %d) : ",T[numeroTache].date.ann);
		scanf("%d",&T[numeroTache-1].date.ann);
   	printf("Tache modifier avec succes ^-^");
   }else printf("Aucune Tache a modifier ");
}else printf("Aucune Tache a modifier");
}
  //Suppresion des taches
void SupprimerTache(){
    // Verifiez que le nombre de taches est > 0
	  	int   numeroTache;
	if(nbretaches>0){
		int i;
		printf("\nEntrer le numero de la tache a supprimer  \n");
		scanf("%d",&numeroTache);
		 // Verifiez que le numero de tache est valide
		if(numeroTache>0 && numeroTache<=nbretaches){
			// Deplacer les taches suivantes pour combler l'espace
			for(i=numeroTache-1; i<nbretaches-1; i++){
				T[i]=T[i+1];
			}
			nbretaches--;  // Reduire le compteur de taches
			printf(" Tache  supprime avec succes^-^");
		}else printf("Numero de Tache invalide.");
	}else printf("Aucune tache a supprimer ");
}
//Filtrer les taches
void FiltrerTache() { 
    int i;
    int priorite;

    printf("Entrez la priorite que vous souhaitez afficher (1 pour Haute, 2 pour Basse) : ");
    scanf("%d", &priorite);

    

    for ( i = 0; i < nbretaches; i++) {
        // Verifie si la priorite de la tache correspond a celle choisie
        if (T[i].priorite == priorite) {
            printf("Tache avec priorite %s :\n", priorite== 1 ? "Haute" : "Basse");
            printf("Titre : %s\n", T[i].titre);
            printf("Description : %s\n", T[i].description);
            printf("Date : %s\n", T[i].date);
            printf("Priorité : %d\n", T[i].priorite);
            printf("\n");
        }
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
					printf("5: Filtrer les taches par prioriter \n");
					printf("6: Quitter \n");
						printf("tapez votre choix: \n");
						scanf("%d",&choix);
				switch(choix){
					case 1:Ajoutertache(); break;
					case 2:AfficherlisteTaches(); break;
					case 3:ModifierTache(); 	 break;
                    case 4:SupprimerTache(); 	 break;
					case 5: FiltrerTache();break;
				    case 6: 
						printf("Au revoir! \n"); break;
				    default : printf("choix introuvable,veuillez reessayer ^-^");
				}
	}while(choix!=6);
return 0;	
}
