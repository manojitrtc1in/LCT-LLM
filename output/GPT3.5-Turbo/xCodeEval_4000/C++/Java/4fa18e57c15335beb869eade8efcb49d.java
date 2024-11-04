import java.util.*;

class Main {
    static class IntABC {
        int a, b, c;

        IntABC(int a, int b, int c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }
    }

    static class AdjListsGraph {
        Set<Integer> verts;
        List<List<Integer>> lists;

        AdjListsGraph(Set<Integer> verts, List<List<Integer>> lists) {
            this.verts = verts;
            this.lists = lists;
        }
    }

    static class PathFinder {
        AdjListsGraph g;
        int v0;
        Function<Integer, Boolean> f;
        List<Integer> path;
        int[] markers;

        PathFinder(AdjListsGraph g, int v0, Function<Integer, Boolean> f, List<Integer> path, int[] markers) {
            this.g = g;
            this.v0 = v0;
            this.f = f;
            this.path = path;
            this.markers = markers;
        }

        boolean dfs(int v) {
            if (f.apply(v)) {
                path.add(v);
                return true;
            }
            markers[v] = 1;
            boolean res = false;
            for (int e : g.lists.get(v)) {
                if (markers[e] == 0 && dfs(e)) {
                    path.add(v);
                    res = true;
                    break;
                }
            }
            return res;
        }

        boolean doDFS() {
            Arrays.fill(markers, 0);
            return dfs(v0);
        }
    }

    static void solve() {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int vol = sc.nextInt();
        int e = sc.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        int[][] ee = new int[e][2];

        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        for (int i = 0; i < n; i++) {
            b[i] = sc.nextInt();
        }

        for (int i = 0; i < e; i++) {
            ee[i][0] = sc.nextInt();
            ee[i][1] = sc.nextInt();
        }

        List<List<Integer>> ee2 = new ArrayList<>();
        int[] markers = new int[n];
        AdjListsGraph G;
        {
            List<List<Integer>> GList = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                GList.add(new ArrayList<>());
            }
            for (int[] edge : ee) {
                GList.get(edge[0]).add(edge[1]);
                GList.get(edge[1]).add(edge[0]);
            }
            G = new AdjListsGraph(new HashSet<>(Arrays.asList(0, 1, 2, 3, 4, 5, 6, 7, 8, 9)), GList);
        }

        {
            List<List<Integer>> G2List = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                G2List.add(new ArrayList<>());
            }
            for (int[] edge : ee2) {
                G2List.get(edge[0]).add(edge[1]);
                G2List.get(edge[1]).add(edge[0]);
            }
            AdjListsGraph G2 = new AdjListsGraph(new HashSet<>(Arrays.asList(0, 1, 2, 3, 4, 5, 6, 7, 8, 9)), G2List);
        }

        List<IntABC> res = new ArrayList<>();
        for (int q = 0; q < n; q++) {
            for (int i = 0; i < n; i++) {
                if (a[i] != b[i]) {
                    List<Integer> path = new ArrayList<>();
                    if (!pathFrom(G2, i, v -> (a[v] - b[v]) % (a[i] - b[i]) < 0, path, markers)) {
                        System.out.println("NO");
                        return;
                    }
                    if (a[path.get(0)] < b[path.get(0)]) {
                        Collections.reverse(path);
                    }

                    int src = path.get(0);
                    int tgt = path.get(path.size() - 1);
                    int diff = Math.min(Math.abs(a[src] - b[src]), Math.abs(a[tgt] - b[tgt]));
                    doit(a, b, path, res, 0, vol, diff);
                    a[src] -= diff;
                    a[tgt] += diff;
                }
            }
        }

        System.out.print(res.size());
        for (IntABC x : res) {
            System.out.print(" " + x.a + " " + x.b + " " + x.c);
        }
        System.out.println();
    }

    static <T> void fillIt(Set<T> keys, Map<T, Integer> map, int value) {
        for (T key : keys) {
            map.put(key, value);
        }
    }

    static boolean pathFrom(AdjListsGraph g, int v0, Function<Integer, Boolean> f, List<Integer> path, int[] markers) {
        PathFinder x = new PathFinder(g, v0, f, path, markers);
        return x.doDFS();
    }

    static void doit(int[] a, int[] b, List<Integer> path, List<IntABC> res, int pos, int vol, int diff) {
        if (pos + 1 >= path.size()) {
            return;
        }
        int tgt = path.get(pos + 1);
        int before = Math.min(diff, vol - a[tgt]);
        int src = path.get(pos);
        if (before > 0) {
            res.add(new IntABC(src + 1, tgt + 1, before));
        }
        doit(a, b, path, res, pos + 1, vol, diff);
        int after = diff - before;
        if (after > 0) {
            res.add(new IntABC(src + 1, tgt + 1, after));
        }
    }

    public static void main(String[] args) {
        solve();
    }
}
