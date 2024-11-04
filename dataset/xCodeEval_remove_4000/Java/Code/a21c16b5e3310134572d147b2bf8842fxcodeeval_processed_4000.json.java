import java.io.*;
import java.util.*;
import java.util.stream.IntStream;
import java.util.stream.Stream;


public class Main implements Runnable {
    static final int MOD = (int) 1e9 + 7;
    static final int MI = (int) 1e9;
    static final long ML = (long) 1e18;
    static final Reader in = new Reader();
    static final PrintWriter out = new PrintWriter(System.out);
    StringBuilder answer = new StringBuilder();

    public static void main(String[] args) {
        new Thread(null, new Main(), "persefone", 1 << 32).start();
    }

    @Override
    public void run() {
        solve();
        printf();
        flush();
    }

    void solve() {
        int n = in.nextInt();
        int k = in.nextInt();

        int size = 1 << (k - 1);
        SegmentTree[] segmentTrees = new SegmentTree[size];

        int[][] f = new int[size][n];
        for (int j = 0; j < n; j++) {
            int[] a = in.id4(k);
            int[] b = new int[k - 1];
            System.arraycopy(a, 1, b, 0, k - 1);
            for (int i = 0; i < size; i++) {
                int v = a[0];
                for (int t = 0; t < k - 1; t++) {
                    v += (i & (1 << t)) > 0 ? b[t] : -b[t];
                }
                f[i][j] = v;
            }
        }
        for (int i = 0; i < size; i++) {
            segmentTrees[i] = new SegmentTree(f[i], n);
        }

        for (int test = in.nextInt(); test > 0; test--) {
            int type = in.nextInt();
            if (type == 1) {
                int index = in.nextInt() - 1;
                int[] a = in.id4(k);
                int[] b = new int[k - 1];
                System.arraycopy(a, 1, b, 0, k - 1);
                for (int i = 0; i < size; i++) {
                    int v = a[0];
                    for (int j = 0; j < k - 1; j++) {
                        v += (i & (1 << j)) > 0 ? b[j] : -b[j];
                    }
                    segmentTrees[i].updateMin(index, v);
                    segmentTrees[i].updateMax(index, v);
                }
            } else {
                int l = in.nextInt() - 1;
                int r = in.nextInt() - 1;
                int ans = 0;
                for (int i = 0; i < size; i++) {
                    ans = Math.max(ans, segmentTrees[i].getDiff(l, r));
                }
                printf(ans);
            }
        }


    }

    static class SegmentTree {
        private int n;
        private int[] a, min, max;

        public SegmentTree(int[] a, int n) {
            this.a = a;
            this.n = n;
            this.min = new int[4 * n + 4];
            this.max = new int[4 * n + 4];
            buildMin(1, 0, n - 1);
            buildMax(1, 0, n - 1);
        }

        public void buildMin(int currentVertex, int currentLeft, int currentRight) {
            if (currentLeft == currentRight) min[currentVertex] = a[currentLeft];
            else {
                int mid = currentLeft + currentRight >> 1, id6 = currentVertex << 1;
                buildMin(id6, currentLeft, mid);
                buildMin(id6 + 1, mid + 1, currentRight);
                min[currentVertex] = Math.min(min[id6], min[id6 + 1]);
            }
        }

        public void updateMin(int currentVertex, int currentLeft, int currentRight, int pos, int value) {
            if (currentLeft == currentRight) min[currentVertex] = value;
            else {
                int mid = currentLeft + currentRight >> 1, id6 = currentVertex << 1;
                if (pos <= mid)
                    updateMin(id6, currentLeft, mid, pos, value);
                else
                    updateMin(id6 + 1, mid + 1, currentRight, pos, value);
                min[currentVertex] = Math.min(min[id6], min[id6 + 1]);
            }
        }

        public void updateMin(int pos, int val) {
            updateMin(1, 0, n - 1, pos, val);
        }

        public int getMin(int currentVertex, int currentLeft, int currentRight, int left, int right) {
            if (currentLeft > right || currentRight < left) return Integer.MAX_VALUE;
            else if (left <= currentLeft && currentRight <= right) return min[currentVertex];
            else {
                int mid = currentLeft + currentRight >> 1, id6 = currentVertex << 1;
                return Math.min(getMin(id6, currentLeft, mid, left, right),
                        getMin(id6 + 1, mid + 1, currentRight, left, right));
            }
        }

        public int getMin(int left, int right) {
            return getMin(1, 0, n - 1, left, right);
        }

