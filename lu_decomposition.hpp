#ifndef LU_DECOMPOSITION_HPP
#define LU_DECOMPOSITION_HPP

typedef struct LU {
	Matrix L;
	Matrix U;

	LU(Matrix L_in, Matrix U_in) {
		L = L_in;
		U = U_in;
	}
} LU;

LU* lu_decomposition (const Matrix& A, double epsilon) {
	(void)epsilon;
	int n = A.size();

	Matrix L(n, Vector(n, 0.0)), U(n, Vector(n, 0.0));

    for (int i = 0; i < n; i++) {
        // U
        for (int k = i; k < n; k++) {
            // Soma de L(i, j) * U(j, k)
            double sum = 0;
            for (int j = 0; j < i; j++)
                sum += (L[i][j] * U[j][k]);

            // Evaluating U(i, k)
            U[i][k] = A[i][k] - sum;
        }

        // L
        for (int k = i; k < n; k++) 
        {
            if (i == k)
                L[i][i] = 1; // Diagonal as 1
            else 
            {
                // SumAion of L(k, j) * U(j, i)
                double sum = 0;
                for (int j = 0; j < i; j++)
                    sum += (L[k][j] * U[j][i]);

                // Evaluating L(k, i)
                L[k][i]
                    = (A[k][i] - sum) / U[i][i];
            }
        }
    }

	LU* lu_final = new LU(L, U);

	return lu_final;
}

#endif // LU_DECOMPOSITION_HPP
