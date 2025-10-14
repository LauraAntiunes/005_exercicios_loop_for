/* Exercício 2 — Paralelizando um for simples
a) Crie um vetor v de tamanho 100 e inicialize todos os elementos com o valor 1.
b) Escreva um loop sequencial que soma todos os elementos.
c) Refaça o loop com #pragma omp parallel for reduction(+:soma).
d) Compare os resultados e explique por que a diretiva reduction é necessária. */


#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int N = 100;
    std::vector<int> v(N, 1); // a) 

    // b) 
    int soma_seq = 0;
    for (int i = 0; i < N; ++i) {
        soma_seq += v[i];
    }

    // c) 
    int soma_par = 0;
    #pragma omp parallel for reduction(+:soma_par)
    for (int i = 0; i < N; ++i) {
        soma_par += v[i];
    }

    // d) 
    std::cout << "Soma sequencial: " << soma_seq << std::endl;
    std::cout << "Soma paralela:   " << soma_par << std::endl;

    return 0;
}
