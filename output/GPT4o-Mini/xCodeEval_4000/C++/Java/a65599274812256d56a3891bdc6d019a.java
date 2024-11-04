import java.util.*;

public class a65599274812256d56a3891bdc6d019a_nc {
    static final int L = 360360;
    static final int N = 100009;
    static final int INF = 0x3f3f3f3f;
    static final long MOD = 1000000007;

    static int[] D = new int[3 * L];
    static List<Integer>[] adj = new ArrayList[L];
    static long a, b, k;
    static int aa, bb, lcm;

    static {
        for (int i = 0; i < L; i++) {
            adj[i] = new ArrayList<>();
        }
    }

    static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    static int lcm(int a, int b) {
        return a * b / gcd(a, b);
    }

    static void bfs() {
        int s = aa;
        Arrays.fill(D, INF);
        D[0] = 0;

        for (int i = 0; i < 3 * lcm; i++) {
            int u = (s - i) % lcm;
            if (u < 0) u += lcm;

            int Du = D[i];
            if (Du == INF) continue;

            for (int j = 0; j < adj[u].size(); j++) {
                checkMin(D[i + adj[u].get(j)], Du + 1);
            }
        }
    }

    static void checkMin(int[] a, int b) {
        if (b < a[0]) a[0] = b;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        a = scanner.nextLong();
        b = scanner.nextLong();
        k = scanner.nextLong();

        lcm = 1;
        for (int i = 2; i <= k; i++) {
            lcm = lcm(lcm, i);
        }

        for (int i = 0; i < lcm; i++) {
            adj[i].add(1);
            for (int j = 2; j <= k; j++) {
                if (i % j != 0) {
                    adj[i].add(i % j);
                }
            }
        }

        long tt = (a - b) / lcm;
        aa = (int) (a % lcm);
        bb = (int) (b % lcm);

        long step = INF;
        bfs();

        bb = (aa - bb + 3 * lcm) % lcm;
        tt *= (long) (D[bb + lcm] - D[bb]);

        System.out.println(D[bb] + tt);
    }
}
