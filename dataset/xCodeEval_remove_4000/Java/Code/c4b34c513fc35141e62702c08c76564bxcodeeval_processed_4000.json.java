import java.io.*;
import java.text.*;
import java.util.*;


public class TemplateFast {

    final boolean id9 = true;

    final boolean id14 = false;
    final Random random = new Random(42);

    private int solveOne(int testCase) {
        int n = nextInt();

        int id13 = -1;
        int id10 = -1;
        int[] r = new int[n];
        for (int i = 0; i < n; i++) {
            int a = (i - 2 + n) % n;
            int b = (i - 1 + n) % n;
            int c = i;
            r[i] = query(a, b, c);
        }
        for(int i = 0 ; i < n; i++) {
            int prev = (i - 1 + n) % n;
            if(id13 == -1) {
                if(r[prev] == 1 && r[i] == 0) {
                    id13 = i;
                }
            }
            if(id10 == -1) {
                if(r[prev] == 0 && r[i] == 1) {
                    id10 = i;
                }
            }
        }
        Set<Integer> set = new TreeSet<>();
        set.add(id13);
        for(int i = 0; i < n; i++) {
            if(id13 != i && id10 != i){
                int res = query(id13, id10, i);
                if(res == 0) {
                    set.add(i);
                }
            }
        }
        System.out.print('!');
        System.out.print(' ');
        System.out.print(set.size());
        for(int s : set) {
            System.out.print(' ');
            System.out.print(s + 1);
        }
        System.out.println();
        System.out.flush();



        return 0;
    }

    int query(int a, int b, int c) {
        System.out.print('?');
        System.out.print(' ');
        System.out.print(a + 1);
        System.out.print(' ');
        System.out.print(b + 1);
        System.out.print(' ');
        System.out.print(c + 1);
        System.out.println();
        System.out.flush();
        int r = nextInt();
        if(r == -1) {
            throw new RuntimeException(a + " - " + b + " - " + c);
        }
        return r;
    }

    private int id8(int testCase) {
        return 0;
    }

    private void solve() {
        if (id14) {
            int t = 100_000;
            for (int testCase = 0; testCase < t; testCase++) {
                int expected = id8(testCase);
                int actual = solveOne(testCase);
                if (expected != actual) {
                    throw new id4(
                            this.getClass().getSimpleName(),
                            testCase,
                            expected,
                            actual);
                }
            }
        } else {
            int t = nextInt();
            for (int testCase = 0; testCase < t; testCase++) {
                solveOne(testCase);
            }
        }
    }

    class id4 extends RuntimeException {

