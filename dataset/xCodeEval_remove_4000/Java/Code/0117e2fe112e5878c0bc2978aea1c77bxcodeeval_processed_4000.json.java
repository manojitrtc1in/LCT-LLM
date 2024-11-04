import java.io.*;
import java.text.MessageFormat;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Objects;
import java.util.Random;
import java.util.function.BiFunction;
import java.util.function.Predicate;


public class D {

    final boolean id13 = java.lang.System.getProperty("id13") != null;

    private String id18(int n, long[] a) {
        for (int l = 0; l < n; l++) {
            for (int r = 0; r < n; r++) {
                if (l < r) {
                    long max = Long.MIN_VALUE;
                    long sum = 0;
                    for (int i = l; i <= r; i++) {
                        max = Math.max(max, a[i]);
                        sum += a[i];
                    }
                    if (max < sum) {
                        return "NO";
                    }
                }
            }
        }
        return "YES";
    }

    private String id3(int testCase, int n, long[] a) {
        id24 st = new id24(a);
        id21 bit = new id21(a);
        for (int l = 0; l < n; l++) {
            for (int r = 0; r < n; r++) {
                if (l < r) {
                    if (st.get(l, r) < bit.get(l, r)) {
                        return "NO";
                    }
                }
            }
        }
        return "YES";
    }


    String id41(int testCase, int n, long[] a) {
        id24 id9 = new id24(a);
        int[] first = id22(a, id9);
        int[] last = id11(a, id9);

        long[] id20 = id20(a);
        long[] prefSum = prefSum(a);
        id24 id26 = new id24(id20);
        id24 id29 = new id24(prefSum);

        for(int i = 0; i < n; i++) {
            

            long exclude1 = i == n - 1 ? 0 : id20[i + 1];
            boolean id19 = a[i] >= id26.get(first[i], i) - exclude1;

            long exclude2 = i == 0 ? 0 : prefSum[i - 1];
            boolean id27 = a[i] >= id29.get(i, last[i]) - exclude2;


            if(!id19 || !id27) {
                return "NO";
            }
        }

        return "YES";
    }
    long[] id20(long[] a) {
        int n = a.length;
        long[] ans = new long[n];
        ans[n - 1] = a[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            ans[i] = ans[i + 1] + a[i];
        }
        return ans;
    }

