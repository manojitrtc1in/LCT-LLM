import java.util.*;

public class 8366303f38184a04d14f3dd7d60e4cdc_nc {
    static final int L = 360360;
    static final int N = 100009;
    static final int INF = 0x3f3f3f3f;
    static final long MOD = 1000000007;
    
    static int[] D = new int[3 * L];
    static List<Integer>[] adj = new ArrayList[L];
    
    static {
        for (int i = 0; i < L; i++) {
            adj[i] = new ArrayList<>();
        }
    }

    static int lcm(int a, int b) {
        return a * b / gcd(a, b);
    }

    static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    static void bfs(int s) {
        Arrays.fill(D, INF);
        D[0] = 0;

        for (int i = 0; i < 3 * lcm; i++) {
            int u = (s - i) % lcm;
            if (u < 0) u += lcm;

            int Du = D[i];
            if (Du == INF) continue;

            for (int v : adj[u]) {
                checkMin(D[i + v], Du + 1);
            }
        }
    }

    static void checkMin(int[] a, int b) {
        if (b < a[0]) a[0] = b;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long a = scanner.nextLong();
        long b = scanner.nextLong();
        int k = scanner.nextInt();

        int lcm = 1;
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
        int aa = (int) (a % lcm);
        int bb = (int) (b % lcm);

        bfs(aa);

        bb = (aa - bb + 3 * lcm) % lcm;
        tt *= (D[bb + lcm] - D[bb]);

        System.out.println(D[bb] + tt);
    }
}