        id4(String testName,
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

    private int id15(long a) {
        assertThat(Integer.MIN_VALUE <= a && a <= Integer.MAX_VALUE,
                "Integer overflow long = [" + a + "]" + " int = [" + (int) a + "]");
        return (int) a;
    }

    void _______debug(String str, Object... os) {
        if (!id9) {
            System.out.println(MessageFormat.format(str, os));
            System.out.flush();
        }
    }

    void _______debug(Object o) {
        if (!id9) {
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

    private int[] id19(int n) {
        return System.in.id0(n);
    }

    private long[] id22(int n) {
        return System.in.id11(n);
    }

    public static void main(String[] args) {
        new TemplateFast().run();
    }

    static class System {
        private static id12 in;
        private static id16 out;
    }

    private void run() {


        final boolean USE_IO = id9;
        if (USE_IO) {
            System.in = new id12(java.lang.System.in);
            System.out = new id16(java.lang.System.out);
            solve();
            System.out.flush();
        } else {
            final String nameIn = "input.txt";
            final String nameOut = "output.txt";
            try {
                System.in = new id12(new FileInputStream(nameIn));
                System.out = new id16(new PrintStream(nameOut));
                solve();
                System.out.flush();
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }




    }

    private static class id16 {
        private static final int BUF_SIZE = 8192;
        private final byte[] buf = new byte[BUF_SIZE];
        private final OutputStream out;
        private int ptr = 0;

        private id16() {
            this(java.lang.System.out);
        }

        public id16(OutputStream os) {
            this.out = os;
        }

        public id16(String path) {
            try {
                this.out = new FileOutputStream(path);
            } catch (FileNotFoundException e) {
                throw new RuntimeException("FastWriter");
            }
        }

        public id16 print(byte b) {
            buf[ptr++] = b;
            if (ptr == BUF_SIZE) innerFlush();
            return this;
        }

        public id16 print(char c) {
            return print((byte) c);
        }

        public id16 print(char[] s) {
            for (char c : s) {
                buf[ptr++] = (byte) c;
                if (ptr == BUF_SIZE) innerFlush();
            }
            return this;
        }

        public id16 print(String s) {
            s.chars().forEach(c -> {
                buf[ptr++] = (byte) c;
                if (ptr == BUF_SIZE) innerFlush();
            });
            return this;
        }

        

        public id16 print0(char[] s) {
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

        

        public id16 print0(String s) {
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

        public id16 print(int x) {
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

        public id16 print(long x) {
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

        public id16 print(double x, int precision) {
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

        public id16 println(char c) {
            return print(c).println();
        }

        public id16 println(int x) {
            return print(x).println();
        }

        public id16 println(long x) {
            return print(x).println();
        }

        public id16 println(String x) {
            return print(x).println();
        }

        public id16 println(Object x) {
            return print(x.toString()).println();
        }

        public id16 println(double x, int precision) {
            return print(x, precision).println();
        }

        public id16 println() {
            return print((byte) '\n');
        }

        public id16 printf(String format, Object... args) {
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

    private static class id12 {
        private boolean finished = false;

        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private id21 filter;

        public id12(InputStream stream) {
            this.stream = stream;
        }

        public double[] id2(int size) {
            double[] array = new double[size];
            for (int i = 0; i < size; i++) {
                array[i] = readDouble();
            }
            return array;
        }

        public String[] id18(int size) {
            String[] array = new String[size];
            for (int i = 0; i < size; i++) {
                array[i] = readString();
            }
            return array;
        }

        public char[] id5(int size) {
            char[] array = new char[size];
            for (int i = 0; i < size; i++) {
                array[i] = readCharacter();
            }
            return array;
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

        public long[] id11(int size) {
            long[] array = new long[size];
            for (int i = 0; i < size; i++) {
                array[i] = readLong();
            }
            return array;
        }

        public int[] id0(int size) {
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

        public int id20() {
            while (isWhitespace(peek())) {
                read();
            }
            return peek();
        }

        public int readInt() {
            int c = read();
            while (id7(c)) {
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
            } while (!id7(c));
            return res * sgn;
        }

        public long readLong() {
            int c = read();
            while (id7(c)) {
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
            } while (!id7(c));
            return res * sgn;
        }

        public String readString() {
            int c = read();
            while (id7(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                if (Character.isValidCodePoint(c)) {
                    res.appendCodePoint(c);
                }
                c = read();
            } while (!id7(c));
            return res.toString();
        }

        public char[] id1() {
            int c = read();
            while (id7(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                if (Character.isValidCodePoint(c)) {
                    res.appendCodePoint(c);
                }
                c = read();
            } while (!id7(c));
            char[] resArr = new char[res.length()];
            res.getChars(0, res.length(), resArr, 0);
            return resArr;
        }

        public boolean id7(int c) {
            if (filter != null) {
                return filter.id7(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        private String id3() {
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
            String s = id3();
            while (s.trim().length() == 0) {
                s = id3();
            }
            return s;
        }

        public String readLine(boolean id17) {
            if (id17) {
                return readLine();
            } else {
                return id3();
            }
        }

        public char readCharacter() {
            int c = read();
            while (id7(c)) {
                c = read();
            }
            return (char) c;
        }

        public double readDouble() {
            int c = read();
            while (id7(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            double res = 0;
            while (!id7(c) && c != '.') {
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
                while (!id7(c)) {
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

        public boolean id6() {
            int value;
            while (id7(value = peek()) && value != -1) {
                read();
            }
            return value == -1;
        }

        public String next() {
            return readString();
        }

        public id21 getFilter() {
            return filter;
        }

        public void setFilter(id21 filter) {
            this.filter = filter;
        }

        public interface id21 {
            public boolean id7(int ch);
        }
    }

}