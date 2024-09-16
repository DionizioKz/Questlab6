#include <stdio.h>
#include "pessoa.h"

// Função para imprimir os dados de uma pessoa
void ImprimePessoa(pessoa p) {
    printf("Data de Cadastro: %d/%d/%d  Valor: %.2lf  Tipo: %s  Nome: %s\n",
           p.data.dia, p.data.mes, p.data.ano, p.valor, p.tipo, p.nome);
    printf("Data de Vencimento: %d/%d/%d\n", p.vencimento.dia, p.vencimento.mes, p.vencimento.ano);
    printf("Taxa de Juros: %.2lf%%  Valor Aplicado: %.2lf  Imposto: %.2lf\n",
           p.taxajuros, p.valorApli, p.Imposto);
}