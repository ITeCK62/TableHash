/*
 * TP4 Algo4
 *
 * @author Julien Cointe
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure pour représenter un noeud dans une liste chaînée
typedef struct Node {
    // Chaîne de caractères représentant le mot
    char word[50];
    // Entier représentant le nombre d'occurrences du mot
    int count;
    // Pointeur vers le prochain noeud dans la liste chaînée
    struct Node* next;
} Node;

// Fonction pour créer un nouveau noeud
Node* createNode(char* word) {
    // Allouer de la mémoire pour le nouveau noeud
    Node* newNode = (Node*) malloc(sizeof(Node));
    // Copier le mot dans le nouveau noeud
    strcpy(newNode->word, word);
    // Initialiser le compteur du nouveau noeud à 1
    newNode->count = 1;
    // Initialiser le pointeur suivant du nouveau noeud à NULL
    newNode->next = NULL;
    // Retourner le nouveau noeud
    return newNode;
}

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
    f=fopen("./test.txt","r");

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

// Fonction pour insérer un noeud dans la liste
void insertNode(Node** head, char* word) {
    // Si la liste est vide
    if (*head == NULL) {
        // Créer un nouveau nœud
        *head = createNode(word);
        return;
    }

    // Pointeur pour parcourir la liste
    Node* current = *head;

    // Tant que le noeud suivant n'est pas NULL
    while (current->next != NULL) {
        // Si le mot du noeud actuel est identique au mot à insérer
        if (strcmp(current->word, word) == 0) {
            // Incrémenter le compteur du noeud actuel
            current->count++;
            return;
        }
        // Passer au noeud suivant
        current = current->next;
    }

    // Si le mot du noeud actuel est égal au mot à insérer
    if (strcmp(current->word, word) == 0) {
        // Incrémenter le compteur du noeud actuel
        current->count++;
        return;
    }

    // Si le mot à insérer est inférieur au mot du noeud actuel
    if (strcmp(word, current->word) < 0) {
        // Créer un nouveau noeud
        Node* newNode = createNode(word);
        // Le nouveau noeud pointe vers le noeud actuel
        newNode->next = *head;
        // Le noeud actuel pointe vers le nouveau noeud
        *head = newNode;
    } else {
        // Le noeud actuel pointe vers le nouveau noeud
        current->next = createNode(word);
    }
}

// Fonction pour afficher la liste
void printList(Node* head) {
    // Pointeur pour parcourir la liste
    Node* current = head;
    // Tant que le pointeur actuel n'est pas NULL
    while (current != NULL) {
        // Afficher le mot et le compteur
        printf("%s - %d\n", current->word, current->count);
        // Passer au nœud suivant
        current = current->next;
    }
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
    Node* head = NULL;
    insertNode(&head, "banane");
    insertNode(&head, "pomme");
    insertNode(&head, "banane");
    insertNode(&head, "orange");
    insertNode(&head, "banane");
    printList(head);
    return 0;
}