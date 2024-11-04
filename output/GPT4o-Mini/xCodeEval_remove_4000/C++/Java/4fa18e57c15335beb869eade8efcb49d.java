import java.util.*;

public class 4fa18e57c15335beb869eade8efcb49dxcodeeval_processed_4000.json {
    public static void doit(int[] a, int[] b, List<Integer> path, List<int[]> res, int pos, int vol, int diff) {
        if (pos + 1 >= path.size()) return;
        int tgt = path.get(pos + 1);
        int before = Math.min(diff, vol - a[tgt]);
        int src = path.get(pos);
        if (before > 0) res.add(new int[]{src + 1, tgt + 1, before});
        doit(a, b, path, res, pos + 1, vol, diff);
        int after = diff - before;
        if (after > 0) res.add(new int[]{src + 1, tgt + 1, after});
    }

    public static void solve() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int vol = scanner.nextInt();
        int e = scanner.nextInt();

        int[] a = new int[n];
        int[] b = new int[n];
        for (int i = 0; i < n; i++) a[i] = scanner.nextInt();
        for (int i = 0; i < n; i++) b[i] = scanner.nextInt();

        List<int[]> ee = new ArrayList<>();
        for (int i = 0; i < e; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            ee.add(new int[]{u, v});
        }

        List<int[]> ee2 = new ArrayList<>();
        List<Integer> markers = new ArrayList<>(Collections.nCopies(n, 0));
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                List<Integer> path = new ArrayList<>();
                if (!pathFrom(ee2, i, v -> (a[v] - b[v]) * (a[i] - b[i]) < 0, path, markers)) {
                    System.out.println("NO");
                    return;
                }
                if (a[path.get(0)] < b[path.get(0)]) Collections.reverse(path);

                int src = path.get(0), tgt = path.get(path.size() - 1);
                int diff = Math.min(Math.abs(a[src] - b[src]), Math.abs(a[tgt] - b[tgt]));
                List<int[]> res = new ArrayList<>();
                doit(a, b, path, res, 0, vol, diff);
                a[src] -= diff;
                a[tgt] += diff;
            }
        }

        System.out.println(res.size());
        for (int[] x : res) {
            System.out.println(x[0] + " " + x[1] + " " + x[2]);
        }
    }

    public static boolean pathFrom(List<int[]> g, int v0, Predicate<Integer> f, List<Integer> path, List<Integer> markers) {
        PathFinder pathFinder = new PathFinder(g, v0, f, path, markers);
        return pathFinder.doPath();
    }

    static class PathFinder {
        List<int[]> g;
        Predicate<Integer> f;
        List<Integer> path;
        List<Integer> markers;
        int v0;

        PathFinder(List<int[]> g, int v0, Predicate<Integer> f, List<Integer> path, List<Integer> markers) {
            this.g = g;
            this.v0 = v0;
            this.f = f;
            this.path = path;
            this.markers = markers;
        }

        boolean dfs(int v) {
            if (f.test(v)) {
                path.add(v);
                return true;
            }
            markers.set(v, 1);
            boolean res = false;
            for (int[] e : g) {
                if (e[0] == v && markers.get(e[1]) == 0) {
                    if (dfs(e[1])) {
                        path.add(v);
                        res = true;
                        break;
                    }
                }
            }
            return res;
        }

        boolean doPath() {
            Collections.fill(markers, 0);
            return dfs(v0);
        }
    }

    public static void main(String[] args) {
        solve();
    }
}
