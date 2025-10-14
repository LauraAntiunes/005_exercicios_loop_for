/* Exercício 3 — Expressão Vetorial
Implemente a expressão: a[i] = x[i]^2 + y[i]^2 + z[i]^2 para vetores de tamanho 1.000.000.
a) Faça a versão sequencial.
b) Paralelize com #pragma omp parallel for schedule(static).
c) Mostre o tempo total de execução em cada versão. */


#include <iostream>
#include <vector>
#include <omp.h>
#include <cmath>

int main() {
    const int N = 1000000;
    std::vector<double> x(N), y(N), z(N), a_seq(N), a_par(N);

    // inicializacao dos vetores
    for (int i = 0; i < N; ++i) {
        x[i] = i * 0.001;
        y[i] = i * 0.002;
        z[i] = i * 0.003;
    }

    // a) 
    double start_seq = omp_get_wtime();
    for (int i = 0; i < N; ++i) {
        a_seq[i] = x[i]*x[i] + y[i]*y[i] + z[i]*z[i];
    }
    double end_seq = omp_get_wtime();
    double tempo_seq = end_seq - start_seq;

    // b) 
    double start_par = omp_get_wtime();
    #pragma omp parallel for schedule(static)
    for (int i = 0; i < N; ++i) {
        a_par[i] = x[i]*x[i] + y[i]*y[i] + z[i]*z[i];
    }
    double end_par = omp_get_wtime();
    double tempo_par = end_par - start_par;

    // c) 
    bool iguais = true;
    for (int i = 0; i < N; ++i) {
        if (std::abs(a_seq[i] - a_par[i]) > 1e-9) {
            iguais = false;
            break;
        }
    }

    //saida dos resultados
    std::cout << "Tempo (sequencial): " << tempo_seq << " segundos\n";
    std::cout << "Tempo (paralelo):   " << tempo_par << " segundos\n";
    std::cout << "Resultados iguais?  " << (iguais ? "Sim" : "Não") << std::endl;

    return 0;
}
