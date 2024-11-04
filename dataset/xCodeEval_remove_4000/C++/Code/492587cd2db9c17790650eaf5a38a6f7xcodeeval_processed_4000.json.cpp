

using namespace std;



































const LL inf = 1000000000;
const LL mod = 1000000000 + 9;


inline void IO() { ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); }
inline int dcmp (LD x) { return x < -EPS ? -1 : (x > EPS); }


template<class T> inline int CHECK(T MASK, int i) { return (MASK >> i) & 1; }
template<class T> inline T ON(T MASK, int i) { return MASK | (T(1) << i); }
template<class T> inline T OFF(T MASK, int i) { return MASK & (~(T(1) << i)); }
template<typename T> inline int CNT(T MASK) {
    if (numeric_limits<T>::digits <= numeric_limits<unsigned int>::digits) return __builtin_popcount(MASK);
    else return __builtin_popcountll(MASK);
}
template<class T> inline int RIGHT(T MASK) { return log2(MASK & -MASK); }


int dx4[] = { 0, 0, -1, +1 }; int dy4[] = { +1, -1, 0, 0 };
int dx8[] = { 1, 1, 0, -1, -1, -1, 0, 1, 0 }; int dy8[] = { 0, 1, 1, 1, 0, -1, -1, -1, 0 };


inline void I(int& a) { scanf("%d", &a); } inline void I(LL& a) { scanf("%lld", &a); }
inline void I(ULL& a) { scanf("%llu", &a); } inline void I(char* a) { scanf("%s", a); }
char Iarr[200]; inline void I(string& a) { scanf("%s", Iarr); a = Iarr; }
inline void I(char& a) { scanf(" %c", &a); }
template<typename T, typename... Args>
void I(T& a, Args&... args) { I(a); I(args...); }


inline void OUT(int a) { printf("%d", a); } inline void OUT(LL a) { printf("%lld", a); }
inline void OUT(const char* a) { printf("%s", a); } inline void OUT(char* a) { printf("%s", a); }
inline void OUT(bool a) { printf("%d", a); } inline void OUT(string a) { rep(it, a.begin(), a.end()) printf("%c", *it); }
inline void OUT(ULL a) { printf("%llu", a); } inline void OUT(char a) { printf("%c", a); }
template<typename T, typename... Args>
void OUT(T a, Args... args) { OUT(a); OUT(" "); OUT(args...); }
template<typename... Args>
void O(Args... args) { OUT(args...); OUT("\n"); }


template<typename T1, typename T2>
inline ostream& operator<<(ostream& os, pair<T1, T2> p) { os << "{" << p.first << ", " << p.second << "}"; return os; }
template<typename T>
inline ostream& operator<<(ostream& os, vector<T>& a) { os << "["; for (int i = 0; i < (int)a.size(); i++) { if (i) os << ", "; os << a[i]; } os << "]"; return os; }



void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a << endl;
	err(++it, args...);
}







const int M = 200010; 








int N; 

vector<int> Edge[MAX+7];
int SubT[MAX+7]; 

int Par[MAX+7]; 

int Level[MAX+7]; 


int nC; 

int ChainLdr[MAX+7]; 

                                          

int Chain[MAX+7];        

int nP;                        

int Pos[MAX+7];    

int rPos[MAX+7];   

ump<LL, char> color;


int Explore( int u,int p,int l )
{
        SubT[u] = 1;
        Par[u] = p;
        Level[u] = l;
        int i;
        for( i=0;i<Edge[u].size();i++){
                int v = Edge[u][i];
                if( p==v ) continue;
                SubT[u] += Explore( v,u,l+1 );
        }
        return SubT[u];
}


