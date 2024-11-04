import java.io.*;
import java.util.Arrays;
import java.util.InputMismatchException;


public class id3 {

    id11 segmentTree = new id11();
    int MAXN = (int) 1e9;
    long LIMIT = (long) 2e9;

    private long ans(int n) {
        return segmentTree.sum(0, n);
    }

    private void precompute() {
        long a, a2;
        for (a = 2, a2 = a * a; a2 <= LIMIT; a++, a2 = a * a) {
            

            

            


            


            long minB = a;
            long maxC = a2 - minB;
            

            if((maxC + 1 - minB) % 2 == 0) {
                long minC = (maxC + 1 + minB) / 2;
                if (minC <= MAXN) {
                    int l = (int) minC;
                    segmentTree.increment(l, l, 1);
                }
            }
        }




    }

    private void solveOne() {
        int n = nextInt();
        System.out.println(ans(n));
    }

    private void solve() {
        precompute();
        int t = nextInt();
        for (int tt = 0; tt < t; tt++) {
            solveOne();
        }
    }


    

    

    static class id11 implements id19 {

        static int id14 = 0;

        static long DEFAULT = (long) 1e18;

        int n = (int) 1e9;


        Node head;
        id11() {
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
                id14++;
            }

            public int len() {
                return tr + 1 - tl;
            }
        }

        enum Turn {
            LEFT, RIGHT
        }

