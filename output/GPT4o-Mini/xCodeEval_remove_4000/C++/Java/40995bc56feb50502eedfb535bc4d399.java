import java.util.*;
import java.io.*;

public class 40995bc56feb50502eedfb535bc4d399xcodeeval_processed_4000.json {
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

        for (int e : a) {
            ct[e]++;
        }
        for (int g = 1; g < MAXV; g++) {
            for (int m = g, c = 1; m < MAXV; m += g, c++) {
                coeff[m].add(g * sv.getMu(c));
                if (c > 1) {
                    ct[g] += ct[m];
                }
            }
            ans.add(coeff[g].multiply(ModNum.nCr(ct[g], K)));
        }

        for (int qv : q) {
            sv.id0(qv, d -> {
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

    public void multiply(ModNum o) {
        v = fastMod((long) v * o.v);
    }

    public static ModNum nCr(int n, int r) {
        if (r < 0 || n < r) return new ModNum(0);
        return factorial(n).multiply(inverseFactorial(r)).multiply(inverseFactorial(n - r));
    }

    public static ModNum factorial(int n) {
        // Implementation of factorial
    }

    public static ModNum inverseFactorial(int n) {
        // Implementation of inverse factorial
    }

    public static int fastMod(long x) {
        return (int) (x % MOD);
    }

    @Override
    public String toString() {
        return String.valueOf(v);
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

        leastPrime[1] = Integer.MAX_VALUE;
        for (int v = 2; v < maxV; v++) {
            if (leastPrime[v] == 0) {
                leastPrime[v] = v;
                primes.add(v);
                // Additional sieve logic
            }
        }
    }

    public int getMu(int c) {
        // Return the value of mu based on the index
    }

    public void id0(int v, Consumer<Integer> f) {
        // Implementation of id0
    }
}
