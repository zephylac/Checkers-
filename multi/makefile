CFLAGS = -g -Wextra 

inc = ../include/
proto = $(inc)joueur.h $(inc)jeu.h $(inc)plateau.h $(inc)liste_ptr.h $(inc)affichage.h $(inc)fichier.h
fichiers = client.o ../joueur.o ../jeu.o ../plateau.o ../liste_ptr.o ../affichage.o ../fichier.o

all : ${fichiers}
	gcc -o multi_exe ${fichiers} ${CFLAGS}

client.o : client.c ${proto}
	gcc -c client.c ${CFLAGS}

liste_ptr.o : liste_ptr.c $(inc)liste_ptr.h
	gcc -c liste_ptr.c ${CFLAGS}

plateau.o : plateau.c $(inc)plateau.h
	gcc -c plateau.c ${CFLAGS}

jeu.o : jeu.c $(inc)jeu.h
	gcc -c jeu.c ${CFLAGS} 

joueur.o : joueur.c $(inc)joueur.h
	gcc -c joueur.c ${CFLAGS} 

affichage.o: affichage.c $(inc)affichage.h
	gcc -c affichage.c ${CFLAGS}

fichier.o: fichier.c $(inc)fichier.h
	gcc -c fichier.c ${CFLAGS}

clean :
	rm -rf *.o
	rm exe
