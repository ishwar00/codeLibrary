/*

   problem link: https://www.hackerrank.com/challenges/permutations-of-strings/problem?isFullScreen=false

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap_char(char** a, char** b) {
    char* store = *a;
    *a = *b;
    *b = store;
}

int upper_bound(const int start, const int end, char** S, const char* target) {
    int right = end;
    int left = start;
    int UB = -1;
    while (left <= right) {
        int center = (right + left) / 2;
        if (strcmp(target, S[center]) < 0) {
            UB = center;
            left = center + 1;
        } else {
            right = center - 1;
        }
    }
    return UB;
}

void reverse(char** S, int peak, int N) {
    for (int i = peak, j = N - 1; i < j; ++i, j = j - 1) {
        swap_char(&S[i], &S[j]);
    }
}

int next_permutation(int N, char** S) {
    int peak = N - 1;
    while (peak > 0 && strcmp(S[peak - 1], S[peak]) >= 0) peak = peak - 1;
    if (peak > 0) {
        int UB_at = upper_bound(peak, N - 1, S, S[peak - 1]);
        swap_char(&S[UB_at], &S[peak - 1]);
        reverse(S, peak, N);
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char** s;
    int n;
    scanf("%d", &n);
    s = (char**)calloc(n, sizeof(char*));
    for (int i = 0; i < n; i++) {
        s[i] =(char*)calloc(11, sizeof(char));
        scanf("%s", s[i]);
    }
    do {
        for (int i = 0; i < n; i++)
            printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
    } while (next_permutation(n, s));
    for (int i = 0; i < n; i++)
        free(s[i]);
    free(s);
    return 0;
}
