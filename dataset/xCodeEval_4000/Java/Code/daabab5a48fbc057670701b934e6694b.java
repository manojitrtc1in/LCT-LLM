import javax.rmi.ssl.SslRMIClientSocketFactory;
import java.io.*;
import java.util.*;

public class Codeforces {

    public static class FastWriter {
        private static final int BUF_SIZE = 1 << 13;
        private final byte[] buf = new byte[BUF_SIZE];
        private final OutputStream out;
        private int ptr = 0;

        private FastWriter() {
            out = null;
        }

        public FastWriter(OutputStream os) {
            this.out = os;
        }

        public FastWriter(String path) {
            try {
                this.out = new FileOutputStream(path);
            } catch (FileNotFoundException e) {
                throw new RuntimeException("FastWriter");
            }
        }

        public FastWriter write(byte b) {
            buf[ptr++] = b;
            if (ptr == BUF_SIZE) innerflush();
            return this;
        }

        public FastWriter write(char c) {
            return write((byte) c);
        }

        public FastWriter write(char[] s) {
            for (char c : s) {
                buf[ptr++] = (byte) c;
                if (ptr == BUF_SIZE) innerflush();
            }
            return this;
        }

        public FastWriter write(String s) {
            s.chars().forEach(c -> {
                buf[ptr++] = (byte) c;
                if (ptr == BUF_SIZE) innerflush();
            });
            return this;
        }

        private static int countDigits(int l) {
            if (l >= 1000000000) return 10;
            if (l >= 100000000) return 9;
            if (l >= 10000000) return 8;
            if (l >= 1000000) return 7;
            if (l >= 100000) return 6;
            if (l >= 10000) return 5;
            if (l >= 1000) return 4;
            if (l >= 100) return 3;
            if (l >= 10) return 2;
            return 1;
        }

        public FastWriter write(int x) {
            if (x == Integer.MIN_VALUE) {
                return write((long) x);
            }
            if (ptr + 12 >= BUF_SIZE) innerflush();
            if (x < 0) {
                write((byte) '-');
                x = -x;
            }
            int d = countDigits(x);
            for (int i = ptr + d - 1; i >= ptr; i--) {
                buf[i] = (byte) ('0' + x % 10);
                x /= 10;
            }
            ptr += d;
            return this;
        }

        private static int countDigits(long l) {
            if (l >= 1000000000000000000L) return 19;
            if (l >= 100000000000000000L) return 18;
            if (l >= 10000000000000000L) return 17;
            if (l >= 1000000000000000L) return 16;
            if (l >= 100000000000000L) return 15;
            if (l >= 10000000000000L) return 14;
            if (l >= 1000000000000L) return 13;
            if (l >= 100000000000L) return 12;
            if (l >= 10000000000L) return 11;
            if (l >= 1000000000L) return 10;
            if (l >= 100000000L) return 9;
            if (l >= 10000000L) return 8;
            if (l >= 1000000L) return 7;
            if (l >= 100000L) return 6;
            if (l >= 10000L) return 5;
            if (l >= 1000L) return 4;
            if (l >= 100L) return 3;
            if (l >= 10L) return 2;
            return 1;
        }

        public FastWriter write(long x) {
            if (x == Long.MIN_VALUE) {
                return write("" + x);
            }
            if (ptr + 21 >= BUF_SIZE) innerflush();
            if (x < 0) {
                write((byte) '-');
                x = -x;
            }
            int d = countDigits(x);
            for (int i = ptr + d - 1; i >= ptr; i--) {
                buf[i] = (byte) ('0' + x % 10);
                x /= 10;
            }
            ptr += d;
            return this;
        }

        public FastWriter write(double x, int precision) {
            if (x < 0) {
                write('-');
                x = -x;
            }
            x += Math.pow(10, -precision) / 2;
            

            write((long) x).write(".");
            x -= (long) x;
            for (int i = 0; i < precision; i++) {
                x *= 10;
                write((char) ('0' + (int) x));
                x -= (int) x;
            }
            return this;
        }

        public FastWriter writeln(char c) {
            return write(c).writeln();
        }

        public FastWriter writeln(int x) {
            return write(x).writeln();
        }

