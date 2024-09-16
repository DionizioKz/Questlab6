#ifndef PESSOA_H
#define PESSOA_H

typedef struct {
    int ano;
    int mes;
    int dia;
} Data;

typedef struct {
    Data data;
    Data vencimento;
    double valor;
    char tipo[50];
    char nome[30];
    double taxajuros;
    double valorApli;
    double Imposto;
} pessoa;

void ImprimePessoa(pessoa p);
double calculaValorFuturo(double valor, double taxa, int anos);
void atualizarInvestimento(pessoa* p);

#endif