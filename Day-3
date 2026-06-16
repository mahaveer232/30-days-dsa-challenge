#include <stdio.h>
#include <limits.h>

typedef struct {
    long long value;
    int left;
    int right;
} Tower;

Tower towers[10000];
long long maxSubtree[10000];

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%lld %d %d", &towers[i].value, &towers[i].left, &towers[i].right);
    }

    int stack[10000], order[10000];
    int top = 0, count = 0;

    stack[top++] = 0;

    while (top > 0) {
        int node = stack[--top];
        order[count++] = node;

        if (towers[node].left != -1) {
            stack[top++] = towers[node].left;
        }

        if (towers[node].right != -1) {
            stack[top++] = towers[node].right;
        }
    }

    int peakCount = 0;

    for (int i = count - 1; i >= 0; i--) {
        int node = order[i];

        long long maxDescendant = LLONG_MIN;

        if (towers[node].left != -1) {
            if (maxSubtree[towers[node].left] > maxDescendant) {
                maxDescendant = maxSubtree[towers[node].left];
            }
        }

        if (towers[node].right != -1) {
            if (maxSubtree[towers[node].right] > maxDescendant) {
                maxDescendant = maxSubtree[towers[node].right];
            }
        }

        if (towers[node].value > maxDescendant) {
            peakCount++;
        }

        maxSubtree[node] = towers[node].value;

        if (maxDescendant > maxSubtree[node]) {
            maxSubtree[node] = maxDescendant;
        }
    }

    printf("%d\n", peakCount);

    return 0;
}
