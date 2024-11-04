


import java.io.*;
import java.util.InputMismatchException;


public class id13 {

    private void solve_() {

        int n = reader.readInt();
        int[] a = reader.id1(n);
        int[] b = reader.id1(n);



































        id2 id14 = new id2(n);


        for (int i = 0; i < n; i++) {
            id14.union(a[i] - 1, b[i] - 1);






















        }
        int ans = 1;
        int amount = id14.amount;
        for (int i = 0; i < amount; i++) {
            ans *= 2;
            ans %= 1_000_000_007;
        }


        writer.println(ans);


    }

    class id2 {
        private int[] rank, parent;
        private int amount;

        public id2(int amount) {
            this.rank = new int[amount];
            this.parent = new int[amount];
            this.amount = amount;
            for (int i = 0; i < amount; i++) {
                parent[i] = i;
            }
        }

        public boolean id10(int u, int v) {
            return find(u) == find(v);
        }

        private int find(int v) {
            if (v == parent[v])
                return v;
            return parent[v] = find(parent[v]);
        }

        public void union(int x, int y) {
            

            int xRoot = find(x), yRoot = find(y);

            

            

            if (xRoot == yRoot)
                return;

            

            if (rank[xRoot] < rank[yRoot])

                

                

                parent[xRoot] = yRoot;

                

            else if (rank[xRoot] > rank[yRoot])

                

                

                parent[yRoot] = xRoot;

            else 

            {
                

                

                parent[yRoot] = xRoot;

                

                

                rank[xRoot]++;
            }
            amount--;
        }

        public int getAmount() {
            return amount;
        }
    }


    private void solve() {
        int t = reader.readInt();
        for (int i = 0; i < t; i++) {
            solve_();
        }
    }

    public static void main(String[] args) {
        new id13().run();
    }

    private InputReader reader;
    private FastWriter writer;

    private void run() {
        reader = new InputReader(System.in);
        writer = new FastWriter(System.out);
        solve();
        writer.flush();
    }

    private static class FastWriter {
        private static final int BUF_SIZE = 8192;

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

    private static class InputReader {
        private boolean finished = false;

        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private id22 filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public double[] id4(int size) {
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

        public char[] id6(int size) {
            char[] array = new char[size];
            for (int i = 0; i < size; i++) {
                array[i] = readCharacter();
            }
            return array;
        }
































        public void id12(int[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = readInt();
                }
            }
        }

        public void id15(long[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = readLong();
                }
            }
        }

        public void id17(double[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = readDouble();
                }
            }
        }

        public char[][] readTable(int rowCount, int columnCount) {
            char[][] table = new char[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = this.id6(columnCount);
            }
            return table;
        }

        public int[][] id9(int rowCount, int columnCount) {
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

        public long[][] id3(int rowCount, int columnCount) {
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

        public void id16(String[]... arrays) {
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

        public int id21() {
            while (isWhitespace(peek())) {
                read();
            }
            return peek();
        }

        public int readInt() {
            int c = read();
            while (id8(c)) {
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
            } while (!id8(c));
            return res * sgn;
        }

        public long readLong() {
            int c = read();
            while (id8(c)) {
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
            } while (!id8(c));
            return res * sgn;
        }

        public String readString() {
            int c = read();
            while (id8(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                if (Character.isValidCodePoint(c)) {
                    res.appendCodePoint(c);
                }
                c = read();
            } while (!id8(c));
            return res.toString();
        }

        public boolean id8(int c) {
            if (filter != null) {
                return filter.id8(c);
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

        public String readLine(boolean id19) {
            if (id19) {
                return readLine();
            } else {
                return id5();
            }
        }

        public char readCharacter() {
            int c = read();
            while (id8(c)) {
                c = read();
            }
            return (char) c;
        }

        public double readDouble() {
            int c = read();
            while (id8(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            double res = 0;
            while (!id8(c) && c != '.') {
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
                while (!id8(c)) {
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

        public boolean id7() {
            int value;
            while (id8(value = peek()) && value != -1) {
                read();
            }
            return value == -1;
        }

        public String next() {
            return readString();
        }

        public id22 getFilter() {
            return filter;
        }

        public void setFilter(id22 filter) {
            this.filter = filter;
        }

        public interface id22 {
            public boolean id8(int ch);
        }
    }

}