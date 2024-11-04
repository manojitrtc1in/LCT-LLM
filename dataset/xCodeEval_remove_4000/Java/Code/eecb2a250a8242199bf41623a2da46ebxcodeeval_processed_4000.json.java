import com.sun.source.tree.Tree;
import org.w3c.dom.Node;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;


public class Main implements Runnable {
    int n, m, k;
    long n1, s;
    static boolean id9 = true;
    long mod = 1_000_000_007;
    static long mod1 = 998244353L;
    List<Integer> primes = id17(0);

    void solve(FastScanner in, PrintWriter out, int testNumber) {
        n = in.nextInt();
        int a = in.nextInt();
        int b = in.nextInt();
        List<Integer> left = new ArrayList<>();
        List<Integer> right = new ArrayList<>();
        left.add(a);
        right.add(b);
        for (int i = 1; i <= n; i++) {
            if (i < b && i != a && right.size() < n / 2) {
                right.add(i);
            } else if (i > a && i != b && left.size() < n / 2) {
                left.add(i);
            }
        }
        if (left.size() == n / 2 && right.size() == n / 2) {
            for (Integer integer : left) {
                out.print(integer + " ");
            }
            for (Integer integer : right) {
                out.print(integer + " ");
            }
            out.println();
        } else {
            out.println(-1);
        }
    }

    


    static class id6 {

        int[] p;
        int[] result;
        int a, b;

        static List<Integer> used = new ArrayList<>();


        public int maxMatching(List<Integer>[] graph, int n2) {
            int n1 = graph.length;
            int[] matching = new int[n2];
            Arrays.fill(matching, -1);
            int matches = 0;
            boolean[] used = new boolean[n1];
            for (int u = 0; u < n1; u++) {
                for (int x : id6.used) {
                    used[x] = false;
                }
                id6.used.clear();
                if (findPath(graph, u, matching, used))
                    ++matches;
            }

            for (int i = 0; i < n2; ++i) {
                if (matching[i] != -1) {
                    out.println(matching[i] + 1 + " " + (i + 1));
                }
            }
            return matches;
        }

        boolean findPath(List<Integer>[] graph, int u1, int[] matching, boolean[] vis) {
            vis[u1] = true;
            used.add(u1);
            for (int v : graph[u1]) {
                int u2 = matching[v];
                if (u2 == -1 || !vis[u2] && findPath(graph, u2, matching, vis)) {
                    matching[v] = u1;
                    return true;
                }
            }
            return false;
        }

    }

    int[] prefix_function(char[] s) {
        int n = s.length;
        int[] pi = new int[n];
        for (int i = 1; i < n; ++i) {
            int j = pi[i - 1];
            while (j > 0 && s[i] != s[j])
                j = pi[j - 1];
            if (s[i] == s[j]) ++j;
            pi[i] = j;
        }
        return pi;
    }

    static class BIT {
        int[] value;
        int n;

        BIT(int n) {
            this.n = n;
            this.value = new int[n + 1];
        }

        void update(int i, int delta) {
            for (; i < n; i = (i | (i + 1)))
                value[i] += delta;
        }

        int sum(int r) {
            int result = 0;
            for (; r >= 0; r = (r & (r + 1)) - 1)
                result += value[r];
            return result;
        }
    }

    static boolean id11 = false;
    static String input_file = "1.txt";
    static String output_file = "output12.txt";

    static public class id8 {
        int len;
        int[][] up;
        int[] tin;
        int[] tout;
        int time;
        static List<Integer>[] tree;
        static id8 t;

        void dfs(List<Integer>[] tree, int u, int p) {
            tin[u] = time++;
            up[0][u] = p;
            for (int i = 1; i < len; i++)
                up[i][u] = up[i - 1][up[i - 1][u]];
            for (int v : tree[u])
                if (v != p)
                    dfs(tree, v, u);
            tout[u] = time++;
        }

        public id8(List<Integer>[] tree, int root) {
            int n = tree.length;
            len = 1;
            while ((1 << len) <= n) ++len;
            up = new int[len][n];
            tin = new int[n];
            tout = new int[n];
            dfs(tree, root, root);
        }

        boolean isParent(int parent, int child) {
            return tin[parent] <= tin[child] && tout[child] <= tout[parent];
        }

        public int lca(int a, int b) {
            if (isParent(a, b))
                return a;
            if (isParent(b, a))
                return b;
            for (int i = len - 1; i >= 0; i--)
                if (!isParent(up[i][a], b))
                    a = up[i][a];
            return up[0][a];
        }


