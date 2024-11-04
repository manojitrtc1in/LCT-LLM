import java.util.*;

public class a65599274812256d56a3891bdc6d019axcodeeval_processed_4000.json {
    static final int L = 360360;
    static final int INF = 0x3f3f3f3f;
    static final long MOD = 1000000007;
    static final int[] dx4 = {-1, 0, 1, 0};
    static final int[] dy4 = {0, 1, 0, -1};
    static final int[] dx8 = {-1, 0, 1, 0, -1, -1, 1, 1};
    static final int[] dy8 = {0, 1, 0, -1, -1, 1, -1, 1};

    static long a, b, k;
    static int aa, bb, lcm;
    static List<Integer>[] adj = new ArrayList[L];
    static int[] D = new int[3 * L];

    static {
        for (int i = 0; i < L; i++) {
            adj[i] = new ArrayList<>();
        }
    }

    static int id2(int a, int b) {
        return a * b / gcd(a, b);
    }

    static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
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
            lcm = id2(lcm, i);
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
        tt *= (D[bb + lcm] - D[bb]);

        System.out.println(D[bb] + tt);
    }
}
