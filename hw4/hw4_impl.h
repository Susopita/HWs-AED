#ifndef HW4_IMPL_H
#define HW4_IMPL_H

#include <string>
#include <vector>

#include "hw4.h"

vector<int> stringMatch_naive(string const& text, string const& pattern) {
  // Implemente aqui el método mas ingenuo para resolver el problema de string
  // matching.
  vector<int> res;

  if ( pattern.size() > text.size() ) return res;
  if ( pattern.size() == 0 or text.size() == 0) return res;


  size_t it = 0;
  while ( it != string::npos ) {
    it = text.find( pattern, it );
    res.emplace_back(it);
    if ( it != string::npos )
      it++;
  }

  res.pop_back();

  return res;
}

// ----------------------------------------------------------------------

int initHash( string s, int in, int sz, int d, int q ) {
  int h = 0;
  for (int i=0; i < sz; i++) {
  	h = (h * d + s[in + i]) % q;
  }
  return h;
}

int reHash( int hcur, char c, char nc, int h, int d, int q ) {
  int nh = (d* ( hcur - c * h ) + nc ) % q;
  return nh < 0 ? nh + q : nh;
}

vector<int> stringMatch_RabinKarp(string const& text, string const& pattern) {
  // Implemente aqui el algoritmo de Rabin-Karp para resolver el problema
  // de string matching.
  vector<int> res;

  if ( pattern.size() > text.size() ) return res;
  if ( pattern.size() == 0 or text.size() == 0) return res;

  int n = text.size();
  int m = pattern.size();

  // Algoritmo de Rabin-Karp

  int d = 256; // cantidad de caracteres ASCCI
  int q = 3; // numero primo

  int h = 1; // h = pow(d, M-1)%q
  for (int i = 0; i < m - 1; i++) {
    h = (h * d) % q;
  }

  // Hashing
  int p = initHash(pattern, 0, m,d,q);
  int t = initHash(text, 0, m,d,q);

  // Comparacion
  for (int i = 0; i <= n - m; i++) {
    // Si los hash son iguales, verifica caracter x caracter
    if (p == t) {
   	  bool match = true;
      for (int j = 0; j < m; j++) {
        if (text[i + j] != pattern[j]) {
          match = false;
          break;
        }
      }
      // Si coinciden se guarda el index
      if (match)
        res.push_back(i);
    }

    // reHashing para el siguiente substring
    if (i < n - m) {
      t = reHash(t, text[i], text[i + m], h, d, q);
    }
  }

  return res;
}

// ----------------------------------------------------------------------

vector<int> vecPrefSuf(string pattern) {
    int sz = pattern.size();
    vector<int> v(sz, 0);
    int k = 0;

    for (int i = 1; i < sz;) {
        if (pattern[i] == pattern[sz]) {
          k++;
          v[i] = k;
          i++;
        } else {
          if (k != 0) {
            k = v[k - 1];
          } else {
            v[i] = 0;
            i++;
          }
        }
    }

    return v;
}


vector<int> stringMatch_KnuthMorrisPratt(string const& text, string const& pattern) {
  // Implemente aqui el algoritmo de Knuth-Morris-Pratt para resolver el
  // problema de string matching.
  vector<int> res;

  if ( pattern.size() > text.size() ) return res;
  if ( pattern.size() == 0 or text.size() == 0) return res;

  int n = text.size();
  int m = pattern.size();

  vector<int> v = vecPrefSuf(pattern);

  int t = 0;
  int p = 0;

  while (t < n) {
    if (text[t] == pattern[p]) {
      t++;
      p++;
    }

    // Si hay coincidencia, guarda el index y sigue buscando en v
    if (p == m) {
      res.push_back(t - p);
      p = v[p - 1];
    } else if (t < n && text[t] != pattern[p]) { // Desajuste
      if (p != 0) {
        p = v[p - 1]; // Retroceder en v
      } else {
        t++; // Moverse al siguiente carácter en el texto
      }
    }
  }

  return res;
}

#endif
