#include <bits/stdc++.h>

using namespace std;

template <typename T> struct Point {
    Point() {}
    Point(T x_, T y_): x(x_), y(y_) {}
    Point& operator+=(Point const&o) {
        x += o.x;
        y += o.y;
        return *this;
    }
    Point& operator-=(Point const&o) {
        x -= o.x;
        y -= o.y;
        return *this;
    }
    Point operator-() const {
        return Point{-x, -y};
    }
    T sq() const {
        return x * x + y * y;
    }
    friend Point operator+(Point a, Point const& b) {
        a += b;
        return a;
    }
    friend Point operator-(Point a, Point const& b) {
        a -= b;
        return a;
    }
    friend T dot(Point const& a, Point const& b) {
        return a.x*b.y + a.y*b.y;
    }
    friend T cross(Point const& a, Point const& b) {
        return a.x*b.y - a.y*b.x;
    }
    friend bool operator<(Point const& a, Point const& b) {
        return tie(a.x, a.y) < tie(b.x, b.y);
    }
    friend bool operator>(Point const& a, Point const& b) {
        return b < a;
    }
    friend ostream& operator<<(ostream& o, Point const& p) {
        o << "[" << p.x << ", " << p.y << "]";
        return o;
    }

    T x = 0;
    T y = 0;
};

template <typename T> struct Point2 : public Point<T> {
    Point2(Point<T> p): Point<T>(p.x, p.y) {}
    friend bool operator<(Point2 const& a, Point2 const& b) {
        bool lower_a = (a.y < 0) or ((a.y == 0) and (a.x < 0));
        bool lower_b = (b.y < 0) or ((b.y == 0) and (b.x < 0));
        return make_pair(lower_a, cross(b, a)) < make_pair(lower_b, T(0));
    }
};

template<typename T> int ccw(Point<T> const& a, Point<T> const& b){
    T x = cross(a, b);
    return (x > 0) - (x < 0);
}

template<typename T> int ccw(Point<T> const& a, Point<T> const& b, Point<T> const& c){
    return ccw(b - a, c - a);
}





