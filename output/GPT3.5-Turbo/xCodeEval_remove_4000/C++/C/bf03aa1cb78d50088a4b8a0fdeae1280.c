#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int* data;
    int size;
} vector;

vector create_vector(int size) {
    vector v;
    v.data = (int*)malloc(size * sizeof(int));
    v.size = size;
    return v;
}

void destroy_vector(vector* v) {
    free(v->data);
    v->size = 0;
}

void reverse(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

char* check(vector a) {
    int n = a.size;
    vector b = create_vector(n);
    char* log = (char*)malloc(n * sizeof(char));
    memset(log, 0, n * sizeof(char));

    void merge(int l, int r) {
        if (r - l <= 1) {
            return;
        }
        int m = (l + r) / 2;
        merge(l, m);
        merge(m, r);
        int i = l;
        int j = m;
        int k = l;
        while (i < m && j < r) {
            if (a.data[i] < a.data[j]) {
                log[k] = '0';
                b.data[k] = a.data[i];
                i++;
            } else {
                log[k] = '1';
                b.data[k] = a.data[j];
                j++;
            }
            k++;
        }
        while (i < m) {
            b.data[k] = a.data[i];
            i++;
            k++;
        }
        while (j < r) {
            b.data[k] = a.data[j];
            j++;
            k++;
        }
        for (int p = l; p < r; p++) {
            a.data[p] = b.data[p];
        }
    }

    merge(0, n);

    return log;
}

bool try_recover(int l, int r, char* s, vector* p) {
    if (r - l <= 1) {
        return true;
    }
    int mid = (l + r) / 2;
    if (!try_recover(l, mid, s, p) || !try_recover(mid, r, s, p)) {
        return false;
    }
    vector left = create_vector(mid - l);
    for (int i = mid - 1; i >= l; i--) {
        left.data[mid - 1 - i] = p->data[i];
    }
    vector right = create_vector(r - mid);
    for (int i = r - 1; i >= mid; i--) {
        right.data[r - 1 - i] = p->data[i];
    }
    int pos = l;
    while (left.size > 0 && right.size > 0) {
        if (*s == '\0') {
            return false;
        }
        char ch = *s;
        s++;

        if (ch == '1') {
            p->data[pos] = right.data[right.size - 1];
            right.size--;
        } else {
            p->data[pos] = left.data[left.size - 1];
            left.size--;
        }
        pos++;
    }
    while (left.size > 0) {
        p->data[pos] = left.data[left.size - 1];
        left.size--;
        pos++;
    }
    while (right.size > 0) {
        p->data[pos] = right.data[right.size - 1];
        right.size--;
        pos++;
    }
    destroy_vector(&left);
    destroy_vector(&right);
    return true;
}

void solve() {
    char s[100001];
    scanf("%s", s);
    reverse(s);

    int L = 1;
    int R = 1111;
    while (R - L > 1) {
        int len = (L + R) / 2;
        vector p = create_vector(len);
        for (int i = 0; i < len; i++) {
            p.data[i] = i;
        }
        char* tmp = strdup(s);
        bool recovered = try_recover(0, len, tmp, &p);
        free(tmp);
        if (recovered) {
            if (*tmp == '\0') {
                printf("%d\n", len);
                for (int i = 0; i < len; i++) {
                    printf("%d ", p.data[i] + 1);
                }
                printf("\n");
                destroy_vector(&p);
                return;
            }
            L = len;
        } else {
            R = len;
        }
        destroy_vector(&p);
    }
}

int main() {
    solve();
    return 0;
}