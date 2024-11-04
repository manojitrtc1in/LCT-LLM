import java.util.*;
import java.io.*;

class DChaoticV {
    public void solve(Scanner cin, PrintWriter cout) {
        int N = cin.nextInt();
        List<Integer> K = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            K.add(cin.nextInt());
        }
        Collections.sort(K);
        List<Integer> C = new ArrayList<>(Collections.nCopies(5001, 0));
        for (int k : K) {
            C.set(k, C.get(k) + 1);
        }

        List<Integer> P = new Sieve(5000).primes();
        int M = P.size();

        List<List<Integer>> D = new ArrayList<>();
        for (int i = 0; i <= 5000; i++) {
            D.add(new ArrayList<>(Collections.nCopies(M, 0)));
        }
        for (int i = 0; i < M; i++) {
            int p = P.get(i);
            for (int j = p; j <= 5000; j += p) {
                for (int k = 0; k <= 5000; k++) {
                    D.get(k).set(i, D.get(k).get(i) + k / p);
                }
            }
        }
        for (int i = 0; i <= 5000; i++) {
            Collections.reverse(D.get(i));
        }

        List<List<Long>> Pref = new ArrayList<>();
        for (int i = 0; i <= 5000; i++) {
            Pref.add(new ArrayList<>(Collections.nCopies(M + 1, 0L)));
        }
        for (int i = 0; i <= 5000; i++) {
            for (int j = 0; j < M; j++) {
                Pref.get(i).set(j + 1, Pref.get(i).get(j) + D.get(i).get(j));
            }
        }

        List<Integer> CountPref = new ArrayList<>(Collections.nCopies(5002, 0));
        long tot = 0;
        for (int i = 0; i <= 5000; i++) {
            CountPref.set(i + 1, CountPref.get(i) + C.get(i));
            tot += C.get(i) * Pref.get(i).get(M);
        }

        int use = K.get(N / 2);
        List<Pair<Long, Integer>> W = new ArrayList<>();
        long base = 0;
        for (int i = 0; i <= 5000; i++) {
            if (C.get(i) == 0) continue;

            int x = 0;
            long len = 0;
            while (x < M && D.get(i).get(x) == D.get(use).get(x)) {
                len += D.get(i).get(x);
                x++;
            }
            if (x < M) {
                len += Math.min(D.get(i).get(x), D.get(use).get(x));
            }
            W.add(new Pair<>(len, C.get(i)));
            base += (Pref.get(i).get(M) - len) * C.get(i);
        }
        Collections.sort(W, new Comparator<Pair<Long, Integer>>() {
            public int compare(Pair<Long, Integer> a, Pair<Long, Integer> b) {
                return a.x.compareTo(b.x);
            }
        });

        long ans = (long) 1e18;
        for (Pair<Long, Integer> w : W) {
            long cur = 0;
            for (Pair<Long, Integer> ww : W) {
                cur += Math.abs(ww.x - w.x) * ww.y;
            }
            ans = Math.min(ans, base + cur);
        }
        cout.println(ans);
    }

    public static void main(String[] args) throws Exception {
        Scanner cin = new Scanner(System.in);
        PrintWriter cout = new PrintWriter(System.out);
        DChaoticV solver = new DChaoticV();
        solver.solve(cin, cout);
        cout.close();
    }

    static class Pair<T, U> {
        T x;
        U y;

        Pair(T x, U y) {
            this.x = x;
            this.y = y;
        }
    }

    static class Sieve {
        boolean[] prime;

        Sieve(int n) {
            prime = new boolean[n + 1];
            Arrays.fill(prime, true);
            prime[0] = prime[1] = false;
            for (int i = 2; i * i <= n; i++) {
                if (prime[i]) {
                    for (int j = i * i; j <= n; j += i) {
                        prime[j] = false;
                    }
                }
            }
        }

        List<Integer> primes() {
            List<Integer> ans = new ArrayList<>();
            for (int i = 2; i < prime.length; i++) {
                if (prime[i]) {
                    ans.add(i);
                }
            }
            return ans;
        }
    }
}
