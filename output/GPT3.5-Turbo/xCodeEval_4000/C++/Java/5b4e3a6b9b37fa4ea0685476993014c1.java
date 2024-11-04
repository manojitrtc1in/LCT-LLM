import java.io.*;
import java.util.*;

class Main {
    static class FastInput {
        static final int BUF_SIZE = 1 << 20;
        final byte[] buf = new byte[BUF_SIZE];
        int charsRead = 0;
        int bufPos = 0;
        InputStream in;
        byte cur = 0;

        public FastInput(InputStream in) {
            this.in = in;
        }

        public char getChar() {
            if (bufPos >= charsRead) {
                try {
                    charsRead = in.read(buf, 0, BUF_SIZE);
                } catch (IOException e) {
                    e.printStackTrace();
                }
                bufPos = 0;
                buf[0] = (byte) (charsRead == -1 ? -1 : buf[0]);
            }
            return (char) (cur = buf[bufPos++]);
        }

        public void tie(int x) {
        }

        public boolean skipBlanks() {
            while (isBlank(cur) && cur != -1) {
                getChar();
            }
            return cur != -1;
        }

        public FastInput readInt(int[] n) {
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

        public FastInput readLong(long[] n) {
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

        public FastInput readDouble(double[] n) {
            n[0] = 0;
            if (skipBlanks()) {
                StringBuilder sb = new StringBuilder();
                while (!isBlank(cur)) {
                    sb.append(cur);
                    getChar();
                }
                n[0] = Double.parseDouble(sb.toString());
            }
            return this;
        }

        public FastInput readString(StringBuilder s) {
            if (skipBlanks()) {
                s.setLength(0);
                do {
                    s.append(cur);
                } while (!isBlank(getChar()));
            }
            return this;
        }

        public static boolean isBlank(char c) {
            return c <= ' ';
        }
    }

    static class FastOutput implements AutoCloseable {
        static final int BUF_SIZE = 1 << 20;
        final byte[] buf = new byte[BUF_SIZE];
        int bufPos = 0;
        static final int TMP_SIZE = 1 << 20;
        final byte[] tmp = new byte[TMP_SIZE];
        OutputStream out;

        public FastOutput(OutputStream out) {
            this.out = out;
        }

        public void putChar(byte c) {
            buf[bufPos++] = c;
            if (bufPos == BUF_SIZE) {
                try {
                    out.write(buf, 0, bufPos);
                } catch (IOException e) {
                    e.printStackTrace();
                }
                bufPos = 0;
            }
        }

        public void flush() {
            try {
                out.write(buf, 0, bufPos);
                out.flush();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        public void close() {
            flush();
            try {
                out.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        public FastOutput print(byte c) {
            putChar(c);
            return this;
        }

        public FastOutput print(char c) {
            putChar((byte) c);
            return this;
        }

        public FastOutput print(char[] s) {
            for (char c : s) {
                putChar((byte) c);
            }
            return this;
        }

        public FastOutput print(String s) {
            for (int i = 0; i < s.length(); i++) {
                putChar((byte) s.charAt(i));
            }
            return this;
        }

        public FastOutput print(double x, int precision) {
            if (x < 0) {
                putChar((byte) '-');
                x = -x;
            }
            x += Math.pow(10, -precision) / 2;
            long t = (long) x;
            print(t).putChar((byte) '.');
            x -= t;
            for (int i = 0; i < precision; i++) {
                x *= 10;
                t = (long) x;
                putChar((byte) ('0' + t));
                x -= t;
            }
            return this;
        }

        public FastOutput println(int x) {
            return print(x).putChar((byte) '\n');
        }

        public FastOutput println(long x) {
            return print(x).putChar((byte) '\n');
        }

        public FastOutput println(double x, int precision) {
            return print(x, precision).putChar((byte) '\n');
        }
    }

    static class Modular {
        static final int MOD = (int) 1e9 + 7;
        final int value;

        public Modular(int value) {
            this.value = normalize(value);
        }

        public int normalize(int x) {
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

        public int getValue() {
            return value;
        }

        public Modular add(Modular other) {
            int sum = value + other.value;
            if (sum >= MOD) {
                sum -= MOD;
            }
            return new Modular(sum);
        }

        public Modular subtract(Modular other) {
            int diff = value - other.value;
            if (diff < 0) {
                diff += MOD;
            }
            return new Modular(diff);
        }

        public Modular multiply(Modular other) {
            return new Modular((int) ((long) value * other.value % MOD));
        }

        public Modular divide(Modular other) {
            return multiply(other.inverse());
        }

        public Modular inverse() {
            return new Modular(inverse(value, MOD));
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
    }

    public static void main(String[] args) {
        FastInput fastInput = new FastInput(System.in);
        FastOutput fastOutput = new FastOutput(System.out);

        int tt = fastInput.getInt();
        while (tt-- > 0) {
            long m = fastInput.getLong();
            int[] d = new int[1];
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
                Modular[] temp = dp;
                dp = newDp;
                newDp = temp;
            }
            fastOutput.println(dp[0].getValue());
        }

        fastOutput.close();
    }
}
