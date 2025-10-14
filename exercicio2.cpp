#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int N = 100;
    std::vector<int> v(N, 1); // a) vetor com 100 elementos valendo 1

    // b) Soma sequencial
    int soma_seq = 0;
    for (int i = 0; i < N; ++i) {
        soma_seq += v[i];
    }

    // c) Soma paralela com reduction
    int soma_par = 0;
    #pragma omp parallel for reduction(+:soma_par)
    for (int i = 0; i < N; ++i) {
        soma_par += v[i];
    }

    // d) Exibir resultados
    std::cout << "Soma sequencial: " << soma_seq << std::endl;
    std::cout << "Soma paralela:   " << soma_par << std::endl;

    return 0;
}
