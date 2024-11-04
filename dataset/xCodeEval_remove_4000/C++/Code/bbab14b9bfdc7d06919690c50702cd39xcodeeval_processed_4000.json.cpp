






















using namespace std;



typedef std::pair<int,int> pii; typedef long long ll; typedef unsigned long long ull; typedef unsigned int ui; typedef pair<ui,ui> puu;

template <typename T, typename U> std::istream&operator>>(std::istream&i, pair<T,U>&p) {i >> p.x >> p.y; return i;}
template<typename T>std::istream&operator>>(std::istream&i,vector<T>&t) {for(auto&v:t){i>>v;}return i;}
template <typename T, typename U> std::ostream&operator<<(std::ostream&o, const pair<T,U>&p) {o << p.x << ' ' << p.y; return o;}
template<typename T>std::ostream&operator<<(std::ostream&o,const vector<T>&t) {if(t.empty())o<<'\n';for(size_t i=0;i<t.size();++i){o<<t[i]<<" \n"[i == t.size()-1];}return o;}
template<typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using maxheap = priority_queue<T, vector<T>, less<T>>;
ui logceil(ll x) { return x?8*sizeof(ll)-__builtin_clzll(x):0; }

namespace std { template<typename T,typename U>struct hash<pair<T,U>>{hash<T>t;hash<U>u;size_t operator()(const pair<T,U>&p)const{return t(p.x)^(u(p.y)<<7);}}; }
template<typename T,typename F>T bsh(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){l=m+1;r=m;}else{h=m-1;}}return r;}
template<typename F> double id0(double l,double h,const F&f,double p=1e-9){ui r=3+(ui)log2((h-l)/p);while(r--){double m=(l+h)/2;if(f(m)){l=m;}else{h=m;}}return (l+h)/2;}
template<typename T,typename F>T bsl(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){h=m-1;r=m;}else{l=m+1;}}return r;}
template<typename F> double bsld(double l,double h,const F&f,double p=1e-9){ui r=3+(ui)log2((h-l)/p);while(r--){double m=(l+h)/2;if(f(m)){h=m;}else{l=m;}}return (l+h)/2;}
template<typename T> T gcd(T a,T b) { if (a<b) swap(a,b); return b?gcd(b,a%b):a; }


template<typename T>class vector2:public vector<vector<T>>{public:vector2(){} vector2(size_t a,size_t b,T t=T()):vector<vector<T>>(a,vector<T>(b,t)){}};
template<typename T>class vector3:public vector<vector2<T>>{public:vector3(){} vector3(size_t a,size_t b,size_t c,T t=T()):vector<vector2<T>>(a,vector2<T>(b,c,t)){}};
template<typename T>class vector4:public vector<vector3<T>>{public:vector4(){} vector4(size_t a,size_t b,size_t c,size_t d,T t=T()):vector<vector3<T>>(a,vector3<T>(b,c,d,t)){}};
template<typename T>class vector5:public vector<vector4<T>>{public:vector5(){} vector5(size_t a,size_t b,size_t c,size_t d,size_t e,T t=T()):vector<vector4<T>>(a,vector4<T>(b,c,d,e,t)){}};




template <typename T, typename Op> class ConstTree {
public:
    explicit ConstTree(const vector<T>&V) : D(logceil(int(V.size()))), N(V.size()), A{V}, L(N,0) {
        for (ui b = 1; b < D; ++b) {
            A.emplace_back(N-(1<<b)+1);
            for (ui i = 0; i + (1<<b) <= N; ++i) {
                A[b][i] = op(A[b-1][i], A[b-1][i+(1<<(b-1))]);
            }
        }
        for (ui i = 2; i < N; ++i) L[i] = L[i-1] + ((1<<L[i-1]) == i/2);
    }

    void update(const vector<T>&V) {
        A[0] = V;
        for (ui b = 1; b < D; ++b) {
            for (ui i = 0; i + (1<<b) <= N; ++i) {
                A[b][i] = op(A[b-1][i], A[b-1][i+(1<<(b-1))]);
            }
        }
    }

    T get(ui i, ui j) const { 

        return op(A[L[j-i]][i], A[L[j-i]][j+1-(1<<L[j-i])]);
    }
private:
    Op op;
    ui D,N;
    vector<vector<T>> A;
    vector<ui> L;
};

