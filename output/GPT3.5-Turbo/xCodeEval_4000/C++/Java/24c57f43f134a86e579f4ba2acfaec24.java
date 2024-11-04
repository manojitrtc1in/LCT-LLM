import java.io.*;
import java.util.*;

class Main {
    static final int MAXV = 1000001;
    static int N, K, Q;
    static int[] a, q;
    static long ans;
    static int[] ct;
    static long[] coeff;
    static ArrayList<Integer>[] divisors;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        Q = Integer.parseInt(st.nextToken());

        a = new int[N];
        q = new int[Q];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            a[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < Q; i++) {
            q[i] = Integer.parseInt(st.nextToken());
        }

        coeff = new long[MAXV];
        divisors = new ArrayList[MAXV];
        for (int i = 1; i < MAXV; i++) {
            divisors[i] = new ArrayList<>();
        }

        for (int g = 1; g < MAXV; g++) {
            for (int m = g, c = 1; m < MAXV; m += g, c++) {
                coeff[m] += g * mobius(c);
                divisors[m].add(g);
            }
        }

        ans = 0;
        ct = new int[MAXV];
        for (int v : a) {
            intro(v);
        }

        StringBuilder sb = new StringBuilder();
        for (int qv : q) {
            intro(qv);
            sb.append(ans).append("\n");
        }

        System.out.print(sb);
    }

    static void intro(int v) {
        for (int d : divisors[v]) {
            ans += coeff[d] * (ncr(ct[d] + 1, K) - ncr(ct[d], K));
            ct[d]++;
        }
    }

    static long mobius(int n) {
        long res = 1;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                n /= i;
                if (n % i == 0) {
                    return 0;
                }
                res *= -1;
            }
        }
        if (n > 1) {
            res *= -1;
        }
        return res;
    }

    static long ncr(int n, int r) {
        if (r > n) {
            return 0;
        }
        long res = 1;
        for (int i = 0; i < r; i++) {
            res *= (n - i);
            res /= (i + 1);
        }
        return res;
    }
}
