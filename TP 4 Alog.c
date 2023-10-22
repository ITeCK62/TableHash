#include <stdio.h>

// Fonction pour vérifier si une lettre est minuscule
int lettreMin(char c){
    // Regarde si la lettre est comprise entre 'a' et 'z'
    if(c > 96 && c < 123){
        printf("Est minuscule\n");
        return 1;
    }
    printf("N'est pas minuscule\n");
    return 0;
}

// Fonction pour vérifier si une lettre est majuscule
int lettreMaj(char c){
    // Si la lettre est comprise entre 'A' et 'Z'
    if(c > 64 && c < 91){
        printf("Est majuscule\n");
        return 1;
    }
    printf("N'est pas majuscule\n");
    return 0;
}

// Fonction pour vérifier si un caractère est une lettre
int estLettre(char c){
    return(lettreMaj(c) || lettreMin(c));
}

// Fonction pour convertir une lettre minuscule en majuscule
int convMinMaj(char * c){
    // On affiche la lettre avant la conversion
    printf("01- %c\n", *c);
    // On soustrait 32 à la lettre pour la convertir en majuscule
    *c -= 32;
    // On affiche la lettre après la conversion
    printf("02- %c\n", *c);
}

// Fonction pour lire un fichier
int lectureFichier(){
    // Ouverture du fichier en mode lecture
    FILE* f = NULL;
    f=fopen("/home/julien/Documents/test.txt","r");

    // Vérification de l'ouverture du fichier
    if(f == NULL){
        printf("Erreur lors de l'ouverture du fichier\n");
        return 1;
    }

    // Lecture du fichier caractère par caractère
    char c;
    while(!feof(f)){
        c=getc(f);

        // Vérification si le caractère est une lettre
        if(estLettre(c)) {
            // Affichage du caractère
            printf("%c\n",c);
        } 
        // Si le caractère n'est pas une lettre
        else{
            // Affichage du caractère
            printf("Non Lettre :%c \n",c);
        }
        // Fermeture du fichier
        fclose(f);
    }
    // Retourne 0 si la lecture du fichier s'est bien déroulée
    return 0;
}

int main(){
    char c = 'e';
    /*lettreMin('z');
    lettreMaj('A');
    if(estLettre(';')){
        printf("C'est une lettre\n");
    }
    else{
        printf("Ce n'est pas une lettre\n");
    }
    convMinMaj(&c);*/
    return 0;
}