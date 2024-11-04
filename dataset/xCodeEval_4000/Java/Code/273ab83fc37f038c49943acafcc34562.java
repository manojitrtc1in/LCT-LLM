import java.io.*;
import java.security.Guard;
import java.util.*;
import java.util.List;
import java.util.stream.IntStream;

public class Main implements Runnable {
    public static final int LIMIT = 100010;
    int n, m;
    long k;
    static boolean use_n_tests = true;
    int[] a;


    void solve(FastScanner in, PrintWriter out, int testNumber) {
        n = in.nextInt();
        char[] s = in.nextc();
        int k = in.nextInt();
        Set<Character> st = new HashSet<>();
        for (int i = 0; i < k; i++) {
            st.add(in.nextc()[0]);
        }
        int ans = 0;
        int cur = 0;
        int have = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (st.contains(s[i])) {
                if (have == 1) {
                    ans = Math.max(ans, cur + 1);
                }
                cur = 0;
                have = 1;
            } else {
                if (have != 0) {
                    cur++;
                }
            }
        }
        if (have == 1) {
            ans = Math.max(ans, cur);
        }
        out.println(ans);
    }


    boolean isPolindrom(int a) {
        if (a < 10) {
            return true;
        }
        List<Integer> dig = getGidits(a);
        for (int i = 0; i < dig.size() / 2; i++) {
            if (!Objects.equals(dig.get(i), dig.get(dig.size() - 1 - i))) {
                return false;
            }
        }
        return true;
    }

    



    static class SegmentTree {
        int[] delta;
        int n;
        int[][] cnt;

        public SegmentTree(int n) {
            this.n = n;
            delta = new int[4 * n + 10];
            cnt = new int[4][4 * n + 10];
            initCnts(0, 0, n - 1);
        }

        private void initCnts(int root, int rl, int rr) {
            if (rl != rr) {
                int rm = (rl + rr) / 2;
                initCnts(root * 2 + 1, rl, rm);
                initCnts(root * 2 + 2, rm + 1, rr);
            }
            updateCnts(root, rl, rr);
        }

        public void update(int left, int right, int by) {
            internalUpdate(0, 0, n - 1, left, right, by);
        }

        private void internalUpdate(int root, int rl, int rr, int left, int right, int by) {
            if (left > right) return;
            if (rl == left && rr == right) {
                delta[root] += by;
                updateCnts(root, rl, rr);
            } else {
                int rm = (rl + rr) / 2;
                internalUpdate(root * 2 + 1, rl, rm, left, Math.min(right, rm), by);
                internalUpdate(root * 2 + 2, rm + 1, rr, Math.max(rm + 1, left), right, by);
                updateCnts(root, rl, rr);
            }
        }

        private void updateCnts(int root, int rl, int rr) {
            if (delta[root] < 0) {
                throw new RuntimeException();
            }
            for (int i = 0; i < 4; ++i) {
                cnt[i][root] = 0;
            }
            if (rl == rr) {
                ++cnt[Math.min(3, delta[root])][root];
            } else {
                for (int i = 0; i < 4; ++i) {
                    cnt[Math.min(3, i + delta[root])][root] += cnt[i][root * 2 + 1] + cnt[i][root * 2 + 2];
                }
            }
        }

        public int getAnswer(int left, int right) {
            return internalGetAtMost(0, 0, n - 1, left, right, 2);
        }

        private int internalGetAtMost(int root, int rl, int rr, int left, int right, int most) {
            if (left > right || most < 0) return 0;
            if (rl == left && rr == right) {
                int res = 0;
                for (int i = 0; i <= most; ++i) {
                    res += cnt[i][root];
                }
                return res;
            } else {
                int rm = (rl + rr) / 2;
                return
                        internalGetAtMost(root * 2 + 1, rl, rm, left, Math.min(right, rm), most - delta[root]) +
                                internalGetAtMost(root * 2 + 2, rm + 1, rr, Math.max(rm + 1, left), right, most - delta[root]);
            }
        }
    }

    public static class DisjointSets {
        int[] p;
        int[] size;
        int sccCount;

        DisjointSets(int size) {
            p = new int[size];
            this.size = new int[size];
            for (int i = 0; i < size; i++) {
                this.size[i] = 1;
                p[i] = i;
            }
            sccCount = size;
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
            sccCount--;
        }

        int size(int id) {
            return size[root(id)];
        }
    }

    static boolean use_file_insteadof_stdin = false; 


    static String input = "input.txt";
    static String output = "output.txt";

    List<Integer> getGidits(long n) {
        List<Integer> res = new ArrayList<>();
        while (n != 0) {
            res.add((int) (n % 10L));
            n /= 10;
        }
        return res;
    }

    List<Integer> generatePrimes(int n) {
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

    int ask(int l, int r) {
        if (l >= r) {
            return -1;
        }
        System.out.printf("? %d %d\n", l + 1, r + 1);
        System.out.flush();
        return in.nextInt() - 1;
    }

    static int stack_size = 1 << 27;

    class Mod {
        long mod;

        Mod(long mod) {
            this.mod = mod;
        }

        long add(long a, long b) {
            a = mod(a);
            b = mod(b);
            return (a + b) % mod;
        }

        long sub(long a, long b) {
            a = mod(a);
            b = mod(b);
            return (a - b + mod) % mod;
        }

        long mul(long a, long b) {
            a = mod(a);
            b = mod(b);
            return (a * b) % mod;
        }

        long div(long a, long b) {
            a = mod(a);
            b = mod(b);
            return (a * inv(b)) % mod;
        }

        public long inv(long r) {
            if (r == 1)
                return 1;
            return ((mod - mod / r) * inv(mod % r)) % mod;
        }

        private long mod(long a) {
            return a % mod;
        }
    }

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

        public long C(int n, int m) {
            if (cycleWay) {
                return C[n][m];
            }
            return fC(n, m);
        }

        private long fC(int n, int m) {
            return (fact[n] * inv(fact[n - m] * fact[m] % mod)) % mod;
        }

        private long fact(int n) {
            return fact[n];
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

    class MultisetTree<T> {
        int size = 0;

        TreeMap<T, Integer> mp = new TreeMap<>();

        void add(T x) {
            mp.merge(x, 1, Integer::sum);
            size++;
        }

        List<T> getElems() {
            List<T> res = new ArrayList<>();
            for (T k : mp.keySet()) {
                int c = mp.get(k);
                for (int i = 0; i < c; i++) {
                    res.add(k);
                }
            }
            return res;
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

        T smallest() {
            return mp.firstKey();
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

        static List<List<Integer>> intInit2D(int n) {
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

        Graph(int n) {
            create(n);
        }

        private void create(int n) {
            List<List<Integer>> graph = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                graph.add(new ArrayList<>());
            }
            this.graph = graph;
        }

        void readBi(int m, FastScanner in) {
            for (int i = 0; i < m; i++) {
                int v = in.nextInt() - 1;
                int u = in.nextInt() - 1;
                graph.get(v).add(u);
                graph.get(u).add(v);
            }
        }

        void add(int v, int u) {
            graph.get(v).add(u);
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(InputStream io) {
            br = new BufferedReader(new InputStreamReader(io));
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

        public int[] nextArray(int n) {
            int[] res = new int[n];
            for (int i = 0; i < n; i++) {
                res[i] = in.nextInt();
            }
            return res;
        }

        public long[] nextArrayL(int n) {
            long[] res = new long[n];
            for (int i = 0; i < n; i++) {
                res[i] = in.nextLong();
            }
            return res;
        }

        public Long[] nextArrayL2(int n) {
            Long[] res = new Long[n];
            for (int i = 0; i < n; i++) {
                res[i] = in.nextLong();
            }
            return res;
        }


        public Integer[] nextArray2(int n) {
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

    void run_t_tests() {
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
        if (use_file_insteadof_stdin) {
            try {
                in = new FastScanner(new FileInputStream(input));


            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        } else {
            in = new FastScanner(System.in);
        }
        out = new PrintWriter(System.out);
        if (use_n_tests) {
            run_t_tests();
        } else {
            run_one();
        }
        out.close();
    }

    static FastScanner in;
    static PrintWriter out;

    public static void main(String[] args) throws InterruptedException {
        Thread thread = new Thread(null, new Main(), "", stack_size);
        thread.start();
        thread.join();
    }
}