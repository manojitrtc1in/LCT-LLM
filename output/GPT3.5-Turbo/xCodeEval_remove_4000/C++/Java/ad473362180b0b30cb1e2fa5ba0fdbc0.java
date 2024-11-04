import java.util.*;

class Main {
    static class Pair {
        int first, second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    static class Quadruple {
        Pair first, second;

        Quadruple(Pair first, Pair second) {
            this.first = first;
            this.second = second;
        }
    }

    static List<Quadruple> a;
    static int[][] pref;
    static int[] ha, haa_0, haa_1;
    static StringBuilder ss;
    static List<Integer> p;

    static boolean uin(int[] a, int b) {
        if (a[0] > b) {
            a[0] = b;
            return true;
        }
        return false;
    }

    static boolean uax(int[] a, int b) {
        if (a[0] < b) {
            a[0] = b;
            return true;
        }
        return false;
    }

    static final long INFLL = (long) 1e18;
    static final int MAXN = (int) 1e5 + 100;
    static final int MAXNN = (int) 2e4 + 100;
    static final int INF = (int) 1e9;
    static final int mod1 = (int) 1e9 + 7;
    static final int mod2 = (int) 1e9 + 21;

    static void ms(int l, int r) {
        if (r <= l)
            return;
        int mid = ((l + r + 1) >> 1) - 1;
        ms(l, mid);
        ms(mid + 1, r);
        a.add(new Quadruple(new Pair(l, mid), new Pair(mid + 1, r)));
    }

    static void mss(int l, int r) {
        if (r <= l)
            return;
        int mid = ((l + r + 1) >> 1) - 1;
        mss(l, mid);
        mss(mid + 1, r);
        int i = l, j = mid + 1;
        List<Integer> b = new ArrayList<>();

        int now = 0;
        while (i <= mid && j <= r) {
            if (p.get(i) < p.get(j)) {
                ss.append('0');
                b.add(p.get(i++));
                now++;
            } else {
                ss.append('1');
                b.add(p.get(j++));
                now++;
            }
        }
        while (i <= mid)
            b.add(p.get(i++));
        while (j <= r)
            b.add(p.get(j++));
        for (i = l, j = 0; i <= r; i++, j++)
            p.set(i, b.get(j));
    }

    static void solve() {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        StringBuilder sb = new StringBuilder(s);
        s = sb.reverse().toString();
        pref = new int[s.length() + 1][2];
        for (int i = 1; i <= s.length(); i++) {
            if (s.charAt(i - 1) == '0') {
                pref[i][0] = pref[i - 1][0] + 1;
                pref[i][1] = pref[i - 1][1];
            } else {
                pref[i][1] = pref[i - 1][1] + 1;
                pref[i][0] = pref[i - 1][0];
            }
        }
        a = new ArrayList<>();
        ms(0, s.length() - 1);
        Collections.reverse(a);
        List<Integer> ans = new ArrayList<>();
        int now = 0;
        int y = -INF;
        for (int i = 0; i < a.size(); i++) {
            Quadruple to = a.get(i);
            int sz1 = to.first.second - to.first.first + 1;
            int sz2 = to.second.second - to.second.first + 1;
            int prev_val = -123, prev_w = -1;
            int id2 = 0, id0 = 0;
            Map<Integer, Boolean> dp = new HashMap<>();
            dp.put(0, true);
            for (Map.Entry<Integer, Boolean> too : dp.entrySet()) {
                int cnt1 = 0, cnt2 = 0;
                int w = too.getKey();
                if (prev_val + 1 == too.getKey()) {
                    cnt1 = id2;
                    cnt2 = id0;
                    w = prev_w;
                    if (s.charAt(prev_val) == '0')
                        cnt1--;
                    else
                        cnt2--;
                }
                while (w < s.length() && cnt1 < sz1 && cnt2 < sz2) {
                    if (s.charAt(w) == '0')
                        cnt1++;
                    else
                        cnt2++;
                    w++;
                }
                if (cnt1 < sz1 && cnt2 < sz2)
                    continue;
                prev_val = too.getKey();
                prev_w = w;
                id2 = cnt1;
                id0 = cnt2;
                if (cnt1 == sz1) {
                    if (s.charAt(too.getKey()) != '0')
                        continue;
                } else {
                    if (s.charAt(too.getKey()) != '1')
                        continue;
                }
                if (i + 1 == a.size())
                    y = Math.max(y, w);
                dp.put(w, true);
                while (w < s.length()) {
                    if (s.charAt(w) == '0') {
                        if (cnt1 + 1 < sz1)
                            cnt1++;
                        else
                            break;
                    } else {
                        if (cnt2 + 1 < sz2)
                            cnt2++;
                        else
                            break;
                    }
                    w++;
                    dp.put(w, true);
                    if (i + 1 == a.size())
                        y = Math.max(y, w);
                }
            }
        }
        if (!dp.containsKey(s.length())) {
            System.out.println(123);
            return;
        }
        dp = new HashMap<>();
        Map<Integer, Integer> from = new HashMap<>();
        dp.put(0, true);
        for (int i = 0; i < a.size(); i++) {
            Quadruple to = a.get(i);
            for (Map.Entry<Integer, Boolean> too : dp.entrySet()) {
                int cnt1 = 0, cnt2 = 0;
                int sz1 = to.first.second - to.first.first + 1;
                int sz2 = to.second.second - to.second.first + 1;
                int w = too.getKey();
                while (w < s.length() && cnt1 < sz1 && cnt2 < sz2) {
                    if (s.charAt(w) == '0')
                        cnt1++;
                    else
                        cnt2++;
                    w++;
                }
                if (cnt1 < sz1 && cnt2 < sz2)
                    continue;
                if (cnt1 == sz1) {
                    if (s.charAt(too.getKey()) != '0')
                        continue;
                } else {
                    if (s.charAt(too.getKey()) != '1')
                        continue;
                }
                dp.put(w, true);
                from.put(w, too.getKey());
                while (w < s.length()) {
                    if (s.charAt(w) == '0') {
                        if (cnt1 + 1 < sz1)
                            cnt1++;
                        else
                            break;
                    } else {
                        if (cnt2 + 1 < sz2)
                            cnt2++;
                        else
                            break;
                    }
                    w++;
                    dp.put(w, true);
                    from.put(w, too.getKey());
                }
            }
        }
        if (!dp.containsKey(s.length())) {
            System.out.println(123);
            return;
        }
        List<Integer> x = new ArrayList<>();
        now = 0;
        int ha = s.length();
        for (int j = a.size(); j > 0; j--) {
            int f = from.get(ha);
            x.add(ha - f);
            ha = f;
        }
        Collections.reverse(x);
        does_zero(x.get(0));
        assert x.size() == a.size();
        for (int ii = 1; ii < x.size(); ii++)
            does(x.get(ii), ii);
        System.out.println(s.length());
        for (int to : ans)
            System.out.print(to + " ");
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int _t = 1;
        while (_t-- > 0)
            solve();
        System.out.println("\nTime : " + (double) (System.currentTimeMillis()) / 1000 + "\n");
    }
}
