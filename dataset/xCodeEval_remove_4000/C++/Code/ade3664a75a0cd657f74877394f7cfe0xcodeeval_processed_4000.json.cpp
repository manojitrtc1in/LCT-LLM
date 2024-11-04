



using namespace std;



























namespace minmax {
    Tp T max (T&& A) { return A; }
    Tp T min (T&& A) { return A; }
    Tp T max (T&& A, T&& B) { return A>B?A:B; }
    Tp T min (T&& A, T&& B) { return A<B?A:B; }
    Tps T max (T&& A, Ts&&... ts) { T B = max(ts...); return A>B?A:B; }
    Tps T min (T&& A, Ts&&... ts) { T B = min(ts...); return A<B?A:B; }
    Tps T chmax(T&& A, Ts&&... ts) { A = max(A, ts...); return A; }
    Tps T chmin(T&& A, Ts&&... ts) { A = min(A, ts...); return A; }
}
namespace input { 
    Tp void re(T&& Xx) { cin >> Xx; }
    Tp2 void re(pair<T1,T2>& Pp) { re(Pp.first); re(Pp.second); }
    Tp void re(vector<T>& Aa) { for(int i = 0; i < sz(Aa); i++) re(Aa[i]); }
    Tp2 void rea(T1&& Aa, T2 t) { for(int i = 0; i < t; i++) re(Aa[i]); }
    Tps2 void rea(T1&& Aa, T2 t, Ts&&... ts) { rea(Aa, t); rea(ts...); }
    Tp2 void rea1(T1&& Aa, T2 t) { for(int i = 1; i <= t; i++) re(Aa[i]); }
    Tps2 void rea1(T1&& Aa, T2 t, Ts&... ts) { rea1(Aa, t); rea1(ts...); }
    Tps void re(T&& t, Ts&... ts) { re(t); re(ts...); }
}
namespace output {
    void pr(int Xx) { cout << Xx; }
    

    void pr(bool Xx) { cout << Xx; }
    void pr(long long Xx) { cout << Xx; }
    void pr(long long unsigned Xx) { cout << Xx; }
    void pr(double Xx) { cout << Xx; }
    void pr(char Xx) { cout << Xx; }
    void pr(const string& Xx) { cout << Xx; }
    void pr(const char* Xx) { cout << Xx; }
    void pr(const char* Xx, size_t len) { cout << string(Xx, len); }
    void ps() { cout << endl; }
    void pn() {  }
    void pw() { pr(" "); }
    void pc() { pr("]"); ps(); }
    Tp2 void pr(const pair<T1,T2>& Xx) { pr(Xx.first); pw(); pr(Xx.second);}
    Tp void pr(const T&);
    bool parse(const char* t) { if(t == e) return true; return false;}
    Tp bool parse(T&& t) { return false;}
    Tp2 bool parsepair(const pair<T1,T2>& Xx) { return true; }
    Tp bool parsepair(T&& t) { return false;}
    Tp2 void psa(T1&& Aa, T2 t) { for(int i = 0; i < t; i++) pr(Aa[i]), pw(); ps(); }
    Tp2 void pna(T1&& Aa, T2 t) { for(int i = 0; i < t; i++) pr(Aa[i]), ps(); }
    Tp2 void id1(T1&& Aa, T2 t1, T2 t2) { for(int i = 1; i <= t1; i++) {for(int j = 1; j <= t2; j++) pr(Aa[i][j]), pw(); ps();} }
    Tp void pr(const T& Xx) { bool fst = 1; bool op = 0; if (parsepair(*Xx.begin())) op = 1; for (const auto& Aa: Xx) {if(!fst) pw(); if(op) pr("{"); pr(Aa), fst = 0; if(op) pr("}"); } }
    Tps void pr(const T& t, const Ts&... ts) { pr(t); pr(ts...); }
    Tps void ps(const T& t, const Ts&... ts) { pr(t); if (sizeof...(ts)) {if (!parse(t)) pw(); } ps(ts...); }
    Tp void pn(const T& t) { for (const auto& Aa: t) ps(Aa); }
    Tps void pw(const T& t, const Ts&... ts) { pr(t); if (sizeof...(ts)) pw(); pw(ts...); }
    Tps void pc(const T& t, const Ts&... ts) { bool op = 0; if (parsepair(t)) op = 1; if(op) pr("{"); pr(t); if(op) pr("}"); if (sizeof...(ts)) pr(", "); pc(ts...); }
    namespace trace {
        
        
        

        Tp2 void __f(const char* name, const T1& Xx, const T2& y){ pr("[",y,"] = "); ps(Xx); }
        Tps2 void __f(const char* name, const T1& Xx, const T2& y, const Ts&... rest){ const char *open = strchr(name, '['); pr("[",y,"]"); __f(open+1, Xx, rest...); }
        Tps2 void id0(const char* name, const T1& Xx, const T2& y, const Ts&... rest){ const char *open = strchr(name, '['); pr(name, size_t(open-name)); __f(name, Xx, y, rest...); }
        Tp void __fn(int n, const char* name, const T& Xx) { for(int i = 0; i < n; i++) pr(name), __f(name, Xx[i], i); }
    }
}
using namespace minmax;
using namespace input;
using namespace output;
using namespace output::trace;
using ll = long long;
using pii = pair<int, int>;
const int N = 1e3 + 5;
pii a[N][N];
int vis[N][N];
char ans[N][N];
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
string dir = "DRUL";

int dfs(int x, int y, int endx, int endy, int col) {
    vis[x][y] = col;
    bool ret = 0;
    for(int i = 0; i < 4; i++) {
        int p = x + dx[i];
        int q = y + dy[i];
        if (a[p][q] != mp(endx, endy))
            continue;
        if(!vis[p][q]) {
            if (dfs(p, q, endx, endy, col)) {
                ans[x][y] = dir[i];
                ret = 1;
            }
            else
                ans[p][q] = dir[(i+2)%4];
        }
        else if (vis[p][q] < col) {
            ans[x][y] = dir[i];
            return 1;
        }
    }
    return ret;
}

int32_t main() {
    IOS;
    int i, j, k, n;
    re(n);
    for(i = 1; i <= n; i++) 
        for(j = 1; j <= n; j++) 
            re(a[i][j]);

    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            if (a[i][j] == mp(i, j)) {
                ans[i][j] = 'X';
                vis[i][j] = 1;
                continue;
            }
            if (a[i][j] != mp(-1, -1)) continue;
            for(k = 0; k < 4; k++) {
                int p = i + dx[k];
                int q = j + dy[k];
                if (a[p][q] == mp(-1, -1))
                    ans[i][j] = dir[k];
            }
        }
    }

    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            if (a[i][j] == mp(-1, -1) and !ans[i][j])
                return ps("INVALID"), 0;
        }
    }
    k = 2;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            if (a[i][j] == mp(-1, -1) or ans[i][j]) 
                continue;
            if(!dfs(i, j, a[i][j].ff, a[i][j].ss, k))
                return ps("INVALID"), 0;
            k++;
        }
    }
    ps("VALID");
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++)
            cout << (ans[i][j]?ans[i][j]:'X');
        ps();
    }
        
    return 0;
}