        public FastWriter writeln(long x) {
            return write(x).writeln();
        }

        public FastWriter writeln(double x, int precision) {
            return write(x, precision).writeln();
        }

        public FastWriter write(int... xs) {
            boolean first = true;
            for (int x : xs) {
                if (!first) write(' ');
                first = false;
                write(x);
            }
            return this;
        }

        public FastWriter write(long... xs) {
            boolean first = true;
            for (long x : xs) {
                if (!first) write(' ');
                first = false;
                write(x);
            }
            return this;
        }

        public FastWriter writeln() {
            return write((byte) '\n');
        }

        public FastWriter writeln(int... xs) {
            return write(xs).writeln();
        }

        public FastWriter writeln(long... xs) {
            return write(xs).writeln();
        }

        public FastWriter writeln(char[] line) {
            return write(line).writeln();
        }

        public FastWriter writeln(char[]... map) {
            for (char[] line : map) write(line).writeln();
            return this;
        }

        public FastWriter writeln(String s) {
            return write(s).writeln();
        }

        private void innerflush() {
            try {
                out.write(buf, 0, ptr);
                ptr = 0;
            } catch (IOException e) {
                throw new RuntimeException("innerflush");
            }
        }

        public void flush() {
            innerflush();
            try {
                out.flush();
            } catch (IOException e) {
                throw new RuntimeException("flush");
            }
        }

        public FastWriter print(byte b) {
            return write(b);
        }

        public FastWriter print(char c) {
            return write(c);
        }

        public FastWriter print(char[] s) {
            return write(s);
        }

        public FastWriter print(String s) {
            return write(s);
        }

        public FastWriter print(int x) {
            return write(x);
        }

        public FastWriter print(long x) {
            return write(x);
        }

        public FastWriter print(double x, int precision) {
            return write(x, precision);
        }

        public FastWriter println(char c) {
            return writeln(c);
        }

        public FastWriter println(int x) {
            return writeln(x);
        }

        public FastWriter println(long x) {
            return writeln(x);
        }

        public FastWriter println(double x, int precision) {
            return writeln(x, precision);
        }

        public FastWriter print(int... xs) {
            return write(xs);
        }

        public FastWriter print(long... xs) {
            return write(xs);
        }

        public FastWriter println(int... xs) {
            return writeln(xs);
        }

        public FastWriter println(long... xs) {
            return writeln(xs);
        }

        public FastWriter println(char[] line) {
            return writeln(line);
        }

        public FastWriter println(char[]... map) {
            return writeln(map);
        }

        public FastWriter println(String s) {
            return writeln(s);
        }

        public FastWriter println() {
            return writeln();
        }
    }


    static final class InputReader {
        private final InputStream stream;
        private final byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        private int read() throws IOException {
            if (curChar >= numChars) {
                curChar = 0;
                numChars = stream.read(buf);
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        public final int readInt() throws IOException {
            return (int) readLong();
        }

        public final long readLong() throws IOException {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
                if (c == -1) throw new IOException();
            }
            boolean negative = false;
            if (c == '-') {
                negative = true;
                c = read();
            }
            long res = 0;
            do {
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return negative ? -res : res;
        }

        public final int[] readIntArray(int size) throws IOException {
            int[] array = new int[size];
            for (int i = 0; i < size; i++) {
                array[i] = readInt();
            }
            return array;
        }

        public final long[] readLongArray(int size) throws IOException {
            long[] array = new long[size];
            for (int i = 0; i < size; i++) {
                array[i] = readLong();
            }
            return array;
        }

        public final String readString() throws IOException {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                res.append((char) c);
                c = read();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        private boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
    }

    static long mulmod(long a, long b,
                       long mod) {
        long res = 0; 

        a = a % mod;
        while (b > 0) {
            

            if (b % 2 == 1) {
                res = (res + a) % mod;
            }

            

            a = (a * 2) % mod;

            

            b /= 2;
        }

        

        return res % mod;
    }

    static long pow(long a, long b, long MOD) {
        long x = 1, y = a;
        while (b > 0) {
            if (b % 2 == 1) {
                x = (x * y);
                if (x > MOD) x %= MOD;
            }
            y = (y * y);
            if (y > MOD) y %= MOD;
            b /= 2;
        }
        return x;
    }

    static long[] f = new long[200001];

    static long InverseEuler(long n, long MOD) {
        return pow(n, MOD - 2, MOD);
    }

    static long C(int n, int r, long MOD) {

        return (f[n] * ((InverseEuler(f[r], MOD) * InverseEuler(f[n - r], MOD)) % MOD)) % MOD;
    }


    static int[] h = {0, 0, -1, 1};
    static int[] v = {1, -1, 0, 0};


    public static class Pair {
        public int a;

        public int b;

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Pair pair = (Pair) o;
            return a == pair.a &&
                    b == pair.b;
        }

        @Override
        public int hashCode() {
            return Objects.hash(a, b);
        }

        public Pair(int a, int b) {
            this.a = a;
            this.b = b;
        }
    }

    static class Pair2 {
        public long cost;
        int node;

        public Pair2(long cos, int node) {
            this.cost = cos;
            this.node = node;
        }
    }

    static long compute_hash(String s) {
        int p = 31;
        int m = 1000000007;
        long hash_value = 0;
        long p_pow = 1;
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
            p_pow = (p_pow * p) % m;
        }
        return hash_value;
    }

