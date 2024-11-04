import java.util.*;
import java.io.*;

public class 1533c622f4378455b3c8b9991c2f60e0xcodeeval_processed_4000.json {
    static class Sparse {
        int n;
        List<List<Pair<Integer, Integer>>> sp;

        void construct(List<Pair<Integer, Integer>> v) {
            n = v.size();
            int r = id17(n - 1);
            sp = new ArrayList<>(r);
            for (int i = 0; i < r; i++) {
                sp.add(new ArrayList<>(Collections.nCopies(n, new Pair<>(0, 0))));
            }
            for (int i = 0; i < n; i++) {
                sp.get(0).set(i, v.get(i));
            }
            for (int i = 1; i < r; i++) {
                for (int j = 0; j < n; j++) {
                    Pair<Integer, Integer> p1 = sp.get(i - 1).get(j);
                    Pair<Integer, Integer> p2 = sp.get(i - 1).get((j + (1 << (i - 1))) % n);
                    sp.get(i).set(j, id1(p1, p2, n));
                }
            }
        }

        Pair<Integer, Integer> segment(int l, int r) {
            if (l == -1 || r == -1) return new Pair<>(-1, -1);
            int szz = raz(r, l, n);
            if (l == r) return sp.get(0).get(l);
            int g = id17(szz) - 1;
            return id1(sp.get(g).get(l), sp.get(g).get((r + 1 - (1 << g)) % n + n) % n, n);
        }
    }

    static class Pair<A, B> {
        A X;
        B Y;

        Pair(A x, B y) {
            this.X = x;
            this.Y = y;
        }
    }

    static int raz(int a, int b, int M) {
        int c = a - b;
        return c < 0 ? c + M : c;
    }

    static int id17(int r) {
        int ans = 0;
        while (r > 0) {
            ++ans;
            r >>= 1;
        }
        return ans;
    }

    static Pair<Integer, Integer> id1(Pair<Integer, Integer> p1, Pair<Integer, Integer> p2, int n) {
        if (p1.X.equals(-1) || p2.X.equals(-1)) return new Pair<>(-1, -1);
        Pair<Integer, Integer> np1 = new Pair<>(0, raz(p1.Y, p1.X, n));
        Pair<Integer, Integer> np2 = new Pair<>(raz(p2.X, p1.X, n), raz(p2.Y, p1.X, n));
        if (np2.X <= np2.Y) {
            if (np2.Y == n - 1) return new Pair<>(-1, -1);
            else return new Pair<>(sum(np1.X, p1.X, n), sum(Math.max(np1.Y, np2.Y), p1.X, n));
        } else {
            if (np2.X <= np1.Y + 1) return new Pair<>(-1, -1);
            else return new Pair<>(sum(np2.X, p1.X, n), sum(Math.max(np1.Y, np2.Y), p1.X, n));
        }
    }

    static int sum(int a, int b, int M) {
        int c = a + b;
        return c >= M ? c - M : c;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

        int n = Integer.parseInt(br.readLine());
        if (n == 1) {
            out.println("0");
            out.close();
            return;
        }

        List<Integer> r = new ArrayList<>();
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            r.add(Integer.parseInt(st.nextToken()));
        }

        int zz = id17(n) + 1;
        List<Sparse> v = new ArrayList<>(zz);
        for (int i = 0; i < zz; i++) {
            v.add(new Sparse());
        }
        List<Pair<Integer, Integer>> prs = new ArrayList<>(Collections.nCopies(n, new Pair<>(0, 0)));

        for (int i = 0; i < n; i++) {
            if (r.get(i) >= n - 1) prs.set(i, new Pair<>(-1, -1));
            else prs.set(i, id1(new Pair<>(raz(i, r.get(i), n), i), new Pair<>(i, sum(i, r.get(i), n)), n));
        }

        v.get(0).construct(prs);

        for (int i = 1; i < zz; i++) {
            List<Pair<Integer, Integer>> id14 = new ArrayList<>(Collections.nCopies(n, new Pair<>(0, 0)));
            for (int j = 0; j < n; j++) {
                Pair<Integer, Integer> pairr = v.get(i - 1).segment(j, j);
                id14.set(j, v.get(i - 1).segment(pairr.X, pairr.Y));
            }
            v.get(i).construct(id14);
        }

        for (int i = 0; i < n; i++) {
            Pair<Integer, Integer> my_pr = new Pair<>(i, i);
            int ans = 0;
            for (int j = zz - 1; j >= 0; --j) {
                Pair<Integer, Integer> new_pr = v.get(j).segment(my_pr.X, my_pr.Y);
                if (new_pr.X != -1) {
                    ans += (1 << j);
                    my_pr = new_pr;
                }
            }
            out.print(ans + 1 + " ");
        }
        out.println();
        out.close();
    }
}
