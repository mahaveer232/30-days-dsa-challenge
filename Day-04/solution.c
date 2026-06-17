#include <stdio.h>

int find_lucky_stone_pairs(int p, int n, int m, int stones[]) {
    int count = 0;

for (int i = 0; i < p; i++) {
    if (stones[i] % n == 0 || stones[i] % m == 0) {
        count++;
    }
}

return count * (count - 1) / 2;
    return 0;
}

int main() {
    int p, n, m;
    scanf("%d %d %d", &p, &n, &m);
    int stones[p];
    for (int i = 0; i < p; i++) {
        scanf("%d", &stones[i]);
    }
    int result = find_lucky_stone_pairs(p, n, m, stones);
    printf("%d\n", result);
    return 0;
}
