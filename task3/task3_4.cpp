#include <iostream>
#include <vector>
#include <random>
#include <future>
#include <chrono>

std::random_device os_seed;
const int seed = 1;
std::mt19937 generator(seed);
std::uniform_int_distribution<> distribute(0, 1000);

double average(const std::vector<double> &v) {
    double sum = 0.0;
    for (int i = 0; i < v.size(); i++)
        sum += v[i];
    return sum / v.size();
}

double maximum(const std::vector<double> &v) {
    double max = 0.0;
    for (int i = 0; i < v.size(); i++)
        if (v[i] > max) max = v[i];
    return max;
}

double minimum(const std::vector<double> &v) {
    double min = 1.0;
    for (int i = 0; i < v.size(); i++)
        if (v[i] < min) min = v[i];
    return min;
}

int main() {
    int size = 100000000;
    std::vector<double> v(size);

    for (int i = 0; i < v.size(); i++)
        v[i] = distribute(generator) / 1000.0;

    auto start = std::chrono::steady_clock::now();

    auto minFuture = std::async(std::launch::async, minimum, std::ref(v));
    auto maxFuture = std::async(std::launch::async, maximum, std::ref(v));
    auto avgFuture = std::async(std::launch::async, average, std::ref(v));

    double min = minFuture.get();
    double max = maxFuture.get();
    double avg = avgFuture.get();

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "Elapsed: " << elapsed_seconds.count() << " seconds" << std::endl;
    std::cout << "Min: " << min << " Max: " << max << " AVG: " << avg << std::endl;

    return 0;
}
