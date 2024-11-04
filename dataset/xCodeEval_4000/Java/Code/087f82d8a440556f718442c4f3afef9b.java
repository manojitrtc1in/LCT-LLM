import java.io.*;
import java.util.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;

public class Main {



    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        int n = in.nextInt();
        long a[] = new long[n];
        int id = -1;
        for (int i = 0; i < n; i++) {
            a[i] = in.nextLong();
            if(a[i] == -1){
                id = i;
            }
            if(id == -1)a[i] = 0;
        }
        long dp[][] = new long[n][18];
        long inf = (long)1e15;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 18; j++) {
                dp[i][j] = inf;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 18; j++) {
                if(i == id){
                    if(i == 0)dp[i][j] = inf;
                    else dp[i][j] = dp[i - 1][j];
                }else{
                    int tobuy = i + 1;
                    

                    if(i > id)tobuy--;
                    

                    if((1<<(j+1)) - 1 > tobuy)dp[i][j] = inf;
                    else{
                        if(i == 0)dp[i][j] = a[0];
                        else if(j == 0)dp[i][j] = min(dp[i-1][j],a[i]);
                        else dp[i][j] = min(dp[i-1][j],dp[i-1][j-1] + a[i]);
                    }
                }
            }
        }


        int log = 1;
        while ((1<<log) < n)++log;
        out.println(dp[n-1][log - 1]);
        out.close();
    }
}
class math {
    static long mod = (int) 1e9 + 7;

    long add(long a, long b) {
        if (a + b >= mod) return a + b - mod;
        return a + b;
    }

    long sqr(long a) {
        if (a * a >= mod) return a * a % mod;
        return a * a;
    }

    long mp(long a, long b) {
        if (a * b >= mod) return a * b % mod;
        return a * b;
    }

    long pow(long a, int n) {
        if (n == 0) return 1;
        if (n == 1) return a;
        if ((n & 1) == 0) {
            long pw = pow(a, n / 2);
            return sqr(pw);
        }
        return mp(a, pow(a, n - 1));
    }

    long gcd(long a, long b) {
        return a == 0 ? b : gcd(b % a, a);
    }
}

class RANDOMIZER {
    static Random rnd = new Random();

    static int randomize() {
        return rnd.nextInt();
    }
}

class array {
    long a[];

    array(long a[]) {
        this.a = a;
    }

    array(int n) {
        a = new long[n];
    }

    void shuffle() {
        for (int i = 0; i < a.length; i++) {
            int id1 = ((RANDOMIZER.randomize() % a.length) + a.length) % a.length;
            int id2 = ((RANDOMIZER.randomize() % a.length) + a.length) % a.length;
            long t = a[id1];
            a[id1] = a[id2];
            a[id2] = t;
        }
    }

    void reverse(int l, int r) {
        for (int i = l; i < l + ((r - l + 1) >> 1); i++) {
            long t = a[i];
            a[i] = a[r - i + l];
            a[r - i + l] = t;
        }
    }

    long[] right_shift(int shift) {
        long aa[] = new long[a.length];
        for (int i = 0; i < a.length; i++) {
            aa[(i + shift) % a.length] = a[i];
        }
        return aa;
    }

    void add(int l, int r, long val) {
        for (int i = l; i <= r; i++) {
            a[i] += val;
        }
    }

    void print(PrintWriter out) {
        for (int i = 0; i < a.length; i++) {
            out.print(a[i] + " ");
        }
    }

    void copy(long t[]) {
        for (int i = 0; i < a.length; i++) {
            a[i] = t[i];
        }
    }

    void scan(FastScanner in) throws IOException {
        for (int i = 0; i < a.length; i++) {
            a[i] = in.nextLong();
        }
    }

    long getSum() {
        long sum = 0;
        long md = (long) 1e16;
        for (int i = 0; i < a.length; i++) {
            sum += a[i];
            sum %= md;
        }
        return sum;
    }

    long getMin() {
        long min = Long.MAX_VALUE;
        for (int i = 0; i < a.length; i++) {
            min = min(min, a[i]);
        }
        return min;
    }