void HeavyLight( int u,int k,bool IsL )
{
        if( IsL ){
                k = ++nC;
                ChainLdr[k] = u;
        }
        Chain[u] = k;
        Pos[u] = ++nP;
        rPos[nP] = u;
        

        int i,mx = -1; 

        for( i=0;i<Edge[u].size();i++){
                int v = Edge[u][i];
                if( Par[u]==v ) continue;
                if( mx==-1 ) mx = v;
                else if( SubT[v] > SubT[mx] ) mx = v;
        }
        if( mx==-1 ) return;
        HeavyLight( mx,k,false );
        for( i=0;i<Edge[u].size();i++){
                int v = Edge[u][i];
                if( Par[u]==v || mx == v ) continue;
                HeavyLight( v,0,true );
        }
}

int LCA( int u,int v )
{
    while( Chain[u]!=Chain[v] ){
        if( Level[ChainLdr[Chain[u]]] < Level[ChainLdr[Chain[v]]] ){
            v = Par[ChainLdr[Chain[v]]];
        }
        else{
            u = Par[ChainLdr[Chain[u]]];
        }
    }
    if( Level[u] < Level[v] ) return u;
    else return v;
}







const LL mod1 = 1000000007;
const LL mod2 = 1000000009;
const LL base = 347;

LL H1(string s)
{
    LL ret = 0;
    for (char c : s) {
        ret = ret * base + c;
        ret %= mod1;
    }
    return ret;
}

LL H2(string s)
{
    LL ret = 0;
    for (char c : s) {
        ret = ret * base + c;
        ret %= mod2;
    }
    return ret;
}

struct Hash
{
    int h1, h2;
    int val;
    Hash(int a, int b, int d)
    {
        h1 = a; h2 = b; val = d;
    }
};

bool operator < (const Hash& obj1, const Hash& obj2)
{
    if (obj1.h1 < obj2.h1) return 1;
    else if (obj1.h1 > obj2.h1) return 0;
    else if (obj1.h2 < obj2.h2) return 1;
    else if (obj1.h2 > obj2.h2) return 0;
    else if (obj1.val < obj2.val) return 1;
    else return 0;
}
bool operator == (const Hash& obj1, const Hash& obj2) {
    if (obj1.h1 == obj2.h1 && obj1.h2 == obj2.h2 && obj1.val == obj2.val) return 1; return 0;
}
bool operator > (const Hash& obj1, const Hash& obj2) { if (!(obj1 < obj2) && !(obj1 == obj2)) return 1; return 0; }
bool operator <= (const Hash& obj1, const Hash& obj2) { return !(obj1 > obj2); }
bool operator >= (const Hash& obj1, const Hash& obj2) { return !(obj1 < obj2); }

bool lesss(const Hash& obj1, const Hash& obj2)
{
    return (obj1 < obj2);
}



set<LL> exists;

LL mak(LL a, LL b)
{
    return a * 1000000021 + b;
}

LL mk(int a, int b)
{
    return (LL)a * 1000000 + b;
}

vector<Hash> v[MAX+7];

void g()
{
    for (int chn = 1; chn <= nC; chn++) {
        int id1 = Pos[ChainLdr[chn]];
        int low = id1, high = nP;
        while (low < high) {
            int mid = (low + high + 1) / 2;
            if (Chain[rPos[mid]] != chn) high = mid - 1;
            else low = mid;
        }
        int id0 = low;

        if (Par[rPos[id1]] != rPos[id1]) {
            LL h1 = 0, h2 = 0;
            for (int i = id1, co = 0; i <= id0 && co < 100; i++, co++) {
                if (i == id1) {
                    h1 = h1 * base + color[mk(Par[rPos[id1]], rPos[id1])];
                }
                else h1 = h1 * base + color[mk(rPos[i-1], rPos[i])];
                h1 %= mod1;
                if (i == id1) {
                    h2 = h2 * base + color[mk(Par[rPos[id1]], rPos[id1])];
                }
                else h2 = h2 * base + color[mk(rPos[i-1], rPos[i])];
                h2 %= mod2;
                if (exists.find(mak(h1, h2)) != exists.end())
                    v[chn].pb(Hash(h1, h2, i));
            }
        }

        for (int i = id1; i <= id0; i++) {
            LL h1 = 0, h2 = 0; int co = 0;
            int curr = i;
            while (co < 101 && curr <= id0) {
                if (co) {
                    h1 = h1 * base + color[mk(rPos[curr-1], rPos[curr])];
                    h1 %= mod1;
                    h2 = h2 * base + color[mk(rPos[curr-1], rPos[curr])];
                    h2 %= mod2;
                    if (exists.find(mak(h1, h2)) != exists.end())
                        v[chn].pb(Hash(h1, h2, curr));
                }
                curr++;
                co++;
            }
        }
        sort(all(v[chn]), lesss);
    }
}

