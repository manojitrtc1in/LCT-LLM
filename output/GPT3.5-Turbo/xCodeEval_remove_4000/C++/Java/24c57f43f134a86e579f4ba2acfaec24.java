import java.util.*;
import java.io.*;

class Main {
    static final int MAXV = 1000001;
    static int N, K, Q;
    static int[] a, q;
    static long ans;
    static int[] ct;
    static long[] coeff;
    static ArrayList<Integer>[] factors;
    static ArrayList<Integer> primes;

    static void sieve() {
        factors = new ArrayList[MAXV];
        primes = new ArrayList<>();
        for (int i = 0; i < MAXV; i++) {
            factors[i] = new ArrayList<>();
        }
        for (int v = 2; v < MAXV; v++) {
            if (factors[v].size() == 0) {
                primes.add(v);
                for (int m = v; m < MAXV; m += v) {
                    factors[m].add(v);
                }
            }
        }
    }

    static void intro(int v) {
        for (int d : factors[v]) {
            ans += coeff[d] * (ncr(ct[d] + 1, K) - ncr(ct[d], K));
            ct[d]++;
        }
    }

    static long ncr(int n, int r) {
        if (r < 0 || n < r) return 0;
        long res = 1;
        for (int i = 0; i < r; i++) {
            res *= (n - i);
            res /= (i + 1);
        }
        return res;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        N = Integer.parseInt(line[0]);
        K = Integer.parseInt(line[1]);
        Q = Integer.parseInt(line[2]);
        a = new int[N];
        q = new int[Q];
        line = br.readLine().split(" ");
        for (int i = 0; i < N; i++) {
            a[i] = Integer.parseInt(line[i]);
        }
        line = br.readLine().split(" ");
        for (int i = 0; i < Q; i++) {
            q[i] = Integer.parseInt(line[i]);
        }

        coeff = new long[MAXV];
        for (int g = 1; g < MAXV; g++) {
            for (int m = g, c = 1; m < MAXV; m += g, c++) {
                coeff[m] += g * (c % 2 == 0 ? -1 : 1);
            }
        }

        ans = 0;
        ct = new int[MAXV];
        sieve();

        for (int v : a) {
            intro(v);
        }

        for (int qv : q) {
            intro(qv);
            System.out.println(ans);
        }
    }
}
