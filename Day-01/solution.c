#include <stdio.h>
#include <stdlib.h>

int difficulty(char c) {
    return (c - 'a' + 1) % 5;
}

int cmp(const void *a, const void *b) {
    char ca = *(char *)a;
    char cb = *(char *)b;
    int da = difficulty(ca);
    int db = difficulty(cb);
    if (da != db) return da - db;
    return cb - ca;  
}

void user_logic(int n, char* s) {
    qsort(s, n, sizeof(char), cmp);
}

int main() {
    int n;
    char s[100001];
    scanf("%d", &n);
    scanf("%s", s);
    user_logic(n, s);
    printf("%s\n", s);
    return 0;
}
