#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    long long x = *(long long *)a;
    long long y = *(long long *)b;

    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main() {

    int n;
    scanf("%d", &n);

    long long books[n];

    for (int i = 0; i < n; i++) {
        scanf("%lld", &books[i]);
    }

    qsort(books, n, sizeof(long long), compare);

    long long answer = books[0];
    int maxFreq = 1, currentFreq = 1;

    for (int i = 1; i < n; i++) {
        if (books[i] == books[i - 1]) {
            currentFreq++;
        } else {
            if (currentFreq > maxFreq) {
                maxFreq = currentFreq;
                answer = books[i - 1];
            }
            currentFreq = 1;
        }
    }

    if (currentFreq > maxFreq) {
        answer = books[n - 1];
    }

    printf("%lld", answer);

    return 0;
}
