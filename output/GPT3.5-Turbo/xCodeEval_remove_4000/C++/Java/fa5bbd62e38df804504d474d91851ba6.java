import java.io.*;
import java.util.*;

class CPaintTree {
    static class Solver {
        private final BufferedReader in;
        private final PrintWriter out;

        Solver(BufferedReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
        }

        int n;
        List<List<Integer>> e;
        int[] subtree_sz;
        int[] xy_mapping;
        List<Pair<Double, Integer>> xys_idx;
        List<int[]> xy;

        void read_tree() throws IOException {
            e = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                e.add(new ArrayList<>());
            }
            for (int i = 0; i < n - 1; i++) {
                String[] parts = in.readLine().split(" ");
                int u = Integer.parseInt(parts[0]) - 1;
                int v = Integer.parseInt(parts[1]) - 1;
                e.get(u).add(v);
                e.get(v).add(u);
            }
        }

        void read_points() throws IOException {
            xy = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                String[] parts = in.readLine().split(" ");
                int x = Integer.parseInt(parts[0]);
                int y = Integer.parseInt(parts[1]);
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
                solve_rec(cur_l, cur_r, i, root);
                cur_l = cur_r + 1;
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

        void solve() throws IOException {
            n = Integer.parseInt(in.readLine());
            subtree_sz = new int[n];
            read_tree();
            read_points();
            xy_mapping = new int[n];
            calculate_subtree_sizes(0, -1);
            xys_idx = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                xys_idx.add(new Pair<>(0.0, i));
            }
            xy_mapping = new int[n];
            calculate_subtree_sizes(0, -1);
            for (int i = 0; i < n; i++) {
                xy_mapping[i]++;
            }
            for (int i : xy_mapping) {
                out.print(i + " ");
            }
            out.println();
        }
    }

    public static void solve(InputStream in, PrintWriter out) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(in));
        Solver solver = new Solver(reader, out);
        solver.solve();
        out.flush();
    }

    public static void main(String[] args) throws IOException {
        InputStream in = System.in;
        PrintWriter out = new PrintWriter(System.out);
        solve(in, out);
    }
}
