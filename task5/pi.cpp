#include <iostream>
#include <cmath>
#include <omp.h>

double f(double x) {
    return 1.0 / (1.0 + x * x);
}

double integrate(double a, double b, int n) {
    double h = (b - a) / n;
    double integral = 0.0;

    #pragma omp parallel for reduction(+:integral)
    for (int i = 0; i < n; ++i) {
        double x = a + i * h + h / 2.0;
        integral += f(x);
    }

    return integral * h;
}

int main() {
    double a = 0.0, b = 1.0;
    int n = 1e7;

    double start_time = omp_get_wtime();
    double result = integrate(a, b, n);
    double end_time = omp_get_wtime();

    std::cout << "Estimated PI: " << result * 4.0 << std::endl;
    std::cout << "Elapsed Time: " << (end_time - start_time) << " seconds" << std::endl;

    return 0;
}
