# Checkers-
A game developped under C library

Jeux de dames++

I- Introduction

	Le jeux de dames++ consiste à adapter un jeu de dames afin de pouvoir y jouer à 4 joueurs. Pour pouvoir permettre  la réalisation de ce jeux nous devrons adapter le tableaux ainsi que certaines règles.

II- Règles

1 – Le matériel

- Le plateau sera modifié, il contiendra 225 cases.
-Chaque joueurs disposera de 18 pions.
- La partie se joue en deux contre deux.
- Il y a deux types de pièce : les pions et les dames
	
2 – La marche des pièces

-Une fois le pion sélectionné, le joueur a alors l’obligation de le jouer si cela est possible
- Un coup ne peut être annulé.
	Les pions :
	- Un pion se déplace obligatoirement vers l’avant, en diagonale, sur un case vide.
	-Lorsqu’un pion atteint la dernière rangé, le pion devient dame.

	Les dames :
	- Une dame rentre en action après que l’adversaire ait joué au moins une fois depuis 		sa création.
	- Une dame peut se déplacer en arrière ou en avant sur toute la longueurs de ses deux 		diagonales
3 – La prise
		
-La prise des pièces adverses est obligatoire dans cette version du jeux sauf pour les pions alliés

-Lorsqu’un pion se trouve en présence, diagonalement, d’une pièce adverse derrière laquelle se trouve une case libre, il doit obligatoirement sauter par-dessus cette pièce et occuper la case libre. Cette pièce adverse est alors enlevée du damier. Cette opération complète est la prise par un pion.

-Lorsqu’une dame se trouve en présence sur la même diagonale, directement ou à distance, d’une pièce adverse derrière laquelle se trouvent une ou plusieurs cases libres, elle doit obligatoirement passer par-dessus cette pièce et occuper, au choix, une des cases libres. Cette pièce est alors enlevée du damier. Cette opération complète est la prise par une dame.

-Lorsqu’au cours d’une prise par un pion, celui-ci se trouve à nouveau en présence, diagonalement, d’une pièce adverse derrière laquelle se trouve une case libre, il doit obligatoirement sauter par-dessus cette seconde pièce, voire d’une troisième et ainsi de suite, et occuper la case libre se trouvant derrière la dernière pièce capturée. Les pièces adverses ainsi capturées sont ensuite enlevées du damier dans l’ordre de la prise. Cette opération complète est une rafle par un pion.
 
Lorsqu’au cours d’une prise par une dame, celle-ci se trouve à nouveau en présence, sur une même diagonale, d’une pièce adverse derrière laquelle se trouve une ou plusieurs cases libres, elle doit obligatoirement sauter par-dessus cette seconde pièce, voire d’une troisième et ainsi de suite, et occuper au choix une case libre se trouvant derrière et sur la même diagonale que la dernière pièce capturée. Les pièces adverses ainsi capturées sont ensuite enlevées du damier dans l’ordre de la prise. Cette opération complète est une rafle par une dame.

Au cours d’une rafle, il est interdit de passer au-dessus de ses propres pièces. Mais il est possible de passer au-dessus des pièces de son allié cependant les pièces seront prise aussi.

Au cours d’une rafle, il est permis de passer plusieurs fois sur une même case libre mais il est interdit de passer plus d’une fois au-dessus d’une même pièce adverse.

4 – Fin de partie

Une partie est considérée comme fini lorsque l’un des deux joueurs adverses n’a plus de pion.
Lorsqu’un joueur ne peut plus jouer, alors son équipe perd.

III – Mode d’interaction

-Le jeux se joue au tour par tour, le programme indiquera quelle joueur doit jouer. 
 
-Les coordonnées seront repéré grâce à une lettre et un chiffre.

-L’utilisateur entrera les coordonnées du pion qu’il veut déplacer. En fonction de cette saisie, le programme affichera si oui ou non le déplacement est possible. Si oui, les possibilités de déplacement.

- On identifiera les pions et les dames de chaque joueurs de manière unique.

-Les cases vides seront identifiés par des points (‘.’). 

IV – Les contraintes

-Le jeux sera développé sous l'environnement  C.

-Le jeux doit être rendu avant le 16 décembre.

IV – La conception


1 -  Structure de données


Un enum permettant de savoir quelle joueur est concerné :
	typedef enum t_joueur(vide, joueur_1, joueur_2, joueur_3, joueur_4, invalide);

Un enum permettant de savoir à quelle type de pièce nous faisons face.
	typedef enum t_piece(vide , pion , dame) ;

Un enum permettant de savoir l'équipe d'un joueur et donc de connaître le statut en 2 joueur 
	typedef enum t_equipe(equipe_1 = 1 , equipe_2) ;

Une structure regroupant tous les types énumérés précédent, cela nous permet de pouvoir représenter une case 
	typedef struct t_case(t_joueur joueur ; t_piece piece ; t_equipe equipe ;) ;


	#define N 17
	t_case plateau[N][N] ;

 typedef struct t_stats(char[20] nom ; int pion_pris ; int pion_perdu ; int nb_coup ;) ;


2 –  Fonctions

void init(t_case plateau[N][N])
void afficher(t_case plateau[N][N])
int jouerTour()
void deplacerPion()
void deplacerDame()
void prendrePiece()
void creerDame()
void finPartie()

int partieFini()
int peutPrendre()

3 -  Structure de fichiers

plateau.c / plateau.h
plateau's management
pion's movement
joueur.c / joueur.h
player's interaction
game.c / game.h
win / loss condition
 other gamerules
main.c
