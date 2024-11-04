import java.io.*;
import java.util.*;

class Main {
    static class FastInput {
        static final int BUF_SIZE = 1 << 20;
        char[] buf = new char[BUF_SIZE];
        int charsRead = 0;
        int bufPos = 0;
        InputStream in = System.in;
        char cur = 0;

        char getChar() throws IOException {
            if (bufPos >= charsRead) {
                charsRead = in.read(buf, 0, BUF_SIZE);
                bufPos = 0;
                buf[0] = (charsRead == -1 ? (char) -1 : buf[0]);
            }
            return cur = buf[bufPos++];
        }

        void tie(int x) {}

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
            long[] ln = new long[1];
            readInteger(ln);
            n[0] = (int) ln[0];
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
        byte[] buf = new byte[BUF_SIZE];
        int bufPos = 0;
        static final int TMP_SIZE = 1 << 20;
        byte[] tmp = new byte[TMP_SIZE];
        OutputStream out = System.out;

        void putChar(byte c) {
            buf[bufPos++] = c;
            if (bufPos == BUF_SIZE) {
                try {
                    out.write(buf, 0, BUF_SIZE);
                } catch (IOException e) {
                    throw new UncheckedIOException(e);
                }
                bufPos = 0;
            }
        }

        @Override
        public void close() {
            try {
                out.write(buf, 0, bufPos);
                out.flush();
            } catch (IOException e) {
                throw new UncheckedIOException(e);
            }
        }

        FastOutput print(byte c) {
            putChar(c);
            return this;
        }

        FastOutput print(char c) {
            putChar((byte) c);
            return this;
        }

        FastOutput print(char[] s) {
            for (char c : s) {
                putChar((byte) c);
            }
            return this;
        }

        FastOutput print(String s) {
            for (int i = 0; i < s.length(); i++) {
                putChar((byte) s.charAt(i));
            }
            return this;
        }

        FastOutput print(int x) {
            if (x == 0) {
                putChar((byte) '0');
            } else {
                if (x < 0) {
                    putChar((byte) '-');
                    x = -x;
                }
                int p = TMP_SIZE - 1;
                while (x > 0) {
                    tmp[p--] = (byte) ('0' + x % 10);
                    x /= 10;
                }
                for (int i = p + 1; i < TMP_SIZE; i++) {
                    putChar(tmp[i]);
                }
            }
            return this;
        }

        FastOutput println(int x) {
            return print(x).putChar((byte) '\n');
        }
    }

    static class Modular<T extends Number> {
        public static final int MOD = (int) 1e9 + 7;
        public final T value;

        public Modular(T value) {
            this.value = normalize(value);
        }

        private static <T extends Number> T normalize(T x) {
            long v;
            if (x instanceof Integer) {
                v = (int) x;
            } else if (x instanceof Long) {
                v = (long) x;
            } else {
                throw new IllegalArgumentException();
            }
            v %= MOD;
            if (v < 0) {
                v += MOD;
            }
            if (x instanceof Integer) {
                return (T) Integer.valueOf((int) v);
            } else if (x instanceof Long) {
                return (T) Long.valueOf(v);
            } else {
                throw new IllegalArgumentException();
            }
        }

        public T add(T x) {
            return normalize(value.longValue() + x.longValue());
        }

        public T subtract(T x) {
            return normalize(value.longValue() - x.longValue());
        }

        public T multiply(T x) {
            return normalize(value.longValue() * x.longValue());
        }

        public T divide(T x) {
            return multiply(inverse(x));
        }

        public T inverse(T x) {
            long a = x.longValue();
            long b = MOD;
            long u = 0;
            long v = 1;
            while (a != 0) {
                long t = b / a;
                b -= t * a;
                u -= t * v;
                long tmp = a;
                a = b;
                b = tmp;
                tmp = u;
                u = v;
                v = tmp;
            }
            if (b != 1) {
                throw new IllegalArgumentException();
            }
            if (u < 0) {
                u += MOD;
            }
            return normalize(u);
        }

        public T pow(long b) {
            T x = value;
            T res = normalize(1);
            while (b > 0) {
                if ((b & 1) != 0) {
                    res = res.multiply(x);
                }
                x = x.multiply(x);
                b >>= 1;
            }
            return res;
        }

        public T negate() {
            return normalize(-value.longValue());
        }

        public int compareTo(Modular<T> other) {
            return value.compareTo(other.value);
        }

        @Override
        public String toString() {
            return value.toString();
        }
    }

    public static void main(String[] args) throws IOException {
        FastInput fastInput = new FastInput();
        FastOutput fastOutput = new FastOutput();

        int tt = fastInput.readInteger();
        while (tt-- > 0) {
            long m;
            fastInput.readInteger(new long[]{m});
            int len = 0;
            while (m > 0) {
                len++;
                m >>= 1;
            }
            int[] d = new int[len];
            for (int i = 0; i < len; i++) {
                d[i] = (int) (m & 1);
                m >>= 1;
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
                Modular<Integer>[] tmp = dp;
                dp = newDp;
                newDp = tmp;
            }
            fastOutput.println(dp[0].value);
        }

        fastOutput.close();
    }
}
