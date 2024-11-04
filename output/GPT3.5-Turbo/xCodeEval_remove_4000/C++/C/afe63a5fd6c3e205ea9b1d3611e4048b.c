#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define C 100
#define DELIMS ",.?!\"\\/|"

typedef struct {
    char* word;
    double value;
} Category;

typedef struct {
    Category* categories;
    int size;
} CategoryMap;

char buf[1100000];
CategoryMap ma[3];
double p[10];
int sel;

void initCategoryMap(CategoryMap* map) {
    map->categories = NULL;
    map->size = 0;
}

void addCategory(CategoryMap* map, char* word, double value) {
    Category* category = (Category*)malloc(sizeof(Category));
    category->word = strdup(word);
    category->value = value;

    map->categories = (Category*)realloc(map->categories, (map->size + 1) * sizeof(Category));
    map->categories[map->size] = *category;
    map->size++;
}

double getCategoryValue(CategoryMap* map, char* word) {
    for (int i = 0; i < map->size; i++) {
        if (strcmp(map->categories[i].word, word) == 0) {
            return map->categories[i].value;
        }
    }
    return 1E-6;
}

void freeCategoryMap(CategoryMap* map) {
    for (int i = 0; i < map->size; i++) {
        free(map->categories[i].word);
    }
    free(map->categories);
    map->size = 0;
}

void toLower(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void tokenizeText(char* text, char* delims, CategoryMap* map) {
    char* token = strtok(text, delims);
    while (token != NULL) {
        toLower(token);
        for (int i = 0; i < 3; i++) {
            double value = getCategoryValue(&map[i], token);
            p[i] += log(value);
        }
        token = strtok(NULL, delims);
    }
}

int main() {
    FILE* input = fopen("input.txt", "rt");
    FILE* output = fopen("output.txt", "wt");

    for (int i = 0; i < 3; i++) {
        initCategoryMap(&ma[i]);
    }

    for (int i = 0; i < 3 * C; i++) {
        double value;
        sscanf(cat[i], "%s%lf", buf, &value);
        addCategory(&ma[i / C], buf, value);
    }

    fgets(buf, sizeof(buf), input);
    char text[1100000] = "";
    while (fgets(buf, sizeof(buf), input)) {
        strcat(text, buf);
        strcat(text, " ");
    }

    for (int i = 0; text[i]; i++) {
        if (strchr(DELIMS, text[i]) != NULL) {
            text[i] = ' ';
        }
    }

    tokenizeText(text, " ", ma);

    sel = 1;
    for (int i = 2; i >= 0; i--) {
        if (p[i] > p[sel] + 1E-9) {
            sel = i;
        }
    }

    fprintf(output, "%d\n", sel + 1);

    fclose(input);
    fclose(output);

    for (int i = 0; i < 3; i++) {
        freeCategoryMap(&ma[i]);
    }

    return 0;
}
