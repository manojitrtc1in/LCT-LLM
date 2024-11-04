import java.util.*;
import java.io.*;

class Main {
    
    static class IO {
        
        static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        static StringTokenizer st;
        
        static String next() throws IOException {
            while (st == null || !st.hasMoreTokens()) {
                st = new StringTokenizer(br.readLine());
            }
            return st.nextToken();
        }
        
        static int nextInt() throws IOException {
            return Integer.parseInt(next());
        }
        
        static long nextLong() throws IOException {
            return Long.parseLong(next());
        }
        
        static double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
        
        static String nextLine() throws IOException {
            return br.readLine();
        }
        
    }
    
    static class Utils {
        
        static class Pair<T1, T2> {
            T1 first;
            T2 second;
            
            Pair(T1 first, T2 second) {
                this.first = first;
                this.second = second;
            }
        }
        
        static class Range implements Iterable<Integer> {
            private final int start;
            private final int stop;
            private final int step;
            
            Range(int start, int stop, int step) {
                this.start = start;
                this.stop = stop;
                this.step = step;
            }
            
            @Override
            public Iterator<Integer> iterator() {
                return new Iterator<Integer>() {
                    private int value = start;
                    
                    @Override
                    public boolean hasNext() {
                        return step > 0 ? value < stop : value > stop;
                    }
                    
                    @Override
                    public Integer next() {
                        int current = value;
                        value += step;
                        return current;
                    }
                };
            }
        }
        
        static Range range(int stop) {
            return new Range(0, stop, 1);
        }
        
        static Range range(int start, int stop) {
            return new Range(start, stop, 1);
        }
        
        static Range range(int start, int stop, int step) {
            return new Range(start, stop, step);
        }
        
        static <T> T max(T... values) {
            T result = values[0];
            for (int i = 1; i < values.length; i++) {
                if (values[i] instanceof Comparable && ((Comparable) values[i]).compareTo(result) > 0) {
                    result = values[i];
                }
            }
            return result;
        }
        
        static <T> T min(T... values) {
            T result = values[0];
            for (int i = 1; i < values.length; i++) {
                if (values[i] instanceof Comparable && ((Comparable) values[i]).compareTo(result) < 0) {
                    result = values[i];
                }
            }
            return result;
        }
        
        static void updmax(int[] a, int b) {
            a[0] = Math.max(a[0], b);
        }
        
        static void updmin(int[] a, int b) {
            a[0] = Math.min(a[0], b);
        }
        
        static boolean chkmax(int[] a, int b) {
            if (a[0] < b) {
                a[0] = b;
                return true;
            }
            return false;
        }
        
        static boolean chkmin(int[] a, int b) {
            if (a[0] > b) {
                a[0] = b;
                return true;
            }
            return false;
        }
        
        static long operator_E(long n) {
            long p = 1;
            long a = 10;
            for (int i = 0; i < n; i++) {
                p *= a;
            }
            return p;
        }
        
        static double operator_deg(double deg) {
            double PI = Math.acos(-1);
            return deg * PI / 180;
        }
        
        static Random rd = new Random();
        
        static int rand(int l, int r) {
            return rd.nextInt(r - l + 1) + l;
        }
        
        static class Color {
            static final String HEADER = "\033[95m";
            static final String OKBLUE = "\033[94m";
            static final String OKGREEN = "\033[92m";
            static final String WARNING = "\033[93m";
            static final String FAIL = "\033[91m";
            static final String ENDC = "\033[0m";
            static final String BOLD = "\033[1m";
            static final String UNDERLINE = "\033[4m";
            static final String BGGREEN = "\u001B[6;30;42m";
        }
        
        static class DTime {
            int h, m, s;
            
            DTime(int h, int m, int s) {
                this.h = h;
                this.m = m;
                this.s = s;
            }
            
            DTime() {
                this.h = ((int) (System.currentTimeMillis() / 1000 / 60 / 60) % 24 + 5) % 24;
                this.m = (int) (System.currentTimeMillis() / 1000 / 60) % 60;
                this.s = (int) (System.currentTimeMillis() / 1000) % 60;
            }
            
            boolean lessThan(DTime t2) {
                if (this.h == t2.h) {
                    if (this.m == t2.m) {
                        return this.s < t2.s;
                    }
                    return this.m < t2.m;
                }
                return this.h < t2.h;
            }
            
            @Override
            public String toString() {
                return this.h + " " + this.m + " " + this.s + "\n";
            }
            
            @Override
            public String toString() {
                return this.h + ":" + this.m + ":" + this.s;
            }
        }
        
        static DTime getCurrentTime() {
            return new DTime();
        }
        
    }
    
    static class NPArray<T> {
        
        private T[] data;
        private T[] max;
        private T[] min;
        private T[] sum;
        private int size;
        
        NPArray(int size) {
            this.size = size;
            this.data = (T[]) new Object[size];
            fill(0);
        }
        
        T sum() {
            return Arrays.stream(data).reduce(0, Integer::sum);
        }
        
        T sum(int stop) {
            return sum(0, stop);
        }
        
