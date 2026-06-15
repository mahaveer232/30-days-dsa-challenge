#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};
typedef struct ListNode ListNode;

char* user_logic(ListNode* head) {
    long long num = 0;
    ListNode* curr = head;
    while (curr != NULL) {
        num = num * 10 + curr->val;
        curr = curr->next;
    }

    long long reversed = 0;
    long long temp = num;
    while (temp > 0) {
        reversed = reversed * 10 + (temp % 10);
        temp /= 10;
    }

    long long digit_sum = 0;
    temp = reversed;
    while (temp > 0) {
        digit_sum += temp % 10;
        temp /= 10;
    }

    long long result = reversed - digit_sum;

    return (result % 2 == 0) ? "even" : "odd";
}

int main() {
    int N;
    scanf("%d", &N);

    ListNode* head = NULL;
    ListNode* tail = NULL;

    for (int i = 0; i < N; i++) {
        int value;
        scanf("%d", &value);
        ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
        newNode->val = value;
        newNode->next = NULL;
        if (!head) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
    }

    char* result = user_logic(head);
    printf("%s\n", result);

    return 0;
}
