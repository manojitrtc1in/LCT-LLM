




    const int BUF_SIZE = 10009 * 15 * 100;
    char pool[BUF_SIZE];
    char *buf;
























using namespace std;




















































	REP(i, n){		                          \
        REP(j, m) cout << A[i][j] << " ";\
		cout << endl;				\
	}						\
}


	id0(i, n){		\
        id0(j, m) cout << A[i][j] << " ";\
		cout << endl;				\
	}						\
}









typedef long long LL;
typedef double DB;
typedef unsigned UINT;
typedef unsigned long long ULL;

typedef vector<int> VI;
typedef vector<char> VC;
typedef vector<string> VS;
typedef vector<LL> VL;
typedef vector<DB> VD;
typedef set<int> SI;
typedef set<string> SS;
typedef set<LL> SL;
typedef set<DB> SD;
typedef map<int, int> MII;
typedef map<string, int> MSI;
typedef map<LL, int> MLI;
typedef map<DB, int> MDI;
typedef map<int, bool> MIB;
typedef map<string, bool> MSB;
typedef map<LL, bool> MLB;
typedef map<DB, bool> MDB;
typedef pair<int, int> PII;
typedef pair<int, bool> PIB;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef vector<VII> VVII;
typedef set<PII> SII;
typedef map<PII, int> MPIII;
typedef map<PII, bool> MPIIB;





template<class T> inline void RD(T &);
template<class T> inline void OT(const T &);



inline LL RD(){ LL x; RD(x); return x;}
template<class T> inline T& _RD(T &x){ RD(x); return x;}
inline void RC(char &c){

    while (!isalnum(*buf)) ++buf;
    c = *buf++;

    scanf(" %c", &c);

    }
inline char RC(){char c; RC(c); return c;}
inline char _RC(char &c){RC(c); return c;}
inline void RF(DB &x){scanf("%lf", &x);};
inline DB RF(){DB x; RF(x); return x;}
inline DB _RF(DB &x){RD(x); return x;}
inline void RS(char *s){scanf("%s", s);}
inline char* _RS(char *s){scanf("%s", s); return s;}

template<class T0, class T1> inline void RD(T0 &x0, T1 &x1){RD(x0), RD(x1);}
template<class T0, class T1, class T2> inline void RD(T0 &x0, T1 &x1, T2 &x2){RD(x0), RD(x1), RD(x2);}
template<class T0, class T1, class T2, class T3> inline void RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3){RD(x0), RD(x1), RD(x2), RD(x3);}
template<class T0, class T1, class T2, class T3, class T4> inline void RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4){RD(x0), RD(x1), RD(x2), RD(x3), RD(x4);}
template<class T0, class T1, class T2, class T3, class T4, class T5> inline void RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4, T5 &x5){RD(x0), RD(x1), RD(x2), RD(x3), RD(x4), RD(x5);}
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> inline void RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4, T5 &x5, T6 &x6){RD(x0), RD(x1), RD(x2), RD(x3), RD(x4), RD(x5), RD(x6);}
template<class T0, class T1> inline void OT(T0 &x0, T1 &x1){OT(x0), OT(x1);}
template<class T0, class T1, class T2> inline void OT(T0 &x0, T1 &x1, T2 &x2){OT(x0), OT(x1), OT(x2);}
template<class T0, class T1, class T2, class T3> inline void OT(T0 &x0, T1 &x1, T2 &x2, T3 &x3){OT(x0), OT(x1), OT(x2), OT(x3);}
template<class T0, class T1, class T2, class T3, class T4> inline void OT(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4){OT(x0), OT(x1), OT(x2), OT(x3), OT(x4);}
template<class T0, class T1, class T2, class T3, class T4, class T5> inline void OT(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4, T5 &x5){OT(x0), OT(x1), OT(x2), OT(x3), OT(x4), OT(x5);}
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> inline void OT(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4, T5 &x5, T6 &x6){OT(x0), OT(x1), OT(x2), OT(x3), OT(x4), OT(x5), OT(x6);}

inline void RF(DB &a, DB &b){RF(a), RF(b);}
inline void RF(DB &a, DB &b, DB &c){RF(a), RF(b), RF(c);}

inline void RS(char *s1, char *s2){RS(s1), RS(s2);}
inline void RS(char *s1, char *s2, char *s3){RS(s1), RS(s2), RS(s3);}

