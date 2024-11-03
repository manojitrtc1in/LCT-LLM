#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LENGTH 100

typedef struct {
    char str[MAX_LENGTH];
} String;

void swap(String *a, String *b) {
    String temp = *a;
    *a = *b;
    *b = temp;
}

void sortStrings(String *str, int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (strcmp(str[j].str, str[j+1].str) > 0) {
                swap(&str[j], &str[j+1]);
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    String *str = (String*) malloc(n * sizeof(String));
    for (int i = 0; i < n; i++) {
        scanf("%s", str[i].str);
    }

    sortStrings(str, n);

    for (int i = 0; i < n; i++) {
        printf("%s\n", str[i].str);
    }

    free(str);
    return 0;
}
