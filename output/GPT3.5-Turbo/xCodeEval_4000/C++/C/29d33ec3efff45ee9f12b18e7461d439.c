#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100000

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int first;
    pii second;
} pip;

typedef struct {
    pii first;
    int second;
} ppi;

typedef struct {
    pii first;
    pii second;
} ppp;

typedef struct {
    int size;
    int capacity;
    int* data;
} vi;

typedef struct {
    int size;
    int capacity;
    char** data;
} vs;

typedef struct {
    int size;
    int capacity;
    char* data;
} vc;

typedef struct {
    int size;
    int capacity;
    bool* data;
} vb;

void vi_init(vi* v) {
    v->size = 0;
    v->capacity = 1;
    v->data = (int*)malloc(v->capacity * sizeof(int));
}

void vi_resize(vi* v, int new_size) {
    if (new_size > v->capacity) {
        v->capacity = new_size;
        v->data = (int*)realloc(v->data, v->capacity * sizeof(int));
    }
    v->size = new_size;
}

void vi_push_back(vi* v, int value) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = (int*)realloc(v->data, v->capacity * sizeof(int));
    }
    v->data[v->size] = value;
    v->size++;
}

void vs_init(vs* v) {
    v->size = 0;
    v->capacity = 1;
    v->data = (char**)malloc(v->capacity * sizeof(char*));
}

void vs_resize(vs* v, int new_size) {
    if (new_size > v->capacity) {
        v->capacity = new_size;
        v->data = (char**)realloc(v->data, v->capacity * sizeof(char*));
    }
    v->size = new_size;
}

void vs_push_back(vs* v, char* value) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = (char**)realloc(v->data, v->capacity * sizeof(char*));
    }
    v->data[v->size] = value;
    v->size++;
}

void vc_init(vc* v) {
    v->size = 0;
    v->capacity = 1;
    v->data = (char*)malloc(v->capacity * sizeof(char));
}

void vc_resize(vc* v, int new_size) {
    if (new_size > v->capacity) {
        v->capacity = new_size;
        v->data = (char*)realloc(v->data, v->capacity * sizeof(char));
    }
    v->size = new_size;
}

void vc_push_back(vc* v, char value) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = (char*)realloc(v->data, v->capacity * sizeof(char));
    }
    v->data[v->size] = value;
    v->size++;
}

void vb_init(vb* v) {
    v->size = 0;
    v->capacity = 1;
    v->data = (bool*)malloc(v->capacity * sizeof(bool));
}

void vb_resize(vb* v, int new_size) {
    if (new_size > v->capacity) {
        v->capacity = new_size;
        v->data = (bool*)realloc(v->data, v->capacity * sizeof(bool));
    }
    v->size = new_size;
}

void vb_push_back(vb* v, bool value) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = (bool*)realloc(v->data, v->capacity * sizeof(bool));
    }
    v->data[v->size] = value;
    v->size++;
}

int getbit(int s, int i) {
    return (s >> i) & 1;
}

int onbit(int s, int i) {
    return s | (1 << i);
}

int offbit(int s, int i) {
    return s & (~(1 << i));
}

int cntbit(int s) {
    int count = 0;
    while (s > 0) {
        count += s & 1;
        s >>= 1;
    }
    return count;
}

void proceed_virus(vs* next_common_prefix, int nv, char* virus) {
    vs_resize(next_common_prefix, nv);
    for (int i = 0; i < nv; i++) {
        for (int j = 0; j < 26; j++) {
            char* pref2 = (char*)malloc((i + 2) * sizeof(char));
            strncpy(pref2, virus, i);
            pref2[i] = 'A' + j;
            pref2[i + 1] = '\0';
            for (int x = i + 1; x >= 0; x--) {
                if (strncmp(pref2 + i + 1 - x, virus, x) == 0) {
                    next_common_prefix->data[i][j] = x;
                    break;
                }
            }
            free(pref2);
        }
    }
}

