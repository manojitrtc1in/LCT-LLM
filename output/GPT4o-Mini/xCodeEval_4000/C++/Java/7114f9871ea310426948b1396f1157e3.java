import java.util.*;
import java.io.*;

public class 7114f9871ea310426948b1396f1157e3_nc {
    static final int MAXV = (int) 1e6 + 1;
    static Sieve sv = new Sieve(MAXV);
    static long MOD = (long) 1e9 + 7;

    static class ModNum {
        long v;

        ModNum() {
            this.v = 0;
        }

        ModNum(long _v) {
            this.v = (_v % MOD + MOD) % MOD;
        }

        public static ModNum add(ModNum a, ModNum b) {
            return new ModNum((a.v + b.v) % MOD);
        }

        public static ModNum subtract(ModNum a, ModNum b) {
            return new ModNum((a.v - b.v + MOD) % MOD);
        }

        public static ModNum multiply(ModNum a, ModNum b) {
            return new ModNum((a.v * b.v) % MOD);
        }

        public static ModNum nCr(int n, int r) {
            if (r < 0 || n < r) return new ModNum(0);
            return multiply(factorial(n), multiply(inverseFactorial(r), inverseFactorial(n - r)));
        }

        static ModNum factorial(int n) {
            static ModNum[] fact = new ModNum[MAXV];
            if (fact[0] == null) {
                fact[0] = new ModNum(1);
                for (int i = 1; i < MAXV; i++) {
                    fact[i] = multiply(fact[i - 1], new ModNum(i));
                }
            }
            return fact[n];
        }

        static ModNum inverseFactorial(int n) {
            static ModNum[] finv = new ModNum[MAXV];
            if (finv[0] == null) {
                finv[0] = new ModNum(1);
                for (int i = 1; i < MAXV; i++) {
                    finv[i] = new ModNum(1).divide(factorial(i));
                }
            }
            return finv[n];
        }

        public ModNum divide(ModNum o) {
            return multiply(this, o.inv());
        }

        public ModNum inv() {
            return new ModNum(pow(MOD - 2));
        }

        public long pow(long e) {
            if (e == 0) return 1;
            ModNum res = new ModNum(1);
            ModNum base = this;
            while (e > 0) {
                if ((e & 1) == 1) res = multiply(res, base);
                base = multiply(base, base);
                e >>= 1;
            }
            return res.v;
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

            Num(int leastPrime, int divLeastPrime, char lpMultiplicity, char mu, int phi) {
                this.leastPrime = leastPrime;
                this.divLeastPrime = divLeastPrime;
                this.lpMultiplicity = lpMultiplicity;
                this.mu = mu;
                this.phi = phi;
            }

            Num prod(int myValue, int p) {
                if (p < leastPrime) {
                    return new Num(p, myValue, (char) 1, (char) -mu, phi * (p - 1));
                }
                return new Num(p, myValue, (char) (lpMultiplicity + 1), (char) 0, phi * p);
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
            return nums[v].leastPrime == v;
        }

        int eliminateLeastPrime(int v) {
            for (int m = nums[v].lpMultiplicity; m > 0; m--) {
                v = nums[v].divLeastPrime;
            }
            return v;
        }

        List<Pair> factor(int v) {
            List<Pair> res = new ArrayList<>();
            while (v > 1) {
                res.add(new Pair(nums[v].leastPrime, nums[v].lpMultiplicity));
                v = eliminateLeastPrime(v);
            }
            Collections.reverse(res);
            return res;
        }

        void forEachDivisorUnordered(int v, Consumer<Integer> f, int c) {
            if (v == 1) {
                f.accept(c);
                return;
            }
            int w = eliminateLeastPrime(v);
            for (int m = 0; m <= nums[v].lpMultiplicity; m++, c *= nums[v].leastPrime) {
                forEachDivisorUnordered(w, f, c);
            }
        }

        List<Integer> unorderedDivisors(int v) {
            List<Integer> res = new ArrayList<>();
            forEachDivisorUnordered(v, res::add, 1);
            return res;
        }
    }

    static class Pair {
        int first, second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
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
        for (int g = 1; g < MAXV; g++) {
            coeff[g] = new ModNum(0);
            for (int m = g, c = 1; m < MAXV; m += g, c++) {
                coeff[m] = ModNum.add(coeff[m], new ModNum(g * sv.nums[c].mu));
            }
        }

        ModNum ans = new ModNum(0);
        int[] ct = new int[MAXV];

        for (int e : a) ct[e]++;
        for (int g = 1; g < MAXV; g++) {
            for (int m = 2 * g; m < MAXV; m += g) {
                ct[g] += ct[m];
            }
            ans = ModNum.add(ans, ModNum.multiply(coeff[g], ModNum.nCr(ct[g], K)));
        }

        for (int qv : q) {
            intro(qv, coeff, ct, ans);
            System.out.println(ans.v);
        }
    }

    static void intro(int v, ModNum[] coeff, int[] ct, ModNum ans) {
        sv.forEachDivisorUnordered(v, d -> {
            ans = ModNum.add(ans, ModNum.multiply(coeff[d], ModNum.subtract(ModNum.nCr(ct[d] + 1, K), ModNum.nCr(ct[d], K))));
            ct[d]++;
        }, 1);
    }
}
