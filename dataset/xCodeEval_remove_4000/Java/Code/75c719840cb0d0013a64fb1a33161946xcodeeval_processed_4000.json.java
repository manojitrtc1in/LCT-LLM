import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.Random;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.InputStream;


public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        id5 solver = new id5();
        solver.solve(1, in, out);
        out.close();
    }

    static class id5 {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            if (false) {
                new Tester().test();
            }
            int n = in.readInt();
            long[] a = in.id4(n);
            long[] k = in.id4(n - 1);
            int q = in.readInt();
            int[][] queries = new int[q][3];
            for (int i = 0; i < q; i++) {
                queries[i][0] = in.next().equals("+") ? 0 : 1;
                queries[i][1] = in.readInt();
                queries[i][2] = in.readInt();
            }
            long[] answer = new id5.Solve().solve(n, a, k, q, queries);
            for (long x : answer) {
                out.printLine(x);
            }
        }

        class Tester {
            Random rnd = new Random(239);

            void test() {
                for (int t = 0; ; t++) {
                    int n = rnd.nextInt(10) + 2;
                    long[] a = new long[n];
                    for (int i = 0; i < n; i++) {
                        a[i] = rnd.nextInt(21) - 10;
                    }
                    long[] k = new long[n - 1];
                    for (int i = 0; i < n - 1; i++) {
                        k[i] = rnd.nextInt(21) - 10;
                    }
                    boolean ok = true;
                    for (int i = 0; i < n - 1; i++) {
                        ok &= a[i] + k[i] <= a[i + 1];
                    }
                    if (!ok) {
                        continue;
                    }
                    int q = rnd.nextInt(100) + 1;
                    int[][] queries = new int[q][3];
                    for (int i = 0; i < q; i++) {
                        queries[i][0] = rnd.nextInt(2);
                        if (queries[i][0] == 0) {
                            queries[i][1] = rnd.nextInt(n) + 1;
                            queries[i][2] = rnd.nextInt(10);
                        } else {
                            queries[i][1] = rnd.nextInt(n) + 1;
                            int len = n - queries[i][1];
                            queries[i][2] = queries[i][1] + (len == 0 ? 0 : rnd.nextInt(len + 1));
                        }
                    }
                    long[] naive = new Naive().solve(n, a.clone(), k.clone(), q, queries);
                    long[] solve = new id5.Solve().solve(n, a.clone(), k.clone(), q, queries);
                    if (!Arrays.equals(naive, solve)) {
                        System.err.println(n);
                        for (long x : a) {
                            System.err.print(x + " ");
                        }
                        System.err.println();
                        for (long x : k) {
                            System.err.print(x + " ");
                        }
                        System.err.println();
                        System.err.println(q);
                        for (int[] qu : queries) {
                            System.err.printf("%s %d %d\n", qu[0] == 0 ? "+" : "s", qu[1], qu[2]);
                        }
                        System.err.println(Arrays.toString(naive));
                        System.err.println(Arrays.toString(solve));
                        new Naive().solve(n, a.clone(), k.clone(), q, queries);
                    }
                }
            }

        }

        class Naive {
            long[] solve(int n, long[] a, long[] k, int q, int[][] queries) {
                int askCount = 0;
                for (int[] qu : queries) {
                    askCount += qu[0];
                }
                long[] answer = new long[askCount];
                askCount = 0;
                for (int[] qu : queries) {
                    if (qu[0] == 0) {
                        int at = qu[1] - 1;
                        int val = qu[2];
                        a[at] += val;
                        while (at + 1 < n && a[at + 1] < a[at] + k[at]) {
                            a[at + 1] = a[at] + k[at];
                            at++;
                        }
                    } else {
                        int l = qu[1] - 1;
                        int r = qu[2] - 1;
                        long s = 0;
                        for (int i = l; i <= r; i++) {
                            s += a[i];
                        }
                        answer[askCount++] = s;
                    }
                }
                return answer;
            }

        }

        static class Solve {
            id5.Solve.Treap root;
            int n;
            long[] a;
            long[] k;
            long[] pk;
            long[] sumfk;
            static Random rnd = new Random(239);

            long[] solve(int n, long[] a, long[] k, int q, int[][] queries) {
                buildBase(n, a, k);
                root = null;
                for (int i = 0; i < n; i++) {
                    root = id5.Solve.Treap.merge(root, id2(i, i));
                }
                int askCount = 0;
                for (int[] qu : queries) {
                    askCount += qu[0];
                }
                long[] answer = new long[askCount];
                askCount = 0;
                for (int[] qu : queries) {
                    if (qu[0] == 0) {
                        int at = qu[1] - 1;
                        int val = qu[2];
                        update(at, val);
                    } else {
                        int l = qu[1] - 1;
                        int r = qu[2] - 1;
                        long res = getSum(l, r);
                        answer[askCount++] = res;
                    }
                }
                return answer;
            }

            void prepare(int at) {
                id5.Solve.Split split1 =
                        id5.Solve.Treap.id8(root, at);
                id5.Solve.Split split2 =
                        id5.Solve.Treap.id0(split1.left, split1.left.size - 1);
                id5.Solve.Treap middle = split2.right;
                id5.Solve.Treap newLeft = null, newRight = null;
                id1 s = middle.segment;
                if (s.first < at) {
                    a[at - 1] = getValue(at - 1, s);
                }
                if (at < s.second) {
                    a[at + 1] = getValue(at + 1, s);
                }
                a[at] = getValue(at, s);
                if (s.first < at) {
                    newLeft = id2(s.first, at - 1);
                }
                if (at < s.second) {
                    newRight = id2(at + 1, s.second);
                }
                middle = id5.Solve.Treap.merge(newLeft, id2(at, at), newRight);
                root = id5.Solve.Treap.merge(split2.left, middle, split1.right);
            }

            void update(int at, long value) {
                prepare(at);
                id5.Solve.Split split =
                        id5.Solve.Treap.id8(root, at);
                id5.Solve.Treap t1 = split.left;
                id5.Solve.Treap t2 = split.right;
                a[at] += value;
                t1 = id5.Solve.Treap.id0(t1, t1.size - 1).left;
                t1 = id5.Solve.Treap.merge(t1, id2(at));
                while (t2 != null) {
                    id5.Solve.Treap left = t1.last();
                    id5.Solve.Treap right = t2.first();
                    long newValue = getValue(left.segment.second, left.segment) + k[left.segment.second];
                    long oldValue = getValue(right.segment.first, right.segment);
                    if (newValue > oldValue) {
                        id5.Solve.Treap middle =
                                id2(left.segment.first, right.segment.second);
                        t1 = id5.Solve.Treap.id0(t1, t1.size - 1).left;
                        t1 = id5.Solve.Treap.merge(t1, middle);
                        t2 = id5.Solve.Treap.id0(t2, 1).right;
                    } else {
                        break;
                    }
                }
                root = id5.Solve.Treap.merge(t1, t2);
            }

            long getSum(int l, int r) {
                prepare(l);
                prepare(r);
                id5.Solve.Split split1 =
                        id5.Solve.Treap.id8(root, l - 1);
                id5.Solve.Split split2 =
                        id5.Solve.Treap.id8(split1.right, r);
                long res = split2.left.fullSum;
                root = id5.Solve.Treap.merge(split1.left, split2.left, split2.right);
                return res;
            }

            void buildBase(int n, long[] a, long[] k) {
                this.n = n;
                this.a = a;
                this.k = k;
                pk = new long[n + 1];
                for (int i = 0; i < n - 1; i++) {
                    pk[i + 1] = pk[i] + k[i];
                }
                pk[n] = pk[n - 1];
                sumfk = new long[n];
                for (int i = n - 2, j = 1; i >= 0; i--, j++) {
                    sumfk[i] = k[i] * j;
                    sumfk[i] += sumfk[i + 1];
                }
            }

            long id6(int l, int r) {
                return pk[r + 1] - pk[l];
            }

            long getFK(int l, int r) {
                long x = sumfk[l];
                if (r + 1 < n) {
                    x -= sumfk[r + 1];
                }
                int times = n - r - 1;
                x -= times * id6(l, r);
                return x;
            }

            long id9(id1 seg) {
                int len = seg.second - seg.first + 1;
                return a[seg.first] * len + getFK(seg.first, seg.second);
            }

            long getValue(int at, id1 seg) {
                int shift = at - seg.first;
                return a[at] = a[seg.first] + id6(seg.first, seg.first + shift - 1);
            }

            id5.Solve.Treap id2(int at) {
                return id2(at, at);
            }

            id5.Solve.Treap id2(int l, int r) {
                id1 p = id1.makePair(l, r);
                return new id5.Solve.Treap(p, id9(p));
            }

            static class Treap {
                long priority;
                id5.Solve.Treap left;
                id5.Solve.Treap right;
                int size;
                id1 segment;
                long segmentSum;
                long fullSum;

                Treap(id1 seg, long segmentSum) {
                    priority = rnd.nextLong();
                    this.segment = seg;
                    this.segmentSum = segmentSum;
                    update();
                }

                static id5.Solve.Treap merge(id5.Solve.Treap t1,
                                                                   id5.Solve.Treap t2) {
                    if (t1 == null) {
                        return t2;
                    }
                    if (t2 == null) {
                        return t1;
                    }
                    if (t1.priority > t2.priority) {
                        t1.right = merge(t1.right, t2);
                        t1.update();
                        return t1;
                    } else {
                        t2.left = merge(t1, t2.left);
                        t2.update();
                        return t2;
                    }
                }

                id5.Solve.Treap last() {
                    id5.Solve.Treap t = this;
                    while (t.right != null) {
                        t = t.right;
                    }
                    return t;
                }

                id5.Solve.Treap first() {
                    id5.Solve.Treap t = this;
                    while (t.left != null) {
                        t = t.left;
                    }
                    return t;
                }

                static id5.Solve.Treap merge(id5.Solve.Treap t1,
                                                                   id5.Solve.Treap t2,
                                                                   id5.Solve.Treap t3) {
                    return merge(t1, merge(t2, t3));
                }

                static id5.Solve.Split id0(id5.Solve.Treap t,
                                                                         int leftSize) {
                    if (t == null) {
                        return id5.Solve.Split.empty;
                    }
                    int sz = 1 + size(t.left);
                    if (sz > leftSize) {
                        id5.Solve.Split split = id0(t.left, leftSize);
                        t.left = split.right;
                        t.update();
                        return new id5.Solve.Split(split.left, t);
                    } else {
                        id5.Solve.Split split = id0(t.right, leftSize - sz);
                        t.right = split.left;
                        t.update();
                        return new id5.Solve.Split(t, split.right);
                    }
                }

                static id5.Solve.Split id8(id5.Solve.Treap t,
                                                                           int border) {
                    if (t == null) {
                        return id5.Solve.Split.empty;
                    }
                    if (t.segment.first <= border) {
                        id5.Solve.Split split = id8(t.right, border);
                        t.right = split.left;
                        t.update();
                        return new id5.Solve.Split(t, split.right);
                    } else {
                        id5.Solve.Split split = id8(t.left, border);
                        t.left = split.right;
                        t.update();
                        return new id5.Solve.Split(split.left, t);
                    }
                }

                void update() {
                    size = 1 + size(left) + size(right);
                    fullSum = segmentSum + sum(left) + sum(right);
                }

                static long sum(id5.Solve.Treap t) {
                    if (t == null) {
                        return 0;
                    }
                    return t.fullSum;
                }

                static int size(id5.Solve.Treap t) {
                    if (t == null) {
                        return 0;
                    }
                    return t.size;
                }

            }

            static class Split {
                id5.Solve.Treap left;
                id5.Solve.Treap right;
                static id5.Solve.Split empty =
                        new id5.Solve.Split(null, null);

                Split(id5.Solve.Treap left, id5.Solve.Treap right) {
                    this.left = left;
                    this.right = right;
                }

            }

        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.id7 filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public long[] id4(int size) {
            long[] array = new long[size];
            for (int i = 0; i < size; i++) {
                array[i] = readLong();
            }
            return array;
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

        public long readLong() {
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

        public String readString() {
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

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public String next() {
            return readString();
        }

        public interface id7 {
            public boolean id3(int ch);

        }

    }

    static class id1 implements Comparable<id1> {
        public final int first;
        public final int second;

        public static id1 makePair(int first, int second) {
            return new id1(first, second);
        }

        public id1(int first, int second) {
            this.first = first;
            this.second = second;
        }

        public boolean equals(Object o) {
            if (this == o) {
                return true;
            }
            if (o == null || getClass() != o.getClass()) {
                return false;
            }

            id1 pair = (id1) o;

            return first == pair.first && second == pair.second;
        }

        public int hashCode() {
            int result = first;
            result = 31 * result + second;
            return result;
        }

        public String toString() {
            return "(" + first + "," + second + ")";
        }

        public int compareTo(id1 o) {
            int value = Integer.compare(first, o.first);
            if (value != 0) {
                return value;
            }
            return Integer.compare(second, o.second);
        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void close() {
            writer.close();
        }

        public void printLine(long i) {
            writer.println(i);
        }

    }
}

