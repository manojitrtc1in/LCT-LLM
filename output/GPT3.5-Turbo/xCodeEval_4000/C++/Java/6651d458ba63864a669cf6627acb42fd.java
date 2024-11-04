import java.io.*;
import java.util.*;

class Main {
    static class FastInput {
        static final int BUF_SIZE = 1 << 20;
        byte[] buf = new byte[BUF_SIZE];
        int charsRead = 0;
        int bufPos = 0;
        InputStream in = System.in;
        byte cur = 0;

        char getChar() {
            if (bufPos >= charsRead) {
                try {
                    charsRead = in.read(buf, 0, BUF_SIZE);
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (charsRead == -1) {
                    buf[0] = -1;
                }
                bufPos = 0;
            }
            return (char) (cur = buf[bufPos++]);
        }

        void tie(int _) {}

        boolean isBlank(char c) {
            return c <= ' ';
        }

        boolean skipBlanks() {
            while (isBlank(cur) && cur != -1) {
                getChar();
            }
            return cur != -1;
        }

        FastInput readInteger(int[] n) {
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

    static class FastOutput implements Closeable {
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
                    out.write(buf, 0, bufPos);
                } catch (IOException e) {
                    e.printStackTrace();
                }
                bufPos = 0;
            }
        }

        public void close() {
            try {
                out.write(buf, 0, bufPos);
                out.flush();
                out.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        FastOutput print(char c) {
            putChar((byte) c);
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

    static final int md = (int) 1e9 + 7;

    static class Mint {
        static class Modular {
            int value;

            Modular(int value) {
                this.value = value;
            }

            int mod() {
                return md;
            }

            Modular add(Modular other) {
                value += other.value;
                if (value >= mod()) {
                    value -= mod();
                }
                return this;
            }

            Modular subtract(Modular other) {
                value -= other.value;
                if (value < 0) {
                    value += mod();
                }
                return this;
            }

            Modular multiply(Modular other) {
                value = (int) ((long) value * other.value % mod());
                return this;
            }

            Modular divide(Modular other) {
                return multiply(new Modular(inverse(other.value, mod())));
            }

            int inverse(int a, int m) {
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

        static Modular of(int x) {
            return new Modular(x);
        }

        int value;

        Mint(int value) {
            this.value = value;
        }

        Mint add(Mint other) {
            value += other.value;
            if (value >= md) {
                value -= md;
            }
            return this;
        }

        Mint subtract(Mint other) {
            value -= other.value;
            if (value < 0) {
                value += md;
            }
            return this;
        }

        Mint multiply(Mint other) {
            value = (int) ((long) value * other.value % md);
            return this;
        }

        Mint divide(Mint other) {
            return multiply(new Mint(inverse(other.value, md)));
        }

        int inverse(int a, int m) {
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
        FastInput fastInput = new FastInput();
        FastOutput fastOutput = new FastOutput();

        int tt = fastInput.getChar() - '0';
        fastInput.getChar();
        while (tt-- > 0) {
            long m = 0;
            while (fastInput.skipBlanks()) {
                m = m * 2 + fastInput.cur - '0';
                fastInput.getChar();
            }
            int[] d = new int[1];
            int len = 0;
            while (m > 0) {
                d[len++] = (int) (m & 1);
                m >>= 1;
            }
            Mint[] dp = new Mint[7];
            Mint[] newDp = new Mint[7];
            for (int i = 0; i <= 6; i++) {
                dp[i] = newDp[i] = new Mint(0);
            }
            dp[0] = Mint.of(1);
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
                Mint[] temp = dp;
                dp = newDp;
                newDp = temp;
            }
            fastOutput.println(dp[0].value);
        }

        fastOutput.close();
    }
}
