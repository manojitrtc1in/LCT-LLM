import java.util.*;
import java.io.*;

class CPaintTree {
    static class Solver {
        BufferedReader in;
        PrintWriter out;

        int n;
        List<List<Integer>> e;
        int[] subtree_sz;
        int[] xy_mapping;
        Pair[] xys_idx;
        int[][] xy;

        Solver(BufferedReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
        }

        void read_tree() throws IOException {
            e.clear();
            e = new ArrayList<>(n);
            for (int i = 0; i < n; i++) e.add(new ArrayList<>());
            for (int i = 0; i < n - 1; i++) {
                StringTokenizer st = new StringTokenizer(in.readLine());
                int u = Integer.parseInt(st.nextToken()) - 1;
                int v = Integer.parseInt(st.nextToken()) - 1;
                e.get(u).add(v);
                e.get(v).add(u);
            }
        }

        void read_points() throws IOException {
            xy = new int[n][2];
            for (int i = 0; i < n; i++) {
                StringTokenizer st = new StringTokenizer(in.readLine());
                xy[i][0] = Integer.parseInt(st.nextToken());
                xy[i][1] = Integer.parseInt(st.nextToken());
            }
        }

        long x_dist(int i, int j) {
            return (long) xy[j][0] - (long) xy[i][0];
        }

        long y_dist(int i, int j) {
            return (long) xy[j][1] - (long) xy[i][1];
        }

        double get_angle(int i, int j) {
            return Math.atan2(y_dist(i, j), x_dist(i, j));
        }

        void sort_by_angle(int l, int r, int cur_xy) {
            if (r < l) return;
            for (int i = l; i <= r; i++) {
                xys_idx[i].first = get_angle(cur_xy, xys_idx[i].second);
            }
            double max_angle = xys_idx[l].first;
            for (int i = l; i <= r; i++) {
                max_angle = Math.max(max_angle, xys_idx[i].first);
            }
            for (int i = l; i <= r; i++) {
                if (xys_idx[i].first + Math.PI < max_angle) {
                    xys_idx[i].first += 2 * Math.PI;
                }
            }
            Arrays.sort(xys_idx, l, r + 1, Comparator.comparingDouble(a -> a.first));
        }

        void solve_rec(int l, int r, int root, int parent) {
            int curr_xy = xys_idx[r--].second;
            xy_mapping[curr_xy] = root;
            sort_by_angle(l, r, curr_xy);
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

        void solve() throws IOException {
            n = Integer.parseInt(in.readLine());
            subtree_sz = new int[n];
            read_tree();
            read_points();
            xy_mapping = new int[n];
            calculate_subtree_sizes(0, -1);
            xys_idx = new Pair[n];
            for (int i = 0; i < n; i++) xys_idx[i] = new Pair(0, i);
            Arrays.sort(xys_idx, (a, b) -> Integer.compare(xy[b.second][1], xy[a.second][1]));
            solve_rec(0, n - 1, 0, -1);
            for (int i = 0; i < n; i++) xy_mapping[i]++;
            for (int i : xy_mapping) out.print(i + " ");
            out.println();
        }
    }

    static class Pair {
        double first;
        int second;

        Pair(double first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    public static void solve(BufferedReader in, PrintWriter out) throws IOException {
        new Solver(in, out).solve();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        solve(in, out);
        out.close();
    }
}
