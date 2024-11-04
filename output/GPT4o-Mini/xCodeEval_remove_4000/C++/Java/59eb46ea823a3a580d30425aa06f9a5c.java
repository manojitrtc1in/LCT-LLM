import java.util.*;
import java.io.*;

public class 59eb46ea823a3a580d30425aa06f9a5cxcodeeval_processed_4000.json {
    static class Pair {
        long x, y;

        Pair(long x, long y) {
            this.x = x;
            this.y = y;
        }
    }

    static class Factorizator {
        final int N = 2000001;
        List<Integer> pr = new ArrayList<>();
        int[] md = new int[N];
        int[] pw = new int[N];
        int[] without_md = new int[N];

        void init() {
            Arrays.fill(without_md, 1);
            for (int i = 2; i < N; i++) {
                md[i] = i;
            }
            for (int i = 2; i < N; i++) {
                if (md[i] == i) {
                    pr.add(i);
                }
                boolean worth = true;
                for (int j = 0; worth && (j < pr.size()) && (pr.get(j) <= md[i]); j++) {
                    long temp = (long) pr.get(j) * i;
                    if (temp < N) {
                        md[(int) temp] = pr.get(j);
                    } else {
                        worth = false;
                    }
                }
            }
            for (int i = 2; i < N; i++) {
                int t = md[i], s = i / t;
                if (md[s] == t) {
                    pw[i] = 1 + pw[s];
                    without_md[i] = without_md[s];
                } else {
                    pw[i] = 1;
                    without_md[i] = s;
                }
            }
        }

        List<Pair> factorize(int n) {
            List<Pair> ans = new ArrayList<>();
            for (int i = 0; (i < pr.size()) && (pr.get(i) * (long) pr.get(i) <= n); i++) {
                int t = n / pr.get(i);
                if (t * pr.get(i) == n) {
                    ans.add(new Pair(pr.get(i), 0));
                    do {
                        ans.get(ans.size() - 1).y++;
                        n = t;
                        t = n / pr.get(i);
                    } while (t * pr.get(i) == n);
                }
                if (n < N) {
                    knownFactorization(n, ans);
                    return ans;
                }
            }
            if (n > 1) {
                ans.add(new Pair(n, 1));
            }
            return ans;
        }

        void knownFactorization(int n, List<Pair> v) {
            while (n > 1) {
                v.add(new Pair(md[n], pw[n]));
                n = without_md[n];
            }
        }
    }

    static Factorizator fac = new Factorizator();

    static int gcd(int a, int b) {
        while (b != 0) {
            a %= b;
            int temp = a;
            a = b;
            b = temp;
        }
        return a;
    }

    static int powMod(int a, int b, int p) {
        if (b < 2) {
            return (b == 0) ? 1 : a;
        }
        int temp = powMod(a, b >> 1, p);
        temp = (int) ((long) temp * temp % p);
        return (b & 1) == 1 ? (int) ((long) temp * a % p) : temp;
    }

    static void take(int k, List<Pair> perm, List<Pair> points) {
        int n = points.size();
        for (int i = 0; i < n; i++) {
            if (points.get(i).y == k) {
                Collections.swap(points, i, n - 1);
                break;
            }
        }
        perm.add(points.remove(points.size() - 1));
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        fac.init();

        int n = Integer.parseInt(br.readLine());
        List<Pair> p = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            long x = Long.parseLong(st.nextToken());
            p.add(new Pair(x, i));
        }
        String s = br.readLine();
        List<Pair> perm = new ArrayList<>();
        int firstIdx = 0;
        for (int i = 1; i < n; i++) {
            if (p.get(i).x < p.get(firstIdx).x) {
                firstIdx = i;
            }
        }
        take(firstIdx, perm, p);
        for (int i = 0; i < n - 2; i++) {
            Pair q = perm.get(perm.size() - 1);
            int best = 0;
            for (int j = 1; j < p.size(); j++) {
                if ((((p.get(best).x - q.x) * (p.get(j).y - q.y)) > 0) == (s.charAt(i) == 'R')) {
                    best = j;
                }
            }
            take(p.get(best).y, perm, p);
        }
        take(p.get(0).y, perm, p);
        for (Pair pair : perm) {
            out.print((pair.y + 1) + " ");
        }
        out.println();
        out.flush();
    }
}
