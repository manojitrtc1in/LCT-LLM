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

        public FastInput() {
            in = new BufferedReader(new InputStreamReader(System.in));
        }

        public char getChar() throws IOException {
            if (bufPos >= charsRead) {
                charsRead = in.read(buf, 0, BUF_SIZE);
                bufPos = 0;
                buf[0] = (charsRead == 0 ? (char) -1 : buf[0]);
            }
            return cur = buf[bufPos++];
        }

        public void tie(int a) {
        }

        public boolean isBlank(char c) {
            return c <= ' ';
        }

        public boolean skipBlanks() throws IOException {
            while (isBlank(cur) && cur != -1) {
                getChar();
            }
            return cur != -1;
        }

        public FastInput readInteger(long[] n) throws IOException {
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
    }

    static class FastOutput implements AutoCloseable {
        static final int BUF_SIZE = 1 << 20;
        char[] buf = new char[BUF_SIZE];
        int bufPos = 0;
        static final int TMP_SIZE = 1 << 20;
        char[] tmp = new char[TMP_SIZE];
        PrintWriter out;

        public FastOutput() {
            out = new PrintWriter(System.out);
        }

        public void putChar(char c) {
            buf[bufPos++] = c;
            if (bufPos == BUF_SIZE) {
                out.write(buf, 0, bufPos);
                bufPos = 0;
            }
        }

        @Override
        public void close() {
            out.write(buf, 0, bufPos);
            out.close();
        }

        public FastOutput print(char c) {
            putChar(c);
            return this;
        }

        public FastOutput print(String s) {
            for (int i = 0; i < s.length(); i++) {
                putChar(s.charAt(i));
            }
            return this;
        }

        public FastOutput print(long n) {
            if (n == 0) {
                putChar('0');
            } else {
                boolean isNegative = false;
                if (n < 0) {
                    isNegative = true;
                    n = -n;
                }
                int idx = TMP_SIZE - 1;
                while (n > 0) {
                    tmp[idx--] = (char) ('0' + n % 10);
                    n /= 10;
                }
                if (isNegative) {
                    putChar('-');
                }
                for (int i = idx + 1; i < TMP_SIZE; i++) {
                    putChar(tmp[i]);
                }
            }
            return this;
        }

        public FastOutput println() {
            putChar('\n');
            return this;
        }
    }

    static class Modular {
        static final int MOD = (int) 1e9 + 7;
        int value;

        public Modular() {
            value = 0;
        }

        public Modular(long x) {
            value = normalize(x);
        }

        public static int normalize(long x) {
            int v;
            if (-MOD <= x && x < MOD) {
                v = (int) x;
            } else {
                v = (int) (x % MOD);
            }
            if (v < 0) {
                v += MOD;
            }
            return v;
        }

        public int getValue() {
            return value;
        }

        public Modular add(Modular other) {
            value += other.value;
            if (value >= MOD) {
                value -= MOD;
            }
            return this;
        }

        public Modular subtract(Modular other) {
            value -= other.value;
            if (value < 0) {
                value += MOD;
            }
            return this;
        }

        public Modular multiply(Modular other) {
            value = normalize((long) value * other.value);
            return this;
        }

        public Modular divide(Modular other) {
            return multiply(inverse(other.value, MOD));
        }

        public static int inverse(int a, int m) {
            int u = 0, v = 1;
            while (a != 0) {
                int t = m / a;
                m -= t * a;
                int temp = u - t * v;
                u = v;
                v = temp;
                temp = a;
                a = m;
                m = temp;
            }
            assert m == 1;
            return u;
        }

        public static Modular power(Modular a, long b) {
            assert b >= 0;
            Modular x = a, res = new Modular(1);
            long p = b;
            while (p > 0) {
                if ((p & 1) == 1) {
                    res.multiply(x);
                }
                x.multiply(x);
                p >>= 1;
            }
            return res;
        }
    }

    public static void main(String[] args) throws IOException {
        FastInput fastInput = new FastInput();
        FastOutput fastOutput = new FastOutput();

        int tt = fastInput.readInteger(new long[1]).getValue();
        while (tt-- > 0) {
            long m = fastInput.readInteger(new long[1]).getValue();
            int[] d = new int[123];
            int len = 0;
            while (m > 0) {
                d[len++] = (int) (m & 1);
                m >>= 1;
            }
            Modular[] dp = new Modular[7];
            Modular[] newDp = new Modular[7];
            for (int i = 0; i <= 6; i++) {
                dp[i] = new Modular();
                newDp[i] = new Modular();
            }
            dp[0] = new Modular(1);
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
                Modular[] temp = dp;
                dp = newDp;
                newDp = temp;
            }
            fastOutput.print(dp[0].getValue()).println();
        }

        fastOutput.close();
    }
}
