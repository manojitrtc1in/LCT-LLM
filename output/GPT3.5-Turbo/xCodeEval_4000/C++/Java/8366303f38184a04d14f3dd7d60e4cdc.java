import java.util.*;

class Main {
    static final int L = 360360;
    static final int N = 100009;

    static int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    static int lcm(int a, int b) {
        return a * b / gcd(a, b);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long a = sc.nextLong();
        long b = sc.nextLong();
        int k = sc.nextInt();
        int aa = (int) (a % L);
        int bb = (int) (b % L);
        int lcm = 1;
        for (int i = 2; i <= k; i++) {
            lcm = lcm(lcm, i);
        }
        List<Integer>[] adj = new List[L];
        for (int i = 0; i < L; i++) {
            adj[i] = new ArrayList<>();
        }
        for (int i = 0; i < L; i++) {
            adj[i].add(1);
            for (int j = 2; j <= k; j++) {
                if (i % j != 0) {
                    adj[i].add(i % j);
                }
            }
        }
        int[] D = new int[3 * L];
        Arrays.fill(D, Integer.MAX_VALUE);
        D[0] = 0;
        Queue<Integer> queue = new LinkedList<>();
        queue.add(aa);
        while (!queue.isEmpty()) {
            int u = queue.poll();
            int Du = D[u];
            if (Du == Integer.MAX_VALUE)
                continue;
            for (int v : adj[u]) {
                if (D[u + v] > Du + 1) {
                    D[u + v] = Du + 1;
                    queue.add(u + v);
                }
            }
        }
        long tt = (a - b) / lcm;
        int bbLcm = bb + lcm;
        long step = Integer.MAX_VALUE;
        for (int i = bb; i < bbLcm; i++) {
            step = Math.min(step, D[i]);
        }
        tt *= D[bbLcm] - step;
        System.out.println(D[bb] + tt);
    }
}
