#include <stdio.h>
#include <stdlib.h>
#include "persistencia.h"

void salvarDados(pessoa* pessoas, int tamanho) {
    FILE *file = fopen("investimentos.txt", "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para salvar dados!\n");
        return;
    }

    for (int i = 0; i < tamanho; i++) {
        fprintf(file, "%d %d %d %d %d %d %lf %s %s %lf %lf %lf\n",
            pessoas[i].data.dia, pessoas[i].data.mes, pessoas[i].data.ano,
            pessoas[i].vencimento.dia, pessoas[i].vencimento.mes, pessoas[i].vencimento.ano,
            pessoas[i].valor, pessoas[i].tipo, pessoas[i].nome,
            pessoas[i].taxajuros, pessoas[i].valorApli, pessoas[i].Imposto);
    }

    fclose(file);
    printf("Dados salvos com sucesso!\n");
}

int carregarDados(pessoa** pessoas) {
    FILE *file = fopen("investimentos.txt", "r");
    if (file == NULL) {
        printf("Nenhum dado encontrado, iniciando sem dados carregados.\n");
        return 0;
    }

    int tamanho = 0;
    pessoa buffer;
    while (fscanf(file, "%d %d %d %d %d %d %lf %s %s %lf %lf %lf",
            &buffer.data.dia, &buffer.data.mes, &buffer.data.ano,
            &buffer.vencimento.dia, &buffer.vencimento.mes, &buffer.vencimento.ano,
            &buffer.valor, buffer.tipo, buffer.nome,
            &buffer.taxajuros, &buffer.valorApli, &buffer.Imposto) != EOF) {
        tamanho++;
        *pessoas = realloc(*pessoas, tamanho * sizeof(pessoa));
        (*pessoas)[tamanho - 1] = buffer;
    }

    fclose(file);
    printf("%d registros carregados com sucesso!\n", tamanho);
    return tamanho;
}