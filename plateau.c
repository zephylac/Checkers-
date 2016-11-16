#include <stdio.h> 
#include <stdlib.h>
#define N 17

typedef enum {vide, joueur1, joueur2, joueur3, joueur4, invalide}t_joueur;
typedef enum {vide, pion, dame}t_piece;
typedef enum {equipe1 = 1, equipe2}t_equipe;
typedef enum {A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q}t_lettre;

typedef struct {int x; int y}t_coordonnees;
typedef struct {t_joueur joueur; t_piece piece; t_equipe equipe} t_contenu;
typedef struct {t_coordonnees coordonnees; t_contenu contenu} t_case;
typedef struct {char nom[20]; int pions_pris; int pions_perdus; int nb_coup} t_stats;
t_contenu plateau[N][N] ;

void ChangeJoueur(int l,c,t_contenu plateau[N][N],t_joueur nouv){
  plateau[l][c]->joueur=nouv;
}
int litJoueur(int l,c){
    return(plateau[l][c]->joueur);
}

void init(t_contenu plateau[N][N]){
  int l,c;
  for(l=0,c=0;l<N;l++){
    for(c=0;c<N;c++){ // parcours une seule fois la matrice
      if((c<4 && (l<4 || l>=(N-4) )||(c>=N-4 && (l<4 || l>=(N-4))) ChangeJoueur(l,c,plateau,invalide); // case dans les coins sont invalides
      else if((l+c)%2==0) ChangeJoueur(l,c,plateau[N][N],vide);//indique que la case est vide
      else if((c>=4 && c<N-4 && l>=N-5 && ((l+c)%2==1) ChangeJoueur(l,c,plateau,joueur1);//place les pions du joueur 1
      else if((c>=N-5 && l>=4 && l<N-4 && ((l+c)%2==1) ChangeJoueur(l,c,plateau,joueur2);//place les pions du joueur 2
      else if((c>=4 && c<N-4 && l<=4 && ((l+c)%2==1) ChangeJoueur(l,c,plateau,joueur3);//place les pions du joueur 3
      else if((c<=4 && l>=4 && l<N-4 && ((l+c)%2==1) ChangeJoueur(l,c,plateau,joueur4);//place les pions du joueur 4  
    }
  }
}
               

void afficher(t_case plateau[N][N]){
  int l,c,joueur;
  for(l=0,c=0;l<N;l++){
    for(c=0;c<N;c++){ // parcours une seule fois la matrice
      joueur=litJoueur(l,c);
      printf("\n");
      if(joueur==5) printf("   ");
      else if(joueur==4) printf(" 4 ");
      else if(joueur==3) printf(" 3 ");
      else if(joueur==2) printf(" 2 ");
      else if(joueur==1) printf(" 1 "); 
    }
  }
}  
  int coupForce(t_joueur joueur,t_liste ls_coup_f /* type t_case*/) // retourne 1 si coup forcé ou 0 si pas coup forcé
  int coupDispo(t_coordonnees,t_joueur/*eviter deplacer pion adverse*/,t_liste ls_coup_d)
  int jouerTour() 
  void deplacerPion()
  void deplacerDame() 
  void prendrePiece() 
  void creerDame() 
  void finPartie()
  int partieFini() 
 int peutPrendre()

void main(){
  init(plateau);
  afficher(plateau);
}
