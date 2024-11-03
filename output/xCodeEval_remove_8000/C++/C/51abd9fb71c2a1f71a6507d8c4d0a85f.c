#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define i64 long long
#define ld long double

typedef struct {
    i64 fi;
    i64 se;
} pii;

typedef struct {
    i64 fi;
    pii se;
} pip;

typedef struct {
    pii fi;
    i64 se;
} ppi;

#define vector(type) type*

#define vector_init() (type*)malloc(sizeof(type))

#define vector_push_back(vec, val) \
    do { \
        vec = (type*)realloc(vec, sizeof(type) * (vec##_size + 1)); \
        vec[vec##_size++] = val; \
    } while (0)

#define vector_size(vec) vec##_size

#define vector_get(vec, idx) vec[idx]

#define vector_free(vec) free(vec)

const long long Mod = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double Pi = 3.141592653589793116, EPS = 1e-9, Gold = ((1+sqrt(5))/2);
long long keymod[] = {1000000007LL, 1000000009LL, 1000000021LL, 1000000033LL};
long long keyCount = sizeof(keymod) / sizeof(long long);

int getbit(i64 s, int i) { return (s >> i) & 1; }

i64 onbit(i64 s, int i) { return s | (1LL << i); }

i64 offbit(i64 s, int i) { return s & (~(1LL << i)); }

int cntbit(i64 s) { return __builtin_popcountll(s); }

void ControlIO(int argc, char* argv[]);
void TimerStart();
void TimerStop();
void Exit();
char* id0 = "FILE.IN";
char* id1 = "FILE.OUT";

i64 n, Min = LINF, Max = -LINF;
vector(pii) A;

i64 Pow(i64 a, i64 b) {
    if (b == 0) return 1;
    i64 tmp = Pow(a, b/2);
    if (b % 2 == 0) return (tmp * tmp);
    return (tmp * tmp * a);
}

void Try(i64 id, i64 x1, i64 x2, i64 x3) {
    if (id == vector_size(A)) {
        Min = (Min < (x1+1)*(x2+2)*(x3+2)) ? Min : (x1+1)*(x2+2)*(x3+2);
        Min = (Min < (x1+2)*(x2+1)*(x3+2)) ? Min : (x1+2)*(x2+1)*(x3+2);
        Min = (Min < (x1+2)*(x2+2)*(x3+1)) ? Min : (x1+2)*(x2+2)*(x3+1);
        Max = (Max > (x1+1)*(x2+2)*(x3+2)) ? Max : (x1+1)*(x2+2)*(x3+2);
        Max = (Max > (x1+2)*(x2+1)*(x3+2)) ? Max : (x1+2)*(x2+1)*(x3+2);
        Max = (Max > (x1+2)*(x2+2)*(x3+1)) ? Max : (x1+2)*(x2+2)*(x3+1);
        return;
    }
    i64 key = vector_get(A, id).fi;
    i64 v = vector_get(A, id).se;
    for (i64 i=0; i<=v; i++) {
        for (i64 j=0; j<=v; j++) {
            for (i64 k=0; k<=v; k++) {
                if (i + j + k != v) continue;
                Try(id+1, x1 * Pow(key, i), x2 * Pow(key, j), x3 * Pow(key, k));
            }
        }
    }
}

void Input() {
    scanf("%lld", &n);
}

void Solve() {
    vector(pii) Map = vector_init();
    i64 N = n;
    for (i64 i=2; i<=sqrt(n); i++) {
        while (n % i == 0) {
            vector_push_back(Map, (pii){i, 0});
            n /= i;
        }
    }
    if (n > 1) vector_push_back(Map, (pii){n, 0});
    for (i64 i=0; i<vector_size(Map); i++) {
        i64 k = vector_get(Map, i).fi;
        i64 v = vector_get(Map, i).se;
        vector_push_back(A, (pii){k, v});
    }
    Try(0, 1, 1, 1);
    printf("%lld %lld", Min - N, Max - N);
}

int main(int argc, char* argv[]) {
    ControlIO(argc, argv);

    Input();
    TimerStart();
    Solve();
    TimerStop();

    int T;
    scanf("%d", &T);
    TimerStart();
    while(T--) {
        Input();
        Solve();
    }
    TimerStop();

    return 0;
}

void ControlIO(int argc, char* argv[]) {
    char* infile = (char*)malloc(sizeof(char) * (strlen(id0) + 1));
    char* outfile = (char*)malloc(sizeof(char) * (strlen(id1) + 1));
    strcpy(infile, id0);
    strcpy(outfile, id1);

    time_t t = time(0);
    struct tm* now = localtime(&t);
    printf("Source code by\n");
    printf("Current time: ");
    printf("%d-", now->tm_year + 1900);
    printf("%s%d-", (now->tm_mon < 9) ? "0" : "", now->tm_mon + 1);
    printf("%s%d | ", (now->tm_mday < 10) ? "0" : "", now->tm_mday);
    printf("%s%d:", (now->tm_hour < 10) ? "0" : "", now->tm_hour);
    printf("%s%d:", (now->tm_min < 10) ? "0" : "", now->tm_min);
    printf("%s%d", (now->tm_sec < 10) ? "0" : "", now->tm_sec);
    printf("\n\n");

    printf("OI-Mode: ON\n");
    printf("Input file: %s\n", infile);
    printf("Output file: %s\n", outfile);
    printf("\n");

    printf("OI-Mode: OFF\n");
    printf("Input file: NULL\n");
    printf("Output file: NULL\n");
    printf("\n");

    printf("MultiTest-Mode: ON\n");

    printf("MultiTest-Mode: OFF\n");

    printf("Interactive-Mode: ON\n\n");

    printf("Interactive-Mode: OFF\n\n");

    if (argc > 1) freopen(argv[1], "r", stdin);
    if (argc > 2) freopen(argv[2], "w", stdout);

    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);

    free(infile);
    free(outfile);
}

void TimerStart() {
    TimeStart = clock();
}

void TimerStop() {
    TimeEnd = clock();
    double ElapsedTime = (double)(TimeEnd - TimeStart) / CLOCKS_PER_SEC;
    printf("\n\nTime elapsed: %lf seconds.\n", ElapsedTime);
}

void Exit() {
    TimerStop();
    exit(0);
}
