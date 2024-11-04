


import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;

public class id6 {
    class id7 {
        List[] g;
        int n;

        List<Integer> id5;
        boolean[] vis;

        int[] euler;
        int[] id4;
        int[] h;

        public id7(List[] g, int n) {
            this.g = g;
            this.n = n;
            this.vis = new boolean[n];
            this.euler = new int[2 * n - 1];
            this.id4 = new int[2 * n - 1];
            this.h = new int[n];
            this.id5 = new ArrayList<>();
        }

        List<Integer> id5() {
            dfs(0, -1, 0);
            return id5;
        }

        int ind = 0;

        void dfs(int u, int p, int cd) {
            vis[u] = true;
            id5.add(u);
            euler[ind] = u;
            id4[ind] = cd;
            h[u] = ind;
            ind++;
            for (Integer v : (List<Integer>) g[u]) {
                if (v != p && !vis[v]) {
                    dfs(v, u, cd + 1);
                    euler[ind] = u;
                    id4[ind] = cd;
                    ind++;
                    id5.add(u);
                }
            }
        }
    }

    public void solve(long testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();

        int q = in.nextInt();

        List[] g = new List[n];

        in.readTree(g, n, 1);

        id7 ett = new id7(g, n);
        ett.dfs(0, -1, 0);

        int[] seg = new int[n];

        for (int i = 0; i < n; i++) {
            seg[i] = ett.h[i];
        }

        id12 minst = new id12(n, seg);

        minst.build(0, 0, n - 1);

        id16 maxst = new id16(n, seg);

        maxst.build(0, 0, n - 1);

        id12 id11 = new id12(2 * n - 1, ett.id4);

        id11.build(0, 0, 2 * n - 2);

        for (int i = 0; i < q; i++) {
            int l = in.nextInt() - 1;
            int r = in.nextInt() - 1;

            minst.init();
            maxst.init();
            int min = seg[minst.query(0, 0, n - 1, l, r)];

            minst.des(minst.ind, minst.rae, minst.rbe, min);

            int mini = minst.ans;

            int max = seg[maxst.query(0, 0, n - 1, l, r)];

            maxst.des(maxst.ind, maxst.rae, maxst.rbe, max);

            int maxi = maxst.ans;

            int minv = inf;
            int maxv = -1;

            if (l <= mini - 1)
                minv = seg[minst.query(0, 0, n - 1, l, mini - 1)];

            if (mini < r)
                minv = Math.min(minv, seg[minst.query(0, 0, n - 1, mini + 1, r)]);

            if (l <= mini - 1)
                maxv = seg[maxst.query(0, 0, n - 1, l, mini - 1)];

            if (mini < r)
                maxv = Math.max(maxv, seg[maxst.query(0, 0, n - 1, mini + 1, r)]);

            int ans1 = ett.id4[id11.query(0, 0, 2 * n - 2, minv, maxv)];

            minv = inf;
            maxv = -1;

            if (l <= maxi - 1)
                minv = seg[minst.query(0, 0, n - 1, l, maxi - 1)];

            if (maxi < r)
                minv = Math.min(minv, seg[minst.query(0, 0, n - 1, maxi + 1, r)]);

            if (l <= maxi - 1)
                maxv = seg[maxst.query(0, 0, n - 1, l, maxi - 1)];

            if (maxi < r)
                maxv = Math.max(maxv, seg[maxst.query(0, 0, n - 1, maxi + 1, r)]);

            int ans2 = ett.id4[id11.query(0, 0, 2 * n - 2, minv, maxv)];

            if (ans1 >= ans2) {
                out.println((mini + 1) + " " + ans1);
            } else {
                out.println((maxi + 1) + " " + ans2);
            }
        }


    }


    int inf = 10000000;

    class id12 {

        int[] st;
        int[] a;
        int n;

        public id12(int n, int[] a) {
            this.a = a;
            st = new int[4 * n];
            this.n = n;
        }

        int build(int i, int r1, int r2) {
            if (r1 == r2) {
                st[i] = r1;
                return st[i];
            } else {
                int fi = build(i * 2 + 1, r1, (r1 + r2) / 2);
                int si = build(i * 2 + 2, (r1 + r2) / 2 + 1, r2);

                st[i] = (a[fi] <= a[si]) ? fi : si;

                return st[i];
            }
        }