int query1(int down, int up, string s)
{
    int ret = 0;
    int h1 = H1(s);
    int h2 = H2(s);
    int x = down;
    int curr = Chain[x];
    while (x != up) {
        if (Chain[x] == Chain[up]) {
            Hash a(h1, h2, Pos[x]);
            Hash b(h1, h2, Pos[up] + SZ(s));
            if (b <= a) {
                auto it = upper_bound(all(v[Chain[x]]), a);
                auto it1 = lb(v[Chain[x]], b);
                ret += it - it1;
            }
            x = up;
        }
        else {
            Hash a(h1, h2, Pos[x]);
            Hash b(h1, h2, Pos[ChainLdr[Chain[x]]] + SZ(s) - 1);
            if (b <= a) {
                auto it = upper_bound(all(v[Chain[x]]), a);
                auto it1 = lb(v[Chain[x]], b);
                ret += it - it1;
            }
            x = Par[ChainLdr[Chain[x]]];
        }
    }
    return ret;
}

vector<int> prefix_function (string s) {
    int n = (int) s.length();
    vector<int> pi (n);
    for (int i=1; i<n; ++i) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])  ++j;
        pi[i] = j;
    }
    return pi;
}

int kmp(string txt, string pat, vector<int> pi)
{
    int match = 0;
    int i = 0, j = 0;
    while (i < txt.size()) {
        if (j == pat.size()) {
            match++;
            

            j = pi[j-1];
        }
        else if (txt[i] == pat[j]) {
            i++; j++;
        }
        else {
            if (!j) i++;
            else j = pi[j-1];
        }
    }
    if (j == pat.size()) {
        match++;
        

    }
    return match;
}

int sett[MAX+7];
int now;

