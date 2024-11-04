import java.io.*;
import java.text.*;
import java.util.*;
import java.util.function.*;


public class id0 {

    final boolean id12 = java.lang.System.getProperty("id12") != null;
    final boolean id16 = false;
    final Random r = new Random(42);
    Interactor interactor = id12 ? new CFInteractor() : new MockInteractor();

    

    private int solveOne(int testCase, int n) {

        interactor.setUp(n);
        

        int secondIndex = interactor.id2(1, n);
        int len = upperBound(0, n, delta -> {
                    int l = Math.max(1, secondIndex - delta);
                    int r = Math.min(secondIndex + delta, n);
                    return secondIndex != interactor.id2(l, r);
                }
        );
        

        

        int l = Math.max(1, secondIndex - len) - 1;
        int r = Math.min(secondIndex + len, n) + 1;
        if (1 <= l) {
            if(interactor.id2(l, secondIndex) == secondIndex){
                interactor.id15(l);
            } else {
                interactor.id15(r);
            }
        }
        else if(r <= n) {
            if(interactor.id2(secondIndex, r) == secondIndex){
                interactor.id15(r);
            } else interactor.id15(l);
        }







        return 0;
    }

    interface Interactor {
        void setUp(int n);

        void id15(int i);

        int id2(int l, int r);
    }

    class CFInteractor implements Interactor {
        public void setUp(int n) {

        }

        public void id15(int i) {
            System.out.printf("! %d\n", i);
            System.out.flush();
        }

        public int id2(int l, int r) {
            System.out.printf("? %d %d\n", l, r);
            System.out.flush();
            return nextInt();
        }
    }

    class MockInteractor implements Interactor {

        int[] a;
        int n;
        int maxInd;
        int tries;
        


        public void setUp(int n) {
            tries = 0;
            a = new int[n + 1];
            this.n = n;







            for (int i = 1; i <= n; i++) {
                a[i] = i;
            }
            for (int i = 1; i <= n; i++) {
                int j = 1 + r.nextInt(n);
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }

            int max = Integer.MIN_VALUE;
            for (int i = 1; i <= n; i++) {
                if (a[i] > max) {
                    max = a[i];
                    maxInd = i;
                }
            }
            System.out.println(Arrays.toString(a));
            

        }

        public void id15(int i) {
            if (i != maxInd) {
                throw new RuntimeException();
            } else {
                System.out.printf("OK %d\n", i);
            }
        }

        public int id2(int l, int r) {
            if(tries + 1 > 20) {
                throw new RuntimeException("LIMIT");
            }
            tries++;
            int max = Integer.MIN_VALUE;
            

            for (int i = l; i <= r; i++) {
                if (a[i] > max) {
                    max = a[i];
                    

                }
            }
            int max_ = Integer.MIN_VALUE;
            int id4 = -1;
            for (int i = l; i <= r; i++) {
                if (a[i] > max_ && a[i] != max) {
                    max_ = a[i];
                    id4 = i;
                }
            }
            return id4;
        }
    }

    private int upperBound(int inclusiveLeft, int exclusiveRight, Predicate<Integer> predicate) {
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

    private int lowerBound(int exclusiveLeft, int inclusiveRight, Predicate<Integer> predicate) {
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

    private int id11(int testCase) {
        return 0;
    }

    private void solve() {
        if (id16) {
            int t = 100_000;
            for (int testCase = 0; testCase < t; testCase++) {


                int actual = solveOne(testCase, 10);














            }
        } else {
            int t = 1;

            for (int testCase = 0; testCase < t; testCase++) {
                int n = nextInt();
                solveOne(testCase, n);
            }
        }
    }

    class id7 extends RuntimeException {

        id7(String testName,
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

    private int id17(long a) {
        assertThat(Integer.MIN_VALUE <= a && a <= Integer.MAX_VALUE,
                "Integer overflow long = [" + a + "]" + " int = [" + (int) a + "]");
        return (int) a;
    }

    void _______debug(String str, Object... os) {
        if (!id12) {
            System.out.println(MessageFormat.format(str, os));
            System.out.flush();
        }
    }

    void _______debug(Object o) {
        if (!id12) {
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

    private int[] id21(int n) {
        return System.in.id1(n);
    }

    private long[] id24(int n) {
        return System.in.id13(n);
    }

    public static void main(String[] args) {
        new id0().run();
    }

    static class System {
        private static id14 in;
        private static id18 out;
    }

    private void run() {


        final boolean USE_IO = id12;
        if (USE_IO) {
            System.in = new id14(java.lang.System.in);
            System.out = new id18(java.lang.System.out);
            solve();
            System.out.flush();
        } else {
            final String nameIn = "input.txt";
            final String nameOut = "output.txt";
            try {
                System.in = new id14(new FileInputStream(nameIn));
                System.out = new id18(new PrintStream(nameOut));
                solve();
                System.out.flush();
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }




    }

    private static class id18 {
        private static final int BUF_SIZE = 8192;
        private final byte[] buf = new byte[BUF_SIZE];
        private final OutputStream out;
        private int ptr = 0;

        private id18() {
            this(java.lang.System.out);
        }

        public id18(OutputStream os) {
            this.out = os;
        }

        public id18(String path) {
            try {
                this.out = new FileOutputStream(path);
            } catch (FileNotFoundException e) {
                throw new RuntimeException("FastWriter");
            }
        }

        public id18 print(byte b) {
            buf[ptr++] = b;
            if (ptr == BUF_SIZE) innerFlush();
            return this;
        }

        public id18 print(char c) {
            return print((byte) c);
        }

        public id18 print(char[] s) {
            for (char c : s) {
                buf[ptr++] = (byte) c;
                if (ptr == BUF_SIZE) innerFlush();
            }
            return this;
        }

        public id18 print(String s) {
            s.chars().forEach(c -> {
                buf[ptr++] = (byte) c;
                if (ptr == BUF_SIZE) innerFlush();
            });
            return this;
        }

        

        public id18 print0(char[] s) {
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

        

        public id18 print0(String s) {
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

        public id18 print(int x) {
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

        public id18 print(long x) {
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

        public id18 print(double x, int precision) {
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

        public id18 println(char c) {
            return print(c).println();
        }

        public id18 println(int x) {
            return print(x).println();
        }

        public id18 println(long x) {
            return print(x).println();
        }

        public id18 println(String x) {
            return print(x).println();
        }

        public id18 println(Object x) {
            return print(x.toString()).println();
        }

        public id18 println(double x, int precision) {
            return print(x, precision).println();
        }

        public id18 println() {
            return print((byte) '\n');
        }

        public id18 printf(String format, Object... args) {
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

    private static class id14 {
        private boolean finished = false;

        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private id23 filter;

        public id14(InputStream stream) {
            this.stream = stream;
        }

        public double[] id5(int size) {
            double[] array = new double[size];
            for (int i = 0; i < size; i++) {
                array[i] = readDouble();
            }
            return array;
        }

        public String[] id20(int size) {
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

        public long[] id13(int size) {
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

        public int id22() {
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

        public char[] id3() {
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
            char[] resArr = new char[res.length()];
            res.getChars(0, res.length(), resArr, 0);
            return resArr;
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

        public String readLine(boolean id19) {
            if (id19) {
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

        public id23 getFilter() {
            return filter;
        }

        public void setFilter(id23 filter) {
            this.filter = filter;
        }

        public interface id23 {
            public boolean id10(int ch);
        }
    }

}