#include <stdio.h>
#include <string.h>
#include <ctype.h>


FILE *ouvertureFichier(char *fichierArg){
    FILE *fichier = fopen(fichierArg, "r");

    if (fichier == NULL)
    {
        printf("Erreur : impossible d'ouvrir le fichier\n");
        return NULL;
    }
    return fichier;
}


int contientIgnoreCase(const char *texte, const char *mot){
    char textTemp[1024];
    char motTemp[1024];

    for(int i=0;i<strlen(texte);i++){
        textTemp[i] = tolower((unsigned char)texte[i]);
    }
    textTemp[strlen(texte)] = '\0';

    for (int i = 0; i < strlen(mot); i++){
        motTemp[i] = tolower((unsigned char)mot[i]); //unsigned char par sécurité avec tolower
    }
    motTemp[strlen(mot)] = '\0';

    if(strstr(textTemp,motTemp)!=NULL){
        return 1;
    }
    return 0;
}


void rechercher(FILE *fichier, char *motChercher, int optionN, int optionI){
    char ligne[1024];
    int count = 1;

    while (fgets(ligne, sizeof(ligne), fichier) != NULL){
        if(optionI){
            if(contientIgnoreCase(ligne,motChercher) ==1){
                printf("%s",ligne);
            }  
        }
        else if (strstr(ligne, motChercher) != NULL){
            if (optionN){
                printf("%d. %s", count, ligne);
            }
            else{
                printf("%s", ligne);
            }
        }
        
        count++;
    }
}


int main(int argc, char *argv[]){
    char *fichierArg;
    char *motChercher;

    int optionN = 0;
    int optionI = 0;

    if (argc == 3){
        motChercher = argv[1];
        fichierArg = argv[2];
    }
    else if (argc == 4){
        if (strcmp(argv[1], "-n") == 0){
            optionN = 1;
            motChercher = argv[2];
            fichierArg = argv[3];
        }
        else if(strcmp(argv[1], "-i")==0){
            optionI = 1;
            motChercher = argv[2];
            fichierArg = argv[3];
        }
        else{
            printf("Mauvais parametre \n");
            return 1;
        }
    }
    else{
        printf("Mauvais nombre d'arguments\n");
        return 1;
    }

    FILE *fichier = ouvertureFichier(fichierArg);
    if (fichier ==NULL){ 
        return 1;
    }
    rechercher(fichier,motChercher,optionN,optionI);
    printf("\n");
    fclose(fichier);
    return 0;
}