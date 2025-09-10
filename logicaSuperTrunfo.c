#include <stdio.h>
#include <string.h>

typedef struct {
    char estado[50];
    char codigo[10];
    char cidade[50];
    long int populacao;
    float area;
    double pib;
    int pontosTuristicos;
} Carta;

void removerQuebraLinha(char str[]) {
    size_t len = strlen(str);
    if(len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

// Função para exibir uma carta
void exibirCarta(Carta c, int num) {
    printf("\nCarta %d: %s - %s\nCidade: %s\nPopulação: %ld\nÁrea: %.2f km²\nPIB: %.2lf bilhões\nPontos Turísticos: %d\n",
           num, c.estado, c.codigo, c.cidade, c.populacao, c.area, c.pib, c.pontosTuristicos);
}

// Função para comparar cartas de acordo com o atributo escolhido
void compararCartas(Carta c1, Carta c2, int atributo) {
    switch(atributo) {
        case 1: // População
            if (c1.populacao > c2.populacao)
                printf("A carta vencedora é a cidade %s com população de %ld!\n", c1.cidade, c1.populacao);
            else if (c2.populacao > c1.populacao)
                printf("A carta vencedora é a cidade %s com população de %ld!\n", c2.cidade, c2.populacao);
            else
                printf("Empate! Ambas as cidades têm a mesma população.\n");
            break;
        case 2: // Área
            if (c1.area > c2.area)
                printf("A carta vencedora é a cidade %s com área de %.2f km²!\n", c1.cidade, c1.area);
            else if (c2.area > c1.area)
                printf("A carta vencedora é a cidade %s com área de %.2f km²!\n", c2.cidade, c2.area);
            else
                printf("Empate! Ambas as cidades têm a mesma área.\n");
            break;
        case 3: // PIB
            if (c1.pib > c2.pib)
                printf("A carta vencedora é a cidade %s com PIB de %.2lf bilhões!\n", c1.cidade, c1.pib);
            else if (c2.pib > c1.pib)
                printf("A carta vencedora é a cidade %s com PIB de %.2lf bilhões!\n", c2.cidade, c2.pib);
            else
                printf("Empate! Ambas as cidades têm o mesmo PIB.\n");
            break;
        case 4: // Pontos Turísticos
            if (c1.pontosTuristicos > c2.pontosTuristicos)
                printf("A carta vencedora é a cidade %s com %d pontos turísticos!\n", c1.cidade, c1.pontosTuristicos);
            else if (c2.pontosTuristicos > c1.pontosTuristicos)
                printf("A carta vencedora é a cidade %s com %d pontos turísticos!\n", c2.cidade, c2.pontosTuristicos);
            else
                printf("Empate! Ambas as cidades têm o mesmo número de pontos turísticos.\n");
            break;
        default:
            printf("Atributo inválido!\n");
    }
}

int main() {
    Carta c1, c2;
    int continuar = 1;

    while (continuar) {
        // Cadastro da Carta 1
        printf("\n=== Cadastro da Carta 1 ===\n");
        printf("Estado: "); fgets(c1.estado, 50, stdin); removerQuebraLinha(c1.estado);
        printf("Código da carta: "); fgets(c1.codigo, 10, stdin); removerQuebraLinha(c1.codigo);
        printf("Cidade: "); fgets(c1.cidade, 50, stdin); removerQuebraLinha(c1.cidade);
        printf("População: "); scanf("%ld", &c1.populacao);
        printf("Área (km²): "); scanf("%f", &c1.area);
        printf("PIB (em bilhões): "); scanf("%lf", &c1.pib);
        printf("Número de pontos turísticos: "); scanf("%d", &c1.pontosTuristicos);
        getchar(); // limpar buffer

        // Cadastro da Carta 2
        printf("\n=== Cadastro da Carta 2 ===\n");
        printf("Estado: "); fgets(c2.estado, 50, stdin); removerQuebraLinha(c2.estado);
        printf("Código da carta: "); fgets(c2.codigo, 10, stdin); removerQuebraLinha(c2.codigo);
        printf("Cidade: "); fgets(c2.cidade, 50, stdin); removerQuebraLinha(c2.cidade);
        printf("População: "); scanf("%ld", &c2.populacao);
        printf("Área (km²): "); scanf("%f", &c2.area);
        printf("PIB (em bilhões): "); scanf("%lf", &c2.pib);
        printf("Número de pontos turísticos: "); scanf("%d", &c2.pontosTuristicos);
        getchar(); // limpar buffer

        // Exibir cartas
        printf("\n=== Cartas Cadastradas ===\n");
        exibirCarta(c1, 1);
        exibirCarta(c2, 2);

        // Escolha do atributo
        int escolha;
        printf("\nEscolha o atributo para comparar:\n");
        printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n");
        printf("Digite o número do atributo: ");
        scanf("%d", &escolha);
        getchar(); // limpar buffer

        // Comparação
        printf("\n=== Resultado ===\n");
        compararCartas(c1, c2, escolha);

        // Perguntar se quer continuar jogando
        printf("\nDeseja jogar outra rodada? (1 = Sim / 0 = Não): ");
        scanf("%d", &continuar);
        getchar(); // limpar buffer
    }

    printf("\nObrigado por jogar o Super Trunfo de Cidades!\n");
    return 0;
}