    long getMax() {
        long max = Long.MIN_VALUE;
        for (int i = 0; i < a.length; i++) {
            max = max(max, a[i]);
        }
        return max;
    }

    int ceilingID(long val) {
        int l = 0;
        int r = a.length - 1;
        while (l + 1 != r) {
            int m = (l + r) >> 1;
            if (a[m] >= val) r = m;
            else l = m;
        }
        int pr = l;
        if (pr > 0 && a[pr - 1] >= val) pr--;
        if (a[pr] < val) pr++;
        if (pr < a.length && a[pr] < val) pr++;
        return pr;
    }
}

class dsu {
    int p[];
    int max[];

    dsu(int n) {
        p = new int[n];
        max = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = i;
            max[i] = i;
        }
    }

    int get(int a) {
        if (p[a] == a) return a;
        return p[a] = get(p[a]);
    }

    void merge(int a, int b) {
        a = get(a);
        b = get(b);
        if (a != b) {
            p[a] = b;
            max[b] = max(max[a], max[b]);
        }
    }
}

class vertex {
    int next[];
}

class trie {
    vertex t[];
    int sz = 1;
    int k;

    trie(int k) {
        this.k = k;
        t = new vertex[300000];
        for (int i = 0; i < t.length; i++) {
            t[i] = new vertex();
            t[i].next = new int[k];
            for (int j = 0; j < k; j++) {
                t[i].next[j] = -1;
            }
        }
    }

    void add(String s, int id) {
        int v = 0;
        for (int i = 0; i < s.length(); i++) {
            char rc = (char) (s.charAt(i) - 'a');
            if (t[v].next[rc] == -1) {
                t[v].next[rc] = sz++;
            }
            v = t[v].next[rc];
        }
    }
}

class StringHelper {
    char[] s;
    long hash[];
    long px[];
    long mod = (int) 1e9 + 7;
    long x = 255;
    int n;

    public StringHelper(String s) {
        this.s = s.toCharArray();
        n = s.length();
    }

    int[] pi() {
        int pi[] = new int[n];
        for (int i = 1; i < n; i++) {
            int j = pi[i - 1];
            while (j > 0 && s[i] != s[j]) j = pi[j - 1];
            pi[i] = s[i] == s[j] ? j + 1 : j;
        }
        return pi;
    }

    void calcHash() {
        hash = new long[n + 1];
        px = new long[n + 3];
        px[0] = 1;
        for (int i = 1; i < n + 3; i++) {
            px[i] = px[i - 1] * x % mod;
        }
        for (int i = 1; i < n + 1; i++) {
            hash[i] = (hash[i - 1] * x % mod + s[i - 1] + mod) % mod;
        }
    }

    long getHash(int l, int r) {
        return (hash[r + 1] - hash[l] * px[r - l + 1] % mod + mod) % mod;
    }
}

class IMPLICITDT {
    long val;
    int y;
    int sz;
    IMPLICITDT l, r;

    static int getSize(IMPLICITDT t) {
        return t == null ? 0 : t.sz;
    }

    private static void recalc(IMPLICITDT t) {
        if (t == null) return;
        int LSZ = t.l == null ? 0 : t.l.sz;
        int RSZ = t.r == null ? 0 : t.r.sz;
        t.sz = LSZ + RSZ + 1;
    }

    IMPLICITDT() {
    }

    IMPLICITDT(long cost, int y, IMPLICITDT l, IMPLICITDT r) {
        this.val = cost;
        this.y = y;
        this.l = l;
        this.r = r;
        recalc(this);
    }

    IMPLICITDT(long cost, int y) {
        this.val = cost;
        this.y = y;
        recalc(this);
    }

    static long get(IMPLICITDT t, int id) {
        int LSZ = getSize(t.l);
        if (LSZ == id) return t.val;
        if (LSZ < id) return get(t.r, id - LSZ - 1);
        return get(t.l, id);
    }