    public static class SegmentTree {
        long[][] tree;
        int n;

        public SegmentTree(int[] nodes) {
            tree = new long[nodes.length * 4][2];
            n = nodes.length;
            build(0, n - 1, 0, nodes);

        }

        private void build(int l, int r, int pos, int[] nodes) {
            if (l == r) {
                tree[pos][0] = nodes[l];
                tree[pos][1] = l;
                return;
            }
            int mid = (l + r) / 2;
            build(l, mid, 2 * pos + 1, nodes);
            build(mid + 1, r, 2 * pos + 2, nodes);
            if (tree[2 * pos + 1][0] > tree[2 * pos + 2][0]) {
                tree[pos][1] = tree[2 * pos + 1][1];
            } else {
                tree[pos][1] = tree[2 * pos + 2][1];
            }
            tree[pos][0] = Math.max(tree[2 * pos + 1][0], tree[2 * pos + 2][0]);
        }

        

        

        


        public long[] get(int l, int r) {
            return getUtil(0, n - 1, 0, l, r);
        }

        private long[] getUtil(int l, int r, int pos, int ql, int qr) {
            if (ql > r || qr < l) {
                return new long[]{-1, -1};
            }
            if (l >= ql && r <= qr) {
                return tree[pos];
            }

            int mid = (l + r) / 2;
            long[] left = getUtil(l, mid, 2 * pos + 1, ql, qr);
            long[] right = getUtil(mid + 1, r, 2 * pos + 2, ql, qr);
            long choice = right[1];
            if (left[0] > right[0]) choice = left[1];
            return new long[]{Math.max(left[0], right[0]), choice};

        }

        

        

        

        

        

        

        

        

        

        

        

        

        

    }

    static int counter = 0;
    static int[] rIn;
    static int[] rOut;
    static int[] lIn;
    static int[] lOut;
    private static int[] flatten;
    private static int[] lFlatten;
    static long answer = 0;

    static int VISITED = 1;
    static int VISITING = 2;

    static int[] DIRX = new int[]{0, 0, 1, -1};
    static int[] DIRY = new int[]{1, -1, 0, 0};

    public static class Pair22 {
        int num, pos;

        public Pair22(int x, int y) {
            this.num = x;
            this.pos = y;
        }
    }

