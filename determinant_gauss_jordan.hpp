#ifndef DETERMINANT_GAUSS_JORDAN
#define DETERMINANT_GAUSS_JORDAN

double determinant_gauss_jordan(Matrix C) {
    int n = C.size();
    double det = 1.0;
    
    for (int i = 0; i < n; i++) {
        int pivot = i;
        for (int j = i + 1; j < n; j++) {
            if (abs(C[j][i]) > abs(C[pivot][i])) {
                pivot = j;
            }
        }
        
        // se há alguma troca de linhas, o det *= -1
        if (pivot != i) {
            swap(C[i], C[pivot]);
            det *= -1; 
        }
    
        if (C[i][i] == 0) return 0;
    
        det *= C[i][i];
        for (int j = i + 1; j < n; j++) {
            double factor = C[j][i] / C[i][i];
            for (int k = i; k < n; k++) {
                C[j][k] -= factor * C[i][k];
            }
        }
    }
    
    return det;
}

#endif // DETERMINANT_GAUSS_JORDAN