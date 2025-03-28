#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank, size;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    printf("Hello from process %d of %d\n", rank, size);

    MPI_Finalize();
    return 0;
}


/* #include <stdio.h>
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
*/
