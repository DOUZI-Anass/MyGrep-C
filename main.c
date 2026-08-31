#include <stdio.h>
#include <string.h>
#include <ctype.h>


FILE *ouvertureFichier(char *fichierArg){
    FILE *fichier = fopen(fichierArg, "r");

    if (fichier == NULL){
        printf("Erreur : impossible d'ouvrir le fichier\n");
        return NULL;
    }
    return fichier;
}


int ignorerMajMin(const char *texte, const char *mot){
    char textTemp[1024];
    char motTemp[1024];

    for(int i = 0 ; i < strlen(texte) ; i++){
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


void rechercher(FILE *fichier, char *motChercher, int optionN, int optionI, int optionV){
    char ligne[1024];
    int count = 1;
    int nbTrv = 0;
    while (fgets(ligne, sizeof(ligne), fichier) != NULL){
        int trouver;
        if(optionI){
            trouver = ignorerMajMin(ligne,motChercher);
        }
        else{
            trouver = strstr(ligne,motChercher) != NULL;
        }
        if(optionV){
            trouver = !trouver;
        }
        if (trouver){
            if (optionN){
                printf("%d. %s", count, ligne);
            }
            else{
                printf("%s", ligne);
            }
        nbTrv++;
        }
        
        count++;
    }
    if(nbTrv == 0){
        printf("Aucun mot trouvé \n");
    }
}


int main(int argc, char *argv[]){
    char *fichierArg;
    char *motChercher;

    int optionN = 0;
    int optionI = 0;
    int optionV = 0;

    if (argc < 3){
        printf("Erreur : Mauvais nombre d'argument !");
        return 0;
    }
    else{
        motChercher = argv[argc - 2];
        fichierArg = argv[argc - 1];
        
        for(int i = 1; i < argc-2; i++){
            if(strcmp(argv[i], "-n") == 0){
                optionN = 1;
            }
            else if(strcmp(argv[i], "-i") == 0){
                optionI = 1;
            }
            else if (strcmp(argv[i], "-v") == 0){
                optionV = 1;
            }
            else{
                printf("Erreur : Mauvais argument \n");
                return 0;
            }
        }
    }

    FILE *fichier = ouvertureFichier(fichierArg);
    if (fichier ==NULL){ 
        return 1;
    }

    rechercher(fichier,motChercher,optionN,optionI, optionV);
    
    printf("\n");
    
    fclose(fichier);
    
    return 0;
}