#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()


const int debug = 0;
#define watch(...) debug && std::cout << "{" << #__VA_ARGS__ << "} = " \
    << std::make_tuple(__VA_ARGS__) << std::endl

template<typename... X>
std::ostream& operator<<(std::ostream& os, const std::pair<X...>& p) 
{ return os << std::make_tuple(std::get<0>(p), std::get<1>(p)); }

template<std::size_t I = 0, typename FuncT, typename... Tp>
inline typename std::enable_if<I == sizeof...(Tp), void>::type
for_each_const(const std::tuple<Tp...> &, FuncT) { }

template<std::size_t I = 0, typename FuncT, typename... Tp>
inline typename std::enable_if<I < sizeof...(Tp), void>::type
for_each_const(const std::tuple<Tp...>& t, FuncT f)
{ f(std::get<I>(t)),for_each_const<I + 1, FuncT, Tp...>(t, f); }


template<std::size_t I = 0, typename FuncT, typename... Tp>
inline typename std::enable_if<I == sizeof...(Tp), void>::type
for_each(std::tuple<Tp...> &, FuncT) { }

template<std::size_t I = 0, typename FuncT, typename... Tp>
inline typename std::enable_if<I < sizeof...(Tp), void>::type
for_each(std::tuple<Tp...>& t, FuncT f)
{ f(std::get<I>(t)); for_each<I + 1, FuncT, Tp...>(t, f); }

struct Printer {
    std::ostream& os; bool was{0};
    Printer(std::ostream& os_) : os(os_) { }
    template<typename X> void operator()(X x) 
    { os << (was?", ":(was=1,"")) << x; }
};

template<typename... X>
std::ostream& operator<<(std::ostream& os, const std::tuple<X...>& t)
{ return os << "{", for_each_const(t, Printer(os)), os << "}"; }

template<typename Iterator>
std::ostream& print(std::ostream& os, Iterator begin, Iterator end)
{ return os << "{", std::for_each(begin,end,Printer(os)), os << "}"; }

#define OUTPUT(container) template<typename X, typename... T>           \
std::ostream& operator<<(std::ostream& os, const container<X,T...>& c)  \
{ return print(os, all(c)); }
OUTPUT(std::vector) OUTPUT(std::list) OUTPUT(std::deque)
OUTPUT(std::set) OUTPUT(std::unordered_set)
OUTPUT(std::multiset) OUTPUT(std::unordered_multiset)
OUTPUT(std::map) OUTPUT(std::multimap) OUTPUT(std::unordered_map)
#undef RANGE_OUTPUT
    
#define OUTPUT2(container, get, pop) template<typename X, typename... T> \
std::ostream& operator<<(std::ostream& os, container<X,T...> c) {       \
    std::vector<X> v(c.size());                                         \
    for (unsigned i = 0; i != v.size(); v[i++] = c.get(),c.pop());      \
    return os << v; }                                                   
OUTPUT2(std::queue,front,pop)
OUTPUT2(std::stack,top,pop)
OUTPUT2(std::priority_queue,top,pop)
#undef OUTPUT
#define isz(x) (int)(x).size()
void setmax(auto &x, auto y) {
    x = y > x ? y : x;
}
void setmin(auto &x, auto y) {
    x = y < x ? y : x;
}
using vi = std::vector<int>;
using vvi = std::vector<vi>;
using pii = std::pair<int,int>;
using vpii = std::vector<pii>;

