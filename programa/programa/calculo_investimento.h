// calculo_investimento.h
#ifndef CALCULO_INVESTIMENTO_H
#define CALCULO_INVESTIMENTO_H

#include "pessoa.h"

double calculaValorFuturo(double valor, double taxa, int anos);
void atualizarInvestimento(pessoa* p);

#endif