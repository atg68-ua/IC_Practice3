#include <iostream>
#include <cstdlib>
#include <cmath>
#include <omp.h>

double monte_carlo_pi(int num_points) {
    int count_inside = 0;

    #pragma omp parallel for reduction(+:count_inside)
    for (int i = 0; i < num_points; ++i) {
        double x = static_cast<double>(rand()) / RAND_MAX;
        double y = static_cast<double>(rand()) / RAND_MAX;

        if (x * x + y * y <= 1.0) {
            ++count_inside;
        }
    }

    return 4.0 * count_inside / num_points;
}

int main() {
    int num_points = 1e6;

    double start_time = omp_get_wtime();
    double pi_estimate = monte_carlo_pi(num_points);
    double end_time = omp_get_wtime();

    std::cout << "Estimated PI: " << pi_estimate << std::endl;
    std::cout << "Elapsed Time: " << (end_time - start_time) << " seconds" << std::endl;

    return 0;
}