int solveOK(const int nRows, const int nCols, const std::vector<std::string>& map, const vi&) {
    int nV = 0;
    static vvi a;
    a.resize(nRows);
    for (auto &it : a) it.assign(nCols,0);
    for (int r = 0; r < nRows; r++) {
        for (int c = 0; c < nCols; c++) {
            if (map[r][c] == '#') a[r][c] = ++nV;
        }
    }
    

    static vvi down;
    down.resize(nRows+1);
    for (auto &it : down) it.assign(nCols,0);
    
    for (int r = nRows-1; r >= 0; r--) {
        for (int c = 0; c < nCols; c++) {
            down[r][c] = a[r][c] ?: down[r+1][c];
        }
    }
    

    

    

    

    

    static vpii edges;
    edges.clear();
    for (int r = 0; r < nRows; r++) {
        for (int c = 0; c < nCols; c++) {
            if (a[r][c]) {
                for (int dr = -1; dr <= 1; dr++) {
                    for (int dc = -1; dc <= 1; dc++) {
                        if (dr * dr + dc * dc != 1) continue;
                        int nr = r + dr, nc = c + dc;
                        if (nr < 0 || nr >= nRows || nc < 0 || nc >= nCols) continue;
                        if (a[nr][nc]) edges.emplace_back(a[r][c],a[nr][nc]);
                    }
                }
                if (down[r+1][c]) edges.emplace_back(a[r][c],down[r+1][c]);
                if (c + 1 < nCols && down[r][c+1]) edges.emplace_back(a[r][c],down[r][c+1]);
                if (c - 1 >= 0 && down[r][c-1]) edges.emplace_back(a[r][c],down[r][c-1]);
            }
        }
    }
    

    std::sort(all(edges));
    edges.erase(std::unique(all(edges)),edges.end());
    

    static vvi next;
    next.assign(nV+1,{});
    for (auto &[from,to] : edges) next[from].push_back(to);
    

    static vi vis,order;
    order.clear();
    vis.assign(nV+1,0);
    std::function<void(int)> dfs = [&](int u) {
        if (vis[u]) return;
        vis[u]=1;
        for (int v : next[u]) dfs(v);
        order.push_back(u);
    };
    for (int u = 1; u <= nV; u++) dfs(u);
    

    

    std::fill(all(vis),0);
    int ans = 0;
    static vi x;
    x = order;
    order = {};
    std::reverse(all(x));
    for (int u : x) {
        if (!vis[u]) ans++, dfs(u);
    }
    return ans;
}

class Timer {
    std::chrono::time_point<std::chrono::steady_clock> timePoint;
    size_t value;
public:
    void start() { timePoint = std::chrono::steady_clock::now(); }
    void finish() {
        auto curr = std::chrono::steady_clock::now();    
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(curr - timePoint);
        value = elapsed.count();
    }
    size_t operator()() const { return value; }
} timer;
bool timing=false;

void topsort(int u,auto&vis,auto&next,auto&order) {
    if (vis[u]) return;
    vis[u]=1;
    for (int v : next[u]) topsort(v,vis,next,order);
    order.push_back(u);
}

