import java.util.*;

public class a45e161ae9f7a216d3542929da392c7cxcodeeval_processed_4000.json {
    static final int L = 360360, N = 100009;
    static final int INF = 0x3f3f3f3f;
    static final long INFF = 1L << 60;
    static final double EPS = 1e-9;
    
    static int[] D = new int[3 * L];
    static List<Integer>[] adj = new ArrayList[L];
    
    static {
        for (int i = 0; i < L; i++) {
            adj[i] = new ArrayList<>();
        }
    }

    static long a, b, k;
    static int aa, bb, lcm;

    static int id1(int a, int b) {
        return a * b / gcd(a, b);
    }

    static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    static void bfs() {
        int s = aa;
        Arrays.fill(D, 0x3f3f3f3f);
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
            lcm = id1(lcm, i);
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

        bfs();

        bb = (aa - bb + 3 * lcm) % lcm;
        tt *= (long) (D[bb + lcm] - D[bb]);

        System.out.println(D[bb] + tt);
    }
}
