

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef pair<int, int> PII;






TTi T SQR(T x) { return x * x; }




































TTi T MIN(T x, T y) { return (x < y) ? x : y; }
TTi T MAX(T x, T y) { return (x > y) ? x : y; }
TTi T ABS(T x) { return (x > 0) ? x : -x; }
TTi void UPDATE_MIN(T &x, T y) {if (y < x) {x = y;}}
TTi void UPDATE_MAX(T &x, T y) {if (x < y) {x = y;}}
TTi int ARGMAX(T cont) { return max_element(cont.begin(), cont.end()) - cont.begin(); }
TTi int ARGMIN(T cont) { return min_element(cont.begin(), cont.end()) - cont.begin(); }

vector<string> split(const string& s, char c) {
    vector<string> v; stringstream ss(s); string x;
    while (getline(ss, x, c)) v.emplace_back(x); return move(v);
}
template<typename T, typename... Args>
inline string arrStr(T arr, int n) {
    stringstream s;
    s << "[";
    FORN(i, n - 1) s << arr[i] << ",";
    s << arr[n - 1] << "]";
    return s.str();
}




    
    
    
    

    inline void id4(int line) { cerr << "
    inline void id1(vector<string>::iterator it) {cerr << endl;}

    TTi void id6(vector<T> val) {
        cerr << arrStr(val, val.size());
    }
    TTi void id6(T* val) {
        cerr << arrStr(val, 10);
    }
    TTi void id6(T val) {
        cerr << val;
    }
    template<typename T, typename... Args>
    inline void id1(vector<string>::iterator it, T a, Args... args) {
        cerr << it->substr((*it)[0] == ' ', it->length()) << "=";
        id6(a);
        cerr << "; ";
        id1(++it, args...);
    }

    
    
    
    


template<class T> inline string TOSTR(const T & x) { stringstream ss; ss << x; return ss.str(); }

inline void PR(void) {}
inline void PR(int x) {printf("%d", x);}
inline void PR(LL x) {printf("%lld", x);}
inline void PR(char * s) {printf("%s", s);}
inline void PR(const char * s) {printf("%s", s);}
inline void PR(double f) {printf("%.10lf", f);}
inline void PR(long double f) {printf("%.10llf", f);}
inline void PR(vector<int> &vec) {for(auto x: vec){PR(x);putc(0x20,stdout);}}
TTi void PRS(T x) {PR(x);putc(0x20,stdout);}
TTi void PRN(T x) {PR(x);putc(0x0a,stdout);}
void PRN(void) {putc(0x0a,stdout);}

inline int gcd(int a, int b) { return a ? gcd(b % a, a) : b; }
inline LL gcd(LL a, LL b) { return a ? gcd(b % a, a) : b; }
inline LL powmod(LL a, LL p, LL m) { LL r = 1; while (p) { if (p & 1) r = r*a%m; p>>=1; a=a*a%m; } return r; }

struct pairhash {
    template <typename T, typename U>
    std::size_t operator() (const std::pair<T, U> &x) const {
        return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
    }
};

template <typename K, typename V>
V id9(const std::map<K,V> & m, const K & key, const V & defval ) {
    auto it = m.find(key);
    return (it == m.end()) ? defval : it->second;
}

template <typename K, typename V>
void SetDef(std::map<K,V> & m, const K & key, const V & defval ) {
    auto it = m.find(key);
    if (it == m.end()) m[key] = defval;
}

template <typename K, typename V>
V id9(const std::unordered_map<K,V> & m, const K & key, const V & defval ) {
    auto it = m.find(key);
    return (it == m.end()) ? defval : it->second;
}

template <typename K, typename V>
void SetDef(std::unordered_map<K,V> & m, const K & key, const V & defval ) {
    auto it = m.find(key);
    if (it == m.end()) m[key] = defval;
}

const int MOD = 1000 * 1000 * 1000 + 7;
const double PI = 3.1415926535897932384626433832795l;

inline void addto(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}
inline int add(int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}
inline void subto(int &a, int b) {
    a -= b;
    if (a < 0) a += MOD;
    if (a >= MOD) a -= MOD;
}
inline int sub(int a, int b) {
    a -= b;
    if (a < 0) a += MOD;
    if (a >= MOD) a -= MOD;
    return a;
}
inline void multo(int &a, int b) {
    a = (long long)a * b % MOD;
}
inline int mul(int a, int b) {
    return (long long)a * b % MOD;
}
inline int mulmod(int a, int b, int mod) {
    return (long long)a * b % mod;
}
inline int powmod(int a, int e, int mod) {
    int x;
    for(x = 1; e > 0; e >>= 1) {
        if (e & 1)
            x = mulmod(x, a, mod);
        a = mulmod(a, a, mod);
    }
    return x;
}
inline int id3(int a, int mod) {
    return powmod(a, mod - 2, mod);
}
inline LL id8(LL p){
    LL q=p;
    for(LL a=p*p;a!=1;a*=a) q*=a;
    return q;
}






typedef int NodeValue;
const NodeValue ZERO = 1e9;

struct Node {
    int my_l, my_r;
    Node *pleft = NULL;
    Node *pright = NULL;

    NodeValue my_val;
    NodeValue my_lazy;

    static Node *mem;
    static int id5;

    Node(){}
    Node(int l, int r): my_l(l), my_r(r), my_val(ZERO), my_lazy(ZERO){};
    


    static inline Node * alloc(int l, int r) {
        

        mem[id5] = Node(l, r);
        return &mem[id5++];
    }
    static void clear_all()
    {id5 = 0;}

    

    inline bool inside(int l, int r)
    { return (l <= my_l) && (my_r <= r); }
    inline bool outside(int l, int r)
    { return (r < my_l) || (l > my_r); }
    inline bool single()
    { return (my_l == my_r); }
    inline int length()
    {return (my_r - my_l + 1); }

    

    inline void check_fork() {
        if (pleft) return;
        

        pleft = alloc(my_l, (my_l + my_r) / 2);
        pright = alloc((my_l + my_r) / 2 + 1, my_r);
    }
    inline Node* left()
    { check_fork(); return pleft; }
    inline Node* right()
    { check_fork(); return pright; }

    

    inline static NodeValue combine(NodeValue a, NodeValue b) {
        return min(a, b);
    }

    


    

    NodeValue sum_range(int l, int r) {
        push();
        if (outside(l, r)) return ZERO;
        if (inside(l, r)) return my_val;
        return combine(
            left()->sum_range(l, r),
            right()->sum_range(l, r)
        );
    }
    NodeValue get_single(int l) {
        return sum_range(l, l);
    }

    void set_single(int x, NodeValue new_val) {
        push();
        if (outside(x, x)) return;
        if ((my_l == my_r) && (my_l == x)) {
            my_val = new_val;
            return;
        }
        left()->set_single(x, new_val);
        right()->set_single(x, new_val);
        my_val = combine(left()->my_val, right()->my_val);
    }
    void modify_single(int x, NodeValue new_val) {
        push();
        if (outside(x, x)) return;
        if ((my_l == my_r) && (my_l == x)) {
            my_val = combine(my_val, new_val);
            return;
        }
        left()->modify_single(x, new_val);
        right()->modify_single(x, new_val);
        my_val = combine(left()->my_val, right()->my_val);
    }

    void modify_range(int l, int r, NodeValue new_val) {
        push();
        if (outside(l, r)) return;
        if (inside(l, r)) {
            my_lazy = combine(my_lazy, new_val);
            return;
        }
        left()->modify_range(l, r, new_val);
        right()->modify_range(l, r, new_val);
        my_val = combine(left()->my_val, right()->my_val);
    }
    void push() {
        return;
        if (!single()) {
            left()->my_lazy = combine(left()->my_lazy, my_lazy);
            right()->my_lazy = combine(right()->my_lazy, my_lazy);
        }
        my_val = combine(my_val, my_lazy);
        my_lazy = ZERO;
    }
};
Node memNodes[MAXNODES];
int Node::id5 = 0;
Node* Node::mem = memNodes;


struct WideNode {
    int my_l, my_r;
    WideNode *pleft = NULL;
    WideNode *pright = NULL;

    Node *my_val;
    


    static WideNode *mem;
    static int id5;

    WideNode(){}
    WideNode(int l, int r, int l2, int r2): my_l(l), my_r(r), my_val(Node::alloc(l2, r2))
    { assert(my_l <= my_r); };

    static inline WideNode * alloc(int l, int r, int l2, int r2) {
        

        mem[id5] = WideNode(l, r, l2, r2);
        return &mem[id5++];
    }
    static void clear_all()
    {id5 = 0;}

    

    inline bool inside(int l, int r)
    { return (l <= my_l) && (my_r <= r); }
    inline bool outside(int l, int r)
    { return (r < my_l) || (l > my_r); }
    inline bool single()
    { return (my_l == my_r); }
    inline int length()
    {return (my_r - my_l + 1); }

    

    inline void check_fork() {
        if (pleft) return;
        assert(!single());
        pleft  = alloc(my_l, (my_l + my_r) / 2,       my_val->my_l, my_val->my_r);
        pright = alloc((my_l + my_r) / 2 + 1, my_r,   my_val->my_l, my_val->my_r);
    }
    inline WideNode* left()
    { check_fork(); return pleft; }
    inline WideNode* right()
    { check_fork(); return pright; }

    

    NodeValue sum_range(int l, int r, int l2, int r2) {
        if (outside(l, r)) return ZERO;
        if (inside(l, r)) return my_val->sum_range(l2, r2);
        return Node::combine(
            left()->sum_range(l, r, l2, r2),
            right()->sum_range(l, r, l2, r2)
        );
    }
    NodeValue get_single(int l, int l2) {
        return sum_range(l, l, l2, l2);
    }

    void set_single(int x, int y, NodeValue new_val) {
        if (outside(x, x)) return;
        if ((my_l == my_r) && (my_l == x)) {
            my_val->set_single(y, new_val);
            return;
        }
        left()->set_single(x, y, new_val);
        right()->set_single(x, y, new_val);
        

        

        

        my_val->modify_single(y, new_val);
    }
    void modify_single(int x, int y, NodeValue new_val) {
        if (outside(x, x)) return;
        if ((my_l == my_r) && (my_l == x)) {
            my_val->set_single(y, Node::combine(my_val->get_single(y), new_val));
            return;
        }
        left()->modify_single(x, y, new_val);
        right()->modify_single(x, y, new_val);
        merge_at(y);
    }
    void merge_at(int y) {
        my_val->set_single(y, Node::combine(
            left()->my_val->get_single(y),
            right()->my_val->get_single(y)
        ));
    }
};
WideNode id2[MAXWIDENODES];
int WideNode::id5 = 0;
WideNode* WideNode::mem = id2;











int N, M, K, L, E, Q, P, SY, SX;
int arr[MAXN] = {};


















int mp[MAXN][MAXN] = {};
int mp_rot[4][MAXN][MAXN] = {};
vector<pair<int,int>> by_val[301*301];
int min_dist[500][500] = {};

int cx;
int cy;
bool id0(pair<int, int> yx1, pair<int, int> yx2) {
    int y1 = yx1.first;
    int x1 = yx1.second;
    int y2 = yx2.first;
    int x2 = yx2.second;
    return abs(cx - x1) + abs(cy - y1) < abs(cx - x2) + abs(cy - y2);
}

inline void id7(int & y, int & x, int sy, int sx) {
    int x2 = sy - 1 - y;
    y = x;
    x = x2;
}
template<typename T>
void id7(T src[MAXN][MAXN], T dst[MAXN][MAXN], int sy, int sx) {
    FORN(x, sx) {
        FORN(y, sy) {
            int y2 = x;
            int x2 = sy - 1 - y;
            dst[y2][x2] = src[y][x];
        }
    }
}











int main() {
    ios_base::sync_with_stdio(0);

    SCiii(SY, SX, P);
    FORN(y, SY) {
        FORN(x, SX) {
            SCi(mp[y][x]);
            by_val[mp[y][x]].PB(MP(y, x));
            min_dist[y][x] = 1e9;
        }
    }

    id7(mp,        mp_rot[0], SY, SX);
    id7(mp_rot[0], mp_rot[1], SX, SY);
    id7(mp_rot[1], mp_rot[2], SY, SX);
    id7(mp_rot[2], mp_rot[3], SX, SY);
    id7(mp_rot[3], mp_rot[0], SY, SX);

    int ans = 1e9;

    FOREACH(yx, by_val[1]) {
        int y = yx.first;
        int x = yx.second;
        min_dist[y][x] = y+x;
        if (P == 1)
            UPDATE_MIN(ans, x+y);
    }

    FOR(val, 1, P) {
        EVARS(val, by_val[val].size());
        vector<WideNode> nodes(4, WideNode(0, MAXN, 0, MAXN));
        FOREACH(yx, by_val[val]) {
            int y = yx.first;
            int x = yx.second;
            int dist = min_dist[y][x];
            int sy = SY;
            int sx = SX;
            FORN(r, 4) {
                

                

                

                nodes[r].set_single(x, y, dist + x + y);
                id7(y, x, sy, sx);
                swap(sy, sx);
            }
        }

        FOREACH(yx2, by_val[val+1]) {
            int y2 = yx2.first;
            int x2 = yx2.second;
            int sy = SY;
            int sx = SX;
            int xorig = x2;
            int yorig = y2;
            FORN(r, 4) {
                int dist2 = nodes[r].sum_range(x2, sx, y2, sy) - x2 - y2;
                

                

                UPDATE_MIN(min_dist[yorig][xorig], dist2);
                if (val + 1 == P)
                    UPDATE_MIN(ans, dist2);
                id7(y2, x2, sy, sx);
                swap(sy, sx);
            }
        }
        Node::clear_all();
        WideNode::clear_all();

        EPR("\n");
    }
    PRN(ans);
    return 0;

    priority_queue<pair<int, pair<int, int>>> pq;
    FOREACH(yx, by_val[1]) {
        int y = yx.first;
        int x = yx.second;
        int dist = y + x;
        pq.push(MP( -dist, yx));
        min_dist[y][x] = dist;
        EVARS(x, y, dist);
    }

    while (!pq.empty()) {
        auto s = pq.top(); pq.pop();
        int dist = -s.first;
        if (dist >= ans)
            break;
        int y = s.second.first;
        int x = s.second.second;
        if (dist != min_dist[y][x])
            continue;
        int val = mp[y][x];
        

        

        

        FOREACH(yx2, by_val[val+1]) {
            int y2 = yx2.first;
            int x2 = yx2.second;
            int dist2 = dist + abs(y2 - y) + abs(x2 - x);
            int val2 = mp[y2][x2];
            EVARS(x, y, dist, val, x2, y2, dist2, val2);
            if (val2 == P)
                UPDATE_MIN(ans, dist2);
            else if (dist2 < ans && dist2 < min_dist[y2][x2]) {
                min_dist[y2][x2] = dist2;
                pq.push(MP(-dist2, yx2));
            }
        }
    }
    PRN(ans);


    return 0;
}