    public static long sumofdig(long n) {
        long sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    public static class DK {
        int D, K;

        public DK(int d, int k) {
            D = d;
            K = k;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            DK dk = (DK) o;
            return D == dk.D &&
                    K == dk.K;
        }

        @Override
        public int hashCode() {
            return Objects.hash(D, K);
        }
    }

    public static void main(String[] args) throws Exception {
        

        InputReader in = new InputReader(System.in);


        FastWriter out = new FastWriter(System.out);
















        int t = in.readInt();

        while (t-- > 0) {

            String a = in.readString();
            String b = in.readString();

            int n = a.length();
            int m = b.length();

            if (m > n) {
                System.out.println("NO");
                continue;
            }
            int[][][] next = new int[n][26][2];

            for (int i = n-2; i >= 0; --i) {

                for (int j = 0; j < 26; ++j) {

                    next[i][j][0] = next[i+1][j][1];
                    next[i][j][1] = next[i+1][j][0];
                }
                next[i][a.charAt(i+1) - 'a'][1] = i + 1;
            }
            int i = 0;
            for (; i < n; ++i) {
                if (a.charAt(i) == b.charAt(0)) break;
            }
            int ogi = i;
            int ogi2 = i;
            if (i == n) {
                System.out.println("NO");
                continue;
            }

            boolean found = true;
            for (int k = 1; k < m; ++k) {
                if (next[i][b.charAt(k) - 'a'][1] != 0) {
                    i = next[i][b.charAt(k) - 'a'][1];
                } else {
                    found = false;
                    break;
                }
            }

            if (found) {
                if (((n - 1 - i) % 2) == 0) {
                    System.out.println("YES");
                    continue;
                }
            }
            for (; ogi < n; ++ogi) {
                if (((ogi2 % 2) != (ogi % 2)) && a.charAt(ogi) == b.charAt(0)) break;
            }

            if (ogi == n) {
                System.out.println("NO");
                continue;
            }
            i = ogi;
            found = true;
            for (int k = 1; k < m; ++k) {
                if (next[i][b.charAt(k) - 'a'][1] != 0) {
                    i = next[i][b.charAt(k) - 'a'][1];
                } else {
                    found = false;
                    break;
                }
            }

            if (found) {
                if (((n - 1 - i) % 2) == 0) {
                    System.out.println("YES");
                    continue;
                }
            }


            System.out.println("NO");
            out.flush();


        }

    }

    private static void dfs(List<List<Integer>> g, int cur, int last, int[][] dp, int k) {


        dp[cur][0] = 1;
        for (int i = 0; i < g.get(cur).size(); ++i) {
            int ntb = g.get(cur).get(i);

            if (ntb != last) {
                dfs(g, ntb, cur, dp, k);

                for (int j = 1; j <= k; ++j) {
                    dp[cur][j] += dp[ntb][j-1];
                }
            }
        }
    }


    private static void solvedd(int[] arr, int left, int right, int[] ans, int depth) {

        if (left > right) return;
        int maxInd = left;
        for (int i = left; i <= right; ++i) {
            if (arr[i] > arr[maxInd]) {
                maxInd = i;
            }
        }

        ans[maxInd] = depth;

        solvedd(arr, left, maxInd - 1, ans, depth + 1);
        solvedd(arr, maxInd + 1, right, ans, depth + 1);

    }


    private static void solved(List<List<Integer>> g, int node, int[][] dp, int last, int[] a) {

        int donttake = 0;
        int take = 0;
        for (int i = 0; i < g.get(node).size(); ++i) {
            int ntb = g.get(node).get(i);

            if (ntb != last) {
                solved(g, ntb, dp, node, a);
                donttake += Math.max(dp[ntb][0], dp[ntb][1]);
                take += dp[ntb][1];
            }
        }
        dp[node][0] = a[node] + take;
        dp[node][1] = donttake;
    }


    private static boolean solve(int n, List<Integer> nums, int cur, int pos, Boolean[][] dp) {
        if (cur > n) return false;
        if (cur == n) return true;
        if (pos >= nums.size()) return false;

        if (dp[cur][pos] != null) {
            return dp[cur][pos];
        }
        boolean without = solve(n, nums, cur, pos + 1, dp);
        boolean with = false;
        int ogcur = cur;
        for (int i = 1; i < 12; ++i) {
            with |= solve(n, nums, cur + nums.get(pos), pos + 1, dp);
            cur += nums.get(pos);
        }

        return dp[ogcur][pos] = with | without;
    }




































    private static int solver(int[] nums, int pos, int[] dp) {
        if (pos >= nums.length) return 0;
        if (dp[pos] != Integer.MAX_VALUE) return dp[pos];
        int min = solver(nums, pos + 2, dp) + nums[pos];
        min = Math.min(solver(nums, pos + 3, dp) + nums[pos], min);
        if (pos + 1 < nums.length) min = Math.min(min, nums[pos] + nums[pos + 1] + solver(nums, pos + 3, dp));
        if (pos + 1 < nums.length) min = Math.min(min, nums[pos] + nums[pos + 1] + solver(nums, pos + 4, dp));

        

        return dp[pos] = min;
    }


    static int countFreq(String pattern, String text) {
        int m = pattern.length();
        int n = text.length();
        int res = 0;

        for (int i = 0; i <= n - m; i++) {
            int j;
            for (j = 0; j < m; j++) {
                if (text.charAt(i + j) != pattern.charAt(j)) {
                    break;
                }
            }
            if (j == m) {
                res++;
                j = 0;
            }
        }
        return res;
    }

    private static void dfsR(List<List<Integer>> g, int node, int[] v) {
        rIn[node] = counter;
        flatten[counter++] = v[node];

        for (int i = 0; i < g.get(node).size(); ++i) {
            dfsR(g, g.get(node).get(i), v);
        }

        rOut[node] = counter;
        flatten[counter++] = v[node] * -1;
    }

    private static void dfsL(List<List<Integer>> g, int node, int[] v) {
        lIn[node] = counter;
        lFlatten[counter++] = v[node];

        for (int i = 0; i < g.get(node).size(); ++i) {
            dfsL(g, g.get(node).get(i), v);
        }

        lOut[node] = counter;
        lFlatten[counter++] = v[node] * -1;

        TreeMap<String, Integer> map = new TreeMap<>();
    }


    private static void preprocess(int pos, int[][] pre, List<List<Integer>> tree, int[] traverse, int depth, int last, int[] tin, int[] tout) {
        tin[pos] = counter++;
        traverse[depth] = pos;

        for (int i = 0; depth - (1 << i) >= 0; ++i) {
            pre[pos][i] = traverse[depth - (1 << i)];
        }

        for (int i = 0; i < tree.get(pos).size(); ++i) {
            if (tree.get(pos).get(i) != last)
                preprocess(tree.get(pos).get(i), pre, tree, traverse, depth + 1, pos, tin, tout);
        }
        tout[pos] = counter++;
    }

    static long gcd(long a, long b) {

        while (b != 0) {
            long t = a;
            a = b;
            b = t % b;
        }
        return a;
    }

    static long lcm(long a, long b) {

        return a * b / gcd(a, b);
    }


    static boolean submit = true;

    static void debug(String s) {
        if (!submit)
            System.out.println(s);
    }

    static void debug(int s) {
        LinkedHashSet<Integer> exist = new LinkedHashSet<>();
            
    }

    class MyCalendarThree {

        int max = 0;
        public class Pair {
            int num;
            boolean pos;
            public Pair (int num, boolean pos) {
                this.num = num;
                this.pos = pos;
            }

            @Override
            public boolean equals(Object o) {
                if (this == o) return true;
                if (o == null || getClass() != o.getClass()) return false;
                Pair pair = (Pair) o;
                return num == pair.num && pos == pair.pos;
            }

            @Override
            public int hashCode() {
                return Objects.hash(num, pos);
            }
        }
        TreeMap<Pair, Integer> count = new TreeMap<>(new Comparator<Pair>() {
            @Override
            public int compare(Pair a, Pair b) {
                int compare = Integer.compare(a.num, b.num);

                if (compare == 0) return Boolean.compare(a.pos, b.pos);
                return compare;
            }
        });
        public MyCalendarThree() {

        }

        public int book(int start, int end) {
            count.put(new Pair(start, true), count.getOrDefault(new Pair(start, true), 0) + 1);
            count.put(new Pair(end, false), count.getOrDefault(new Pair(end, false), 0) + 1);

            int counter = 0;

            SortedMap<Pair, Integer> pairIntegerSortedMap = count.subMap(new Pair(start, true), new Pair(end, false));
            for (Pair p: pairIntegerSortedMap.keySet()) {
                if (p.pos) {
                    counter += count.get(p);
                } else {
                    counter -= count.get(p);
                }
                max = Math.max(counter, max);
            }

            return max;
        }
    }


}