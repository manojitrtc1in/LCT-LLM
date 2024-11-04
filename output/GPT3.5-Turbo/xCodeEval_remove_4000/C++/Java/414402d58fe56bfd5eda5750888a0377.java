import java.io.*;
import java.util.*;

class Main {
    static class FastInput {
        static final int BUF_SIZE = 1 << 20;
        char[] buf = new char[BUF_SIZE];
        int charsRead = 0;
        int bufPos = 0;
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        char cur = 0;

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

        char nextChar() throws IOException {
            skipBlanks();
            return cur;
        }

        String next() throws IOException {
            skipBlanks();
            StringBuilder sb = new StringBuilder();
            do {
                sb.append(cur);
            } while (!isBlank(getChar()));
            return sb.toString();
        }

        int nextInt() throws IOException {
            skipBlanks();
            int sign = 1;
            if (cur == '-') {
                sign = -1;
                getChar();
            }
            int n = 0;
            do {
                n += n + (n << 3) + cur - '0';
            } while (!isBlank(getChar()));
            return n * sign;
        }

        long nextLong() throws IOException {
            skipBlanks();
            int sign = 1;
            if (cur == '-') {
                sign = -1;
                getChar();
            }
            long n = 0;
            do {
                n += n + (n << 3) + cur - '0';
            } while (!isBlank(getChar()));
            return n * sign;
        }

        double nextDouble() throws IOException {
            skipBlanks();
            StringBuilder sb = new StringBuilder();
            while (!isBlank(cur)) {
                sb.append(cur);
                getChar();
            }
            return Double.parseDouble(sb.toString());
        }
    }

    static class FastOutput {
        static final int BUF_SIZE = 1 << 20;
        char[] buf = new char[BUF_SIZE];
        int bufPos = 0;
        static final int TMP_SIZE = 1 << 20;
        char[] tmp = new char[TMP_SIZE];
        PrintWriter out = new PrintWriter(System.out);

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

        void print(Object obj) {
            out.print(obj);
        }

        void println(Object obj) {
            out.println(obj);
        }

        void println() {
            out.println();
        }

        void close() {
            out.close();
        }
    }

    static class Modular {
        static int mod = (int) 1e9 + 7;
        int value;

        Modular() {
            value = 0;
        }

        Modular(int x) {
            value = normalize(x);
        }

        static int normalize(int x) {
            int v;
            if (-mod <= x && x < mod) {
                v = x;
            } else {
                v = x % mod;
            }
            if (v < 0) {
                v += mod;
            }
            return v;
        }

        int getValue() {
            return value;
        }

        void add(Modular other) {
            value += other.value;
            if (value >= mod) {
                value -= mod;
            }
        }

        void subtract(Modular other) {
            value -= other.value;
            if (value < 0) {
                value += mod;
            }
        }

        void multiply(Modular other) {
            value = normalize((int) ((long) value * other.value % mod));
        }

        void divide(Modular other) {
            multiply(inverse(other.value));
        }

        Modular inverse(int a) {
            int u = 0, v = 1;
            while (a != 0) {
                int t = mod / a;
                mod -= t * a;
                int temp = u - t * v;
                u = v;
                v = temp;
            }
            assert mod == 1;
            return new Modular(u);
        }
    }

    public static void main(String[] args) throws IOException {
        FastInput fastInput = new FastInput();
        FastOutput fastOutput = new FastOutput();

        int tt = fastInput.nextInt();
        while (tt-- > 0) {
            long m = fastInput.nextLong();
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
                    newDp[0].add(dp[0]);
                    newDp[0].add(dp[1]);
                    newDp[0].add(dp[2]);
                    newDp[0].add(dp[3]);

                    newDp[1].add(dp[1]);
                    newDp[1].add(dp[2]);
                    newDp[1].add(dp[3]);
                    newDp[1].add(dp[4]);

                    newDp[2].add(dp[2]);
                    newDp[2].add(dp[3]);
                    newDp[2].add(dp[4]);
                    newDp[2].add(dp[5]);

                    newDp[3].add(dp[3]);
                    newDp[3].add(dp[4]);
                    newDp[3].add(dp[5]);
                    newDp[3].add(dp[6]);

                    newDp[4].add(dp[1]);
                    newDp[4].add(dp[2]);
                    newDp[4].add(dp[3]);
                    newDp[4].add(dp[4]);

                    newDp[5].add(dp[2]);
                    newDp[5].add(dp[3]);
                    newDp[5].add(dp[4]);
                    newDp[5].add(dp[5]);

                    newDp[6].add(dp[3]);
                    newDp[6].add(dp[4]);
                    newDp[6].add(dp[5]);
                    newDp[6].add(dp[6]);
                } else {
                    newDp[0].add(dp[0]);
                    newDp[0].add(dp[1]);
                    newDp[0].add(dp[2]);
                    newDp[0].add(dp[3]);

                    newDp[1].add(dp[0]);
                    newDp[1].add(dp[1]);
                    newDp[1].add(dp[2]);
                    newDp[1].add(dp[3]);

                    newDp[2].add(dp[1]);
                    newDp[2].add(dp[2]);
                    newDp[2].add(dp[3]);
                    newDp[2].add(dp[4]);

                    newDp[3].add(dp[2]);
                    newDp[3].add(dp[3]);
                    newDp[3].add(dp[4]);
                    newDp[3].add(dp[5]);

                    newDp[4].add(dp[1]);
                    newDp[4].add(dp[2]);
                    newDp[4].add(dp[3]);
                    newDp[4].add(dp[4]);

                    newDp[5].add(dp[2]);
                    newDp[5].add(dp[3]);
                    newDp[5].add(dp[4]);
                    newDp[5].add(dp[5]);

                    newDp[6].add(dp[3]);
                    newDp[6].add(dp[4]);
                    newDp[6].add(dp[5]);
                    newDp[6].add(dp[6]);
                }
                Modular[] temp = dp;
                dp = newDp;
                newDp = temp;
            }
            fastOutput.println(dp[0].getValue());
        }

        fastOutput.flush();
    }
}
