#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000007

typedef long long int i64;
typedef long double ld;

typedef struct {
    i64 first;
    i64 second;
} pii;

typedef struct {
    pii first;
    pii second;
} pip;

typedef struct {
    pii first;
    pii second;
} ppi;

const i64 Mod = 1000000007LL, INF = 1e9, LINF = 1e18;
const ld Pi = 3.141592653589793116, EPS = 1e-9, Gold = ((1+sqrt(5))/2);
i64 keymod[] = {1000000007LL, 1000000009LL, 1000000021LL, 1000000033LL};
i64 keyCount = sizeof(keymod) / sizeof(i64);

typedef struct {
    i64 size;
    i64 capacity;
    i64* data;
} vector;

void vector_init(vector* v) {
    v->size = 0;
    v->capacity = 1;
    v->data = (i64*)malloc(sizeof(i64) * v->capacity);
}

void vector_push_back(vector* v, i64 value) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = (i64*)realloc(v->data, sizeof(i64) * v->capacity);
    }
    v->data[v->size++] = value;
}

void vector_resize(vector* v, i64 size) {
    if (size > v->capacity) {
        v->capacity = size;
        v->data = (i64*)realloc(v->data, sizeof(i64) * v->capacity);
    }
    v->size = size;
}

void vector_free(vector* v) {
    free(v->data);
    v->size = 0;
    v->capacity = 0;
}

typedef struct {
    i64 size;
    i64 capacity;
    char* data;
} string;

void string_init(string* s) {
    s->size = 0;
    s->capacity = 1;
    s->data = (char*)malloc(sizeof(char) * s->capacity);
}

void string_push_back(string* s, char value) {
    if (s->size == s->capacity) {
        s->capacity *= 2;
        s->data = (char*)realloc(s->data, sizeof(char) * s->capacity);
    }
    s->data[s->size++] = value;
}

void string_resize(string* s, i64 size) {
    if (size > s->capacity) {
        s->capacity = size;
        s->data = (char*)realloc(s->data, sizeof(char) * s->capacity);
    }
    s->size = size;
}

void string_free(string* s) {
    free(s->data);
    s->size = 0;
    s->capacity = 0;
}

i64 max(i64 a, i64 b) {
    return (a > b) ? a : b;
}

i64 min(i64 a, i64 b) {
    return (a < b) ? a : b;
}

i64 getbit(i64 s, i64 i) {
    return (s >> i) & 1;
}

i64 onbit(i64 s, i64 i) {
    return s | (1LL << i);
}

i64 offbit(i64 s, i64 i) {
    return s & (~(1LL << i));
}

i64 cntbit(i64 s) {
    i64 count = 0;
    while (s > 0) {
        count += s & 1;
        s >>= 1;
    }
    return count;
}

void proceed_virus(vector* id1, string* virus, i64 nv) {
    vector_resize(id1, nv);
    for (i64 i = 0; i < nv; i++) {
        vector_resize(&id1[i], 26);
        for (i64 j = 0; j < 26; j++) {
            string pref2;
            string_init(&pref2);
            for (i64 k = 0; k < i; k++) {
                string_push_back(&pref2, virus->data[k]);
            }
            string_push_back(&pref2, 65 + j);
            for (i64 x = i + 1; x >= 0; x--) {
                i64 equal = 1;
                for (i64 y = 0; y < x; y++) {
                    if (pref2.data[i + 1 - x + y] != virus->data[y]) {
                        equal = 0;
                        break;
                    }
                }
                if (equal) {
                    vector_push_back(&id1[i], x);
                    break;
                }
            }
            string_free(&pref2);
        }
    }
}

void input(string* s1, string* s2, string* virus, i64* n1, i64* n2, i64* nv) {
    scanf("%s", s1->data);
    scanf("%s", s2->data);
    scanf("%s", virus->data);
    *n1 = strlen(s1->data);
    *n2 = strlen(s2->data);
    *nv = strlen(virus->data);
}

void solve(string* s1, string* s2, string* virus, i64 n1, i64 n2, i64 nv) {
    vector id1;
    vector_init(&id1);
    proceed_virus(&id1, virus, nv);
    vector List1[26], List2[26];
    for (i64 i = 0; i < n1; i++) {
        vector_push_back(&List1[s1->data[i] - 'A'], i);
    }
    for (i64 i = 0; i < n2; i++) {
        vector_push_back(&List2[s2->data[i] - 'A'], i);
    }
    vector dp[n1][n2][min(n1, n2) + 1];
    pip Default = {{-1, -1}, {-1, -1}};
    for (i64 i = 0; i < n1; i++) {
        for (i64 j = 0; j < n2; j++) {
            vector_resize(&dp[i][j][1], nv + 1);
            for (i64 k = 0; k < nv + 1; k++) {
                dp[i][j][1].data[k] = 0;
            }
            if (s1->data[i] == s2->data[j]) {
                dp[i][j][1].data[id1.data[0].data[s1->data[i] - 'A']] = 1;
            } else {
                dp[i][j][0].data[0] = 1;
            }
        }
    }
    for (i64 x = 1; x < min(n1, n2); x++) {
        for (i64 i = 0; i < n1 - 1; i++) {
            for (i64 j = 0; j < n2 - 1; j++) {
                for (i64 y = 0; y < nv; y++) {
                    if (!dp[i][j][x].data[y]) {
                        continue;
                    }
                    for (i64 z = 0; z < 26; z++) {
                        if (vector_size(&List1[z]) == 0 || vector_size(&List2[z]) == 0) {
                            continue;
                        }
                        i64 i1 = List1[z].data[vector_size(&List1[z]) - 1];
                        i64 j1 = List2[z].data[vector_size(&List2[z]) - 1];
                        if (i1 <= i || j1 <= j) {
                            continue;
                        }
                        dp[i1][j1][x + 1].data[id1.data[y].data[z]] = 1;
                        Default.first.first = i;
                        Default.first.second = j;
                        Default.second.first = x;
                        Default.second.second = y;
                    }
                }
            }
        }
    }
    for (i64 x = min(n1, n2); x > 0; x--) {
        for (i64 y = 0; y < nv; y++) {
            for (i64 i = 0; i < n1; i++) {
                for (i64 j = 0; j < n2; j++) {
                    if (!dp[i][j][x].data[y]) {
                        continue;
                    }
                    i64 I = i, J = j, X = x, Y = y;
                    string s;
                    string_init(&s);
                    while (I != -1) {
                        string_push_back(&s, s1->data[I]);
                        pip Token = Default;
                        I = Token.first.first;
                        J = Token.first.second;
                        X = Token.second.first;
                        Y = Token.second.second;
                    }
                    printf("%s\n", s.data);
                    return;
                }
            }
        }
    }
    printf("0\n");
}

int main() {
    string s1, s2, virus;
    i64 n1, n2, nv;
    string_init(&s1);
    string_init(&s2);
    string_init(&virus);
    input(&s1, &s2, &virus, &n1, &n2, &nv);
    solve(&s1, &s2, &virus, n1, n2, nv);
    string_free(&s1);
    string_free(&s2);
    string_free(&virus);
    return 0;
}
