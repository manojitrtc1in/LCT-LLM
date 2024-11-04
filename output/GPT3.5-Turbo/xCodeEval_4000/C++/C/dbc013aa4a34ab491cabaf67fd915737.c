#include <stdio.h>
#include <stdlib.h>
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

void bubbleSort(String arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (strcmp(arr[j].str, arr[j+1].str) > 0) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    String *arr = (String*)malloc(n * sizeof(String));
    for (int i = 0; i < n; i++) {
        scanf("%s", arr[i].str);
    }

    bubbleSort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i].str);
    }

    free(arr);

    return 0;
}