template<class T> inline void RST(T &A){memset(A, 0, sizeof(A));}
template<class T0, class T1> inline void RST(T0 &A0, T1 &A1){RST(A0), RST(A1);}
template<class T0, class T1, class T2> inline void RST(T0 &A0, T1 &A1, T2 &A2){RST(A0), RST(A1), RST(A2);}
template<class T0, class T1, class T2, class T3> inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3){RST(A0), RST(A1), RST(A2), RST(A3);}
template<class T0, class T1, class T2, class T3, class T4> inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4){RST(A0), RST(A1), RST(A2), RST(A3), RST(A4);}
template<class T0, class T1, class T2, class T3, class T4, class T5> inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5){RST(A0), RST(A1), RST(A2), RST(A3), RST(A4), RST(A5);}
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5, T6 &A6){RST(A0), RST(A1), RST(A2), RST(A3), RST(A4), RST(A5), RST(A6);}


template<class T> inline void CLR(priority_queue<T, vector<T>, less<T> > &Q){
    while (!Q.empty()) Q.pop();
}

template<class T> inline void CLR(priority_queue<T, vector<T>, greater<T> > &Q){
    while (!Q.empty()) Q.pop();
}

template<class T> inline void CLR(T &A){A.clear();}
template<class T0, class T1> inline void CLR(T0 &A0, T1 &A1){CLR(A0), CLR(A1);}
template<class T0, class T1, class T2> inline void CLR(T0 &A0, T1 &A1, T2 &A2){CLR(A0), CLR(A1), CLR(A2);}
template<class T0, class T1, class T2, class T3> inline void CLR(T0 &A0, T1 &A1, T2 &A2, T3 &A3){CLR(A0), CLR(A1), CLR(A2), CLR(A3);}
template<class T0, class T1, class T2, class T3, class T4> inline void CLR(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4){CLR(A0), CLR(A1), CLR(A2), CLR(A3), CLR(A4);}
template<class T0, class T1, class T2, class T3, class T4, class T5> inline void CLR(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5){CLR(A0), CLR(A1), CLR(A2), CLR(A3), CLR(A4), CLR(A5);}
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> inline void CLR(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5, T6 &A6){CLR(A0), CLR(A1), CLR(A2), CLR(A3), CLR(A4), CLR(A5), CLR(A6);}
template<class T> inline void CLR(T &A, int n){REP(i, n) CLR(A[i]);}
template<class T> inline void FLC(T &A, int x){memset(A, x, sizeof(A));}
template<class T0, class T1> inline void FLC(T0 &A0, T1 &A1, int x){FLC(A0, x), FLC(A1, x);}
template<class T0, class T1, class T2> inline void FLC(T0 &A0, T1 &A1, T2 &A2){FLC(A0), FLC(A1), FLC(A2);}
template<class T0, class T1, class T2, class T3> inline void FLC(T0 &A0, T1 &A1, T2 &A2, T3 &A3){FLC(A0), FLC(A1), FLC(A2), FLC(A3);}
template<class T0, class T1, class T2, class T3, class T4> inline void FLC(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4){FLC(A0), FLC(A1), FLC(A2), FLC(A3), FLC(A4);}
template<class T0, class T1, class T2, class T3, class T4, class T5> inline void FLC(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5){FLC(A0), FLC(A1), FLC(A2), FLC(A3), FLC(A4), FLC(A5);}
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> inline void FLC(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5, T6 &A6){FLC(A0), FLC(A1), FLC(A2), FLC(A3), FLC(A4), FLC(A5), FLC(A6);}

template<class T> inline void SRT(T &A){sort(ALL(A));}
template<class T, class C> inline void SRT(T &A, C B){sort(ALL(A), B);}



const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const DB EPS = 1e-9;
const DB OO = 1e15;
const DB PI = acos(-1.0); 





template<class T> inline void checkMin(T &a,const T b){if (b<a) a=b;}
template<class T> inline void checkMax(T &a,const T b){if (b>a) a=b;}
template <class T, class C> inline void checkMin(T& a, const T b, C c){if (c(b,a)) a = b;}
template <class T, class C> inline void checkMax(T& a, const T b, C c){if (c(a,b)) a = b;}
template<class T> inline T min(T a, T b, T c){return min(min(a, b), c);}
template<class T> inline T max(T a, T b, T c){return max(max(a, b), c);}
template<class T> inline T min(T a, T b, T c, T d){return min(min(a, b), min(c, d));}
template<class T> inline T max(T a, T b, T c, T d){return max(max(a, b), max(c, d));}
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline T cub(T a){return a*a*a;}
int Ceil(int x, int y){return (x - 1) / y + 1;}



inline bool _1(int x, int i){return x & 1<<i;}
inline bool _1(LL x, int i){return x & 1LL<<i;}
inline LL _1(int i){return 1LL<<i;}


inline LL _U(int i){return _1(i) - 1;};




template<class T> inline T low_bit(T x) {
    return x & -x;
}

template<class T> inline T high_bit(T x) {
    T p = low_bit(x);
    while (p != x) x -= p, p = low_bit(x);
    return p;
}

template<class T> inline T cover_bit(T x){
    T p = 1; while (p < x) p <<= 1;
    return p;
}


