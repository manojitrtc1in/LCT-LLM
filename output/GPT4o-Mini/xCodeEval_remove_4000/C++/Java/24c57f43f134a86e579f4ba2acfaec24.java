import java.util.*;
import java.io.*;

public class 24c57f43f134a86e579f4ba2acfaec24xcodeeval_processed_4000.json {
    static final int MAXV = (int) 1e6 + 1;
    static Sieve sv = new Sieve(MAXV);
    
    static class ModNum {
        int v;
        static final int MOD = (int) 1e9 + 7;

        ModNum() {
            this.v = 0;
        }

        ModNum(long _v) {
            this.v = (int) (_v % MOD);
            if (v < 0) v += MOD;
        }

        public static ModNum add(ModNum a, ModNum b) {
            return new ModNum((a.v + b.v) % MOD);
        }

        public static ModNum subtract(ModNum a, ModNum b) {
            return new ModNum((a.v - b.v + MOD) % MOD);
        }

        public static ModNum multiply(ModNum a, ModNum b) {
            return new ModNum((long) a.v * b.v % MOD);
        }

        public static ModNum nCr(int n, int r) {
            if (r < 0 || n < r) return new ModNum(0);
            return multiply(factorial(n), multiply(inverseFactorial(r), inverseFactorial(n - r)));
        }

        static ModNum factorial(int n) {
            ModNum[] fact = new ModNum[n + 1];
            fact[0] = new ModNum(1);
            for (int i = 1; i <= n; i++) {
                fact[i] = multiply(fact[i - 1], new ModNum(i));
            }
            return fact[n];
        }

        static ModNum inverseFactorial(int n) {
            return new ModNum(1).divide(factorial(n));
        }

        public ModNum divide(ModNum o) {
            return multiply(this, o.inv());
        }

        public ModNum inv() {
            return new ModNum(pow(MOD - 2));
        }

        public long pow(long e) {
            if (e < 0) return 1 / pow(-e);
            if (e == 0) return 1;
            if (e % 2 == 1) return multiply(this, pow(e - 1)).v;
            return multiply(this, this).pow(e / 2).v;
        }
    }

    static class Sieve {
        int[] leastPrime;
        int[] phi;
        List<Integer> primes;

        Sieve(int maxV) {
            leastPrime = new int[maxV];
            phi = new int[maxV];
            primes = new ArrayList<>();
            for (int i = 1; i < maxV; i++) {
                phi[i] = i;
            }
            for (int v = 2; v < maxV; v++) {
                if (leastPrime[v] == 0) {
                    leastPrime[v] = v;
                    primes.add(v);
                    phi[v] = v - 1;
                }
                for (int p : primes) {
                    if (p > leastPrime[v] || v * p >= maxV) break;
                    leastPrime[v * p] = p;
                    if (v % p == 0) {
                        phi[v * p] = phi[v] * p;
                        break;
                    } else {
                        phi[v * p] = phi[v] * (p - 1);
                    }
                }
            }
        }

        public void id0(int v, Consumer<Integer> f, int c) {
            if (v == 1) {
                f.accept(c);
                return;
            }
            int w = eliminateLeastPrime(v);
            for (int m = 0; m <= leastPrime[v]; m++, c *= leastPrime[v]) {
                id0(w, f, c);
            }
        }

        public int eliminateLeastPrime(int v) {
            for (int m = leastPrime[v]; m > 0; m--) {
                v = leastPrime[v];
            }
            return v;
        }
    }

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

        ModNum[] coeff = new ModNum[MAXV];
        for (int i = 0; i < MAXV; i++) {
            coeff[i] = new ModNum();
        }

        for (int g = 1; g < MAXV; g++) {
            for (int m = g, c = 1; m < MAXV; m += g, c++) {
                coeff[m] = ModNum.add(coeff[m], new ModNum(g).multiply(new ModNum(sv.phi[c])));
            }
        }

        ModNum ans = new ModNum();
        int[] ct = new int[MAXV];

        for (int v : a) {
            intro(v, coeff, ct, ans);
        }

        for (int qv : q) {
            intro(qv, coeff, ct, ans);
            System.out.println(ans.v);
        }
    }

    private static void intro(int v, ModNum[] coeff, int[] ct, ModNum ans) {
        sv.id0(v, d -> {
            ans = ModNum.add(ans, ModNum.subtract(ModNum.nCr(ct[d] + 1, K), ModNum.nCr(ct[d], K)));
            ct[d]++;
        }, 1);
    }
}
