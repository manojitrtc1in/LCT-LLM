import java.util.*;
import java.io.*;

public class 5eba0e03479abf144bfe543c0db3803b_nc {
    static final int INF = (int) 1e9;
    static final long INF64 = (long) 1e18;
    static final int MOD = (int) 1e9 + 7;
    static final double EPS = 1e-9;
    static final double PI = Math.acos(-1.0);
    static final int N = 20 * 1000 * 1000 + 13;

    static String s;
    static int n;
    static List<Integer> ord = new ArrayList<>();

    static boolean read() {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            s = br.readLine();
            n = s.length();
            return true;
        } catch (IOException e) {
            return false;
        }
    }

    static void gen(int n) {
        if (n == 1) {
            ord.add(1);
            return;
        }
        gen(n / 2);
        gen((n + 1) / 2);
        ord.add(n);
    }

    static void solve() {
        for (int t = n + 1; t >= 1; --t) {
            ord.clear();
            gen(t);
            int l = 0;
            int pr = 0;
            for (int x : ord) {
                if (x == 1) {
                    ++pr;
                    continue;
                }
                int cnt0 = 0, cnt1 = 0;
                int r = l;
                boolean fl = false;
                while (r < n) {
                    if (s.charAt(r++) == '0') {
                        ++cnt0;
                        if (cnt0 == x / 2 && cnt1 < (x + 1) / 2) {
                            fl = true;
                            break;
                        }
                    } else {
                        ++cnt1;
                        if (cnt1 == (x + 1) / 2 && cnt0 < x / 2) {
                            fl = true;
                            break;
                        }
                    }
                }
                if (!fl) break;
                l = r;
                ++pr;
            }
            if (l != n || pr != ord.size()) continue;
            List<List<Integer>> res = new ArrayList<>();
            l = 0;
            for (int x : ord) {
                if (x == 1) {
                    res.add(Collections.singletonList(0));
                    continue;
                }
                int cnt0 = 0, cnt1 = 0;
                int r = l;
                boolean fl = false;
                List<Integer> L = new ArrayList<>(Collections.nCopies(x / 2, 0));
                List<Integer> R = new ArrayList<>(Collections.nCopies((x + 1) / 2, 0));
                while (r < n) {
                    if (s.charAt(r++) == '0') {
                        L.set(cnt0, cnt0 + cnt1);
                        ++cnt0;
                        if (cnt0 == x / 2 && cnt1 < (x + 1) / 2) {
                            fl = true;
                            break;
                        }
                    } else {
                        R.set(cnt1, cnt0 + cnt1);
                        ++cnt1;
                        if (cnt1 == (x + 1) / 2 && cnt0 < x / 2) {
                            fl = true;
                            break;
                        }
                    }
                }
                while (cnt0 < x / 2) L.set(cnt0, cnt0 + cnt1++);
                while (cnt1 < (x + 1) / 2) R.set(cnt1, cnt0 + cnt1++);
                List<Integer> nw = new ArrayList<>();
                for (int val : res.get(res.size() - 2)) nw.add(L.get(val));
                for (int val : res.get(res.size() - 1)) nw.add(R.get(val));
                res.remove(res.size() - 1);
                res.remove(res.size() - 1);
                res.add(nw);
                if (!fl) break;
                l = r;
            }
            System.out.println(t);
            for (int x : res.get(0))
                System.out.print((x + 1) + " ");
            System.out.println();
            break;
        }
    }

    public static void main(String[] args) {
        while (read()) {
            solve();
        }
    }
}