void input(char* s1, char* s2, char* virus, int* n1, int* n2, int* nv) {
    scanf("%s %s %s", s1, s2, virus);
    *n1 = strlen(s1);
    *n2 = strlen(s2);
    *nv = strlen(virus);
}

void solve(char* s1, char* s2, char* virus, int n1, int n2, int nv) {
    vs next_common_prefix;
    vs_init(&next_common_prefix);
    proceed_virus(&next_common_prefix, nv, virus);

    vi list1[26];
    vi list2[26];
    for (int i = 0; i < n1; i++) {
        vi_push_back(&list1[s1[i] - 'A'], i);
    }
    for (int i = 0; i < n2; i++) {
        vi_push_back(&list2[s2[i] - 'A'], i);
    }

    vb dp[MAX_SIZE][MAX_SIZE][MAX_SIZE + 1][nv + 1];
    ppp last[MAX_SIZE][MAX_SIZE][MAX_SIZE + 1][nv + 1];
    ppp default_value;
    default_value.first.first = -1;
    default_value.first.second = -1;
    default_value.second.first = -1;
    default_value.second.second = -1;

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (s1[i] == s2[j]) {
                dp[i][j][1][next_common_prefix.data[0][s1[i] - 'A']] = true;
            } else {
                dp[i][j][0][0] = true;
            }
        }
    }

    for (int x = 1; x < (n1 < n2 ? n1 : n2); x++) {
        for (int i = 0; i < n1 - 1; i++) {
            for (int j = 0; j < n2 - 1; j++) {
                for (int y = 0; y < nv; y++) {
                    if (!dp[i][j][x][y]) {
                        continue;
                    }
                    for (int z = 0; z < 26; z++) {
                        if (list1[z].size == 0 || list2[z].size == 0) {
                            continue;
                        }
                        int i1 = list1[z].data[0];
                        int j1 = list2[z].data[0];
                        for (int k = 1; k < list1[z].size; k++) {
                            if (list1[z].data[k] > i) {
                                i1 = list1[z].data[k];
                                break;
                            }
                        }
                        for (int k = 1; k < list2[z].size; k++) {
                            if (list2[z].data[k] > j) {
                                j1 = list2[z].data[k];
                                break;
                            }
                        }
                        dp[i1][j1][x + 1][next_common_prefix.data[y][z]] = true;
                        last[i1][j1][x + 1][next_common_prefix.data[y][z]].first.first = i;
                        last[i1][j1][x + 1][next_common_prefix.data[y][z]].first.second = j;
                        last[i1][j1][x + 1][next_common_prefix.data[y][z]].second.first = x;
                        last[i1][j1][x + 1][next_common_prefix.data[y][z]].second.second = y;
                    }
                }
            }
        }
    }

    for (int x = (n1 < n2 ? n1 : n2); x > 0; x--) {
        for (int y = 0; y < nv; y++) {
            for (int i = 0; i < n1; i++) {
                for (int j = 0; j < n2; j++) {
                    if (!dp[i][j][x][y]) {
                        continue;
                    }
                    int I = i;
                    int J = j;
                    int X = x;
                    int Y = y;
                    char* s = (char*)malloc((X + 1) * sizeof(char));
                    int idx = 0;
                    while (I != -1) {
                        s[idx] = s1[I];
                        I = last[I][J][X][Y].first.first;
                        J = last[I][J][X][Y].first.second;
                        X = last[I][J][X][Y].second.first;
                        Y = last[I][J][X][Y].second.second;
                        idx++;
                    }
                    s[idx] = '\0';
                    printf("%s\n", s);
                    free(s);
                    return;
                }
            }
        }
    }

    printf("0\n");
}

int main() {
    char s1[MAX_SIZE];
    char s2[MAX_SIZE];
    char virus[MAX_SIZE];
    int n1, n2, nv;

    input(s1, s2, virus, &n1, &n2, &nv);
    solve(s1, s2, virus, n1, n2, nv);

    return 0;
}
