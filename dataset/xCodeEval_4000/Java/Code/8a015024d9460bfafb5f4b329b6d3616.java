

import java.io.*;
import java.text.MessageFormat;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.function.BinaryOperator;


public class _C {

    final boolean ONLINE_JUDGE = java.lang.System.getProperty("ONLINE_JUDGE") != null;

    private void solveOne() {
        int n = nextInt();
        int q = nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        SegmentTree_ cols = new SegmentTree_(a);
        SegmentTree_ rows = new SegmentTree_(b);


        for (int i = 0; i < q; i++) {
            int type = nextInt();
            if (type == 1) {
                int x = nextInt() - 1;
                cols.update(x, x, cols.rsq(x, x) + 1);
                int y = nextInt() - 1;
                rows.update(y, y, rows.rsq(y,y) + 1);
            } else if (type == 2) {
                int x = nextInt() - 1;
                cols.update(x, x, cols.rsq(x, x) - 1);
                int y = nextInt() - 1;
                rows.update(y, y, rows.rsq(y,y) -1);
            } else {
                int x1 = nextInt() - 1;
                int y1 = nextInt() - 1;
                int x2 = nextInt() - 1;
                int y2 = nextInt() - 1;

                boolean ans = cols.rMinQ(x1, x2) > 0 || rows.rMinQ(y1, y2) > 0;
                System.out.println(ans ? "YES" : "NO");
            }
        }


    }

    static class SegmentTree {

        int neutral;
        BinaryOperator<Integer> function;

        SegmentTree(int[] a, BinaryOperator<Integer> function, int neutral) {
            this.function = function;
            this.neutral = neutral;
            this.n = a.length;
            this.t = new int[2 * n];
            this.d = new int[n];
            this.h = 32 - Integer.numberOfLeadingZeros(n);
            for (int i = 0; i < n; i++) {
                this.inc(i, i + 1, a[i]);
            }

        }

        static SegmentTree MIN(int[] a) {
            return new SegmentTree(a, Integer::min, Integer.MAX_VALUE);
        }

        static SegmentTree MAX(int[] a) {
            return new SegmentTree(a, Integer::max, Integer.MIN_VALUE);
        }

        static SegmentTree SUM(int[] a) {
            return new SegmentTree(a, Integer::sum, 0);
        }

        int n;
        int[] t;
        int[] d;
        int h;

        void apply(int p, int value) {
            t[p] += value;
            if (p < n) d[p] += value;
        }

        void build(int p) {
            while (p > 1) {
                p >>= 1;
                t[p] = function.apply(t[p << 1], t[p << 1 | 1]) + d[p];
            }
        }

        void push(int p) {
            for (int s = h; s > 0; --s) {
                int i = p >> s;
                if (d[i] != 0) {
                    apply(i << 1, d[i]);
                    apply(i << 1 | 1, d[i]);
                    d[i] = 0;
                }
            }
        }

        public void inc(int l, int r, int value) {
            if (l >= n) return;
            l += n;
            r += n;
            int l0 = l, r0 = r;
            for (; l < r; l >>= 1, r >>= 1) {
                if ((l & 1) != 0) apply(l++, value);
                if ((r & 1) != 0) apply(--r, value);
            }
            build(l0);
            build(r0 - 1);
        }


        public int query(int l, int r) {
            if (l >= n) return neutral;
            l += n;
            r += n;
            push(l);
            push(r - 1);
            int res = neutral;
            for (; l < r; l >>= 1, r >>= 1) {
                if ((l & 1) != 0) res = function.apply(res, t[l++]);
                if ((r & 1) != 0) res = function.apply(t[--r], res);
            }
            return res;
        }
    }

    static class SparseSegmentTree {


        static int cntOfNodes = 0;

        static long DEFAULT = (long) 1e18;

        int n = (int) 1e9;


        Node head;

        public SparseSegmentTree(int n) {
            this.n = n;
            head = new Node(0, n);
        }

        static class Node {

            long t = 0;
            long sum = 0;
            long add_mod = 0;
            long set_mod = DEFAULT;

            Node l;
            Node r;

            final int tl;
            final int tr;

