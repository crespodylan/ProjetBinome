			/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\
			/\        -- SU DO KU --        /\
			/\			        /\
			/\			        /\
			/\	+-----+-----+-----+     /\
			/\	|5 1 3|6 8 7|2 4 9|     /\
			/\	|8 4 9|5 2 1|6 3 7|     /\
			/\	|2 6 7|3 4 9|5 8 1|     /\
			/\	+-----+-----+-----+     /\
			/\	|1 5 8|4 6 3|9 7 2|     /\
			/\	|9 7 4|2 1 8|3 6 5|     /\
			/\	|3 2 6|7 9 5|4 1 8|     /\
			/\	+-----+-----+-----+     /\
			/\	|7 8 2|9 3 4|1 5 6|     /\
			/\	|6 3 5|1 7 2|8 9 4|     /\
			/\	|4 9 1|8 5 6|7 2 3|     /\
			/\	+-----+-----+-----+     /\
			/\			        /\
			/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\

Les fichiers .o sont dans /obj/Release
Les fichiers .h sont dans Headers
Les fichier .c sont dans Code

Windows
--------------------------------------
Il suffit de lancer le .exe dans le dossier /bin/release/ .
Le fichier Sudoku.cbp permet d'ouvrir le projet sous code::blocks.
/!\ Même si vous ouvrez le projet avec code::blocks vous ne serez plus en mesure de le compiler
/!\ Mais il n'y a pas besoin de recompiler. L'exécutable est déjà créé ! (/bin/Release)

Linux
--------------------------------------
Pour lancer le jeu il suffit de lancer un ./Sudoku (avec les droits néscéssaires à l'exécution)
Le makefile permet de compiler et de créer le programme sous linux.
Nous avons coder sous Windows. Si vous êtes sous linux vous serez,
malheureusement obliger de lancer la commande make.
Le fichier Sudoku.cbp permet d'ouvrir le projet sous code::blocks.

Pour compiler et lancer le programme sous linux :

make all
./Sudoku


Les commandes du programme
--------------------------------------
- random : Créé un sudoku et le met en mémoire ( faire un print pour le voir )
	
- easy : Créé un sudoku facile (45 cases en moins) et le met en mémoire

- medium : Créé un sudoku moyen (55 cases en moins) et le met en mémoire

- hard : Créé un sudoku difficile (65 cases en moins) et le met en mémoire

- resolve : Resoue le sudoku en memoire (si il y en a un)

- open $fichier (sous forme de chemin) : Ouvre un fichier et l'importe comme sudoku
Après importation faire un print ;)

- save $fichier (sous forme de chemin) : Sauvegarde le dernier sudoku en memoire dans un fichier

- print : Affiche le sudoku en mémoire

- delete $n: Supprimer des cases du sudoku en mémoire 
(attention à ne pas supprimer plus de cases qu'il n'y en a)

- exit : Sortir du jeu


Les fichiers
--------------------------------------

sudoku.c
Fichier contenant la structure d'un sudoku et les fonctions associées à un sudoku.
-
generation.c
Fichier contenant l'algorithme de génération du sudoku.
-
resolution.c
Fichier contenant les algorithmes de résolution d'un sudoku.
-
files.c
Fichier contenant l'écriture et la lecture d'un fichier contenant un sudoku.
-
displaying.c
Fichier contenant la fonction pour afficher un sudoku.
-
utils.c
Fichier contenant différents algorithme pouvant être utiles pour ce projet.
-
Liste.c
Fichier qui contient la structure et les opérations d'une liste
