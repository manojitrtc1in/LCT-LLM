import java.io.*;
import java.util.*;
import java.util.function.BiFunction;
import java.util.function.Function;

public class Main {

    static BiFunction<Integer, Integer, Integer> ADD = (x, y) -> (x + y);
    static BiFunction<ArrayList<Integer>, ArrayList<Integer>, ArrayList<Integer>> ADD_ARRAY_LIST = (x, y) -> {
        x.addAll(y);
        return x;
    };

    static Function<Pair<Integer, Integer>, Integer> GET_FIRST = (x) -> (x.first);
    static Function<Pair<Integer, Integer>, Integer> GET_SECOND = (x) -> (x.second);
    static Comparator<Pair<Integer, Integer>> C = Comparator.comparing(x -> x.first + x.second);
    static long MOD = 1_000_000_000 + 7;
    static Map<Integer, Set<Pair<Integer, Integer>>> config = getValid();

    public static void main(String[] args) throws Exception {
        long startTime = System.nanoTime();
        

        int t = in.nextInt();
        while (t-- > 0) {
            solve();
        }
        long endTime = System.nanoTime();
        err.println("Execution Time : +" + (endTime - startTime) / 1000000 + " ms");
        exit(0);
    }

    static void solveBKP() {
        int n = in.nextInt();
        char[] num = (n + "").toCharArray();
        Map<Pair<Integer, Integer>, HashSet<Pair<Integer, Integer>>> adj = new HashMap<>();
        int temp = n;
        int index = 0;
        while (temp > 0) {
            int cur = Character.getNumericValue(num[n - 1]);

        }
    }

    static void solve2() {
        int n = in.nextInt();
        int temp = n;
        int cur = temp % 10;
        ArrayList<Pair<Integer, Integer>> current = new ArrayList<>();
        ArrayList<Pair<Integer, Integer>> prev = new ArrayList<>(config.get(cur));
        temp /= 10;
        int index = 1;
        int mul = 10;
        while (temp > 0) {
            for (Pair<Integer, Integer> p : prev) {
                int num = add(p.first, p.second);
                cur = temp % 10 - get(num, index);
                

                if (cur < 0) {
                    cur += 10;
                }
                for (Pair<Integer, Integer> x : config.get(cur)) {
                    Pair<Integer, Integer> tt = make_pair(p.first + x.first * mul, p.second + x.second * mul);
                    int next = add(tt.first, tt.second);
                    if (next > n || next < 0) {
                        continue;
                    }
                    current.add(tt);
                }
            }
            index++;
            temp /= 10;
            prev = current;
            current = new ArrayList<>();
            mul *= 10;
        }
        long ans = 0;
        for (Pair<Integer, Integer> p : prev) {
            if (add(p.first, p.second) == n) {
                int count = 0;
                long t1 = p.first;
                long t2 = p.second;
                while (t1 > 0 || t2 > 0) {
                    if (t1 % 10 != t2 % 10) {
                        count++;
                    }
                    t1 /= 10;
                    t2 /= 10;
                }
                ans += (1L << (count));
            }
        }
        ans -= 2;
        out.println(ans);
    }


