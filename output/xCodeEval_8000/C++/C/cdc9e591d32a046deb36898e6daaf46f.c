#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <limits.h>

typedef long long int int64;
typedef unsigned long long int uint64;

#define DOUBLE_INF INFINITY
#define DOUBLE_NAN NAN

#define STR(a) #a

#define ASSERT(expr, msg) \
    if (!( expr )) \
        throw std::runtime_error(__FILE__ ":" STR(__LINE__) " - " msg);

typedef struct ScopeTimer {
    clock_t tic;
    const char* msg;
} ScopeTimer;

ScopeTimer* create_ScopeTimer(const char* msg) {
    ScopeTimer* timer = malloc(sizeof(ScopeTimer));
    timer->msg = msg;
    timer->tic = clock();
    return timer;
}

void destroy_ScopeTimer(ScopeTimer* timer) {
    free(timer);
}

void print_ScopeTimer(ScopeTimer* timer) {
    clock_t toc = clock();
    uint64 dt = 1000L * (toc - timer->tic) / CLOCKS_PER_SEC;

    uint64 mil = dt % 1000L;
    uint64 sec = (dt / 1000L) % 60L;
    uint64 min = (dt / 60000L) % 60L;
    uint64 hrs = (dt / 3600000L);

    printf("\n%s\n\telapsed time: ", timer->msg);

    if (hrs)
        printf("%llu hrs, ", hrs);
    if (min)
        printf("%llu min, ", min);
    if (sec)
        printf("%llu sec, ", sec);
    printf("%llu mil-sec\n", mil);
}

void b303() {
    int64 n, m, x, y, a, b;
    scanf("%lld %lld %lld %lld %lld %lld", &n, &m, &x, &y, &a, &b);

    int64 g = gcd(a, b);
    a /= g;
    b /= g;

    printf("gcd: %lld\n", g);
    printf("a: %lld\n", a);
    printf("b: %lld\n", b);

    int64 k = min(m / b, n / a);
    int64 width = k * a;
    int64 height = k * b;

    printf("k: %lld\n", k);
    printf("width: %lld\n", width);
    printf("height: %lld\n", height);

    int64 x1 = max(x - (width + 1) / 2, 0LL);
    int64 x2 = min(x1 + width, n);
    x1 = x2 - width;

    int64 y1 = max(y - (height + 1) / 2, 0LL);
    int64 y2 = min(y1 + height, m);
    y1 = y2 - height;

    printf("%lld %lld %lld %lld\n", x1, y1, x2, y2);
}

bool xsolve(const size_t w, const size_t j, const size_t t,
        const size_t jump_size,
        const char** wall,
        bool** tag,
        size_t n,
        size_t m,
        set < tuple < size_t, size_t, size_t > > & cache)
{
    if (! (j < n))
        return true;
    else if (j < t || wall[w][j] != '-')
        return false;
    else
    {
        const auto tpl = make_tuple(w, j, t);
        printf("tpl: (%zu, %zu, %zu)\n", get<0>(tpl), get<1>(tpl), get<2>(tpl));

        auto iter = cache.lower_bound(tpl);

        if (*iter != tpl)
            --iter;
        else
            return false;

        if (get<0>(*iter) == w && get<1>(*iter) == j && get<2>(*iter) <= t)
            return false;

        cache.insert(tpl);
        if (xsolve(1 - w, j + jump_size, t + 1, jump_size, wall, tag, n, m, cache)
                || xsolve(w, j + 1, t + 1, jump_size, wall, tag, n, m, cache)
                || (j > 0 && xsolve(w, j - 1, t + 1, jump_size, wall, tag, n, m, cache)))
            return true;

        return false;
    }
}

const char* _b198() {
    size_t n, k;
    scanf("%zu %zu", &n, &k);
    char** wall = malloc(2 * sizeof(char*));
    wall[0] = malloc((n + 1) * sizeof(char));
    wall[1] = malloc((n + 1) * sizeof(char));
    scanf("%s %s", wall[0], wall[1]);

    typedef tuple<size_t, size_t, size_t> loc_type;
    set<loc_type> cache;

    const auto INF = SIZE_MAX;

    cache.insert(make_tuple(0, 0, INF));
    cache.insert(make_tuple(1, n, INF));

    const auto flag = xsolve(1, k, 1, k, (const char**)wall, NULL, n, 2, cache) || xsolve(0, 1, 1, k, (const char**)wall, NULL, n, 2, cache);

    return flag ? "YES" : "NO";
}

