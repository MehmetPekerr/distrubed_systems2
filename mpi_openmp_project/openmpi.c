#include <stdio.h>
#include <omp.h>

int main() {
    int n = 1000000;
    double sum = 0.0;

    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < n; i++) {
        sum += 1.0 / (i + 1);
    }

    printf("Sum: %f\n", sum);
    return 0;
}
