#ifndef CRAMER_METHOD_HPP
#define CRAMER_METHOD_HPP

#include "useful_functions.hpp"
#include "determinant_gauss_jordan.hpp"

Vector cramer_method(Matrix C, Vector v) {
    int n = C.size();
    
    double detC = determinant_gauss_jordan(C);
    if (detC == 0) {
        throw std::runtime_error("O sistema não tem solução única (determinante é zero).\n");
    }
    
    Vector p(n);
    for (int i = 0; i < n; i++) {
        Matrix Ci = C;
        for (int j = 0; j < n; j++) {
            Ci[j][i] = v[j];
        }
        p[i] = determinant_gauss_jordan(Ci) / detC;
    }
    return p;
}

#endif // CRAMER_METHOD_HPP