inline int count_bits(int x){
    x = (x & 0x55555555) + ((x & 0xaaaaaaaa) >> 1);
    x = (x & 0x33333333) + ((x & 0xcccccccc) >> 2);
    x = (x & 0x0f0f0f0f) + ((x & 0xf0f0f0f0) >> 4);
    x = (x & 0x00ff00ff) + ((x & 0xff00ff00) >> 8);
    x = (x & 0x0000ffff) + ((x & 0xffff0000) >> 16);
    return x;
}

inline int count_bits(LL x){
    x = (x & 0x5555555555555555LL) + ((x & 0xaaaaaaaaaaaaaaaaLL) >> 1);
    x = (x & 0x3333333333333333LL) + ((x & 0xccccccccccccccccLL) >> 2);
    x = (x & 0x0f0f0f0f0f0f0f0fLL) + ((x & 0xf0f0f0f0f0f0f0f0LL) >> 4);
    x = (x & 0x00ff00ff00ff00ffLL) + ((x & 0xff00ff00ff00ff00LL) >> 8);
    x = (x & 0x0000ffff0000ffffLL) + ((x & 0xffff0000ffff0000LL) >> 16);
    x = (x & 0x00000000ffffffffLL) + ((x & 0xffffffff00000000LL) >> 32);
    return x;
}

int reverse_bits(int x){
    x = ((x >> 1) & 0x55555555) | ((x << 1) & 0xaaaaaaaa);
    x = ((x >> 2) & 0x33333333) | ((x << 2) & 0xcccccccc);
    x = ((x >> 4) & 0x0f0f0f0f) | ((x << 4) & 0xf0f0f0f0);
    x = ((x >> 8) & 0x00ff00ff) | ((x << 8) & 0xff00ff00);
    x = ((x >>16) & 0x0000ffff) | ((x <<16) & 0xffff0000);
    return x;
}

LL reverse_bits(LL x){
    x = ((x >> 1) & 0x5555555555555555LL) | ((x << 1) & 0xaaaaaaaaaaaaaaaaLL);
    x = ((x >> 2) & 0x3333333333333333LL) | ((x << 2) & 0xccccccccccccccccLL);
    x = ((x >> 4) & 0x0f0f0f0f0f0f0f0fLL) | ((x << 4) & 0xf0f0f0f0f0f0f0f0LL);
    x = ((x >> 8) & 0x00ff00ff00ff00ffLL) | ((x << 8) & 0xff00ff00ff00ff00LL);
    x = ((x >>16) & 0x0000ffff0000ffffLL) | ((x <<16) & 0xffff0000ffff0000LL);
    x = ((x >>32) & 0x00000000ffffffffLL) | ((x <<32) & 0xffffffff00000000LL);
    return x;
}




inline void INC(int &a, int b){a += b; if (a >= MOD) a -= MOD;}
inline int sum(int a, int b){a += b; if (a >= MOD) a -= MOD; return a;}
inline void DEC(int &a, int b){a -= b; if (a < 0) a += MOD;}
inline int dff(int a, int b){a -= b; if (a < 0) a  += MOD; return a;}
inline void MUL(int &a, int b){a = (LL)a * b % MOD;}
inline int pdt(int a, int b){return (LL)a * b % MOD;}

inline int sum(int a, int b, int c){return sum(sum(a, b), c);}
inline int sum(int a, int b, int c, int d){return sum(sum(a, b), sum(c, d));}


inline int pow(int a, LL b){
    int c(1); while (b) {
        if (b&1) MUL(c, a);
        MUL(a, a), b >>= 1;
    }
    return c;
}

template<class T> inline T pow(T a, LL b){
    T c(1);
    while (b) {
        if (b&1) c *= a;
        a *= a, b >>= 1;
    }
    return c;
}

inline int _I(int b){
    int a = MOD, x1 = 0, x2 = 1, q;
    while (true){
        q = a / b, a %= b;
        if (!a) return (x2 + MOD) % MOD;
        DEC(x1, pdt(q, x2));

        q = b / a, b %= a;
        if (!b) return (x1 + MOD) % MOD;
        DEC(x2, pdt(q, x1));
    }
}

inline void DIA(int &a, int b){MUL(a, _I(b));}
inline int qtt(int a, int b){return pdt(a, _I(b));}



inline int phi(int n){
    int res = n;
    for (int i=2;sqr(i)<=n;++i) if (!(n%i)){
        DEC(res, qtt(res, i));
        do{n /= i;} while(!(n%i));
    }
    if (n != 1)
        DEC(res, qtt(res, n));
    return res;
}






inline int rand32(){return (bool(rand() & 1) << 30) | (rand() << 15) + rand();}
inline int random32(int l, int r){return rand32() % (r - l + 1) + l;}
inline int random(int l, int r){return rand() % (r - l + 1) + l;}
int dice(){return rand() % 6;}
bool coin(){return rand() % 2;}






