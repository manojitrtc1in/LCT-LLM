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

        FastInput readInteger(int n) throws IOException {
            n = 0;
            if (skipBlanks()) {
                int sign = +1;
                if (cur == '-') {
                    sign = -1;
                    getChar();
                }
                do {
                    n += n + (n << 3) + cur - '0';
                } while (!isBlank(getChar()));
                n *= sign;
            }
            return this;
        }

        FastInput readInteger(long n) throws IOException {
            n = 0;
            if (skipBlanks()) {
                int sign = +1;
                if (cur == '-') {
                    sign = -1;
                    getChar();
                }
                do {
                    n += n + (n << 3) + cur - '0';
                } while (!isBlank(getChar()));
                n *= sign;
            }
            return this;
        }

        FastInput readString(String s) throws IOException {
            if (skipBlanks()) {
                s = "";
                do {
                    s += cur;
                } while (!isBlank(getChar()));
            }
            return this;
        }

        FastInput readDouble(double d) throws IOException {
            d = 0;
            if (skipBlanks()) {
                String s = "";
                readString(s);
                d = Double.parseDouble(s);
            }
            return this;
        }
    }

    static class FastOutput {
        static final int BUF_SIZE = 1 << 20;
        char[] buf = new char[BUF_SIZE];
        int bufPos = 0;
        static final int TMP_SIZE = 1 << 20;
        char[] tmp = new char[TMP_SIZE];
        BufferedWriter out;

        FastOutput() {
            out = new BufferedWriter(new OutputStreamWriter(System.out));
        }

        void putChar(char c) throws IOException {
            buf[bufPos++] = c;
            if (bufPos == BUF_SIZE) {
                out.write(buf, 0, bufPos);
                bufPos = 0;
            }
        }

        void flush() throws IOException {
            out.write(buf, 0, bufPos);
            out.flush();
            bufPos = 0;
        }

        FastOutput print(char c) throws IOException {
            putChar(c);
            return this;
        }

        FastOutput print(String s) throws IOException {
            for (int i = 0; i < s.length(); i++) {
                putChar(s.charAt(i));
            }
            return this;
        }

        FastOutput print(int n) throws IOException {
            return print(Integer.toString(n));
        }

        FastOutput print(long n) throws IOException {
            return print(Long.toString(n));
        }

        FastOutput print(double d) throws IOException {
            return print(Double.toString(d));
        }

        FastOutput println() throws IOException {
            return print('\n');
        }

        FastOutput println(char c) throws IOException {
            return print(c).println();
        }

        FastOutput println(String s) throws IOException {
            return print(s).println();
        }

        FastOutput println(int n) throws IOException {
            return print(n).println();
        }

        FastOutput println(long n) throws IOException {
            return print(n).println();
        }

        FastOutput println(double d) throws IOException {
            return print(d).println();
        }
    }

    static class Modular<T> {
        static class Type {
            static final int value = (int) 1e9 + 7;
        }

        T value;

        Modular() {
            value = null;
        }

        Modular(T x) {
            value = normalize(x);
        }

        static <U> T normalize(U x) {
            T v;
            if (-mod() <= x && x < mod()) {
                v = (T) x;
            } else {
                v = (T) (x % mod());
            }
            if (v < 0) {
                v += mod();
            }
            return v;
        }

        T getValue() {
            return value;
        }

        <U> U toType() {
            return (U) value;
        }

        static int mod() {
            return Type.value;
        }

        Modular<T> add(Modular<T> other) {
            if ((value += other.value) >= mod()) {
                value -= mod();
            }
            return this;
        }

        Modular<T> subtract(Modular<T> other) {
            if ((value -= other.value) < 0) {
                value += mod();
            }
            return this;
        }

        <U> Modular<T> add(U other) {
            return add(new Modular<>(other));
        }

        <U> Modular<T> subtract(U other) {
            return subtract(new Modular<>(other));
        }

        Modular<T> increment() {
            return add(1);
        }

        Modular<T> decrement() {
            return subtract(1);
        }

        Modular<T> negate() {
            return new Modular<>(-value);
        }

        <U> Modular<T> multiply(Modular<U> rhs) {
            long x = (long) value * (long) rhs.value;
            long xh = (x >> 32) & 0xffffffffL, xl = (x & 0xffffffffL), d, m;
            d = xh / mod();
            m = xh - d * mod();
            x = xl - d * mod();
            if (x < 0) {
                x += mod();
            }
            value = (T) x;
            return this;
        }

        <U> Modular<T> multiply(U rhs) {
            return multiply(new Modular<>(rhs));
        }

        <U> Modular<T> divide(Modular<U> other) {
            return multiply(inverse(other.value, mod()));
        }

        static <U> U inverse(U a, U m) {
            U u = (U) 0, v = (U) 1;
            while (!a.equals(0)) {
                U t = (U) (m / a);
                m -= t * a;
                u -= t * v;
                U temp = u;
                u = v;
                v = temp;
            }
            assert m.equals(1);
            return u;
        }

        @Override
        public boolean equals(Object obj) {
            if (obj == null || getClass() != obj.getClass()) {
                return false;
            }
            Modular<T> other = (Modular<T>) obj;
            return value.equals(other.value);
        }

        @Override
        public int hashCode() {
            return value.hashCode();
        }

        @Override
        public String toString() {
            return value.toString();
        }
    }

    static class Mint extends Modular<Integer> {
        Mint() {
            super();
        }

        Mint(Integer x) {
            super(x);
        }
    }

    static int[] d = new int[123];
    static Mint[] dp = new Mint[7];
    static Mint[] newDp = new Mint[7];

    public static void main(String[] args) throws IOException {
        FastInput fastInput = new FastInput();
        FastOutput fastOutput = new FastOutput();

        int tt = fastInput.readInteger(0).getValue();
        while (tt-- > 0) {
            long m = fastInput.readInteger(0L).getValue();
            int len = 0;
            while (m > 0) {
                d[len++] = (int) (m & 1);
                m >>= 1;
            }
            for (int i = 0; i <= 6; i++) {
                dp[i] = newDp[i] = new Mint(0);
            }
            dp[0] = new Mint(1);
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
            fastOutput.println(dp[0]).flush();
        }

        fastOutput.flush();
    }
}