template <typename T> struct UpperHull {
    struct Link{
        Point<T> p;
        Link *prev = nullptr, *next = nullptr;
        int id;
    };
    struct Node{
        Link *chain, *chain_back;
        Link *tangent;
    };
    template<typename S, typename U>
    pair<Link*, Link*> find_bridge(Link*l, Link*r, S next, U convex){
        while(next(l) || next(r)){
            if(!next(r) || (next(l) && convex(Point<T>{0, 0}, next(l)->p - l->p, next(r)->p - r->p))){
                if(convex(l->p, next(l)->p, r->p)){
                    l = next(l);
                } else {
                    break;
                }
            } else {
                if(!convex(l->p, r->p, next(r)->p)){
                    r = next(r);
                } else {
                    break;
                }
            }
        }
        return {l, r};
    }
    template<bool rev = false>
    void fix_chain(int u, Link*l, Link*r){
        if(rev){ 

            tie(r, l) = find_bridge(r, l,
                [](Link*x){ return x->prev; },
                [](Point<T> const&a, Point<T> const&b, Point<T> const&c){
                    return ccw(a, b, c) >= 0;
                });
        } else { 

            tie(l, r) = find_bridge(l, r,
                [](Link*x){ return x->next; },
                [](Point<T> const&a, Point<T> const&b, Point<T> const&c){
                    return ccw(a, b, c) <= 0;
                });
        }
        tree[u].tangent = l;
        tree[u].chain = tree[2*u].chain;
        tree[u].chain_back = tree[2*u+1].chain_back;
        tree[2*u].chain = l->next;
        tree[2*u+1].chain_back = r->prev;
        if(l->next){
            l->next->prev = nullptr;
        } else {
            tree[2*u].chain_back = nullptr;
        }
        if(r->prev){
            r->prev->next = nullptr;
        } else {
            tree[2*u+1].chain = nullptr;
        }
        l->next = r;
        r->prev = l;
    }
    void build(int u, int a, int b){
        if(b-a == 1){
            tree[u].chain = tree[u].chain_back = &lists[a];
            tree[u].tangent = nullptr;
            return;
        }
        const int m = a + (b-a)/2;
        build(2*u, a, m);
        build(2*u+1, m, b);
        auto l = tree[2*u].chain, r = tree[2*u+1].chain;
        fix_chain(u, l, r);
    }

    void rob(int u, int v){
            tree[u].chain = tree[v].chain;
            tree[v].chain = nullptr;
            tree[u].chain_back = tree[v].chain_back;
            tree[v].chain_back = nullptr;
    }

    void remove(int u, int a, int b, int const&i){
        if(i < a || i >= b) return;
        

        assert(b-a > 1);
        const int m = a + (b-a)/2;
        

        if(!tree[u].tangent){
            int v = i<m ? 2*u : 2*u+1;
            tree[v].chain = tree[u].chain;
            tree[v].chain_back = tree[u].chain_back;
            if(i < m){
                remove(2*u, a, m, i);
            } else {
                remove(2*u+1, m, b, i);
            }
            rob(u, v);
            return;
        }
        

        auto l = tree[u].tangent, r = l->next;
        l->next = tree[2*u].chain;
        if(tree[2*u].chain){
            tree[2*u].chain->prev = l;
        } else {
            tree[2*u].chain_back = l;
        }
        tree[2*u].chain = tree[u].chain;
        r->prev = tree[2*u+1].chain_back;
        if(tree[2*u+1].chain_back){
            tree[2*u+1].chain_back->next = r;
        } else {
            tree[2*u+1].chain = r;
        }
        tree[2*u+1].chain_back = tree[u].chain_back;
        

        const int v = i<m ? 2*u : 2*u+1;
        

        if(tree[v].chain == tree[v].chain_back && tree[v].chain->id == i){
            tree[v].chain = tree[v].chain_back = nullptr;
            rob(u, v^1);
            tree[u].tangent = nullptr;
            return;
        }
        if(i < m){
            if(l->id == i){
                l = l->next;
            }
            remove(2*u, a, m, i);
            if(!l){
                l = tree[2*u].chain_back;
            }
            fix_chain<true>(u, l, r);
        } else {
            if(r->id == i){
                r = r->prev;
            }
            remove(2*u+1, m, b, i);
            if(!r){
                r = tree[2*u+1].chain;
            }
            fix_chain<false>(u, l, r);
        }
    }
    void remove(int i){
        

        if(tree[1].chain == tree[1].chain_back){
            tree[1].chain = tree[1].chain_back = nullptr;
            return;
        }
        remove(1, 0, n, i);
    }
    UpperHull<T>(vector<Point<T>> const&v) : n(v.size()), tree(4*n), lists(n){
        assert(is_sorted(v.begin(), v.end()));
        for(int i=0; i<n; ++i){
            lists[i].p = v[i];
            lists[i].id = i;
        }
        build(1, 0, n);
    }
    vector<int> get_hull(){
        vector<int> ret;
        for(Link* u = tree[1].chain; u; u=u->next){
            ret.push_back(u->id);
        }
        return ret;
    }
    vector<Point<T>> get_hull_points(){
        vector<Point<T>> ret;
        for(Link* u = tree[1].chain; u; u=u->next){
            ret.push_back(u->p);
        }
        return ret;
    }

    int n;
    vector<Node> tree;
    vector<Link> lists;
};

template <typename T> struct DecrConvexHull {
    DecrConvexHull(vector<Point<T>> const& ps): n(ps.size()), ps(ps), idxs(n), inv_idxs(n) {
        for (auto i = 0U; i < n; ++i) {
            idxs[i] = i;
        }
        sort(idxs.begin(), idxs.end(), [&](int i, int j) { return ps[i] < ps[j]; });
        for (auto i = 0U; i < n; ++i) {
            inv_idxs[idxs[i]] = i;
        }
        vector<Point<T>> upper_ps(n);
        vector<Point<T>> lower_ps(n);
        for (auto i = 0U; i < n; ++i) {
            upper_ps[i] = ps[idxs[i]];
            lower_ps[i] = -ps[idxs[n - 1 - i]];
        }
        upper_hull = make_unique<UpperHull<T>>(upper_ps);
        lower_hull = make_unique<UpperHull<T>>(lower_ps);
    }
    vector<int> get_hull() {
        vector<int> upper_res = upper_hull->get_hull();
        vector<int> lower_res = lower_hull->get_hull();
        vector<int> res;
        if (upper_res.empty() or lower_res.empty()) {
            assert (upper_res.empty() and lower_res.empty());
            return lower_res;
        }
        for (auto r : upper_res) {
            res.push_back(idxs[r]);
        }
        unordered_set<int> seen(res.begin(), res.end());
        for (auto r2 : lower_res) {
            auto r = idxs[n - 1 - r2];
            if (seen.find(r) == seen.end()) {
                res.push_back(r);
            }
        }
        return res;
    }
    void remove(int i) {
        upper_hull->remove(inv_idxs[i]);
        lower_hull->remove(n - 1 - inv_idxs[i]);
    }

    uint32_t n;
    const vector<Point<T>>& ps;
    vector<int> idxs;
    vector<int> inv_idxs;
    unique_ptr<UpperHull<T>> upper_hull;
    unique_ptr<UpperHull<T>> lower_hull;
};