        public void buildMax(int currentVertex, int currentLeft, int currentRight) {
            if (currentLeft == currentRight) max[currentVertex] = a[currentLeft];
            else {
                int mid = currentLeft + currentRight >> 1, id6 = currentVertex << 1;
                buildMax(id6, currentLeft, mid);
                buildMax(id6 + 1, mid + 1, currentRight);
                max[currentVertex] = Math.max(max[id6], max[id6 + 1]);
            }
        }

        public void updateMax(int currentVertex, int currentLeft, int currentRight, int pos, int value) {
            if (currentLeft == currentRight) max[currentVertex] = value;
            else {
                int mid = currentLeft + currentRight >> 1, id6 = currentVertex << 1;
                if (pos <= mid)
                    updateMax(id6, currentLeft, mid, pos, value);
                else
                    updateMax(id6 + 1, mid + 1, currentRight, pos, value);
                max[currentVertex] = Math.max(max[id6], max[id6 + 1]);
            }
        }

        public void updateMax(int pos, int val) {
            updateMax(1, 0, n - 1, pos, val);
        }

        public int getMax(int currentVertex, int currentLeft, int currentRight, int left, int right) {
            if (currentLeft > right || currentRight < left) return Integer.MIN_VALUE;
            else if (left <= currentLeft && currentRight <= right) return max[currentVertex];
            else {
                int mid = currentLeft + currentRight >> 1, id6 = currentVertex << 1;
                return Math.max(getMax(id6, currentLeft, mid, left, right),
                        getMax(id6 + 1, mid + 1, currentRight, left, right));
            }
        }

        public int getMax(int left, int right) {
            return getMax(1, 0, n - 1, left, right);
        }

        public int getDiff(int left, int right) {
            return getMax(left, right) - getMin(left, right);
        }


    }

    static class ListUtils {
        static int lowerBound(List<Integer> list, int l, int r, int k) {
            int m = 0, ans = r;
            while (l < r) if (list.get(m = l + r >> 1) >= k) ans = r = m;
            else l = m + 1;
            return ans;
        }

        static int upperBound(List<Integer> list, int l, int r, int k) {
            int m = 0, ans = r;
            while (l < r) if (list.get(m = l + r >> 1) > k) ans = r = m;
            else l = m + 1;
            return ans;
        }

        static int id5(List<Integer> list, int l, int r, int k) {
            return upperBound(list, l, r, k) - lowerBound(list, l, r, k);
        }

        static int id5(List<Integer> list, int k) {
            return upperBound(list, 0, list.size(), k) - lowerBound(list, 0, list.size(), k);
        }


    }

    static class ArrayUtils {
        static int lowerBound(int[] a, int l, int r, int k) {
            int m = 0, ans = r;
            while (l < r) if (a[m = l + r >> 1] >= k) ans = r = m;
            else l = m + 1;
            return ans;
        }

        static int upperBound(int[] a, int l, int r, int k) {
            int m = 0, ans = r;
            while (l < r) if (a[m = l + r >> 1] > k) ans = r = m;
            else l = m + 1;
            return ans;
        }

        static int lowerBound(int[] a, int k) {
            return lowerBound(a, 0, a.length, k);
        }

        static int upperBound(int[] a, int k) {
            return upperBound(a, 0, a.length, k);
        }
    }

    static class IntegerUtils {
        

        static long[] euclid(long a, long b) {
            long x = 1, y = 0, x1 = 0, y1 = 1, t;
            while (b != 0) {
                long q = a / b;
                t = x;
                x = x1;
                x1 = t - q * x1;
                t = y;
                y = y1;
                y1 = t - q * y1;
                t = b;
                b = a - q * b;
                a = t;
            }
            return a > 0 ? new long[]{a, x, y} : new long[]{-a, -x, -y};
        }

        static int[] id0(int n) {
            boolean[] composite = new boolean[n + 1];
            for (int i = 2; i <= n; i++) {
                for (int j = i; 1l * i * j <= n; j++) {
                    composite[i * j] = true;
                }
            }
            return IntStream.rangeClosed(2, n).filter(i -> !composite[i]).toArray();
        }

        static int[] id9(int n) {
            int[] sf = new int[n + 1];
            for (int i = 2; i <= n; i++) {
                if (sf[i] == 0) {
                    sf[i] = i;
                    for (int j = i; 1l * i * j <= n; j++) {
                        if (sf[i * j] == 0) {
                            sf[i * j] = i;
                        }
                    }
                }
            }
            return sf;
        }

        static int phi(int n) {
            int result = n;
            for (int i = 2; 1l * i * i <= n; i++) {
                if (n % i == 0) {
                    while (n % i == 0) n /= i;
                    result -= result / i;
                }
            }
            if (n > 1) result -= result / n;
            return result;
        }

