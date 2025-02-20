#include <iostream>
#include <cstring>

#include "useful_functions.hpp"

#include "gauss_jacobi.hpp"
#include "gauss_seidel.hpp"

#include "inversa_gauss_jacobi.hpp"
#include "inversa_gauss_seidel.hpp"

#include "lu_decomposition.hpp"
#include "determinant_gauss_jordan.hpp"
#include "cramer_method.hpp"

#define MAX_ITER 1000

int main(int argc, const char** argv)
{
    Matrix A, inv_A_gauss_jacobi, inv_A_gauss_seidel;
    Vector b, solution;
    double a, epsilon;
    size_t n;

    if (argc > 1) {
        if (!strcmp(argv[1], "--default")) {
            A = { {10,  1,  1},
                  { 1, 10,  1},
                  { 1,  1, 10}};

            b =  {12, 12, 12};

    	    epsilon = 1e-5;

            a = 1;

            LU* final = lu_decomposition(A);

            Vector p = solve_using_LU(final, b);

            std::cout << "Matriz L:\n";
            print_matrix(final->L);
            std::cout << "\nMatriz U:\n";
            print_matrix(final->U);

            std::cout << "Solução do sistema [p] usando fatoração LU:\n";
            print_matrix(transpose(Matrix(1, p)));
            std::cout << std::endl; 

            std::cout << "O determinante da matriz (calculado via Gauss-Jordan) é " << determinant_gauss_jordan(A) << ".\n";

            std::cout << "\nSolução do sistema através do método de Cramer:\n";
            print_matrix(transpose(Matrix(1, cramer_method(A, b))));

            std::cout << "\nSolução do sistema através do método de Gauss-Seidel:\n";
            print_matrix(transpose(Matrix(1, gauss_seidel(A, b, epsilon, MAX_ITER))));

	   } else std::cout << "usage: ./main or ./main --default";

    } else {
    	std::cout << "Número de deslocamentos (n): ";
    	std::cin >> n;

        for (size_t i = 0; i < n; ++i) {
            A = { {10,  1,  1},
                  { 1, 10,  1},
                  { 1,  1, 10}};

            b =  {12, 12, 12};

            std::cout << "a: ";
            std::cin >> a;

        	std::cout << "Tolerância (ε): ";
            std::cin >> epsilon;

            A = mul(A, a);
        
            LU* final = lu_decomposition(A);

            Vector p = solve_using_LU(final, b);

            std::cout << "Matriz L:\n";
            print_matrix(final->L);
            std::cout << "\nMatriz U:\n";
            print_matrix(final->U);

            std::cout << "Solução do sistema [p] usando fatoração LU:\n";
            print_matrix(transpose(Matrix(1, p)));
            std::cout << std::endl; 

            std::cout << "O determinante da matriz (calculado via Gauss-Jordan) é " << determinant_gauss_jordan(A) << ".\n";

            std::cout << "\nSolução do sistema através do método de Cramer:\n";
            print_matrix(transpose(Matrix(1, cramer_method(A, b))));

            std::cout << "\nSolução do sistema através do método de Gauss-Seidel:\n";
            print_matrix(transpose(Matrix(1, gauss_seidel(A, b, epsilon, MAX_ITER))));
        }
    }
    
    return 0;
}
