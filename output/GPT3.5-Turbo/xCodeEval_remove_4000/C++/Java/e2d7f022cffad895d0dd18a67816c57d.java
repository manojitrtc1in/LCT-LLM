import java.util.*;
import java.io.*;

class Main {
    static class Op {
        int u, v, d;

        Op(int u, int v, int d) {
            this.u = u;
            this.v = v;
            this.d = d;
        }

        void output() {
            System.out.println(u + " " + v + " " + d);
        }
    }

    static int[] A, B, t;
    static List<Integer>[] adj;
    static List<Op> op;
    static boolean[] vis;
    static List<Integer> path;
    static int n, e, UP;

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

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        UP = Integer.parseInt(st.nextToken());
        e = Integer.parseInt(st.nextToken());

        A = new int[n + 1];
        B = new int[n + 1];
        t = new int[n + 1];
        adj = new List[n + 1];
        for (int i = 1; i <= n; i++) {
            adj[i] = new ArrayList<>();
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) {
            B[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = 0; i < e; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            adj[x].add(y);
            adj[y].add(x);
        }

        for (int i = 1; i <= n; i++) {
            while (A[i] > B[i]) {
                vis = new boolean[n + 1];
                path = new ArrayList<>();
                if (!dfs(i)) {
                    System.out.println("NO");
                    return;
                }

                int f = Math.min(A[i] - B[i], B[path.get(path.size() - 1)] - A[path.get(path.size() - 1)]);

                for (int j = 0; j < path.size() - 1; j++) {
                    int u = path.get(j);
                    int v = path.get(j + 1);
                    int d = Math.min(f, A[u], UP - A[v]);
                    t[j] = f - d;
                    if (d > 0) {
                        op.add(new Op(u, v, d));
                    }
                }

                for (int j = path.size() - 2; j >= 0; j--) {
                    int u = path.get(j);
                    int v = path.get(j + 1);
                    int d = t[j];
                    if (d > 0) {
                        op.add(new Op(u, v, d));
                    }
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
        for (Op o : op) {
            o.output();
        }
    }
}