    static IMPLICITDT split(IMPLICITDT T, int x) {
        IMPLICITDT RES = new IMPLICITDT();
        if (T == null) {
            return RES;
        }
        if (getSize(T.l) > x) {
            IMPLICITDT lsplit = split(T.l, x);
            RES.l = lsplit.l;
            RES.r = T;
            T.l = lsplit.r;
        } else {
            IMPLICITDT rsplit = split(T.r, x - getSize(T.l) - 1);
            RES.r = rsplit.r;
            RES.l = T;
            T.r = rsplit.l;
        }
        recalc(RES);
        recalc(T);
        return RES;
    }

    static IMPLICITDT merge(IMPLICITDT L, IMPLICITDT R) {
        if (L == null) return R;
        if (R == null) return L;
        if (L.y > R.y) return new IMPLICITDT(L.val, L.y, L.l, merge(L.r, R));
        else return new IMPLICITDT(R.val, R.y, merge(L, R.l), R.r);
    }

    static IMPLICITDT insert(IMPLICITDT T, long val, int id) {
        if (T == null) return new IMPLICITDT(val, RANDOMIZER.randomize());
        IMPLICITDT _T = split(T, id);
        IMPLICITDT _TR = new IMPLICITDT(val, RANDOMIZER.randomize());
        IMPLICITDT NEWTREAP = merge(_T.l, _TR);
        IMPLICITDT TREAP = merge(NEWTREAP, _T.r);
        recalc(TREAP);
        return TREAP;
    }
}

class stSUM {
    int t[];
    int a[];

    stSUM(int a[]) {
        this.a = a;
        t = new int[a.length * 4];
    }

    void build(int v, int l, int r) {
        if (l == r) t[v] = a[l];
        else {
            int m = (l + r) >> 1;
            build(v * 2, l, m);
            build(v * 2 + 1, m + 1, r);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }

    void upd(int v, int l, int r, int pos, int x) {
        if (l == r) t[v] = x;
        else {
            int m = (l + r) >> 1;
            if (pos <= m) upd(v * 2, l, m, pos, x);
            else upd(v * 2 + 1, m + 1, r, pos, x);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }

    int query(int v, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return t[v];
        if (l > qr || ql > r) return 0;
        int m = (l + r) >> 1;
        return query(v * 2, l, m, ql, qr) + query(v * 2 + 1, m + 1, r, ql, qr);
    }
}

class stMIN {
    int t[];
    int a[];

    stMIN(int a[]) {
        this.a = a;
        t = new int[a.length * 4];
    }

    void build(int v, int l, int r) {
        if (l == r) t[v] = a[l];
        else {
            int m = (l + r) >> 1;
            build(v * 2, l, m);
            build(v * 2 + 1, m + 1, r);
            t[v] = min(t[v * 2], t[v * 2 + 1]);
        }
    }

    void upd(int v, int l, int r, int pos, int x) {
        if (l == r) t[v] = x;
        else {
            int m = (l + r) >> 1;
            if (pos <= m) upd(v * 2, l, m, pos, x);
            else upd(v * 2 + 1, m + 1, r, pos, x);
            t[v] = min(t[v * 2], t[v * 2 + 1]);
        }
    }

    int query(int v, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return t[v];
        if (l > qr || ql > r) return Integer.MAX_VALUE;
        int m = (l + r) >> 1;
        return min(query(v * 2, l, m, ql, qr), query(v * 2 + 1, m + 1, r, ql, qr));
    }
}

class DT {
    long val;
    int x, y;
    int sz;
    DT l, r;

    DT() {
        recalc(this);
    }

    DT(int x, int y, long val) {
        this.x = x;
        this.y = y;
        this.val = val;
        recalc(this);
    }

    DT(int x, int y, DT l, DT r, long val) {
        this.x = x;
        this.y = y;
        this.l = l;
        this.r = r;
        this.val = val;
        recalc(this);
    }

    static DT split(DT t, int x) {
        DT res = new DT();
        if (t == null) {
            res.l = null;
            res.r = null;
            return res;
        }
        if (x < t.x) {
            DT lsplit = split(t.l, x);
            res.l = lsplit.l;
            res.r = t;
            t.l = lsplit.r;
        } else {
            DT rsplit = split(t.r, x);
            res.r = rsplit.r;
            res.l = t;
            t.r = rsplit.l;
        }
        recalc(t);
        recalc(res);
        return res;
    }

    static DT merge(DT t1, DT t2) {
        if (t1 == null || t2 == null)
            return t1 == null ? t2 : t1;
        if (t1.y < t2.y) {
            t1.r = merge(t1.r, t2);
            recalc(t1);
            return t1;
        } else {
            t2.l = merge(t1, t2.l);
            recalc(t2);
            return t2;
        }
    }

    static void recalc(DT t) {
        if (t == null) return;
        int lsz = t.l == null ? 0 : t.l.sz;
        int rsz = t.r == null ? 0 : t.r.sz;
        t.sz = lsz + rsz + 1;
    }

    static DT insert(DT t, int x, long val) {
        try {
            if (t == null) {
                DT ret = new DT(x, RANDOMIZER.randomize(), val);
                recalc(ret);
                return ret;
            }
            DT split = split(t, x);
            DT prelast = merge(split.l, new DT(x, RANDOMIZER.randomize(), val));
            DT newtreap = merge(prelast, split.r);
            recalc(newtreap);
            return newtreap;
        } catch (Exception e) {
            System.exit(0);
            return new DT();
        }
    }

    static long find_kth(DT t, int k) {
        if (t.l == null && k == 1)
            return t.val;
        if (t.l != null && t.l.sz == k - 1)
            return t.val;
        if (t.l != null && t.l.sz >= k)
            return find_kth(t.l, k);
        else
            return find_kth(t.r, k - (t.l == null ? 0 : t.l.sz) - 1);
    }

}


class FT {
    private int[] a;
    private long[] t;

    FT(int[] a) {
        this.a = a;
        t = new long[a.length];
    }

    void inc(int i, int delta) {
        for (; i < a.length; i = (i | (i + 1)))
            t[i] += delta;
    }

    long sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    private long sum(int r) {
        long sum = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            sum += t[r];
        }
        return sum;
    }
}


class LAZY_ST {
    long min[], sum[], set[];
    int last;
    long not_set = Long.MAX_VALUE;

