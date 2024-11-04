import java.util.*;
import java.io.*;

public class 24c57f43f134a86e579f4ba2acfaec24_nc {
    static final int MAXV = (int) 1e6 + 1;
    static Sieve sv = new Sieve(MAXV);
    
    static class ModNum {
        int v;
        static final int MOD = (int) 1e9 + 7;

        ModNum() {
            v = 0;
        }

        ModNum(long _v) {
            v = (int) (_v % MOD);
            if (v < 0) v += MOD;
        }

        public static ModNum fromInt(int x) {
            return new ModNum(x);
        }

        public ModNum add(ModNum o) {
            v += o.v;
            if (v >= MOD) v -= MOD;
            return this;
        }

        public ModNum subtract(ModNum o) {
            v -= o.v;
            if (v < 0) v += MOD;
            return this;
        }

        public ModNum multiply(ModNum o) {
            v = (int) ((long) v * o.v % MOD);
            return this;
        }

        public ModNum pow(long e) {
            if (e < 0) return new ModNum(1).divide(this.pow(-e));
            if (e == 0) return new ModNum(1);
            if (e % 2 == 1) return this.multiply(this.pow(e - 1));
            return this.multiply(this).pow(e / 2);
        }

        public ModNum inverse() {
            return this.pow(MOD - 2);
        }

        public ModNum divide(ModNum o) {
            return this.multiply(o.inverse());
        }

        public static ModNum factorial(int n) {
            static List<ModNum> fact = new ArrayList<>(Collections.singletonList(new ModNum(1)));
            if (fact.size() <= n) {
                int had = fact.size();
                for (int i = had; i <= n; i++) {
                    fact.add(fact.get(i - 1).multiply(new ModNum(i)));
                }
            }
            return fact.get(n);
        }

        public static ModNum inverseFactorial(int n) {
            static List<ModNum> finv = new ArrayList<>(Collections.singletonList(new ModNum(1)));
            if (finv.size() <= n) {
                int had = finv.size();
                finv.add(factorial(n).inverse());
                for (int i = n - 1; i >= had; i--) {
                    finv.add(finv.get(i + 1).multiply(new ModNum(i + 1)));
                }
            }
            return finv.get(n);
        }

        public static ModNum nCr(int n, int r) {
            if (r < 0 || n < r) return new ModNum(0);
            return factorial(n).multiply(inverseFactorial(r)).multiply(inverseFactorial(n - r));
        }
    }

    static class Sieve {
        List<Integer> primes;
        Num[] nums;

        static class Num {
            int leastPrime;
            int divLeastPrime;
            char lpMultiplicity;
            char mu;
            int phi;

            static Num ONE() {
                return new Num(Integer.MAX_VALUE, 1, 0, 1, 1);
            }

            Num(int lp, int myValue, int lpMult, char mu, int phi) {
                this.leastPrime = lp;
                this.divLeastPrime = myValue;
                this.lpMultiplicity = (char) lpMult;
                this.mu = mu;
                this.phi = phi;
            }

            Num prod(int myValue, int p) {
                if (p < leastPrime)
                    return new Num(p, myValue, 1, (char) -mu, phi * (p - 1));
                assert (p == leastPrime);
                return new Num(p, myValue, lpMultiplicity + 1, (char) 0, phi * p);
            }
        }

        Sieve(int maxV) {
            primes = new ArrayList<>();
            nums = new Num[maxV];
            nums[1] = Num.ONE();
            for (int v = 2; v < maxV; v++) {
                Num n = nums[v];
                if (n == null) {
                    n = nums[1].prod(1, v);
                    primes.add(v);
                }
                for (int p : primes) {
                    if (p > n.leastPrime || v * p >= maxV) break;
                    nums[v * p] = n.prod(v, p);
                }
            }
        }

        boolean isPrime(int v) {
            assert (0 < v && v < MAXV);
            return nums[v].leastPrime == v;
        }

        int eliminateLeastPrime(int v) {
            assert (1 < v && v < MAXV);
            for (int m = nums[v].lpMultiplicity; m > 0; m--)
                v = nums[v].divLeastPrime;
            return v;
        }

        List<Pair<Integer, Integer>> factor(int v) {
            assert (0 < v && v < MAXV);
            List<Pair<Integer, Integer>> res = new ArrayList<>();
            while (v > 1) {
                res.add(new Pair<>(nums[v].leastPrime, nums[v].lpMultiplicity));
                v = eliminateLeastPrime(v);
            }
            Collections.reverse(res);
            return res;
        }

        void forEachDivisorUnordered(int v, Consumer<Integer> f, int c) {
            assert (0 < v && v < MAXV);
            if (v == 1) {
                f.accept(c);
                return;
            }
            int w = eliminateLeastPrime(v);
            for (int m = 0; m <= nums[v].lpMultiplicity; m++, c *= nums[v].leastPrime)
                forEachDivisorUnordered(w, f, c);
        }

        List<Integer> unorderedDivisors(int v) {
            assert (0 < v && v < MAXV);
            List<Integer> res = new ArrayList<>();
            forEachDivisorUnordered(v, res::add, 1);
            return res;
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

        List<ModNum> coeff = new ArrayList<>(Collections.nCopies(MAXV, new ModNum(0)));
        for (int g = 1; g < MAXV; g++) {
            for (int m = g, c = 1; m < MAXV; m += g, c++) {
                coeff.set(m, coeff.get(m).add(new ModNum(g).multiply(new ModNum(sv.nums[c].mu))));
            }
        }

        ModNum ans = new ModNum();
        int[] ct = new int[MAXV];

        Consumer<Integer> intro = (v) -> {
            sv.forEachDivisorUnordered(v, d -> {
                ans.add(coeff.get(d).multiply(ModNum.nCr(ct[d] + 1, K).subtract(ModNum.nCr(ct[d], K))));
                ct[d]++;
            }, 1);
        };

        for (int v : a) intro.accept(v);

        for (int qv : q) {
            intro.accept(qv);
            System.out.println(ans.v);
        }
    }
}
