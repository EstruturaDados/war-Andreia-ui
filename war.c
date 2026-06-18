#include <stdio.h>
#include <string.h>

#define MAX_TERRITORIOS 5
#define MAX_NOME 50
#define MAX_COR 30

// Definição da struct
typedef struct {
    char nome[MAX_NOME];
    char corExercito[MAX_COR];
    int tropas;
} Territorio;

// Função auxiliar para remover o '\n' do fgets
void removerQuebraLinha(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int main() {
    Territorio territorios[MAX_TERRITORIOS];
    
    printf("=== Cadastro Inicial dos Territórios ===\n\n");

    for (int i = 0; i < MAX_TERRITORIOS; i++) {
        printf("Território %d:\n", i + 1);

        // Nome do território
        printf("Digite o nome: ");
        fgets(territorios[i].nome, MAX_NOME, stdin);
        removerQuebraLinha(territorios[i].nome);

        // Cor do exército
        printf("Digite a cor do exército: ");
        fgets(territorios[i].corExercito, MAX_COR, stdin);
        removerQuebraLinha(territorios[i].corExercito);

        // Número de tropas
        printf("Digite o número de tropas: ");
        scanf("%d", &territorios[i].tropas);
        getchar(); // consome o \n deixado pelo scanf

        printf("\n");
    }

    // Exibição do estado atual do mapa
    printf("\n=== Estado Atual do Mapa ===\n\n");
    for (int i = 0; i < MAX_TERRITORIOS; i++) {
        printf("Território %d:\n", i + 1);
        printf("  Nome: %s\n", territorios[i].nome);
        printf("  Cor do Exército: %s\n", territorios[i].corExercito);
        printf("  Tropas: %d\n\n", territorios[i].tropas);
    }

    return 0;
}