            public Node(int tl, int tr) {
                this.tl = tl;
                this.tr = tr;
                cntOfNodes++;
            }

            public int len() {
                return tr + 1 - tl;
            }
        }

        enum Turn {
            LEFT, RIGHT
        }

        private void ensureChildExist(Node p, Turn turn) {
            int tl = p.tl;
            int tr = p.tr;
            int tm = (tl + tr) >>> 1;
            if (turn == Turn.LEFT && p.l == null) {
                p.l = new Node(tl, tm);
            }

            if (turn == Turn.RIGHT && p.r == null) {
                p.r = new Node(tm + 1, tr);
            }
        }

        public void set(int l, int r, long value) {
            set(l, r, value, head);
        }

        private void set(int l, int r, long value, Node v) {
            int tl = v.tl, tr = v.tr;
            if (l > r) {
                return;
            }

            if (l == tl && r == tr) {
                applySetMod(v, value);
                return;
            }
            int tm = (tl + tr) >>> 1;
            push(v);

            set(l, Math.min(r, tm), value, v.l);

            set(Math.max(l, tm + 1), r, value, v.r);

            propagate(v);
        }


        public void increment(int l, int r, long delta) {
            increment(l, r, delta, head);
        }

        private void increment(int l, int r, long val, Node v) {
            int tl = v.tl, tr = v.tr;
            if (l > r) {
                return;
            }

            if (l == tl && r == tr) {
                applyAddMod(v, val);
                return;
            }
            int tm = (tl + tr) >>> 1;
            push(v);


            increment(l, Math.min(r, tm), val, v.l);

            increment(Math.max(l, tm + 1), r, val, v.r);

            propagate(v);
        }

        private void propagate(Node v) {
            v.t = Math.min(getValue(v.l), getValue(v.r));
            v.sum = getSum(v.l) + getSum(v.r);
        }

        private long getSum(Node v) {
            if (v.set_mod != DEFAULT) {
                return v.set_mod * v.len();
            }
            if (v.add_mod != 0) {
                return v.add_mod * v.len() + v.sum;
            }
            return v.sum;
        }

        private long getValue(Node v) {
            if (v.set_mod != DEFAULT) {
                return v.set_mod;
            }
            if (v.add_mod != 0) {
                return v.add_mod + v.t;
            }
            return v.t;
        }

        private void push(Node v) {


            ensureChildExist(v, Turn.LEFT);
            ensureChildExist(v, Turn.RIGHT);

            if (v.add_mod != 0) {
                v.t += v.add_mod;
                v.sum += v.add_mod * v.len();

                applyAddMod(v.l, v.add_mod);

                applyAddMod(v.r, v.add_mod);
                v.add_mod = 0;
            }
            if (v.set_mod != DEFAULT) {
                v.t = v.set_mod;
                v.sum = v.set_mod * v.len();

                applySetMod(v.l, v.set_mod);

                applySetMod(v.r, v.set_mod);
                v.set_mod = DEFAULT;
            }
        }

        private void applyAddMod(Node v, long val) {
            if (v.set_mod != DEFAULT) {
                v.set_mod += val;
            } else {
                v.add_mod += val;
            }
        }

        private void applySetMod(Node v, long val) {
            v.add_mod = 0;
            v.set_mod = val;
        }

        public long sum(int l, int r) {
            return sum(l, r, head);
        }

        public long sum(int l, int r, Node v) {
            int tl = v.tl, tr = v.tr;
            if (l > r) {
                return 0;
            }

            if (l == tl && r == tr) {
                return getSum(v);
            }
            int tm = (tl + tr) >>> 1;
            push(v);
            long res_l = sum(l, Math.min(r, tm), v.l);
            long res_r = sum(Math.max(l, tm + 1), r, v.r);
            return res_l + res_r;
        }


        public long min(int l, int r) {
            return min(l, r, head);
        }

        public long min(int l, int r, Node v) {
            int tl = v.tl, tr = v.tr;
            if (l > r) {
                return 0;
            }

            if (l == tl && r == tr) {
                return getValue(v);
            }
            int tm = (tl + tr) >>> 1;
            push(v);
            long res_l = min(l, Math.min(r, tm), v.l);
            long res_r = min(Math.max(l, tm + 1), r, v.r);
            return Math.min(res_l, res_r);
        }

    }