template <typename T>
struct OuterHull {
    using P = Point<T>;
    using P2 = Point2<T>;
    map<P2, int> directions;
    OuterHull(vector<P>& ps)
    {
        

        int n = static_cast<int>(ps.size());
        for (int i = 0; i < n; ++i) {
            int j = (i + 1) % n;
            directions[P2(ps[j] - ps[i])] = i;
        }
        

        

        

        

        

    }
    int get_left(P& dir) {
        auto it = directions.lower_bound(P2(dir));
        if (it == directions.end()) {
            it = directions.begin();
        }
        auto a = P2(dir);
        auto b = it->first;
        

        return it->second;
    }
};

template<typename T>
void solve() {
    using P = Point<T>;
    using LayerPos = pair<int, int>; 

    using Edge = pair<int, int>; 

    using Query = pair<P, int>; 

    int n;
    cin >> n;
    vector<P> ps(n);
    for (auto& p : ps) {
        cin >> p.x >> p.y;
    }
    int Q;
    cin >> Q;
    vector<Query> qs(Q);
    for (auto& q : qs) {
        cin >> q.first.x >> q.first.y >> q.second;
    }
    DecrConvexHull<T> decr_convex_hull(ps);
    vector<vector<int>> layers;
    
    vector<LayerPos> layer_pos(n, { -1, -1 });
    for (int num_removed = 0; num_removed != n;) {
        assert (num_removed < n);
        vector<int> layer_rev = decr_convex_hull.get_hull();
        vector<int> layer(layer_rev.rbegin(), layer_rev.rend());
        

        

        

        

        

        num_removed += static_cast<int>(layer.size());
        for (int j = 0; j < (int) layer.size(); ++j) {
            int i = layer[j];
            decr_convex_hull.remove(i);
            layer_pos[i] = { static_cast<int>(layers.size()), j };
        }
        layers.push_back(layer);
    }
    vector<int> parents(n, -1);
    for (int k = 0; k < static_cast<int>(layers.size()) - 1; ++k) {
        

        const auto& next_layer = layers[k + 1];
        int next_size = static_cast<int>(next_layer.size());
        int cur_p = 0;
        for (int j = 0; j < (int) layers[k].size(); ++j) {
            int i = layers[k][j];
            

            while (true) {
                

                auto& a = ps[next_layer[(cur_p - 1 + next_size) % next_size]];
                auto& b = ps[next_layer[cur_p]];
                auto& c = ps[next_layer[(cur_p + 1) % next_size]];
                if (ccw(ps[i], b, a) >= 0 and ccw(ps[i], b, c) >= 0) {
                    break;
                }
                ++cur_p;
                if (cur_p == next_size) {
                    cur_p = 0;
                }
            }
            int i2 = layers[k][(j + 1) % layers[k].size()];
            parents[i2] = next_layer[cur_p];
        }
    }
    int K = 1;
    while ((1 << K) < static_cast<int>(layers.size())) {
        ++K;
    }
    vector<vector<Edge>> edges(K + 1, vector<Edge>(n, {-1, -1}));
    for (int i = 0; i < n; ++i) {
        if (parents[i] == -1) {
            edges[0][i] = { i, 0 };
        } else {
            edges[0][i] = { parents[i], static_cast<int>(layers[layer_pos[i].first].size()) };
        }
    }
    for (int k = 1; k <= K; ++k) {
        for (int u0 = 0; u0 < n; ++u0) {
            auto [u1, d1] = edges[k - 1][u0];
            auto [u2, d2] = edges[k - 1][u1];
            edges[k][u0] = { u2, d1 + d2 };
        }
    }
    vector<P> outer_layer;
    for (int i : layers[0]) {
        outer_layer.push_back(ps[i]);
    }
    OuterHull<T> outer_hull(outer_layer);
    function<int (int, int, int)> get_parent = [&](int u, int k, int d) {
        auto [layer_num, idx_at_layer] = layer_pos[u];
        auto& cur_layer = layers[layer_num];
        int layer_size = static_cast<int>(cur_layer.size());
        if (d < layer_size) {
            return cur_layer[(idx_at_layer + d) % layer_size];
        }
        auto [v, d2] = edges[k][u];
        if (d2 > d) {
            assert (k > 0);
            return get_parent(u, k - 1, d);
        }
        return get_parent(v, k, d - d2);
    };
    for (auto& [dir, m] : qs) {
        int i = layers[0][outer_hull.get_left(dir)];
        

        int k = K;
        cout << get_parent(i, K, m - 1) + 1 << "\n";
    }
}


int main() {
    solve<long long>();
    return 0;
}
