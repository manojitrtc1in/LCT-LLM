import java.util.*;

public class f1c75dae29c083f6f324656ccf7c5b55xcodeeval_processed_4000.json {
    static final int MOD = 1000000007;
    static final int INF = 0x7fffffff;
    static final double PI = Math.acos(-1.0);
    static final double EPS = 1e-6;
    static final double OO = 1e15;

    static int n;
    static int[] adj;
    static int[] A;
    static int[] P;
    static long[] F;

    static int _1(int x, int i) {
        return x & (1 << i);
    }

    static int _1(int i) {
        return 1 << i;
    }

    static int _U(int i) {
        return _1(i) - 1;
    }

    static void RD(int[] x) {
        Scanner sc = new Scanner(System.in);
        for (int i = 0; i < x.length; i++) {
            x[i] = sc.nextInt();
        }
    }

    static void RD(int[][] x) {
        Scanner sc = new Scanner(System.in);
        for (int i = 0; i < x.length; i++) {
            for (int j = 0; j < x[i].length; j++) {
                x[i][j] = sc.nextInt();
            }
        }
    }

    static void OT(int[] x) {
        for (int i = 0; i < x.length; i++) {
            System.out.print(x[i] + " ");
        }
    }

    static long dfs() {
        Arrays.fill(F, 0);
        F[0] = 1;
        for (int s = 0; s < (1 << n) - 1; s++) {
            if (F[s] != 0) {
                for (int i = 0; i < n; i++) {
                    if ((_1(s, i) == 0) && (P[i] == -1) && ((s & adj[i]) == 0)) {
                        F[s | _1(i)] += F[s];
                    }
                }
            }
        }
        return F[(1 << n) - 1];
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        int k = sc.nextInt() - 2000;
        adj = new int[n];
        A = new int[n];
        P = new int[n];
        F = new long[1 << n];
        for (int i = 0; i < n; i++) {
            adj[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            int m = sc.nextInt();
            for (int j = 0; j < m; j++) {
                int x = sc.nextInt() - 1;
                adj[i] |= _1(x);
            }
        }
        if (dfs() < k) {
            System.out.println("The times have changed");
        } else {
            int s = _U(n);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (_1(s, j) != 0) {
                        P[A[i] = j] = i;
                        long t = dfs();
                        if (t < k) {
                            k -= t;
                            P[j] = -1;
                        } else {
                            s ^= _1(j);
                            System.out.print((j + 1) + " ");
                            break;
                        }
                    }
                }
            }
        }
    }
}
