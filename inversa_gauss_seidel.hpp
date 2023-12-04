#ifndef INVERSA_GAUSS_SEIDEL_HPP
#define INVERSA_GAUSS_SEIDEL_HPP

#include "useful_functions.hpp"
#include "gauss_seidel.hpp"

#define MAX_ITER 1000

Matrix inversa_gauss_seidel(const Matrix& A, double epsilon)
{
    size_t n = A.size();
    
    Matrix inversa_A_transposta(n, Vector(n, 0.0));
    Matrix id = identity(n);    

    for (size_t i = 0; i < n; i++) {
        inversa_A_transposta[i] = gauss_seidel(A, id[i], epsilon, MAX_ITER);
    }

    return transpose(inversa_A_transposta);
}

#endif // INVERSA_GAUSS_SEIDEL_HPP
