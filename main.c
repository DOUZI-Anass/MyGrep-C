#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
    if (argc!=3){
        printf("Erreur :  Nombre d'argument différent de 3 ! \n");
        return 1;
    } 
    
    FILE *fichier;
    fichier = fopen(argv[2],"r");

    if (fichier == NULL){
        printf("Erreur : impossible d'ouvrir le fichier \n");
        return 1;
    }

    char ligne[1024];
    while(fgets(ligne,sizeof(ligne),fichier) != NULL){
        if(strstr(ligne,argv[1])!=NULL){
            printf("%s",ligne);
        }
    }

    print("\n");
    fclose(fichier);
    return 0;
}