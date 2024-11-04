import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.function.BiFunction;
import java.util.Collection;
import java.util.Set;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Objects;
import java.util.List;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Queue;
import java.util.LinkedList;
import java.io.InputStream;


public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        id1 solver = new id1();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class id1 {
        public void solve(int testNumber, InputReader in, OutputWriter out) {


            int n = in.nextInt();
            int m = in.nextInt();
            String[] map = new String[n];
            for (int i = 0; i < n; i++) {
                map[i] = in.nextString();
            }
            String[] dir = new String[n];
            for (int i = 0; i < n; i++) {
                dir[i] = in.nextString();
            }
            BiFunction<Integer, Integer, Integer> id2 = (i, j) -> (i * m + j);








































            

            int[][] indeg = new int[n][m];
            Set<Integer> st = new HashSet<>();
            int mx = n * m;
            for (int i = 0; i < mx; i++) {
                st.add(i);
            }
            for (int i = 0; i < n; i++) {




                for (int j = 0; j < m; j++) {






                    int nxi = next(i, j, id2, dir);
                    st.remove(nxi);
                    int di = nxi / m;
                    int dj = nxi % m;
                    indeg[di][dj]++;


                }
            }




            Queue<Integer> q = new LinkedList<>(st);














            while (!q.isEmpty()) {


                int u = q.poll();
                int nx = next(u / m, u % m, id2, dir);






                int ni = nx / m;
                int nj = nx % m;
                indeg[ni][nj]--;
                if (indeg[ni][nj] == 0) {


                    q.add(nx);
                }
            }

            boolean[][] done = new boolean[n][m];
            boolean[][] place = new boolean[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (indeg[i][j] != 0 && !done[i][j]) {
                        List<Integer> cycle = new ArrayList<>();
                        int thisInd = id2.apply(i, j);
                        int curr = thisInd;
                        do {
                            cycle.add(curr);
                            done[curr / m][curr % m] = true;
                            curr = next(curr / m, curr % m, id2, dir);
                        } while (curr != thisInd);
                        int nn = cycle.size();
                        for (int k = 0; k < nn; ++k) {
                            int node = cycle.get(k);
                            Queue<Pair<Integer, Integer>> queue = new LinkedList<>();
                            queue.add(Pair.of(node, 0));
                            int ni = node / m;
                            int nj = node % m;
                            if (map[ni].charAt(nj) == '0') {
                                place[ni][nj] = true;
                            }

                            while (!queue.isEmpty()) {
                                Pair<Integer, Integer> u = queue.poll();
                                int indu = u.getLeft();
                                int r = indu / m;
                                int c = indu % m;
                                process(r - 1, c, n, m, indu, indeg, queue, id2, dir, u, k, nn, map, place, cycle);
                                process(r + 1, c, n, m, indu, indeg, queue, id2, dir, u, k, nn, map, place, cycle);
                                process(r, c + 1, n, m, indu, indeg, queue, id2, dir, u, k, nn, map, place, cycle);
                                process(r, c - 1, n, m, indu, indeg, queue, id2, dir, u, k, nn, map, place, cycle);
















                            }
                        }
                    }
                }
            }

            int fans = 0;
            int sans = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (indeg[i][j] != 0) {
                        fans++;
                        if (place[i][j]) {
                            sans++;
                        }
                    }
                }
            }
            out.println(fans + " " + sans);






























































































































































































































        }

        private int next(int i, int j, BiFunction<Integer, Integer, Integer> id2, String[] dir) {
            switch (dir[i].charAt(j)) {
                case 'U':
                    return id2.apply(i - 1, j);
                case 'D':
                    return id2.apply(i + 1, j);
                case 'L':
                    return id2.apply(i, j - 1);
                case 'R':
                default:
                    return id2.apply(i, j + 1);
            }
        }

        private void process(int i, int j, int n, int m, int indu, int[][] indeg, Queue<Pair<Integer, Integer>> queue,
                             BiFunction<Integer, Integer, Integer> id2, String[] dir, Pair<Integer, Integer> u,
                             int k, int nn, String[] map, boolean[][] place, List<Integer> cycle) {
            if (i >= 0 && i < n && j >= 0 && j < m) {
                if (next(i, j, id2, dir) == indu && indeg[i][j] == 0) {
                    int steps = u.getRight() + 1;
                    int nodeIndex = cycle.get(MathUtility.sub(k, steps % nn, nn));
                    if (map[i].charAt(j) == '0') {
                        place[nodeIndex / m][nodeIndex % m] = true;
                    }
                    queue.add(Pair.of(id2.apply(i, j), steps));
                }
            }
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

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.id3 filter;

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

        public int nextInt() {
            int c = read();
            while (id0(c)) {
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
            } while (!id0(c));
            return res * sgn;
        }

        public String nextString() {
            int c = read();
            while (id0(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                if (Character.isValidCodePoint(c)) {
                    res.appendCodePoint(c);
                }
                c = read();
            } while (!id0(c));
            return res.toString();
        }

        public boolean id0(int c) {
            if (filter != null) {
                return filter.id0(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public String next() {
            return nextString();
        }

        public interface id3 {
            public boolean id0(int ch);

        }

    }

    static class MathUtility {
        public static int sub(int a, int b, int MOD) {
            return add(a, MOD - b, MOD);
        }

        public static int add(int a, int b, int MOD) {
            int res = a + b;
            if (res >= MOD) {
                res -= MOD;
            }
            return res;
        }

    }

    static class Pair<L, R> {
        private L left;
        private R right;

        private Pair(L left, R right) {
            this.left = left;
            this.right = right;
        }

        public L getLeft() {
            return left;
        }

        public R getRight() {
            return right;
        }

        public static <A, B> Pair<A, B> of(A a, B b) {
            return new Pair<>(a, b);
        }

        public String toString() {
            return "Pair{" +
                    "left=" + left +
                    ", right=" + right +
                    '}';
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Pair<?, ?> pair = (Pair<?, ?>) o;
            return Objects.equals(left, pair.left) &&
                    Objects.equals(right, pair.right);
        }

        public int hashCode() {
            return Objects.hash(left, right);
        }

    }
}

