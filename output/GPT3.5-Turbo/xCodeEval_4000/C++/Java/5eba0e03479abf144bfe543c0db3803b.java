import java.util.*;
import java.io.*;

public class 5eba0e03479abf144bfe543c0db3803b_nc {
    static final int N = 20 * 1000 * 1000 + 13;
    static String s;
    static int n;
    static List<Integer> ord;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        while ((line = br.readLine()) != null) {
            s = line;
            n = s.length();
            solve();
        }
    }

    static void solve() {
        for (int t = n + 1; t >= 1; --t) {
            ord = new ArrayList<>();
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
                List<Integer> L = new ArrayList<>(x / 2);
                List<Integer> R = new ArrayList<>((x + 1) / 2);
                while (r < n) {
                    if (s.charAt(r++) == '0') {
                        L.add(cnt0 + cnt1);
                        ++cnt0;
                        if (cnt0 == x / 2 && cnt1 < (x + 1) / 2) {
                            fl = true;
                            break;
                        }
                    } else {
                        R.add(cnt0 + cnt1);
                        ++cnt1;
                        if (cnt1 == (x + 1) / 2 && cnt0 < x / 2) {
                            fl = true;
                            break;
                        }
                    }
                }
                while (cnt0 < x / 2) {
                    L.add(cnt0 + cnt1);
                    ++cnt0;
                }
                while (cnt1 < (x + 1) / 2) {
                    R.add(cnt0 + cnt1);
                    ++cnt1;
                }
                List<Integer> nw = new ArrayList<>();
                for (int i = 0; i < res.get(res.size() - 2).size(); i++) {
                    nw.add(L.get(res.get(res.size() - 2).get(i)));
                }
                for (int i = 0; i < res.get(res.size() - 1).size(); i++) {
                    nw.add(R.get(res.get(res.size() - 1).get(i)));
                }
                res.remove(res.size() - 1);
                res.remove(res.size() - 1);
                res.add(nw);
                if (!fl) break;
                l = r;
            }
            System.out.println(t);
            for (int x : res.get(0)) {
                System.out.print((x + 1) + " ");
            }
            System.out.println();
            break;
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
}
