// g++ -fopenmp nome.cpp -o nome.exe

// ./nome

/* Exercício 1 — “Hello World” Paralelo
a) Crie uma região paralela com #pragma omp parallel.

b) Cada thread deve imprimir uma mensagem indicando seu número 
(omp_get_thread_num()) e o total de threads (omp_get_num_threads()).
*/

#include <iostream> 
#include <omp.h> 

int main() {
 
    #pragma omp parallel 
    {
        // Cada thread recebe um ID único de 0 a (T-1), onde T = número de threads.
        int thread_id = omp_get_thread_num();

        // Atenção: várias threads escrevendo no mesmo stdout podem "misturar" saídas.
        // Para garantir a impressão linha-a-linha sem entrelaçamento, usar criticals. Próximo script.
        std::cout << "Hello, world from thread " << thread_id << std::endl;
    }
    return 0;

}

/*
c) Configure o programa para rodar com 4 threads.
*/
