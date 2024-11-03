import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Solution {

    public static boolean useInFile = false;
    public static boolean useOutFile = false;

    public static void main(String args[]) throws IOException {
        InOut inout = new InOut();
        Resolver resolver = new Resolver(inout);


        resolver.solve();


        inout.flush();
    }

    private static class Resolver {

        final long LONG_INF = (long) 1e18;
        final int INF = (int) (1e9 + 7);
        final int MOD = 998244353;
        long f[], inv[];
        InOut inout;

        Resolver(InOut inout) {
            this.inout = inout;
        }

        void initF(int n, int mod) {
            f = new long[n + 1];
            f[1] = 1;
            for (int i = 2; i <= n; i++) {
                f[i] = (f[i - 1] * i) % mod;
            }
        }

        void initInv(int n, int mod) {
            inv = new long[n + 1];
            inv[n] = pow(f[n], mod - 2, mod);
            for (int i = inv.length - 2; i >= 0; i--) {
                inv[i] = inv[i + 1] * (i + 1) % mod;
            }
        }

        long cmn(int n, int m, int mod) {
            return f[n] * inv[m] % mod * inv[n - m] % mod;
        }

        int d[] = {0, -1, 0, 1, 0};

        boolean legal(int r, int c, int n, int m) {
            return r >= 0 && r < n && c >= 0 && c < m;
        }

        int[] getBits(int n) {
            int b[] = new int[31];
            for (int i = 0; i < 31; i++) {
                if ((n & (1 << i)) != 0) {
                    b[i] = 1;
                }
            }
            return b;
        }

        private long ask2(long a, long b, long c, long d) throws IOException {
            format("? %d %d %d %d\n", a, b, c, d);
            flush();
            return nextLong(25);
        }

        private long ask1(long l, long r) throws IOException {
            format("? %d %d\n", l, r);
            flush();
            return nextLong(25);
        }

        void solve() throws IOException {
            int tt = 1;
            boolean hvt = true;
            if (hvt) {
                tt = nextInt();


            }






            for (int cs = 1; cs <= tt; cs++) {
                long rs = 0;
                boolean ok = true;



                long l = nextLong(25);
                long r = nextLong(25);
                long a = BinSearch.bs(1, (long) (1e9 + 1), new BinSearch.IBinSearch() {
                    @Override
                    public boolean binSearchCmp(long k) throws IOException {
                        return k * k < l;
                    }
                });
                if (a * a > l) a--;
                long b = BinSearch.bs(1, (long) (1e9 + 1), new BinSearch.IBinSearch() {
                    @Override
                    public boolean binSearchCmp(long k) throws IOException {
                        return k * k < r;
                    }
                });
                if (b * b > r) b--;
                rs = (b - a) * 3;
                rs += 1 + (r - b * b) / b;
                if (a * a < l) {
                    rs = rs - (1 + (l - 1 - a * a) / a);
                }










































                print("" + rs);






                if (cs < tt) {
                    format("\n");


                    

                }
                

            }
        }

        private void updateSegTree(int n, long l, SegmentTree lft) {
            long lazy;
            lazy = 1;
            for (int j = 1; j <= l; j++) {
                lazy = (lazy + cmn((int) l, j, INF)) % INF;
                lft.modify(1, j, j, lazy);
            }
            lft.modify(1, (int) (l + 1), n, lazy);
        }

        String next() throws IOException {
            return inout.next();
        }

        String next(int n) throws IOException {
            return inout.next(n);
        }

        String nextLine() throws IOException {
            return inout.nextLine();
        }

        int nextInt() throws IOException {
            return inout.nextInt();
        }

        long nextLong(int n) throws IOException {
            return inout.nextLong(n);
        }

        int[] anInt(int i, int j) throws IOException {
            int a[] = new int[j + 1];
            for (int k = i; k <= j; k++) {
                a[k] = nextInt();
            }
            return a;
        }

        long[] anLong(int i, int j) throws IOException {
            long a[] = new long[j + 1];
            for (int k = i; k <= j; k++) {
                a[k] = nextInt();
            }
            return a;
        }

        long[] anLong(int i, int j, int len) throws IOException {
            long a[] = new long[j + 1];
            for (int k = i; k <= j; k++) {
                a[k] = nextLong(len);
            }
            return a;
        }

        void print(long a[], int l, int r) {
            for (int i = l; i <= r; i++) {
                format("%s%d", i > l ? " " : "", a[i]);
            }
        }

        void print(int a[], int l, int r) {
            for (int i = l; i <= r; i++) {
                format("%s%d", i > l ? "\n" : "", a[i]);
            }
        }

        void print(String s) {
            inout.print(s, false);
        }

        void print(String s, boolean nextLine) {
            inout.print(s, nextLine);
        }

        void format(String format, Object... obj) {
            inout.format(format, obj);
        }

        void flush() {
            inout.flush();
        }

        void swap(int a[], int i, int j) {
            a[i] ^= a[j];
            a[j] ^= a[i];
            a[i] ^= a[j];
        }

        void swap(long a[], int i, int j) {
            a[i] ^= a[j];
            a[j] ^= a[i];
            a[i] ^= a[j];
        }

        int getP(int x, int p[]) {
            if (p[x] == 0 || p[x] == x) {
                return x;
            }
            return p[x] = getP(p[x], p);
        }

        void union(int x, int y, int p[]) {
            if (x < y) {
                p[y] = x;
            } else {
                p[x] = y;
            }
        }

        boolean topSort() {
            int n = adj2.length - 1;
            int d[] = new int[n + 1];
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j < adj2[i].size(); j++) {
                    d[adj2[i].get(j)[0]]++;
                }
            }
            List<Integer> list = new ArrayList<>();
            for (int i = 1; i <= n; i++) {
                if (d[i] == 0) {
                    list.add(i);
                }
            }
            for (int i = 0; i < list.size(); i++) {
                for (int j = 0; j < adj2[list.get(i)].size(); j++) {
                    int t = adj2[list.get(i)].get(j)[0];
                    d[t]--;
                    if (d[t] == 0) {
                        list.add(t);
                    }
                }
            }
            return list.size() == n;
        }

        class DSU {
            int[] f, siz;

            DSU(int n) {
                f = new int[n];
                siz = new int[n];
                Arrays.fill(siz, 1);
            }

            int leader(int x) {
                while (x != f[x]) x = f[x] = f[f[x]];
                return x;
            }

            boolean same(int x, int y) {
                return leader(x) == leader(y);
            }

            boolean merge(int x, int y) {
                x = leader(x);
                y = leader(y);
                if (x == y) return false;
                siz[x] += siz[y];
                f[y] = x;
                return true;
            }

            int size(int x) {
                return siz[leader(x)];
            }
        }

        ;

        class SegmentTreeNode {
            long defaultVal = 0;
            int l, r;
            

            long val = 0;
            long lazy = defaultVal;

            SegmentTreeNode(int l, int r) {
                this.l = l;
                this.r = r;
            }
        }

        class SegmentTree {
            SegmentTreeNode tree[];
            long inf = Long.MIN_VALUE;
            long c[];

            SegmentTree(int n) {
                assert n > 0;
                tree = new SegmentTreeNode[n * 3 + 1];
            }

            void setAn(long cn[]) {
                c = cn;
            }

            SegmentTree build(int k, int l, int r) {
                if (l > r) {
                    return this;
                }
                if (null == tree[k]) {
                    tree[k] = new SegmentTreeNode(l, r);
                }
                if (l == r) {


                    return this;
                }
                int mid = (l + r) >> 1;
                build(k << 1, l, mid);
                build(k << 1 | 1, mid + 1, r);
                tree[k].val = (tree[k << 1].val + tree[k << 1 | 1].val) % MOD;


                return this;
            }

            void pushDown(int k) {
                if (tree[k].l == tree[k].r) {
                    return;
                }
                long lazy = tree[k].lazy;


                tree[k << 1].val += lazy;
                tree[k << 1].lazy += lazy;


                tree[k << 1 | 1].val += lazy;
                tree[k << 1 | 1].lazy += lazy;
                tree[k].lazy = 0;
            }

            void modify(int k, int l, int r, long change) {
                if (tree[k].l >= l && tree[k].r <= r) {


                    tree[k].val += change;
                    tree[k].lazy += change;
                    return;
                }
                int mid = (tree[k].l + tree[k].r) >> 1;
                if (tree[k].lazy != 0) {
                    pushDown(k);
                }
                if (mid >= l) {
                    modify(k << 1, l, r, change);
                }
                if (mid + 1 <= r) {
                    modify(k << 1 | 1, l, r, change);
                }
                tree[k].val = (tree[k << 1].val + tree[k << 1 | 1].val) % MOD;


            }

            long query(int k, int l, int r) {
                if (tree[k].l > r || tree[k].r < l) {
                    return 0;
                }
                if (tree[k].lazy != 0) {
                    pushDown(k);
                }
                if (tree[k].l >= l && tree[k].r <= r) {
                    return tree[k].val;
                }
                long ans = (query(k << 1, l, r) + query(k << 1 | 1, l, r)) % MOD;
                if (tree[k].l < tree[k].r) {
                    tree[k].val = (tree[k << 1].val + tree[k << 1 | 1].val) % MOD;


                }
                return ans;
            }
        }

        class BitMap {
            boolean[] vis = new boolean[32];
            List<Integer> g[];

            void init() {
                for (int i = 0; i < 32; i++) {
                    g = new List[32];
                    g[i] = new ArrayList<>();
                }
            }

            void dfs(int p) {
                if (vis[p]) return;
                vis[p] = true;
                for (int it : g[p]) dfs(it);
            }

            boolean connected(int a[], int n) {
                int m = 0;
                for (int i = 0; i < n; i++) if (a[i] == 0) return false;
                for (int i = 0; i < n; i++) m |= a[i];
                for (int i = 0; i < 31; i++) g[i].clear();
                for (int i = 0; i < n; i++) {
                    int last = -1;
                    for (int j = 0; j < 31; j++)
                        if ((a[i] & (1 << j)) > 0) {
                            if (last != -1) {
                                g[last].add(j);
                                g[j].add(last);
                            }
                            last = j;
                        }
                }

                Arrays.fill(vis, false);
                for (int j = 0; j < 31; j++)
                    if (((1 << j) & m) > 0) {
                        dfs(j);
                        break;
                    }
                for (int j = 0; j < 31; j++) if (((1 << j) & m) > 0 && !vis[j]) return false;
                return true;
            }
        }


        class BinaryIndexedTree {

            int n = 1;
            long C[];

            BinaryIndexedTree(int sz) {
                while (n <= sz) {
                    n <<= 1;
                }
                n = sz + 1;
                C = new long[n];
            }

            int lowbit(int x) {
                return x & -x;
            }

            void add(int x, long val) {
                while (x < n) {
                    C[x] += val;
                    x += lowbit(x);
                }
            }

            long getSum(int x) {
                long res = 0;
                while (x > 0) {
                    res += C[x];
                    x -= lowbit(x);
                }
                return res;
            }

            int binSearch(long sum) {
                if (sum == 0) {
                    return 0;
                }
                int n = C.length;
                int mx = 1;
                while (mx < n) {
                    mx <<= 1;
                }
                int res = 0;
                for (int i = mx / 2; i >= 1; i >>= 1) {
                    if (C[res + i] < sum) {
                        sum -= C[res + i];
                        res += i;
                    }
                }
                return res + 1;
            }
        }

        static class TrieNode {
            int cnt = 0;

            TrieNode next[];

            TrieNode() {
                next = new TrieNode[2];
            }

            private void insert(TrieNode trie, int ch[], int i) {
                while (i < ch.length) {
                    int idx = ch[i];
                    if (null == trie.next[idx]) {
                        trie.next[idx] = new TrieNode();
                    }
                    trie.cnt++;
                    trie = trie.next[idx];
                    i++;
                }
            }

            private static int query(TrieNode trie) {
                if (null == trie) {
                    return 0;
                }
                int ans[] = new int[2];
                for (int i = 0; i < trie.next.length; i++) {
                    if (null == trie.next[i]) {
                        continue;
                    }
                    ans[i] = trie.next[i].cnt;
                }
                if (ans[0] == 0 && ans[0] == ans[1]) {
                    return 0;
                }
                if (ans[0] == 0) {
                    return query(trie.next[1]);
                }
                if (ans[1] == 0) {
                    return query(trie.next[0]);
                }
                return Math.min(ans[0] - 1 + query(trie.next[1]), ans[1] - 1 + query(trie.next[0]));
            }
        }

        

        class TreeNode {
            int val;
            int tier = -1;
            TreeNode parent;
            TreeNode left;
            TreeNode right;

            TreeNode(int val) {
                this.val = val;
            }
        }

        

        void tierTree(TreeNode root) {
            if (null == root) {
                return;
            }
            if (null != root.parent) {
                root.tier = root.parent.tier + 1;
            } else {
                root.tier = 0;
            }
            tierTree(root.left);
            tierTree(root.right);
        }

        

        TreeNode[][] lca;
        TreeNode[] tree;

        void lcaDfsTree(TreeNode root) {
            if (null == root) {
                return;
            }
            tree[root.val] = root;
            TreeNode nxt = root.parent;
            int idx = 0;
            while (null != nxt) {
                lca[root.val][idx] = nxt;
                nxt = lca[nxt.val][idx];
                idx++;
            }
            lcaDfsTree(root.left);
            lcaDfsTree(root.right);
        }

        TreeNode lcaTree(TreeNode root, int n, TreeNode x, TreeNode y) throws IOException {
            if (null == root) {
                return null;
            }
            if (-1 == root.tier) {
                tree = new TreeNode[n + 1];
                tierTree(root);
            }
            if (null == lca) {
                lca = new TreeNode[n + 1][31];
                lcaDfsTree(root);
            }
            int z = Math.abs(x.tier - y.tier);
            int xx = x.tier > y.tier ? x.val : y.val;
            while (z > 0) {
                final int zz = z;
                int l = (int) BinSearch.bs(0, 31
                        , k -> zz < (1 << k));
                xx = lca[xx][l].val;
                z -= 1 << l;
            }
            int yy = y.val;
            if (x.tier <= y.tier) {
                yy = x.val;
            }
            while (xx != yy) {
                final int xxx = xx;
                final int yyy = yy;
                int l = (int) BinSearch.bs(0, 31
                        , k -> (1 << k) <= tree[xxx].tier && lca[xxx][(int) k] != lca[yyy][(int) k]);
                xx = lca[xx][l].val;
                yy = lca[yy][l].val;
            }
            return tree[xx];
        }
        


        

        List<Integer> adj[];
        List<int[]> adj2[];

        void initGraph(int n) throws IOException {
            initGraph(n, 0, false, false, 1, false);
        }

        void initGraph(int n, int m, boolean hasW, boolean directed, int type, boolean useInput) throws IOException {
            if (type == 1) {
                adj = new List[n + 1];
            } else {
                adj2 = new List[n + 1];
            }
            for (int i = 1; i <= n; i++) {
                if (type == 1) {
                    adj[i] = new ArrayList<>();
                } else {
                    adj2[i] = new ArrayList<>();
                }
            }
            if (!useInput) return;
            for (int i = 0; i < m; i++) {
                int f = nextInt();
                int t = nextInt();
                if (type == 1) {
                    adj[f].add(t);
                    if (!directed) {
                        adj[t].add(f);
                    }
                } else {
                    int w = hasW ? nextInt() : 0;
                    adj2[f].add(new int[]{t, w});
                    if (!directed) {
                        adj2[t].add(new int[]{f, w});
                    }
                }
            }
        }

        void getDiv(Map<Integer, Integer> map, long n) {
            int sqrt = (int) Math.sqrt(n);
            for (int i = 2; i <= sqrt; i++) {
                int cnt = 0;
                while (n % i == 0) {
                    cnt++;
                    n /= i;
                }
                if (cnt > 0) {
                    map.put(i, cnt);
                }
            }
            if (n > 1) {
                map.put((int) n, 1);
            }
        }

        boolean[] generatePrime(int n) {
            boolean p[] = new boolean[n + 1];
            p[2] = true;

            for (int i = 3; i <= n; i += 2) {
                p[i] = true;
            }

            for (int i = 3; i <= Math.sqrt(n); i += 2) {
                if (!p[i]) {
                    continue;
                }
                for (int j = i * i; j <= n; j += i << 1) {
                    p[j] = false;
                }
            }
            return p;
        }

        boolean isPrime(long n) { 

            int p[] = {2, 3, 5, 233, 331};
            int pn = p.length;
            long s = 0, t = n - 1;

            while ((t & 1) == 0) {
                t >>= 1;
                ++s;
            }
            for (int i = 0; i < pn; ++i) {
                if (n == p[i]) {
                    return true;
                }
                long pt = pow(p[i], t, n);
                for (int j = 0; j < s; ++j) {
                    long cur = llMod(pt, pt, n);
                    if (cur == 1 && pt != 1 && pt != n - 1) {
                        return false;
                    }
                    pt = cur;
                }
                if (pt != 1) {
                    return false;
                }
            }
            return true;
        }

        long[] llAdd2(long a[], long b[], long mod) {
            long c[] = new long[2];
            c[1] = (a[1] + b[1]) % (mod * mod);
            c[0] = (a[1] + b[1]) / (mod * mod) + a[0] + b[0];
            return c;
        }

        long[] llMod2(long a, long b, long mod) {
            long x1 = a / mod;
            long y1 = a % mod;
            long x2 = b / mod;
            long y2 = b % mod;
            long c = (x1 * y2 + x2 * y1) / mod;
            c += x1 * x2;
            long d = (x1 * y2 + x2 * y1) % mod * mod + y1 * y2;
            return new long[]{c, d};
        }

        long llMod(long a, long b, long mod) {
            if (a > mod || b > mod) {
                return (a * b - (long) ((double) a / mod * b + 0.5) * mod + mod) % mod;
            }
            return a * b % mod;
            

            

            

            

            

            

            

            

            

            

            

        }

        long pow(long a, long n) {
            long ans = 1;
            while (n > 0) {
                if ((n & 1) == 1) {
                    ans = ans * a;
                }
                a = a * a;
                n >>= 1;
            }
            return ans;
        }

        long pow(long a, long n, long mod) {
            long ans = 1;
            while (n > 0) {
                if ((n & 1) == 1) {
                    ans = llMod(ans, a, mod);
                }
                a = llMod(a, a, mod);
                n >>= 1;
            }
            return ans;
        }

        private long[][] initC(int n) {
            long c[][] = new long[n][n];

            for (int i = 0; i < n; i++) {
                c[i][0] = 1;
            }

            for (int i = 1; i < n; i++) {
                for (int j = 1; j <= i; j++) {
                    c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
                }
            }
            return c;
        }

        
        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        


        long[] exGcd(long a, long b) {
            if (b == 0) {
                return new long[]{a, 1, 0};
            }
            long[] ans = exGcd(b, a % b);
            long x = ans[2];
            long y = ans[1] - a / b * ans[2];
            ans[1] = x;
            ans[2] = y;
            return ans;
        }

        long gcd(long a, long b) {
            if (a < b) {
                return gcd(b, a);
            }
            while (b != 0) {
                long tmp = a % b;
                a = b;
                b = tmp;
            }
            return a;
        }

        int[] unique(int a[], Map<Integer, Integer> idx) {
            int tmp[] = a.clone();
            Arrays.sort(tmp);
            int j = 0;
            for (int i = 0; i < tmp.length; i++) {
                if (i == 0 || tmp[i] > tmp[i - 1]) {
                    idx.put(tmp[i], j++);
                }
            }
            int rs[] = new int[j];
            j = 0;
            for (int key : idx.keySet()) {
                rs[j++] = key;
            }
            Arrays.sort(rs);
            return rs;
        }

        boolean isEven(long n) {
            return (n & 1) == 0;
        }

        static class BinSearch {

            static long bs(long l, long r, IBinSearch sort) throws IOException {
                while (l < r) {
                    long m = l + (r - l) / 2;
                    if (sort.binSearchCmp(m)) {
                        l = m + 1;
                    } else {
                        r = m;
                    }
                }
                return l;
            }

            interface IBinSearch {
                boolean binSearchCmp(long k) throws IOException;
            }

        }
    }

    private static class InOut {
        private BufferedReader br;
        private StreamTokenizer st;
        private PrintWriter pw;

        InOut() throws FileNotFoundException {
            if (useInFile) {
                System.setIn(new FileInputStream("resources/inout/in.text"));
            }
            if (useOutFile) {
                System.setOut(new PrintStream("resources/inout/out.text"));
            }
            br = new BufferedReader(new InputStreamReader(System.in));
            st = new StreamTokenizer(br);
            pw = new PrintWriter(new OutputStreamWriter(System.out));
            st.ordinaryChar('\'');
            st.ordinaryChar('\"');
            st.ordinaryChar('/');
        }

        private boolean hasNext() throws IOException {
            return st.nextToken() != StreamTokenizer.TT_EOF;
        }

        private String next() throws IOException {
            if (st.nextToken() == StreamTokenizer.TT_EOF) {
                throw new IOException();
            }
            return st.sval;
        }

        private String next(int n) throws IOException {
            return next(n, false);
        }

        private String next(int len, boolean isDigit) throws IOException {
            char ch[] = new char[len];
            int cur = 0;
            char c;
            while ((c = (char) br.read()) == '\n' || c == '\r' || c == ' ' || c == '\t'
                    || (isDigit && (c < '0' || c > '9') && c != '-' && c != '+')) ;
            do {
                ch[cur++] = c;
            } while (!((c = (char) br.read()) == '\n' || c == '\r' || c == ' ' || c == '\t')
                    && (!isDigit || c >= '0' && c <= '9'));
            return String.valueOf(ch, 0, cur);
        }

        private int nextInt() throws IOException {
            if (st.nextToken() == StreamTokenizer.TT_EOF) {
                throw new IOException();
            }
            return (int) st.nval;
        }

        private long nextLong(int n) throws IOException {
            return Long.parseLong(next(n, true));
        }

        private double nextDouble() throws IOException {
            st.nextToken();
            return st.nval;
        }

        private String[] nextSS(String reg) throws IOException {
            return br.readLine().split(reg);
        }

        private String nextLine() throws IOException {
            return br.readLine();
        }

        private void print(String s, boolean newLine) {
            if (null != s) {
                pw.print(s);
            }
            if (newLine) {
                pw.println();
            }
        }

        private void format(String format, Object... obj) {
            pw.format(format, obj);
        }

        private void flush() {
            pw.flush();
        }
    }

    private static class FFT {
        double[] roots;
        int maxN;

        public FFT(int maxN) {
            this.maxN = maxN;
            initRoots();
        }

        public long[] multiply(int[] a, int[] b) {
            int minSize = a.length + b.length - 1;
            int bits = 1;
            while (1 << bits < minSize) bits++;
            int N = 1 << bits;
            double[] aa = toComplex(a, N);
            double[] bb = toComplex(b, N);
            fftIterative(aa, false);
            fftIterative(bb, false);
            double[] c = new double[aa.length];
            for (int i = 0; i < N; i++) {
                c[2 * i] = aa[2 * i] * bb[2 * i] - aa[2 * i + 1] * bb[2 * i + 1];
                c[2 * i + 1] = aa[2 * i] * bb[2 * i + 1] + aa[2 * i + 1] * bb[2 * i];
            }
            fftIterative(c, true);
            long[] ret = new long[minSize];
            for (int i = 0; i < ret.length; i++) {
                ret[i] = Math.round(c[2 * i]);
            }
            return ret;
        }

        static double[] toComplex(int[] arr, int size) {
            double[] ret = new double[size * 2];
            for (int i = 0; i < arr.length; i++) {
                ret[2 * i] = arr[i];
            }
            return ret;
        }

        void initRoots() {
            roots = new double[2 * (maxN + 1)];
            double ang = 2 * Math.PI / maxN;
            for (int i = 0; i <= maxN; i++) {
                roots[2 * i] = Math.cos(i * ang);
                roots[2 * i + 1] = Math.sin(i * ang);
            }
        }

        int bits(int N) {
            int ret = 0;
            while (1 << ret < N) ret++;
            if (1 << ret != N) throw new RuntimeException();
            return ret;
        }

        void fftIterative(double[] array, boolean inv) {
            int bits = bits(array.length / 2);
            int N = 1 << bits;
            for (int from = 0; from < N; from++) {
                int to = Integer.reverse(from) >>> (32 - bits);
                if (from < to) {
                    double tmpR = array[2 * from];
                    double tmpI = array[2 * from + 1];
                    array[2 * from] = array[2 * to];
                    array[2 * from + 1] = array[2 * to + 1];
                    array[2 * to] = tmpR;
                    array[2 * to + 1] = tmpI;
                }
            }
            for (int n = 2; n <= N; n *= 2) {
                int delta = 2 * maxN / n;
                for (int from = 0; from < N; from += n) {
                    int rootIdx = inv ? 2 * maxN : 0;
                    double tmpR, tmpI;
                    for (int arrIdx = 2 * from; arrIdx < 2 * from + n; arrIdx += 2) {
                        tmpR = array[arrIdx + n] * roots[rootIdx] - array[arrIdx + n + 1] * roots[rootIdx + 1];
                        tmpI = array[arrIdx + n] * roots[rootIdx + 1] + array[arrIdx + n + 1] * roots[rootIdx];
                        array[arrIdx + n] = array[arrIdx] - tmpR;
                        array[arrIdx + n + 1] = array[arrIdx + 1] - tmpI;
                        array[arrIdx] += tmpR;
                        array[arrIdx + 1] += tmpI;
                        rootIdx += (inv ? -delta : delta);
                    }
                }
            }
            if (inv) {
                for (int i = 0; i < array.length; i++) {
                    array[i] /= N;
                }
            }
        }
    }
}
