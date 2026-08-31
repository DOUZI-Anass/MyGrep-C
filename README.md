# mygrep

`mygrep` est une implémentation simplifiée de la commande Unix `grep`, développée en C.

Le programme permet de rechercher un mot ou une chaîne de caractères dans un fichier texte et d'afficher les lignes correspondantes.

## Fonctionnalités

- Recherche d'un mot dans un fichier texte
- `-n` : affiche le numéro des lignes correspondantes
- `-i` : ignore les différences entre majuscules et minuscules
- `-v` : inverse la recherche et affiche les lignes qui ne correspondent pas
- Possibilité de combiner plusieurs options
- Gestion des erreurs d'ouverture de fichier et des mauvais arguments

## Compilation

Le projet utilise un `Makefile`.

Pour compiler :

~~~bash
make
~~~

Cela génère l'exécutable `mygrep`.

## Utilisation

Syntaxe générale :

~~~bash
./mygrep [OPTIONS] MOT FICHIER
~~~

## Exemples

### Recherche simple

~~~bash
./mygrep hello fichier.txt
~~~

Affiche toutes les lignes de `fichier.txt` contenant `hello`.

### Afficher les numéros de ligne

~~~bash
./mygrep -n hello fichier.txt
~~~

Exemple de résultat :

~~~text
1. hello world
4. hello EPITA
~~~

### Ignorer les majuscules et minuscules

~~~bash
./mygrep -i hello fichier.txt
~~~

Cette commande peut trouver :

~~~text
hello
Hello
HELLO
hELLo
~~~

### Inverser la recherche

~~~bash
./mygrep -v hello fichier.txt
~~~

Affiche les lignes qui ne contiennent pas `hello`.

### Combiner plusieurs options

Les options peuvent être combinées.

Par exemple :

~~~bash
./mygrep -n -i hello fichier.txt
~~~

Cette commande recherche `hello` sans tenir compte des majuscules/minuscules et affiche les numéros de ligne.

Autre exemple :

~~~bash
./mygrep -n -i -v hello fichier.txt
~~~

Cette commande combine les trois options.

## Options

| Option | Description |
|--------|-------------|
| `-n` | Affiche le numéro de ligne |
| `-i` | Ignore les majuscules et minuscules |
| `-v` | Inverse la recherche |

## Nettoyage

Pour supprimer l'exécutable généré :

~~~bash
make clean
~~~

## Outils utilisés

- C
- GCC
- Make
- Git
- Valgrind
- Linux / WSL
- Visual Studio Code

## Vérification mémoire

Le programme a été testé avec Valgrind :

~~~bash
valgrind ./mygrep hello fichier.txt
~~~

Les tests effectués ne montrent aucune fuite mémoire ni erreur mémoire détectée.

## Objectif du projet

Ce projet a été réalisé afin de pratiquer plusieurs concepts du langage C et de l'environnement Unix/Linux :

- utilisation de `argc` et `argv`
- manipulation des chaînes de caractères
- utilisation des pointeurs
- lecture de fichiers avec `FILE *`
- utilisation de `fopen`, `fgets` et `fclose`
- utilisation de buffers
- création et utilisation de fonctions
- gestion d'options en ligne de commande
- compilation avec GCC et Make
- gestion de versions avec Git
- vérification de la mémoire avec Valgrind
