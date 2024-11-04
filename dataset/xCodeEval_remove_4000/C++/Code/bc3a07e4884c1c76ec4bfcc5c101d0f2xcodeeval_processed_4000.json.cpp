




















    
     
     
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }

     
inline int readChar();
template <class T = int> inline T readInt(); 
template <class T> inline void writeInt( T x, char end = 0 );
inline void writeChar( int x ); 
inline void writeWord( const char *s );
     

     
static const int buf_size = 4096;
     
inline int getChar() {
    static char buf[buf_size];
    static int len = 0, pos = 0;
    if (pos == len) {
        pos = 0, len = fread(buf, 1, buf_size, stdin);
    }
    if (pos == len) {
        return -1;
    }
    return buf[pos++];
}
     
inline int readChar() {
    int c = getChar();
    while (c <= 32) {
        c = getChar();
    }
    return c;
}
     
template <class T>
inline T readInt() {
    int s = 1, c = readChar();
    T x = 0;
    if (c == '-')
        s = -1, c = getChar();
    while ('0' <= c && c <= '9')
        x = x * 10 + c - '0', c = getChar();
    return s == 1 ? x : -x;
}
     

     
static int write_pos = 0;
static char write_buf[buf_size];
     
inline void writeChar( int x ) {
    if (write_pos == buf_size)
        fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
    write_buf[write_pos++] = x;
}
     
template <class T> 
inline void writeInt( T x, char end ) {
    if (x < 0)
        writeChar('-'), x = -x;
     
    char s[24];
    int n = 0;
    while (x || !n)
        s[n++] = '0' + x % 10, x /= 10;
    while (n--)
        writeChar(s[n]);
    if (end)
        writeChar(end);
}
     
inline void writeWord( const char *s ) {     while (*s)
writeChar(*s++); }
     
struct Flusher {
    ~Flusher() {
        if (write_pos)
            fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
    }
} flusher;   















const string FILENAME = "input";


struct node{
    int l, r, y, p, mod;
    int pr;
};


const int MAXN = 300003;
node TREE[MAXN];
int Link[MAXN];


void init(int u) {
    Link[u] = 0;
    TREE[u].l = 0;
    TREE[u].r = 0;
    TREE[u].y = rand();
    TREE[u].mod = 0;
    TREE[u].pr = 0;
    TREE[u].p = 1;
}


void reverse(int u) {
    TREE[u].mod ^= 1;
}


void update(int v) {
    TREE[v].p = 1;
    if (TREE[v].l) {
        TREE[TREE[v].l].pr = v;
        TREE[v].p += TREE[TREE[v].l].p;
    }
    if (TREE[v].r) {
        TREE[TREE[v].r].pr = v;
        TREE[v].p += TREE[TREE[v].r].p;
    }
}


void push(int v) {
    if (TREE[v].mod) {
        TREE[v].mod = 0;
        swap(TREE[v].l, TREE[v].r);
        if (TREE[v].l) {
            TREE[TREE[v].l].mod ^= 1;
        }
        if (TREE[v].r) {
            TREE[TREE[v].r].mod ^= 1;
        }
    }
}


void split(int v, int x, int &l, int &r) {
    if (v == 0) {
        l = 0;r = 0;
        return;
    }
    push(v);
    int s = (TREE[v].l ? TREE[TREE[v].l].p: 0) + 1;
    if (x >= s) {
        split(TREE[v].r, x - s, TREE[v].r, r);
        l = v;
        update(l);
    } else {
        split(TREE[v].l, x, l, TREE[v].l);
        r = v;
        update(r);
    }
}   


int merge(int l, int r) {
    if (l == 0) {
        return r;
    }
    if (r == 0) {
        return l;
    }
    if (l == r) {
        return l;
    }
    push(l);
    push(r);
    if (TREE[l].y > TREE[r].y) {
        TREE[l].r = merge(TREE[l].r, r);
        update(l);
        return l;
    } else {
        TREE[r].l = merge(l, TREE[r].l);
        update(r);
        return r;
    }
}


int getleft(int v) {
    push(v);
    if (TREE[v].l) {
        return getleft(TREE[v].l);
    }
    return v;
}


inline int find_root(int v) {
    int root = v;
    while (TREE[root].pr) {
        root = TREE[root].pr;
    }
    return root;
}


vector<int> vert;


int getnum(int v) {
    int v1 = v;
    vert.clear();
    vert.push_back(v1);
    while (TREE[v1].pr) {
        v1 = TREE[v1].pr;
        vert.push_back(v1);
    }
    for (int i = (int)vert.size() - 1; i >= 0; i--) {
        push(vert[i]);
    }
    int ans = 1 + (TREE[v].l ? TREE[TREE[v].l].p: 0);
    v1 = v;
    while (TREE[v1].pr) {
        int v2 = TREE[v1].pr;
        if (TREE[v2].l == v1) {
            v1 = v2;
            continue;
        } else {
            ans += 1;
            if (TREE[v2].l) ans += TREE[TREE[v2].l].p;
        }
        v1 = v2;
    }
    return ans;
}


