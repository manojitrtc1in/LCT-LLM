import java.util.*;
import java.io.*;

class Main {
    static final int MAXV = 1000001;
    static int N, K, Q;
    static int[] a, q;
    static long ans;
    static int[] ct;
    static long[] coeff;
    static int[] primes;
    static int[] leastPrime;
    static int[] divLeastPrime;
    static int[] lpMultiplicity;
    static int[] mu;
    static int[] phi;

    static void sieve() {
        primes = new int[MAXV];
        leastPrime = new int[MAXV];
        divLeastPrime = new int[MAXV];
        lpMultiplicity = new int[MAXV];
        mu = new int[MAXV];
        phi = new int[MAXV];
        ct = new int[MAXV];
        coeff = new long[MAXV];

        int idx = 0;
        for (int i = 2; i < MAXV; i++) {
            if (leastPrime[i] == 0) {
                leastPrime[i] = i;
                primes[idx++] = i;
            }
            for (int j = 0; j < idx && primes[j] <= leastPrime[i] && i * primes[j] < MAXV; j++) {
                leastPrime[i * primes[j]] = primes[j];
                divLeastPrime[i * primes[j]] = i;
            }
        }

        mu[1] = 1;
        phi[1] = 1;
        for (int i = 2; i < MAXV; i++) {
            if (leastPrime[i] == i) {
                if (i % leastPrime[divLeastPrime[i]] == 0) {
                    lpMultiplicity[i] = lpMultiplicity[divLeastPrime[i]] + 1;
                    mu[i] = 0;
                } else {
                    lpMultiplicity[i] = 1;
                    mu[i] = -mu[divLeastPrime[i]];
                }
                phi[i] = phi[divLeastPrime[i]] * (leastPrime[i] - 1);
            } else {
                lpMultiplicity[i] = lpMultiplicity[divLeastPrime[i]] + 1;
                mu[i] = 0;
                phi[i] = phi[divLeastPrime[i]] * leastPrime[i];
            }
        }
    }

    static void id0(int v, IntConsumer f, int c) {
        if (v == 1) {
            f.accept(c);
            return;
        }
        int w = eliminateLeastPrime(v);
        for (int m = 0; m <= lpMultiplicity[v]; m++, c *= leastPrime[v]) {
            id0(w, f, c);
        }
    }

    static int eliminateLeastPrime(int v) {
        for (int m = lpMultiplicity[v]; m > 0; m--) {
            v = divLeastPrime[v];
        }
        return v;
    }

    static void solve() {
        ans = 0;
        for (int i = 0; i < N; i++) {
            ct[a[i]]++;
        }

        for (int g = 1; g < MAXV; g++) {
            for (int m = g, c = 1; m < MAXV; m += g, c++) {
                coeff[m] += g * mu[c];
                if (c > 1) {
                    ct[g] += ct[m];
                }
            }
            ans += coeff[g] * ncr(ct[g], K);
        }

        for (int i = 0; i < Q; i++) {
            int qv = q[i];
            id0(qv, d -> {
                ans += coeff[d] * (ncr(ct[d] + 1, K) - ncr(ct[d], K));
                ct[d]++;
            });
            System.out.println(ans);
        }
    }

    static long ncr(int n, int r) {
        if (r < 0 || n < r) {
            return 0;
        }
        long res = 1;
        for (int i = 0; i < r; i++) {
            res = res * (n - i) / (i + 1);
        }
        return res;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        K = Integer.parseInt(input[1]);
        Q = Integer.parseInt(input[2]);
        a = new int[N];
        q = new int[Q];
        input = br.readLine().split(" ");
        for (int i = 0; i < N; i++) {
            a[i] = Integer.parseInt(input[i]);
        }
        input = br.readLine().split(" ");
        for (int i = 0; i < Q; i++) {
            q[i] = Integer.parseInt(input[i]);
        }

        sieve();
        solve();
    }
}
