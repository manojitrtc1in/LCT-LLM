import java.util.*;

public class e2d7f022cffad895d0dd18a67816c57dxcodeeval_processed_4000.json {
    static final int N = (int) (3e2) + 9;
    static List<Integer>[] adj = new ArrayList[N];
    static int[] A = new int[N], B = new int[N], t = new int[N];
    static int n, e, UP;
    static List<Op> op = new ArrayList<>();

    static class Op {
        int u, v, d;

        Op(int u, int v, int d) {
            this.u = u;
            this.v = v;
            this.d = d;
            A[u] -= d;
            A[v] += d;
        }

        void output() {
            System.out.println(u + " " + v + " " + d);
        }
    }

    static List<Integer> path = new ArrayList<>();
    static boolean[] vis = new boolean[N];

    static boolean dfs(int u) {
        if (vis[u]) return false;
        vis[u] = true;
        path.add(u);
        if (A[u] < B[u]) return true;
        for (int v : adj[u]) {
            if (dfs(v)) return true;
        }
        path.remove(path.size() - 1);
        return false;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        for (int i = 0; i < N; i++) {
            adj[i] = new ArrayList<>();
        }

        n = scanner.nextInt();
        UP = scanner.nextInt();
        e = scanner.nextInt();

        for (int i = 1; i <= n; i++) {
            A[i] = scanner.nextInt();
        }
        for (int i = 1; i <= n; i++) {
            B[i] = scanner.nextInt();
        }

        for (int i = 0; i < e; i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            adj[x].add(y);
            adj[y].add(x);
        }

        for (int i = 1; i <= n; i++) {
            while (A[i] > B[i]) {
                Arrays.fill(vis, false);
                path.clear();
                if (!dfs(i)) {
                    System.out.println("NO");
                    return;
                }

                int f = Math.min(A[i] - B[i], B[path.get(path.size() - 1)] - A[path.get(path.size() - 1)]);

                for (int j = 0; j < path.size() - 1; j++) {
                    int u = path.get(j), v = path.get(j + 1);
                    int d = Math.min(f, A[u], UP - A[v]);
                    t[j] = f - d;
                    if (d > 0) op.add(new Op(u, v, d));
                }
                for (int j = path.size() - 2; j >= 0; j--) {
                    int u = path.get(j), v = path.get(j + 1);
                    int d = t[j];
                    if (d > 0) op.add(new Op(u, v, d));
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            if (A[i] != B[i]) {
                System.out.println("NO");
                return;
            }
        }
        System.out.println(op.size());
        for (Op opItem : op) {
            opItem.output();
        }
    }
}
