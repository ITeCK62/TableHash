#include <stdio.h>

int lettreMin(char c){
    if(c > 96 && c < 123){
        printf("Est minuscule\n");
        return 1;
    }
    printf("N'est pas minuscule\n");
    return 0;
}

int lettreMaj(char c){
    if(c > 64 && c < 91){
        printf("Est majuscule\n");
        return 1;
    }
    printf("N'est pas majuscule\n");
    return 0;
}

int estLettre(char c){
    return(lettreMaj(c) || lettreMin(c));
}

int convMinMaj(char * c){
    printf("01- %c\n", *c);
    *c -= 32;
    printf("02- %c\n", *c);
}

int lectureFichier(){
    FILE* f = NULL;
    char c;
    f=fopen("/home/julien/Documents/test.txt","r");
    while(!feof(f)){
        c=getc(f);
        if(estLettre(c)) {
            printf("%c ",c);
            convMinMaj(&c);
            printf("\n");
        } 
        else{
                printf("Non Lettre :%c \n",c);
        }
        fclose(f);
    }
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