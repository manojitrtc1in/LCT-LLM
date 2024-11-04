import java.util.*;
import java.io.*;

public class 7114f9871ea310426948b1396f1157e3xcodeeval_processed_4000.json {
    static final int MAXV = (int) 1e6 + 1;
    static Sieve sv = new Sieve(MAXV);
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
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

        ModNum[] coeff = new ModNum[MAXV];
        for (int i = 0; i < MAXV; i++) {
            coeff[i] = new ModNum();
        }

        for (int g = 1; g < MAXV; g++) {
            for (int m = g, c = 1; m < MAXV; m += g, c++) {
                coeff[m].add(g * sv.nums[c].mu);
            }
        }

        ModNum ans = new ModNum();
        int[] ct = new int[MAXV];

        for (int e : a) ct[e]++;
        for (int g = 1; g < MAXV; g++) {
            for (int m = 2 * g; m < MAXV; m += g) {
                ct[g] += ct[m];
            }
            ans.add(coeff[g].multiply(ModNum.nCr(ct[g], K)));
        }

        for (int qv : q) {
            intro(qv, coeff, ct, ans);
            out.println(ans);
        }

        out.close();
    }

    static void intro(int v, ModNum[] coeff, int[] ct, ModNum ans) {
        sv.id0(v, d -> {
            ans.add(coeff[d].multiply(ModNum.nCr(ct[d] + 1, K).subtract(ModNum.nCr(ct[d], K))));
            ct[d]++;
        });
    }
}

class ModNum {
    static final int MOD = (int) 1e9 + 7;
    long v;

    ModNum() {
        this.v = 0;
    }

    ModNum(long _v) {
        this.v = _v % MOD;
        if (this.v < 0) this.v += MOD;
    }

    public void add(long x) {
        this.v += x;
        if (this.v >= MOD) this.v -= MOD;
    }

    public void subtract(long x) {
        this.v -= x;
        if (this.v < 0) this.v += MOD;
    }

    public ModNum multiply(ModNum o) {
        return new ModNum(this.v * o.v % MOD);
    }

    public static ModNum nCr(int n, int r) {
        if (r < 0 || n < r) return new ModNum(0);
        return factorial(n).multiply(inverseFactorial(r)).multiply(inverseFactorial(n - r));
    }

    static ModNum factorial(int n) {
        ModNum[] fact = new ModNum[n + 1];
        fact[0] = new ModNum(1);
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1].multiply(new ModNum(i));
        }
        return fact[n];
    }

    static ModNum inverseFactorial(int n) {
        return factorial(n).inverse();
    }

    public ModNum inverse() {
        return new ModNum(pow(MOD - 2));
    }

    public long pow(long e) {
        if (e == 0) return 1;
        ModNum res = new ModNum(1);
        ModNum base = this;
        while (e > 0) {
            if ((e & 1) == 1) res = res.multiply(base);
            base = base.multiply(base);
            e >>= 1;
        }
        return res.v;
    }
}

class Sieve {
    int[] leastPrime;
    int[] divLeastPrime;
    char[] lpMultiplicity;
    char[] mu;
    int[] phi;
    List<Integer> primes;

    Sieve(int maxV) {
        leastPrime = new int[maxV];
        divLeastPrime = new int[maxV];
        lpMultiplicity = new char[maxV];
        mu = new char[maxV];
        phi = new int[maxV];
        primes = new ArrayList<>();
        Arrays.fill(leastPrime, Integer.MAX_VALUE);
        leastPrime[1] = 1;

        for (int v = 2; v < maxV; v++) {
            if (leastPrime[v] == Integer.MAX_VALUE) {
                leastPrime[v] = v;
                primes.add(v);
                phi[v] = v - 1;
                mu[v] = 1;
            }
            for (int p : primes) {
                if (p > leastPrime[v] || v * p >= maxV) break;
                leastPrime[v * p] = p;
                if (v % p == 0) {
                    divLeastPrime[v * p] = divLeastPrime[v] * p;
                    lpMultiplicity[v * p] = (char) (lpMultiplicity[v] + 1);
                    mu[v * p] = 0;
                    phi[v * p] = phi[v] * p;
                    break;
                } else {
                    divLeastPrime[v * p] = v;
                    lpMultiplicity[v * p] = 1;
                    mu[v * p] = (char) -mu[v];
                    phi[v * p] = phi[v] * (p - 1);
                }
            }
        }
    }

    void id0(int v, Consumer<Integer> f) {
        if (v == 1) {
            f.accept(1);
            return;
        }
        int w = eliminateLeastPrime(v);
        for (int m = 0; m <= lpMultiplicity[v]; m++) {
            f.accept(w);
        }
    }

    int eliminateLeastPrime(int v) {
        for (int m = lpMultiplicity[v]; m > 0; m--) {
            v = divLeastPrime[v];
        }
        return v;
    }
}
