#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int x;
    int y;
} xyPoint;

typedef struct {
    xyPoint center;
    double radius;
} xyCircle;

void erase(char *str, const char ch) {
    char *src = str;
    char *dst = str;
    while (*src) {
        if (*src != ch) {
            *dst = *src;
            dst++;
        }
        src++;
    }
    *dst = '\0';
}

void chunk(const char *first, const char *last, const size_t k, const bool right_to_left, char **str_list) {
    size_t len = strlen(first);
    size_t num_chunks = len / k + (len % k != 0);
    *str_list = malloc(num_chunks * (k + 1) * sizeof(char));
    char *chunk_ptr = *str_list;

    if (right_to_left) {
        for (int i = num_chunks - 1; i >= 0; i--) {
            strncpy(chunk_ptr, last - (i + 1) * k, k);
            chunk_ptr += k;
            *chunk_ptr = '\0';
            chunk_ptr++;
        }
    } else {
        for (int i = 0; i < num_chunks; i++) {
            strncpy(chunk_ptr, first + i * k, k);
            chunk_ptr += k;
            *chunk_ptr = '\0';
            chunk_ptr++;
        }
    }
}

char *operator++(char *s) {
    char *p = s;
    while (*p) {
        if (*p == 'z') {
            *p = 'a';
            p++;
        } else {
            (*p)++;
            break;
        }
    }
    return s;
}

bool starts_with(const char *a, const char *b) {
    while (*a && *b) {
        if (*a != *b) {
            return false;
        }
        a++;
        b++;
    }
    return *b == '\0';
}

void get_prefix_tree(const char **word, size_t num_words, char ***tree) {
    size_t max_word_len = 0;
    for (size_t i = 0; i < num_words; i++) {
        size_t word_len = strlen(word[i]);
        if (word_len > max_word_len) {
            max_word_len = word_len;
        }
    }

    *tree = malloc(max_word_len * sizeof(char *));
    for (size_t i = 0; i < max_word_len; i++) {
        (*tree)[i] = malloc(num_words * (max_word_len + 1) * sizeof(char));
    }

    for (size_t i = 0; i < num_words; i++) {
        const char *w = word[i];
        size_t w_len = strlen(w);
        for (size_t j = 0; j < w_len; j++) {
            strncpy((*tree)[j] + i * (max_word_len + 1), w, w_len);
            (*tree)[j][i * (max_word_len + 1) + w_len] = '\0';
        }
    }
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void prime_factors(int n, int **fac, size_t *num_factors) {
    *fac = malloc(n * sizeof(int));
    *num_factors = 0;

    while (n % 2 == 0) {
        (*fac)[*num_factors] = 2;
        (*num_factors)++;
        n /= 2;
    }

    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            (*fac)[*num_factors] = i;
            (*num_factors)++;
            n /= i;
        }
    }

    if (n > 2) {
        (*fac)[*num_factors] = n;
        (*num_factors)++;
    }
}

int absdiff(int a, int b) {
    return a < b ? b - a : a - b;
}

int main() {
    printf("Hello, World!\n");
    return 0;
}
