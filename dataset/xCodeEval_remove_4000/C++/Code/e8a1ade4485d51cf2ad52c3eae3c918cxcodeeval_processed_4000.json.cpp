
























































using namespace std;






























































































const     ll                        MOD=1e9+7;
const     ll                        INF = 0x3f3f3f3f;
const     ll                        LINF = 0x3f3f3f3f3f3f3f3f;
const     ld                        PI = acos(-1);
const     ld                        eps= 0.00001;




int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int dx4[] = {-1, 0, 1, 0};
int dy4[] = { 0, 1, 0,-1};
int dx8[] = {-1, 0, 1, 0, -1,-1, 1, 1};
int dy8[] = { 0, 1, 0,-1, -1, 1,-1, 1};
int dxhorse[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dyhorse[] = {1,  -1, 2 , -2, 2,-2, 1,-1};



int X,Y,Z,N,M,K;
int L[3],R[3];
int OK[101010][3],NG[101010][3],Q[101010][3];
int ret[101010];
vector<pair<int,int>> query[8];




template<typename T> inline void setmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void setmax(T &x, T y) { if (y > x) x = y; }
template<typename T> inline T gcd(T a, T b) { while (b)swap(a %= b, b); return a; }
template<class T>  inline T id3(T u, T v) {
    int shl = 0; while (u && v && u != v) {
        T eu = u & 1; u >>= eu ^ 1; T ev = v & 1; v >>= ev ^ 1;
        shl += (~(eu | ev) & 1); T d = u & v & 1 ? (u + v) >> 1 : 0; T dif = (u - v) >> (sizeof(T) * 8 - 1); u -= d & ~dif; v -= d & dif;
    } return std::max(u, v) << shl;
}
template<class T1,class T2> inline void upd1(T1&a,T2 b){a>b?a=b:0;}
template<class T1,class T2> inline void upd2(T1&a,T2 b){a<b?a=b:0;}
template<class T> inline bool equ(const T&a,const T&b) { return!memcmp(&a,&b,sizeof a);}
template<class T> bool isPrime(T x) {
    if (x <= 4 || x % 2 == 0 || x % 3 == 0) return x == 2 || x == 3;
    for (T i = 5; i * i <= x; i += 6) if (x % i == 0 || x % (i + 2) == 0) return 0; return 1;
}
template<typename T> static inline T aabs(T x){if(x<0)return -x; return x;}
template<typename T, typename U> inline static void aswap(T &x, U &y){T temp; temp=x; x=y; y=temp;}
template<typename T, typename U> inline static ll fpow(T n, U k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline void normmod(T &x, T m =MOD) { x %= m; if (x < 0) x += m; }
template<typename T> vector<vector<T> > newton(int N, int MOD) {
    vector<vector<T> > npok(N + 1, vector<T>(N + 1));
    for (int i = 0; i <= N; ++i)npok[i][0] = 1;
    for (int i = 1; i <= N; ++i)for (int j = 1; j <= N; ++j)npok[i][j] = (npok[i - 1][j] + npok[i - 1][j - 1]) % MOD; return npok;
}




template <typename T> inline T id1(T x1,T y1,T x2, T y2) {return abs(x1-x2)+abs(y1-y2);}
template <typename T> inline T id4(T x1,T y1,T x2, T y2) {return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));}
template <typename T> inline T id5(T x1,T y1,T x2, T y2) { T tmp1=abs(x1-x2); T tmp2=abs(y1-y2); T tmp3=abs(tmp1-tmp2); T tmp4=min(tmp1, tmp2); return tmp3+tmp4; }
template <typename T> inline T id2(T x1,T y1,T z1,T x2,T y2,T z2) {return sqrt(square(x2-x1)+square(y2-y1)+square(z2-z1));}
template <typename T> inline T Cube(T a){return a*a*a;}
template <typename T> inline T id7(T a,T b,T c){return a*b*c;}
template <typename T> inline T Pyramid(T base, T height){return (1/3)*base*height;}
template <typename T> inline T Ellipsoid(T r1,T r2,T r3) {return (4/3)*PI*r1*r2*r3;}
template <typename T> inline T id8(T base, T height){return base*height;}
template <typename T> inline T Sphere(T radius){ return (4/3)*PI*radius*radius*radius;}
template <typename T> inline T CylinderB(T base, T height){return base*height;} 