    static class ST  {
        class Segment {
            public Segment(int l, int r) {
                this.l = l;
                this.r = r;
            }

            final int l;
            final int r;

            int min;

            int len(){
                return r + 1 - l;
            }



















        }

        Segment[] tree;

        int n;
        public ST(int n) {
            this.n = n;
            tree = new Segment[8 * n];

            init(0, 0, n - 1);
        }

        void init(int v, int tl, int tr) {













            if (tl == tr) {
                

                tree[v] = new Segment(tl, tr);
            } else {
                int tm = (tl + tr) / 2;
                init(v*2 + 1, tl, tm);
                init( v*2 + 2, tm+1, tr);
                tree[v] = new Segment(tl, tr);
                

            }
        }

        public void increment(int i, int val) {
            

            int j = 0;
            while (j < tree.length ) {
                Segment curSeg = tree[j];
                if(curSeg.len() == 1) {
                    curSeg.min += val;
                    break;
                }







                int m = (curSeg.l + curSeg.r) / 2;
                j = 2 * j + (i <= m ? 1 : 2);
                

            }
            while (true) {
                j = (j - 1) / 2;
                tree[j].min = Math.min(tree[2*i + 1].min, tree[2*i + 2].min);
                if(j == 0) break;
            }

        }
        public int min(int from, int to){
            return min(from, to, 0, 0, n - 1);
        }
        public int min(int l, int r, int i, int tl, int tr){



            if (l > r) {
                return Integer.MIN_VALUE;
            }

            if (l == tl && r == tr) {
                Segment seg = tree[i];






                    return seg.min;
            }
            int tm = (tl + tr) / 2;
            


            int min1 = min(l, Math.min(tm, r), 2 * i + 1, tl, tm);
            int min2 = min(Math.max(l, tm + 1), r, 2 * i + 2, tm + 1, tr);
            return Math.min(min1, min2);
        }


    }

    static class SegmentTree_ {

        private Node[] heap;
        private int[] array;
        private int size;

        
        public SegmentTree_(int[] array) {
            this.array = Arrays.copyOf(array, array.length);
            

            size = (int) (2 * Math.pow(2.0, Math.floor((Math.log((double) array.length) / Math.log(2.0)) + 1)));
            heap = new Node[size];
            build(1, 0, array.length);
        }


        public int size() {
            return array.length;
        }

        

        private void build(int v, int from, int size) {
            heap[v] = new Node();
            heap[v].from = from;
            heap[v].to = from + size - 1;

            if (size == 1) {
                heap[v].sum = array[from];
                heap[v].min = array[from];
            } else {
                

                build(2 * v, from, size / 2);
                build(2 * v + 1, from + size / 2, size - size / 2);

                heap[v].sum = heap[2 * v].sum + heap[2 * v + 1].sum;
                

                heap[v].min = Math.min(heap[2 * v].min, heap[2 * v + 1].min);
            }
        }

        
        public int rsq(int from, int to) {
            return rsq(1, from, to);
        }

        private int rsq(int v, int from, int to) {
            Node n = heap[v];

            

            if (n.pendingVal != null && contains(n.from, n.to, from, to)) {
                return (to - from + 1) * n.pendingVal;
            }

            if (contains(from, to, n.from, n.to)) {
                return heap[v].sum;
            }

            if (intersects(from, to, n.from, n.to)) {
                propagate(v);
                int leftSum = rsq(2 * v, from, to);
                int rightSum = rsq(2 * v + 1, from, to);

                return leftSum + rightSum;
            }

            return 0;
        }

        
        public int rMinQ(int from, int to) {
            return rMinQ(1, from, to);
        }

        private int rMinQ(int v, int from, int to) {
            Node n = heap[v];


            

            if (n.pendingVal != null && contains(n.from, n.to, from, to)) {
                return n.pendingVal;
            }

            if (contains(from, to, n.from, n.to)) {
                return heap[v].min;
            }

            if (intersects(from, to, n.from, n.to)) {
                propagate(v);
                int leftMin = rMinQ(2 * v, from, to);
                int rightMin = rMinQ(2 * v + 1, from, to);

                return Math.min(leftMin, rightMin);
            }

            return Integer.MAX_VALUE;
        }


        
        public void update(int from, int to, int value) {
            update(1, from, to, value);
        }

