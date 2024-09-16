#include <math.h>
#include <time.h>
#include "pessoa.h"

// Função para calcular o valor futuro com base no valor inicial, taxa de juros e anos
double calculaValorFuturo(double valor, double taxa, int anos) {
    return valor * pow(1 + taxa / 100.0, anos);
}

// Função para atualizar o imposto de um investimento com base no tempo desde a aplicação
void atualizarInvestimento(pessoa* p) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    int diaAtual = tm.tm_mday;
    int mesAtual = tm.tm_mon + 1;
    int anoAtual = tm.tm_year + 1900;

    int diasDesdeAplicacao = (anoAtual - p->data.ano) * 365 + (mesAtual - p->data.mes) * 30 + (diaAtual - p->data.dia);
    diasDesdeAplicacao += (anoAtual - p->data.ano) / 4;

    if (diasDesdeAplicacao <= 180) {
        p->Imposto = 0.225 * (p->valorApli - p->valor) + 10.0;
    } else if (diasDesdeAplicacao <= 360) {
        p->Imposto = 0.20 * (p->valorApli - p->valor) + 10.0;
    } else if (diasDesdeAplicacao <= 720) {
        p->Imposto = 0.175 * (p->valorApli - p->valor) + 10.0;
    } else {
        p->Imposto = 0.15 * (p->valorApli - p->valor) + 10.0;
    }
}