#include <iostream>
#include <vector>
#include <random>
#include <omp.h>
#include <chrono>

std::random_device os_seed;
const int seed = 1;
std::mt19937 generator(seed);
std::uniform_int_distribution<> distribute(0, 1000);

double average(const std::vector<double> &v) {
    double sum = 0.0;
    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < v.size(); i++)
        sum += v[i];
    return sum / v.size();
}

double maximum(const std::vector<double> &v) {
    double max = 0.0;
    #pragma omp parallel for reduction(max:max)
    for (int i = 0; i < v.size(); i++)
        if (v[i] > max) max = v[i];
    return max;
}

double minimum(const std::vector<double> &v) {
    double min = 1.0;
    #pragma omp parallel for reduction(min:min)
    for (int i = 0; i < v.size(); i++)
        if (v[i] < min) min = v[i];
    return min;
}

int main() {
    int size = 100000000;
    std::vector<double> v(size);

    for (int i = 0; i < v.size(); i++)
        v[i] = distribute(generator) / 1000.0;

    double min, max, avg;
    auto start = std::chrono::steady_clock::now();

    #pragma omp parallel sections
    {
        #pragma omp section
        { min = minimum(v); }
        #pragma omp section
        { max = maximum(v); }
        #pragma omp section
        { avg = average(v); }
    }

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "Elapsed: " << elapsed_seconds.count() << " seconds" << std::endl;
    std::cout << "Min: " << min << " Max: " << max << " AVG: " << avg << std::endl;

    return 0;
}