template<class T> inline void RD(T &x){

    while (!isdigit(*buf)) ++buf; x = 0;
    while (isdigit(*buf)) x = x * 10 + *buf++ - '0';

    

    

    char c; for (c = getchar(); c < '0'; c = getchar()); x = c - '0'; for (c = getchar(); c >= '0'; c = getchar()) x = x * 10 + c - '0';
    


}

int ____Case;
template<class T> inline void OT(const T &x){
    

    

    

    printf("%d ", x);
    


    

}




int n,m;
int a[MAXN] , ia[MAXN];
const int N = 21;
struct Seg{
    struct SEGTREE{
        int l,r,num,op;
    }tree[MAXN*4];

    void refresh(int root){
        tree[root].num = tree[root<<1].num + tree[root<<1|1].num;
    }

    void buildsegtree(int root,int l,int r)
    {
        tree[root].l = l;    tree[root].r = r;
        tree[root].op = -1;
        if(l == r)
        {
            tree[root].num = a[l];
            return ;
        }
        int mid = (l+r)>>1;
        buildsegtree(root<<1,l,mid);
        buildsegtree(root<<1|1,mid+1,r);
        refresh(root);
    }

    void pushdown(int root)
    {
        if(tree[root].op == -1)    return ;
        if(tree[root].l != tree[root].r)
        {
            if(tree[root].op == 2)
            {
                switch(tree[root<<1].op)
                {
                    case -1:    tree[root<<1].op = 2;    break;
                    case 0:        tree[root<<1].op = 1;    break;
                    case 1:        tree[root<<1].op = 0;    break;
                    case 2:        tree[root<<1].op = -1;    break;
                }
                switch(tree[root<<1|1].op)
                {
                    case -1:    tree[root<<1|1].op = 2;    break;
                    case 0:        tree[root<<1|1].op = 1;    break;
                    case 1:        tree[root<<1|1].op = 0;    break;
                    case 2:        tree[root<<1|1].op = -1;    break;
                }

            }
            else
                tree[root<<1].op = tree[root<<1|1].op = tree[root].op;
        }
        if(tree[root].op == 0)
        {
            tree[root].num
                = 0;
        }
        else if(tree[root].op == 1)
        {
            tree[root].num
                = tree[root].r - tree[root].l + 1;
        }
        else
        {
            tree[root].num = tree[root].r - tree[root].l + 1 - tree[root].num;
        }
        tree[root].op = -1;
    }

    int query_num(int root,int l,int r)
    {
        pushdown(root);
        if(tree[root].l == l && tree[root].r == r)
            return tree[root].num;
        int mid = (tree[root].l + tree[root].r)>>1;
        if(r <= mid)
            return query_num(root<<1,l,r);
        else if(l > mid)
            return query_num(root<<1|1,l,r);
        else
            return query_num(root<<1,l,mid) + query_num(root<<1|1,mid+1,r);

    }

    void update(int root,int l,int r,int op)
    {
        pushdown(root);
        if(tree[root].l == l && tree[root].r == r)
        {
            tree[root].op = op;
            return ;
        }
        int mid = (tree[root].l + tree[root].r)>>1;
        if(r<=mid)
            update(root<<1,l,r,op);
        else if(l > mid)
            update(root<<1|1,l,r,op);
        else
        {
            update(root<<1,l,mid,op);
            update(root<<1|1,mid+1,r,op);
        }
        pushdown(root<<1);
        pushdown(root<<1|1);
        refresh(root);
    }
}Meng[N];
int MM[N];
void init(){
    for (int i = 0 ; i < N ; ++i)
        MM[i] = 1 << i;
}
int main()
{
    init();
    while(cin >> n)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&ia[i]);
        }
        for (int i = 0 ; i < N ; ++i){
            int j = (1 << i);
            for (int k = 1 ; k <= n ; ++k){
                if (ia[k] & j) a[k] = 1;
                else a[k] = 0;
            }
            Meng[i].buildsegtree(1 , 1 , n);
        }
        int op,a,b,c;
        cin >> m ;
        while(m--)
        {
            scanf("%d" , &op);
            if (op == 1){
                scanf("%d%d" , &a  , &b);
                long long ans = 0;
                for (int i = 0 ; i < N ; ++i){
                    long long res = MM[i];
                    long long ret = Meng[i].query_num(1,a,b);
                    res *= ret;
                    ans += res;
                }
                cout << ans << endl;
            }
            else{
                scanf("%d%d%d" , &a , &b , &c);
                for (int i = 0 ; i < N; ++i){
                    if (c & MM[i]) Meng[i].update(1 , a , b , 2);
                }
            }
        }
    }
    return 0;
}
