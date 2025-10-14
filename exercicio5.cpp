/* Exercício 5 — Escalonamento
Use novamente o cálculo de a[i] = x[i]^2 + y[i]^2 + z[i]^2, mas:
a) Execute com schedule(static) e schedule(dynamic, 1000).
b) Compare os tempos em diferentes quantidades de threads (2, 4, 8).
c) Explique em quais situações static e dynamic são mais adequados. */

#include <iostream>
#include <vector>
#include <omp.h>
#include <cmath>
#include <iomanip>

void calcula_vetores(const std::string& tipo_schedule, int chunk_size = 0) {
    const int N = 1000000;
    std::vector<double> x(N), y(N), z(N), a(N);

    // inicializa os vetores
    for (int i = 0; i < N; ++i) {
        x[i] = i * 0.001;
        y[i] = i * 0.002;
        z[i] = i * 0.003;
    }

    double inicio = omp_get_wtime();

    // regiao paralela com controle de escalonamento
    #pragma omp parallel
    {
        #pragma omp for schedule(static)
        for (int i = 0; i < N; ++i) {
            if (tipo_schedule == "static") {
                // ja esta dentro do for com schedule
                a[i] = x[i]*x[i] + y[i]*y[i] + z[i]*z[i];
            } else if (tipo_schedule == "dynamic") {
                // nao faz nada aqui pois precisa de chunk size
            }
        }


        if (tipo_schedule == "dynamic") {
            #pragma omp for schedule(dynamic, 1000)
            for (int i = 0; i < N; ++i) {
                a[i] = x[i]*x[i] + y[i]*y[i] + z[i]*z[i];
            }
        }
    }

    double fim = omp_get_wtime();
    double tempo = fim - inicio;

    int num_threads = 0;
    #pragma omp parallel
    {
        #pragma omp single
        num_threads = omp_get_num_threads();
    }

    std::cout << std::fixed << std::setprecision(6);
    std::cout << "[ " << tipo_schedule;
    if (tipo_schedule == "dynamic") std::cout << ", chunk=1000";
    std::cout << " | threads=" << num_threads << " ] Tempo: " << tempo << " segundos\n";
}
