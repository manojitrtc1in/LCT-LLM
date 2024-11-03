import java.util.*;
import java.io.*;

public class 6d42941032a084c3b28df326724fbec5_nc {
    static final int M = 998244353;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[] a = new int[n];
        int[] w = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            w[i] = Integer.parseInt(st.nextToken());
        }
        int W1 = 0, W2 = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {
                W1 += w[i];
            } else {
                W2 += w[i];
            }
        }
        int[] probs = new int[m + 1];
        probs[0] = 1;
        for (int i = 0; i < m; i++) {
            int[] newProbs = new int[m + 1];
            for (int d1 = 0; d1 <= i; d1++) {
                int d2 = d1 - i;
                int w1 = W1 + d1;
                int w2 = W2 + d2;
                int w0 = w1 + w2;
                if (probs[d1] != 0 && w2 >= 0) {
                    int inv_w0 = inverse(w0, M);
                    if (w2 > 0) {
                        newProbs[d1] = sum(newProbs[d1], prod(probs[d1], prod(w2, inv_w0, M), M), M);
                    }
                    newProbs[d1 + 1] = sum(newProbs[d1 + 1], prod(probs[d1], prod(w1, inv_w0, M), M), M);
                }
            }
            probs = newProbs;
        }
        int[] after_ops_1 = new int[m + 1];
        int[] after_ops_2 = new int[m + 1];
        after_ops_1[0] = 1;
        after_ops_2[0] = 1;
        for (int i = 1; i <= m; i++) {
            after_ops_1[i] = prod(after_ops_1[i - 1], sum(1, inverse(W1 + i - 1, M), M), M);
        }
        for (int i = 1; i <= m; i++) {
            after_ops_2[i] = prod(after_ops_2[i - 1], raz(1, inverse(W2 - i + 1, M), M), M);
        }
        int coef1 = 0, coef2 = 0;
        for (int i = 0; i <= m; i++) {
            coef1 = sum(coef1, prod(after_ops_1[i], probs[i], M), M);
        }
        for (int i = 0; i <= m; i++) {
            coef2 = sum(coef2, prod(after_ops_2[i], probs[m - i], M), M);
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {
                sb.append(prod(w[i], coef1, M)).append("\n");
            } else {
                sb.append(prod(w[i], coef2, M)).append("\n");
            }
        }
        System.out.print(sb);
    }

    static int inverse(int a, int n) {
        int c = cool_gcd(a, n).X;
        if (c < 0) {
            c += n;
        }
        return c;
    }

    static int cool_gcd(int a, int b) {
        if (b != 0) {
            int c = a % b;
            int d = cool_gcd(b, a - b * c);
            return d;
        } else {
            return a;
        }
    }

    static int prod(int a, int b, int M) {
        return (int) ((long) a * b % M);
    }

    static int sum(int a, int b, int M) {
        int c = a + b;
        return c >= M ? c - M : c;
    }

    static int raz(int a, int b, int M) {
        int c = a - b;
        return c < 0 ? c + M : c;
    }
}
