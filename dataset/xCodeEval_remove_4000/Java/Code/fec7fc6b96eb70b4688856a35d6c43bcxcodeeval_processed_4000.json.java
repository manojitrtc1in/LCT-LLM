import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Stack;

public class Main {
    static long MOD = 998244353l;
    int min = Integer.MAX_VALUE;
    int max = 0;

    char result[][];
    int count = 0;
    int pattern = 0;

    public static void main(String[] args) throws Exception {
        

        var sc = new FastScanner();
        

        

        var pw = new id7();
        solve(sc, pw);
        sc.close();
        pw.flush();
        pw.close();
    }

    public static void solve(FastScanner sc, id7 pw) {
        int t = sc.nextInt();
        for (int times = 0; times < t; times++) {
            int n = sc.nextInt();
            int a[] = new int[n];
            Arrays.setAll(a, i -> sc.nextInt());
            Map<Integer, Integer> map = new HashMap<Integer, Integer>();
            for (int i = 0; i < n; i++) {
                int count = 1;
                if (map.containsKey(a[i])) {
                    count = map.get(a[i]) + 1;
                }
                map.put(a[i], count);
            }
            List<Integer> list = new ArrayList<Integer>();
            for (Integer in : map.keySet()) {
                list.add(map.get(in));
            }
            Collections.sort(list);
            int count = list.size();
            int index = 0;
            int nowcount = list.get(index);
            int now = 0;
            for (now = 0; now < list.size(); now++) {
                pw.print(count + " ");
            } 

            for (; now < n; now++) {
                pw.print(now+1+" ");
            }
            pw.println();
        }
    }

    public static int id6(int a[], int x) {
        int min = 0;
        int max = a.length - 1;
        int re = Integer.MAX_VALUE;
        while (min <= max) {
            int mid = (min + max) / 2;
            if (a[mid] >= x) {
                re = Math.min(mid, re);
                max = mid - 1;
            } else {
                min = mid + 1;
            }
        }
        return re;
    }

    public static int binarySearch(int a[], int x) {
        int min = 0;
        int max = a.length - 1;
        int re = Integer.MAX_VALUE;
        while (min <= max) {
            int mid = (min + max) / 2;
            if (a[mid] < x) {
                re = Math.max(mid, re);
                min = mid + 1;
            } else {
                max = mid - 1;
            }
        }
        return re;
    }

    public char[][] copyArray(char c[][], int n) {
        char re[][] = new char[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                re[i][j] = c[i][j];
            }
        }
        return re;
    }

    public static void swap(int[] s, int i, int j) {
        int tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }

    public void permutation(int[] s, int from, int to, int a[]) {
        if (to <= 1)
            return;
        if (from == to) {
            check(s, a);
        } else {
            for (int i = from; i <= to; i++) {
                swap(s, i, from);
                permutation(s, from + 1, to, a);
                swap(s, from, i);
            }
        }
    }

    public void check(int[] s, int a[]) {
        int re = 0;
        int b[][] = new int[2][3];
        for (int i = 0; i < 6; i++) {
            b[i / 3][i % 3] = a[s[i]];
        }
        int maxx = 0;
        int maxy = 0;
        int minx = 10000;
        int miny = 10000;
        for (int i = 0; i < 3; i++) {
            maxx = Math.max(maxx, b[0][i]);
            minx = Math.min(minx, b[0][i]);
            maxy = Math.max(maxy, b[1][i]);
            miny = Math.min(miny, b[1][i]);
        }
        re = (maxx - minx) * (maxy - miny) * 2;
        re = re - (Math.abs(b[0][0] - b[0][1]) * Math.abs(b[1][0] - b[1][1]));
        re = re - (Math.abs(b[0][0] - b[0][2]) * Math.abs(b[1][0] - b[1][2]));
        re = re - (Math.abs(b[0][2] - b[0][1]) * Math.abs(b[1][2] - b[1][1]));
        max = Math.max(re, max);
    }

    public static long id3(long ano, int another) {
        long ten = 0;
        long now = 1;
        long temp = ano;
        while (temp > 0) {
            long i = temp % 10;
            ten += now * i;
            now *= another;
            temp /= 10;
        }
        return ten;
    }

    public static long id4(long ten, int another) {
        Stack<Long> stack = new Stack<Long>();
        while (ten > 0) {
            stack.add(ten % another);
            ten /= another;
        }
        long re = 0;
        while (!stack.isEmpty()) {
            long pop = stack.pop();
            re = re * 10 + pop;
        }
        return re;
    }

    

    public static long XCY(long x, long y) {
        long temp = 1;
        for (int i = 0; i < x; i++) {
            temp = (temp * (y - i)) % MOD;
        }
        long tempx = 1;
        for (int i = 2; i <= x; i++) {
            tempx = (tempx * i) % MOD;
        }
        tempx = modpow(tempx, (long) MOD - 2);
        temp = (temp * tempx) % MOD;
        return temp;
    }

    static long modpow(long N, Long K) {
        return BigInteger.valueOf(N).modPow(BigInteger.valueOf(K), BigInteger.valueOf(MOD)).longValue();
    }

    static long modpow(long N, Long K, long mod) {
        return BigInteger.valueOf(N).modPow(BigInteger.valueOf(K), BigInteger.valueOf(mod)).longValue();
    }

    public static long gcd(long a, long b) {
        if (b == 0) {
            return a;
        }
        if (a < b) {
            return gcd(b, a);
        }
        return gcd(b, a % b);
    }

    public static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        if (a < b) {
            return gcd(b, a);
        }
        return gcd(b, a % b);
    }

}

