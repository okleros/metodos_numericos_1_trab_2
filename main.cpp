#include <iostream>
#include <cstring>

#include "useful_functions.hpp"

#include "gauss_jacobi.hpp"
#include "gauss_seidel.hpp"

#include "inversa_gauss_jacobi.hpp"
#include "inversa_gauss_seidel.hpp"

#include "lu_decomposition.hpp"
#include "determinant_gauss_jordan.hpp"

#define MAX_ITER 1000

int main(int argc, const char** argv)
{
    Matrix A, inv_A_gauss_jacobi, inv_A_gauss_seidel;
    Vector b, solution;
    double epsilon;
    size_t n;
    
    if (argc > 1) {
        if (!strcmp(argv[1], "--default")) {
	    A = { {10,  1,  1},
		      { 1, 10,  1},
		      { 1,  1, 10}};

	    b =  {12, 12, 12};

	    epsilon = 1e-5;

	} else std::cout << "usage: ./main or ./main --default";

    } else {
	std::cout << "Número de deslocamentos (n): ";
	std::cin >> n;

	A = get_matrix_from_user(n);
	b = get_b_from_user(n);

	std::cout << "Tolerância (ε): ";
	std::cin >> epsilon;
    }

    // std::cout << "\nSolução do sistema através de Gauss-Jacobi:\n";
    // print_matrix(transpose(Matrix(1, gauss_jacobi(A, b, epsilon, MAX_ITER))));

    LU* final = lu_decomposition(A);

    Vector p = solve_using_LU(final, b);

    std::cout << "Solução do sistema [p] usando fatoração LU: [ ";
    for (auto el : p) {
        std::cout << el << " ";
    }
    std::cout << "]\n";

    std::cout << "O determinante da matrix é " << determinant_gauss_jordan(A) << ".\n";

    std::cout << "\nSolução do sistema através do método de Gauss-Seidel:\n";
    print_matrix(transpose(Matrix(1, gauss_seidel(A, b, epsilon, MAX_ITER))));
    
    // std::cout << "\nSolução do sistema (M⁻¹xb) Gauss-Jacobi:\n";
    // print_matrix(dot(inv_A_gauss_jacobi, transpose(Matrix(1, b))));
    
    // std::cout << "\nSolução do sistema (M⁻¹xb) Gauss-Seidel:\n";    
    // print_matrix(dot(inv_A_gauss_seidel, transpose(Matrix(1, b))));
    

    // std::cout << p << std::endl;

    // std::cout << "Matriz L:\n";
    // print_matrix(final->L);
    // std::cout << "\nMatriz U:\n";
    // print_matrix(final->U);
    
    return 0;
}
