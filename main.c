#include <stdio.h>
#include <stdlib.h>
//Etichette 
#define N 3
#define MAX_NOME 20
#define MAX_DESCRIZIONE 50
//Definizione del record
struct s_ricetta {
    char nome[MAX_NOME+1];
    char descrizione[MAX_DESCRIZIONE+1];
    unsigned int pomodoro;
    unsigned int mozzarella;
    int glutine;
};

typedef struct s_ricetta elenco;

int main(int argc, char** argv) {
    //Dichiarazione variabili
    FILE *pNormale;
    FILE *pSenzaGlutine;
    elenco temp;
    elenco array[N];
    int i,j;
    //Input Ricette
    for(i = 0; i < N; i++) {
        printf("Ricetta %d\n", (i+1));
        printf("Nome : ");
        scanf("\n%[^\n]", array[i].nome);
        printf("Descrizione : ");
        scanf("\n%[^\n]", array[i].descrizione);
        printf("Pomodoro (in grammi) : ");
        scanf("%d", &(array[i].pomodoro));
        printf("Mozzarella (in grammi) : ");
        scanf("%d", &(array[i].mozzarella));
        printf("Glutine (0 = No, 1 = si') : ");
        scanf("%d", &(array[i].glutine));
    }
    //Ordinamento dell'array di record tramite Bubble-Sort
    for(i = 0; i < N-1; i++) {
        for(j = 0; j < N-1-i; j++) {
            if((strcmp(array[j].nome, array[j+1].nome)) > 0) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    
    //Apertura dei file
    pNormale = fopen("normale.csv", "w");
    if(pNormale == NULL) {
        printf("Impossibile creare il file\n");
        exit(1);
    }
    pSenzaGlutine = fopen("senzaglutine.csv", "w");
    if(pSenzaGlutine == NULL) {
        printf("Impossibile creare il file\n");
        exit(2);
    }
    //Smistamento delle ricette sui file appositi
    for(i = 0; i < N; i++) {
        if(array[i].glutine == 0){
        fprintf(pSenzaGlutine, "%s; %s; %d; %d; %d;\n", 
            array[i].nome, 
            array[i].descrizione, 
            array[i].pomodoro, 
            array[i].mozzarella, 
            array[i].glutine);
        }
        else {
            fprintf(pNormale, "%s; %s; %d; %d; %d;\n", 
            array[i].nome, 
            array[i].descrizione, 
            array[i].pomodoro, 
            array[i].mozzarella, 
            array[i].glutine);
        }
            
    }
    
    fclose(pNormale);
    fclose(pSenzaGlutine);
    
    return (EXIT_SUCCESS);
}

