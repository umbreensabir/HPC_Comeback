#include <iostream>
#include <vector>
#include <chrono>

__attribute__((noinline))
double sum_with_stride(
    const std::vector<double>& data,
    std::size_t stride)
{
    double sum = 0.0;

    for (std::size_t i = 0; i < data.size(); i += stride) {
        sum += data[i];
    }

    return sum;
}

int main()
{
    const std::size_t N = 100'000'000;
    std::vector<double> data(N, 1.0);

    auto start1  = std::chrono::steady_clock::now();
    double sum1 = 0.0;
    for (std::size_t i = 0; i < N; ++i) 
    {
    sum1 += data[i];
    }
    auto end1 = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration1 = end1 - start1;
    std::cout << "Sequential Sum: " << sum1 << ", Time taken: " << duration1.count() << " seconds" << std::endl;

     
    for (std::size_t stride = 1; stride <= 16; stride *= 2) {
        auto start2 = std::chrono::steady_clock::now();   
        double sum2 = sum_with_stride(data, stride);
        auto end2 = std::chrono::steady_clock::now();
        std::chrono::duration<double> duration2 = end2 - start2;
        std::cout << "Sum with stride " << stride << ": " << sum2 << ", Time taken: " << duration2.count() << " seconds" << std::endl;
    }
    return 0;
    }
