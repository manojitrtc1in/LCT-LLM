import java.io.*;
import java.text.MessageFormat;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Random;
import java.util.function.IntFunction;
import java.util.function.IntUnaryOperator;
import java.util.function.Predicate;


public class C {

    final boolean id12 = java.lang.System.getProperty("id12") != null;

     int id10(int n, char[] s, int[] segment){
         int ans = Integer.MAX_VALUE;
         int ones = 0;
         int zeros = 0;
         for(int i = 0; i < n ; i  ++) {
             if(s[i] == '1') ones++; else zeros++;
         }
         for(int l = 0; l < n; l++) {
             for (int r = 0; r < n; r++) {
                 if(l <= r) {
                     int remainingZeros = zeros;
                     int id25 = 0;
                     for(int i = 0; i < l; i++) {
                         if(s[i] == '1') id25++; else remainingZeros--;
                     }

                     for(int i = r + 1; i < n; i++) {
                         if(s[i] == '1') id25++; else remainingZeros--;
                     }
                     int localAns = Math.max(remainingZeros, id25);
                     if(ans > localAns) {
                         ans = localAns;
                         segment[0] = l;
                         segment[1] = r;
                     }
                 }
             }
         }
         {
            int localAns = Math.max(zeros, 0);
             if(ans > localAns) {
                 ans = localAns;
                 segment[0] = 0;
                 segment[1] = n - 1;
             }
         }
         {
             int localAns = Math.max(0, ones);
             if(ans > localAns) {
                 ans = localAns;
                 segment[0] = -1;
                 segment[1] = -1;
             }
         }
         return ans;
     }

    private int solveOne(int n, char[] s) {
        int[] p0 = new int[n];
        int[] p1 = new int[n];
        p0[0] = s[0] == '0' ? 1 : 0;
        p1[0] = s[0] == '1' ? 1 : 0;

        int[] s0 = new int[n];
        int[] s1 = new int[n];
        s0[n - 1] = s[n - 1] == '0' ? 1 : 0;
        s1[n - 1] = s[n - 1] == '1' ? 1 : 0;

        for (int i = 1; i < n; i++) {
            p0[i] = p0[i - 1] + (s[i] == '0' ? 1 : 0);
            p1[i] = p1[i - 1] + (s[i] == '1' ? 1 : 0);
        }

        for (int i = n - 2; i >= 0; i--) {
            s0[i] = s0[i + 1] + (s[i] == '0' ? 1 : 0);
            s1[i] = s1[i + 1] + (s[i] == '1' ? 1 : 0);
        }

        int ans = Math.min(s0[0], s1[0]);
        for (int i = -1; i < n; i++) {
            

            int id25 = i == -1 ? 0 : p1[i];
            int id20 = i == -1 ? p0[n - 1] : p0[n - 1] - p0[i];

            int localAns = Math.max(id25, id20);
            IntUnaryOperator ansFor = ind -> Math.max(id25 + s1[ind], id20 - s0[ind]);
            

            if (i < n - 1) {
                int j = upperBound(
                        i,
                        n,
                        ind -> id25 + s1[ind] >= id20 - s0[ind]);
                localAns = Math.min(localAns, ansFor.applyAsInt(j));
            } else {
                

            }
            ans = Math.min(ans, localAns);
        }
        return ans;
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
        return upperBound(exclusiveLeft, inclusiveRight, predicate.negate()) + 1;
    }

    private int id19(int left, int right, IntFunction<Integer> func) {
        while (right - left > 2) {
            int mid1 = left + (right - left) / 3;
            int mid2 = right - (right - left) / 3;
            if (func.apply(mid1) < func.apply(mid2)) {
                right = mid2;
            } else {
                left = mid1;
            }
        }
        return left;
    }

    

    

    

    

    

    

    

    

    

    

    

    

    

    