        int query(int i, int ra, int rb, int r1, int r2) {
            if (ra > r2 || rb < r1) {
                return -1;
            }

            if (ra >= r1 && rb <= r2) {
                if (min == -1 || a[st[i]] < min) {
                    min = a[st[i]];
                    rae = ra;
                    rbe = rb;
                    ind = i;
                }
                return st[i];
            }

            int p1 = query(i * 2 + 1, ra, (ra + rb) / 2, r1, r2);
            int p2 = query(i * 2 + 2, (ra + rb) / 2 + 1, rb, r1, r2);

            if (p1 == -1) {
                return p2;
            } else if (p2 == -1) {
                return p1;
            } else {
                return a[p1] <= a[p2] ? p1 : p2;
            }
        }

        void init() {
            rae = -1;
            rbe = -1;
            min = -1;
            ans = -1;
            ind = -1;
        }

        int ind = -1;
        int rae = -1;
        int rbe = -1;
        int min = -1;
        int ans = -1;

        void des(int i, int r1, int r2, int min) {
            if (r1 == r2) {
                ans = r1;
            } else {
                if (a[st[i * 2 + 1]] == min) {
                    des(i * 2 + 1, r1, (r1 + r2) / 2, min);
                } else {
                    des(i * 2 + 2, (r1 + r2) / 2 + 1, r2, min);
                }
            }
        }
    }

    class id16 {

        int[] st;
        int[] a;
        int n;

        public id16(int n, int[] a) {
            this.a = a;
            st = new int[4 * n];
            this.n = n;
        }

        int build(int i, int r1, int r2) {
            if (r1 == r2) {
                st[i] = r1;
                return st[i];
            } else {
                int fi = build(i * 2 + 1, r1, (r1 + r2) / 2);
                int si = build(i * 2 + 2, (r1 + r2) / 2 + 1, r2);

                st[i] = (a[fi] >= a[si]) ? fi : si;

                return st[i];
            }
        }

        int query(int i, int ra, int rb, int r1, int r2) {
            if (ra > r2 || rb < r1) {
                return -1;
            }

            if (ra >= r1 && rb <= r2) {
                if (min == -1 || a[st[i]] > min) {
                    min = a[st[i]];
                    rae = ra;
                    rbe = rb;
                    ind = i;
                }
                return st[i];
            }

            int p1 = query(i * 2 + 1, ra, (ra + rb) / 2, r1, r2);
            int p2 = query(i * 2 + 2, (ra + rb) / 2 + 1, rb, r1, r2);

            if (p1 == -1) {
                return p2;
            } else if (p2 == -1) {
                return p1;
            } else {
                return a[p1] >= a[p2] ? p1 : p2;
            }
        }

        void init() {
            rae = -1;
            rbe = -1;
            min = -1;
            ans = -1;
            ind = -1;
        }

        int ind = -1;
        int rae = -1;
        int rbe = -1;
        int min = -1;
        int ans = -1;

        void des(int i, int r1, int r2, int min) {
            if (r1 == r2) {
                ans = r1;
            } else {
                if (a[st[i * 2 + 1]] == min) {
                    des(i * 2 + 1, r1, (r1 + r2) / 2, min);
                } else {
                    des(i * 2 + 2, (r1 + r2) / 2 + 1, r2, min);
                }
            }
        }

    }


    class SegmentTree {
        long[] st;
        int n;

        public SegmentTree(int n) {
            st = new long[4 * n];
            this.n = n;
        }

        void build(int i, int[] a, int r1, int r2) {
            if (r1 == r2) {
                st[i] = a[r1];
            } else {
                build(i * 2 + 1, a, r1, (r1 + r2) / 2);
                build(i * 2 + 2, a, (r1 + r2) / 2 + 1, r2);

                st[i] = st[i * 2 + 1] + st[i * 2 + 2];
            }
        }

        long query(int i, int ra, int rb, int r1, int r2) {
            if (ra > r2 || rb < r1) {
                return 0;
            }

            if (ra >= r1 && rb <= r2) {
                return st[i];
            }

            long p1 = query(i * 2 + 1, ra, (ra + rb) / 2, r1, r2);
            long p2 = query(i * 2 + 2, (ra + rb) / 2 + 1, rb, r1, r2);

            return p1 + p2;
        }

