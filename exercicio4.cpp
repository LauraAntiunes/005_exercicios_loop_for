/* Exercício 4 — Medindo tempo por thread
Adapte o código do exercício anterior para:
a) Medir e exibir o tempo total de execução.
b) Medir e exibir o tempo gasto por cada thread.
c) Mostrar quantas threads foram utilizadas no cálculo. */ 


#include <iostream>
#include <vector>
#include <omp.h>
#include <cmath>
#include <iomanip> // para formatar a saída

int main() {
    const int N = 1000000;
    std::vector<double> x(N), y(N), z(N), a(N);

    // inicializacao dos vetores
    for (int i = 0; i < N; ++i) {
        x[i] = i * 0.001;
        y[i] = i * 0.002;
        z[i] = i * 0.003;
    }

    // vetores para medir o tempo por thread 
    const int MAX_THREADS = 128;
    double start_thread[MAX_THREADS] = {0.0};
    double end_thread[MAX_THREADS] = {0.0};

    // a) 
    double start_total = omp_get_wtime();

    // b) 
    #pragma omp parallel
    {
        int tid = omp_get_thread_num();  // ID da thread
        start_thread[tid] = omp_get_wtime();

        // c) 
        #pragma omp for schedule(static)
        for (int i = 0; i < N; ++i) {
            a[i] = x[i]*x[i] + y[i]*y[i] + z[i]*z[i];
        }

        end_thread[tid] = omp_get_wtime();
    }

    double end_total = omp_get_wtime();
    double tempo_total = end_total - start_total;

    // quantas threads foram usadas
    int num_threads = 0;
    #pragma omp parallel
    {
        #pragma omp single
        num_threads = omp_get_num_threads();
    }

    // saida dos resultados
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Tempo total (paralelo): " << tempo_total << " segundos\n";
    std::cout << "Número de threads usadas: " << num_threads << "\n\n";

    // mostrar tempo por thread
    for (int i = 0; i < num_threads; ++i) {
        double tempo_thread = end_thread[i] - start_thread[i];
        std::cout << "Thread " << i << " executou em " << tempo_thread << " segundos\n";
    }

    return 0;
}
