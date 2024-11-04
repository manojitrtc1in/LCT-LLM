#include <stdio.h>
#include <stdlib.h>

#define REP(i, n) for (int i=0;i<int(n);++i)
#define FOR(i, a, b) for (int i=int(a);i<int(b);++i)
#define DWN(i, b, a) for (int i=int(b-1);i>=int(a);--i)
#define REP_1(i, n) for (int i=1;i<=int(n);++i)
#define FOR_1(i, a, b) for (int i=int(a);i<=int(b);++i)
#define DWN_1(i, b, a) for (int i=int(b);i>=int(a);--i)
#define REP_C(i, n) for (int n____=int(n),i=0;i<n____;++i)
#define FOR_C(i, a, b) for (int b____=int(b),i=a;i<b____;++i)
#define DWN_C(i, b, a) for (int a____=int(a),i=b-1;i>=a____;--i)
#define REP_N(i, n) for (i=0;i<int(n);++i)
#define FOR_N(i, a, b) for (i=int(a);i<int(b);++i)
#define DWN_N(i, b, a) for (i=int(b-1);i>=int(a);--i)
#define REP_1_C(i, n) for (int n____=int(n),i=1;i<=n____;++i)
#define FOR_1_C(i, a, b) for (int b____=int(b),i=a;i<=b____;++i)
#define DWN_1_C(i, b, a) for (int a____=int(a),i=b;i>=a____;--i)
#define REP_1_N(i, n) for (i=1;i<=int(n);++i)
#define FOR_1_N(i, a, b) for (i=int(a);i<=int(b);++i)
#define DWN_1_N(i, b, a) for (i=int(b);i>=int(a);--i)
#define REP_C_N(i, n) for (int n____=(i=0,int(n));i<n____;++i)
#define FOR_C_N(i, a, b) for (int b____=(i=0,int(b);i<b____;++i)
#define DWN_C_N(i, b, a) for (int a____=(i=b-1,int(a));i>=a____;--i)
#define REP_1_C_N(i, n) for (int n____=(i=1,int(n));i<=n____;++i)
#define FOR_1_C_N(i, a, b) for (int b____=(i=1,int(b);i<=b____;++i)
#define DWN_1_C_N(i, b, a) for (int a____=(i=b,int(a));i>=a____;--i)

#define ECH(it, A) for (__typeof(A.begin()) it=A.begin(); it != A.end(); ++it)
#define REP_S(it, str) for (char*it=str;*it;++it)
#define REP_G(it, u) for (int it=hd[u];it;it=suc[it])

#define DO(n) for ( int ____n ## __line__ = n; ____n ## __line__ -- ; )

#define _TO(i, a, b) int s_=a<b?1:-1,b_=b+s_;for(int i=a+s_;i!=b_;i+=s_)
#define TO(i, a, b) int s_=a<b?1:-1,b_=b+s_;for(int i=a;i!=b_;i+=s_)
#define TO_1(i, a, b) int s_=a<b?1:-1,b_=b;for(int i=a;i!=b_;i+=s_)
#define SQZ(i, j, a, b) for (int i=int(a),j=int(b)-1;i<j;++i,--j)
#define SQZ_1(i, j, a, b) for (int i=int(a),j=int(b);i<=j;++i,--j)
#define REP_2(i, j, n, m) REP(i, n) REP(j, m)
#define REP_2_1(i, j, n, m) REP_1(i, n) REP_1(j, m)
#define REP_3(i, j, k, n, m, l) REP(i, n) REP(j, m) REP(k, l)
#define REP_3_1(i, j, k, n, m, l) REP_1(i, n) REP_1(j, m) REP_1(k, l)

#define ALL(A) A.begin(), A.end()
#define LLA(A) A.rbegin(), A.rend()
#define CPY(A, B) memcpy(A, B, sizeof(A))
#define INS(A, P, B) A.insert(A.begin() + P, B)
#define ERS(A, P) A.erase(A.begin() + P)
#define BSC(A, X) find(ALL(A), X) 

#define CTN(T, x) (T.find(x) != T.end())
#define SZ(A) int(A.size())
#define PB push_back
#define MP(A, B) make_pair(A, B)

#define Rush int T____; RD(T____); DO(T____)

#define Display(A, n, m) {           \
    REP(i, n){                                  \
        REP(j, m) printf("%d ", A[i][j]);\
        printf("\n");                \
    }                                                \
}

#define Display_1(A, n, m) {                \
    REP_1(i, n){        \
        REP_1(j, m) printf("%d ", A[i][j]);\
        printf("\n");                \
    }		                    \
}

#define Ruby system("ruby main.rb")
#define Haskell system("runghc main.hs")
#define Python system("python main.py")
#define Pascal system("fpc main.pas")

#define PTT pair<T, T>
#define fi first
#define se second

typedef long long LL;
typedef double DB;
typedef unsigned UINT;
typedef unsigned long long ULL;

typedef struct {
    int a;
    int b;
    int k;
} Input;

typedef struct {
    int aa;
    int bb;
    int lcm;
    int adj[360360][10];
} Data;

Data* createData() {
    Data* data = (Data*)malloc(sizeof(Data));
    return data;
}

void destroyData(Data* data) {
    free(data);
}

void bfs(Data* data, int* D) {
    int s = data->aa;
    for (int i = 0; i < 3 * data->lcm; i++) {
        D[i] = 0x3f3f3f3f;
    }
    D[0] = 0;

    for (int i = 0; i < 3 * data->lcm; i++) {
        int u = (s - i) % data->lcm;
        if (u < 0) u += data->lcm;

        int Du = D[i];

        if (Du == 0x3f3f3f3f) continue;

        for (int j = 0; j < SZ(data->adj[u]); j++) {
            if (Du + 1 < D[i + data->adj[u][j]]) {
                D[i + data->adj[u][j]] = Du + 1;
            }
        }
    }
}

int main() {
    Input input;
    scanf("%lld %lld %lld", &input.a, &input.b, &input.k);

    Data* data = createData();

    int lcm = 1;
    for (int i = 2; i <= input.k; i++) {
        int gcd = lcm;
        int a = i;
        while (a != 0) {
            int temp = a;
            a = gcd % a;
            gcd = temp;
        }
        lcm = lcm * i / gcd;
    }

    data->lcm = lcm;

    for (int i = 0; i < lcm; i++) {
        data->adj[i][0] = 1;
        int index = 1;
        for (int j = 2; j <= input.k; j++) {
            if (i % j != 0) {
                data->adj[i][index] = i % j;
                index++;
            }
        }
    }

    LL tt = (input.a - input.b) / lcm;

    data->aa = input.a % lcm;
    data->bb = input.b % lcm;

    int D[3 * 360360];
    bfs(data, D);

    data->bb = (data->aa - data->bb + 3 * lcm) % lcm;

    tt *= (LL)(D[data->bb + lcm] - D[data->bb]);

    printf("%d\n", D[data->bb] + tt);

    destroyData(data);

    return 0;
}
