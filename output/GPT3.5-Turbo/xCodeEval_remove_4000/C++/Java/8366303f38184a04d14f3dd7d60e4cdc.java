import java.util.*;
import java.io.*;

class Main {
    static final int L = 360360;
    static final int N = 100009;

    static int id2(int a, int b) {
        return a * b / gcd(a, b);
    }

    static long a, b, k;
    static int aa, bb, lcm;
    static List<Integer>[] adj = new List[L];

    static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    static int f(int s, int t) {
        return D[t];
    }

    static int[] D = new int[3 * L];

    static void bfs() {
        int s = aa;
        Arrays.fill(D, Integer.MAX_VALUE);
        D[0] = 0;

        for (int i = 0; i < 3 * lcm; i++) {
            int u = (s - i) % lcm;
            if (u < 0) u += lcm;

            int Du = D[i];

            if (Du == Integer.MAX_VALUE) continue;

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
            lcm = id2(lcm, i);
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
