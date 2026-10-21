#include <iostream>
#include <iomanip>
#include <vector>
#include <chrono>

// Function to calculate the sum of elements in a vector (reference version)
double calculate_sum(const std::vector<double>& data) {
    double sum = 0.0;
    for (const double value : data) {
        sum += value;
    }
    return sum;
}

// Function to calculate the sum of elements in a vector (copy version)
double calculate_sum_copy(std::vector<double> data) {
    double sum = 0.0;
    for (const double value : data) {
        sum += value;
    }
    return sum;
}

int main() {
    const std::size_t N = 10000000;

    std::vector<double> data(N, 1.0); // Initialize a vector<double> with N elements, all set to 1.0

    // Start the timer here
    auto start1 = std::chrono::steady_clock::now();

    // Perform a simple operation on the vector (e.g., summing all elements)
    double sum1 = calculate_sum(data);


    // Stop the timer here
    auto end1 = std::chrono::steady_clock::now();

    auto start2 = std::chrono::steady_clock::now();
    double sum2 = calculate_sum_copy(data);
    auto end2 = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration2 = end2 - start2;
    std::chrono::duration<double> duration1 = end1 - start1;

    std::cout << "Reference sum: " << sum1 << '\n';  
    std::cout << "Reference time: " << duration1.count() << " seconds\n";

    std::cout << "Copy sum: " << sum2 << '\n';
    std::cout << "Copy time: " << duration2.count() << " seconds\n";

    return 0;
}

