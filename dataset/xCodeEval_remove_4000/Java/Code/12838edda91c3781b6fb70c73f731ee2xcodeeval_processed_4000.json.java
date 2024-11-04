
import javax.swing.text.Segment;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.lang.reflect.Array;
import java.math.BigInteger;
import java.util.*;
import java.util.stream.IntStream;
import java.util.stream.Stream;


public class AtCoder implements Runnable {
    static final double time = 1e9;
    static final int MOD = (int) 1e9 + 7;
    static final long mh = Long.MAX_VALUE;
    static final Reader in = new Reader();
    static final PrintWriter out = new PrintWriter(System.out);
    StringBuilder answer = new StringBuilder();
    long start = System.nanoTime();

    public static void main(String[] args) {
        new Thread(null, new AtCoder(), "persefone", 1 << 28).start();
    }

    @Override
    public void run() {
        solve();
        printf();
        out.flush();
    }


    void solve() {
        int m = 100000000;
        int n = in.nextInt();
        int[] l = in.id2(n);
        int[] c = in.id2(n);
        Map<Integer, Integer> dp = new HashMap<>();
        int ans = l[0] == 1 ? c[0] : -1;
        dp.put(l[0], c[0]);
        for (int i = 1; i < n; i++) {
            dp.put(l[i], Math.min(c[i], dp.getOrDefault(l[i], m)));
            Map<Integer, Integer> cur = new HashMap<>();
            for (Map.Entry<Integer, Integer> e : dp.entrySet()) {
                int k = e.getKey();
                int v = e.getValue();
                int g = IntegerUtils.gcd(l[i], k);
                if (!dp.containsKey(g)) cur.put(g, Math.min(cur.getOrDefault(g, m), v + c[i]));
                else if (dp.containsKey(g) && dp.get(g) > v + c[i]) dp.put(g, v + c[i]);
            }

            if (!cur.isEmpty()) dp.putAll(cur);
        }

        printf(dp.containsKey(1) ? dp.get(1) : -1);
    }

    static class IntegerUtils {
        static int gcd(int a, int b) {
            return b == 0 ? a : gcd(b, a % b);
        }
    }

    static class Fenwick {
        private int n = 100010;
        private int[] max;

        public Fenwick() {
            this.max = new int[n];
        }

        public void update(int i, int val) {
            for (; i < n; i += i & -i) max[i] = Math.max(max[i], val);
        }

        public int get(int i) {
            int ans = 0;
            for (; i > 0; i -= i & -i) ans = Math.max(ans, max[i]);
            return ans;
        }

        public void refresh() {
            Arrays.fill(max, 0);
        }
    }

    static class SearchUtils {
        static int lowerBound(int[] arr, int l, int r, int k) {
            int m = 0, ans = r;
            while (l < r) {
                m = l + r >> 1;
                if (arr[m] >= k) ans = r = m; else l = m + 1;
            }
            return ans;
        }

        static int upperBound(int[] arr, int l, int r, int k) {
            int m = 0, ans = r;
            while (l < r) {
                m = l + r >> 1;
                if (arr[m] >= k) ans = r = m; else l = m + 1;
            }
            return ans;
        }

        static <T> int lowerBound(T[] arr, int l, int r, T t, Comparator<T> cmp) {
            int m = 0, ans = r;
            while (l < r) {
                m = l + r >> 1;
                if (cmp.compare(arr[m], t) >= 0) ans = r = m; else l = m + 1;
            }
            return ans;
        }

        static <T> int upperBound(T[] arr, int l, int r, T t, Comparator<T> cmp) {
            int m = 0, ans = r;
            while (l < r) {
                m = l + r >> 1;
                if (cmp.compare(arr[m], t) > 0) ans = r = m; else l = m + 1;
            }
            return ans;
        }
    }

    interface SegmentTree<T> {
        void build(int currentVertex, int currentLeft, int currentRight);
        void update(int currentVertex, int currentLeft, int currentRight, int pos, int value);
        T calc(T a, T b);
        T get(int currentVertex, int currentLeft, int currentRight, int left, int right);
    }

    static class id0 implements SegmentTree<Integer> {
        private int n;
        private int[] a;
        private int[] max;

        public id0(int[] a, int n) {
            this.a = a;
            this.n = n;
            this.max = new int[4 * n + 4];
            build(1, 0, n - 1);
        }

