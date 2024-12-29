#include <iostream>
#include <omp.h>
#include <vector>

const int size = 1000;

int main() {
    int max = 0;
    int min = 1000;

    #pragma omp parallel for
    for (int i = 1000; i >= 0; i--) {
        #pragma omp critical
        {
            if (i > max) max = i;
            if (i < min) min = i;
        }
    }

    std::cout << "Max: " << max << " Min: " << min << std::endl;
}