        private void update(int v, int from, int to, int value) {

            

            Node n = heap[v];

            
            if (contains(from, to, n.from, n.to)) {
                change(n, value);
            }

            if (n.size() == 1) return;

            if (intersects(from, to, n.from, n.to)) {
                
                propagate(v);

                update(2 * v, from, to, value);
                update(2 * v + 1, from, to, value);

                n.sum = heap[2 * v].sum + heap[2 * v + 1].sum;
                n.min = Math.min(heap[2 * v].min, heap[2 * v + 1].min);
            }
        }

        

        private void propagate(int v) {
            Node n = heap[v];

            if (n.pendingVal != null) {
                change(heap[2 * v], n.pendingVal);
                change(heap[2 * v + 1], n.pendingVal);
                n.pendingVal = null; 

            }
        }

        

        private void change(Node n, int value) {
            n.pendingVal = value;
            n.sum = n.size() * value;
            n.min = value;
            array[n.from] = value;

        }

        

        private boolean contains(int from1, int to1, int from2, int to2) {
            return from2 >= from1 && to2 <= to1;
        }

        

        private boolean intersects(int from1, int to1, int from2, int to2) {
            return from1 <= from2 && to1 >= from2   

                    || from1 >= from2 && from1 <= to2; 

        }

        

        static class Node {
            int sum;
            int min;
            

            Integer pendingVal = null;
            int from;
            int to;

            int size() {
                return to - from + 1;
            }

        }
    }

    private void solve() {
        int t = 1;

        for (int testCase = 0; testCase < t; testCase++) {
            solveOne();
        }
    }

    class AssertionRuntimeException extends RuntimeException {

        AssertionRuntimeException(String testName,
                                  int testCase,
                                  Object expected,
                                  Object actual, Object... input) {
            super("Testcase: " + testCase + "\n expected = " + expected + ",\n actual = " + actual + ",\n " + Arrays.deepToString(input));
        }
    }

    private void assertThat(boolean b) {
        if (!b) throw new RuntimeException();
    }

    private void assertThat(boolean b, String s) {
        if (!b) throw new RuntimeException(s);
    }

    private int assertThatInt(long a) {
        assertThat(Integer.MIN_VALUE <= a && a <= Integer.MAX_VALUE);
        return (int) a;
    }

    void _______debug(String str, Object... os) {
        if (!ONLINE_JUDGE) {
            System.out.println(MessageFormat.format(str, os));
        }
    }

    void _______debug(Object o) {
        if (!ONLINE_JUDGE) {
            _______debug("{0}", String.valueOf(o));
        }
    }

    private int nextInt() {
        return System.in.readInt();
    }

    private long nextLong() {
        return System.in.readLong();
    }

    private String nextString() {
        return System.in.readString();
    }

    private int[] nextIntArr(int n) {
        return System.in.readIntArray(n);
    }

    private long[] nextLongArr(int n) {
        return System.in.readLongArray(n);
    }

    public static void main(String[] args) {
        new _C().run();
    }

    static class System {
        private static FastInputStream in;
        private static FastPrintStream out;
    }

