import java.util.*;
import java.io.*;

public class 4418eb8ac9d0234e17ff1694fffa2258_nc {
    static final int MOD = 1000000007;
    static final int maxn = 100100;
    static final int mod = 998244353;
    static int n;
    static Pair<Long, Pair<Long, Long>>[] orig = new Pair[maxn];

    static class Info implements Comparable<Info> {
        Pair<Long, Long> time;
        long p;

        @Override
        public int compareTo(Info other) {
            return Long.compare(time.first * other.time.second, time.second * other.time.first);
        }

        @Override
        public boolean equals(Object obj) {
            if (this == obj) return true;
            if (!(obj instanceof Info)) return false;
            Info other = (Info) obj;
            return time.first * other.time.second == time.second * other.time.first;
        }
    }

    static List<Info> merge(List<Info> a, List<Info> b) {
        List<Info> ans = new ArrayList<>();
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a.get(i).equals(b.get(j))) {
                ans.add(new Info() {{
                    time = a.get(i).time;
                    p = (a.get(i).p + b.get(j).p) % mod;
                }});
                i++;
                j++;
            } else if (a.get(i).compareTo(b.get(j)) > 0) {
                if (a.get(i).p != 0) ans.add(a.get(i));
                i++;
            } else {
                if (b.get(j).p != 0) ans.add(b.get(j));
                j++;
            }
        }
        while (i < a.size()) {
            ans.add(a.get(i));
            i++;
        }
        while (j < b.size()) {
            ans.add(b.get(j));
            j++;
        }
        return ans;
    }

    static List<Info> mergeDp(List<Info> a, List<Info> b) {
        List<Info> ra = new ArrayList<>(a);
        List<Info> rb = new ArrayList<>(b);
        for (int i = 0, j = 0, sum = 0; i < a.size(); i++) {
            while (j < b.size() && b.get(j).compareTo(a.get(i)) >= 0) {
                sum = (int) ((sum + b.get(j).p) % mod);
                j++;
            }
            ra.get(i).p = (ra.get(i).p * sum) % mod;
        }
        for (int i = 0, j = 0, sum = 0; j < b.size(); j++) {
            while (i < a.size() && a.get(i).compareTo(b.get(j)) > 0) {
                sum = (int) ((sum + a.get(i).p) % mod);
                i++;
            }
            rb.get(j).p = (rb.get(j).p * sum) % mod;
        }
        return merge(ra, rb);
    }

    static List<Info>[] all_info = new ArrayList[maxn];
    static List<Info>[] temp_info = new ArrayList[4];

    static {
        for (int i = 0; i < maxn; i++) {
            all_info[i] = new ArrayList[4];
            for (int j = 0; j < 4; j++) {
                all_info[i][j] = new ArrayList<>();
            }
        }
        for (int i = 0; i < 4; i++) {
            temp_info[i] = new ArrayList<>();
        }
    }

    static long pow(long n, long m, long mod) {
        if (m < 0) return 0;
        long ans = 1;
        long k = n;
        while (m > 0) {
            if ((m & 1) == 1) {
                ans = (ans * k) % mod;
            }
            k = (k * k) % mod;
            m >>= 1;
        }
        return ans;
    }

    static void add(long[] a, long b) {
        a[0] += b;
        while (a[0] >= MOD) a[0] -= MOD;
        while (a[0] < 0) a[0] += MOD;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            long first = Long.parseLong(st.nextToken());
            long second = Long.parseLong(st.nextToken());
            long third = Long.parseLong(st.nextToken());
            orig[i] = new Pair<>(first, new Pair<>(second, (third * pow(100, mod - 2, mod)) % mod));
        }

        int all_size = 0;
        for (int l = 0; l < n - 1; l++) {
            for (int cate = 0; cate < 4; cate++) {
                int r = l + 1;
                long p = 1, dv = 0;
                p *= (cate & 1) != 0 ? orig[l].second.second : mod + 1 - orig[l].second.second;
                dv += (cate & 1) != 0 ? orig[l].second.first : -orig[l].second.first;
                p *= (cate & 2) != 0 ? orig[r].second.second : mod + 1 - orig[r].second.second;
                dv += (cate & 2) != 0 ? -orig[r].second.first : orig[r].second.first;
                dv = Math.max(0, dv);
                p %= mod;
                all_info[l][cate].add(new Info() {{
                    time = new Pair<>(orig[r].first - orig[l].first, dv);
                    p = p;
                }});
                all_size++;
            }
        }

        for (int i = 0; (1 << i) < (n - 1); i++) {
            for (int j = 0; j * (1 << (i + 1)) < n - 1; j++) {
                int no_a = j * (1 << (i + 1)), no_b = no_a + (1 << i);
                if (no_b >= n - 1) continue;
                for (int f1 = 0; f1 < 2; f1++) {
                    for (int f2 = 0; f2 < 2; f2++) {
                        List<Info> rans1 = mergeDp(all_info[no_a][f1], all_info[no_b][f2 << 1]);
                        long p1 = pow(mod + 1 - orig[no_b].second.second, mod - 2, mod);
                        for (Info it : rans1) {
                            it.p = (it.p * p1) % mod;
                        }
                        List<Info> rans2 = mergeDp(all_info[no_a][f1 + 2], all_info[no_b][(f2 << 1) + 1]);
                        long p2 = pow(orig[no_b].second.second, mod - 2, mod);
                        for (Info it : rans2) {
                            it.p = (it.p * p2) % mod;
                        }
                        temp_info[f1 + (f2 << 1)] = merge(rans1, rans2);
                    }
                }
                for (int i = 0; i < 4; i++) {
                    all_info[no_a][i] = temp_info[i];
                }
            }
        }

        long ans = 0;
        for (int cate = 0; cate < 4; cate++) {
            for (Info it : all_info[0][cate]) {
                if (it.time.second != 0) {
                    ans += it.p * it.time.first % mod * pow(it.time.second, mod - 2, mod);
                    ans %= mod;
                }
            }
        }
        System.out.println(ans);
    }
}

class Pair<K, V> {
    public K first;
    public V second;

    public Pair(K first, V second) {
        this.first = first;
        this.second = second;
    }
}