const char* b198() {
    size_t n, k;

    scanf("%zu %zu", &n, &k);
    char** wall = malloc(2 * sizeof(char*));
    wall[0] = malloc((n + 1) * sizeof(char));
    wall[1] = malloc((n + 1) * sizeof(char));
    scanf("%s %s", wall[0], wall[1]);

    bool** tag = malloc(2 * sizeof(bool*));
    tag[0] = malloc(n * sizeof(bool));
    tag[1] = malloc(n * sizeof(bool));
    for (size_t i = 0; i < 2; ++i) {
        for (size_t j = 0; j < n; ++j) {
            tag[i][j] = wall[i][j] == 'X';
        }
    }

    typedef tuple<size_t, size_t, size_t> loc_type;
    set<loc_type> cache;

    cache.insert(make_tuple(0, 0, SIZE_MAX));
    cache.insert(make_tuple(1, n, SIZE_MAX));

    queue<loc_type> q;
    q.push(make_tuple(0, 0, 0));

    while (!q.empty()) {
        const auto w = get<0>(q.front());
        const auto j = get<1>(q.front());
        const auto t = get<2>(q.front());
        q.pop();

        if (n < j + 1 + k)
            return "YES";

        if (!tag[w][j + 1]) {
            tag[w][j + 1] = true;
            q.push(make_tuple(w, j + 1, t + 1));
        }

        if (j > 0 && t + 1 < j && !tag[w][j - 1]) {
            tag[w][j - 1] = true;
            q.push(make_tuple(w, j - 1, t + 1));
        }

        if (!tag[1 - w][j + k]) {
            tag[1 - w][j + k] = true;
            q.push(make_tuple(1 - w, j + k, t + 1));
        }
    }

    return "NO";
}

size_t a442() {
    size_t n;
    scanf("%zu", &n);
    char** xs = malloc(n * sizeof(char*));
    for (size_t i = 0; i < n; ++i) {
        xs[i] = malloc(3 * sizeof(char));
        scanf("%s", xs[i]);
    }

    typedef struct {
        char ch;
        size_t count;
    } char_count;

    char_count* counts = malloc(n * sizeof(char_count));
    for (size_t i = 0; i < n; ++i) {
        counts[i].ch = xs[i][0];
        counts[i].count = 0;
    }

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if (xs[j][1] == counts[i].ch) {
                ++counts[i].count;
            }
        }
    }

    size_t total = 0;
    for (size_t i = 0; i < n; ++i) {
        total += counts[i].count;
    }

    size_t result = total;
    for (size_t i = 0; i < n; ++i) {
        size_t count = total - counts[i].count + 1;
        if (counts[i].count > 1) {
            count += 1;
        }
        if (count < result) {
            result = count;
        }
    }

    return result;
}

uint64 a163() {
    char* subj = malloc(100001 * sizeof(char));
    char* targ = malloc(100001 * sizeof(char));
    scanf("%s %s", subj, targ);

    typedef struct {
        char ch;
        size_t count;
    } char_count;

    char_count* counts = malloc(26 * sizeof(char_count));
    for (size_t i = 0; i < 26; ++i) {
        counts[i].ch = 'a' + i;
        counts[i].count = 0;
    }

    for (size_t i = 0; i < strlen(subj); ++i) {
        ++counts[subj[i] - 'a'].count;
    }

    uint64* soln = malloc((strlen(targ) + 1) * sizeof(uint64));
    uint64* xsoln = malloc((strlen(targ) + 1) * sizeof(uint64));
    const auto m = 1000000007ULL;

    for (size_t i = 0; i < strlen(targ); ++i) {
        soln[i + 1] = (1 + xsoln[i]) % m;
        for (size_t j = 0; j < 26; ++j) {
            if (targ[i] == counts[j].ch) {
                soln[i + 1] = (soln[i + 1] + m - counts[j].count) % m;
            }
        }
        xsoln[i + 1] = (xsoln[i] + soln[i + 1]) % m;
    }

    return soln[strlen(targ)];
}

int main(const int argc, char* argv[]) {
    printf("%llu\n", a163());

    return EXIT_SUCCESS;
}
