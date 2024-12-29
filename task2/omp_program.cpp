#include <iostream>
#include <omp.h>

int main() {
    const int size = 1000000; // Size of the array
    int array[size];
    long long sum = 0;

    // Initialize the array
    #pragma omp parallel for
    for (int i = 0; i < size; i++) {
        array[i] = i + 1; // Assign values 1 to size
    }

    // Parallel reduction to compute the sum
    #pragma omp parallel for reduction(+:sum) schedule(dynamic, 100)
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }

    std::cout << "Sum of array elements: " << sum << std::endl;
    return 0;
}
