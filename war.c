#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TERRITORIOS 10
#define EXERCITO_VERDE 1
#define EXERCITO_AZUL 2

typedef struct {
    int dono;
    int tropas;
} Territorio;
void inicializarTerritorios(Territorio territorios[], int n);
void mostrarMapa(const Territorio territorios[], int n);
void atacar(Territorio territorios[], int n);
int verificarMissao(const Territorio territorios[], int n, int missao);
int sortearMissao();
void menuPrincipal(Territorio territorios[], int n, int missao);
void inicializarTerritorios(Territorio territorios[], int n) {
    for (int i = 0; i < n; i++) {
        territorios[i].dono = (i % 2 == 0) ? EXERCITO_VERDE : EXERCITO_AZUL;
        territorios[i].tropas = rand() % 5 + 1;
    }
}
int sortearMissao() {
    int missao = rand() % 2; 
    return missao; // 0 = destruir exército verde, 1 = conquistar 3 territórios
}

int verificarMissao(const Territorio territorios[], int n, int missao) {
    if (missao == 0) {
        for (int i = 0; i < n; i++) {
            if (territorios[i].dono == EXERCITO_VERDE) return 0;
        }
        return 1; // missão cumprida
    } else if (missao == 1) {
        int conquistas = 0;
        for (int i = 0; i < n; i++) {
            if (territorios[i].dono == EXERCITO_AZUL) conquistas++;
        }
        return conquistas >= 3;
    }
    return 0;
}
int main() {
    srand(time(NULL));
    Territorio territorios[MAX_TERRITORIOS];
    inicializarTerritorios(territorios, MAX_TERRITORIOS);

    int missao = sortearMissao();
    printf("Missão sorteada: %s\n", missao == 0 ? "Destruir o exército Verde" : "Conquistar 3 territórios");

    mostrarMapa(territorios, MAX_TERRITORIOS);
    menuPrincipal(territorios, MAX_TERRITORIOS, missao);

    return 0;
}
