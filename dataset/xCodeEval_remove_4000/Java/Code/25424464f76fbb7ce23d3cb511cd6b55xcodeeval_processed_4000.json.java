

import java.io.*;
import java.util.Arrays;
import java.util.InputMismatchException;


public class C {

    int n;
    long[] h = new long[200_001];
    long[] buffer = new long[200_001];

    private void solveOne() {
        n = nextInt();
        for (int i = 0; i < n; i++) {
            h[i] = nextLong();
        }
        



        long ans = 0;
        long border = 1_000_000_000_000L;
        while (border - ans > 1) {
            long mid = ans + (border - ans) / 2;
            if (pos(mid)) {
                ans = mid;
            } else {
                border = mid;
            }
        }


        












        System.out.println(ans);

    }

    boolean pos(long min) {
        

        

        for(int i = 0 ; i < n ; i ++ ) {
            buffer[i] = h[i];
        }

        for (int i = n - 1; i >= 2; i--) {

            

            


            

            if (buffer[i] < min) {
                return false;
            }
            long id17 = (buffer[i] - min) / 3 * 3;
            id17 = Math.min(id17, h[i] / 3 * 3);









            buffer[i] -= id17;
            buffer[i - 1] += id17 / 3;
            buffer[i - 2] += id17 / 3 * 2;
        }

        return buffer[0] >= min && buffer[1] >= min;
    }

    private void solve() {
        int t = System.in.readInt();
        for (int tt = 0; tt < t; tt++) {
            solveOne();
        }
    }

    class id5 extends RuntimeException {

        id5(Object expected,
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

    private int[] id21(int n) {
        return System.in.id1(n);
    }

    private long[] id24(int n) {
        return System.in.id11(n);
    }


    public static void main(String[] args) {
        new C().run();
    }

    static class System {
        private static id12 in;
        private static id6 out;
    }

    private void run() {
        System.in = new id12(java.lang.System.in);
        System.out = new id6(java.lang.System.out);
        solve();
        System.out.flush();
    }

    

    private static class id12 {
        private boolean finished = false;

        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private id23 filter;

        public id12(InputStream stream) {
            this.stream = stream;
        }

        public double[] id3(int size) {
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

        public char[] id7(int size) {
            char[] array = new char[size];
            for (int i = 0; i < size; i++) {
                array[i] = readCharacter();
            }
            return array;
        }

        public void id13(int[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = readInt();
                }
            }
        }

        public void id14(long[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = readLong();
                }
            }
        }

        public void id16(double[]... arrays) {
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
                table[i] = this.id3(columnCount);
            }
            return table;
        }

        public long[][] id2(int rowCount, int columnCount) {
            long[][] table = new long[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = id11(columnCount);
            }
            return table;
        }

        public String[][] id18(int rowCount, int columnCount) {
            String[][] table = new String[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = this.id20(columnCount);
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

        public void id15(String[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = readString();
                }
            }
        }

        public long[] id11(int size) {
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

        private String id4() {
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
            String s = id4();
            while (s.trim().length() == 0) {
                s = id4();
            }
            return s;
        }

        public String readLine(boolean id19) {
            if (id19) {
                return readLine();
            } else {
                return id4();
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

        public id23 getFilter() {
            return filter;
        }

        public void setFilter(id23 filter) {
            this.filter = filter;
        }

        public interface id23 {
            public boolean id9(int ch);
        }
    }


    public static class id6 {
        private static final int BUF_SIZE = 2_000_000;

        private final byte[] buf = new byte[BUF_SIZE];
        private final OutputStream out;
        private int ptr = 0;

        private id6() {
            this.out = java.lang.System.out;
        }

        public id6(OutputStream os) {
            this.out = os;
        }

        public id6(String path) {
            try {
                this.out = new FileOutputStream(path);
            } catch (FileNotFoundException e) {
                throw new RuntimeException("FastWriter");
            }
        }

        public id6 write(byte b) {
            buf[ptr++] = b;
            return this;
        }

        public id6 write(char c) {
            return write((byte) c);
        }

        public id6 write(char[] s) {
            for (char c : s) {
                buf[ptr++] = (byte) c;
            }
            return this;
        }

        public id6 write(String s) {
            s.chars().forEach(c -> {
                buf[ptr++] = (byte) c;
            });
            return this;
        }

        

        public id6 print0(char[] s) {

            for (int i = 0, n = s.length; i < n; i++) {
                buf[ptr++] = (byte) s[i];
            }

            return this;
        }

        

        public id6 print0(String s) {

            for (int i = 0, n = s.length(); i < n; i++) {
                buf[ptr++] = (byte) s.charAt(i);
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

        public id6 write(int x) {
            if (x == Integer.MIN_VALUE) {
                return write((long) x);
            }
            

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

        public id6 write(long x) {
            if (x == Long.MIN_VALUE) {
                return write("" + x);
            }


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

        public id6 write(double x, int precision) {
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

        public id6 writeln(char c) {
            return write(c).writeln();
        }

        public id6 writeln(int x) {
            return write(x).writeln();
        }

        public id6 writeln(long x) {
            return write(x).writeln();
        }

        public id6 writeln(double x, int precision) {
            return write(x, precision).writeln();
        }

        public id6 write(int... xs) {
            boolean first = true;
            for (int x : xs) {
                if (!first) write(' ');
                first = false;
                write(x);
            }
            return this;
        }

        public id6 write(long... xs) {
            boolean first = true;
            for (long x : xs) {
                if (!first) write(' ');
                first = false;
                write(x);
            }
            return this;
        }

        public id6 writeln() {
            return write((byte) '\n');
        }

        public id6 writeln(int... xs) {
            return write(xs).writeln();
        }

        public id6 writeln(long... xs) {
            return write(xs).writeln();
        }

        public id6 writeln(char[] line) {
            return write(line).writeln();
        }

        public id6 writeln(char[]... map) {
            for (char[] line : map) write(line).writeln();
            return this;
        }

        public id6 writeln(String s) {
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

        public id6 print(byte b) {
            return write(b);
        }

        public id6 print(char c) {
            return write(c);
        }

        public id6 print(char[] s) {
            return write(s);
        }

        public id6 print(String s) {
            return write(s);
        }

        public id6 print(int x) {
            return write(x);
        }

        public id6 print(long x) {
            return write(x);
        }

        public id6 print(double x, int precision) {
            return write(x, precision);
        }

        public id6 println(char c) {
            return writeln(c);
        }

        public id6 println(int x) {
            return writeln(x);
        }

        public id6 println(long x) {
            return writeln(x);
        }

        public id6 println(double x, int precision) {
            return writeln(x, precision);
        }

        public id6 print(int... xs) {
            return write(xs);
        }

        public id6 print(long... xs) {
            return write(xs);
        }

        public id6 println(int... xs) {
            return writeln(xs);
        }

        public id6 println(long... xs) {
            return writeln(xs);
        }

        public id6 println(char[] line) {
            return writeln(line);
        }

        public id6 println(char[]... map) {
            return writeln(map);
        }

        public id6 println(String s) {
            return writeln(s);
        }

        public id6 println() {
            return writeln();
        }
    }
}