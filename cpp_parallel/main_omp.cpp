#include <iostream>
#include <iomanip>
#include <vector>
#include <chrono>
#include <omp.h> // The OpenMP library for parallel programming
int main() {
    const std::size_t N = 10000000;

    std::vector<double> data(N, 1.0); // Initialize a vector<double> with N elements, all set to 1.0

    // Start the timer here
    auto start = std::chrono::steady_clock::now();

    // Perform a simple operation on the vector (e.g., summing all elements)
    double sum = 0.0;
    const double* ptr = data.data();
    #pragma omp parallel for simd reduction(+:sum)
    for (std::size_t i = 0; i < N; ++i) {
        sum += ptr[i]  ;
    }
    // Stop the timer here
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration = end - start;

    std::cout << std::fixed << std::setprecision(0) << "Sum: " << sum << '\n';
    std::cout << std::fixed << std::setprecision(6) << "Time taken: " << duration.count() << " seconds" << '\n';

    return 0;
}