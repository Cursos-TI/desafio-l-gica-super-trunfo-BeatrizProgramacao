#include <stdio.h>

typedef struct {
    char estado[50];
    char codigo[10];
    char cidade[50];
    long int populacao;
    float area;
    double pib;
    int pontosTuristicos;
} Carta;

int main() {
    Carta c1, c2;

    printf("=== Cadastro da Carta 1 ===\n");
    printf("Estado: ");
    fgets(c1.estado, 50, stdin);
    printf("Código da carta: ");
    fgets(c1.codigo, 10, stdin);
    printf("Cidade: ");
    fgets(c1.cidade, 50, stdin);
    printf("População: ");
    scanf("%ld", &c1.populacao);
    printf("Área (km²): ");
    scanf("%f", &c1.area);
    printf("PIB (em bilhões): ");
    scanf("%lf", &c1.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &c1.pontosTuristicos);
    getchar(); // Limpar buffer

    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Estado: ");
    fgets(c2.estado, 50, stdin);
    printf("Código da carta: ");
    fgets(c2.codigo, 10, stdin);
    printf("Cidade: ");
    fgets(c2.cidade, 50, stdin);
    printf("População: ");
    scanf("%ld", &c2.populacao);
    printf("Área (km²): ");
    scanf("%f", &c2.area);
    printf("PIB (em bilhões): ");
    scanf("%lf", &c2.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &c2.pontosTuristicos);

    // Exibição das cartas
    printf("\n=== Cartas Cadastradas ===\n");
    printf("\nCarta 1: %s - %sCidade: %sPopulação: %ld\nÁrea: %.2f km²\nPIB: %.2lf bilhões\nPontos Turísticos: %d\n",
           c1.estado, c1.codigo, c1.cidade, c1.populacao, c1.area, c1.pib, c1.pontosTuristicos);
    printf("\nCarta 2: %s - %sCidade: %sPopulação: %ld\nÁrea: %.2f km²\nPIB: %.2lf bilhões\nPontos Turísticos: %d\n",
           c2.estado, c2.codigo, c2.cidade, c2.populacao, c2.area, c2.pib, c2.pontosTuristicos);

    // Comparação pelo atributo população
    printf("\n=== Comparação ===\n");
    if (c1.populacao > c2.populacao) {
        printf("A carta vencedora é a da cidade %s com população de %ld!\n", c1.cidade, c1.populacao);
    } else if (c2.populacao > c1.populacao) {
        printf("A carta vencedora é a da cidade %s com população de %ld!\n", c2.cidade, c2.populacao);
    } else {
        printf("Empate! Ambas as cidades têm a mesma população.\n");
    }

    return 0;
}