#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct {
    int x;
    int y;
    int r;
} Circle;

typedef struct {
    long k;
    long b;
} Line;

typedef struct {
    double angle;
    int type;
} Point;

typedef struct {
    int x1;
    int y1;
    int x2;
    int y2;
} Rect;

typedef struct {
    long x;
    long y;
} Pair;

typedef struct {
    long x;
    long y;
} Fraction;

typedef struct {
    int* div;
    int* primes;
} id5;

typedef struct {
    int x;
    int y;
} Pair;

typedef struct {
    int* sum;
} id6;

typedef struct {
    int pow;
    long* max;
    long* delta;
    bool* flag;
} id3;

long mod = 1000000007;

long pow(long x, long p, long mod) {
    if (p <= 0) {
        return 1;
    }
    long th = pow(x, p / 2, mod);
    th *= th;
    th %= mod;
    if (p % 2 == 1) {
        th *= x;
    }
    return th;
}

Fraction createFraction(long x, long y) {
    Fraction fraction;
    fraction.x = x;
    fraction.y = y;
    return fraction;
}

void norm(Fraction* fraction) {
    long gcd = gcd(fraction->x, fraction->y);
    fraction->x /= gcd;
    fraction->y /= gcd;
}

int compareTo(Fraction* a, Fraction* b) {
    if (a->x > b->x) {
        return 1;
    }
    if (a->x < b->x) {
        return -1;
    }
    if (a->y > b->y) {
        return 1;
    }
    if (a->y < b->y) {
        return -1;
    }
    return 0;
}

Fraction sum(Fraction* a, Fraction* b) {
    Fraction c;
    c.x = a->x * b->y + a->y * b->x;
    c.y = a->y * b->y;
    norm(&c);
    return c;
}

long gcd(long x, long y) {
    if (y == 0) {
        return x;
    }
    if (x == 0) {
        return y;
    }
    return gcd(y, x % y);
}

Pair createPair(int x, int y) {
    Pair pair;
    pair.x = x;
    pair.y = y;
    return pair;
}

Pair clonePair(Pair* p) {
    Pair pair;
    pair.x = p->x;
    pair.y = p->y;
    return pair;
}

int compareToPair(Pair* a, Pair* b) {
    if (a->x > b->x) {
        return 1;
    }
    if (a->x < b->x) {
        return -1;
    }
    if (a->y > b->y) {
        return 1;
    }
    if (a->y < b->y) {
        return -1;
    }
    return 0;
}

int in(int min, int max, int x) {
    if (x == min || x == max) {
        return 1;
    }
    if (x > min && x < max) {
        return 2;
    }
    return 0;
}

int sum(int x, int y) {
    if (x + y >= mod) {
        return x + y - mod;
    }
    return x + y;
}

long mult(long x, long y) {
    return x * y % mod;
}

long div(long x, long y) {
    return x * modInv(y) % mod;
}

int modInv(long x) {
    return pow(x, mod - 2);
}

int next(int* th, int* max, int len) {
    for (int i = len - 1; i >= 0; i--) {
        if (th[i] != max[i]) {
            th[i]++;
            for (int j = i + 1; j < len; j++) {
                th[j] = 0;
            }
            return 1;
        }
    }
    return 0;
}

id5 createId5(int max) {
    id5 id;
    id.div = (int*)malloc((max + 1) * sizeof(int));
    id.primes = (int*)malloc((max + 1) * sizeof(int));
    for (int i = 2; i <= max; i++) {
        if (id.div[i] == 0) {
            id.div[i] = i;
            id.primes[i] = i;
        }
        for (int j = 0; j < id.primes[i] && i * id.primes[j] <= max; j++) {
            id.div[i * id.primes[j]] = id.primes[j];
            if (id.primes[j] == id.div[i]) {
                break;
            }
        }
    }
    return id;
}

int* factorization(id5* id, int x, int* len) {
    int* ans = (int*)malloc(100 * sizeof(int));
    *len = 0;
    while (id->div[x] > 0) {
        ans[*len] = id->div[x];
        (*len)++;
        x /= id->div[x];
    }
    return ans;
}

