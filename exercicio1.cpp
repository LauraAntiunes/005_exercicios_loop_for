// g++ -fopenmp nome.cpp -o nome.exe

// ./nome

/* Exercício 1 — “Hello World” Paralelo
a) Crie uma região paralela com #pragma omp parallel.

b) Cada thread deve imprimir uma mensagem indicando seu número 
(omp_get_thread_num()) e o total de threads (omp_get_num_threads()).


c) Configure o programa para rodar com 4 threads.
*/


#include <iostream> 
#include <sstream>    // std::ostringstream (buffer local de string)
#include <omp.h> 

int main() {
 
    #pragma omp parallel num_threads(4) // cria um time de 4 threads
    {
        // Cada thread recebe um ID único de 0 a (T-1), onde T = número de threads.
        int tid = omp_get_thread_num();
        int tot = omp_get_num_threads();

        std::ostringstream oss;
      

        oss << "Hello, world from thread " << tid << " of " << tot << "\n";    
    
    
        #pragma omp critical
        {
            std::cout << oss.str();
        }
    
    
    }
    return 0;

}

