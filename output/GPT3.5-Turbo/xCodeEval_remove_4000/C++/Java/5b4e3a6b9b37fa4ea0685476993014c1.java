import java.io.*;
import java.util.*;

class Main {
    static class FastInput {
        static final int BUF_SIZE = 1 << 20;
        char[] buf = new char[BUF_SIZE];
        int charsRead = 0;
        int bufPos = 0;
        BufferedReader in;
        char cur = 0;

        FastInput() {
            in = new BufferedReader(new InputStreamReader(System.in));
        }

        char getChar() throws IOException {
            if (bufPos >= charsRead) {
                charsRead = in.read(buf, 0, BUF_SIZE);
                bufPos = 0;
                buf[0] = (charsRead == 0 ? (char) -1 : buf[0]);
            }
            return cur = buf[bufPos++];
        }

        void tie(int x) {
        }

        boolean isBlank(char c) {
            return c <= ' ';
        }

        boolean skipBlanks() throws IOException {
            while (isBlank(cur) && cur != -1) {
                getChar();
            }
            return cur != -1;
        }

        FastInput readInteger(long[] n) throws IOException {
            n[0] = 0;
            if (skipBlanks()) {
                int sign = +1;
                if (cur == '-') {
                    sign = -1;
                    getChar();
                }
                do {
                    n[0] += n[0] + (n[0] << 3) + cur - '0';
                } while (!isBlank(getChar()));
                n[0] *= sign;
            }
            return this;
        }

        FastInput readInteger(int[] n) throws IOException {
            long[] longArr = new long[1];
            readInteger(longArr);
            n[0] = (int) longArr[0];
            return this;
        }

        FastInput readString(StringBuilder s) throws IOException {
            if (skipBlanks()) {
                s.setLength(0);
                do {
                    s.append(cur);
                } while (!isBlank(getChar()));
            }
            return this;
        }
    }

    static class FastOutput implements AutoCloseable {
        static final int BUF_SIZE = 1 << 20;
        char[] buf = new char[BUF_SIZE];
        int bufPos = 0;
        static final int TMP_SIZE = 1 << 20;
        char[] tmp = new char[TMP_SIZE];
        PrintWriter out;

        FastOutput() {
            out = new PrintWriter(System.out);
        }

        void putChar(char c) {
            buf[bufPos++] = c;
            if (bufPos == BUF_SIZE) {
                out.write(buf, 0, bufPos);
                bufPos = 0;
            }
        }

        public void close() {
            out.write(buf, 0, bufPos);
            out.close();
        }

        FastOutput print(char c) {
            putChar(c);
            return this;
        }

        FastOutput print(String s) {
            for (int i = 0; i < s.length(); i++) {
                putChar(s.charAt(i));
            }
            return this;
        }

        FastOutput print(int x) {
            return print(Integer.toString(x));
        }

        FastOutput println() {
            return print('\n');
        }

        FastOutput println(int x) {
            return print(x).println();
        }
    }

    static class Modular<T extends Number> {
        public static final int MOD = (int) 1e9 + 7;
        public static final Modular<Integer> MODULAR_INT = new Modular<>(MOD);

        private final T value;

        public Modular(T value) {
            this.value = normalize(value);
        }

        private static <T extends Number> T normalize(T x) {
            long v;
            if (x instanceof Integer || x instanceof Long) {
                v = x.longValue();
            } else {
                throw new IllegalArgumentException();
            }
            if (-MOD <= v && v < MOD) {
                return x;
            }
            v %= MOD;
            if (v < 0) {
                v += MOD;
            }
            if (x instanceof Integer) {
                return (T) Integer.valueOf((int) v);
            }
            return (T) Long.valueOf(v);
        }

        public T value() {
            return value;
        }

        public Modular<T> add(Modular<T> other) {
            return new Modular<>(normalize(value + other.value));
        }

        public Modular<T> subtract(Modular<T> other) {
            return new Modular<>(normalize(value - other.value));
        }

        public Modular<T> multiply(Modular<T> other) {
            return new Modular<>(normalize(value * other.value));
        }

        public Modular<T> divide(Modular<T> other) {
            return new Modular<>(normalize(value * Modular.inverse(other.value, MOD)));
        }

        public static <T extends Number> Modular<T> power(Modular<T> a, long b) {
            Modular<T> x = a, res = new Modular<>(1);
            long p = b;
            while (p > 0) {
                if ((p & 1) != 0) {
                    res = res.multiply(x);
                }
                x = x.multiply(x);
                p >>= 1;
            }
            return res;
        }

        public static <T extends Number> T inverse(T a, int m) {
            long u = 0, v = 1;
            while (a.longValue() != 0) {
                long t = m / a.longValue();
                m -= t * a.longValue();
                long temp = u - t * v;
                u = v;
                v = temp;
                temp = a.longValue();
                a = (T) Long.valueOf(m);
                m = (int) temp;
            }
            assert m == 1;
            return (T) Long.valueOf(u);
        }
    }

    public static void main(String[] args) throws IOException {
        FastInput fastInput = new FastInput();
        FastOutput fastOutput = new FastOutput();

        int tt = fastInput.readInteger(new int[1]);
        while (tt-- > 0) {
            long[] m = new long[1];
            fastInput.readInteger(m);
            int len = 0;
            while (m[0] > 0) {
                len++;
                m[0] >>= 1;
            }
            int[] d = new int[len];
            for (int i = 0; i < len; i++) {
                d[i] = (int) (m[0] & 1);
                m[0] >>= 1;
            }
            Modular<Integer>[] dp = new Modular[7];
            Modular<Integer>[] newDp = new Modular[7];
            for (int i = 0; i <= 6; i++) {
                dp[i] = newDp[i] = new Modular<>(0);
            }
            dp[0] = new Modular<>(1);
            for (int it = len - 1; it >= 0; it--) {
                if (d[it] == 0) {
                    newDp[0] = dp[0].add(dp[1]).add(dp[2]).add(dp[3]);
                    newDp[1] = newDp[2] = dp[1].add(dp[2]).add(dp[3]).add(dp[4]);
                    newDp[3] = newDp[4] = dp[2].add(dp[3]).add(dp[4]).add(dp[5]);
                    newDp[5] = newDp[6] = dp[3].add(dp[4]).add(dp[5]).add(dp[6]);
                } else {
                    newDp[0] = newDp[1] = dp[0].add(dp[1]).add(dp[2]).add(dp[3]);
                    newDp[2] = newDp[3] = dp[1].add(dp[2]).add(dp[3]).add(dp[4]);
                    newDp[4] = newDp[5] = dp[2].add(dp[3]).add(dp[4]).add(dp[5]);
                    newDp[6] = dp[3].add(dp[4]).add(dp[5]).add(dp[6]);
                }
                System.arraycopy(newDp, 0, dp, 0, 7);
            }
            fastOutput.println(dp[0].value());
        }

        fastOutput.close();
    }
}
