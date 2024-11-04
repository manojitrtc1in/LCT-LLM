import java.util.*;

public class 4fa18e57c15335beb869eade8efcb49d_nc {
    
    static class IntABC {
        int a, b, c;
        IntABC(int a, int b, int c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }
    }

    static class IntUV {
        int u, v;
        IntUV(int u, int v) {
            this.u = u;
            this.v = v;
        }
    }

    public static void doit(int[] a, int[] b, List<Integer> path, List<IntABC> res, int pos, int vol, int diff) {
        if (pos + 1 >= path.size()) return;
        int tgt = path.get(pos + 1);
        int before = Math.min(diff, vol - a[tgt]);
        int src = path.get(pos);
        if (before > 0) res.add(new IntABC(src + 1, tgt + 1, before));
        doit(a, b, path, res, pos + 1, vol, diff);
        int after = diff - before;
        if (after > 0) res.add(new IntABC(src + 1, tgt + 1, after));
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

        List<IntUV> ee = new ArrayList<>();
        for (int i = 0; i < e; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            ee.add(new IntUV(u - 1, v - 1));
        }

        List<List<IntUV>> G = new ArrayList<>(n);
        for (int i = 0; i < n; i++) G.add(new ArrayList<>());

        for (IntUV edge : ee) {
            G.get(edge.u).add(edge);
            G.get(edge.v).add(new IntUV(edge.v, edge.u));
        }

        List<IntUV> ee2 = new ArrayList<>();
        boolean[] markers = new boolean[n];
        for (int i = 0; i < n; i++) markers[i] = false;

        for (int i = 0; i < n; i++) {
            if (!markers[i]) {
                dfs(G, i, markers, ee2);
            }
        }

        List<IntABC> res = new ArrayList<>();
        for (int q = 0; q < n; q++) {
            for (int i = 0; i < n; i++) {
                if (a[i] != b[i]) {
                    List<Integer> path = new ArrayList<>();
                    if (!pathFrom(G, i, v -> (a[v] - b[v]) * (a[i] - b[i]) < 0, path, markers)) {
                        System.out.println("NO");
                        return;
                    }
                    if (a[path.get(0)] < b[path.get(0)]) Collections.reverse(path);

                    int src = path.get(0), tgt = path.get(path.size() - 1);
                    int diff = Math.min(Math.abs(a[src] - b[src]), Math.abs(a[tgt] - b[tgt]));
                    doit(a, b, path, res, 0, vol, diff);
                    a[src] -= diff;
                    a[tgt] += diff;
                }
            }
        }
        System.out.println(res.size());
        for (IntABC x : res) {
            System.out.println(x.a + " " + x.b + " " + x.c);
        }
    }

    private static void dfs(List<List<IntUV>> G, int v, boolean[] markers, List<IntUV> ee2) {
        markers[v] = true;
        for (IntUV edge : G.get(v)) {
            if (!markers[edge.v]) {
                ee2.add(edge);
                dfs(G, edge.v, markers, ee2);
            }
        }
    }

    private static boolean pathFrom(List<List<IntUV>> G, int v0, Predicate<Integer> f, List<Integer> path, boolean[] markers) {
        if (f.test(v0)) {
            path.add(v0);
            return true;
        }
        markers[v0] = true;
        boolean res = false;
        for (IntUV e : G.get(v0)) {
            if (!markers[e.v] && pathFrom(G, e.v, f, path, markers)) {
                path.add(v0);
                res = true;
                break;
            }
        }
        return res;
    }

    public static void main(String[] args) {
        solve();
    }
}
