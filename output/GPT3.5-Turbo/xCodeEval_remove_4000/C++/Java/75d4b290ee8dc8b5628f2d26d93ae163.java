import java.io.*;
import java.util.*;

class TaskD {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        OutputWriter out = new OutputWriter(System.out);
        int n = in.readInt();
        int[] x = new int[n];
        int[] v = new int[n];
        int[] p = new int[n];
        for (int i = 0; i < n; i++) {
            x[i] = in.readInt();
            v[i] = in.readInt();
            p[i] = in.readInt();
        }
        int mod = 998244353;
        ModInt.setMod(mod);
        ModInt[] pp = new ModInt[4 * n];
        ModInt[] tmp = new ModInt[4 * n];
        boolean[][] allowed = new boolean[n][4];
        Event[] events = new Event[2 * (n - 1)];
        int eventIndex = 0;
        for (int i = 1; i < n; i++) {
            events[eventIndex++] = new Event(2, i, x[i] - x[i - 1], v[i] + v[i - 1]);
            if (v[i] > v[i - 1]) {
                events[eventIndex++] = new Event(0, i, x[i] - x[i - 1], v[i] - v[i - 1]);
            } else if (v[i] < v[i - 1]) {
                events[eventIndex++] = new Event(3, i, x[i] - x[i - 1], v[i - 1] - v[i]);
            }
        }
        Arrays.sort(events);
        for (int i = 0; i < 4 * n; i++) {
            pp[i] = new ModInt(0);
            tmp[i] = new ModInt(0);
        }
        for (int i = 0; i < n; i++) {
            allowed[i][0] = true;
            allowed[i][1] = true;
            allowed[i][2] = true;
            allowed[i][3] = true;
        }
        for (int i = 0; i < 4 * n; i++) {
            pp[i] = new ModInt(0);
            tmp[i] = new ModInt(0);
        }
        for (int i = 0; i < 4; i++) {
            pp[0].set(i, 0);
        }
        for (int i = 1; i < 4 * n; i++) {
            int parent = (i - 1) / 2;
            for (int j = 0; j < 4; j++) {
                pp[i].add(j, pp[parent].get(j));
            }
        }
        ModInt answer = new ModInt(0);
        for (Event e : events) {
            query(pp, tmp, allowed, 0, 0, n, 0, e.at);
            ModInt left = tmp[0].get(e.type / 2).add(tmp[0].get(2 + e.type / 2));
            query(pp, tmp, allowed, 0, 0, n, e.at, n);
            ModInt right = tmp[0].get(e.type % 2 * 2).add(tmp[0].get(e.type % 2 * 2 + 1));
            answer.add(left.multiply(right).multiply(e.dx).divide(e.v));
            allowed[e.at][e.type] = false;
            recalc(pp, tmp, allowed, 0, 0, n, e.at);
        }
        out.printLine(answer);
        out.flush();
    }

    static void query(ModInt[] pp, ModInt[] tmp, boolean[][] allowed, int root, int left, int right, int from, int to) {
        if (left >= to || right <= from) {
            return;
        }
        if (left >= from && right <= to) {
            for (int i = 0; i < 4; i++) {
                tmp[root].set(i, pp[root].get(i));
            }
            return;
        }
        int mid = (left + right) / 2;
        query(pp, tmp, allowed, 2 * root + 1, left, mid, from, to);
        query(pp, tmp, allowed, 2 * root + 2, mid, right, from, to);
        join(pp, tmp, root, mid);
    }

    static void join(ModInt[] pp, ModInt[] tmp, int root, int mid) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    for (int l = 0; l < 2; l++) {
                        if (allowed(mid, 2 * j + k)) {
                            tmp[root].add(i * 2 + l, tmp[2 * root + 1].get(i * 2 + j).multiply(tmp[2 * root + 2].get(k * 2 + l)));
                        }
                    }
                }
            }
        }
    }

    static void recalc(ModInt[] pp, ModInt[] tmp, boolean[][] allowed, int root, int left, int right, int at) {
        if (left >= at || right <= at) {
            return;
        }
        int mid = (left + right) / 2;
        recalc(pp, tmp, allowed, 2 * root + 1, left, mid, at);
        recalc(pp, tmp, allowed, 2 * root + 2, mid, right, at);
        join(pp, tmp, root, mid);
    }

    static boolean allowed(int at, int type) {
        return at >= 0 && at < allowed.length && type >= 0 && type < allowed[at].length && allowed[at][type];
    }

    static class Event implements Comparable<Event> {
        int type;
        int at;
        int dx;
        int v;

        Event(int type, int at, int dx, int v) {
            this.type = type;
            this.at = at;
            this.dx = dx;
            this.v = v;
        }

        public int compareTo(Event o) {
            return Long.compare((long) dx * o.v, (long) o.dx * v);
        }
    }

    static class ModInt {
        static int mod;
        int n;

        ModInt(int n) {
            if (n >= 0 && n < mod) {
                this.n = n;
                return;
            }
            n %= mod;
            if (n < 0) {
                n += mod;
            }
            this.n = n;
        }

        void set(int index, int value) {
            n = n - (n % (int) Math.pow(mod, index + 1)) + value * (int) Math.pow(mod, index);
        }

        ModInt get(int index) {
            return new ModInt((n / (int) Math.pow(mod, index)) % mod);
        }

        void add(int index, ModInt value) {
            set(index, get(index).add(value).n);
        }

        ModInt add(ModInt other) {
            int sum = n + other.n;
            if (sum >= mod) {
                sum -= mod;
            }
            return new ModInt(sum);
        }

        void multiply(int index, ModInt value) {
            set(index, get(index).multiply(value).n);
        }

        ModInt multiply(ModInt other) {
            return new ModInt((int) ((long) n * other.n % mod));
        }

        void divide(int index, ModInt value) {
            set(index, get(index).divide(value).n);
        }

        ModInt divide(ModInt other) {
            return multiply(other.inverse());
        }

        ModInt inverse() {
            int x, y;
            int g = gcd(n, mod, x = 0, y = 1);
            if (g != 1) {
                throw new ArithmeticException("not inversable");
            }
            return new ModInt(x);
        }

        static int gcd(int a, int b, int x, int y) {
            if (a == 0) {
                x = 0;
                y = 1;
                return b;
            }
            int d = gcd(b % a, a, y, x);
            x -= (b / a) * y;
            return d;
        }

        static void setMod(int mod) {
            ModInt.mod = mod;
        }
    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        public int readInt() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
    }

    static class OutputWriter {
        private PrintWriter writer;

        public OutputWriter(OutputStream stream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(stream)));
        }

        public void print(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(objects[i]);
            }
        }

        public void printLine(Object... objects) {
            print(objects);
            writer.println();
        }

        public void flush() {
            writer.flush();
        }
    }
}
