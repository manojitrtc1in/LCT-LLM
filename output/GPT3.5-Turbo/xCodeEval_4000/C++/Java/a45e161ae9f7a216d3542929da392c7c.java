import java.util.*;
import java.io.*;

public class a45e161ae9f7a216d3542929da392c7c_nc {
    static final int L = 360360;
    static final int N = 100009;

    static int __lcm(int a, int b) {
        return a * b / gcd(a, b);
    }

    static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    static long a, b, k;
    static int aa, bb, lcm;
    static List<Integer>[] adj = new List[L];
    static int[] D = new int[3 * L];

    static int f(int s, int t) {
        return D[t];
    }

    static void bfs() {
        int s = aa;
        Arrays.fill(D, Integer.MAX_VALUE);
        D[0] = 0;

        for (int i = 0; i < 3 * lcm; i++) {
            int u = (s - i) % lcm;
            if (u < 0) {
                u += lcm;
            }

            int Du = D[i];

            if (Du == Integer.MAX_VALUE) {
                continue;
            }

            for (int j = 0; j < adj[u].size(); j++) {
                int v = adj[u].get(j);
                D[i + v] = Math.min(D[i + v], Du + 1);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        a = Long.parseLong(st.nextToken());
        b = Long.parseLong(st.nextToken());
        k = Long.parseLong(st.nextToken());

        lcm = 1;
        for (int i = 2; i <= k; i++) {
            lcm = __lcm(lcm, i);
        }

        for (int i = 0; i < lcm; i++) {
            adj[i] = new ArrayList<>();
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

        long step = Integer.MAX_VALUE;
        int h;

        bfs();

        bb = (aa - bb + 3 * lcm) % lcm;

        tt *= (long) (D[bb + lcm] - D[bb]);

        System.out.println(D[bb] + tt);
    }
}
