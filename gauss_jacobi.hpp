#ifndef GAUSS_JACOBI_HPP
#define GAUSS_JACOBI_HPP

#include "useful_functions.hpp"

Vector gauss_jacobi(const Matrix& A, const Vector& b, double epsilon, size_t max_iter)
{
    size_t n = A.size();
    Vector x(n, 0.0);
    Vector x_prev = x;

    for (size_t iter = 0; iter < max_iter; ++iter) {
        for (size_t i = 0; i < n; ++i) {
            double sigma = 0.0;
            for (size_t j = 0; j < n; ++j) {
                if (j != i) {
                    sigma += A[i][j] * x_prev[j];
                }
            }
            x[i] = (b[i] - sigma) / A[i][i];
        }

        if (norma(x_prev, x) < epsilon) {
            return x;
        }

        x_prev = x;
    }

    return x;
}

#endif // GAUSS_JACOBI_HPP