class Range {
    long start = 0;
    long end = 0;
}

class Point implements Comparable {
    int n;
    int x;
    int y;

    public int compareTo(Object p) {
        Point t = (Point) p;
        if (this.x != t.x) {
            return this.x - t.x;
        }
        

        

        

        return this.n - t.n;
    }
}

class PointY implements Comparable {
    int a;
    int b;

    public int compareTo(Object p) {
        PointY t = (PointY) p;
        if (this.a > t.a) {
            return -1;
        }
        if (this.a < t.a) {
            return 1;
        }
        return 0;
    }
}

class id7 implements AutoCloseable {
    private static final int BUF_SIZE = 1 << 15;
    private final byte[] buf = new byte[BUF_SIZE];
    private int ptr = 0;
    private final java.lang.reflect.Field strField;
    private final java.nio.charset.CharsetEncoder encoder;

    private java.io.OutputStream out;

    public id7(java.io.OutputStream out) {
        this.out = out;
        java.lang.reflect.Field f;
        try {
            f = java.lang.String.class.getDeclaredField("value");
            f.setAccessible(true);
        } catch (NoSuchFieldException | SecurityException e) {
            f = null;
        }
        this.strField = f;
        this.encoder = java.nio.charset.StandardCharsets.US_ASCII.newEncoder();
    }

    public id7(java.io.File file) throws java.io.IOException {
        this(new java.io.FileOutputStream(file));
    }

    public id7(java.lang.String filename) throws java.io.IOException {
        this(new java.io.File(filename));
    }

    public id7() {
        this(System.out);
        try {
            java.lang.reflect.Field f = java.io.PrintStream.class.getDeclaredField("autoFlush");
            f.setAccessible(true);
            f.set(System.out, false);
        } catch (IllegalAccessException | IllegalArgumentException | NoSuchFieldException e) {
            

        }
    }

    public id7 println() {
        if (ptr == BUF_SIZE)
            internalFlush();
        buf[ptr++] = (byte) '\n';
        return this;
    }

    public id7 println(java.lang.Object o) {
        return print(o).println();
    }

    public id7 println(java.lang.String s) {
        return print(s).println();
    }

    public id7 println(char[] s) {
        return print(s).println();
    }

    public id7 println(char c) {
        return print(c).println();
    }

    public id7 println(int x) {
        return print(x).println();
    }

    public id7 println(long x) {
        return print(x).println();
    }

    public id7 println(double d, int precision) {
        return print(d, precision).println();
    }

    private id7 print(byte[] bytes) {
        int n = bytes.length;
        if (ptr + n > BUF_SIZE) {
            internalFlush();
            try {
                out.write(bytes);
            } catch (java.io.IOException e) {
                throw new RuntimeException();
            }
        } else {
            System.arraycopy(bytes, 0, buf, ptr, n);
            ptr += n;
        }
        return this;
    }

