import java.util.*;

public class 7afb3175a99463ca4b05e4a7f45e7c86xcodeeval_processed_4000.json {
    static final int N = 50, M = 20;
    static String[] S = new String[N];
    static long[] f = new long[1 << M];
    static long[] ok = new long[M + 1];
    static int n, m;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        scanner.nextLine(); // Consume the newline

        for (int i = 0; i < n; i++) {
            S[i] = scanner.nextLine();
        }
        m = S[0].length();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    int s = 0;
                    for (int k = 0; k < m; k++) {
                        if (S[i].charAt(k) == S[j].charAt(k)) {
                            s |= (1 << k);
                        }
                    }
                    f[s] |= (1L << i);
                }
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
        for (int i = 0; i <= m; i++) {
            if (ok[i] > 0) {
                double t = ok[i] * i;
                for (int j = 1; j < i; j++) {
                    t *= j;
                }
                for (int j = i; j <= m; j++) {
                    t /= j;
                }
                ans += t;
            }
        }

        ans /= n;
        System.out.printf("%.15f\n", ans);
    }
}
