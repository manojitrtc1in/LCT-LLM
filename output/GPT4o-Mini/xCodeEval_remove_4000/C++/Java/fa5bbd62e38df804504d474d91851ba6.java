import java.util.*;
import java.util.function.*;
import java.io.*;

class CPaintTree {
    static class Solver {
        BufferedReader in;
        PrintWriter out;

        Solver(BufferedReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
        }

        int n;
        List<List<Integer>> e;
        int[] subtreeSz;
        int[] xyMapping;
        List<Pair<Double, Integer>> xysIdx;
        int[][] xy;

        void readTree() throws IOException {
            e.clear();
            e = new ArrayList<>(n);
            for (int i = 0; i < n; i++) e.add(new ArrayList<>());
            for (int i = 0; i < n - 1; i++) {
                String[] line = in.readLine().split(" ");
                int u = Integer.parseInt(line[0]) - 1;
                int v = Integer.parseInt(line[1]) - 1;
                e.get(u).add(v);
                e.get(v).add(u);
            }
        }

        void readPoints() throws IOException {
            xy = new int[n][2];
            for (int i = 0; i < n; i++) {
                String[] line = in.readLine().split(" ");
                xy[i][0] = Integer.parseInt(line[0]);
                xy[i][1] = Integer.parseInt(line[1]);
            }
        }

        long xDist(int i, int j) {
            return (long) xy[j][0] - (long) xy[i][0];
        }

        long yDist(int i, int j) {
            return (long) xy[j][1] - (long) xy[i][1];
        }

        double getAngle(int i, int j) {
            return Math.atan2(yDist(i, j), xDist(i, j));
        }

        void sortByAngle(int l, int r, int curXY) {
            if (r < l) return;
            for (int i = l; i <= r; i++) {
                xysIdx.get(i).first = getAngle(curXY, xysIdx.get(i).second);
            }
            double maxAngle = xysIdx.get(l).first;
            for (int i = l; i <= r; i++) {
                maxAngle = Math.max(maxAngle, xysIdx.get(i).first);
            }
            for (int i = l; i <= r; i++) {
                if (xysIdx.get(i).first + Math.PI < maxAngle) {
                    xysIdx.get(i).first += 2 * Math.PI;
                }
            }
            xysIdx.subList(l, r + 1).sort(Comparator.comparingDouble(a -> a.first));
        }

        void solveRec(int l, int r, int root, int parent) {
            int currXY = xysIdx.get(r--).second;
            xyMapping[currXY] = root;
            sortByAngle(l, r, currXY);
            int curL = l;
            for (int i : e.get(root)) {
                if (i == parent) continue;
                int curR = curL + subtreeSz[i] - 1;
                int id3 = curR + 1;
                solveRec(curL, curR, i, root);
                curL = id3;
            }
        }

        void calculateSubtreeSizes(int i, int p) {
            subtreeSz[i] = 1;
            for (int j : e.get(i)) {
                if (j == p) continue;
                calculateSubtreeSizes(j, i);
                subtreeSz[i] += subtreeSz[j];
            }
        }

        void solve() throws IOException {
            n = Integer.parseInt(in.readLine());
            subtreeSz = new int[n];
            readTree();
            readPoints();
            xyMapping = new int[n];
            calculateSubtreeSizes(0, -1);
            xysIdx = new ArrayList<>(n);
            for (int i = 0; i < n; i++) {
                xysIdx.add(new Pair<>(0.0, i));
            }
            Arrays.sort(xysIdx.toArray(), (a, b) -> {
                return Integer.compare(xy[(int) b.second][1], xy[(int) a.second][1]);
            });
            solveRec(0, n - 1, 0, -1);
            for (int i = 0; i < n; i++) xyMapping[i]++;
            for (int i : xyMapping) out.print(i + " ");
            out.println();
        }
    }

    static void solve(BufferedReader in, PrintWriter out) throws IOException {
        new Solver(in, out).solve();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        solve(in, out);
        out.close();
    }

    static class Pair<F, S> {
        F first;
        S second;

        Pair(F first, S second) {
            this.first = first;
            this.second = second;
        }
    }
}
