import java.io.*;
import java.util.*;

class CPaintTree {
    static class Solver {
        private final InputReader in;
        private final OutputWriter out;

        public Solver(InputReader in, OutputWriter out) {
            this.in = in;
            this.out = out;
        }

        int n;
        List<List<Integer>> e;
        int[] subtree_sz;
        int[] xy_mapping;
        List<Pair<Double, Integer>> xys_idx;
        List<int[]> xy;

        void read_tree() {
            e = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                e.add(new ArrayList<>());
            }
            for (int i = 0; i < n - 1; i++) {
                int u = in.nextInt() - 1;
                int v = in.nextInt() - 1;
                e.get(u).add(v);
                e.get(v).add(u);
            }
        }

        void read_points() {
            xy = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                int x = in.nextInt();
                int y = in.nextInt();
                xy.add(new int[]{x, y});
            }
        }

        long x_dist(int i, int j) {
            return xy.get(j)[0] - xy.get(i)[0];
        }

        long y_dist(int i, int j) {
            return xy.get(j)[1] - xy.get(i)[1];
        }

        double get_angle(int i, int j) {
            return Math.atan2(y_dist(i, j), x_dist(i, j));
        }

        void sort_by_angel(int l, int r, int cur_xy) {
            if (r < l) return;
            for (int i = l; i <= r; i++) {
                xys_idx.get(i).first = get_angle(cur_xy, xys_idx.get(i).second);
            }
            double max_angle = xys_idx.get(l).first;
            for (int i = l; i <= r; i++) {
                max_angle = Math.max(max_angle, xys_idx.get(i).first);
            }
            for (int i = l; i <= r; i++) {
                if (xys_idx.get(i).first + Math.PI < max_angle) {
                    xys_idx.get(i).first += 2 * Math.PI;
                }
            }
            Collections.sort(xys_idx.subList(l, r + 1));
        }

        void solve_rec(int l, int r, int root, int parent) {
            int curr_xy = xys_idx.get(r--).second;
            xy_mapping[curr_xy] = root;
            sort_by_angel(l, r, curr_xy);
            int cur_l = l;
            for (int i : e.get(root)) {
                if (i == parent) continue;
                int cur_r = cur_l + subtree_sz[i] - 1;
                int nxt_l = cur_r + 1;
                solve_rec(cur_l, cur_r, i, root);
                cur_l = nxt_l;
            }
        }

        void calculate_subtree_sizes(int i, int p) {
            subtree_sz[i] = 1;
            for (int j : e.get(i)) {
                if (j == p) continue;
                calculate_subtree_sizes(j, i);
                subtree_sz[i] += subtree_sz[j];
            }
        }

        void solve() {
            n = in.nextInt();
            subtree_sz = new int[n];
            read_tree();
            read_points();
            xy_mapping = new int[n];
            calculate_subtree_sizes(0, -1);
            xys_idx = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                xys_idx.add(new Pair<>(0.0, i));
            }
            xys_idx.sort((i, j) -> {
                int[] xyi = xy.get(i.second);
                int[] xyj = xy.get(j.second);
                if (xyi[0] != xyj[0]) {
                    return xyj[0] - xyi[0];
                } else {
                    return xyj[1] - xyi[1];
                }
            });
            solve_rec(0, n - 1, 0, -1);
            for (int i = 0; i < n; i++) {
                xy_mapping[i]++;
            }
            out.println(xy_mapping);
        }
    }

    public static void solve(InputReader in, OutputWriter out) {
        Solver solver = new Solver(in, out);
        solver.solve();
    }

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        OutputWriter out = new OutputWriter(System.out);
        solve(in, out);
        out.close();
    }

    static class InputReader {
        private final BufferedReader reader;
        private StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public int[] nextIntArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = nextInt();
            }
            return a;
        }

        public long[] nextLongArray(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++) {
                a[i] = nextLong();
            }
            return a;
        }
    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream stream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(stream)));
        }

        public void println(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(objects[i]);
            }
            writer.println();
        }

        public void close() {
            writer.close();
        }
    }

    static class Pair<F, S> {
        public final F first;
        public final S second;

        public Pair(F first, S second) {
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
            Pair<?, ?> pair = (Pair<?, ?>) o;
            return Objects.equals(first, pair.first) && Objects.equals(second, pair.second);
        }

        public int hashCode() {
            return Objects.hash(first, second);
        }

        public String toString() {
            return "(" + first + ", " + second + ")";
        }
    }
}