inline void expose(int v) {
    int l = 0, r = 0, rl, a = getnum(v);
    split(find_root(v), a, l, r);
    TREE[r].pr = 0, TREE[l].pr = 0;
    if (r) rl = getleft(r), Link[rl] = v;
    v = getleft(l);
    while (Link[v]) {
        int g = Link[v], l = 0, r = 0;
        split(find_root(g), getnum(g), l, r);
        TREE[r].pr = 0, TREE[l].pr = 0;
        if (r) {
            int gl = getleft(r); 
            Link[gl] = g;
        }
        int a = merge(l, find_root(v));
        Link[v] = 0, TREE[a].pr = 0, v = getleft(a);
    }
}


void make_root(int v) {
    expose(v);
    reverse(find_root(v));
}



int findroot(int u) {
    expose(u);
    return getleft(find_root(u));
}


bool isParent(int u, int v) {
    expose(u);
    expose(v);
    return !Link[getleft(find_root(u))];
}   


void link(int u, int v) {
    Link[u] = v;
    expose(u);
}

void cut(int u, int v) {
    expose(v);
    Link[u] = 0;
    expose(u);
}


void link_edge(int u, int v) {
    make_root(u);
    link(u, v);
}


void cut_edge(int u, int v) {
    make_root(v);
    cut(u, v);
}


int a[MAXN];
int b[MAXN];
vector<pair<int, int> > z[MAXN];
long long ans[MAXN];
vector<int> endings[MAXN];
long long d[MAXN * 5];
long long mod[MAXN * 5];
int ss = 1;


inline void push(int v, int g) {
    if (mod[v] != 0) {
        d[v] += mod[v] * g; 
        if (v < ss) {
            mod[v * 2] += mod[v];
            mod[v * 2 + 1] += mod[v];
        }
        mod[v] = 0;
    }
}


void add(int v, int vl, int vr, int l, int r, int x) {
    if (vl > r || vr < l) {
        push(v, vr - vl + 1);
        return;
    }
    if (l <= vl && vr <= r) {
        mod[v] += x;
        push(v, vr - vl + 1);
        return;
    }
    push(v, vr - vl + 1);
    add(v * 2, vl, (vl + vr) / 2, l, r, x);
    add(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r, x);
    d[v] = d[v * 2] + d[v * 2 + 1];
}


long long rmq(int v, int vl, int vr, int l, int r) {
    if (vl > r || vr < l) {
        return 0;
    }
    if (l <= vl && vr <= r) {
        push(v, vr - vl + 1);
       

       

        return d[v];
    }
    push(v, vr - vl + 1);
    return rmq(v * 2, vl, (vl + vr) / 2, l, r) + rmq(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r);
}



set<int> g[MAXN];
vector<int> gt[MAXN];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  

    int n, m;
    cin >> n >> m;
  

    for (int i = 0; i <= n; i++) {
        init(i);
    }
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
       

        

        if (a[i] > b[i]) {
            swap(a[i], b[i]);
        }
        g[b[i] - 1].insert(a[i]);
        gt[a[i] - 1].push_back(b[i] - 1);
    }
    int q;
    cin >> q;
 

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
       

       

        l--, r--;
        z[l].push_back(make_pair(r, i));
    }
    int uk = -1;
   

    int move = -1;
    for (int i = 0; i < n; i++) {
        if (uk < i) {
            uk = i;
        }
        while (uk + 1 < n && move < i) {
            bool bad = false;
            auto it = g[uk + 1].lower_bound(i + 1);
            vector<int> back;
            for (auto x = it; x != g[uk + 1].end(); x++) {
                int f = *x;
                if (findroot(f) == findroot(uk + 2)) {
                    bad = true;
                    for (auto kek: back) {
                        cut_edge(kek, uk + 2);
                    }
                   

                    break;
                }
                link_edge(f, uk + 2);
                back.push_back(f);
            }
            if (bad) {
                break;
            }
            uk++;
        }
        endings[i].push_back(uk);
        for (auto x: gt[i]) {
            if (x <= uk) {
                cut_edge(i + 1, x + 1);
            }
        }
        

     

    }
   

    ss = 1;
    while (ss <= m) {
        ss <<= 1;
    }
    long long sum = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (auto x: endings[i]) {
            

           

            add(1, 1, ss, i + 1, x + 1, 1);
        }
        for (auto x: z[i]) {
            

           

            ans[x.second] = rmq(1, 1, ss, i + 1, x.first + 1);
        }
    }
   

    for (int i = 0; i < q; i++) {
        cout << ans[i] << '\n';
    }
}