    long[] prefSum(long[] a) {
        int n = a.length;
        long[] ans = new long[n];
        ans[0] = a[0];
        for(int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] + a[i];
        }
        return ans;
    }

    int[] id11(long[] a, id24 id9) {
        int n = a.length;
        int[] ans = new int[n];
        for(int i = 0; i < n; i++) {
            final int i_ = i;
            ans[i] = upperBound(i, n, ind -> id9.get(i_, ind) <= a[i_]);
        }

        return ans;
    }

    int[] id22(long[] a, id24 id9) {
        int n = a.length;
        int[] ans = new int[n];

        for(int i = 0; i < n; i++) {
            final int i_ = i;
            ans[i] = lowerBound(-1, i, ind -> id9.get(ind, i_) <= a[i_]);
        }

        return ans;
    }


    int upperBound(int inclusiveLeft, int exclusiveRight, Predicate<Integer> predicate) {
        while (exclusiveRight - inclusiveLeft > 1) {
            int middle = inclusiveLeft + (exclusiveRight - inclusiveLeft) / 2;
            if (predicate.test(middle)) {
                inclusiveLeft = middle;
            } else {
                exclusiveRight = middle;
            }
        }
        return inclusiveLeft;
    }

     int lowerBound(int exclusiveLeft, int inclusiveRight, Predicate<Integer> predicate) {
        while (inclusiveRight - exclusiveLeft > 1) {
            int middle = exclusiveLeft + (inclusiveRight - exclusiveLeft) / 2;
            if (predicate.test(middle)) {
                inclusiveRight = middle;
            } else {
                exclusiveLeft = middle;
            }
        }
        return inclusiveRight;
    }




    private String solveOne(int testCase, int n, long[] a) {




        id24 id9 = new id24(a);
        id17 id40 = new id17(n);
        id40.increment(0, 0, a[0]);
        for (int i = 1; i < n; i++) {






            id40.increment(0, i, a[i]);













            long maxPrev = id9.get(0, i - 1);
            if(maxPrev >= a[i]){
                id40.increment(i, i, maxPrev - a[i]);
            } else {
                maxPrev = a[i];
            }

            boolean invariant = maxPrev >= id40.max(0, i);
            if (!invariant) {
                return "NO";
            }


        }
        return "YES";
    }



    static class id17 {

        int n;
        Node head;

        id17(int n) {
            this.n = n;
            head = new Node(0, n);
        }

        static class Node {
            long max = 0;
            long pendingAdd = 0;

            Node l;
            Node r;

            final int tl;
            final int tr;

            public Node(int tl, int tr) {
                this.tl = tl;
                this.tr = tr;
            }

        }

        enum Turn {
            LEFT, RIGHT
        }

        private void id31(Node p, Turn turn) {
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

        public void increment(int l, int r, long delta) {
            increment(l, r, delta, head);
        }

        private void increment(int l, int r, long val, Node v) {
            int tl = v.tl, tr = v.tr;
            if (l > r) {
                return;
            }
            if (l == tl && r == tr) {
                applyPending(v, val);
                return;
            }
            int tm = (tl + tr) >>> 1;
            id28(v);
            increment(l, Math.min(r, tm), val, v.l);
            increment(Math.max(l, tm + 1), r, val, v.r);
            v.max = Math.max(getValue(v.l), getValue(v.r));
        }

        private long getValue(Node v) {
            return v.pendingAdd + v.max;
        }

        private void id28(Node v) {
            id31(v, Turn.LEFT);
            id31(v, Turn.RIGHT);

            if (v.pendingAdd != 0) {
                v.max += v.pendingAdd;
                applyPending(v.l, v.pendingAdd);
                applyPending(v.r, v.pendingAdd);
                v.pendingAdd = 0;
            }
        }

        private void applyPending(Node v, long val) {
            v.pendingAdd += val;
        }

        public long max(int l, int r) {
            return max(l, r, head);
        }

        public long max(int l, int r, Node v) {
            int tl = v.tl, tr = v.tr;
            if (l > r) {
                return Long.MIN_VALUE;
            }

            if (l == tl && r == tr) {
                return getValue(v);
            }
            int tm = (tl + tr) >>> 1;
            id28(v);
            long res_l = max(l, Math.min(r, tm), v.l);
            long res_r = max(Math.max(l, tm + 1), r, v.r);
            return Math.max(res_l, res_r);
        }


    }


    static class id24 {

        

        public static final BiFunction<Long, Long, Long> MAX = Math::max;



        BiFunction<Long, Long, Long> FUNC = MAX;

        int LOG = 20;
        long[][] id32;

        public id24(long[] arr) {
            int n = arr.length;
            id32 = new long[n][LOG];
            for (int i = 0; i < n; i++) {
                id32[i][0] = arr[i];
            }
            for (int j = 1; j < LOG; j++) {
                for (int i = 0; i + (1 << j) - 1 < n; i++) {
                    id32[i][j] = FUNC.apply(id32[i][j - 1], id32[i + (1 << (j - 1))][j - 1]);
                }
            }
        }

        private long get(int l, int r) {
            int len = r - l + 1;
            int p = 0;
            while ((1 << (p + 1)) <= len) {
                p++;
            }
            return FUNC.apply(id32[l][p], id32[r - (1 << p) + 1][p]);
        }

    }

    private String id14(int n, long[] a) {

        if (allPos(a)) {
            return "NO";
        } else if (allNeg(a)) {
            return "YES";
        } else {
            for (int i = 0; i < n - 1; i++) {
                if (Math.max(a[i], a[i + 1]) < a[i] + a[i + 1]) {
                    return "NO";
                }
            }
            for (int i = 0; i < n - 2; i++) {
                if (Math.max(Math.max(a[i], a[i + 1]), a[i + 2]) < a[i] + a[i + 1] + a[i + 2]) {
                    return "NO";
                }
            }
            id24 st = new id24(a);
            id21 bit = new id21(a);
            Random r = new Random(42);
            for (int i = 0; i < 64 * n; i++) {
                int u = r.nextInt(n);
                int v = r.nextInt(n);
                int from = Math.min(u, v);
                int upTo = Math.max(u, v);
                if (st.get(from, upTo) < bit.get(from, upTo)) {
                    return "NO";
                }
            }
            if (st.get(0, n - 1) < bit.get(0, n - 1)) {
                return "NO";
            }


            return "YES";

        }

    }

    private boolean allNeg(long[] a) {
        boolean res = true;
        for (long i : a) res &= i <= 0;
        return res;
    }

    private boolean allPos(long[] a) {
        boolean res = true;
        for (long i : a) res &= i > 0;
        return res;
    }


    static class id21 {
        private final long[] value;

        public id21(int size) {
            value = new long[size];
        }

        public id21(long[] a) {
            int size = a.length;
            value = new long[size];
            for (int i = 0; i < size; i++) {
                add(i, a[i]);
            }

        }

        public long get(int from, int to) {
            if (from > to) {
                return 0;
            }
            return get(to) - get(from - 1);
        }

        private long get(int to) {
            long result = 0;
            while (to >= 0) {
                result += value[to];
                to = (to & (to + 1)) - 1;
            }
            return result;
        }

        public void add(int at, long value) {
            while (at < this.value.length) {
                this.value[at] += value;
                at = at | (at + 1);
            }
        }
    }

    boolean id25 = false;

    private void solve() {
        if (id25) {
            Random r = new Random(42);
            for (int testCase = 1; testCase <= 10000; testCase++) {
                int n = r.nextInt(500) + 5;
                long[] a = new long[n];
                for (int j = 0; j < n; j++) {
                    a[j] = -20 + r.nextInt(40);
                }
                String expected = id3(testCase, n, a);
                String actual = id41(testCase, n, a);




                if (!Objects.equals(expected, actual)) {
                    throw new id6(
                            testCase,
                            expected,
                            actual,
                            n, a);
                }
            }
        } else {
            int t = nextInt();
            for (int tt = 0; tt < t; tt++) {
                int n = nextInt();
                long[] a = id42(n);


                String actual = id41(tt, n, a);


                System.out.println(actual);
            }
        }
    }

    class id6 extends RuntimeException {

        id6(int testCase,
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

    private int id30(long a) {
        assertThat(Integer.MIN_VALUE <= a && a <= Integer.MAX_VALUE);
        return (int) a;
    }

    void _______debug(String str, Object... os) {
        if (!id13) {
            System.out.println(MessageFormat.format(str, os));
        }
    }

    void _______debug(Object o) {
        if (!id13) {
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

    private int[] id37(int n) {
        return System.in.id1(n);
    }

    private long[] id42(int n) {
        return System.in.id15(n);
    }

    public static void main(String[] args) {
        new D().run();
    }

    static class System {
        private static id16 in;
        private static id33 out;
    }

    private void run() {
        final boolean USE_IO = id13;
        if (USE_IO) {
            System.in = new id16(java.lang.System.in);
            System.out = new id33(java.lang.System.out);
            solve();
            System.out.flush();
        } else {
            final String nameIn = "input.txt";
            final String nameOut = "output.txt";
            try {
                System.in = new id16(new FileInputStream(nameIn));
                System.out = new id33(new PrintStream(nameOut));
                solve();
                System.out.flush();
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }
    }

    private static class id33 {
        private static final int BUF_SIZE = 8192;
        private final byte[] buf = new byte[BUF_SIZE];
        private final OutputStream out;
        private int ptr = 0;

        private id33() {
            this(java.lang.System.out);
        }

        public id33(OutputStream os) {
            this.out = os;
        }

        public id33(String path) {
            try {
                this.out = new FileOutputStream(path);
            } catch (FileNotFoundException e) {
                throw new RuntimeException("FastWriter");
            }
        }

        public id33 print(byte b) {
            buf[ptr++] = b;
            if (ptr == BUF_SIZE) innerFlush();
            return this;
        }

        public id33 print(char c) {
            return print((byte) c);
        }

        public id33 print(char[] s) {
            for (char c : s) {
                buf[ptr++] = (byte) c;
                if (ptr == BUF_SIZE) innerFlush();
            }
            return this;
        }

        public id33 print(String s) {
            s.chars().forEach(c -> {
                buf[ptr++] = (byte) c;
                if (ptr == BUF_SIZE) innerFlush();
            });
            return this;
        }

        

        public id33 print0(char[] s) {
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

        

        public id33 print0(String s) {
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

        public id33 print(int x) {
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

        public id33 print(long x) {
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

        public id33 print(double x, int precision) {
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

        public id33 println(int[] a, int from, int upTo, char separator) {
            for (int i = from; i < upTo; i++) {
                print(a[i]);
                print(separator);
            }
            print('\n');
            return this;
        }

        public id33 println(int[] a) {
            return println(a, 0, a.length, ' ');
        }

        public id33 println(long[] a, int from, int upTo, char separator) {
            for (int i = from; i < upTo; i++) {
                print(a[i]);
                print(separator);
            }
            print('\n');
            return this;
        }

        public id33 println(long[] a) {
            return println(a, 0, a.length, ' ');
        }

        public id33 println(char c) {
            return print(c).println();
        }

        public id33 println(int x) {
            return print(x).println();
        }

        public id33 println(long x) {
            return print(x).println();
        }

        public id33 println(String x) {
            return print(x).println();
        }

        public id33 println(Object x) {
            return print(x.toString()).println();
        }

        public id33 println(double x, int precision) {
            return print(x, precision).println();
        }

        public id33 println() {
            return print((byte) '\n');
        }

        public id33 printf(String format, Object... args) {
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

    private static class id16 {
        private boolean finished = false;

        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private id39 filter;

        public id16(InputStream stream) {
            this.stream = stream;
        }

        public double[] id4(int size) {
            double[] array = new double[size];
            for (int i = 0; i < size; i++) {
                array[i] = readDouble();
            }
            return array;
        }

        public String[] id36(int size) {
            String[] array = new String[size];
            for (int i = 0; i < size; i++) {
                array[i] = readString();
            }
            return array;
        }

        public char[] id7(int size) {
            char[] array = new char[size];
            for (int i = 0; i < size; i++) {
                array[i] = readCharacter();
            }
            return array;
        }

        public char[][] readTable(int rowCount, int columnCount) {
            char[][] table = new char[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = this.id7(columnCount);
            }
            return table;
        }

        public int[][] id12(int rowCount, int columnCount) {
            int[][] table = new int[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = id1(columnCount);
            }
            return table;
        }

        public double[][] id0(int rowCount, int columnCount) {
            double[][] table = new double[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = this.id4(columnCount);
            }
            return table;
        }

        public long[][] id2(int rowCount, int columnCount) {
            long[][] table = new long[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = id15(columnCount);
            }
            return table;
        }

        public String[][] id34(int rowCount, int columnCount) {
            String[][] table = new String[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = this.id36(columnCount);
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

        public void id23(String[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = readString();
                }
            }
        }

        public long[] id15(int size) {
            long[] array = new long[size];
            for (int i = 0; i < size; i++) {
                array[i] = readLong();
            }
            return array;
        }

        public int[] id1(int size) {
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

        public int id38() {
            while (isWhitespace(peek())) {
                read();
            }
            return peek();
        }

        public int readInt() {
            int c = read();
            while (id10(c)) {
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
            } while (!id10(c));
            return res * sgn;
        }

        public long readLong() {
            int c = read();
            while (id10(c)) {
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
            } while (!id10(c));
            return res * sgn;
        }

        public String readString() {
            int c = read();
            while (id10(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                if (Character.isValidCodePoint(c)) {
                    res.appendCodePoint(c);
                }
                c = read();
            } while (!id10(c));
            return res.toString();
        }

        public boolean id10(int c) {
            if (filter != null) {
                return filter.id10(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        private String id5() {
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
            String s = id5();
            while (s.trim().length() == 0) {
                s = id5();
            }
            return s;
        }

        public String readLine(boolean id35) {
            if (id35) {
                return readLine();
            } else {
                return id5();
            }
        }

        public char readCharacter() {
            int c = read();
            while (id10(c)) {
                c = read();
            }
            return (char) c;
        }

        public double readDouble() {
            int c = read();
            while (id10(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            double res = 0;
            while (!id10(c) && c != '.') {
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
                while (!id10(c)) {
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

        public boolean id8() {
            int value;
            while (id10(value = peek()) && value != -1) {
                read();
            }
            return value == -1;
        }

        public String next() {
            return readString();
        }

        public id39 getFilter() {
            return filter;
        }

        public void setFilter(id39 filter) {
            this.filter = filter;
        }

        public interface id39 {
            public boolean id10(int ch);
        }
    }

}