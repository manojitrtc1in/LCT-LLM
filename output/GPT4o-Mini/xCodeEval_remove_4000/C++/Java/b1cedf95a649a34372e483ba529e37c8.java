import java.util.*;

public class b1cedf95a649a34372e483ba529e37c8xcodeeval_processed_4000.json {
    static final int e5 = 100000;
    static final int e9 = 1000000000;
    static final int MD = 1000000007;
    static final int md = 998244353;
    static final long e18 = 1000000000000000000L;

    static long sum(int[] a) {
        long s = 0;
        for (int e : a) {
            s += e;
        }
        return s;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        int[] K = new int[N];
        for (int i = 0; i < N; i++) {
            K[i] = scanner.nextInt();
        }
        List<List<Integer>> vv = new ArrayList<>(4 * e5 + 1);
        for (int i = 0; i < 4 * e5 + 1; i++) {
            vv.add(new ArrayList<>());
        }
        for (int _ = 0; _ < M; _++) {
            int D = scanner.nextInt() - 1;
            int T = scanner.nextInt() - 1;
            vv.get(D).add(T);
        }
        int ok = 2 * (int) sum(K);
        int ng = (int) sum(K) - 1;
        while (ok - ng > 1) {
            int k = (ok + ng) >> 1;
            int[] v = new int[k];
            boolean[] b = new boolean[N];
            for (int i = k - 1; i >= 0; i--) {
                for (int j : vv.get(i)) {
                    if (!b[j]) {
                        b[j] = true;
                        v[i] += K[j];
                    }
                }
            }
            int t = 0;
            int s = (int) sum(K);
            for (int i = 0; i < k; i++) {
                t++;
                int m = Math.min(t, v[i]);
                t -= m;
                s -= m;
            }
            if (t >= s * 2) {
                ok = k;
            } else {
                ng = k;
            }
        }
        System.out.println(ok);
    }
}
