import java.util.*;
import java.io.*;

class Main {
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    public static void main(String[] args) {
        FastReader sc = new FastReader();
        int N = sc.nextInt();
        int M = sc.nextInt();
        int[] K = new int[N];
        for (int i = 0; i < N; i++) {
            K[i] = sc.nextInt();
        }
        List<List<Integer>> vv = new ArrayList<>();
        for (int i = 0; i < 4 * 1e5 + 1; i++) {
            vv.add(new ArrayList<>());
        }
        for (int i = 0; i < M; i++) {
            int D = sc.nextInt();
            int T = sc.nextInt();
            vv.get(D - 1).add(T - 1);
        }
        int ok = 2 * Arrays.stream(K).sum();
        int ng = Arrays.stream(K).sum() - 1;
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
            int s = Arrays.stream(K).sum();
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
