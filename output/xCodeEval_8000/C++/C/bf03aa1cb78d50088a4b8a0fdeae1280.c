#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int* data;
    int size;
} Vector;

Vector* create_vector(int size) {
    Vector* vector = (Vector*)malloc(sizeof(Vector));
    vector->data = (int*)malloc(size * sizeof(int));
    vector->size = size;
    return vector;
}

void destroy_vector(Vector* vector) {
    free(vector->data);
    free(vector);
}

void reverse(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

Vector* merge_sort(Vector* a, int l, int r, char* log) {
    if (r - l <= 1) {
        Vector* result = create_vector(r - l);
        for (int i = l; i < r; i++) {
            result->data[i - l] = a->data[i];
        }
        return result;
    }
    int m = (l + r) / 2;
    Vector* left = merge_sort(a, l, m, log);
    Vector* right = merge_sort(a, m, r, log);
    Vector* result = create_vector(r - l);
    int i = 0, j = 0, k = 0;
    while (i < left->size && j < right->size) {
        if (left->data[i] < right->data[j]) {
            log[k++] = '0';
            result->data[k - 1] = left->data[i++];
        } else {
            log[k++] = '1';
            result->data[k - 1] = right->data[j++];
        }
    }
    while (i < left->size) {
        result->data[k++] = left->data[i++];
    }
    while (j < right->size) {
        result->data[k++] = right->data[j++];
    }
    destroy_vector(left);
    destroy_vector(right);
    return result;
}

bool try_recover(int l, int r, char* s, Vector* p) {
    if (r - l <= 1) {
        return true;
    }
    int mid = (l + r) / 2;
    if (!try_recover(l, mid, s, p) || !try_recover(mid, r, s, p)) {
        return false;
    }
    Vector* left = create_vector(mid - l);
    for (int i = mid - 1; i >= l; i--) {
        left->data[mid - i - 1] = p->data[i];
    }
    Vector* right = create_vector(r - mid);
    for (int i = r - 1; i >= mid; i--) {
        right->data[r - i - 1] = p->data[i];
    }
    int pos = l;
    while (left->size > 0 && right->size > 0) {
        if (*s == '\0') {
            return false;
        }
        char ch = *s;
        s++;
        if (ch == '1') {
            p->data[pos++] = right->data[right->size - 1];
            right->size--;
        } else {
            p->data[pos++] = left->data[left->size - 1];
            left->size--;
        }
    }
    while (left->size > 0) {
        p->data[pos++] = left->data[left->size - 1];
        left->size--;
    }
    while (right->size > 0) {
        p->data[pos++] = right->data[right->size - 1];
        right->size--;
    }
    destroy_vector(left);
    destroy_vector(right);
    return true;
}

void solve() {
    char s[1111];
    scanf("%s", s);
    reverse(s);

    int L = 1;
    int R = 1111;
    while (R - L > 1) {
        int len = (L + R) / 2;
        Vector* p = create_vector(len);
        for (int i = 0; i < len; i++) {
            p->data[i] = i;
        }
        char tmp[1111];
        strcpy(tmp, s);
        bool recovered = try_recover(0, len, tmp, p);
        if (recovered) {
            if (tmp[0] == '\0') {
                printf("%d\n", len);
                for (int i = 0; i < len; i++) {
                    printf("%d ", p->data[i] + 1);
                }
                printf("\n");
                destroy_vector(p);
                return;
            }
            L = len;
        } else {
            R = len;
        }
        destroy_vector(p);
    }
}

int main() {
    solve();
    return 0;
}