    public id7 print(java.lang.Object o) {
        return print(o.toString());
    }

    public id7 print(java.lang.String s) {
        if (strField == null) {
            return print(s.getBytes());
        } else {
            try {
                return print((byte[]) strField.get(s));
            } catch (IllegalAccessException e) {
                return print(s.getBytes());
            }
        }
    }

    public id7 print(char[] s) {
        try {
            return print(encoder.encode(java.nio.CharBuffer.wrap(s)).array());
        } catch (java.nio.charset.CharacterCodingException e) {
            byte[] bytes = new byte[s.length];
            for (int i = 0; i < s.length; i++) {
                bytes[i] = (byte) s[i];
            }
            return print(bytes);
        }
    }

    public id7 print(char c) {
        if (ptr == BUF_SIZE)
            internalFlush();
        buf[ptr++] = (byte) c;
        return this;
    }

    public id7 print(int x) {
        if (x == 0) {
            if (ptr == BUF_SIZE)
                internalFlush();
            buf[ptr++] = '0';
            return this;
        }
        int d = len(x);
        if (ptr + d > BUF_SIZE)
            internalFlush();
        if (x < 0) {
            buf[ptr++] = '-';
            x = -x;
            d--;
        }
        int j = ptr += d;
        while (x > 0) {
            buf[--j] = (byte) ('0' + (x % 10));
            x /= 10;
        }
        return this;
    }

    public id7 print(long x) {
        if (x == 0) {
            if (ptr == BUF_SIZE)
                internalFlush();
            buf[ptr++] = '0';
            return this;
        }
        int d = len(x);
        if (ptr + d > BUF_SIZE)
            internalFlush();
        if (x < 0) {
            buf[ptr++] = '-';
            x = -x;
            d--;
        }
        int j = ptr += d;
        while (x > 0) {
            buf[--j] = (byte) ('0' + (x % 10));
            x /= 10;
        }
        return this;
    }

    public id7 print(double d, int precision) {
        if (d < 0) {
            print('-');
            d = -d;
        }
        d += Math.pow(10, -d) / 2;
        print((long) d).print('.');
        d -= (long) d;
        for (int i = 0; i < precision; i++) {
            d *= 10;
            print((int) d);
            d -= (int) d;
        }
        return this;
    }

    private void internalFlush() {
        try {
            out.write(buf, 0, ptr);
            ptr = 0;
        } catch (java.io.IOException e) {
            throw new RuntimeException(e);
        }
    }

    public void flush() {
        try {
            out.write(buf, 0, ptr);
            out.flush();
            ptr = 0;
        } catch (java.io.IOException e) {
            throw new RuntimeException(e);
        }
    }

    public void close() {
        try {
            out.close();
        } catch (java.io.IOException e) {
            throw new RuntimeException(e);
        }
    }

    private static int len(int x) {
        int d = 1;
        if (x >= 0) {
            d = 0;
            x = -x;
        }
        int p = -10;
        for (int i = 1; i < 10; i++, p *= 10)
            if (x > p)
                return i + d;
        return 10 + d;
    }

    private static int len(long x) {
        int d = 1;
        if (x >= 0) {
            d = 0;
            x = -x;
        }
        long p = -10;
        for (int i = 1; i < 19; i++, p *= 10)
            if (x > p)
                return i + d;
        return 19 + d;
    }
}

class FastScanner implements AutoCloseable {
    private final java.io.InputStream in;
    private final byte[] buf = new byte[2048];
    private int ptr = 0;
    private int buflen = 0;

    public FastScanner(java.io.InputStream in) {
        this.in = in;
    }

    public FastScanner() {
        this(System.in);
    }

    private boolean id9() {
        if (ptr < buflen)
            return true;
        ptr = 0;
        try {
            buflen = in.read(buf);
        } catch (java.io.IOException e) {
            throw new RuntimeException(e);
        }
        return buflen > 0;
    }

    private int readByte() {
        return id9() ? buf[ptr++] : -1;
    }

    public boolean hasNext() {
        while (id9() && !(32 < buf[ptr] && buf[ptr] < 127))
            ptr++;
        return id9();
    }