template <typename F> struct MinQOp { F operator()(F a, F b) const { return std::min(a,b); }};
template <typename F> struct MaxQOp { F operator()(F a, F b) const { return std::max(a,b); }};
template<typename T> struct Fenwick {
    explicit Fenwick(ui N=0, T t=T()):N(1u<<logceil(N)),F(this->N,t),t(t){}
    explicit Fenwick(const vector<T>&A, T t=T()):N(1u<<logceil(A.size())),F(A),t(t){
        F.resize(N); fill(F.begin()+A.size(),F.end(),t);
        for(int i=0;i<N;i++){int j=i+lsb(i+1);if(j<N)F[j]+=F[i];}}
    void add(int i, T v){while(i<=N){F[i]+=v;i+=lsb(i+1);}}
    T sum(int i)const{T sum(t);while(i){sum+=F[i-1];i-=lsb(i);}return sum;}
    T range(int i,int j)const{j++; T s(t);while(j>i){s+=F[j-1];j-=lsb(j);}while(i>j){s-=F[i-1];i-=lsb(i);}return s;}
    T get(int i)const{return range(i,i);}
    void set(int i, T v) {add(i, v-get(i)); }
    constexpr int lsb(int i)const{return i&-i;}
    ui N;vector<T> F;T t;
    int max_lower(T v) {
        if (F[0] >= v) return -1;
        if (F[N-1] < v) return N-1;

        int x = 0; T a = t;
        for (int s = N>>1; s > 0; s >>= 1) if (a+F[x+s-1]<v) { a += F[x+s-1]; x += s; }
        return x;
    }
};

template<typename T> struct id1 {
    explicit id1(ui N=0, T t=T()):N(1u<<logceil(N)),F(this->N,this->N,t),t(t){}














    void add(int x, int y, T v){
        while(x<=N){ int z = y; while(z<=N) { F[x][z] += v; z += lsb(z+1); }x +=lsb(x+1); }
    }

    T sum(int x, int y) {
        T sum(t);
        while (x <= N) { int z = y;while (z <= N) { sum += F[x][z];z -= lsb(z + 1); }x -= lsb(x + 1); }
        return sum;
    }
    T range(int x1, int y1, int x2, int y2) {
        T ans = sum(x2, y2);
        if (x1) ans -= sum(x1-1, y2);
        if (y1) ans -= sum(x2, y1-1);
        if (x1 && y1) ans += sum(x1-1,y1-1);
        return ans;
    }
    constexpr int lsb(int i)const{return i&-i;}
    ui N;vector2<T> F;T t;
};

constexpr int LOGN = 17;

class EGoodSubsegments {
public:
    int N;
    vector<int> P;
    ConstTree<int, MinQOp<int>> Min{{0}};
    ConstTree<int, MaxQOp<int>> Max{{0}};
    vector<vector<pii>> Range;
    vector<vector<int>> ListId;
    vector<vector<pii>> FullRange;
    vector<vector<int>> G;
    vector<vector<int>> Pairs;

    void prepare(int l, int r, int depth) {
        if (l+1 >= r) {
            return;
        }
        int m = (l+r)/2;
        for (int i = l; i < r; ++i) FullRange[depth][i] = {l,r};

        int loA = N, hiA = 0, loB = N, hiB = 0;
        map<int, int> LL, LH, RL, RH;
        auto add = [&](map<int,int>&W, int s, int t) {
            auto it = W.find(s);
            if (it != W.end()) {
                G[it->y].push_back(t);
            } else {
                int g = G.size();
                G.push_back({t});
                W[s] = g;
            }
        };
        int bb = m;
        for (int a = m-1; a >= l; --a) {
            loA = min(loA, P[a]);
            hiA = max(hiA, P[a]);
            while (bb < r && P[bb] > loA && P[bb] < hiA) ++bb;
            if (hiA - loA + 1 == bb - a && bb != m) {
                Pairs[bb-1].emplace_back(a);
            }

            add(LL, loA - a, a);
            add(LH, hiA + a, a);
        }
        int aa = m-1;
        for (int b = m; b < r; ++b) {
            loB = min(loB, P[b]);
            hiB = max(hiB, P[b]);
            while (aa >= l && P[aa] > loB && P[aa] < hiB) --aa;
            if (hiB - loB + 1 == b - aa && aa != m-1) {
                Pairs[b].emplace_back(aa+1);
            }
            add(RL, loB + b, b);
            add(RH, hiB - b, b);
        }

        auto run = [&](const map<int, int>&A, const map<int, int>&B, int type, function<bool(int,int)> cmp, bool left) {
            for (auto &a: A) {
                auto it = B.find(a.x);
                if (it != B.end()) {
                    const auto &b = G[it->y];
                    const auto &e = G[a.y];
                    if (b.empty()) continue;
                    int s = b.size()-1;
                    for (int i = 0; i < e.size(); ++i) {
                        int lo = Min.get(left ? e[i] : m, left ? m-1 : e[i]);
                        int hi = Max.get(left ? e[i] : m, left ? m-1 : e[i]);
                        int c = bsl(0, s, [&](int x) {
                            return type ?
                                   cmp(Min.get(left ? m : b[x], left ? b[x] : m-1), lo)
                                   : cmp(Max.get(left ? m : b[x], left ? b[x] : m-1), hi);
                        });
                        int d = bsh(0, s, [&](int x) {
                            return type ?
                                   cmp(Max.get(left ? m : b[x], left ? b[x] : m-1), hi)
                                   : cmp(Min.get(left ? m : b[x], left ? b[x] : m-1), lo);
                        });

                        if (c != -1 && d != -1 && c <= d) {
                            Range[depth][e[i]] = pii{c, d};
                            ListId[depth][e[i]] = it->y;
                        }
                    }
                }
            }
        };

        run(LL, RH, 0, greater<int>(), true);
        run(LH, RL, 1, less<int>(), true);
        run(RL, LH, 0, greater<int>(), false);
        run(RH, LL, 1, less<int>(), false);

        prepare(l, m, depth+1);
        prepare(m, r, depth+1);
    }

