#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 0, sign = 1, t = 0; scanf("%d", &n);
    int** m = malloc(n * sizeof(int*));
    for (size_t i = 0; i < n; ++i) {
        *(m + i) = (int*) malloc(n * sizeof(int));
    }
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            scanf("%d", &*(*(m + i) + j));
        }
    }
    for (size_t i = 0; i < n; ++i) {
        int p = 0;
        if (*(*(m + i) + i) == 0) {
            p = 0;
            while (*(*(m + p) + i) == 0 || *(*(m + i) + p) == 0) {
                if (p < n - 1) ++p;
                else { 
                    printf("%d\n", 0);
                    return 0;
                }
            }
            for (size_t j = 0; j < n; ++j) {
                t = *(*(m + j) + i); *(*(m + j) + i) = *(*(m + j) + p); *(*(m + j) + p) = t;
            }
            sign *= -1;
        }
    }
    for (size_t k = 0; k < n - 1; ++k) {
        for (size_t i = k + 1; i < n; ++i) {
            for (size_t j = k + 1; j < n; ++j) {
                *(*(m + i) + j) = *(*(m + i) + j) * *(*(m + k) + k) - *(*(m + i) + k) * *(*(m + k) + j);
                if (k > 0) {
                if (*(*(m + k - 1) + k - 1) == 0) {
                    printf("%d\n", 0);
                    return 0;
                }
                else *(*(m + i) + j) /= *(*(m + k - 1) + k - 1);
            }
            }
        }
    }
    printf("%d\n", sign * *(*(m + n - 1) + n - 1));
    return 0;
}
