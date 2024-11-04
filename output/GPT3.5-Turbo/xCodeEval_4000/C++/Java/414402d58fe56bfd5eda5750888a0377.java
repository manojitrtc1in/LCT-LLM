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
                buf[0] = (char) (charsRead == 0 ? -1 : buf[0]);
            }
            return cur = buf[bufPos++];
        }

        void tie(int a) {
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
    }

    static class FastOutput implements Closeable {
        static final int BUF_SIZE = 1 << 20;
        byte[] buf = new byte[BUF_SIZE];
        int bufPos = 0;
        static final int TMP_SIZE = 1 << 20;
        byte[] tmp = new byte[TMP_SIZE];
        OutputStream out;

        FastOutput() {
            out = new BufferedOutputStream(System.out);
        }

        void putChar(byte c) throws IOException {
            buf[bufPos++] = c;
            if (bufPos == BUF_SIZE) {
                out.write(buf, 0, bufPos);
                bufPos = 0;
            }
        }

        public void close() throws IOException {
            out.write(buf, 0, bufPos);
            out.close();
        }

        FastOutput print(byte c) throws IOException {
            putChar(c);
            return this;
        }

        FastOutput print(char c) throws IOException {
            putChar((byte) c);
            return this;
        }

        FastOutput print(char[] s) throws IOException {
            for (char c : s) {
                putChar((byte) c);
            }
            return this;
        }

        FastOutput print(String s) throws IOException {
            for (int i = 0; i < s.length(); i++) {
                putChar((byte) s.charAt(i));
            }
            return this;
        }

        FastOutput print(long x) throws IOException {
            if (x == 0) {
                putChar((byte) '0');
            } else {
                if (x < 0) {
                    putChar((byte) '-');
                    x = -x;
                }
                int j = TMP_SIZE - 1;
                while (x > 0) {
                    tmp[j--] = (byte) ('0' + x % 10);
                    x /= 10;
                }
                for (int i = j + 1; i < TMP_SIZE; i++) {
                    putChar(tmp[i]);
                }
            }
            return this;
        }

        FastOutput println(long x) throws IOException {
            return print(x).putChar((byte) '\n');
        }
    }

    static class Modular {
        static class Type {
            static final int value = (int) 1e9 + 7;
        }

        int value;

        Modular() {
            value = 0;
        }

        Modular(long x) {
            value = normalize(x);
        }

        static int normalize(long x) {
            int v;
            if (-mod() <= x && x < mod()) {
                v = (int) x;
            } else {
                v = (int) (x % mod());
            }
            if (v < 0) {
                v += mod();
            }
            return v;
        }

        int get() {
            return value;
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
            value = normalize((long) value * other.value);
            return this;
        }

        Modular divide(Modular other) {
            return multiply(inverse(other.value, mod()));
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

        static int mod() {
            return Type.value;
        }
    }

    static class Mint extends Modular {
        Mint() {
            super();
        }

        Mint(long x) {
            super(x);
        }
    }

    static class Pair<A, B> {
        A first;
        B second;

        Pair(A first, B second) {
            this.first = first;
            this.second = second;
        }
    }

    static class Tuple<A, B, C> {
        A first;
        B second;
        C third;

        Tuple(A first, B second, C third) {
            this.first = first;
            this.second = second;
            this.third = third;
        }
    }

    static class Tuple<A, B, C, D> {
        A first;
        B second;
        C third;
        D fourth;

        Tuple(A first, B second, C third, D fourth) {
            this.first = first;
            this.second = second;
            this.third = third;
            this.fourth = fourth;
        }
    }

    static class Debug {
        static void debugOut() {
            System.err.println();
        }

        static void debugOut(Object... objects) {
            StringBuilder stringBuilder = new StringBuilder();
            stringBuilder.append(" ");
            for (Object obj : objects) {
                stringBuilder.append(obj.toString());
            }
            debugOut(stringBuilder.toString());
        }

        static void debugOut(String str) {
            System.err.print(str);
        }
    }

    static class FastIO {
        FastInput cin;
        FastOutput cout;

        FastIO() {
            cin = new FastInput();
            cout = new FastOutput();
        }

        void close() throws IOException {
            cin.in.close();
            cout.close();
        }
    }

    static class TaskSolver {
        void solve(FastIO io) throws IOException {
            int tt;
            io.cin.readInteger(new long[]{tt});
            while (tt-- > 0) {
                long[] m = new long[1];
                io.cin.readInteger(m);
                int len = 0;
                while (m[0] > 0) {
                    d[len++] = (int) (m[0] & 1);
                    m[0] >>= 1;
                }
                for (int i = 0; i <= 6; i++) {
                    dp[i] = new_dp[i] = new Mint();
                }
                dp[0] = new Mint(1);
                for (int it = len - 1; it >= 0; it--) {
                    if (d[it] == 0) {
                        new_dp[0] = dp[0].add(dp[1]).add(dp[2]).add(dp[3]);
                        new_dp[1] = new_dp[2] = dp[1].add(dp[2]).add(dp[3]).add(dp[4]);
                        new_dp[3] = new_dp[4] = dp[2].add(dp[3]).add(dp[4]).add(dp[5]);
                        new_dp[5] = new_dp[6] = dp[3].add(dp[4]).add(dp[5]).add(dp[6]);
                    } else {
                        new_dp[0] = new_dp[1] = dp[0].add(dp[1]).add(dp[2]).add(dp[3]);
                        new_dp[2] = new_dp[3] = dp[1].add(dp[2]).add(dp[3]).add(dp[4]);
                        new_dp[4] = new_dp[5] = dp[2].add(dp[3]).add(dp[4]).add(dp[5]);
                        new_dp[6] = dp[3].add(dp[4]).add(dp[5]).add(dp[6]);
                    }
                    swap(dp, new_dp);
                }
                io.cout.println(dp[0].get());
            }
        }

        void swap(Mint[] a, Mint[] b) {
            Mint[] temp = new Mint[a.length];
            System.arraycopy(a, 0, temp, 0, a.length);
            System.arraycopy(b, 0, a, 0, b.length);
            System.arraycopy(temp, 0, b, 0, temp.length);
        }

        int[] d = new int[123];
        Mint[] dp = new Mint[7];
        Mint[] new_dp = new Mint[7];
    }

    public static void main(String[] args) throws IOException {
        FastIO io = new FastIO();
        TaskSolver solver = new TaskSolver();
        solver.solve(io);
        io.close();
    }
}