    void solve(istream& cin, ostream& cout) {
        cin >> N;
        P.resize(N);
        cin >> P;
        Range = vector2<pii>(LOGN, N, {-1,-1});
        ListId = vector2<int>(LOGN, N, -1);

        FullRange = vector2<pii>(LOGN, N);
        Min = ConstTree<int, MinQOp<int>>{P};
        Max = ConstTree<int, MaxQOp<int>>{P};
        Pairs.resize(N);

        prepare(0, N, 0);

        int Q; cin >> Q;
        int S = max(2, int(sqrt(N)));
        vector<ll> Ans(Q, 0);
        vector<vector<pii>> ByR(N);
        vector<vector<pair<pii, int>>> Queries(N/S+1); 

        for (int i = 0; i < Q; ++i) {
            int l, r; cin >> l >> r; --l; --r;
            Queries[l / S].push_back({{r, l}, i});
            Ans[i] = r - l + 1;
            ByR[r].push_back({l, i});
        }

        ll cur;
        int left, right;
        auto putLeft = [&](int diff) {
            if (diff == 1) left -= 1;

            for (int i = 0; i < LOGN; ++i) {
                if (Range[i][left].x == -1) continue;
                int mid = (FullRange[i][left].x + FullRange[i][left].y)/2;

                int d = 0;
                if (mid > right || mid <= left) {
                    

                } else if (FullRange[i][left].y > right) {
                    

                    auto &g = G[ListId[i][left]];
                    if (g.empty()) continue;
                    int r = bsh(0, (int)g.size()-1, [&](int x) { return g[x] <= right; });
                    d = r >= Range[i][left].x ? (min(r, Range[i][left].y) - Range[i][left].x + 1) : 0;
                } else {
                    

                    d = (Range[i][left].y - Range[i][left].x + 1);
                }
                cur += diff == 1 ? d : -d;
            }

            if (diff == -1) left += 1;
        };

        auto putRight = [&](int diff) {
            if (diff == 1) right += 1;

            for (int i = 0; i < LOGN; ++i) {
                if (Range[i][right].x == -1) continue;

                int mid = (FullRange[i][right].x + FullRange[i][right].y)/2;
                int d = 0;
                if (mid > right || mid < left) {
                    

                } else if (FullRange[i][right].x < left) {
                    

                    auto &g = G[ListId[i][right]];
                    if (g.empty()) continue;
                    int r = bsh(0, (int)g.size()-1, [&](int x) { return g[x] >= left; });
                    d = (r >= Range[i][right].x) ? (min(r, Range[i][right].y) - Range[i][right].x + 1) : 0;
                } else {
                    

                    d = (Range[i][right].y - Range[i][right].x + 1);
                }
                cur += diff == 1 ? d : -d;
            }


            if (diff == -1) right -= 1;
        };

        Fenwick<ll> F(N, 0LL);
        for (int i = 0; i < N; ++i) {
            for (int p: Pairs[i]) {
                F.add(p, 1);
            }
            for (pii q: ByR[i]) {
                Ans[q.y] += F.range(q.x, i);
            }
        }

        for (int block = 0; block <= N/S; ++block) {
            auto &queries = Queries[block];
            sort(queries.begin(),queries.end());

            left = right = block * S;
            cur = 0LL;
            for (auto &query: queries) {
                int r = query.x.x, l = query.x.y;
                while (r > right) putRight(1);
                while (l > left) putLeft(-1);
                while (l < left) putLeft(1);

                Ans[query.y] += cur;
            }
        }

        for (ll ans: Ans) {
            cout << ans << '\n';
        }
    }
};


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	EGoodSubsegments solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
    return 0;
}