template <typename T> inline T CylinderR(T radius, T height){return PI*radius*radius*height;} 

template <typename T> inline T Cone (T radius,T base, T height){return (1/3)*PI*radius*radius*height;}









inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
inline bool id6(ll year) { return (year%400==0) || (year%4==0 && year%100!=0); }
inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b));}
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }

inline ll id0(ll x) {int count(0);while(x) x&=(x-1),count++;return count;}

inline void solve() {
    int i,j,k,l,r,x,y; string s;
    scanf("%d%d%d%d%d%d",&X,&Y,&Z,&N,&M,&K);
    R[0]=R[1]=R[2]=1;L[0]=X;L[1]=Y;L[2]=Z;
    FOR(i,N){scanf("%d%d%d",&OK[i][0],&OK[i][1],&OK[i][2]);
        FOR(j,3) L[j]=min(L[j],OK[i][j]),R[j]=max(R[j],OK[i][j]);}
    FOR(i,M) {
        scanf("%d%d%d",&NG[i][0],&NG[i][1],&NG[i][2]);
        int ok=0;
        FOR(j,3) {
            if(NG[i][j]<L[j] || R[j]<NG[i][j]) ok=1;
            if(NG[i][j]>R[j]) NG[i][j]-=R[j]-L[j];
            else if(NG[i][j]>=L[j]) NG[i][j]=L[j];
        }
        if(ok==0)  return _P("INCORRECT\n");
        
        FOR(j,8) {
            int ok=1;
            FOR(x,3) {
                y=(j>>x)&1;
                if(y==0 && NG[i][x]>L[x]) ok=0;
                if(y==1 && NG[i][x]<L[x]) ok=0;
            }
            if(ok){
                if(j&4) query[j].push_back({NG[i][2],i});
                else query[j].push_back({Z+1-NG[i][2],i});
            }
        }
    }
    FOR(i,K) {
        scanf("%d%d%d",&Q[i][0],&Q[i][1],&Q[i][2]);
        ret[i]=1;
        FOR(j,3) {
            ret[i]&=(L[j]<=Q[i][j]&&Q[i][j]<=R[j]);
            if(Q[i][j]>R[j]) Q[i][j]-=R[j]-L[j];
            else if(Q[i][j]>=L[j]) Q[i][j]=L[j];
        }
        if(ret[i]==0) {
            FOR(j,8) {
                int ok=1;
                FOR(x,3) {
                    y=(j>>x)&1;
                    if(y==0 && Q[i][x]>L[x]) ok=0;
                    if(y==1 && Q[i][x]<L[x]) ok=0;
                }
                if(ok) {
                    if(j&4) query[j].push_back({Q[i][2],100000+i});
                    else query[j].push_back({Z+1-Q[i][2],100000+i});
                }
            }
        }
    }
    
    FOR(i,8) {
        map<ll,ll> mp;
        mp[0]=1000000;
        mp[1000000]=0;
        sort(ALL(query[i]));
        FORR(z,query[i]) {
            j=z.second;
            if(j<100000) {
                x=NG[j][0];
                y=NG[j][1];
                if((i&1)==0) x=X+1-x;
                if((i&2)==0) y=Y+1-y;
                auto it=mp.lower_bound(x+1);
                it--;
                if(it->second>=y) {
                    mp[x]=y;
                    while(1) {
                        it=mp.lower_bound(x+1);
                        if(it->second<y) break;
                        mp.erase(it);
                    }
                }
            }
            else {
                j-=100000;
                x=Q[j][0];
                y=Q[j][1];
                if((i&1)==0) x=X+1-x;
                if((i&2)==0) y=Y+1-y;
                auto it=mp.lower_bound(x+1);
                it--;
                if(it->second<=y) ret[j]=2;
            }
        }
        
    }
    
    _P("CORRECT\n");
    FOR(i,K) {
        if(ret[i]==1) _P("OPEN\n");
        if(ret[i]==2) _P("CLOSED\n");
        if(ret[i]==0) _P("UNKNOWN\n");
    }
}
















































int main(int argc, const char * argv[]) {
    string s;int i;
    if(argc==1) speed
    FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
    rt
}
