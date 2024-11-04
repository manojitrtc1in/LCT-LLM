#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef long long int int64;

typedef struct {
    char *first;
    char *second;
} Pair;

typedef struct {
    size_t size;
    size_t capacity;
    Pair *data;
} Map;

void init_map(Map *map, size_t capacity) {
    map->size = 0;
    map->capacity = capacity;
    map->data = (Pair *)malloc(capacity * sizeof(Pair));
}

void free_map(Map *map) {
    free(map->data);
}

void insert_map(Map *map, size_t key, const char *value) {
    if (map->size >= map->capacity) {
        map->capacity *= 2;
        map->data = (Pair *)realloc(map->data, map->capacity * sizeof(Pair));
    }
    map->data[map->size].first = (char *)malloc(20 * sizeof(char));
    sprintf(map->data[map->size].first, "%zu", key);
    map->data[map->size].second = strdup(value);
    map->size++;
}

char* find_map(Map *map, size_t key) {
    for (size_t i = 0; i < map->size; i++) {
        if (atoi(map->data[i].first) == key) {
            return map->data[i].second;
        }
    }
    return NULL;
}

void free_string(char *str) {
    free(str);
}

char* id28(size_t i, size_t j, const char **str, const char *vir, Map *cache) {
    if (i == strlen(str[0]) || j == strlen(str[1])) {
        return "";
    }

    char key[20];
    sprintf(key, "%zu_%zu", i, j);
    char *cached_value = find_map(cache, atoi(key));
    if (cached_value) {
        return cached_value;
    }

    if (str[0][i] != str[1][j]) {
        char *a = id28(i + 1, j, str, vir, cache);
        char *b = id28(i, j + 1, str, vir, cache);
        char *result = (strlen(a) < strlen(b)) ? b : a;
        insert_map(cache, atoi(key), result);
        return result;
    } else {
        char *rest = id28(i + 1, j + 1, str, vir, cache);
        char *a = (char *)malloc(20 * sizeof(char));
        sprintf(a, "%c%s", str[0][i], rest);
        char *b = (char *)malloc(20 * sizeof(char));
        sprintf(b, "%c%s", str[0][i], rest);
        free(rest);
        insert_map(cache, atoi(key), a);
        return a;
    }
}

char* b346() {
    char str[2][100];
    char vir[100];
    scanf("%s %s", str[0], vir);

    Map cache;
    init_map(&cache, 10);

    char *val = id28(0, 0, (const char **)str, vir, &cache);
    if (strcmp(val, "") == 0) {
        free_map(&cache);
        return "0";
    }
    free_map(&cache);
    return val;
}

int main() {
    char *result = b346();
    printf("%s\n", result);
    return EXIT_SUCCESS;
}