        @Override
        public void build (int currentVertex, int currentLeft, int currentRight) {
            if (currentLeft == currentRight) max[currentVertex] = a[currentLeft];
            else {
                int middle = currentLeft + currentRight >> 1, id4 = currentVertex << 1;
                build(id4, currentLeft, middle);
                build(id4 + 1, middle + 1, currentRight);
                max[currentVertex] = calc(max[id4], max[id4 + 1]);
            }
        }

        @Override
        public Integer calc(Integer x, Integer y) {
            return Math.max(x, y);
        }

        @Override
        public void update(int currentVertex, int currentLeft, int currentRight, int pos, int value) {
            if (currentLeft == currentRight) max[currentVertex] = value;
            else {
                int middle = currentLeft + currentRight >> 1, id4 = currentVertex << 1;
                if (pos <= middle && pos >= currentLeft)
                    update(id4, currentLeft, middle, pos, value);
                else
                    update(id4 + 1, middle + 1, currentRight, pos, value);
                max[currentVertex] = calc(max[id4], max[id4 + 1]);
            }
        }

        void update(int pos, int value) {
            update(1, 0, n - 1, pos, value);
        }

        @Override
        public Integer get(int currentVertex, int currentLeft, int currentRight, int left, int right) {
            if (currentLeft > right || currentRight < left) return -1;
            else if (currentLeft >= left && currentRight <= right) return max[currentVertex];
            else {
                int middle = currentLeft + currentRight >> 1, id4 = currentVertex << 1;
                return calc(get(id4, currentLeft, middle, left, right), get(id4 + 1, middle + 1, currentRight, left, right));

            }
        }

        Integer get(int left, int right) {
            return get(1, 0, n - 1, left, right);
        }

    }

    interface SparseTable {
        int function(int a, int b);
        void build();
        int get(int l, int r);
    }

    static class id5 implements SparseTable {
        private int n, MAX_LENGTH;
        private int[] log;
        private int[][] gcd;

        public id5(int[] a, int n) {
            this.n = n;
            this.log = new int[n + 1];
            for (int i = 2; i <= n; i++) log[i] = log[i >> 1] + 1;
            this.MAX_LENGTH = log[n];
            this.gcd = new int[n + 1][MAX_LENGTH + 1];
            for (int i = 0; i < n; i++) gcd[i][0] = a[i];
            build();
        }

        @Override
        public int function(int a, int b) {
            return b == 0 ? a : function(b, a % b);
        }

        @Override
        public void build() {
            for (int j = 1; j <= MAX_LENGTH; j++)
                for (int i = 0; i <= n - (1 << j); i++)
                    gcd[i][j] = function(gcd[i][j - 1], gcd[i + (1 << j - 1)][j - 1]);
        }

        @Override
        public int get(int l, int r) {
            int k = log[r - l + 1];
            return function(gcd[l][k], gcd[r - (1 << k) + 1][k]);
        }

        int findLeft(int l, int r, int k) {
            int m = 0, R = r, ans = 0, g = 0, t = 0;
            while (l < r) {
                m = l + r >> 1;
                if ((t = get(m, R)) >= k) { ans = r = m; g = t; } else l = m + 1;
            }
            return g == k ? ans : R;
        }

        int findRight(int l, int r, int k) {
            int m = 0, L = l, ans = 0, g = 0, t = 0;
            while (l < r) {
                m = l + r >> 1;
                if ((t = get(L, m)) >= k) { ans = m; l = m + 1; g = t; } else r = m;
            }
            return g == k ? ans : L;
        }

        int find(int cur, int k) {
            return findRight(cur, n, k) - findLeft(0, cur, k) + 1;
        }

    }

    static class id7 {
        private int n;
        private int[] min, a;

        public id7(int[] a, int n) {
            this.n = n;
            this.a = a;
            this.min = new int[4 * n + 4];
            build(1, 0, n - 1);
        }

        private void build(int currentVertex, int currentLeft, int currentRight) {
            if (currentLeft == currentRight) min[currentVertex] = a[currentLeft];
            else {
                int middle = currentLeft + currentRight >> 1, id4 = currentVertex << 1;
                build(id4, currentLeft, middle);
                build(id4 + 1, middle + 1, currentRight);
                min[currentVertex] = Math.min(min[id4], min[id4 + 1]);
            }
        }

