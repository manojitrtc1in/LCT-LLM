import java.util.*;

public class ad473362180b0b30cb1e2fa5ba0fdbc0_nc {
    static long INFLL = (long) 1e18;
    static int MAXN = (int) 1e5 + 100;
    static int MAXNN = (int) 2e4 + 100;
    static int INF = (int) 1e9;
    static int mod1 = (int) 1e9 + 7;
    static int mod2 = (int) 1e9 + 21;
    static List<Pair<Pair<Integer, Integer>, Pair<Integer, Integer>>> a = new ArrayList<>();
    static int[][] pref = new int[MAXN][2];
    static int[] ha = new int[MAXNN], haa_0 = new int[MAXNN], haa_1 = new int[MAXNN];
    static StringBuilder ss = new StringBuilder();
    static List<Integer> p = new ArrayList<>();

    static void ms(int l, int r) {
        if (r <= l) return;
        int mid = ((l + r + 1) >> 1) - 1;
        ms(l, mid);
        ms(mid + 1, r);
        a.add(new Pair<>(new Pair<>(l, mid), new Pair<>(mid + 1, r)));
    }

    static void mss(int l, int r) {
        if (r <= l) return;
        int mid = ((l + r + 1) >> 1) - 1;
        mss(l, mid);
        mss(mid + 1, r);
        int i = l, j = mid + 1;
        List<Integer> b = new ArrayList<>(Collections.nCopies(r - l + 1, 0));

        int now = 0;
        while (i <= mid && j <= r) {
            if (p.get(i) < p.get(j)) {
                ss.append('0');
                b.set(now++, p.get(i++));
            } else {
                ss.append('1');
                b.set(now++, p.get(j++));
            }
        }
        while (i <= mid) b.set(now++, p.get(i++));
        while (j <= r) b.set(now++, p.get(j++));
        for (i = l, j = 0; i <= r; i++, j++) p.set(i, b.get(j));
    }

