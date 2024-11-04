import java.util.*;
import java.io.*;

class Main {
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    static class Pair<T1, T2> {
        T1 first;
        T2 second;

        public Pair(T1 first, T2 second) {
            this.first = first;
            this.second = second;
        }
    }

    static class Triple<T1, T2, T3> {
        T1 first;
        T2 second;
        T3 third;

        public Triple(T1 first, T2 second, T3 third) {
            this.first = first;
            this.second = second;
            this.third = third;
        }
    }

    static class Quadruple<T1, T2, T3, T4> {
        T1 first;
        T2 second;
        T3 third;
        T4 fourth;

        public Quadruple(T1 first, T2 second, T3 third, T4 fourth) {
            this.first = first;
            this.second = second;
            this.third = third;
            this.fourth = fourth;
        }
    }

    static class FastWriter {
        BufferedWriter bw;

        public FastWriter() {
            bw = new BufferedWriter(new OutputStreamWriter(System.out));
        }

        void print(Object object) throws IOException {
            bw.write(object.toString());
        }

        void println(Object object) throws IOException {
            print(object);
            bw.newLine();
        }

        void close() throws IOException {
            bw.close();
        }
    }

    static final int INF = (int) 1e9;
    static final int MAXN = (int) 1e5 + 100;
    static final int MAXNN = (int) 2e4 + 100;
    static final int mod1 = (int) 1e9 + 7;
    static final int mod2 = (int) 1e9 + 21;
    static final long INFLL = (long) 1e18;
    static final int MANX = MAXN;

    static List<Pair<Pair<Integer, Integer>, Pair<Integer, Integer>>> a;
    static int[][] pref;
    static int[] ha, haa_0, haa_1;
    static String ss;
    static List<Integer> p;

    static void ms(int l, int r) {
        if (r <= l)
            return;
        int mid = ((l + r + 1) >> 1) - 1;
        ms(l, mid);
        ms(mid + 1, r);
        a.add(new Pair<>(new Pair<>(l, mid), new Pair<>(mid + 1, r)));
    }

    static void mss(int l, int r) {
        if (r <= l)
            return;
        int mid = ((l + r + 1) >> 1) - 1;
        mss(l, mid);
        mss(mid + 1, r);
        int i = l, j = mid + 1;
        List<Integer> b = new ArrayList<>(r - l + 1);

        int now = 0;
        while (i <= mid && j <= r) {
            if (p.get(i) < p.get(j))
                ss += '0';
            else
                ss += '1';
            b.add(p.get(i));
            i++;
            now++;
        }
        while (i <= mid) {
            b.add(p.get(i));
            i++;
            now++;
        }
        while (j <= r) {
            b.add(p.get(j));
            j++;
            now++;
        }
        for (i = l, j = 0; i <= r; i++, j++)
            p.set(i, b.get(j));
    }

    static void solve() throws IOException {
        FastReader sc = new FastReader();
        FastWriter out = new FastWriter();
        String s = sc.next();
        s = new StringBuilder(s).reverse().toString();
        int n = s.length();
        pref = new int[n + 1][2];
        a = new ArrayList<>();
        p = new ArrayList<>();
        ss = "";
        for (int i = 0; i < n; i++)
            p.add(s.charAt(i) - '0');
        for (int i = 1; i <= n; i++) {
            if (s.charAt(i - 1) == '0') {
                pref[i][0] = pref[i - 1][0] + 1;
                pref[i][1] = pref[i - 1][1];
            } else {
                pref[i][1] = pref[i - 1][1] + 1;
                pref[i][0] = pref[i - 1][0];
            }
        }
        int now = 0;
        int l = 1, r = n;
        while (l <= r) {
            int mid = ((l + r) >> 1);
            int w = check_ans2(mid);
            if (w < n)
                l = mid + 1;
            else
                r = mid - 1;
            now = mid;
        }
        while (true) {
            if (check_ans1(now++))
                break;
        }
        out.close();
    }

    static int check_ans2(int n) {
        a.clear();
        ms(0, n - 1);
        Collections.reverse(a);
        List<Integer> ans = new ArrayList<>(n);
        int now = 0;
        int y = -INF;
        for (int i = 0; i < a.size(); i++) {
            Pair<Pair<Integer, Integer>, Pair<Integer, Integer>> to = a.get(i);
            int sz1 = to.first.second - to.first.first + 1;
            int sz2 = to.second.second - to.second.first + 1;
            int was = now;
            int cur = 1;
            int cnt1 = 0, cnt2 = 0;
            now = n;
            for (int j = now - 1; j >= 0; j--) {
                char u = ss.charAt(j);
                if (u == '0')
                    ans.add(cnt1++, cur++);
                else
                    ans.add(sz1 + cnt2++, cur++);
            }
            while (cnt1 < sz1)
                ans.add(cnt1++, cur++);
            while (cnt2 < sz2)
                ans.add(sz1 + cnt2++, cur++);
            if (i + 1 == a.size())
                y = Math.max(y, n);
        }
        return y;
    }

    static boolean check_ans1(int n) {
        a.clear();
        ms(0, n - 1);
        Collections.reverse(a);
        List<Integer> ans = new ArrayList<>(n);
        int now = 0;
        for (int i = 0; i < a.size(); i++) {
            Pair<Pair<Integer, Integer>, Pair<Integer, Integer>> to = a.get(i);
            int sz1 = to.first.second - to.first.first + 1;
            int sz2 = to.second.second - to.second.first + 1;
            int was = now;
            int cur = 1;
            int cnt1 = 0, cnt2 = 0;
            now = n;
            for (int j = now - 1; j >= 0; j--) {
                char u = ss.charAt(j);
                if (u == '0')
                    ans.add(cnt1++, cur++);
                else
                    ans.add(sz1 + cnt2++, cur++);
            }
            while (cnt1 < sz1)
                ans.add(cnt1++, cur++);
            while (cnt2 < sz2)
                ans.add(sz1 + cnt2++, cur++);
        }
        if (ans.size() != n)
            return false;
        System.out.println(n);
        for (int to : ans)
            System.out.print(to + " ");
        System.out.println();
        return true;
    }

    public static void main(String[] args) throws IOException {
        solve();
    }
}