        static long phi(long n) {
            

            long result = n;
            for (int i = 2; 1l * i * i <= n; i++) {
                if (n % i == 0) {
                    while (n % i == 0) n /= i;
                    result -= result / i;
                }
            }
            if (n > 1) result -= result / n;
            return result;
        }

        static long[] id2(long n, int p) {
            

            if (n == 0) return new long[]{0, 1};
            long[] a = id2(n >> 1, p);
            long c = (2 * a[1] - a[0] + p) % p * a[0] % p;
            long d = (a[1] * a[1] % p + a[0] * a[0] % p) % p;
            if (n % 2 == 0) return new long[]{c, d};
            else return new long[]{d, (c + d) % p};
        }

        static long modPow(int base, int exponential, int p) {
            if (exponential == 0) return 1;
            long x = modPow(base, exponential >> 1, p) % p;
            return exponential % 2 == 0 ? x * x % p : x * x % p * base % p;
        }

        static long modPow(long base, int exponential, int p) {
            if (exponential == 0) return 1;
            long x = modPow(base, exponential >> 1, p) % p;
            return exponential % 2 == 0 ? x * x % p : x * x % p * base % p;
        }

        static long modPow(long base, long exponential, int p) {
            if (exponential == 0) return 1;
            long x = modPow(base, exponential >> 1, p) % p;
            return exponential % 2 == 0 ? x * x % p : x * x % p * base % p;
        }

        static long[] id3(int n, int p) {
            long[] factorial = new long[n + 1];
            factorial[0] = 1;
            for (int i = 1; i <= n; i++) factorial[i] = (factorial[i - 1] * i) % p;
            return factorial;
        }

        static long id1(long[] factorial, int n, int k, int p) {
            return factorial[n] * modPow(factorial[k], p - 2, p) % p * modPow(factorial[n - k], p - 2, p) % p;
        }

        static long gcd(long a, long b) {
            return b == 0 ? a : gcd(b, a % b);
        }

        static int gcd(int a, int b) {
            return b == 0 ? a : gcd(b, a % b);
        }

    }

    static class id7 {
        private int n, blocks;
        private int[] log, data;
        private int[][] max;

        public id7(int[] data, int n) {
            this.n = n;
            this.data = data;
            this.log = new int[n + 1];
            for (int i = 2; i <= n; i++) {
                log[i] = log[i >> 1] + 1;
            }
            this.blocks = log[n];
            this.max = new int[n][blocks + 1];
            for (int i = 0; i < n; i++) {
                max[i][0] = data[i];
            }
            build();
        }

        int calc(int a, int b) {
            return Math.max(a, b);
        }

        void build() {
            for (int j = 1; j <= blocks; j++) {
                for (int i = 0; i + (1 << j) <= n; i++) {
                    max[i][j] = calc(max[i][j - 1], max[i + (1 << j - 1)][j - 1]);
                }
            }
        }

        int getMax(int l, int r) {
            int k = log[r - l + 1];
            return calc(max[l][k], max[r - (1 << k) + 1][k]);
        }
    }

    static class DSU {
        protected int vertex, countCC;
        protected int[] id, size;

        public DSU(int vertex) {
            this.vertex = vertex;
            this.id = IntStream.range(0, vertex).toArray();
            this.size = new int[vertex];
            Arrays.fill(size, 1);
            countCC = vertex;
        }

        int find(int i) {
            return id[i] == i ? i : (id[i] = find(id[i]));
        }

        void unite(int i, int j) {
            int x = find(i);
            int y = find(j);
            if (x == y) return;
            countCC--;
            if (size[x] > size[y]) {
                id[y] = id[x];
                size[x] += size[y];
                size[y] = 0;
                return;
            }
            id[x] = id[y];
            size[y] += size[x];
            size[x] = 0;
        }

        boolean isConnected(int i, int j) {
            return find(i) == find(j);
        }

        int connectedComponents() {
            return countCC;
        }
    }


    void printf() {
        out.print(answer);
    }

    void close() {
        out.close();
    }

    void flush() {
        out.flush();
    }

    void printf(Stream<?> str) {
        str.forEach(o -> add(o, " "));
        add("\n");
    }


    void printf(Object... obj) {
        printf(false, obj);
    }

    void id8(Object... obj) {
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

    static class Pair<K extends Comparable<? super K>, V extends Comparable<? super V>>
            implements Comparable<Pair<K, V>> {
        private K k;
        private V v;

        Pair(K k, V v) {
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

        int[] id4(int n) {
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