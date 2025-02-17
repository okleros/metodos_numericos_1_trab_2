#ifndef USEFUL_FUNCTIONS_HPP
#define USEFUL_FUNCTIONS_HPP

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <stdexcept>

typedef std::vector<std::vector<double>> Matrix;
typedef std::vector<double> Vector;

Matrix transpose(const Matrix& M);
Matrix identity(size_t n);
Matrix dot(const Matrix& A, const Matrix& B);
double norma(const Vector& previous_guess, const Vector& current_guess);
void print_matrix(const Matrix& m);
Matrix get_matrix_from_user(size_t n);
Vector get_b_from_user(size_t n);

Matrix transpose(const Matrix& M)
{
    size_t m = M.size();
    size_t n = M[0].size();
    
    Matrix T(n, Vector(m, 0.0));

    for(size_t i = 0; i < n; i++) {
	for(size_t j = 0; j < m; j++) {
	    T[i][j] = M[j][i];
	}
    }

    return T;
}

Matrix identity(size_t n)
{
    Matrix M(n, Vector(n, 0.0));

    for (size_t i = 0; i < n; ++i) {
	for (size_t j = 0; j < n; ++j) {
	    if (i == j) M[i][j] = 1.0;
	}
    }

    return M;
}

double norma(const Vector& previous_guess, const Vector& current_guess) {
    double norma_num = 0;
    double norma_den = 0;

    for (size_t i = 0; i < previous_guess.size(); i++) {
	double temp = std::abs(current_guess[i] - previous_guess[i]);
    
	if (temp > norma_num) norma_num = temp;
	
	if (std::fabs(current_guess[i]) > norma_den) norma_den = std::fabs(current_guess[i]);
    }

    return norma_num / norma_den;
}

Matrix dot(const Matrix& A, const Matrix& B)
{
    size_t m = A.size();
    size_t n = A[0].size();
    size_t p = B.size();
    size_t q = B[0].size();

    if (n != p)
	throw std::runtime_error("ERROR: dimension mismatch (Matrix A columns should equal Matrix B rows).");
    
    Matrix C(m, Vector(q, 0.0));

    for (size_t i = 0; i < m; ++i) {
	for (size_t j = 0; j < q; ++j) {
	    double sum = 0;

	    for (size_t k = 0; k < n; ++k) {
		sum += A[i][k] * B[k][j];
	    }

	    C[i][j] = sum;
	}
    }
    
    return C;
}

void print_matrix(const Matrix& m)
{  
    for (size_t i = 0; i < m.size(); ++i) {
	std::cout << "| ";
	std::cout << std::fixed << std::setprecision(6);
	
	for (size_t j = 0; j < m[0].size(); ++j) {
	    if (m[i][j] >= 0) std::cout << ' ';
	    
	    if (j != m[0].size() - 1)
		std::cout << std::setw(9) << m[i][j] << "  ";
	    else
		std::cout << std::setw(9)  << m[i][j];
	}

	std::cout << " |\n";
    }
}

Matrix get_matrix_from_user(size_t n)
{
    Matrix M(n, Vector(n, 0.0));

    for (size_t i = 0; i < n; ++i) {
	for (size_t j = 0; j < n; ++j) {
	    std::cout << "M[" << i + 1 << "][" << j + 1 << "]: ";
	    std::cin >> M[i][j];
	}
    }

    return M;
}

Vector get_b_from_user(size_t n)
{
    Vector b(n, 0.0);

    for (size_t i = 0; i < n; ++i) {
	std::cout << "b[" << i + 1 << "]: ";
	std::cin >> b[i];
    }

    return b;
}

#endif // USEFUL_FUNCTIONS_HPP
