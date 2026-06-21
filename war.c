#include <stdio.h>
#include <string.h>
typedef struct {
    int id;
    int tropas;
    int conquistado; // 0 = não, 1 = sim
} Territorio;
Territorio* criarTerritorios(int n) {
    Territorio* t = (Territorio*) calloc(n, sizeof(Territorio));
    for (int i = 0; i < n; i++) {
        t[i].id = i + 1;
        t[i].tropas = 5; // valor inicial
        t[i].conquistado = 0;
    }
    return t;
}
void batalha(Territorio* atacante, Territorio* defensor) {
    int dadoAtq = rand() % 6 + 1; // 1 a 6
    int dadoDef = rand() % 6 + 1;

    printf("Atacante (%d tropas) rolou: %d\n", atacante->tropas, dadoAtq);
    printf("Defensor (%d tropas) rolou: %d\n", defensor->tropas, dadoDef);

    if (dadoAtq >= dadoDef) {
        defensor->tropas--;
        printf("Defensor perdeu 1 tropa!\n");
        if (defensor->tropas <= 0) {
            defensor->conquistado = 1;
            printf("Território %d foi conquistado!\n", defensor->id);
        }
    } else {
        printf("Defensor resistiu ao ataque!\n");
    }
}
int main() {
    srand(time(NULL));
    int n = 5;
    Territorio* territorios = criarTerritorios(n);

    int atq, def;
    while (1) {
        printf("\nEscolha atacante (1-5) e defensor (1-5): ");
        scanf("%d %d", &atq, &def);

        if (atq < 1 || atq > n || def < 1 || def > n || atq == def) {
            printf("Entrada inválida!\n");
            continue;
        }

        batalha(&territorios[atq-1], &territorios[def-1]);

        // Mostrar estado atual
        for (int i = 0; i < n; i++) {
            printf("Território %d: %d tropas %s\n",
                   territorios[i].id,
                   territorios[i].tropas,
                   territorios[i].conquistado ? "(CONQUISTADO)" : "");
        }
    }

    free(territorios);
    return 0;
}