        private void update(int currentVertex, int currentLeft, int currentRight, int pos, int value) {
            if (currentLeft == currentRight) min[currentVertex] = a[pos] = value;
            else {
                int middle = currentLeft + currentRight >> 1, id4 = currentVertex << 1;
                if (pos <= middle && pos >= currentLeft)
                    update(id4, currentLeft, middle, pos, value);
                else
                    update(id4 + 1, middle + 1, currentRight, pos, value);
                min[currentVertex] = Math.min(min[id4], min[id4 + 1]);
            }
        }

        public void update(int pos, int value) {
            update(1, 0, n - 1, pos, value);
        }

        private int getMin(int currentVertex, int currentLeft, int currentRight, int left, int right) {
            if (left > currentRight || right < currentLeft) return Integer.MAX_VALUE;
            if (currentLeft >= left && currentRight <= right) return min[currentVertex];
            int middle = currentLeft + currentRight >> 1, id4 = currentVertex << 1;
            return Math.min(getMin(id4, currentLeft, middle, left, right),
                    getMin(id4 + 1, middle + 1, currentRight, left, right));
        }

        public int getMin(int left, int right) {
            return getMin(1, 0, n - 1, left, right);
        }
    }

    static class ArrayUtils {
        static void compressed(int[] a, int n) {
            int[] b = a.clone();
            Arrays.sort(b, 0, n);
            for (int i = 0; i < n; i++) a[i] = lw(b, 0, n, a[i]) + 1;
        }

        static int lw(int[] b, int l, int r, int k) {
            int R = r, m = 0;
            while (l <= r) {
                m = l + r >> 1;
                if (m == R) return m;
                if (b[m] >= k) r = m - 1;
                else l = m + 1;
            }
            return l;
        }

        static void compressed(long[] a, int n) {
            long[] b = a.clone();
            Arrays.sort(b, 0, n);
            for (int i = 0; i < n; i++) a[i] = lw(b, 0, n, a[i]) + 1;
        }

        static int lw(long[] b, int l, int r, long k) {
            int R = r, m = 0;
            while (l <= r) {
                m = l + r >> 1;
                if (m == R) return m;
                if (b[m] >= k) r = m - 1;
                else l = m + 1;
            }
            return l;
        }

        static int up(int[] b, int l, int r, int k) {
            int R = r, m = 0;
            while (l <= r) {
                m = l + r >> 1;
                if (m == R) return m;
                if (b[m] > k) r = m - 1;
                else l = m + 1;
            }
            return l;
        }
    }

    static class ListUtils {
        static <T extends Comparable<T>> int upperBound(List<T> list, int l, int r, T t) {
            int R = r, m = 0;
            while (l <= r) {
                m = l + r >> 1;
                if (R == m) return m;
                if (list.get(m).compareTo(t) > 0)
                    r = m - 1;
                else
                    l = m + 1;
            }
            return l;
        }

        static <T extends Comparable<T>> int lowerBound(List<T> list, int l, int r, T t) {
            int R = r, m = 0;
            while (l <= r) {
                m = l + r >> 1;
                if (R == m) return m;
                if (list.get(m).compareTo(t) >= 0)
                    r = m - 1;
                else
                    l = m + 1;
            }
            return l;
        }

    }

    void printf() {
        out.print(answer);
    }

    void close() {
        out.close();
    }

    void printf(Stream<?> str) {
        str.forEach(o -> add(o, " "));
        add("\n");
    }


    void printf(Object... obj) {
        printf(false, obj);
    }

    void id6(Object... obj) {
        printf(true, obj);
    }


    private void printf(boolean b, Object... obj) {

        if (obj.length > 1) {
            for (int i = 0; i < obj.length; i++) {
                if (b) add(obj[i].getClass().getSimpleName(), " - ");
                if (obj[i] instanceof Collection<?>) {
                    printf((Collection<?>) obj[i]);
                } else if (obj[i] instanceof int[][]) {
                    printf((int[][]) obj[i]);
                } else if (obj[i] instanceof long[][]) {
                    printf((long[][]) obj[i]);
                } else if (obj[i] instanceof double[][]) {
                    printf((double[][]) obj[i]);
                } else printf(obj[i]);
            }
            return;
        }

        if (b) add(obj[0].getClass().getSimpleName(), " - ");
        printf(obj[0]);
    }

