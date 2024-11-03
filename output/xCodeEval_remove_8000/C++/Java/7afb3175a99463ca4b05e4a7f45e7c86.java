import java.util.*;

class Main {
    static final int N = 50, M = 20;
    static String[] S = new String[N];
    static long[] f = new long[1 << M];
    static long[] ok = new long[M + 1];
    static int n, m;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            S[i] = sc.next();
        }
        m = S[0].length();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int s = 0;
                for (int k = 0; k < m; k++) {
                    if (S[i].charAt(k) == S[j].charAt(k)) {
                        s |= (1 << k);
                    }
                }
                f[s] |= (1 << i);
            }
        }

        for (int s = (1 << m) - 1; s >= 0; s--) {
            for (int i = 0; i < m; i++) {
                if ((s & (1 << i)) != 0) {
                    f[s ^ (1 << i)] |= f[s];
                }
            }
        }

        for (int s = 0; s < (1 << m); s++) {
            int step = Integer.bitCount(s) + 1;
            for (int i = 0; i < m; i++) {
                if ((s & (1 << i)) == 0) {
                    long d = f[s | (1 << i)] ^ f[s];
                    ok[step] += Long.bitCount(d);
                }
            }
        }

        double ans = 0;
        for (int i = 0; i < m; i++) {
            if (ok[i] != 0) {
                double t = ok[i] * i;
                for (int j = 1; j < i; j++) {
                    t *= j;
                }
                for (int j = m - i + 1; j <= m; j++) {
                    t /= j;
                }
                ans += t;
            }
        }

        ans /= n;
        System.out.println(ans);
    }
}
