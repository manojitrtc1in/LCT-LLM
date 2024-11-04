import java.util.*;

class Main {
    static final int maxn = 100100;
    static final int mod = 998244353;
    static int n;
    static Pair<Long, Pair<Long, Long>>[] orig;
    static List<Info>[][] all_info;
    static List<Info>[] temp_info;
    static int all_size = 0;

    static class Pair<T, U> {
        T first;
        U second;

        Pair(T first, U second) {
            this.first = first;
            this.second = second;
        }
    }

    static class Info implements Comparable<Info> {
        Pair<Long, Long> time;
        long p;

        Info(Pair<Long, Long> time, long p) {
            this.time = time;
            this.p = p;
        }

        @Override
        public int compareTo(Info other) {
            return Long.compare(this.time.first * other.time.second, this.time.second * other.time.first);
        }
    }

    static List<Info> merge(List<Info> a, List<Info> b) {
        List<Info> ans = new ArrayList<>();
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a.get(i).compareTo(b.get(j)) == 0) {
                ans.add(new Info(a.get(i).time, (a.get(i).p + b.get(j).p) % mod));
                i++;
                j++;
            } else if (a.get(i).compareTo(b.get(j)) > 0) {
                if (a.get(i).p != 0) {
                    ans.add(a.get(i));
                }
                i++;
            } else {
                if (b.get(j).p != 0) {
                    ans.add(b.get(j));
                }
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
        for (int i = 0, j = 0; i < a.size(); i++) {
            long sum = 0;
            while (j < b.size() && b.get(j).compareTo(a.get(i)) >= 0) {
                sum = (sum + b.get(j).p) % mod;
                j++;
            }
            ra.get(i).p = (ra.get(i).p * sum) % mod;
        }
        for (int i = 0, j = 0; j < b.size(); j++) {
            long sum = 0;
            while (i < a.size() && a.get(i).compareTo(b.get(j)) > 0) {
                sum = (sum + a.get(i).p) % mod;
                i++;
            }
            rb.get(j).p = (rb.get(j).p * sum) % mod;
        }
        return merge(ra, rb);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        orig = new Pair[n];
        all_info = new ArrayList[n - 1][4];
        temp_info = new ArrayList[4];
        for (int i = 0; i < n; i++) {
            long first = sc.nextLong();
            long secondFirst = sc.nextLong();
            long secondSecond = sc.nextLong();
            secondSecond = (secondSecond * pow(100, mod - 2, mod)) % mod;
            orig[i] = new Pair<>(first, new Pair<>(secondFirst, secondSecond));
        }

        for (int l = 0; l < n - 1; l++) {
            for (int cate = 0; cate < 4; cate++) {
                int r = l + 1;
                long p = 1;
                long dv = 0;
                p *= (cate & 1) != 0 ? orig[l].second.second : mod + 1 - orig[l].second.second;
                dv += (cate & 1) != 0 ? orig[l].second.first : -orig[l].second.first;
                p *= (cate & 2) != 0 ? orig[r].second.second : mod + 1 - orig[r].second.second;
                dv += (cate & 2) != 0 ? -orig[r].second.first : orig[r].second.first;
                dv = Math.max(0, dv);
                p %= mod;
                all_info[l][cate] = new ArrayList<>();
                all_info[l][cate].add(new Info(new Pair<>(orig[r].first - orig[l].first, dv), p));
                all_size++;
            }
        }
        for (int i = 0; (1 << i) < (n - 1); i++) {
            for (int j = 0; j * (1 << (i + 1)) < n - 1; j++) {
                int no_a = j * (1 << (i + 1));
                int no_b = no_a + (1 << i);
                if (no_b >= n - 1) {
                    continue;
                }
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
                for (int k = 0; k < 4; k++) {
                    all_info[no_a][k] = new ArrayList<>(temp_info[k]);
                }
            }
        }

        long ans = 0;
        for (int cate = 0; cate < 4; cate++) {
            for (Info it : all_info[0][cate]) {
                if (it.time.second != 0) {
                    ans = (ans + it.p * it.time.first % mod * pow(it.time.second, mod - 2, mod)) % mod;
                }
            }
        }
        System.out.println(ans);
    }

    static long pow(long n, long m, long mod) {
        if (m < 0) {
            return 0;
        }
        long ans = 1;
        long k = n;
        while (m != 0) {
            if ((m & 1) != 0) {
                ans = (ans * k) % mod;
            }
            k = (k * k) % mod;
            m >>= 1;
        }
        return ans;
    }
}
