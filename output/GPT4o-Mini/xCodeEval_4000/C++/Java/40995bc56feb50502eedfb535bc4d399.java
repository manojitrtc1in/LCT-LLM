import java.util.*;
import java.io.*;

public class 40995bc56feb50502eedfb535bc4d399_nc {
    static final int MAXV = (int) 1e6 + 1;
    static Sieve sv = new Sieve(MAXV);

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        int Q = Integer.parseInt(st.nextToken());
        
        int[] a = new int[N];
        int[] q = new int[Q];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            a[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < Q; i++) {
            q[i] = Integer.parseInt(st.nextToken());
        }

        ModNum ans = new ModNum(0);
        int[] ct = new int[MAXV];
        ModNum[] coeff = new ModNum[MAXV];
        for (int i = 0; i < MAXV; i++) {
            coeff[i] = new ModNum(0);
        }

        for (int e : a) ct[e]++;
        for (int g = 1; g < MAXV; g++) {
            for (int m = g, c = 1; m < MAXV; m += g, c++) {
                coeff[m].add(g * sv.getMu(c));
                if (c > 1) ct[g] += ct[m];
            }
            ans.add(coeff[g].multiply(ModNum.nCr(ct[g], K)));
        }

        for (int qv : q) {
            sv.forEachDivisorUnordered(qv, d -> {
                ans.add(coeff[d].multiply(ModNum.nCr(ct[d] + 1, K).subtract(ModNum.nCr(ct[d], K))));
                ct[d]++;
            });
            System.out.println(ans);
        }
    }
}

class ModNum {
    static final int MOD = (int) 1e9 + 7;
    int v;

    ModNum() {
        this.v = 0;
    }

    ModNum(long _v) {
        this.v = (int) (_v % MOD);
        if (v < 0) v += MOD;
    }

    public void add(ModNum o) {
        v += o.v;
        if (v >= MOD) v -= MOD;
    }

    public void subtract(ModNum o) {
        v -= o.v;
        if (v < 0) v += MOD;
    }

    public ModNum multiply(ModNum o) {
        return new ModNum((long) v * o.v);
    }

    public static ModNum nCr(int n, int r) {
        if (r < 0 || n < r) return new ModNum(0);
        return factorial(n).multiply(inverseFactorial(r)).multiply(inverseFactorial(n - r));
    }

    static ModNum factorial(int n) {
        // Implement factorial logic
        return new ModNum(1); // Placeholder
    }

    static ModNum inverseFactorial(int n) {
        // Implement inverse factorial logic
        return new ModNum(1); // Placeholder
    }

    @Override
    public String toString() {
        return String.valueOf(v);
    }
}

class Sieve {
    int[] leastPrime;
    int[] lpMultiplicity;
    int[] mu;
    int[] phi;
    List<Integer> primes;

    Sieve(int maxV) {
        leastPrime = new int[maxV];
        lpMultiplicity = new int[maxV];
        mu = new int[maxV];
        phi = new int[maxV];
        primes = new ArrayList<>();
        initialize(maxV);
    }

    void initialize(int maxV) {
        Arrays.fill(leastPrime, 0);
        mu[1] = 1;
        for (int v = 2; v < maxV; v++) {
            if (leastPrime[v] == 0) {
                leastPrime[v] = v;
                primes.add(v);
                mu[v] = -1;
                phi[v] = v - 1;
            }
            for (int p : primes) {
                if (p > leastPrime[v] || v * p >= maxV) break;
                leastPrime[v * p] = p;
                if (v % p == 0) {
                    lpMultiplicity[v * p] = lpMultiplicity[v] + 1;
                    mu[v * p] = 0;
                    phi[v * p] = phi[v] * p;
                    break;
                } else {
                    lpMultiplicity[v * p] = 1;
                    mu[v * p] = -mu[v];
                    phi[v * p] = phi[v] * (p - 1);
                }
            }
        }
    }

    int getMu(int c) {
        return mu[c];
    }

    void forEachDivisorUnordered(int v, Consumer<Integer> f) {
        if (v == 1) {
            f.accept(1);
            return;
        }
        int w = eliminateLeastPrime(v);
        for (int m = 0; m <= lpMultiplicity[v]; m++) {
            forEachDivisorUnordered(w, f, m);
        }
    }

    int eliminateLeastPrime(int v) {
        for (int m = lpMultiplicity[v]; m > 0; m--) {
            v = v / leastPrime[v];
        }
        return v;
    }
}
