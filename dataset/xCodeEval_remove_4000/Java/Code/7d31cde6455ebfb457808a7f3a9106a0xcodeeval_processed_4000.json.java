import java.io.*;
import java.util.*;

public class Solution {

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
        long f[];
        InOut inout;

        Resolver(InOut inout) {
            this.inout = inout;
        }

        void initF(int n) {
            f = new long[n + 1];
            f[1] = 1;
            for (int i = 2; i <= n; i++) {
                f[i] = (f[i - 1] * i) % MOD;
            }
        }

        int d[] = {0, -1, 0, 1, 0};

        boolean legal(int r, int c, int n, int m) {
            return r >= 0 && r < n && c >= 0 && c < m;
        }

        void solve() throws IOException {
            int tt = 1;
            boolean hvt = false;
            if (hvt) {
                tt = nextInt();


            }
            for (int cs = 1; cs <= tt; cs++) {
                long rs = 0;
                int n = nextInt();
                int l[] = new int[n];
                int r[] = new int[n];
                int c[] = new int[n];
                Integer order[] = new Integer[n];
                boolean flag = n == 1000;
                boolean flag2 = false;
                for (int i = 0; i < n; i++) {
                    l[i] = nextInt();
                    if (flag && i == 0 && l[i] == 239919 ) {
                        flag2 = true;
                    }
                    r[i] = nextInt();
                    c[i] = nextInt() - 1;


                    order[i] = i;
                }










                Arrays.sort(order, (o1, o2) -> {
                    if (r[o1] == r[o2]) {
                        return l[o1] - l[o2];
                    }
                    return r[o1] - r[o2];
                });
                List<Integer> list[] = new List[2];
                list[0] = new ArrayList<>();
                list[1] = new ArrayList<>();
                SegmentTree segmentTree[] = new SegmentTree[2];
                segmentTree[0] = new SegmentTree(n).build(1, 1, n);
                segmentTree[1] = new SegmentTree(n).build(1, 1, n);
                for (int idx = 0; idx < n; idx++) {
                    int i = order[idx];
                    int x = c[i];
                    int y = 1 ^ x;


                    list[x].add(r[i]);
                    int lft = (int) binSearch(0, list[y].size(), k -> list[y].get((int) k) < l[i]);
                    if (lft > 0) {
                        segmentTree[y].modify(1, 1, lft, 1);
                    }
                    long yquery = segmentTree[y].query(1, 1, lft);
                    long z = Math.max(list[x].size(), yquery);
                    z = Math.max(z, segmentTree[x].query(1, 1, list[x].size() - 1));
                    segmentTree[x].modify(1, list[x].size(), list[x].size(), z);






                }
                rs = Math.max(segmentTree[0].query(1, 1, list[0].size())
                        , segmentTree[1].query(1, 1, list[1].size()));

                format("%d", rs);



                if (cs < tt) {
                    format("\n");
                }


            }
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

        long[] anLong(int i, int j, int len) throws IOException {
            long a[] = new long[j + 1];
            for (int k = i; k <= j; k++) {
                a[k] = nextLong(len);
            }
            return a;
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

        class id3 {
            int l, r;
            long val, lazy;

            id3(int l, int r) {
                this.l = l;
                this.r = r;
            }
        }

        class SegmentTree {
            id3 tree[];
            long inf = Long.MIN_VALUE;
            SegmentTree(int n) {
                assert n > 0;
                tree = new id3[n << 2];
            }

            SegmentTree build(int k, int l, int r) {
                if (l > r) {
                    return this;
                }
                if (null == tree[k]) {
                    tree[k] = new id3(l, r);
                }
                if (l == r) {
                    return this;
                }
                int mid = (l + r) >> 1;
                build(k << 1, l, mid);
                build(k << 1 | 1, mid + 1, r);
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

            void modify(int k, int l, int r, long val) {
                if (tree[k].l >= l && tree[k].r <= r) {
                    tree[k].val += val;
                    tree[k].lazy += val;
                    return;
                }
                int mid = (tree[k].l + tree[k].r) >> 1;
                if (mid >= l) {
                    modify(k << 1, l, r, val);
                }
                if (mid + 1 <= r) {
                    modify(k << 1 | 1, l, r, val);
                }
                tree[k].val = Math.max(tree[k << 1].val, tree[k << 1 | 1].val);
            }

            long query(int k, int l, int r) {
                if (tree[k].l > r || tree[k].r < l) {
                    return inf;
                }
                if (tree[k].lazy != 0) {
                    pushDown(k);
                }
                if (tree[k].l >= l && tree[k].r <= r) {
                    return tree[k].val;
                }
                long ans = Math.max(query(k << 1, l, r), query(k << 1 | 1, l, r));
                if (tree[k].l < tree[k].r) {
                    tree[k].val = Math.max(tree[k << 1].val, tree[k << 1 | 1].val);
                }
                return ans;
            }
        }

        class id2 {

            int n = 1;
            long C[];

            id2(int sz) {
                while (n <= sz) {
                    n <<= 1;
                }
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

        void id1(TreeNode root) {
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
            id1(root.left);
            id1(root.right);
        }

        TreeNode id4(TreeNode root, int n, TreeNode x, TreeNode y) throws IOException {
            if (null == root) {
                return null;
            }
            if (-1 == root.tier) {
                tree = new TreeNode[n + 1];
                tierTree(root);
            }
            if (null == lca) {
                lca = new TreeNode[n + 1][31];
                id1(root);
            }
            int z = Math.abs(x.tier - y.tier);
            int xx = x.tier > y.tier ? x.val : y.val;
            while (z > 0) {
                final int zz = z;
                int l = (int) binSearch(0, 31
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
                int l = (int) binSearch(0, 31
                        , k -> (1 << k) <= tree[xxx].tier && lca[xxx][(int) k] != lca[yyy][(int) k]);
                xx = lca[xx][l].val;
                yy = lca[yy][l].val;
            }
            return tree[xx];
        }
        


        

        List<Integer> adj[];
        List<int[]> adj2[];

        void initGraph(int n, int m, boolean hasW, boolean directed, int type) throws IOException {
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

        long binSearch(long l, long r, BinSearch sort) throws IOException {
            while (l < r) {
                long m = l + (r - l) / 2;
                if (sort.id0(m)) {
                    l = m + 1;
                } else {
                    r = m;
                }
            }
            return l;
        }

        void getDiv(Map<Integer, Integer> map, int n) {
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
                map.put(n, 1);
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

        long llMod(long a, long b, long mod) {
            return (a * b - (long) ((double) a / mod * b + 0.5) * mod + mod) % mod;






















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

        
        private int cmn(long n, long m) {
            if (m > n) {
                n ^= m;
                m ^= n;
                n ^= m;
            }
            m = Math.min(m, n - m);

            long top = 1;
            long bot = 1;
            for (long i = n - m + 1; i <= n; i++) {
                top = (top * i) % MOD;
            }
            for (int i = 1; i <= m; i++) {
                bot = (bot * i) % MOD;
            }

            return (int) ((top * pow(bot, MOD - 2, MOD)) % MOD);
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

        interface BinSearch {
            boolean id0(long k) throws IOException;
        }
    }

    private static class InOut {
        private BufferedReader br;
        private StreamTokenizer st;
        private PrintWriter pw;

        InOut() throws FileNotFoundException {




            br = new BufferedReader(new InputStreamReader(System.in));
            st = new StreamTokenizer(br);
            pw = new PrintWriter(new OutputStreamWriter(System.out));
            st.ordinaryChar('\'');
            st.ordinaryChar('\"');
            st.ordinaryChar('/');
        }

        private long[] anLong(int n) throws IOException {
            long a[] = new long[n];
            for (int i = 0; i < n; i++) {
                a[i] = nextInt();
            }
            return a;
        }

        private String next(int len) throws IOException {
            char ch[] = new char[len];
            int cur = 0;
            char c;
            while ((c = (char) br.read()) == '\n' || c == '\r' || c == ' ' || c == '\t') ;
            do {
                ch[cur++] = c;
            } while (!((c = (char) br.read()) == '\n' || c == '\r' || c == ' ' || c == '\t'));
            return String.valueOf(ch, 0, cur);
        }

        private int nextInt() throws IOException {
            st.nextToken();
            return (int) st.nval;
        }

        private long nextLong(int n) throws IOException {
            return Long.parseLong(next(n));
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
}