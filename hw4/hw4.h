#ifndef HW4_H
#define HW4_H

/*******************************************************************************

MODIFIQUE ESTE ARCHIVO Y LA CORRESPONDIENTE IMPLEMENTACIÓN A SU GUSTO.


Los tests que se usarán para calificar esta tarea serán los provistos en el
archivo de tests y muchos otros. El archivo de tests se incluye solo a modo
de referencia, pero no es una version completa de los tests que serán
utilizados.

Todas las funciones listadas en este archivo serán testeadas por el corrector
automático, con el mismo prototipo mostrado en este archivo.

*******************************************************************************/

#include <vector>
#include <string>

using namespace std;

vector<int> stringMatch_naive(string const& text,
                                   string const& pattern);

vector<int> stringMatch_RabinKarp(string const& text,
                                       string const& pattern);

vector<int> stringMatch_KnuthMorrisPratt(string const& text,
                                              string const& pattern);

#include "hw4_impl.h"

#endif