int* id1(id5* id, int x, int* len) {
    int* div = factorization(id, x, len);
    int* ans = (int*)malloc(100 * sizeof(int));
    int size = 0;
    for (int mask = 0; mask < (1 << *len); mask++) {
        int th = 1;
        for (int i = 0; i < *len; i++) {
            if ((mask & (1 << i)) > 0) {
                th *= div[i];
            }
        }
        ans[size++] = th;
    }
    *len = size;
    return ans;
}

int* id0(id5* id, int x, int* len) {
    int* div = factorization(id, x, len);
    int pr = 0;
    for (int i = 0; i < *len; i++) {
        if (i == 0 || div[i] != div[i - 1]) {
            pr++;
        }
    }
    int* primes = (int*)malloc(pr * sizeof(int));
    int* sz = (int*)malloc(pr * sizeof(int));
    pr = -1;
    for (int i = 0; i < *len; i++) {
        if (i == 0 || div[i] != div[i - 1]) {
            pr++;
            primes[pr] = div[i];
            sz[pr] = 1;
        } else {
            sz[pr]++;
        }
    }
    pr++;
    int** pow = (int**)malloc(pr * sizeof(int*));
    for (int i = 0; i < pr; i++) {
        pow[i] = (int*)malloc((sz[i] + 1) * sizeof(int));
        pow[i][0] = 1;
        for (int j = 1; j <= sz[i]; j++) {
            pow[i][j] = pow[i][j - 1] * primes[i];
        }
    }
    int* th = (int*)malloc(pr * sizeof(int));
    int* ans = (int*)malloc(100 * sizeof(int));
    int size = 0;
    do {
        int z = 1;
        for (int i = 0; i < pr; i++) {
            z *= pow[i][th[i]];
        }
        ans[size++] = z;
    } while (next(th, sz, pr));
    *len = size;
    return ans;
}

char* id2(id5* id, int x) {
    if (x == 1) {
        char* ans = (char*)malloc(10 * sizeof(char));
        sprintf(ans, "1 = 1");
        return ans;
    }
    int len;
    int* list = factorization(id, x, &len);
    char* ans = (char*)malloc(100 * sizeof(char));
    sprintf(ans, "%d = ", x);
    for (int i = 0; i < len; i++) {
        char* temp = (char*)malloc(10 * sizeof(char));
        sprintf(temp, "%d", list[i]);
        strcat(ans, temp);
        if (i < len - 1) {
            strcat(ans, " * ");
        }
        free(temp);
    }
    return ans;
}

id6 createId6(int n) {
    id6 id;
    id.sum = (long*)malloc(n * sizeof(long));
    return id;
}

void add(id6* id, int x, long d) {
    for (int i = x; i < sizeof(id->sum) / sizeof(id->sum[0]); i = (i | (i + 1))) {
        id->sum[i] += d;
    }
}

long sum(id6* id, int r) {
    long ans = 0;
    for (int i = r; i >= 0; i = (i & (i + 1)) - 1) {
        ans += id->sum[i];
    }
    return ans;
}

long sumRange(id6* id, int l, int r) {
    if (l > r) {
        return 0;
    }
    return sum(id, r) - sum(id, l - 1);
}

id3 createId3(int n) {
    id3 id;
    id.pow = 1;
    while (id.pow < n) {
        id.pow *= 2;
    }
    id.flag = (bool*)malloc(2 * id.pow * sizeof(bool));
    id.max = (long*)malloc(2 * id.pow * sizeof(long));
    id.delta = (long*)malloc(2 * id.pow * sizeof(long));
    for (int i = 0; i < 2 * id.pow; i++) {
        id.max[i] = LONG_MIN / 2;
    }
    return id;
}

void add(id3* id, int v, int l, int r, Line line) {
    if (id->ch[v] == NULL) {
        id->ch[v] = line;
        return;
    }
    if (v >= id->pow) {
        if (v % 2 == 0) {
            if (line.value(l) < id->ch[v].value(l)) {
                id->ch[v] = line;
            }
        } else {
            if (line.value(r) < id->ch[v].value(r)) {
                id->ch[v] = line;
            }
        }
        return;
    }
    int m = (l + r) / 2;
    if (line.value(m) < id->ch[v].value(m)) {
        Line c = line;
        line = id->ch[v];
        id->ch[v] = c;
    }
    if (line.value(l) < id->ch[v].value(l)) {
        add(id, 2 * v, l, m, line);
    }
    if (line.value(r) < id->ch[v].value(r)) {
        add(id, 2 * v + 1, m, r, line);
    }
}