        T sum(int start, int stop) {
            if (sum == null) {
                sum = new T[size];
                sum[0] = data[0];
                for (int i = 1; i < size; i++) {
                    sum[i] = sum[i - 1] + data[i];
                }
            }
            T sum_ = sum[stop];
            if (start > 0) {
                sum_ -= sum[start - 1];
            }
            return sum_;
        }
        
        T sum(int start, int stop, int step) {
            T sum_ = 0;
            for (int i = start; i < stop; i += step) {
                sum_ += data[i];
            }
            return sum_;
        }
        
        T max() {
            return Arrays.stream(data).max().orElse(null);
        }
        
        T max(int index) {
            if (max == null) {
                max = new T[size];
                max[0] = data[0];
                for (int i = 1; i < size; i++) {
                    max[i] = data[i] > max[i - 1] ? data[i] : max[i - 1];
                }
            }
            return max[index];
        }
        
        T min() {
            return Arrays.stream(data).min().orElse(null);
        }
        
        T min(int index) {
            if (min == null) {
                min = new T[size];
                min[0] = data[0];
                for (int i = 1; i < size; i++) {
                    min[i] = data[i] < min[i - 1] ? data[i] : min[i - 1];
                }
            }
            return min[index];
        }
        
        void fill(int value) {
            Arrays.fill(data, value);
        }
        
        void reverse() {
            Collections.reverse(Arrays.asList(data));
            if (sum != null) {
                Collections.reverse(Arrays.asList(sum));
            }
            if (max != null) {
                Collections.reverse(Arrays.asList(max));
            }
            if (min != null) {
                Collections.reverse(Arrays.asList(min));
            }
        }
        
        void sort() {
            Arrays.sort(data);
            if (sum != null) {
                sum = null;
            }
            if (max != null) {
                max = null;
            }
            if (min != null) {
                min = null;
            }
        }
        
        void shift(int count) {
            count %= size;
            T[] temp = (T[]) new Object[size];
            int j = count < 0 ? size + count : count;
            for (int i = 0; i < size; i++, j++) {
                if (j == size) {
                    j = 0;
                }
                temp[j] = data[i];
            }
            System.arraycopy(temp, 0, data, 0, size);
        }
        
        void randomShuffle() {
            List<T> list = Arrays.asList(data);
            Collections.shuffle(list);
            list.toArray(data);
        }
        
        boolean isSorted() {
            for (int i = 1; i < size; i++) {
                if (data[i - 1] > data[i + 1]) {
                    return false;
                }
            }
            return true;
        }
        
        void resize(int size) {
            this.size = size;
            this.data = (T[]) new Object[size];
            fill(0);
        }
        
        T get(int index) {
            return data[index];
        }
        
        void set(int index, T value) {
            data[index] = value;
        }
        
        int size() {
            return size;
        }
        
        boolean isEmpty() {
            return size == 0;
        }
        
        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < size; i++) {
                if (i > 0) {
                    sb.append(" ");
                }
                sb.append(data[i]);
            }
            return sb.toString();
        }
        
    }
    
    static final int MOD = 1_000_000_007;
    static final double EPS = 1e-9;
    static final double PI = Math.acos(-1);
    static final long LLINF = 18_E + 10;
    static final int INF = 9_E + 10;
    static final int MAXN = 6_E + 6;
    static final int N = 5_E + 5;
    
    static int[] cnt = new int[MAXN];
    static int[] l = new int[MAXN];
    static int[] r = new int[MAXN];
    
    static class Fenwick {
        
        int[] fw;
        
        Fenwick(int n) {
            fw = new int[n + 1];
        }
        
        void update(int i, int d) {
            while (i < fw.length) {
                Utils.updmax(fw, d);
                i |= (i + 1);
            }
        }
        
        int get(int n) {
            int result = 0;
            while (n >= 0) {
                Utils.updmax(result, fw[n]);
                n = (n & (n + 1)) - 1;
            }
            return result;
        }
        
        int get(int l, int r) {
            return get(r) - get(l - 1);
        }
        
    }
    
    static void solution() throws IOException {
        int n = IO.nextInt();
        int m = IO.nextInt();
        
        for (int i = 1; i <= n; i++) {
            int l = IO.nextInt();
            int r = IO.nextInt();
            cnt[l]++;
            cnt[r + 1]--;
        }
        
        for (int i = 1; i <= m; i++) {
            cnt[i] += cnt[i - 1];
        }
        
        Fenwick fw_l = new Fenwick(100_001);
        for (int i = 1; i <= m; i++) {
            l[i] = fw_l.get(cnt[i]) + 1;
            fw_l.update(cnt[i], l[i]);
        }
        
        Fenwick fw_r = new Fenwick(100_001);
        for (int i = m; i >= 1; i--) {
            r[i] = fw_r.get(cnt[i]) + 1;
            fw_r.update(cnt[i], r[i]);
        }
        
        int ans = 0;
        for (int i = 1; i <= m; i++) {
            Utils.updmax(ans, l[i] + r[i] - 1);
        }
        
        System.out.println(ans);
    }
    
    public static void main(String[] args) throws IOException {
        int queries = 1;
        
        for (int test_case : Utils.range(1, queries + 1)) {
            solution();
        }
    }
    
}
