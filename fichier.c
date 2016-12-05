#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/struct.h"

void sauv(){
	FILE * fic;
	int i, j;
	char nom[30];
	
	printf("\nLe nom de la sauvegard ene doit pa sdépasser 30 charactères");
	printf("\nEntrer le nom de la sauvegarde : ");
	scanf("%s", nom);
	
	fic = fopen(nom,"w");

	//Seulement utile lorsque l'on sauvegarde au milieu d'un tour, lorsque l tour ne sera pas au joueur 1
	//Il faudra init la variable tour joueur 
	//fprintf(fic,"%i ",joueur);
	
	for(i = 0; i < Z; i++){
		for( j = 0; j < Z; j++){
			fprintf(fic,"%i %i %i ",plateau[i][j].joueur, plateau[i][j].piece,plateau[i][j].equipe);
		}
	}
	fclose(fic);
}

void lireSauv(){
	FILE * fic;
	int i, j;
	char nom[30];

	printf("\nEntrer le nom de la sauvegarde à lire");
	scanf("%s", nom);
	fic = fopen(nom,"r");
	while(fic == NULL){
		printf("Erreur, le nom entré n'est pas valide\n");
		printf("\nEntrer le nom de la sauvegarde à lire");
		scanf("%s",nom);
		fic = fopen(nom,"r");
	}	
	
	//Seulement utile lorsque l'on sauvegarde au milieu d'un tour, lorsque l tour ne sera pas au joueur 1
	//Il faudra init la variable tour joueur 
	//fscanf(fic,"%i ",&joueur);	

	for(i = 0; i < Z; i++){
		for( j = 0; j < Z; j++){
			fscanf(fic,"%i %i %i ",plateau[i][j].joueur, plateau[i][j].piece,plateau[i][j].equipe);
		}
	}
}