        private void id20(Node p, Turn turn) {
            int tl = p.tl;
            int tr = p.tr;
            int tm = (tl + tr) >>> 1;
            if (turn == Turn.LEFT && p.l == null) {
                p.l = new Node(tl, tm);
            }

            if (turn == Turn.RIGHT && p.r == null){
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
                id24(v, value);
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
                id16(v, val);
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


            id20(v, Turn.LEFT);
            id20(v, Turn.RIGHT);

            if (v.add_mod != 0) {
                v.t += v.add_mod;
                v.sum += v.add_mod * v.len();

                id16(v.l, v.add_mod);

                id16(v.r, v.add_mod);
                v.add_mod = 0;
            }
            if (v.set_mod != DEFAULT) {
                v.t = v.set_mod;
                v.sum = v.set_mod * v.len();

                id24(v.l, v.set_mod);

                id24(v.r, v.set_mod);
                v.set_mod = DEFAULT;
            }
        }

        private void id16(Node v, long val) {
            if (v.set_mod != DEFAULT) {
                v.set_mod += val;
            } else {
                v.add_mod += val;
            }
        }

        private void id24(Node v, long val) {
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

    }

    interface id19 {

        void set(int l, int r, long value);

        void increment(int l, int r, long delta);

        long sum(int l, int r);

    }

    private static void assertTrue(boolean assertion, String msg) {
        if (!assertion) {
            throw new RuntimeException(msg);
        }
    }

    class id6 extends RuntimeException {

        id6(Object expected,
                                  Object actual, Object... input) {
            super("expected = " + expected + ",\n actual = " + actual + ",\n " + Arrays.deepToString(input));
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

    private int[] id27(int n) {
        return System.in.id1(n);
    }

    private long[] id30(int n) {
        return System.in.id12(n);
    }

    public static void main(String[] args) {
        new id3().run();
    }

    static class System {
        private static id13 in;
        private static id22 out;
    }

    private void run() {
        System.in = new id13(java.lang.System.in);
        System.out = new id22(java.lang.System.out);
        solve();
        System.out.flush();
    }

    private static class id22 {
        private static final int BUF_SIZE = 8192;
        private final byte[] buf = new byte[BUF_SIZE];
        private final OutputStream out;
        private int ptr = 0;

        private id22() {
            this(java.lang.System.out);
        }

        public id22(OutputStream os) {
            this.out = os;
        }

        public id22(String path) {
            try {
                this.out = new FileOutputStream(path);
            } catch (FileNotFoundException e) {
                throw new RuntimeException("FastWriter");
            }
        }

        public id22 print(byte b) {
            buf[ptr++] = b;
            if (ptr == BUF_SIZE) innerflush();
            return this;
        }

        public id22 print(char c) {
            return print((byte) c);
        }

        public id22 print(char[] s) {
            for (char c : s) {
                buf[ptr++] = (byte) c;
                if (ptr == BUF_SIZE) innerflush();
            }
            return this;
        }

        public id22 print(String s) {
            s.chars().forEach(c -> {
                buf[ptr++] = (byte) c;
                if (ptr == BUF_SIZE) innerflush();
            });
            return this;
        }

        

        public id22 print0(char[] s) {
            if (ptr + s.length < BUF_SIZE) {
                for (char c : s) {
                    buf[ptr++] = (byte) c;
                }
            } else {
                for (char c : s) {
                    buf[ptr++] = (byte) c;
                    if (ptr == BUF_SIZE) innerflush();
                }
            }
            return this;
        }

        

        public id22 print0(String s) {
            if (ptr + s.length() < BUF_SIZE) {
                for (int i = 0; i < s.length(); i++) {
                    buf[ptr++] = (byte) s.charAt(i);
                }
            } else {
                for (int i = 0; i < s.length(); i++) {
                    buf[ptr++] = (byte) s.charAt(i);
                    if (ptr == BUF_SIZE) innerflush();
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

        public id22 print(int x) {
            if (x == Integer.MIN_VALUE) {
                return print((long) x);
            }
            if (ptr + 12 >= BUF_SIZE) innerflush();
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

        public id22 print(long x) {
            if (x == Long.MIN_VALUE) {
                return print("" + x);
            }
            if (ptr + 21 >= BUF_SIZE) innerflush();
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

        public id22 print(double x, int precision) {
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

        public id22 println(int[] a, int from, int upTo, char separator) {
            for (int i = from; i < upTo; i++) {
                print(a[i]);
                print(separator);
            }
            print('\n');
            return this;
        }

        public id22 println(int[] a) {
            return println(a, 0, a.length, ' ');
        }

        public id22 println(char c) {
            return print(c).println();
        }

        public id22 println(int x) {
            return print(x).println();
        }

        public id22 println(long x) {
            return print(x).println();
        }

        public id22 println(String x) {
            return print(x).println();
        }

        public id22 println(double x, int precision) {
            return print(x, precision).println();
        }

        public id22 println() {
            return print((byte) '\n');
        }

        public id22 printf(String format, Object... args) {
            return print(String.format(format, args));
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
    }

    private static class id13 {
        private boolean finished = false;

        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private id29 filter;

        public id13(InputStream stream) {
            this.stream = stream;
        }

        public double[] id4(int size) {
            double[] array = new double[size];
            for (int i = 0; i < size; i++) {
                array[i] = readDouble();
            }
            return array;
        }

        public String[] id26(int size) {
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

        public void id15(int[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = readInt();
                }
            }
        }

        public void id17(long[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = readLong();
                }
            }
        }

        public void id21(double[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = readDouble();
                }
            }
        }

        public char[][] readTable(int rowCount, int columnCount) {
            char[][] table = new char[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = this.id7(columnCount);
            }
            return table;
        }

        public int[][] id10(int rowCount, int columnCount) {
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
                table[i] = id12(columnCount);
            }
            return table;
        }

        public String[][] id23(int rowCount, int columnCount) {
            String[][] table = new String[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = this.id26(columnCount);
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

        public void id18(String[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = readString();
                }
            }
        }

        public long[] id12(int size) {
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

        public int id28() {
            while (isWhitespace(peek())) {
                read();
            }
            return peek();
        }

        public int readInt() {
            int c = read();
            while (id9(c)) {
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
            } while (!id9(c));
            return res * sgn;
        }

        public long readLong() {
            int c = read();
            while (id9(c)) {
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
            } while (!id9(c));
            return res * sgn;
        }

        public String readString() {
            int c = read();
            while (id9(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                if (Character.isValidCodePoint(c)) {
                    res.appendCodePoint(c);
                }
                c = read();
            } while (!id9(c));
            return res.toString();
        }

        public boolean id9(int c) {
            if (filter != null) {
                return filter.id9(c);
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

        public String readLine(boolean id25) {
            if (id25) {
                return readLine();
            } else {
                return id5();
            }
        }

        public char readCharacter() {
            int c = read();
            while (id9(c)) {
                c = read();
            }
            return (char) c;
        }

        public double readDouble() {
            int c = read();
            while (id9(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            double res = 0;
            while (!id9(c) && c != '.') {
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
                while (!id9(c)) {
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
            while (id9(value = peek()) && value != -1) {
                read();
            }
            return value == -1;
        }

        public String next() {
            return readString();
        }

        public id29 getFilter() {
            return filter;
        }

        public void setFilter(id29 filter) {
            this.filter = filter;
        }

        public interface id29 {
            public boolean id9(int ch);
        }
    }

}