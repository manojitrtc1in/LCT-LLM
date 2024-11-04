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

void erase(char* str, const char ch) {
    char* p = str;
    while (*str) {
        if (*str != ch) {
            *p++ = *str;
        }
        str++;
    }
    *p = '\0';
}

void erase_str(char* str, const char* chrs) {
    char* p = str;
    while (*str) {
        if (!strchr(chrs, *str)) {
            *p++ = *str;
        }
        str++;
    }
    *p = '\0';
}

char* val2str(int val) {
    int len = snprintf(NULL, 0, "%d", val);
    char* str = malloc(len + 1);
    snprintf(str, len + 1, "%d", val);
    return str;
}

int str2val(const char* str) {
    return atoi(str);
}

char* tokenize(const char* str, const char sep) {
    char* token;
    char* copy = strdup(str);
    token = strtok(copy, &sep);
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, &sep);
    }
    free(copy);
}

void chunk(const char* str, const int k, const bool right_to_left, char** str_list) {
    int len = strlen(str);
    int num_chunks = len / k + (len % k != 0);
    *str_list = malloc(num_chunks * (k + 1));
    char* p = *str_list;
    if (right_to_left) {
        for (int i = len - 1; i >= 0; i -= k) {
            int start = i - k + 1;
            if (start < 0) {
                start = 0;
            }
            strncpy(p, &str[start], i - start + 1);
            p += i - start + 1;
            *p++ = '\0';
        }
    } else {
        for (int i = 0; i < len; i += k) {
            strncpy(p, &str[i], k);
            p += k;
            *p++ = '\0';
        }
    }
}

void operator_increment(char* s) {
    char* p = s + strlen(s) - 1;
    while (p >= s && *p == 'z') {
        *p = 'a';
        p--;
    }
    if (p >= s) {
        (*p)++;
    } else {
        int len = strlen(s);
        memmove(s + 1, s, len);
        s[0] = 'a';
        s[len + 1] = '\0';
    }
}

bool starts_with(const char* a, const char* b) {
    return strncmp(a, b, strlen(b)) == 0;
}

int main() {
    char str[] = "Hello, World!";
    erase(str, 'o');
    printf("%s\n", str);

    char str2[] = "Hello, World!";
    erase_str(str2, "oW");
    printf("%s\n", str2);

    int val = 123;
    char* str3 = val2str(val);
    printf("%s\n", str3);
    free(str3);

    const char* str4 = "123";
    int val2 = str2val(str4);
    printf("%d\n", val2);

    const char* str5 = "Hello, World!";
    tokenize(str5, ',');

    const char* str6 = "Hello, World!";
    char* str_list;
    chunk(str6, 3, true, &str_list);
    printf("%s\n", str_list);
    free(str_list);

    char s[] = "abc";
    operator_increment(s);
    printf("%s\n", s);

    const char* a = "Hello, World!";
    const char* b = "Hello";
    bool starts_with_result = starts_with(a, b);
    printf("%d\n", starts_with_result);

    return 0;
}
