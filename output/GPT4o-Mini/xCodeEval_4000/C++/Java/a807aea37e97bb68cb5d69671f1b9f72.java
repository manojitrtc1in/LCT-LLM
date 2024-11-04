import java.util.*;

class DChaoticV {
    public void solve(Scanner cin, PrintWriter cout) {
        int N = cin.nextInt();
        int[] K = new int[N];
        for (int i = 0; i < N; i++) {
            K[i] = cin.nextInt();
        }
        Arrays.sort(K);
        int[] C = new int[5001];
        for (int k : K) C[k]++;

        List<Integer> P = Sieve.primes(5000);
        int M = P.size();

        int[][] D = new int[5001][M];
        for (int i = 0; i < M; i++) {
            int p = P.get(i);
            for (int pp = p; pp <= 5000; pp *= p) {
                for (int j = 0; j <= 5000; j++) {
                    D[j][i] += j / pp;
                }
            }
        }
        for (int i = 0; i <= 5000; i++) {
            for (int j = 0; j < M / 2; j++) {
                int temp = D[i][j];
                D[i][j] = D[i][M - 1 - j];
                D[i][M - 1 - j] = temp;
            }
        }

        long[][] Pref = new long[5001][M + 1];
        for (int i = 0; i <= 5000; i++) {
            for (int j = 0; j < M; j++) {
                Pref[i][j + 1] = Pref[i][j] + D[i][j];
            }
        }

        int[] CountPref = new int[5003];
        long tot = 0;
        for (int i = 0; i <= 5000; i++) {
            CountPref[i + 1] = CountPref[i] + C[i];
            tot += C[i] * Pref[i][M];
        }

        int use = K[N / 2];
        List<Pair> W = new ArrayList<>();
        long base = 0;
        for (int i = 0; i <= 5000; i++) {
            if (C[i] == 0) continue;

            int x = 0;
            long len = 0;
            while (x < M && D[i][x] == D[use][x]) {
                len += D[i][x];
                x++;
            }
            if (x < M) {
                len += Math.min(D[i][x], D[use][x]);
            }
            W.add(new Pair(len, C[i]));
            base += (Pref[i][M] - len) * C[i];
        }
        W.sort(Comparator.comparingLong(a -> a.x));

        long ans = Long.MAX_VALUE;
        for (Pair w : W) {
            long cur = 0;
            for (Pair ww : W) {
                cur += Math.abs(ww.x - w.x) * ww.y;
            }
            ans = Math.min(ans, base + cur);
        }
        cout.println(ans);
    }

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        PrintWriter cout = new PrintWriter(System.out);
        DChaoticV solver = new DChaoticV();
        solver.solve(cin, cout);
        cout.flush();
    }
}

class Sieve {
    public static List<Integer> primes(int n) {
        boolean[] isPrime = new boolean[n + 1];
        Arrays.fill(isPrime, true);
        isPrime[0] = false;
        if (n != 0) isPrime[1] = false;
        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        List<Integer> primes = new ArrayList<>();
        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) {
                primes.add(i);
            }
        }
        return primes;
    }
}

class Pair {
    long x;
    int y;

    Pair(long x, int y) {
        this.x = x;
        this.y = y;
    }
}
