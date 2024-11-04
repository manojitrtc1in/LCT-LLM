import java.util.*;

public class 29ec0e05357a8bdf6aa4e82c6526a556_nc {
    static final int N = 16, S = 1 << 16;
    static long[] F = new long[S];
    static int[] adj = new int[N];
    static int[] A = new int[N];
    static int[] P = new int[N];
    static int n;
    static long k, t;

    static int count_bits(int x) {
        x = (x & 0x55555555) + ((x & 0xaaaaaaaa) >> 1);
        x = (x & 0x33333333) + ((x & 0xcccccccc) >> 2);
        x = (x & 0x0f0f0f0f) + ((x & 0xf0f0f0f0) >> 4);
        x = (x & 0x00ff00ff) + ((x & 0xff00ff00) >> 8);
        x = (x & 0x0000ffff) + ((x & 0xffff0000) >> 16);
        return x;
    }

    static long dfs() {
        Arrays.fill(F, 0);
        F[0] = 1;
        for (int s = 0; s < (1 << n) - 1; s++) {
            if (F[s] != 0) {
                for (int i = 0; i < n; i++) {
                    if ((s & (1 << i)) == 0 && (P[count_bits(s)] == -1 || P[count_bits(s)] == i) && (s & adj[i]) == 0) {
                        F[s | (1 << i)] += F[s];
                    }
                }
            }
        }
        return F[(1 << n) - 1];
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        k = sc.nextLong();
        k -= 2000;
        for (int i = 0; i < n; i++) {
            adj[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            int m = sc.nextInt();
            for (int j = 0; j < m; j++) {
                int x = sc.nextInt();
                adj[i] |= (1 << (x - 1));
            }
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
}