int query2(vector<int> v1, int st, int en, string org)
{
    now++;
    string s;
    int j;
    for (int i = 0; i < SZ(v1); i++) {
        if (v1[i] != st && v1[i] != en) {
            vector<int> vtemp;
            int prev;
            if (i == 0) prev = st;
            else prev = v1[i-1];
            int curr = v1[i];
            int len = 0;
            j = i;
            while (len < SZ(org) - 1 && sett[curr] != now) {
                if (curr != v1[i]) sett[curr] = now;
                int found = -1;
                int same = -1;
                for (int u : Edge[curr]) {
                    if (Chain[u] == Chain[curr]) {
                        if (Level[u] > Level[curr] && Level[prev] > Level[curr])
                            same = u;
                        if (Level[u] < Level[curr] && Level[prev] < Level[curr])
                            same = u;
                    }
                    if (Chain[u] == Chain[prev]) {
                        if (Chain[u] == Chain[curr]) {
                            if (Level[u] > Level[curr] && Level[prev] > Level[curr]) {
                                found = u; break;
                            }
                            if (Level[u] < Level[curr] && Level[prev] < Level[curr]) {
                                found = u; break;
                            }
                        }
                        else {
                            found = u;
                            break;
                        }
                    }
                }
                if (found == -1) {
                    if (same == -1) break;
                    else {
                        vtemp.pb(same);
                        curr = same;
                    }
                }
                else {
                    vtemp.pb(found);
                    curr = found;
                }
                len++;
                if (curr == st) {
                    break;
                }
                else if (curr == prev) {
                    int temp = prev;
                    j--;
                    if (j == 0) prev = st;
                    else prev = v1[j-1];
                    curr = temp;
                }
            }
            reverse(all(vtemp));
            if (sett[v1[i]] != now) {
                vtemp.pb(v1[i]);
                sett[v1[i]] = now;
            }

            int next;
            if (i == SZ(v1) - 1) next = en;
            else next = v1[i+1];
            curr = v1[i];
            len = 0;
            j = i;
            while (len < SZ(org) - 1) {
                int found = -1;
                int same = -1;
                for (int u : Edge[curr]) {
                    if (Chain[u] == Chain[curr]) {
                        if (Level[u] > Level[curr] && Level[next] > Level[curr])
                            same = u;
                        if (Level[u] < Level[curr] && Level[next] < Level[curr])
                            same = u;
                    }
                    if (Chain[u] == Chain[next]) {
                        if (Chain[u] == Chain[curr]) {
                            if (Level[u] > Level[curr] && Level[next] > Level[curr]) {
                                found = u; break;
                            }
                            if (Level[u] < Level[curr] && Level[next] < Level[curr]) {
                                found = u; break;
                            }
                        }
                        else {
                            found = u; break;
                        }
                    }
                }
                if (found == -1) {
                    if (same == -1) break;
                    else {
                        vtemp.pb(same);
                        curr = same;
                    }
                }
                else {
                    vtemp.pb(found);
                    curr = found;
                }
                len++;
                if (curr == en) {
                    break;
                }
                else if (curr == next) {
                    int temp = next;
                    j++;
                    if (j == SZ(v1) - 1) next = en;
                    else next = v1[j+1];
                    curr = temp;
                }
            }

            s += "$
            for (int i = 1; i < SZ(vtemp); i++) {
                s += color[mk(vtemp[i-1], vtemp[i])];
            }
            s += "$
        }
    }

    if (SZ(s) && SZ(org)) {
        vector<int> pf = prefix_function(org);
        return kmp(s, org, pf);
    }
    else return 0;
}

int query(int st, int en, string s)
{
    int lca = LCA(st, en);
    int ans = 0;
    string rev = s;
    reverse(all(rev));
    ans += query1(st, lca, rev);
    ans += query1(en, lca, s);

    vector<int> points;
    int temp = st;
    bool flag = 0;
    while (temp != lca) {
        if (Chain[temp] != Chain[lca]) {
            points.pb(Par[ChainLdr[Chain[temp]]]);
            temp = Par[ChainLdr[Chain[temp]]];
            if (temp == lca) flag = 1;
        }
        else {
            temp = lca;
        }
    }
    vector<int> points1;
    temp = en;
    while (temp != lca) {
        if (Chain[temp] != Chain[lca]) {
            temp = Par[ChainLdr[Chain[temp]]];
            if (temp == lca) {
                if (!flag) points1.pb(temp);
            }
            else points1.pb(temp);
        }
        else {
            temp = lca;
        }
    }
    reverse(all(points1));
    for (int x : points1) points.pb(x);
    ans += query2(points, st, en, s);

    return ans;
}

int main()
{
    color.reserve(262144);
    color.max_load_factor(0.25);
    I(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        char c;
        I(u, v, c);
        u--; v--;
        Edge[u].pb(v);
        Edge[v].pb(u);
        color[mk(u,v)] = c;
        color[mk(v,u)] = c;
    }
    Explore(0, 0, 0);
    HeavyLight(0, 0, true);

    int q;
    I(q);
    vector<pair<pii, string> > temp;
    while (q--) {
        int st, en;
        string s;
        I(st, en, s);
        st--; en--;
        temp.pb(mp(mp(st, en), s));
        exists.insert(mak(H1(s), H2(s)));
        reverse(all(s));
        exists.insert(mak(H1(s), H2(s)));
    }

    g();
    for (auto it : temp) {
        O(query(it.ff.ff, it.ff.ss, it.ss));
    }

    return 0;
}
