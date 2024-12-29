#include <iostream>
#include <vector>
#include <omp.h>
#include <chrono>

int main() {
    int size = 10000000;

    //Parallelized push_back with critical section
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<float> v1;
    #pragma omp parallel for
    for (int i = 0; i < size; i++) {
        #pragma omp critical
        v1.push_back(i);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Parallel push_back (with critical): " << elapsed.count() << " ms" << std::endl;
    
    //Parallelized indexed access (safe)
    start = std::chrono::high_resolution_clock::now();
    std::vector<float> v2(size);
    #pragma omp parallel for
    for (int i = 0; i < size; i++) {
        v2[i] = i;
    }
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Parallel indexed access: " << elapsed.count() << " ms" << std::endl;
}