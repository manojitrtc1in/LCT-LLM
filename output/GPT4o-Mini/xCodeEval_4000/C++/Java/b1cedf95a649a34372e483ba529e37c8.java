import java.util.*;
import java.io.*;

public class b1cedf95a649a34372e483ba529e37c8_nc {
    static final int e5 = 100000;
    static final int e9 = 1000000000;
    static final int MD = 1000000007;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        
        int[] K = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            K[i] = Integer.parseInt(st.nextToken());
        }
        
        List<List<Integer>> vv = new ArrayList<>(4 * e5 + 1);
        for (int i = 0; i < 4 * e5 + 1; i++) {
            vv.add(new ArrayList<>());
        }
        
        for (int _ = 0; _ < M; _++) {
            st = new StringTokenizer(br.readLine());
            int D = Integer.parseInt(st.nextToken()) - 1;
            int T = Integer.parseInt(st.nextToken()) - 1;
            vv.get(D).add(T);
        }
        
        int ok = 2 * sum(K), ng = sum(K) - 1;
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

    static int sum(int[] a) {
        int s = 0;
        for (int e : a) {
            s += e;
        }
        return s;
    }
}