    static void solve() {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        s = new StringBuilder(s).reverse().toString();
        for (int i = 1; i <= s.length(); i++) {
            if (s.charAt(i - 1) == '0') {
                pref[i][0] = pref[i - 1][0] + 1;
                pref[i][1] = pref[i - 1][1];
            } else {
                pref[i][1] = pref[i - 1][1] + 1;
                pref[i][0] = pref[i - 1][0];
            }
        }

        int[] check_ans2(int n) {
            a.clear();
            ms(0, n - 1);
            Collections.reverse(a);
            int[] ans = new int[n];
            int now = 0;

            boolean does_zero(int ff) {
                int cur = 1;
                int cnt1 = 0, cnt2 = 0;
                Pair<Pair<Integer, Integer>, Pair<Integer, Integer>> to = a.get(0);
                int sz1 = to.first.second - to.first.first + 1;
                int sz2 = to.second.second - to.second.first + 1;
                cnt1 = 0;
                cnt2 = 0;
                now = ff;

                for (int i = now - 1; i >= 0; i--) {
                    char u = s.charAt(i);
                    if (u == '0') ans[cnt1++] = cur++;
                    else ans[sz1 + cnt2] = cur++, cnt2++;
                }
                while (cnt1 < sz1) ans[cnt1++] = cur++;
                while (cnt2 < sz2) ans[sz1 + cnt2] = cur++, cnt2++;
                return true;
            }

            boolean does(int delta, int _) {
                Pair<Pair<Integer, Integer>, Pair<Integer, Integer>> to = a.get(_);
                int cnt1 = 0, cnt2 = 0;
                int sz1 = to.first.second - to.first.first + 1;
                int sz2 = to.second.second - to.second.first + 1;
                int was = now;
                List<Integer> fir = new ArrayList<>(Collections.nCopies(sz1, 0));
                List<Integer> sec = new ArrayList<>(Collections.nCopies(sz2, 0));
                cnt1 = 0;
                cnt2 = 0;
                int f = to.first.first;
                now += delta;

                for (int i = now - 1; i >= was; i--) {
                    if (s.charAt(i) == '0') fir.set(cnt1++, ans[f++]);
                    else sec.set(cnt2++, ans[f++]);
                }
                assert cnt1 == sz1 || cnt2 == sz2;
                assert cnt1 < sz1 || cnt2 < sz2;
                while (cnt1 < sz1) fir.set(cnt1++, ans[f++]);
                while (cnt2 < sz2) sec.set(cnt2++, ans[f++]);
                for (int i = to.first.first, j = 0; i <= to.first.second; i++, j++) ans[i] = fir.get(j);
                for (int i = to.second.first, j = 0; i <= to.second.second; i++, j++) ans[i] = sec.get(j);
                return true;
            }

            List<Map<Integer, Boolean>> dp = new ArrayList<>(Collections.nCopies(a.size() + 1, new HashMap<>()));
            dp.get(0).put(0, true);
            int y = -INF;

            for (int i = 0; i < a.size(); i++) {
                if (dp.get(i).isEmpty()) break;
                Pair<Pair<Integer, Integer>, Pair<Integer, Integer>> to = a.get(i);
                int sz1 = to.first.second - to.first.first + 1;
                int sz2 = to.second.second - to.second.first + 1;
                int prev_val = -123, prev_w = -1;
                int was_cnt1 = 0, was_cnt2 = 0;

                for (Map.Entry<Integer, Boolean> too : dp.get(i).entrySet()) {
                    int cnt1 = 0, cnt2 = 0;
                    int w = too.getKey();
                    if (prev_val + 1 == too.getKey()) {
                        cnt1 = was_cnt1;
                        cnt2 = was_cnt2;
                        w = prev_w;
                        if (s.charAt(prev_val) == '0') cnt1--;
                        else cnt2--;
                    }
                    while (w < s.length() && cnt1 < sz1 && cnt2 < sz2) {
                        if (s.charAt(w) == '0') cnt1++;
                        else cnt2++;
                        w++;
                    }
                    if (cnt1 < sz1 && cnt2 < sz2) continue;
                    prev_val = too.getKey();
                    prev_w = w;
                    was_cnt1 = cnt1;
                    was_cnt2 = cnt2;
                    if (cnt1 == sz1) {
                        if (s.charAt(too.getKey()) != '0') continue;
                    } else {
                        if (s.charAt(too.getKey()) != '1') continue;
                    }
                    if (i + 1 == a.size()) y = Math.max(y, w);
                    dp.get(i + 1).put(w, true);
                    while (w < s.length()) {
                        if (s.charAt(w) == '0') {
                            if (cnt1 + 1 < sz1) cnt1++;
                            else break;
                        } else {
                            if (cnt2 + 1 < sz2) cnt2++;
                            else break;
                        }
                        w++;
                        dp.get(i + 1).put(w, true);
                        if (i + 1 == a.size()) y = Math.max(y, w);
                    }
                }
            }
            return y;
        }

        boolean check_ans1(int n) {
            a.clear();
            ms(0, n - 1);
            Collections.reverse(a);
            int[] ans = new int[n];
            int now = 0;

            boolean does_zero(int ff) {
                int cur = 1;
                int cnt1 = 0, cnt2 = 0;
                Pair<Pair<Integer, Integer>, Pair<Integer, Integer>> to = a.get(0);
                int sz1 = to.first.second - to.first.first + 1;
                int sz2 = to.second.second - to.second.first + 1;
                cnt1 = 0;
                cnt2 = 0;
                now = ff;

                for (int i = now - 1; i >= 0; i--) {
                    char u = s.charAt(i);
                    if (u == '0') ans[cnt1++] = cur++;
                    else ans[sz1 + cnt2] = cur++, cnt2++;
                }
                while (cnt1 < sz1) ans[cnt1++] = cur++;
                while (cnt2 < sz2) ans[sz1 + cnt2] = cur++, cnt2++;
                return true;
            }

            boolean does(int delta, int _) {
                Pair<Pair<Integer, Integer>, Pair<Integer, Integer>> to = a.get(_);
                int cnt1 = 0, cnt2 = 0;
                int sz1 = to.first.second - to.first.first + 1;
                int sz2 = to.second.second - to.second.first + 1;
                int was = now;
                List<Integer> fir = new ArrayList<>(Collections.nCopies(sz1, 0));
                List<Integer> sec = new ArrayList<>(Collections.nCopies(sz2, 0));
                cnt1 = 0;
                cnt2 = 0;
                int f = to.first.first;
                now += delta;

                for (int i = now - 1; i >= was; i--) {
                    if (s.charAt(i) == '0') fir.set(cnt1++, ans[f++]);
                    else sec.set(cnt2++, ans[f++]);
                }
                assert cnt1 == sz1 || cnt2 == sz2;
                assert cnt1 < sz1 || cnt2 < sz2;
                while (cnt1 < sz1) fir.set(cnt1++, ans[f++]);
                while (cnt2 < sz2) sec.set(cnt2++, ans[f++]);
                for (int i = to.first.first, j = 0; i <= to.first.second; i++, j++) ans[i] = fir.get(j);
                for (int i = to.second.first, j = 0; i <= to.second.second; i++, j++) ans[i] = sec.get(j);
                return true;
            }

            List<Map<Integer, Boolean>> dp = new ArrayList<>(Collections.nCopies(a.size() + 1, new HashMap<>()));
            dp.get(0).put(0, true);
            for (int i = 0; i < a.size(); i++) {
                if (dp.get(i).isEmpty()) break;
                Pair<Pair<Integer, Integer>, Pair<Integer, Integer>> to = a.get(i);
                for (Map.Entry<Integer, Boolean> too : dp.get(i).entrySet()) {
                    int cnt1 = 0, cnt2 = 0;
                    int sz1 = to.first.second - to.first.first + 1;
                    int sz2 = to.second.second - to.second.first + 1;
                    int w = too.getKey();
                    while (w < s.length() && cnt1 < sz1 && cnt2 < sz2) {
                        if (s.charAt(w) == '0') cnt1++;
                        else cnt2++;
                        w++;
                    }
                    if (cnt1 < sz1 && cnt2 < sz2) continue;
                    if (cnt1 == sz1) {
                        if (s.charAt(too.getKey()) != '0') continue;
                    } else {
                        if (s.charAt(too.getKey()) != '1') continue;
                    }
                    dp.get(i + 1).put(w, true);
                    while (w < s.length()) {
                        if (s.charAt(w) == '0') {
                            if (cnt1 + 1 < sz1) cnt1++;
                            else break;
                        } else {
                            if (cnt2 + 1 < sz2) cnt2++;
                            else break;
                        }
                        w++;
                        dp.get(i + 1).put(w, true);
                    }
                }
            }
            return !dp.get(a.size()).isEmpty();
        }

        int now;
        int l = 1, r = (int) 1e5;
        while (l <= r) {
            int mid = ((l + r) >> 1);
            int w = check_ans2(mid);
            if (w < s.length()) l = mid + 1;
            else r = mid - 1, now = mid;
        }
        while (true) {
            if (check_ans1(now++)) return;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int _t = 1;

        while (_t-- > 0) solve();
    }

    static class Pair<A, B> {
        public final A first;
        public final B second;

        public Pair(A first, B second) {
            this.first = first;
            this.second = second;
        }
    }
}
