import java.io.*;
import java.util.*;

class CPaintTree {
    static class Solver {
        private final InputReader in;
        private final OutputWriter out;

        Solver(InputReader in, OutputWriter out) {
            this.in = in;
            this.out = out;
        }

        int n;
        List<List<Integer>> e;
        int[] subtree_sz;
        int[] xy_mapping;
        List<Pair<Double, Integer>> xys_idx;
        List<int[]> xy;

        void readTree() {
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

        void readPoints() {
            xy = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                int[] point = new int[2];
                point[0] = in.nextInt();
                point[1] = in.nextInt();
                xy.add(point);
            }
        }

        long xDist(int i, int j) {
            return xy.get(j)[0] - xy.get(i)[0];
        }

        long yDist(int i, int j) {
            return xy.get(j)[1] - xy.get(i)[1];
        }

        double getAngle(int i, int j) {
            return Math.atan2(yDist(i, j), xDist(i, j));
        }

        void sortByAngle(int l, int r, int cur_xy) {
            if (r < l) return;
            for (int i = l; i <= r; i++) {
                xys_idx.get(i).first = getAngle(cur_xy, xys_idx.get(i).second);
            }
            double maxAngle = xys_idx.get(l).first;
            for (int i = l; i <= r; i++) {
                maxAngle = Math.max(maxAngle, xys_idx.get(i).first);
            }
            for (int i = l; i <= r; i++) {
                if (xys_idx.get(i).first + Math.PI < maxAngle) {
                    xys_idx.get(i).first += 2 * Math.PI;
                }
            }
            Collections.sort(xys_idx.subList(l, r + 1));
        }

        void solveRec(int l, int r, int root, int parent) {
            int curr_xy = xys_idx.get(r--).second;
            xy_mapping[curr_xy] = root;
            sortByAngle(l, r, curr_xy);
            int cur_l = l;
            for (int i : e.get(root)) {
                if (i == parent) continue;
                int cur_r = cur_l + subtree_sz[i] - 1;
                int nxt_l = cur_r + 1;
                solveRec(cur_l, cur_r, i, root);
                cur_l = nxt_l;
            }
        }

        void calculateSubtreeSizes(int i, int p) {
            subtree_sz[i] = 1;
            for (int j : e.get(i)) {
                if (j == p) continue;
                calculateSubtreeSizes(j, i);
                subtree_sz[i] += subtree_sz[j];
            }
        }

        void solve() {
            n = in.nextInt();
            subtree_sz = new int[n];
            readTree();
            readPoints();
            xy_mapping = new int[n];
            calculateSubtreeSizes(0, -1);
            xys_idx = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                xys_idx.add(new Pair<>(0.0, i));
            }
            xys_idx.sort((i, j) -> {
                int[] pi = xy.get(i.second);
                int[] pj = xy.get(j.second);
                if (pi[0] != pj[0]) {
                    return pj[0] - pi[0];
                } else {
                    return pj[1] - pi[1];
                }
            });
            solveRec(0, n - 1, 0, -1);
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

        InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                tokenizer = new StringTokenizer(readLine());
            }
            return tokenizer.nextToken();
        }

        String readLine() {
            String line;
            try {
                line = reader.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
            return line;
        }
    }

    static class OutputWriter {
        private final PrintWriter writer;

        OutputWriter(OutputStream stream) {
            writer = new PrintWriter(stream);
        }

        void println(int[] arr) {
            for (int i = 0; i < arr.length; i++) {
                writer.print(arr[i]);
                writer.print(' ');
            }
            writer.println();
        }

        void close() {
            writer.close();
        }
    }

    static class Pair<T, U> {
        T first;
        U second;

        Pair(T first, U second) {
            this.first = first;
            this.second = second;
        }
    }
}