    private void run() {
        final boolean USE_IO = ONLINE_JUDGE;
        if (USE_IO) {
            System.in = new FastInputStream(java.lang.System.in);
            System.out = new FastPrintStream(java.lang.System.out);
            solve();
            System.out.flush();
        } else {
            final String nameIn = "input.txt";
            final String nameOut = "output.txt";
            try {
                System.in = new FastInputStream(new FileInputStream(nameIn));
                System.out = new FastPrintStream(new PrintStream(nameOut));
                solve();
                System.out.flush();
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }
    }

    private static class FastPrintStream {
        private static final int BUF_SIZE = 8192;
        private final byte[] buf = new byte[BUF_SIZE];
        private final OutputStream out;
        private int ptr = 0;

        private FastPrintStream() {
            this(java.lang.System.out);
        }

        public FastPrintStream(OutputStream os) {
            this.out = os;
        }

        public FastPrintStream(String path) {
            try {
                this.out = new FileOutputStream(path);
            } catch (FileNotFoundException e) {
                throw new RuntimeException("FastWriter");
            }
        }

        public FastPrintStream print(byte b) {
            buf[ptr++] = b;
            if (ptr == BUF_SIZE) innerFlush();
            return this;
        }

        public FastPrintStream print(char c) {
            return print((byte) c);
        }

        public FastPrintStream print(char[] s) {
            for (char c : s) {
                buf[ptr++] = (byte) c;
                if (ptr == BUF_SIZE) innerFlush();
            }
            return this;
        }

        public FastPrintStream print(String s) {
            s.chars().forEach(c -> {
                buf[ptr++] = (byte) c;
                if (ptr == BUF_SIZE) innerFlush();
            });
            return this;
        }

        

        public FastPrintStream print0(char[] s) {
            if (ptr + s.length < BUF_SIZE) {
                for (char c : s) {
                    buf[ptr++] = (byte) c;
                }
            } else {
                for (char c : s) {
                    buf[ptr++] = (byte) c;
                    if (ptr == BUF_SIZE) innerFlush();
                }
            }
            return this;
        }

        

        public FastPrintStream print0(String s) {
            if (ptr + s.length() < BUF_SIZE) {
                for (int i = 0; i < s.length(); i++) {
                    buf[ptr++] = (byte) s.charAt(i);
                }
            } else {
                for (int i = 0; i < s.length(); i++) {
                    buf[ptr++] = (byte) s.charAt(i);
                    if (ptr == BUF_SIZE) innerFlush();
                }
            }
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

        public FastPrintStream print(int x) {
            if (x == Integer.MIN_VALUE) {
                return print((long) x);
            }
            if (ptr + 12 >= BUF_SIZE) innerFlush();
            if (x < 0) {
                print((byte) '-');
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

        public FastPrintStream print(long x) {
            if (x == Long.MIN_VALUE) {
                return print("" + x);
            }
            if (ptr + 21 >= BUF_SIZE) innerFlush();
            if (x < 0) {
                print((byte) '-');
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

        public FastPrintStream print(double x, int precision) {
            if (x < 0) {
                print('-');
                x = -x;
            }
            x += Math.pow(10, -precision) / 2;
            

            print((long) x).print(".");
            x -= (long) x;
            for (int i = 0; i < precision; i++) {
                x *= 10;
                print((char) ('0' + (int) x));
                x -= (int) x;
            }
            return this;
        }

        public FastPrintStream println(int[] a, int from, int upTo, char separator) {
            for (int i = from; i < upTo; i++) {
                print(a[i]);
                print(separator);
            }
            print('\n');
            return this;
        }

        public FastPrintStream println(int[] a) {
            return println(a, 0, a.length, ' ');
        }

        public FastPrintStream println(long[] a, int from, int upTo, char separator) {
            for (int i = from; i < upTo; i++) {
                print(a[i]);
                print(separator);
            }
            print('\n');
            return this;
        }

        public FastPrintStream println(long[] a) {
            return println(a, 0, a.length, ' ');
        }

        public FastPrintStream println(char c) {
            return print(c).println();
        }

        public FastPrintStream println(int x) {
            return print(x).println();
        }

        public FastPrintStream println(long x) {
            return print(x).println();
        }

        public FastPrintStream println(String x) {
            return print(x).println();
        }

        public FastPrintStream println(Object x) {
            return print(x.toString()).println();
        }

        public FastPrintStream println(double x, int precision) {
            return print(x, precision).println();
        }

        public FastPrintStream println() {
            return print((byte) '\n');
        }

        public FastPrintStream printf(String format, Object... args) {
            return print(String.format(format, args));
        }

        private void innerFlush() {
            try {
                out.write(buf, 0, ptr);
                ptr = 0;
            } catch (IOException e) {
                throw new RuntimeException("innerFlush");
            }
        }

        public void flush() {
            innerFlush();
            try {
                out.flush();
            } catch (IOException e) {
                throw new RuntimeException("flush");
            }
        }
    }

    private static class FastInputStream {
        private boolean finished = false;

        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private SpaceCharFilter filter;

        public FastInputStream(InputStream stream) {
            this.stream = stream;
        }

        public double[] readDoubleArray(int size) {
            double[] array = new double[size];
            for (int i = 0; i < size; i++) {
                array[i] = readDouble();
            }
            return array;
        }

        public String[] readStringArray(int size) {
            String[] array = new String[size];
            for (int i = 0; i < size; i++) {
                array[i] = readString();
            }
            return array;
        }

        public char[] readCharArray(int size) {
            char[] array = new char[size];
            for (int i = 0; i < size; i++) {
                array[i] = readCharacter();
            }
            return array;
        }

        public char[][] readTable(int rowCount, int columnCount) {
            char[][] table = new char[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = this.readCharArray(columnCount);
            }
            return table;
        }

        public int[][] readIntTable(int rowCount, int columnCount) {
            int[][] table = new int[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = readIntArray(columnCount);
            }
            return table;
        }

        public double[][] readDoubleTable(int rowCount, int columnCount) {
            double[][] table = new double[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = this.readDoubleArray(columnCount);
            }
            return table;
        }

        public long[][] readLongTable(int rowCount, int columnCount) {
            long[][] table = new long[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = readLongArray(columnCount);
            }
            return table;
        }

        public String[][] readStringTable(int rowCount, int columnCount) {
            String[][] table = new String[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = this.readStringArray(columnCount);
            }
            return table;
        }

        public String readText() {
            StringBuilder result = new StringBuilder();
            while (true) {
                int character = read();
                if (character == '\r') {
                    continue;
                }
                if (character == -1) {
                    break;
                }
                result.append((char) character);
            }
            return result.toString();
        }

        public void readStringArrays(String[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = readString();
                }
            }
        }

        public long[] readLongArray(int size) {
            long[] array = new long[size];
            for (int i = 0; i < size; i++) {
                array[i] = readLong();
            }
            return array;
        }

        public int[] readIntArray(int size) {
            int[] array = new int[size];
            for (int i = 0; i < size; i++) {
                array[i] = readInt();
            }
            return array;
        }

        public int read() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        public int peek() {
            if (numChars == -1) {
                return -1;
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    return -1;
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar];
        }

        public int peekNonWhitespace() {
            while (isWhitespace(peek())) {
                read();
            }
            return peek();
        }

        public int readInt() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public long readLong() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public String readString() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                if (Character.isValidCodePoint(c)) {
                    res.appendCodePoint(c);
                }
                c = read();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public boolean isSpaceChar(int c) {
            if (filter != null) {
                return filter.isSpaceChar(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        private String readLine0() {
            StringBuilder buf = new StringBuilder();
            int c = read();
            while (c != '\n' && c != -1) {
                if (c != '\r') {
                    buf.appendCodePoint(c);
                }
                c = read();
            }
            return buf.toString();
        }

        public String readLine() {
            String s = readLine0();
            while (s.trim().length() == 0) {
                s = readLine0();
            }
            return s;
        }

        public String readLine(boolean ignoreEmptyLines) {
            if (ignoreEmptyLines) {
                return readLine();
            } else {
                return readLine0();
            }
        }

        public char readCharacter() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            return (char) c;
        }

        public double readDouble() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            double res = 0;
            while (!isSpaceChar(c) && c != '.') {
                if (c == 'e' || c == 'E') {
                    return res * Math.pow(10, readInt());
                }
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            }
            if (c == '.') {
                c = read();
                double m = 1;
                while (!isSpaceChar(c)) {
                    if (c == 'e' || c == 'E') {
                        return res * Math.pow(10, readInt());
                    }
                    if (c < '0' || c > '9') {
                        throw new InputMismatchException();
                    }
                    m /= 10;
                    res += (c - '0') * m;
                    c = read();
                }
            }
            return res * sgn;
        }

        public boolean isExhausted() {
            int value;
            while (isSpaceChar(value = peek()) && value != -1) {
                read();
            }
            return value == -1;
        }

        public String next() {
            return readString();
        }

        public SpaceCharFilter getFilter() {
            return filter;
        }

        public void setFilter(SpaceCharFilter filter) {
            this.filter = filter;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);
        }
    }

}