import java.util.*;

public class f1c75dae29c083f6f324656ccf7c5b55_nc {
    static final int MOD = 1000000007;
    static final int N = 16, S = 1 << 16;
    static long[] F = new long[S];
    static int[] adj = new int[N], A = new int[N], P = new int[N];
    static int n;
    static long k, t;

    static int pos(int s) {
        return P[countBits(s)];
    }

    static long dfs() {
        Arrays.fill(F, 0);
        F[0] = 1;
        for (int s = 0; s < (1 << n); s++) {
            if (F[s] > 0) {
                for (int i = 0; i < n; i++) {
                    if (!isOne(s, i) && (pos(s) == -1 || pos(s) == i) && (s & adj[i]) == 0) {
                        F[s | (1 << i)] += F[s];
                    }
                }
            }
        }
        return F[(1 << n) - 1];
    }

    static boolean isOne(int x, int i) {
        return (x & (1 << i)) != 0;
    }

    static int countBits(int x) {
        x = (x & 0x55555555) + ((x & 0xaaaaaaaa) >> 1);
        x = (x & 0x33333333) + ((x & 0xcccccccc) >> 2);
        x = (x & 0x0f0f0f0f) + ((x & 0xf0f0f0f0) >> 4);
        x = (x & 0x00ff00ff) + ((x & 0xff00ff00) >> 8);
        x = (x & 0x0000ffff) + ((x & 0xffff0000) >> 16);
        return x;
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
        Arrays.fill(P, -1);

        if (dfs() < k) {
            System.out.println("The times have changed");
        } else {
            int s = (1 << n) - 1;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (isOne(s, j)) {
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
