#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pessoa.h"
#include "calculo_investimento.h"
#include "gerenciamento_investimento.h"
#include "persistencia.h"

int main() {
    pessoa* pessoas = NULL;
    int tamanho = 0;

    tamanho = carregarDados(&pessoas);

    int escolha;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Cadastrar novo investimento\n");
        printf("2. Mostrar investimentos\n");
        printf("3. Sair e salvar dados\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        if (escolha == 1) {
            tamanho++;
            pessoas = realloc(pessoas, tamanho * sizeof(pessoa));

            printf("Digite o dia de cadastro: ");
            scanf("%d", &pessoas[tamanho - 1].data.dia);
            printf("Digite o mês de cadastro: ");
            scanf("%d", &pessoas[tamanho - 1].data.mes);
            printf("Digite o ano de cadastro: ");
            scanf("%d", &pessoas[tamanho - 1].data.ano);

            printf("Digite o valor: ");
            scanf("%lf", &pessoas[tamanho - 1].valor);

            printf("Digite o tipo de investimento: ");
            scanf("%s", pessoas[tamanho - 1].tipo);

            printf("Digite a data de vencimento (dia, mês, ano): ");
            scanf("%d %d %d", &pessoas[tamanho - 1].vencimento.dia, &pessoas[tamanho - 1].vencimento.mes, &pessoas[tamanho - 1].vencimento.ano);

            atualizarInvestimento(&pessoas[tamanho - 1]);
            printf("Investimento cadastrado com sucesso!\n");

        } else if (escolha == 2) {
            for (int i = 0; i < tamanho; i++) {
                ImprimePessoa(pessoas[i]);
            }

        } else if (escolha == 3) {
            salvarDados(pessoas, tamanho);
            break;
        } else {
            printf("Opção inválida, tente novamente.\n");
        }
    }

    free(pessoas);
    return 0;
}