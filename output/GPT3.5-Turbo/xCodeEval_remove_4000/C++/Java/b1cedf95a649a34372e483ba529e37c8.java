import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        int[] K = new int[N];
        for (int i = 0; i < N; i++) {
            K[i] = scanner.nextInt();
        }
        List<List<Integer>> vv = new ArrayList<>();
        for (int i = 0; i < 4 * 1e5 + 1; i++) {
            vv.add(new ArrayList<>());
        }
        for (int i = 0; i < M; i++) {
            int D = scanner.nextInt();
            int T = scanner.nextInt();
            vv.get(D - 1).add(T - 1);
        }
        int ok = 2 * sum(K);
        int ng = sum(K) - 1;
        while (ok - ng > 1) {
            int k = (ok + ng) >> 1;
            int[] v = new int[k];
            boolean[] b = new boolean[N];
            for (int i = 0; i < k; i++) {
                for (int j : vv.get(i)) {
                    if (!b[j]) {
                        b[j] = true;
                        v[i] += K[j];
                    }
                }
            }
            int t = 0;
            int s = sum(K);
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

    private static int sum(int[] a) {
        int s = 0;
        for (int e : a) {
            s += e;
        }
        return s;
    }
}
