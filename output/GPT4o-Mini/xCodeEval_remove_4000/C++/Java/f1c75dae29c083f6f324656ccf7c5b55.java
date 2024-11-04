import java.util.*;

public class f1c75dae29c083f6f324656ccf7c5b55xcodeeval_processed_4000.json {
    static final int MOD = 1000000007;
    static final int N = 16, S = 1 << 16;
    static long[] F = new long[S];
    static int[] adj = new int[N], A = new int[N], P = new int[N];
    static long k, t;
    static int n;

    static void reset(long[] A) {
        Arrays.fill(A, 0);
    }

    static void reset(int[] A) {
        Arrays.fill(A, 0);
    }

    static long dfs() {
        reset(F);
        F[0] = 1;
        for (int s = 0; s < (1 << n); s++) {
            if (F[s] != 0) {
                for (int i = 0; i < n; i++) {
                    if ((s & (1 << i)) == 0 && (adj[i] & s) == 0) {
                        F[s | (1 << i)] += F[s];
                    }
                }
            }
        }
        return F[(1 << n) - 1];
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        k = scanner.nextLong() - 2000;

        for (int i = 0; i < n; i++) {
            int u = scanner.nextInt() - 1;
            int v = scanner.nextInt() - 1;
            adj[u] |= (1 << v);
        }

        if (dfs() < k) {
            System.out.println("The times have changed");
        } else {
            int s = (1 << n) - 1;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if ((s & (1 << j)) != 0) {
                        P[A[i] = j] = i;
                        t = dfs();
                        if (t < k) {
                            k -= t;
                            P[j] = -1;
                        } else {
                            s ^= (1 << j);
                            System.out.print((j + 1) + " ");
                            break;
                        }
                    }
                }
            }
        }
        scanner.close();
    }
}