    LAZY_ST(long a[]) {
        int n = a.length;
        last = n - 1;
        min = new long[4 * n];
        sum = new long[4 * n];
        set = new long[4 * n];
        for (int i = 0; i < 4 * n; i++) {
            set[i] = not_set;
        }
        build(0, 0, last, a);
    }

    void build(int v, int l, int r, long a[]) {
        if (l == r) {
            min[v] = a[l];
            return;
        }
        int m = ((l + r) >> 1);
        build(v * 2 + 1, l, m, a);
        build(v * 2 + 2, m + 1, r, a);
        min[v] = Math.min(min[v * 2 + 1], min[v * 2 + 2]);
    }

    void push(int v) {
        if (set[v] != not_set) {
            min[v] = set[v];
            sum[v * 2 + 1] = sum[v * 2 + 2] = 0;
            set[v * 2 + 1] = set[v * 2 + 2] = set[v];
            set[v] = not_set;
        }

        min[v] += sum[v];
        sum[v * 2 + 1] += sum[v];
        sum[v * 2 + 2] += sum[v];
        sum[v] = 0;
    }

    void upd(int v) {
        min[v] = Math.min(get_el(v * 2 + 1), get_el(v * 2 + 2));
    }

    long get_el(int v) {
        return (set[v] == not_set ? min[v] : set[v]) + sum[v];
    }

    void set(int l, int r, long x) {
        set(0, 0, last, l, r, x);
    }

    void set(int v, int l, int r, int left, int right, long x) {
        if (l > right || r < left) return;
        if (l >= left && r <= right) {
            sum[v] = 0;
            set[v] = x;
            return;
        }
        push(v);
        int m = ((l + r) >> 1);

        set(v * 2 + 1, l, m, left, right, x);
        set(v * 2 + 2, m + 1, r, left, right, x);

        upd(v);
    }

