import java.io.*;
import java.util.*;

public class 6d42941032a084c3b28df326724fbec5xcodeeval_processed_4000.json {
    static final int M = 998244353;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        int[] a = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(st.nextToken());
        }

        int[] w = new int[n];
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

        long[] probs = new long[m + 1];
        probs[0] = 1;

        for (int i = 0; i < m; i++) {
            long[] new_probs = new long[m + 1];
            for (int d1 = 0; d1 <= i; d1++) {
                int d2 = d1 - i;
                int w1 = W1 + d1;
                int w2 = W2 + d2;
                int w0 = w1 + w2;

                if (probs[d1] > 0 && w2 >= 0) {
                    int id16 = inverse(w0);
                    if (w2 > 0) {
                        new_probs[d1] = (new_probs[d1] + (probs[d1] * w2 % M) * id16 % M) % M);
                    }
                    new_probs[d1 + 1] = (new_probs[d1 + 1] + (probs[d1] * w1 % M) * id16 % M) % M;
                }
            }
            probs = new_probs;
        }

        long[] id4 = new long[m + 1];
        long[] id29 = new long[m + 1];
        id4[0] = 1;
        id29[0] = 1;

        for (int i = 1; i <= m; i++) {
            id4[i] = (id4[i - 1] * (1 + inverse(W1 + i - 1)) % M) % M;
        }
        for (int i = 1; i <= m; i++) {
            id29[i] = (id29[i - 1] * raz(1, inverse(W2 - i + 1)) % M) % M;
        }

        long coef1 = 0, coef2 = 0;
        for (int i = 0; i <= m; i++) {
            coef1 = (coef1 + (id4[i] * probs[i] % M)) % M;
        }
        for (int i = 0; i <= m; i++) {
            coef2 = (coef2 + (id29[i] * probs[m - i] % M)) % M;
        }

        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {
                out.println(w[i] * coef1 % M);
            } else {
                out.println(w[i] * coef2 % M);
            }
        }

        out.close();
    }

    static int inverse(int a) {
        return pow_mod(a, M - 2);
    }

    static int pow_mod(int a, int b) {
        int result = 1;
        a %= M;
        while (b > 0) {
            if ((b & 1) == 1) {
                result = (int)((result * (long)a) % M);
            }
            a = (int)((a * (long)a) % M);
            b >>= 1;
        }
        return result;
    }

    static int raz(int a, int b) {
        int c = a - b;
        return c < 0 ? c + M : c;
    }
}
