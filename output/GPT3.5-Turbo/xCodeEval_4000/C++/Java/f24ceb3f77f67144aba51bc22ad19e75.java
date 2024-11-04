import java.io.*;
import java.util.*;

class Main {
    static class Input {
        private boolean exhausted = false;
        private int bufSize = 4096;
        private char[] buf = new char[bufSize];
        private int bufRead = 0;
        private int bufAt = 0;
        private BufferedReader br;

        public Input() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        private int get() throws IOException {
            if (exhausted) {
                return -1;
            }
            if (bufRead == bufAt) {
                bufRead = br.read(buf, 0, bufSize);
                bufAt = 0;
            }
            if (bufRead == bufAt) {
                exhausted = true;
                return -1;
            }
            return buf[bufAt++];
        }

        private int peek() throws IOException {
            if (exhausted) {
                return -1;
            }
            if (bufRead == bufAt) {
                bufRead = br.read(buf, 0, bufSize);
                bufAt = 0;
            }
            if (bufRead == bufAt) {
                exhausted = true;
                return -1;
            }
            return buf[bufAt];
        }

        private int skipWhitespace() throws IOException {
            int c;
            while (Character.isWhitespace(c = get()) && c != -1);
            return c;
        }

        public int readInt() throws IOException {
            int c = skipWhitespace();
            int sign = 1;
            if (c == '-') {
                sign = -1;
                c = get();
            } else if (c == '+') {
                c = get();
            }
            int res = 0;
            do {
                if (!Character.isDigit(c)) {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = get();
            } while (!Character.isWhitespace(c));
            return res * sign;
        }

        public long readLong() throws IOException {
            int c = skipWhitespace();
            int sign = 1;
            if (c == '-') {
                sign = -1;
                c = get();
            } else if (c == '+') {
                c = get();
            }
            long res = 0;
            do {
                if (!Character.isDigit(c)) {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = get();
            } while (!Character.isWhitespace(c));
            return res * sign;
        }

        public String readString() throws IOException {
            int c = skipWhitespace();
            if (c == -1) {
                throw new NoSuchElementException();
            }
            StringBuilder sb = new StringBuilder();
            do {
                sb.append((char) c);
                c = get();
            } while (!Character.isWhitespace(c));
            return sb.toString();
        }

        public int[] readIntArray(int size) throws IOException {
            int[] array = new int[size];
            for (int i = 0; i < size; i++) {
                array[i] = readInt();
            }
            return array;
        }

        public long[] readLongArray(int size) throws IOException {
            long[] array = new long[size];
            for (int i = 0; i < size; i++) {
                array[i] = readLong();
            }
            return array;
        }

        public double[] readDoubleArray(int size) throws IOException {
            double[] array = new double[size];
            for (int i = 0; i < size; i++) {
                array[i] = readDouble();
            }
            return array;
        }

        public String[] readStringArray(int size) throws IOException {
            String[] array = new String[size];
            for (int i = 0; i < size; i++) {
                array[i] = readString();
            }
            return array;
        }

        public char[] readCharArray(int size) throws IOException {
            char[] array = new char[size];
            for (int i = 0; i < size; i++) {
                array[i] = (char) readInt();
            }
            return array;
        }

        public double readDouble() throws IOException {
            int c = skipWhitespace();
            int sign = 1;
            if (c == '-') {
                sign = -1;
                c = get();
            } else if (c == '+') {
                c = get();
            }
            double res = 0;
            do {
                if (!Character.isDigit(c)) {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = get();
            } while (!Character.isWhitespace(c) && c != '.');
            if (c == '.') {
                double add = 0;
                int length = 0;
                c = get();
                do {
                    if (!Character.isDigit(c)) {
                        throw new InputMismatchException();
                    }
                    add *= 10;
                    add += c - '0';
                    length++;
                    c = get();
                } while (!Character.isWhitespace(c));
                res += add / Math.pow(10, length);
            }
            return res * sign;
        }

        public char readChar() throws IOException {
            int c = skipWhitespace();
            if (c == -1) {
                throw new NoSuchElementException();
            }
            return (char) c;
        }

        public boolean isExhausted() {
            return exhausted;
        }

        public void close() throws IOException {
            br.close();
        }
    }

    static class Output {
        private PrintWriter pw;

        public Output() {
            pw = new PrintWriter(System.out);
        }

        public void print(Object obj) {
            pw.print(obj);
        }

        public void println(Object obj) {
            pw.println(obj);
        }

        public void flush() {
            pw.flush();
        }

        public void close() {
            pw.close();
        }
    }

    static class BVerkhnyayaYacheika {
        private static final int MOD7 = 1000000007;
        private static final int MOD9 = 1000000009;
        private static final int MODF = 998244353;

        private int mod = MOD7;

        private long gcd(long a, long b, long[] x, long[] y) {
            if (a == 0) {
                x[0] = 0;
                y[0] = 1;
                return b;
            }
            long[] x1 = new long[1];
            long[] y1 = new long[1];
            long d = gcd(b % a, a, x1, y1);
            x[0] = y1[0] - (b / a) * x1[0];
            y[0] = x1[0];
            return d;
        }

        private static class ModInt {
            private int n;

            public ModInt() {
                n = 0;
            }

            public ModInt(long n, boolean special) {
                if (special) {
                    this.n = -1;
                    return;
                }
                if (n >= 0 && n < mod) {
                    this.n = (int) n;
                    return;
                }
                n %= mod;
                if (n < 0) {
                    n += mod;
                }
                this.n = (int) n;
            }

            public ModInt add(ModInt other) {
                if (n == -1 || other.n == -1) {
                    throw new IllegalStateException();
                }
                n += other.n;
                if (n >= mod) {
                    n -= mod;
                }
                return this;
            }

            public ModInt subtract(ModInt other) {
                if (n == -1 || other.n == -1) {
                    throw new IllegalStateException();
                }
                n -= other.n;
                if (n < 0) {
                    n += mod;
                }
                return this;
            }

            public ModInt multiply(ModInt other) {
                if (n == -1 || other.n == -1) {
                    throw new IllegalStateException();
                }
                n = (int) ((long) n * other.n % mod);
                return this;
            }

            public ModInt divide(ModInt other) {
                if (other.n == 0) {
                    throw new ArithmeticException("Division by zero");
                }
                if (n == -1 || other.n == -1) {
                    throw new IllegalStateException();
                }
                return multiply(other.inverse());
            }

            public ModInt negate() {
                if (n == -1) {
                    throw new IllegalStateException();
                }
                if (n == 0) {
                    return new ModInt(0, false);
                }
                return new ModInt(mod - n, false);
            }

            public ModInt inverse() {
                if (n == -1) {
                    throw new IllegalStateException();
                }
                long[] x = new long[1];
                long[] y = new long[1];
                long g = gcd(n, mod, x, y);
                if (g != 1) {
                    throw new ArithmeticException("Not inversable");
                }
                return new ModInt(x[0], false);
            }

            @Override
            public String toString() {
                return Integer.toString(n);
            }
        }

        public void solve() throws IOException {
            Input in = new Input();
            Output out = new Output();

            int n = in.readInt();
            int m = in.readInt();

            mod = m;
            ModInt[] ft = new ModInt[n + 1];
            ft[n] = new ModInt(1, false);
            for (int i = n - 1; i >= 1; i--) {
                ModInt res = ft[i + 1];
                for (int z = 2; z * i <= n; z++) {
                    res = res.add(ft[z * i].subtract(ft[z * i + z]));
                }
                ft[i] = res;
            }
            out.println(ft[1].subtract(ft[2]));

            in.close();
            out.flush();
            out.close();
        }
    }

    public static void main(String[] args) throws IOException {
        BVerkhnyayaYacheika solver = new BVerkhnyayaYacheika();
        solver.solve();
    }
}