    private StringBuilder nextSequence() {
        if (!hasNext())
            throw new java.util.NoSuchElementException();
        StringBuilder sb = new StringBuilder();
        for (int b = readByte(); 32 < b && b < 127; b = readByte()) {
            sb.appendCodePoint(b);
        }
        return sb;
    }

    public String next() {
        return nextSequence().toString();
    }

    public String next(int len) {
        return new String(nextChars(len));
    }

    public char nextChar() {
        if (!id9())
            throw new java.util.NoSuchElementException();
        return (char) readByte();
    }

    public char[] nextChars() {
        StringBuilder sb = nextSequence();
        int l = sb.length();
        char[] dst = new char[l];
        sb.getChars(0, l, dst, 0);
        return dst;
    }

    public char[] nextChars(int len) {
        if (!hasNext())
            throw new java.util.NoSuchElementException();
        char[] s = new char[len];
        int i = 0;
        int b = readByte();
        while (32 < b && b < 127 && i < len) {
            s[i++] = (char) b;
            b = readByte();
        }
        if (i != len) {
            throw new java.util.NoSuchElementException(
                    String.format("Next token has smaller length than expected.", len));
        }
        return s;
    }

    public long nextLong() {
        if (!hasNext())
            throw new java.util.NoSuchElementException();
        long n = 0;
        boolean minus = false;
        int b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        if (b < '0' || '9' < b)
            throw new NumberFormatException();
        while (true) {
            if ('0' <= b && b <= '9') {
                n = n * 10 + b - '0';
            } else if (b == -1 || !(32 < b && b < 127)) {
                return minus ? -n : n;
            } else
                throw new NumberFormatException();
            b = readByte();
        }
    }

    public int nextInt() {
        return Math.toIntExact(nextLong());
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }

    public void close() {
        try {
            in.close();
        } catch (java.io.IOException e) {
            throw new RuntimeException(e);
        }
    }

}


class SegTree<S> {
    final int MAX;

    final int N;
    final java.util.function.BinaryOperator<S> op;
    final S E;

    final S[] data;

    @SuppressWarnings("unchecked")
    public SegTree(int n, java.util.function.BinaryOperator<S> op, S e) {
        this.MAX = n;
        int k = 1;
        while (k < n)
            k <<= 1;
        this.N = k;
        this.E = e;
        this.op = op;
        this.data = (S[]) new Object[N << 1];
        java.util.Arrays.fill(data, E);
    }

    public SegTree(S[] dat, java.util.function.BinaryOperator<S> op, S e) {
        this(dat.length, op, e);
        build(dat);
    }

    private void build(S[] dat) {
        int l = dat.length;
        System.arraycopy(dat, 0, data, N, l);
        for (int i = N - 1; i > 0; i--) {
            data[i] = op.apply(data[i << 1 | 0], data[i << 1 | 1]);
        }
    }

    public void set(int p, S x) {
        id8(p);
        data[p += N] = x;
        p >>= 1;
        while (p > 0) {
            data[p] = op.apply(data[p << 1 | 0], data[p << 1 | 1]);
            p >>= 1;
        }
    }

    public S get(int p) {
        id8(p);
        return data[p + N];
    }

    public S prod(int l, int r) {
        if (l > r) {
            throw new IllegalArgumentException(String.format("Invalid range: [%d, %d)", l, r));
        }
        id0(l);
        id0(r);
        S sumLeft = E;
        S sumRight = E;
        l += N;
        r += N;
        while (l < r) {
            if ((l & 1) == 1)
                sumLeft = op.apply(sumLeft, data[l++]);
            if ((r & 1) == 1)
                sumRight = op.apply(data[--r], sumRight);
            l >>= 1;
            r >>= 1;
        }
        return op.apply(sumLeft, sumRight);
    }

    public S allProd() {
        return data[1];
    }