        long update(int i, int ra, int rb, int ind, long val) {
            if (ra == rb && rb == ind) {
                st[i] = val;
                return st[i];
            }

            if (ra > ind || rb < ind) {
                return st[i];
            }

            long p1 = update(i * 2 + 1, ra, (ra + rb) / 2, ind, val);
            long p2 = update(i * 2 + 2, (ra + rb) / 2 + 1, rb, ind, val);

            return st[i] = p1 + p2;
        }
    }

    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        id6 solver = new id6();
        solver.solve(1, in, out);
        out.close();
    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void print(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(objects[i]);
            }
        }

        public void println(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
        }

        public void println(long i) {
            writer.println(i);
        }

    }

    static class InputReader {
        private boolean finished = false;

        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private id18 filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
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

        public int peek() {
            if (numChars == -1) {
                return -1;
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    return -1;
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar];
        }

        public int nextInt() {
            int c = read();
            while (id3(c)) {
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
            } while (!id3(c));
            return res * sgn;
        }

        public long nextLong() {
            int c = read();
            while (id3(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!id3(c));
            return res * sgn;
        }

        public String nextString() {
            int c = read();
            while (id3(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                if (Character.isValidCodePoint(c)) {
                    res.appendCodePoint(c);
                }
                c = read();
            } while (!id3(c));
            return res.toString();
        }

        public boolean id3(int c) {
            if (filter != null) {
                return filter.id3(c);
            }
            return isWhitespace(c);
        }

        private String id0() {
            StringBuilder buf = new StringBuilder();
            int c = read();
            while (c != '\n' && c != -1) {
                if (c != '\r') {
                    buf.appendCodePoint(c);
                }
                c = read();
            }
            return buf.toString();
        }

        public String readLine() {
            String s = id0();
            while (s.trim().length() == 0) {
                s = id0();
            }
            return s;
        }

        public String readLine(boolean id17) {
            if (id17) {
                return readLine();
            } else {
                return id0();
            }
        }

        public BigInteger id13() {
            try {
                return new BigInteger(nextString());
            } catch (NumberFormatException e) {
                throw new InputMismatchException();
            }
        }

        public char nextCharacter() {
            int c = read();
            while (id3(c)) {
                c = read();
            }
            return (char) c;
        }

        public double nextDouble() {
            int c = read();
            while (id3(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            double res = 0;
            while (!id3(c) && c != '.') {
                if (c == 'e' || c == 'E') {
                    return res * Math.pow(10, nextInt());
                }
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            }
            if (c == '.') {
                c = read();
                double m = 1;
                while (!id3(c)) {
                    if (c == 'e' || c == 'E') {
                        return res * Math.pow(10, nextInt());
                    }
                    if (c < '0' || c > '9') {
                        throw new InputMismatchException();
                    }
                    m /= 10;
                    res += (c - '0') * m;
                    c = read();
                }
            }
            return res * sgn;
        }

        public boolean id2() {
            int value;
            while (id3(value = peek()) && value != -1) {
                read();
            }
            return value == -1;
        }

        public String next() {
            return nextString();
        }

        public id18 getFilter() {
            return filter;
        }

        public void setFilter(id18 filter) {
            this.filter = filter;
        }

        public int[] id8(int n) {
            int[] array = new int[n];
            for (int i = 0; i < n; ++i) array[i] = nextInt();
            return array;
        }

        public int[] id10(int n) {
            int array[] = id8(n);
            Arrays.sort(array);
            return array;
        }

        public int[] id14(int n) {
            int[] array = new int[n];
            array[0] = nextInt();
            for (int i = 1; i < n; ++i) array[i] = array[i - 1] + nextInt();
            return array;
        }

        public long[] id20(int n) {
            long[] array = new long[n];
            for (int i = 0; i < n; ++i) array[i] = nextLong();
            return array;
        }

        public long[] id1(int n) {
            long[] array = new long[n];
            array[0] = nextInt();
            for (int i = 1; i < n; ++i) array[i] = array[i - 1] + nextInt();
            return array;
        }

        public long[] id9(int n) {
            long array[] = id20(n);
            Arrays.sort(array);
            return array;
        }

        public interface id18 {
            public boolean id3(int ch);
        }

        public void readTree(List[] g, int id15, int offset) {
            int id19 = id15 - 1;

            for (int i = 0; i < id15; i++) {
                g[i] = new ArrayList();
            }

            for (int i = 0; i < id19; i++) {
                int p = nextInt() - offset;

                g[p].add(i + 1);
                g[i + 1].add(p);
            }
        }
    }
}
