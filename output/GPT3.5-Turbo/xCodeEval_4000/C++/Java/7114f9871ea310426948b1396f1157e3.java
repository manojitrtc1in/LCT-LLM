import java.io.*;
import java.util.*;

class Main {
    static final int MAXV = 1000001;
    static int N, K, Q;
    static int[] a, q;
    static long ans;
    static int[] ct;
    static long[] coeff;
    static ArrayList<Integer>[] factors;
    static boolean[] isPrime;
    static ArrayList<Integer> primes;

    static void sieve() {
        isPrime = new boolean[MAXV];
        factors = new ArrayList[MAXV];
        primes = new ArrayList<>();
        for (int i = 0; i < MAXV; i++) {
            isPrime[i] = true;
            factors[i] = new ArrayList<>();
        }
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i < MAXV; i++) {
            if (isPrime[i]) {
                primes.add(i);
                for (int j = i; j < MAXV; j += i) {
                    isPrime[j] = false;
                    factors[j].add(i);
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
        PrintWriter pw = new PrintWriter(System.out);
        sieve();
        String[] parts = br.readLine().split(" ");
        N = Integer.parseInt(parts[0]);
        K = Integer.parseInt(parts[1]);
        Q = Integer.parseInt(parts[2]);
        a = new int[N];
        q = new int[Q];
        parts = br.readLine().split(" ");
        for (int i = 0; i < N; i++) {
            a[i] = Integer.parseInt(parts[i]);
        }
        parts = br.readLine().split(" ");
        for (int i = 0; i < Q; i++) {
            q[i] = Integer.parseInt(parts[i]);
        }
        coeff = new long[MAXV];
        for (int g = 1; g < MAXV; g++) {
            for (int m = g, c = 1; m < MAXV; m += g, c++) {
                coeff[m] += g * mu(c);
            }
        }
        ans = 0;
        ct = new int[MAXV];
        for (int e : a) ct[e]++;
        for (int g = 1; g < MAXV; g++) {
            for (int m = 2 * g; m < MAXV; m += g) {
                ct[g] += ct[m];
            }
            ans += coeff[g] * ncr(ct[g], K);
        }
        for (int qv : q) {
            intro(qv);
            pw.println(ans);
        }
        pw.close();
    }

    static int mu(int x) {
        int res = 1;
        for (int p : primes) {
            if (x % p == 0) {
                res *= -1;
                x /= p;
                if (x % p == 0) {
                    return 0;
                }
            }
            if (p * p > x) {
                break;
            }
        }
        if (x > 1) {
            res *= -1;
        }
        return res;
    }
}