    private void id23() {
        

        char[] s = nextString().toCharArray();
        int n = s.length;
        int leftOne = -1;
        int rightOne = n;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                leftOne = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '1') {
                rightOne = i;
                break;
            }
        }

        if (leftOne == -1) {
            System.out.println(0);
            return;
        }

        

        

        int id25 = 0;
        int id20 = 0;
        for (int i = leftOne; i <= rightOne; i++) {
            if (s[i] == '0') {
                id20++;
            }
        }
        

        int ans = Math.max(id25, id20);

        

        int[] id3 = new int[n];
        int[] id18 = new int[n];
        int[] nextRight = new int[n];
        {
            int cur1 = 0;
            int cur0 = 0;
            int id26 = -1;
            for (int i = leftOne; i < n; i++) {
                if ((i == 0 || s[i - 1] == '0') && s[i] == '1') {
                    id26 = i;
                    cur1 = 0;
                    cur0 = 0;
                }
                if (s[i] == '1') {
                    cur1++;
                }
                if (s[i] == '0') {
                    cur0++;
                }

                if (s[i] == '0' && (i == n - 1 || s[i + 1] == '1')) {
                    id3[id26] = cur1;
                    id18[id26] = cur0;
                    nextRight[id26] = i + 1;
                }
            }
        }
        int[] id32 = new int[n];
        int[] id15 = new int[n];
        int[] nextLeft = new int[n];

        {
            int cur1 = 0;
            int cur0 = 0;
            int id26 = -1;
            for (int i = rightOne; i >= 0; i--) {
                if ((i == n - 1 || s[i + 1] == '0') && s[i] == '1') {
                    id26 = i;
                    cur1 = 0;
                    cur0 = 0;
                }
                if (s[i] == '1') {
                    cur1++;
                }
                if (s[i] == '0') {
                    cur0++;
                }

                if (s[i] == '0' && (i == 0 || s[i - 1] == '1')) {
                    id32[id26] = cur1;
                    id15[id26] = cur0;
                    nextLeft[id26] = i - 1;
                }
            }
        }












        for (int l = leftOne, r = rightOne; ; ) {

            if (nextRight[l] > r) {
                

                break;
            }

            

            int id14 = Math.max(id25 + id3[l], id20 - id18[l]);
            int id13 = Math.max(id25 + id32[r], id20 - id15[r]);
            if (id14 < ans || id13 < ans) {
                if (id13 <= id14) {
                    id25 += id32[r];
                    id20 -= id15[r];
                    r = nextLeft[r];
                } else {
                    id25 += id3[l];
                    id20 -= id18[l];
                    l = nextRight[l];
                }
                ans = Math.max(id25, id20);
            } else {
                break;
            }

        }

        System.out.println(ans);


    }



    boolean id24 = false;

    private void solve() {
        if (!id24) {
            int t = nextInt();
            for (int tt = 0; tt < t; tt++) {
                char[] s = nextString().toCharArray();
                int n = s.length;
                int ans = solveOne(n, s);
                System.out.println(ans);
            }
        } else {
            Random r = new Random(42);
            for(int testCase = 0; testCase < 10_000; testCase++) {
                int n = 5 + r.nextInt(5);
                char[] s = new char[n];
                for(int i = 0; i  < n; i ++) {
                    s[i] = r.nextBoolean() ? '1' : '0';
                }
                int[] segment = new int[2];
                int expected = id10(n, s, segment);
                int actual = solveOne(n, s);
                if(expected != actual) {
                    throw new id6(testCase,
                            expected, actual, n, s, segment);
                }
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

    private int id22(long a) {
        assertThat(Integer.MIN_VALUE <= a && a <= Integer.MAX_VALUE);
        return (int) a;
    }

    void _______debug(String str, Object... os) {
        if (!id12) {
            System.out.println(MessageFormat.format(str, os));
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

    private int[] id31(int n) {
        return System.in.id1(n);
    }

    private long[] id35(int n) {
        return System.in.id16(n);
    }

    public static void main(String[] args) {
        new C().run();
    }

    static class System {
        private static id17 in;
        private static id27 out;
    }

    private void run() {
        final boolean USE_IO = id12;
        if (USE_IO) {
            System.in = new id17(java.lang.System.in);
            System.out = new id27(java.lang.System.out);
            solve();
            System.out.flush();
        } else {
            final String nameIn = "input.txt";
            final String nameOut = "output.txt";
            try {
                System.in = new id17(new FileInputStream(nameIn));
                System.out = new id27(new PrintStream(nameOut));
                solve();
                System.out.flush();
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }
    }

    private static class id27 {
        private static final int BUF_SIZE = 8192;
        private final byte[] buf = new byte[BUF_SIZE];
        private final OutputStream out;
        private int ptr = 0;

        private id27() {
            this(java.lang.System.out);
        }

        public id27(OutputStream os) {
            this.out = os;
        }

        public id27(String path) {
            try {
                this.out = new FileOutputStream(path);
            } catch (FileNotFoundException e) {
                throw new RuntimeException("FastWriter");
            }
        }

        public id27 print(byte b) {
            buf[ptr++] = b;
            if (ptr == BUF_SIZE) innerFlush();
            return this;
        }

        public id27 print(char c) {
            return print((byte) c);
        }

        public id27 print(char[] s) {
            for (char c : s) {
                buf[ptr++] = (byte) c;
                if (ptr == BUF_SIZE) innerFlush();
            }
            return this;
        }

        public id27 print(String s) {
            s.chars().forEach(c -> {
                buf[ptr++] = (byte) c;
                if (ptr == BUF_SIZE) innerFlush();
            });
            return this;
        }

        

        public id27 print0(char[] s) {
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

        

        public id27 print0(String s) {
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

        public id27 print(int x) {
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

        public id27 print(long x) {
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

        public id27 print(double x, int precision) {
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

        public id27 println(int[] a, int from, int upTo, char separator) {
            for (int i = from; i < upTo; i++) {
                print(a[i]);
                print(separator);
            }
            print('\n');
            return this;
        }

        public id27 println(int[] a) {
            return println(a, 0, a.length, ' ');
        }

        public id27 println(long[] a, int from, int upTo, char separator) {
            for (int i = from; i < upTo; i++) {
                print(a[i]);
                print(separator);
            }
            print('\n');
            return this;
        }

        public id27 println(long[] a) {
            return println(a, 0, a.length, ' ');
        }

        public id27 println(char c) {
            return print(c).println();
        }

        public id27 println(int x) {
            return print(x).println();
        }

        public id27 println(long x) {
            return print(x).println();
        }

        public id27 println(String x) {
            return print(x).println();
        }

        public id27 println(Object x) {
            return print(x.toString()).println();
        }

        public id27 println(double x, int precision) {
            return print(x, precision).println();
        }

        public id27 println() {
            return print((byte) '\n');
        }

        public id27 printf(String format, Object... args) {
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

    private static class id17 {
        private boolean finished = false;

        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private id34 filter;

        public id17(InputStream stream) {
            this.stream = stream;
        }

        public double[] id4(int size) {
            double[] array = new double[size];
            for (int i = 0; i < size; i++) {
                array[i] = readDouble();
            }
            return array;
        }

        public String[] id30(int size) {
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
                table[i] = this.id4(columnCount);
            }
            return table;
        }

        public long[][] id2(int rowCount, int columnCount) {
            long[][] table = new long[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = id16(columnCount);
            }
            return table;
        }

        public String[][] id28(int rowCount, int columnCount) {
            String[][] table = new String[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = this.id30(columnCount);
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

        public void id21(String[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = readString();
                }
            }
        }

        public long[] id16(int size) {
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

        public int id33() {
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

        public String readLine(boolean id29) {
            if (id29) {
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

        public id34 getFilter() {
            return filter;
        }

        public void setFilter(id34 filter) {
            this.filter = filter;
        }

        public interface id34 {
            public boolean id9(int ch);
        }
    }

}