    void add(int l, int r, long x) {
        add(0, 0, last, l, r, x);
    }

    void add(int v, int l, int r, int left, int right, long x) {
        if (l > right || r < left) return;
        if (l >= left && r <= right) {
            sum[v] += x;
            return;
        }
        push(v);
        int m = ((l + r) >> 1);

        add(v * 2 + 1, l, m, left, right, x);
        add(v * 2 + 2, m + 1, r, left, right, x);

        upd(v);
    }

    long get(int l, int r) {
        return get(0, 0, last, l, r);
    }

    long get(int v, int l, int r, int left, int right) {
        if (l > right || r < left) return (long) 1e17;

        if (l >= left && r <= right) {
            return get_el(v);
        }
        push(v);
        int m = ((l + r) >> 1);

        long ans = Math.min(get(v * 2 + 1, l, m, left, right), get(v * 2 + 2, m + 1, r, left, right));
        upd(v);
        return ans;
    }

}

class multiset {
    TreeMap<Long, Integer> t;

    void insert(long val) {
        t.put(val, t.getOrDefault(val, 0) + 1);
    }

    void erase(long val) {
        int nw = t.getOrDefault(val, 1);
        if (nw == 1) t.remove(val);
        else t.put(val, nw - 1);
    }

    long ceiling(long val) {
        return t.ceilingKey(val);
    }

    long floor(long val) {
        return t.floorKey(val);
    }

    long higher(long val) {
        return t.higherKey(val);
    }

    long lower(long val) {
        return t.lowerKey(val);
    }

    int count(long val) {
        return t.getOrDefault(val, 0);
    }
}

class FastScanner {
    BufferedReader br;
    StringTokenizer st;

    FastScanner(File f) throws FileNotFoundException {
        br = new BufferedReader(new FileReader(f));
    }

    FastScanner(InputStream is) {
        br = new BufferedReader(new InputStreamReader(is));
    }

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }
}

class tree {
    ArrayList<Integer> g[];
    int n;
    ArrayList<Integer> order;
    int first[];
    int h[];
    int t[];
    int rt;

    tree(ArrayList<Integer> g[]) {
        this.g = g;
        this.n = g.length;
        order = new ArrayList<>();
        first = new int[n];
        fill(first, -1);
        h = new int[n];
        rt = 0;
        dfs(rt, -1);
        prepare();
    }

    void dfs(int v, int p) {
        if (first[v] == -1) first[v] = order.size();
        order.add(v);
        for (int to : g[v]) {
            if (to == p) continue;
            h[to] = h[v] + 1;
            dfs(to, v);
            order.add(v);
        }
    }

    void prepare() {
        t = new int[order.size() * 4];
        build(1, 0, order.size() - 1);
    }

    void build(int v, int l, int r) {
        if (l == r) t[v] = order.get(l);
        else {
            int m = (l + r) >> 1;
            build(v * 2, l, m);
            build(v * 2 + 1, m + 1, r);
            t[v] = h[t[v * 2]] < h[t[v * 2 + 1]] ? t[v * 2] : t[v * 2 + 1];
        }
    }

    int query(int v, int l, int r, int ql, int qr) {
        if (l > qr || ql > r) return Integer.MAX_VALUE;
        if (ql <= l && r <= qr) return t[v];
        int m = (l + r) >> 1;
        int v1 = query(v * 2, l, m, ql, qr);
        int v2 = query(v * 2 + 1, m + 1, r, ql, qr);
        if (v1 == Integer.MAX_VALUE) return v2;
        if (v2 == Integer.MAX_VALUE) return v1;
        return h[v1] < h[v2] ? v1 : v2;
    }

    int lca(int a, int b) {
        int l = first[a];
        int r = first[b];
        return query(1, 0, order.size() - 1, min(l, r), max(l, r));
    }
}