    void printf(Object o) {
        if (o instanceof int[])
            printf(Arrays.stream((int[]) o).boxed());
        else if (o instanceof char[])
            printf(new String((char[]) o));
        else if (o instanceof long[])
            printf(Arrays.stream((long[]) o).boxed());
        else if (o instanceof double[])
            printf(Arrays.stream((double[]) o).boxed());
        else if (o instanceof boolean[]) {
            for (boolean b : (boolean[]) o) add(b, " ");
            add("\n");
        } else
            add(o, "\n");
    }

    void printf(int[]... obj) {
        for (int i = 0; i < obj.length; i++) printf(obj[i]);
    }

    void printf(long[]... obj) {
        for (int i = 0; i < obj.length; i++) printf(obj[i]);
    }

    void printf(double[]... obj) {
        for (int i = 0; i < obj.length; i++) printf(obj[i]);
    }

    void printf(boolean[]... obj) {
        for (int i = 0; i < obj.length; i++) printf(obj[i]);
    }

    void printf(Collection<?> col) {
        printf(col.stream());
    }

    <T, K> void add(T t, K k) {
        if (t instanceof Collection<?>) {
            ((Collection<?>) t).forEach(i -> add(i, " "));
        } else if (t instanceof Object[]) {
            Arrays.stream((Object[]) t).forEach(i -> add(i, " "));
        } else
            add(t);
        add(k);
    }


    <T> void add(T t) {
        answer.append(t);
    }

    @SuppressWarnings("unchecked")
    <T extends Comparable<? super T>> T min(T... t) {
        if (t.length == 0)
            return null;
        T m = t[0];
        for (int i = 1; i < t.length; i++)
            if (t[i].compareTo(m) < 0)
                m = t[i];
        return m;
    }

    @SuppressWarnings("unchecked")
    <T extends Comparable<? super T>> T max(T... t) {
        if (t.length == 0)
            return null;
        T m = t[0];
        for (int i = 1; i < t.length; i++)
            if (t[i].compareTo(m) > 0)
                m = t[i];
        return m;
    }

    int gcd(int a, int b) {
        return (b == 0) ? a : gcd(b, a % b);
    }

    long gcd(long a, long b) {
        return (b == 0) ? a : gcd(b, a % b);
    }

    

    int[] id1(int a, int b) {
        if (b == 0) return new int[]{a, 1, 0};
        int[] vals = id1(b, a % b);
        int d = vals[0]; 

        int p = vals[2]; 

        int q = vals[1] - (a / b) * vals[2];
        return new int[]{d, p, q};
    }

    

    boolean id3(int a, int b, int c, int[] root) {
        int[] vals = id1(Math.abs(a), Math.abs(b));
        if (c % vals[0] != 0) return false;
        printf(vals);
        root[0] = c * vals[1] / vals[0];
        root[1] = c * vals[2] / vals[0];
        if (a < 0) root[0] *= -1;
        if (b < 0) root[1] *= -1;
        return true;
    }

    int mod(int x) {
        return x % MOD;
    }

    int mod(int x, int y) {
        return mod(mod(x) + mod(y));
    }

    long mod(long x) {
        return x % MOD;
    }

    long mod(long x, long y) {
        return mod(mod(x) + mod(y));
    }

    int lw(long[] f, int l, int r, long k) {
        int R = r, m = 0;
        while (l <= r) {
            m = l + r >> 1;
            if (m == R) return m;
            if (f[m] >= k) r = m - 1;
            else l = m + 1;
        }
        return l;
    }

    int up(long[] f, int l, int r, long k) {
        int R = r, m = 0;
        while (l <= r) {
            m = l + r >> 1;
            if (m == R) return m;
            if (f[m] > k) r = m - 1;
            else l = m + 1;
        }
        return l;
    }

    int lw(int[] f, int l, int r, int k) {
        int R = r, m = 0;
        while (l <= r) {
            m = l + r >> 1;
            if (m == R) return m;
            if (f[m] >= k) r = m - 1;
            else l = m + 1;
        }
        return l;
    }