        public static int id18(int a, int b) {
            return t.lca(a, b);
        }
    }


    List<Integer> factorize(int a) {
        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < primes.size(); i++) {
            int p = primes.get(i);
            while (a % p == 0) {
                res.add(p);
                a /= p;
            }
            if (a == 1 && p > a) {
                break;
            }
        }
        if (a != 1) {
            res.add(a);
        }
        return res;
    }

    void impossible() {
        out.println(-1);
    }

    void yes() {
        out.println("YES");
    }

    void no() {
        out.println("NO");
    }

    static boolean id12(char[] p) {
        for (int a = p.length - 2; a >= 0; --a)
            if (p[a] < p[a + 1])
                for (int b = p.length - 1; ; --b)
                    if (p[b] > p[a]) {
                        char t = p[a];
                        p[a] = p[b];
                        p[b] = t;
                        for (++a, b = p.length - 1; a < b; ++a, --b) {
                            t = p[a];
                            p[a] = p[b];
                            p[b] = t;
                        }
                        return true;
                    }
        return false;
    }

    public static class id1 {
        int[] p;
        int[] size;
        int id10;

        id1(int size) {
            p = new int[size];
            this.size = new int[size];
            for (int i = 0; i < size; i++) {
                this.size[i] = 1;
                p[i] = i;
            }
            id10 = size;
        }

        public int root(int x) {
            return x == p[x] ? x : (p[x] = root(p[x]));
        }

        public void unite(int a, int b) {
            a = root(a);
            b = root(b);
            if (a == b) {
                return;
            }
            if (size[b] > size[a]) {
                int tmp = a;
                a = b;
                b = tmp;
            }
            size[a] += size[b];
            p[b] = a;
            id10--;
        }

        int size(int id) {
            return size[root(id)];
        }
    }

    boolean triangleCheck(int a, int b, int c) {
        return a + b > c && a + c > b && b + c > a;
    }

    Map<Integer, Integer> numberCompression(List<Integer> ls) {
        Collections.sort(ls);
        int id = 1;
        Map<Integer, Integer> comp = new HashMap<>();
        for (int num : ls) {
            if (!comp.containsKey(num)) {
                comp.put(num, id++);
            }
        }
        return comp;
    }

    long lcm(long a, long b) {
        return (a / gcd(a, b)) * b;
    }

    long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    int gcd(int a, int b) {
        return (int) gcd(a, (long) b);
    }

    class Pt {
        int x, y;

        Pt(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public int getX() {
            return x;
        }

        public int getY() {
            return y;
        }

        boolean sameAxis(Pt b) {
            return b.x == x || b.y == y;
        }

        int id14(Pt b) {
            return Math.abs(x - b.x) + Math.abs(y - b.y);
        }

        void read() {
            x = in.nextInt();
            y = in.nextInt();
        }

        long getHash() {
            return x * 1000000000L + (long) y;
        }
    }

    void swap(Integer[] a, int i, int j) {
        Integer tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }

    void swap(List<Integer> a, int i, int j) {
        Integer tmp = a.get(i);
        a.set(i, a.get(j));
        a.set(j, tmp);
    }

    long id5(long x, long y, long x1, long y1) {
        return Math.abs(x - x1) + Math.abs(y - y1);
    }

    double dist(double x, double y, double x1, double y1) {
        return Math.sqrt(Math.pow(x - x1, 2.0) + Math.pow(y - y1, 2.0));
    }

    public static class FW {
        public static void add(long[] t, int i, long value) {
            for (; i < t.length; i |= i + 1)
                t[i] += value;
        }

        public static long sum(long[] t, int i) {
            long res = 0;
            for (; i >= 0; i = (i & (i + 1)) - 1)
                res += t[i];
            return res;
        }

        public static void add(long[] t, int a, int b, long value) {
            add(t, a, value);
            add(t, b + 1, -value);
        }
    }

    int sign(int a) {
        if (a < 0) {
            return -1;
        }
        return 1;
    }

    long binpow(long a, int b) {
        long res = 1;
        while (b != 0) {
            if (b % 2 == 0) {
                b /= 2;
                a *= a;
                a %= mod;
            }

            b--;
            res *= a;
            res %= mod;
        }
        return res;
    }

    List<Integer> getDigits(long n) {
        List<Integer> res = new ArrayList<>();
        while (n != 0) {
            res.add((int) (n % 10L));
            n /= 10;
        }
        return res;
    }

    List<Integer> id17(int n) {
        List<Integer> res = new ArrayList<>();
        boolean[] sieve = new boolean[n + 1];
        for (int i = 2; i <= n; i++) {
            if (!sieve[i]) {
                res.add(i);
            }
            if ((long) i * i <= n) {
                for (int j = i * i; j <= n; j += i) {
                    sieve[j] = true;
                }
            }
        }
        return res;
    }

    static int stack_size = 1 << 29;

    static class Coeff {
        long mod;
        long[][] C;
        long[] fact;
        boolean cycleWay = false;

        Coeff(int n, long mod) {
            this.mod = mod;
            fact = new long[n + 1];
            fact[0] = 1;
            for (int i = 1; i <= n; i++) {
                fact[i] = i;
                fact[i] %= mod;
                fact[i] *= fact[i - 1];
                fact[i] %= mod;
            }
        }

        Coeff(int n, int m, long mod) {
            

            cycleWay = true;
            this.mod = mod;
            C = new long[n + 1][m + 1];
            for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= Math.min(i, m); j++) {
                    if (j == 0 || j == i) {
                        C[i][j] = 1;
                    } else {
                        C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
                        C[i][j] %= mod;
                    }
                }
            }
        }

        public long fact(int n) {
            return fact[n];
        }

        public long C(int n, int m) {
            if (cycleWay) {
                return C[n][m];
            }
            return fC(n, m);
        }

        private long fC(int n, int m) {
            return (fact[n] * inv(fact[n - m] * fact[m] % mod)) % mod;
        }

        private long inv(long r) {
            if (r == 1)
                return 1;
            return ((mod - mod / r) * inv(mod % r)) % mod;
        }
    }

    class Pair {
        int first;
        long second;

        Pair(int f, long s) {
            first = f;
            second = s;
        }

        public int getFirst() {
            return first;
        }

        public long getSecond() {
            return second;
        }
    }

    class id13<T> {
        int size = 0;

        TreeMap<T, Integer> mp = new TreeMap<>();

        void add(T x) {
            mp.merge(x, 1, Integer::sum);
            size++;
        }

        void remove(T x) {
            if (mp.containsKey(x)) {
                mp.merge(x, -1, Integer::sum);
                if (mp.get(x) == 0) {
                    mp.remove(x);
                }
                size--;
            }
        }

        boolean contains(T x) {
            return mp.containsKey(x);
        }

        T greatest() {
            return mp.lastKey();
        }

        Integer keyCnt(T x) {
            return mp.get(x);
        }

        T higher(T x) {
            return mp.higherKey(x);
        }

        T smaller(T x) {
            return mp.lowerKey(x);
        }

        T id15(T x) {
            if (mp.containsKey(x)) {
                return x;
            }
            return smaller(x);
        }

        T smallest() {
            return mp.firstKey();
        }

        T biggest() {
            return mp.lastKey();
        }

        int size() {
            return size;
        }

        int diffSize() {
            return mp.size();
        }
    }

    class Multiset<T> {
        int size = 0;

        Map<T, Integer> mp = new HashMap<>();

        void add(T x) {
            mp.merge(x, 1, Integer::sum);
            size++;
        }

        boolean contains(T x) {
            return mp.containsKey(x);
        }

        void remove(T x) {
            if (mp.containsKey(x)) {
                mp.merge(x, -1, Integer::sum);
                if (mp.get(x) == 0) {
                    mp.remove(x);
                }
                size--;
            }
        }

        int size() {
            return size;
        }

        int diffSize() {
            return mp.size();
        }
    }

    static class Range {
        int l, r;
        int id;

        public int getL() {
            return l;
        }

        public int getR() {
            return r;
        }

        public Range(int l, int r, int id) {
            this.l = l;
            this.r = r;
            this.id = id;
        }
    }

    static class Array {
        static Range[] readRanges(int n, FastScanner in) {
            Range[] result = new Range[n];
            for (int i = 0; i < n; i++) {
                result[i] = new Range(in.nextInt(), in.nextInt(), i);
            }
            return result;
        }

        static List<List<Integer>> id7(int n) {
            List<List<Integer>> res = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                res.add(new ArrayList<>());
            }
            return res;
        }

        static boolean isSorted(Integer[] a) {
            for (int i = 0; i < a.length - 1; i++) {
                if (a[i] > a[i + 1]) {
                    return false;
                }
            }
            return true;
        }

        static public long sum(List<Integer> a) {
            long sum = 0;
            for (int x : a) {
                sum += x;
            }
            return sum;
        }

        static public long sum(int[] a) {
            long sum = 0;
            for (int x : a) {
                sum += x;
            }
            return sum;
        }

        static public long sum(long[] a) {
            long sum = 0;
            for (long x : a) {
                sum += x;
            }
            return sum;
        }

        static public long sum(Integer[] a) {
            long sum = 0;
            for (int x : a) {
                sum += x;
            }
            return sum;
        }

        static public int min(Integer[] a) {
            int mn = Integer.MAX_VALUE;
            for (int x : a) {
                mn = Math.min(mn, x);
            }
            return mn;
        }

        static public int min(int[] a) {
            int mn = Integer.MAX_VALUE;
            for (int x : a) {
                mn = Math.min(mn, x);
            }
            return mn;
        }

        static public int max(Integer[] a) {
            int mx = Integer.MIN_VALUE;
            for (int x : a) {
                mx = Math.max(mx, x);
            }
            return mx;
        }

        static public int max(int[] a) {
            int mx = Integer.MIN_VALUE;
            for (int x : a) {
                mx = Math.max(mx, x);
            }
            return mx;
        }

        static public int[] readint(int n, FastScanner in) {
            int[] out = new int[n];
            for (int i = 0; i < out.length; i++) {
                out[i] = in.nextInt();
            }
            return out;
        }
    }

    class Graph {
        List<List<Integer>> graph;
        public List<Integer> edges;

        Graph(int n) {
            create(n);
        }

        private void create(int n) {
            List<List<Integer>> graph = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                graph.add(new ArrayList<>());
            }
            this.graph = graph;
            this.edges = new ArrayList<>();
        }

        int size() {
            return graph.size();
        }

        List<Integer> abj(int v) {
            return graph.get(v);
        }

        void read(int m, FastScanner in) {
            for (int i = 0; i < m; i++) {
                int v = in.nextInt() - 1;
                int u = in.nextInt() - 1;
                graph.get(v).add(u);
            }
        }

        void readBi(int m, FastScanner in) {
            for (int i = 0; i < m; i++) {
                int v = in.nextInt() - 1;
                int u = in.nextInt() - 1;
                addEdge(v, u);
                edges.add(v);
                edges.add(u);
            }
        }

        public void addEdge(int v, int u) {
            graph.get(v).add(u);
            graph.get(u).add(v);
        }

        public void id4(int v, int u) {
            graph.get(v).add(u);
        }

    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(InputStream io) {
            br = new BufferedReader(new InputStreamReader(io));
        }

        public boolean ready() {
            try {
                return br.ready();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return false;
        }

        public String line() {
            String result = "";
            try {
                result = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return result;
        }

        public String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        public char[] nextc() {
            return next().toCharArray();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public int[] nextArray(int n) {
            int[] res = new int[n];
            for (int i = 0; i < n; i++) {
                res[i] = in.nextInt();
            }
            return res;
        }

        public int[] nextArray() {
            int n = in.nextInt();
            return nextArray(n);
        }

        public long[] id3(int n) {
            long[] res = new long[n];
            for (int i = 0; i < n; i++) {
                res[i] = in.nextLong();
            }
            return res;
        }

        public Long[] id16(int n) {
            Long[] res = new Long[n];
            for (int i = 0; i < n; i++) {
                res[i] = in.nextLong();
            }
            return res;
        }


        public Integer[] id2(int n) {
            Integer[] res = new Integer[n];
            for (int i = 0; i < n; i++) {
                res[i] = in.nextInt();
            }
            return res;
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

    }

    void id0() {
        int t = in.nextInt();
        int i = 0;
        while (t-- > 0) {
            solve(in, out, i++);
        }
    }

    void run_one() {
        solve(in, out, -1);
    }

    @Override
    public void run() {
        try {
            in = new FastScanner(id11 ? new FileInputStream(input_file) : System.in);
            out = new PrintWriter(id11 ? new FileOutputStream(output_file) : System.out);
            if (id9) {
                id0();
            } else {
                run_one();
            }
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static FastScanner in;
    static PrintWriter out;

    public static void main(String[] args) throws InterruptedException {
        Thread thread = new Thread(null, new Main(), "", stack_size);
        thread.start();
        thread.join();
    }
}