    public int maxRight(int l, java.util.function.Predicate<S> f) {
        id0(l);
        if (!f.test(E)) {
            throw new IllegalArgumentException("Identity element must satisfy the condition.");
        }
        if (l == MAX)
            return MAX;
        l += N;
        S sum = E;
        do {
            l >>= Long.numberOfTrailingZeros(l);
            if (!f.test(op.apply(sum, data[l]))) {
                while (l < N) {
                    l = l << 1;
                    if (f.test(op.apply(sum, data[l]))) {
                        sum = op.apply(sum, data[l]);
                        l++;
                    }
                }
                return l - N;
            }
            sum = op.apply(sum, data[l]);
            l++;
        } while ((l & -l) != l);
        return MAX;
    }

    public int minLeft(int r, java.util.function.Predicate<S> f) {
        id0(r);
        if (!f.test(E)) {
            throw new IllegalArgumentException("Identity element must satisfy the condition.");
        }
        if (r == 0)
            return 0;
        r += N;
        S sum = E;
        do {
            r--;
            while (r > 1 && (r & 1) == 1)
                r >>= 1;
            if (!f.test(op.apply(data[r], sum))) {
                while (r < N) {
                    r = r << 1 | 1;
                    if (f.test(op.apply(data[r], sum))) {
                        sum = op.apply(data[r], sum);
                        r--;
                    }
                }
                return r + 1 - N;
            }
            sum = op.apply(data[r], sum);
        } while ((r & -r) != r);
        return 0;
    }

    private void id8(int p) {
        if (p < 0 || p >= MAX) {
            throw new IndexOutOfBoundsException(
                    String.format("Index %d out of bounds for the range [%d, %d).", p, 0, MAX));
        }
    }

    private void id0(int p) {
        if (p < 0 || p > MAX) {
            throw new IndexOutOfBoundsException(
                    String.format("Index %d out of bounds for the range [%d, %d].", p, 0, MAX));
        }
    }

    


    private int indent = 6;

    public void setIndent(int newIndent) {
        this.indent = newIndent;
    }

    @Override
    public String toString() {
        return id2();
    }

    public String id5() {
        return id5(1, 0);
    }

    private String id5(int k, int sp) {
        if (k >= N)
            return indent(sp) + data[k];
        String s = "";
        s += id5(k << 1 | 1, sp + indent);
        s += "\n";
        s += indent(sp) + data[k];
        s += "\n";
        s += id5(k << 1 | 0, sp + indent);
        return s;
    }

    private static String indent(int n) {
        StringBuilder sb = new StringBuilder();
        while (n-- > 0)
            sb.append(' ');
        return sb.toString();
    }

    public String id2() {
        StringBuilder sb = new StringBuilder();
        sb.append('[');
        for (int i = 0; i < N; i++) {
            sb.append(data[i + N]);
            if (i < N - 1)
                sb.append(',').append(' ');
        }
        sb.append(']');
        return sb.toString();
    }
}

class DSU {
    private int n;
    private int[] id1;

    public DSU(int n) {
        this.n = n;
        this.id1 = new int[n];
        Arrays.fill(id1, -1);
    }

    int merge(int a, int b) {
        if (!(0 <= a && a < n) || !(0 <= b && b < n)) {
            return -1;
        }
        int x = leader(a);
        int y = leader(b);
        if (x == y)
            return x;
        if (-id1[x] < -id1[y]) {
            int tmp = x;
            x = y;
            y = tmp;
        }
        id1[x] += id1[y];
        id1[y] = x;
        return x;
    }

    boolean same(int a, int b) {
        if (!(0 <= a && a < n) || !(0 <= b && b < n)) {
            return false;
        }
        return leader(a) == leader(b);
    }

    int leader(int a) {
        if (id1[a] < 0) {
            return a;
        } else {
            id1[a] = leader(id1[a]);
            return id1[a];
        }
    }

    int size(int a) {
        if (!(0 <= a && a < n)) {
            return -1;
        }
        return -id1[leader(a)];
    }

    ArrayList<ArrayList<Integer>> groups() {
        int[] leaderBuf = new int[n];
        int[] groupSize = new int[n];
        for (int i = 0; i < n; i++) {
            leaderBuf[i] = leader(i);
            groupSize[leaderBuf[i]]++;
        }
        ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();
        for (int i = 0; i < n; i++) {
            result.add(new ArrayList<>());
        }
        for (int i = 0; i < n; i++) {
            result.get(leaderBuf[i]).add(i);
        }
        return result;
    }
}
