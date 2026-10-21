#include <iostream>
#include <omp.h> // The OpenMP library for parallel programming

int main() {

    //This directive tells the compiler to run the next block in parallel.

    #pragma omp parallel
    {
        //Get the unique ID of the current CPU core thread
        int thread_id = omp_get_thread_num();
         std::cout << "Hello World from CPU thread core: " << thread_id << std::endl;
    }  

    return 0;
}