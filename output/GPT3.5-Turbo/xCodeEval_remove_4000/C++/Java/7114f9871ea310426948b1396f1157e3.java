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
    static ArrayList<Integer>[] unorderedDivisors;

    static void setIO() {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        K = sc.nextInt();
        Q = sc.nextInt();
        a = new int[N];
        q = new int[Q];
        for (int i = 0; i < N; i++) {
            a[i] = sc.nextInt();
        }
        for (int i = 0; i < Q; i++) {
            q[i] = sc.nextInt();
        }
    }

    static void intro(int v) {
        for (int d : unorderedDivisors[v]) {
            ans += coeff[d] * (ncr(ct[d] + 1, K) - ncr(ct[d], K));
            ct[d]++;
        }
    }

    static long ncr(int n, int r) {
        if (r < 0 || n < r)
            return 0;
        long res = 1;
        for (int i = 1; i <= r; i++) {
            res = res * (n - i + 1) / i;
        }
        return res;
    }

    public static void main(String[] args) {
        setIO();

        coeff = new long[MAXV];
        factors = new ArrayList[MAXV];
        unorderedDivisors = new ArrayList[MAXV];
        for (int i = 0; i < MAXV; i++) {
            factors[i] = new ArrayList<>();
            unorderedDivisors[i] = new ArrayList<>();
        }

        for (int g = 1; g < MAXV; g++) {
            for (int m = g, c = 1; m < MAXV; m += g, c++) {
                coeff[m] += g * sv[c].mu;
            }
        }

        ans = 0;
        ct = new int[MAXV];
        for (int e : a) {
            ct[e]++;
        }
        for (int g = 1; g < MAXV; g++) {
            for (int m = 2 * g; m < MAXV; m += g) {
                ct[g] += ct[m];
            }
            ans += coeff[g] * ncr(ct[g], K);
        }

        for (int i = 0; i < N; i++) {
            intro(a[i]);
            System.out.println(ans);
        }
    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
            st = new StringTokenizer("");
        }

        public String next() {
            while (!st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }
    }

    static class Sieve {
        int[] primes;
        Num[] nums;

        class Num {
            int leastPrime;
            int divLeastPrime;
            int lpMultiplicity;
            int mu;
            int phi;

            Num(int leastPrime, int divLeastPrime, int lpMultiplicity, int mu, int phi) {
                this.leastPrime = leastPrime;
                this.divLeastPrime = divLeastPrime;
                this.lpMultiplicity = lpMultiplicity;
                this.mu = mu;
                this.phi = phi;
            }

            Num prod(int myValue, int p) {
                if (p < leastPrime) {
                    return new Num(p, myValue, 1, -mu, phi * (p - 1));
                }
                return new Num(p, myValue, lpMultiplicity + 1, 0, phi * p);
            }
        }

        Sieve() {
            primes = new int[MAXV];
            nums = new Num[MAXV];
            nums[1] = Num.ONE();
            int idx = 0;
            for (int v = 2; v < MAXV; v++) {
                Num n = nums[v];
                if (n == null) {
                    n = nums[1].prod(1, v);
                    primes[idx++] = v;
                }
                for (int p : primes) {
                    if (p > n.leastPrime || v * p >= MAXV) {
                        break;
                    }
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

        ArrayList<Integer> factor(int v) {
            ArrayList<Integer> res = new ArrayList<>();
            while (v > 1) {
                res.add(nums[v].leastPrime);
                v = eliminateLeastPrime(v);
            }
            return res;
        }

        void id0(int v, IntConsumer f, int c) {
            if (v == 1) {
                f.accept(c);
                return;
            }
            int w = eliminateLeastPrime(v);
            for (int m = 0; m <= nums[v].lpMultiplicity; m++, c *= nums[v].leastPrime) {
                id0(w, f, c);
            }
        }

        ArrayList<Integer> unorderedDivisors(int v) {
            ArrayList<Integer> res = new ArrayList<>();
            id0(v, res::add, 1);
            return res;
        }
    }

    static Sieve sv = new Sieve();
}
