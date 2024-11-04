import java.util.*;
import java.io.*;

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

        FastInput readInteger(double[] n) throws IOException {
            n[0] = 0;
            if (skipBlanks()) {
                StringBuilder sb = new StringBuilder();
                do {
                    sb.append(cur);
                } while (!isBlank(getChar()));
                n[0] = Double.parseDouble(sb.toString());
            }
            return this;
        }
    }

    static class FastOutput {
        static final int BUF_SIZE = 1 << 20;
        char[] buf = new char[BUF_SIZE];
        int bufPos = 0;
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

        void flush() {
            out.write(buf, 0, bufPos);
            out.flush();
            bufPos = 0;
        }

        FastOutput print(Object obj) {
            out.print(obj);
            return this;
        }

        FastOutput println(Object obj) {
            out.println(obj);
            return this;
        }
    }

    static class Modular {
        static final int MOD = (int) 1e9 + 7;
        int value;

        Modular(int x) {
            value = normalize(x);
        }

        static int normalize(int x) {
            int v;
            if (-MOD <= x && x < MOD) {
                v = x;
            } else {
                v = x % MOD;
            }
            if (v < 0) {
                v += MOD;
            }
            return v;
        }

        int getValue() {
            return value;
        }

        Modular add(Modular other) {
            value += other.value;
            if (value >= MOD) {
                value -= MOD;
            }
            return this;
        }

        Modular subtract(Modular other) {
            value -= other.value;
            if (value < 0) {
                value += MOD;
            }
            return this;
        }

        Modular multiply(Modular other) {
            value = (int) ((long) value * other.value % MOD);
            return this;
        }

        Modular divide(Modular other) {
            return multiply(inverse(other.value, MOD));
        }

        static int inverse(int a, int m) {
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
                dp[i] = newDp[i] = new Modular(0);
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
                System.arraycopy(newDp, 0, dp, 0, 7);
            }
            fastOutput.println(dp[0].getValue());
        }

        fastOutput.flush();
    }
}