    static void solve() {
        String s = in.next();
        StringBuilder s1 = new StringBuilder();
        StringBuilder s2 = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            if (i % 2 == 0) {
                s1.append(s.charAt(i));
            } else {
                s2.append(s.charAt(i));
            }
        }
        int a = get(s1.toString()) + 1;
        int b = get(s2.toString()) + 1;
        out.println(a * b - 2);
    }

    static int get(String s){
        if(s.isEmpty()){
            return 0;
        }
        return Integer.parseInt(s);
    }

    static int get(int n, int index) {
        while (index > 0 && n > 0) {
            n /= 10;
            index--;
        }
        return n % 10;
    }














































































































































    static int count(int a) {
        int count = 0;
        for (int i = 1; i <= a; i++) {
            for (int j = 1; j <= a; j++) {
                if (add(i, j) == a) {
                    out.println(i + " " + j);
                    count++;
                }
            }
        }
        out.println(count);
        return count;
    }

    static int add(int a, int b) {
        int sum = 0;
        int[] carry = new int[15];
        int ind = 0;
        int mul = 1;
        int count = 3;
        while (count > 0) {
            int i = (a % 10 + b % 10) + carry[ind];
            sum = sum + (i % 10) * mul;
            carry[ind + 2] = i / 10;
            a /= 10;
            b /= 10;
            ind++;
            mul *= 10;
            if (Math.max(a, b) == 0) {
                count--;
            }
        }
        return sum;
    }

    static int[][] copy(int[][] t) {
        int[][] t1 = new int[3][12];
        for (int i = 0; i < 3; i++) {
            t1[i] = Arrays.copyOf(t[i], 12);
        }
        return t1;
    }


















































    static Map<Integer, Set<Pair<Integer, Integer>>> getValid() {
        Map<Integer, Set<Pair<Integer, Integer>>> config = new HashMap<>();
        for (int i = 0; i <= 9; i++) {
            for (int j = i; j <= 9; j++) {
                int v = (i + j) % 10;
                Set<Pair<Integer, Integer>> cur = config.getOrDefault(v, new HashSet<>());
                cur.add(make_pair(i, j));
                config.put(v, cur);
            }
        }
        return config;
    }

    static void debug(Object... args) {
        for (Object a : args) {
            out.println(a);
        }
    }

    static int dist(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        return Math.abs(a.first - b.first) + Math.abs(a.second - b.second);
    }

    static void y() {
        out.println("YES");
    }

    static void n() {
        out.println("NO");
    }

    static int[] stringToArray(String s) {
        return s.chars().map(x -> Character.getNumericValue(x)).toArray();
    }

    static <T> T min(T a, T b, Comparator<T> C) {
        if (C.compare(a, b) <= 0) {
            return a;
        }
        return b;
    }

    static <T> T max(T a, T b, Comparator<T> C) {
        if (C.compare(a, b) >= 0) {
            return a;
        }
        return b;
    }

    static void fail() {
        out.println("-1");
    }

    static class Pair<T, R> {
        public T first;
        public R second;

        public Pair(T first, R second) {
            this.first = first;
            this.second = second;
        }

        @Override
        public boolean equals(final Object o) {
            if (this == o) {
                return true;
            }
            if (o == null || getClass() != o.getClass()) {
                return false;
            }
            final Pair<?, ?> pair = (Pair<?, ?>) o;
            return Objects.equals(first, pair.first) && Objects.equals(second, pair.second);
        }

        @Override
        public int hashCode() {
            return Objects.hash(first, second);
        }

        @Override
        public String toString() {
            return "Pair{" + "a=" + first + ", b=" + second + '}';
        }

        public T getFirst() {
            return first;
        }

        public R getSecond() {
            return second;
        }
    }

    static <T, R> Pair<T, R> make_pair(T a, R b) {
        return new Pair<>(a, b);
    }

    static long mod_inverse(long a, long m) {
        Number x = new Number(0);
        Number y = new Number(0);
        extended_gcd(a, m, x, y);
        return (m + x.v % m) % m;
    }

    static long extended_gcd(long a, long b, Number x, Number y) {
        long d = a;
        if (b != 0) {
            d = extended_gcd(b, a % b, y, x);
            y.v -= (a / b) * x.v;
        } else {
            x.v = 1;
            y.v = 0;
        }
        return d;
    }

    static class Number {
        long v = 0;

        public Number(long v) {
            this.v = v;
        }
    }

    static long lcm(long a, long b, long c) {
        return lcm(a, lcm(b, c));
    }

    static long lcm(long a, long b) {
        long p = 1L * a * b;
        return p / gcd(a, b);
    }

    static long gcd(long a, long b) {
        while (b != 0) {
            long t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    static long gcd(long a, long b, long c) {
        return gcd(a, gcd(b, c));
    }

    static class ArrayUtils {

        static void swap(int[] a, int i, int j) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }

        static void swap(char[] a, int i, int j) {
            char temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }

        static void print(char[] a) {
            for (char c : a) {
                out.print(c);
            }
            out.println("");
        }

        static int[] reverse(int[] data) {
            int[] p = new int[data.length];
            for (int i = 0, j = data.length - 1; i < data.length; i++, j--) {
                p[i] = data[j];
            }
            return p;
        }

        static void prefixSum(long[] data) {
            for (int i = 1; i < data.length; i++) {
                data[i] += data[i - 1];
            }
        }

        static void prefixSum(int[] data) {
            for (int i = 1; i < data.length; i++) {
                data[i] += data[i - 1];
            }
        }

        static long[] reverse(long[] data) {
            long[] p = new long[data.length];
            for (int i = 0, j = data.length - 1; i < data.length; i++, j--) {
                p[i] = data[j];
            }
            return p;
        }

        static char[] reverse(char[] data) {
            char[] p = new char[data.length];
            for (int i = 0, j = data.length - 1; i < data.length; i++, j--) {
                p[i] = data[j];
            }
            return p;
        }

        static int[] MergeSort(int[] A) {
            if (A.length > 1) {
                int q = A.length / 2;
                int[] left = new int[q];
                int[] right = new int[A.length - q];
                System.arraycopy(A, 0, left, 0, q);
                System.arraycopy(A, q, right, 0, A.length - q);
                int[] left_sorted = MergeSort(left);
                int[] right_sorted = MergeSort(right);
                return Merge(left_sorted, right_sorted);
            } else {
                return A;
            }
        }

        static int[] Merge(int[] left, int[] right) {
            int[] A = new int[left.length + right.length];
            int i = 0;
            int j = 0;
            for (int k = 0; k < A.length; k++) {
                

                if (i == left.length && j < right.length) {
                    A[k] = right[j];
                    j++;
                    continue;
                }
                

                if (j == right.length && i < left.length) {
                    A[k] = left[i];
                    i++;
                    continue;
                }
                if (left[i] <= right[j]) {
                    A[k] = left[i];
                    i++;
                } else {
                    A[k] = right[j];
                    j++;
                }
            }
            return A;
        }

        static long[] MergeSort(long[] A) {
            if (A.length > 1) {
                int q = A.length / 2;
                long[] left = new long[q];
                long[] right = new long[A.length - q];
                System.arraycopy(A, 0, left, 0, q);
                System.arraycopy(A, q, right, 0, A.length - q);
                long[] left_sorted = MergeSort(left);
                long[] right_sorted = MergeSort(right);
                return Merge(left_sorted, right_sorted);
            } else {
                return A;
            }
        }

        static long[] Merge(long[] left, long[] right) {
            long[] A = new long[left.length + right.length];
            int i = 0;
            int j = 0;
            for (int k = 0; k < A.length; k++) {
                

                if (i == left.length && j < right.length) {
                    A[k] = right[j];
                    j++;
                    continue;
                }
                

                if (j == right.length && i < left.length) {
                    A[k] = left[i];
                    i++;
                    continue;
                }
                if (left[i] <= right[j]) {
                    A[k] = left[i];
                    i++;
                } else {
                    A[k] = right[j];
                    j++;
                }
            }
            return A;
        }

        static int upper_bound(int[] data, int num, int start) {
            int low = start;
            int high = data.length - 1;
            int mid = 0;
            int ans = -1;
            while (low <= high) {
                mid = (low + high) / 2;
                if (data[mid] < num) {
                    low = mid + 1;
                } else if (data[mid] >= num) {
                    high = mid - 1;
                    ans = mid;
                }
            }
            if (ans == -1) {
                return 100000000;
            }
            return data[ans];
        }

        static int lower_bound(int[] data, int num, int start) {
            int low = start;
            int high = data.length - 1;
            int mid = 0;
            int ans = -1;
            while (low <= high) {
                mid = (low + high) / 2;
                if (data[mid] <= num) {
                    low = mid + 1;
                    ans = mid;
                } else if (data[mid] > num) {
                    high = mid - 1;
                }
            }
            if (ans == -1) {
                return 100000000;
            }
            return data[ans];
        }
    }

    static boolean[] primeSieve(int n) {
        boolean[] primes = new boolean[n + 1];
        Arrays.fill(primes, true);
        primes[0] = false;
        primes[1] = false;
        for (int i = 2; i <= Math.sqrt(n); i++) {
            if (primes[i]) {
                for (int j = i * i; j <= n; j += i) {
                    primes[j] = false;
                }
            }
        }
        return primes;
    }

    

    static HashMap<Integer, Boolean> subsets_sum_iter(int[] data) {
        HashMap<Integer, Boolean> temp = new HashMap<Integer, Boolean>();
        temp.put(data[0], true);
        for (int i = 1; i < data.length; i++) {
            HashMap<Integer, Boolean> t1 = new HashMap<Integer, Boolean>(temp);
            t1.put(data[i], true);
            for (int j : temp.keySet()) {
                t1.put(j + data[i], true);
            }
            temp = t1;
        }
        return temp;
    }

    static HashMap<Integer, Integer> subsets_sum_count(int[] data) {
        HashMap<Integer, Integer> temp = new HashMap<>();
        temp.put(data[0], 1);
        for (int i = 1; i < data.length; i++) {
            HashMap<Integer, Integer> t1 = new HashMap<>(temp);
            t1.merge(data[i], 1, ADD);
            for (int j : temp.keySet()) {
                t1.merge(j + data[i], temp.get(j) + 1, ADD);
            }
            temp = t1;
        }
        return temp;
    }

    static class Graph {
        ArrayList<Integer>[] g;

        boolean[] visited;

        ArrayList<Integer>[] graph(int n) {
            g = new ArrayList[n];
            visited = new boolean[n];
            for (int i = 0; i < n; i++) {
                g[i] = new ArrayList<>();
            }
            return g;
        }

        void BFS(int s) {
            Queue<Integer> Q = new ArrayDeque<>();
            visited[s] = true;
            Q.add(s);
            while (!Q.isEmpty()) {
                int v = Q.poll();
                for (int a : g[v]) {
                    if (!visited[a]) {
                        visited[a] = true;
                        Q.add(a);
                    }
                }
            }
        }
    }

    static class SparseTable {
        int[] log;
        int[][] st;

        public SparseTable(int n, int k, int[] data, BiFunction<Integer, Integer, Integer> f) {
            log = new int[n + 1];
            st = new int[n][k + 1];
            log[1] = 0;
            for (int i = 2; i <= n; i++) {
                log[i] = log[i / 2] + 1;
            }
            for (int i = 0; i < data.length; i++) {
                st[i][0] = data[i];
            }
            for (int j = 1; j <= k; j++)
                for (int i = 0; i + (1 << j) <= data.length; i++)
                    st[i][j] = f.apply(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }

        public int query(int L, int R, BiFunction<Integer, Integer, Integer> f) {
            int j = log[R - L + 1];
            return f.apply(st[L][j], st[R - (1 << j) + 1][j]);
        }
    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 2048);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public int[] readAllInts(int n) {
            int[] p = new int[n];
            for (int i = 0; i < n; i++) {
                p[i] = in.nextInt();
            }
            return p;
        }

        public int[] readAllInts(int n, int s) {
            int[] p = new int[n + s];
            for (int i = s; i < n + s; i++) {
                p[i] = in.nextInt();
            }
            return p;
        }

        public long[] readAllLongs(int n) {
            long[] p = new long[n];
            for (int i = 0; i < n; i++) {
                p[i] = in.nextLong();
            }
            return p;
        }

        public long[] readAllLongs(int n, int s) {
            long[] p = new long[n + s];
            for (int i = s; i < n + s; i++) {
                p[i] = in.nextLong();
            }
            return p;
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    static void exit(int a) {
        out.close();
        err.close();
        System.exit(a);
    }

    static InputStream inputStream = System.in;
    static OutputStream outputStream = System.out;
    static OutputStream errStream = System.err;
    static InputReader in = new InputReader(inputStream);
    static PrintWriter out = new PrintWriter(outputStream);
    static PrintWriter err = new PrintWriter(errStream);
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

}