    int up(int[] f, int l, int r, int k) {
        int R = r, m = 0;
        while (l <= r) {
            m = l + r >> 1;
            if (m == R) return m;
            if (f[m] > k) r = m - 1;
            else l = m + 1;
        }
        return l;
    }

    <K extends Comparable<K>> int lw(List<K> li, int l, int r, K k) {
        int R = r, m = 0;
        while (l <= r) {
            m = l + r >> 1;
            if (m == R) return m;
            if (li.get(m).compareTo(k) >= 0)
                r = m - 1;
            else
                l = m + 1;
        }
        return l;
    }

    <K extends Comparable<K>> int up(List<K> li, int l, int r, K k) {
        int R = r, m = 0;
        while (l <= r) {
            m = l + r >> 1;
            if (m == R) return m;
            if (li.get(m).compareTo(k) > 0)
                r = m - 1;
            else
                l = m + 1;
        }
        return l;
    }

    <K extends Comparable<K>> int bs(List<K> li, int l, int r, K k) {
        while (l <= r) {
            int m = l + r >> 1;
            if (li.get(m) == k) return m;
            else if (li.get(m).compareTo(k) < 0)
                l = m + 1;
            else
                r = m - 1;
        }
        return -1;
    }

    long calc(int base, int exponent) {
        if (exponent == 0) return 1;
        if (exponent == 1) return base % MOD;
        long m = calc(base, exponent / 2);
        if (exponent % 2 == 0) return (m * m) % MOD;
        return (base * ((m * m) % MOD)) % MOD;
    }

    long calc(int base, long exponent) {
        if (exponent == 0) return 1;
        if (exponent == 1) return base % MOD;
        long m = calc(base, exponent / 2);
        if (exponent % 2 == 0) return (m * m) % MOD;
        return (base * ((m * m) % MOD)) % MOD;
    }

    long calc(long base, long exponent) {
        if (exponent == 0) return 1;
        if (exponent == 1) return base % MOD;
        long m = calc(base, exponent / 2);
        if (exponent % 2 == 0) return (m * m) % MOD;
        return (base * (m * m % MOD)) % MOD;
    }

    long power(int base, int exponent) {
        if (exponent == 0) return 1;
        long m = power(base, exponent / 2);
        if (exponent % 2 == 0) return m * m;
        return base * m * m;
    }

    void swap(int[] a, int i, int j) {
        a[i] ^= a[j];
        a[j] ^= a[i];
        a[i] ^= a[j];
    }

    void swap(long[] a, int i, int j) {
        long tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }

    static class Pair<K extends Comparable<? super K>, V extends Comparable<? super V>>
            implements Comparable<Pair<K, V>> {
        private K k;
        private V v;

        Pair() {
        }

        Pair(K k, V v) {
            this.k = k;
            this.v = v;
        }

        K getK() {
            return k;
        }

        V getV() {
            return v;
        }

        void setK(K k) {
            this.k = k;
        }

        void setV(V v) {
            this.v = v;
        }

        void setKV(K k, V v) {
            this.k = k;
            this.v = v;
        }

        @SuppressWarnings("unchecked")
        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || !(o instanceof Pair)) return false;
            Pair<K, V> p = (Pair<K, V>) o;
            return k.compareTo(p.k) == 0 && v.compareTo(p.v) == 0;
        }

        @Override
        public int hashCode() {
            int hash = 31;
            hash = hash * 89 + k.hashCode();
            hash = hash * 89 + v.hashCode();
            return hash;
        }

        @Override
        public int compareTo(Pair<K, V> pair) {
            return k.compareTo(pair.k) == 0 ? v.compareTo(pair.v) : k.compareTo(pair.k);
        }

        @Override
        public Pair<K, V> clone() {
            return new Pair<K, V>(this.k, this.v);
        }

        @Override
        public String toString() {
            return String.valueOf(k).concat(" ").concat(String.valueOf(v)).concat("\n");
        }
    }

    static class Reader {
        private BufferedReader br;
        private StringTokenizer st;

        Reader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            try {
                while (st == null || !st.hasMoreTokens()) {
                    st = new StringTokenizer(br.readLine());
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int[] id2(int n) {
            int[] arr = new int[n];
            for (int i = 0; i < n; i++)
                arr[i] = nextInt();
            return arr;
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String s = "";
            try {
                s = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return s;
        }
    }
}