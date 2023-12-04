#ifndef GAUSS_SEIDEL_HPP
#define GAUSS_SEIDEL_HPP

#include "useful_functions.hpp"

Vector gauss_seidel(const Matrix& A, const Vector& b, double epsilon, size_t max_iter)
{   
    size_t n = A.size();
    size_t k = 0;
    
    Vector x (n, 0.0);
    Vector v (n, 0.0);
    Vector t (b);
    
    Matrix M (A);
    
    for(size_t i = 0; i < n; i++) {
        double r = 1.0 / M[i][i];

	for(size_t j = 0; j < n; j++)
	    if(i != j) M[i][j] *= r;
        
        t[i] *= r;
        x[i] = t[i];
    }
    
    double norm;

    do {
	for(size_t i = 0; i < n; i++) {
            double soma = 0;
            for(size_t j = 0; j < n; j++)
                if(i != j) soma += M[i][j] * x[j];

            v[i] = x[i];
            x[i] = t[i] - soma;
        }

        norm = norma(v, x);

	k++;
    } while (norm > epsilon && k < max_iter);

    return x;
}

#endif // GAUSS_SEIDEL_HPP