void removeCells(const int nRows, const int nCols,std::vector<std::string>& map, const vi& cnt,vpii& removed) {
    removed.clear();
    static vvi a;
    a.resize(nRows); for (auto &it : a) it.assign(nCols,0);
    int nV = 0;
    for (int r = 0; r < nRows; r++) {
        for (int c = 0; c < nCols; c++) {
            if (map[r][c] == '#') a[r][c] = ++nV;
        }
    }
    static vvi down;
    down.resize(nRows+1);
    for (auto &it : down) it.assign(nCols,0);
    for (int r = nRows-1; r >= 0; r--) {
        for (int c = 0; c < nCols; c++) {
            down[r][c] = a[r][c]?:down[r+1][c];
        }
    }
    static vpii edges;
    edges.clear();
    for (int r = 0; r < nRows; r++) {
        for (int c = 0; c < nCols; c++) {
            if (a[r][c]) {
                for (int dr = -1; dr <= 1; dr++) {
                    for (int dc = -1; dc <= 1; dc++) {
                        if (dr * dr + dc * dc != 1) continue;
                        const int nr = r + dr, nc = c + dc;
                        if (nr < 0 || nr >= nRows || nc < 0 || nc >= nCols) continue;
                        if (a[nr][nc]) edges.emplace_back(a[r][c],a[nr][nc]);
                    }
                }
                if (c+1<nCols&&down[r][c+1])edges.emplace_back(a[r][c],down[r][c+1]);
                if (c-1>=0&&down[r][c-1])edges.emplace_back(a[r][c],down[r][c-1]);
                if (down[r+1][c]) edges.emplace_back(a[r][c],down[r+1][c]);
            }
        }
    }
    std::sort(all(edges));
    edges.erase(std::unique(all(edges)),edges.end());
    for (int r = 0; r < nRows; r++) 
        watch(r,a[r]);
    watch(edges);
    static vvi next,prev;
    next.assign(1+nV,{});
    prev.assign(1+nV,{});
    for (auto &[u,v] : edges) {
        next[u].push_back(v);
        prev[v].push_back(u);
    }
    static vi vis,order;
    order.clear();
    vis.assign(1+nV,0);
    
    for (int u = 1; u <= nV; u++) topsort(u,vis,next,order);
    std::reverse(all(order));
    watch(order);
    std::fill(all(vis),0);
    int nComp=0;
    for (int u : order) {
        if (!vis[u]) {
            vis[u]=++nComp;
            static vi q;
            q = {u};
            for (int i = 0; i < isz(q); i++) {
                for (int v : prev[q[i]]) {
                    if (!vis[v]) vis[v]=nComp,q.push_back(v);
                }
            }
        }
    }
    for (int r = 0; r < nRows; r++) {
        watch(r,map[r]);
    }
    for (int col = 0; col < nCols; col++) {
        static vvi kek;
        kek.clear();
        static vi idKek;
        idKek.clear();
        for (int row = nRows-1; row >= 0; row--) {
            if (map[row][col] == '#') {
                if (!isz(idKek) || vis[a[row][col]] != idKek.back()) {
                    idKek.push_back(vis[a[row][col]]);
                    kek.push_back({});
                }
                assert(vis[a[row][col]] == idKek.back());
                kek.back().push_back(row);
            }
        }
        watch(col,kek);
        watch(col,idKek);
        int counter=cnt[col]-1;
        int idG = 0;
        while (idG < isz(kek) && counter >= isz(kek[idG])) {
            counter -= isz(kek[idG]);
            for (int row : kek[idG]) {
                map[row][col] = '.';
                removed.emplace_back(row,col);
            }
            idG++;
        }
    }
}
void dfs2(int u,vi&vis,auto&next,auto&min,auto&max) {
    if (vis[u])return;
    vis[u]=1;
    for (int v : next[u]) {
        dfs2(v,vis,next,min,max);
        setmin(min[u],min[v]);
        setmax(max[u],max[v]);
    }
}
int solveWrong(const int nRows, const int nCols, std::vector<std::string>& map, const vi& cnt) {
    timer.start();
    static vpii removed;
    removeCells(nRows,nCols,map,cnt,removed);
    timer.finish();
    if (timing) {
        std::cout << timer() << "ms" << std::endl;
    }
    timer.start();
    const int INF = (int)1e9+7;
    int nV=0;
    static vvi a;
    a.resize(nRows);
    for (auto &it : a) it.assign(nCols,0);
    for (int r = 0; r < nRows; r++) {
        watch(r,map[r]);
    }
    for (int r = 0; r < nRows; r++) {
        for (int c = 0; c < nCols; c++) {
            if (map[r][c] == '#') a[r][c] = ++nV;
        }
        watch(r,a[r]);
    }
    
    

    static vvi down;
    down.resize(nRows+1);
    for (auto &it : down) it.assign(nCols,0);
    
    for (int r = nRows-1; r >= 0; r--) {
        for (int c = 0; c < nCols; c++) {
            down[r][c] = a[r][c] ?: down[r+1][c];
        }
    }
    

    

    

    

    

    static vpii edges;
    edges.clear();
    for (int r = 0; r < nRows; r++) {
        for (int c = 0; c < nCols; c++) {
            if (a[r][c]) {
                for (int dr = -1; dr <= 1; dr++) {
                    for (int dc = -1; dc <= 1; dc++) {
                        if (dr * dr + dc * dc != 1) continue;
                        int nr = r + dr, nc = c + dc;
                        if (nr < 0 || nr >= nRows || nc < 0 || nc >= nCols) continue;
                        if (a[nr][nc]) edges.emplace_back(a[r][c],a[nr][nc]);
                    }
                }
                if (down[r+1][c]) edges.emplace_back(a[r][c],down[r+1][c]);
                if (c + 1 < nCols && down[r][c+1]) edges.emplace_back(a[r][c],down[r][c+1]);
                if (c - 1 >= 0 && down[r][c-1]) edges.emplace_back(a[r][c],down[r][c-1]);
            }
        }
    }
    

    std::sort(all(edges));
    edges.erase(std::unique(all(edges)),edges.end());
    

    static vvi next,prev;
    next.assign(nV+1,{});
    prev.assign(nV+1,{});
    for (auto &[from,to] : edges) {
        next[from].push_back(to);
        prev[to].push_back(from);
    }
    

    static vi vis,order;
    vis.assign(nV+1,0);
    order.clear();
    timer.finish();
    if (timing) {
        std::cout << timer() << "ms" << std::endl;
    }
    timer.start();
    for (int u = 1; u <= nV; u++) topsort(u,vis,next,order);
    timer.finish();
    if (timing) {
        std::cout << timer() << "ms" << std::endl;
    }
    timer.start();
    std::fill(all(vis),0);
    int nComp = 0;
    std::reverse(all(order));
    for (int u : order) {
        if (!vis[u]) {
            vis[u] = ++nComp;
            static vi q;
            q={u};
            for (int i = 0; i < isz(q); i++)
                for (int v : prev[q[i]])
                    if (!vis[v]) vis[v]=nComp,q.push_back(v);
        }
    }
    timer.finish();
    if (timing) std::cout << timer() << "ms" << std::endl;
    static vpii tree;
    tree.clear();
    for (int u = 1; u <= nV; u++) {
        for (int v : next[u]) {
            if (vis[u] != vis[v]) {
                tree.emplace_back(vis[u],vis[v]);
            }
        }
    }
    std::sort(all(tree));
    tree.erase(std::unique(all(tree)),tree.end());
    static vi min,max;
    min.assign(1+nComp,INF);
    max.assign(1+nComp,-1);
    
    for (int col = 0; col < nCols; col++) {
        

        for (int row = nRows-1; row >= 0; row--) {
            if (auto u = a[row][col]) {
                

                int idComp = vis[u];
                setmin(min[idComp],col);
                setmax(max[idComp],col);
            }
        }
    }
    watch(min);
    watch(max);
    next.clear();
    next.resize(1+nComp);
    for (auto &[u,v] : tree) {
        next[u].push_back(v);
    }

    static vpii segs;
    segs.clear();
    static vvi open,close;
    open.assign(nCols,{});
    close.assign(nCols,{});
    timer.start();
    vi visComp(1+nComp);
    for (int u = 1; u <= nComp; u++) {
        dfs2(u,visComp,next,min,max);
        if (min[u] <= max[u]) {
            open[min[u]].push_back(isz(segs));
            close[max[u]].push_back(isz(segs));
            segs.emplace_back(min[u],max[u]);
        }
    }
    timer.finish();
    if (timing) {
        std::cout << timer() << "ms" << std::endl;
    }
    int ans=0,covered=-1;
    static std::multiset<int> ms;
    ms.clear();
    for (int col = 0; col < nCols; col++) {
        for (int id : open[col]) ms.insert(segs[id].second);
        if (cnt[col] > 0 && covered < col) {
            ans++;
            assert(ms.size());
            covered=*ms.rbegin();
        }
        for (int id : close[col]) ms.erase(ms.find(segs[id].second));
    }
    for (auto &[u,v] : removed) map[u][v]='#';
    return ans;
}
void read(int &nRows, int &nCols, std::vector<std::string>& map, vi &cnt) {
    std::cin >> nRows >> nCols;
    

    map.assign(nRows,{});
    cnt.assign(nCols,{});
    for (auto &it : map) std::cin >> it;
    for (auto &it : cnt) std::cin >> it;
}
void checkAll(const int nRows, const int nCols) {
    std::cout << "checkAll(" << nRows << ", " << nCols << ")" << std::endl;
    static std::vector<std::string> map;
    map.resize(nRows);
    for (auto &it : map) it.resize(nCols,'.');
    static vi cnt;
    cnt.assign(nCols,0);
    for (int mask = 0; mask < (1 << (nRows * nCols)); mask++) {
        std::fill(all(cnt),0);
        

        for (int bit = 0; bit < nRows * nCols; bit++) {
            const int i = bit / nCols;
            const int j = bit % nCols;
            map[i][j] = ".#"[(mask >> bit) & 1];
            cnt[j] += map[i][j] == '#';
        }
        int ok = solveOK(nRows,nCols,map,cnt);
        

        int wa = solveWrong(nRows,nCols,map,cnt);
        

        if (ok != wa) {
            std::cout << nRows << ' ' << nCols << '\n';
            for (auto &it : map) std::cout << it << '\n';
            for (int i = 0; i < nCols; i++) std::cout << cnt[i] << ' ';
            std::cout << std::endl;
            std::cout << "expected = " << ok << std::endl;
            std::cout << "     got = " << wa << std::endl;
            std::exit(0);
        }
    }
}
void brute() {
    for (int prod = 27; prod <= 40; prod+=4) {
        for (int nCols = 2; nCols < prod; nCols++) {
            if (prod % nCols != 0) continue;
            const int nRows = prod / nCols;
            checkAll(nRows,nCols);
            std::cout << "\tnCols = " << nCols << ": OK" << std::endl;
        }
        std::cout << "prod = " << prod << ": OK" << std::endl;
    }
    std::exit(0);
}
int main() {
    

    

    

    

    

    

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int nRows, nCols;
    std::vector<std::string> map;
    vi cnt;
    read(nRows,nCols,map,cnt);
    std::cout << solveWrong(nRows,nCols,map,cnt) << std::endl;
    

    return 0;
}