#include <iostream>
#include<fstream>
#include<windows.h>

using namespace std;
typedef struct {

    char * nombre;
    char sexo;
    int peso;

} Nacimientos;

Nacimientos *naci;
//void vaciar(char temp[]);
//void copiar(char temp[], int);

void copiar(char temp[], int i);

void vaciar(char temp[]);

int main() {
    int i, j;
    char aux;
    char temp[200];
    int cont = 0;
    FILE *f;
    f = fopen("nacimientos.csv", "r");
    if (f == NULL) {
        printf("no se ha podido abrir. \n");
        exit(1);
    }

    while (!feof(f)) {
        fgets(temp, 200, f);
        cont++;
    }
    rewind(f);
    naci = (Nacimientos *) malloc(cont * sizeof(Nacimientos));
    if (naci == NULL) {
        printf("no se ha podido reservar espacio de memoria \n");
        exit(1);
    }
    for (i = 0; i < !feof(f); ++i) {
        vaciar(temp);
        aux = '0';
        for (j = 0; aux != ','; j++) {
            aux = fgetc(f);
            if (aux != ',') {
                temp[j] = aux;
            }
        }
        copiar(temp, i);

        fgets(temp,50,f);
        naci[i].peso= atoi(temp);

        printf(" hola  %s %s %i \n",naci[i].nombre,naci[i].sexo,naci[i].peso);
    }
    system("pause");
    return 0;
}

void vaciar(char temp[]) {
    int i;
    for (int j = 0; j < 200; ++j) {
        temp[i] = '\0';
    }
}


void copiar(char temp[], int i) {
    int N = strlen(temp) + 1;
    naci[i].nombre = (char*)malloc(N * sizeof(char));
    if (naci[i].nombre == NULL) {
        printf("no se ha podido reservar memoria \n");
        exit(1);
    }
    strcpy(naci[i].nombre, temp);
}