void addLine(id3* id, Line line) {
    add(id, 1, 0, id->pow, line);
}

long get(id3* id, int v, int l, int r, int x) {
    if (id->ch[v] == NULL) {
        return id->neutral;
    }
    if (v >= id->pow) {
        return id->ch[v].value(x);
    }
    long ans = id->ch[v].value(x);
    int m = (l + r) / 2;
    if (x <= m) {
        ans = id->function(ans, get(id, 2 * v, l, m, x));
    }
    if (x >= m) {
        ans = id->function(ans, get(id, 2 * v + 1, m, r, x));
    }
    return ans;
}

long getValue(id3* id, int x) {
    return get(id, 1, 0, id->pow, x);
}

int compareCircles(Circle* a, Circle* b) {
    if (a->r != b->r) {
        return a->r - b->r;
    }
    if (a->x != b->x) {
        return a->x - b->x;
    }
    return a->y - b->y;
}

bool inside(Circle* small, Circle* big) {
    return (small->x - big->x) * (small->x - big->x) + (small->y - big->y) * (small->y - big->y) <= (big->r - small->r) * (big->r - small->r);
}

double* tangent(Circle* c1, Circle* c2) {
    Circle a = *c1;
    Circle b = *c2;
    int minr = fmin(a.r, b.r);
    a.r -= minr;
    b.r -= minr;
    b.x -= a.x;
    b.y -= a.y;
    double a0 = atan2(b.y, b.x);
    double len = sqrt(b.x * b.x + b.y * b.y);
    double da = 0;
    if (a.r == 0) {
        da = asin(b.r / len) + M_PI / 2;
    } else {
        da = acos(a.r / len);
    }
    double* ans = (double*)malloc(2 * sizeof(double));
    ans[0] = a0 - da;
    ans[1] = a0 + da;
    return ans;
}

double* norm(double* ans) {
    for (int i = 0; i < 2; i++) {
        while (ans[i] < 0) {
            ans[i] += 2 * M_PI;
        }
        while (ans[i] > 2 * M_PI) {
            ans[i] -= 2 * M_PI;
        }
    }
    if (ans[0] > ans[1]) {
        double* answer = (double*)malloc(4 * sizeof(double));
        answer[0] = 0;
        answer[1] = ans[1];
        answer[2] = ans[0];
        answer[3] = 2 * M_PI;
        return answer;
    }
    return ans;
}

bool mergeSort(char* s, int* a, int l, int r, int x) {
    if (r - l <= 1) {
        return true;
    }
    int m = (l + r) >> 1;
    if (!mergeSort(s, a, l, m, x)) {
        return false;
    }
    if (!mergeSort(s, a, m, r, x)) {
        return false;
    }
    int i = l;
    int j = m;
    int k = l;
    while (i < m && j < r) {
        if (x == strlen(s)) {
            return false;
        }
        if (s[x++] == '0') {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
        }
    }
    while (i < m) {
        b[k++] = a[i++];
    }
    while (j < r) {
        b[k++] = a[j++];
    }
    for (int p = l; p < r; p++) {
        a[p] = b[p];
    }
    return true;
}

int* rev(int* a, int len) {
    int* res = (int*)malloc(len * sizeof(int));
    for (int i = 0; i < len; ++i) {
        res[a[i]] = i;
    }
    return res;
}

void solve() {
    char* s = (char*)malloc(100 * sizeof(char));
    scanf("%s", s);
    for (int sz = 1;; sz++) {
        int* a = (int*)malloc(sz * sizeof(int));
        for (int i = 0; i < sz; i++) {
            a[i] = i;
        }
        x = 0;
        b = (int*)malloc(sz * sizeof(int));
        if (!mergeSort(s, a, 0, sz, x)) {
            continue;
        }
        if (x < strlen(s)) {
            continue;
        }
        a = rev(a, sz);
        printf("%d\n", sz);
        for (int i = 0; i < sz; i++) {
            printf("%d ", a[i] + 1);
        }
        return;
    }
}

int main() {
    solve();
    return 0;
}
