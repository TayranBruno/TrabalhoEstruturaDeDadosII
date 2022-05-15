#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<ctype.h>
#include<time.h>

using namespace std;


int valoresAleatorios(int vetor[], int quantidadeNumero){

        for (int i = 0; i < quantidadeNumero; i++){
        vetor[quantidadeNumero] = rand() % quantidadeNumero + 1;
        }
            return(vetor[quantidadeNumero]);

}
void troca(int vetor[], int a, int b) {
    int aux = vetor[a];
    vetor[a] = vetor[b];
    vetor[b] = aux;
}
int particiona(int vetor[], int s, int e) {

    int pivot = vetor[s];
    int i = s;
    for (int j = s + 1; j <= e; j++) {
        if (vetor[j] <= pivot) {
            i++;
            troca(vetor, i, j);
        }
    }
    troca(vetor, s, i);
    return i;
}
int quickSort(int vetor[], int s, int e) {
    if (s < e) {
        int p = particiona(vetor, s, e);

        quickSort(vetor, s, p - 1);
        quickSort(vetor, p + 1, e);
    }
}
void merge(int vetor[], int s, int m, int e) {
    int tmp[(e - s) + 1];
    int i = s, j = m + 1, k = 0;
    while (i <= m && j <= e) {
        if (vetor[i] < vetor[j]) {
            tmp[k++] = vetor[i++];
        } else {
            tmp[k++] = vetor[j++];
        }
    }
    for (; i <= m; i++, k++) {
        tmp[k] = vetor[i];
    }
    for (; j <= e; j++, k++) {
        tmp[k] = vetor[j];
    }
    for (i = s, k = 0; i <= e; i++, k++) {
        vetor[i] = tmp[k];
    }
}
void mergeSort(int vetor[], int s, int e) {
    if (s < e) {
        int m = (s + e) / 2;
        mergeSort(vetor, s, m);
        mergeSort(vetor, m + 1, e);
        merge(vetor, s, m, e);
    }
}

int ordenarValores(int vetor[], int quantidadeNumero){
    for (int i = 0; i < quantidadeNumero; i++){
        printf("\t %d",vetor[quantidadeNumero]);
    }
}

int buscaSequencial(int vetor[], int quantidadeNumero, int buscar) {
    for (int i = 0; i < quantidadeNumero; i++) { // O(n)
        if (vetor[i] == buscar) {
            return i;
        }
    }
    return -1;
}

int buscaBinaria(int vetor[], int n, int buscar) { // O(log n)
    int inicio = 0, fim = buscar - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (buscar == vetor[meio]) {
            return meio;
        } else if (buscar > vetor[meio]) {
            inicio = meio + 1;
        } else if (buscar < vetor[meio]) {
            fim = meio - 1;
        }
    }
}

void imprimirVetor(int vetor[], int quantidadeNumero) {
    for (int i = 0; i < quantidadeNumero; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}
void menu(){
    printf("*******MENU*******\n");
    printf("A - GERAR VETOR\n");
    printf("B - ORDENAR VETOR\n");
    printf("C - BUSCA SEQUENCIAL\n");
    printf("D - BUSCA BINARIA\n");
    printf("E - SAIR\n");
}
int escolha(int vetor[],int quantidadeNumero, bool quit_menu){
char opcao , mous;
    menu();
    while(!quit_menu){
    scanf("%c", &opcao);
    opcao = tolower(opcao);
        switch (opcao){
             case 'a':
                        printf("Digite a quantidade de valor que deseja gerar: ");
                        scanf("%d",&quantidadeNumero);
                        printf("\n\n\t\t\t\Gerando valores aleatorios\n");
                        valoresAleatorios(vetor,quantidadeNumero);
                        imprimirVetor(vetor, quantidadeNumero);

                        break;
            case 'b':
                            printf("\n\n\t\t\t\Ordenando vetores\n");
                            printf("\n\t\t\tq _Ordenacao pelo metodo quick");
                            printf("\n\t\t\tm _Ordenacao pelo metodo marge");
                            scanf("%c", &mous);
                            mous = tolower(mous);
                                switch(mous)
                                case 'q':
                                        quickSort(vetor, 0, 1);
                                        imprimirVetor(vetor, quantidadeNumero);

                                    break;
                                case 'm':
                                        mergeSort(vetor, 0, quantidadeNumero - 1);
                                        imprimirVetor(vetor, quantidadeNumero);

                                    break;
                            ordenarValores(vetor, quantidadeNumero);
                            break;


            case 'c':
                            printf("\n\n\t\t\t\Busca sequencial\n");
                            break;


            case 'd':
                            printf("\n\n\t\t\t\Busca binaria\n");

                            break;

            case 'e':
                            printf("\n\n\t\t\t\Saindo do programa\n");
                            quit_menu= true;
                            break;

                }

    }
}

int main(){
    srand(time(NULL));
    int quantidadeNumero;
    char opcao;
    bool quit_menu;
    int vetor[quantidadeNumero];
    escolha(vetor,quantidadeNumero,quit_menu);

}


