import java.io.*;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.TreeMap;


public class id3 {

    private long MOD = 998_244_353;

    private void solveOne() {
        int n = nextInt();
        int[] a = id27(n);
        

        TreeMap<Integer, Integer> tree = new TreeMap<>();
        for (int i : a) {
            tree.merge(i, 1, Integer::sum);
        }
        int M1 = tree.lastKey();
        if (tree.get(M1) > 1) {
            

            long ans = 1;
            for (int i = 1; i <= n; i++) {
                ans *= i;
                ans %= MOD;
            }
            System.out.println(ans);
        } else {
            tree.remove(M1);
            int M2 = tree.lastKey();
            if (M2 + 1 < M1) {
                System.out.println(0);
            } else {
                long ans = 0;
                

                int id15 = tree.get(M2);
                int id19 = n - 1 - id15;
                for (int i = n - 2; i >= 0; i--) {
                    int R = n - (i + 1);
                    int L = i;
                    

                    long localAns = fact[n - 1] * rev_fact[n - 1 - R];
                    localAns = posModule(localAns);

                    

                    

                    if (R <= id19) {
                        localAns -= fact[id19] * rev_fact[id19 - R];
                        localAns = posModule(localAns);
                    }
                    localAns *= fact[L];
                    localAns = posModule(localAns);
                    ans += localAns;
                    ans = posModule(ans);
                }
                System.out.println(ans);
            }
        }

    }

    long[] fact;
    long[] rev_fact;

    long posModule(long x) {
        return (x % MOD + MOD) % MOD;
    }

    class id21 {
        int n;
        long[] fact;
        long[] rev_fact;

        id21(int n, long MOD) {
            this.n = n;
            fact = new long[n + 1];
            rev_fact = new long[n + 1];
            calculate();
        }

        void calculate() {
            fact[0] = 1;
            for (int i = 1; i <= n; i++) {
                fact[i] = fact[i - 1] * i;
                fact[i] %= MOD;
            }
            for (int i = 0; i <= n; i++) {
                rev_fact[i] = id20(fact[i], MOD);
            }
        }

        public long[] getFact() {
            return fact;
        }

        public long[] id18() {
            return rev_fact;
        }
    }

    private long powMod(long base, long exp, long mod) {
        long ans = 1;
        while (exp > 0) {
            if ((exp & 1) == 1) {
                ans *= base;
                ans %= mod;
            }
            base *= base;
            base %= mod;
            exp >>= 1;
        }
        return ans;
    }

    private long id20(long a, long mod) {
        return powMod(a, mod - 2, mod);
    }

    private void solve() {
        id21 id4 = new id21((int) 2e5, MOD);
        fact = id4.getFact();
        rev_fact = id4.id18();
        int t = nextInt();
        for (int tt = 0; tt < t; tt++) {
            solveOne();
        }
    }

    class id7 extends RuntimeException {

        id7(Object expected,
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
        private static id23 out;
    }

    private void run() {
        System.in = new id13(java.lang.System.in);
        System.out = new id23(java.lang.System.out);
        solve();
        System.out.flush();
    }

    private static class id23 {
        private static final int BUF_SIZE = 8192;
        private final byte[] buf = new byte[BUF_SIZE];
        private final OutputStream out;
        private int ptr = 0;

        private id23() {
            this(java.lang.System.out);
        }

        public id23(OutputStream os) {
            this.out = os;
        }

        public id23(String path) {
            try {
                this.out = new FileOutputStream(path);
            } catch (FileNotFoundException e) {
                throw new RuntimeException("FastWriter");
            }
        }

        public id23 print(byte b) {
            buf[ptr++] = b;
            if (ptr == BUF_SIZE) innerflush();
            return this;
        }

        public id23 print(char c) {
            return print((byte) c);
        }

        public id23 print(char[] s) {
            for (char c : s) {
                buf[ptr++] = (byte) c;
                if (ptr == BUF_SIZE) innerflush();
            }
            return this;
        }

        public id23 print(String s) {
            s.chars().forEach(c -> {
                buf[ptr++] = (byte) c;
                if (ptr == BUF_SIZE) innerflush();
            });
            return this;
        }

        

        public id23 print0(char[] s) {
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

        

        public id23 print0(String s) {
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

        public id23 print(int x) {
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

        public id23 print(long x) {
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

        public id23 print(double x, int precision) {
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

        public id23 println(int[] a, int from, int upTo, char separator) {
            for (int i = from; i < upTo; i++) {
                print(a[i]);
                print(separator);
            }
            print('\n');
            return this;
        }

        public id23 println(int[] a) {
            return println(a, 0, a.length, ' ');
        }

        public id23 println(char c) {
            return print(c).println();
        }

        public id23 println(int x) {
            return print(x).println();
        }

        public id23 println(long x) {
            return print(x).println();
        }

        public id23 println(String x) {
            return print(x).println();
        }

        public id23 println(double x, int precision) {
            return print(x, precision).println();
        }

        public id23 println() {
            return print((byte) '\n');
        }

        public id23 printf(String format, Object... args) {
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

        public double[] id5(int size) {
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

        public char[] id8(int size) {
            char[] array = new char[size];
            for (int i = 0; i < size; i++) {
                array[i] = readCharacter();
            }
            return array;
        }

        public void id14(int[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = readInt();
                }
            }
        }

        public void id16(long[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = readLong();
                }
            }
        }

        public void id22(double[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = readDouble();
                }
            }
        }

        public char[][] readTable(int rowCount, int columnCount) {
            char[][] table = new char[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = this.id8(columnCount);
            }
            return table;
        }

        public int[][] id11(int rowCount, int columnCount) {
            int[][] table = new int[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = id1(columnCount);
            }
            return table;
        }

        public double[][] id0(int rowCount, int columnCount) {
            double[][] table = new double[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = this.id5(columnCount);
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

        public String[][] id24(int rowCount, int columnCount) {
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

        public void id17(String[]... arrays) {
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

        private String id6() {
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
            String s = id6();
            while (s.trim().length() == 0) {
                s = id6();
            }
            return s;
        }

        public String readLine(boolean id25) {
            if (id25) {
                return readLine();
            } else {
                return id6();
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

        public boolean id9() {
            int value;
            while (id10(value = peek()) && value != -1) {
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
            public boolean id10(int ch);
        }
    }

}