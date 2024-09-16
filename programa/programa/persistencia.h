#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include "pessoa.h"

void salvarDados(pessoa* pessoas, int tamanho);
int carregarDados(pessoa** pessoas);

#endif