import java.util.*;

public class 29ec0e05357a8bdf6aa4e82c6526a556xcodeeval_processed_4000.json {
    static final int N = 16, S = 1 << 16;
    static long[] F = new long[S];
    static int[] adj = new int[N];
    static int[] A = new int[N];
    static int[] P = new int[N];
    static int n;
    static long k, t;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        k = sc.nextLong();
        k -= 2000;
        for (int i = 0; i < n; i++) {
            adj[i] = 0;
        }
        int c = sc.nextInt();
        for (int i = 0; i < c; i++) {
            int x = sc.nextInt() - 1;
            int y = sc.nextInt() - 1;
            adj[x] |= (1 << y);
        }
        Arrays.fill(P, -1);

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
    }

    static long dfs() {
        Arrays.fill(F, 0);
        F[0] = 1;
        for (int s = 0; s < (1 << n); s++) {
            if (F[s] != 0) {
                for (int i = 0; i < n; i++) {
                    if ((s & (1 << i)) == 0 && (P[i] == -1 || P[i] == i) && (s & adj[i]) == 0) {
                        F[s | (1 << i)] += F[s];
                    }
                }
            }
        }
        return F[(1 << n) - 1];
    }
}
