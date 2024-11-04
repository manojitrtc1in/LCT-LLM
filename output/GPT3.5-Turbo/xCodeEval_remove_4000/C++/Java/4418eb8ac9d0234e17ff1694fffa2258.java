import java.util.*;
import java.io.*;

class Main {
    static final int maxn = 100100;
    static final int mod = 998244353;
    static int n;
    static Pair<Long, Pair<Long, Long>>[] orig;
    static ArrayList<Info>[][] all_info;
    static ArrayList<Info>[] temp_info;
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

        public int compareTo(Info other) {
            return Long.compare(this.time.first * other.time.second, this.time.second * other.time.first);
        }
    }

    static ArrayList<Info> Merge(ArrayList<Info> a, ArrayList<Info> b) {
        ArrayList<Info> ans = new ArrayList<>();
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a.get(i).compareTo(b.get(j)) == 0) {
                ans.add(new Info(a.get(i).time, (a.get(i).p + b.get(j).p) % mod));
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

    static ArrayList<Info> MergeDp(ArrayList<Info> a, ArrayList<Info> b) {
        ArrayList<Info> ra = new ArrayList<>(a);
        ArrayList<Info> rb = new ArrayList<>(b);
        for (long i = 0, j = 0, sum = 0; i < a.size(); i++) {
            while (j < b.size() && b.get((int) j).compareTo(a.get((int) i)) >= 0) {
                sum += b.get((int) j).p;
                sum %= mod;
                j++;
            }
            ra.get((int) i).p *= sum;
            ra.get((int) i).p %= mod;
        }
        for (long i = 0, j = 0, sum = 0; j < b.size(); j++) {
            while (i < a.size() && a.get((int) i).compareTo(b.get((int) j)) > 0) {
                sum += a.get((int) i).p;
                sum %= mod;
                i++;
            }
            rb.get((int) j).p *= sum;
            rb.get((int) j).p %= mod;
        }
        return Merge(ra, rb);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        orig = new Pair[n];
        all_info = new ArrayList[n][4];
        temp_info = new ArrayList[4];
        for (int i = 0; i < n; i++) {
            String[] line = br.readLine().split(" ");
            long first = Long.parseLong(line[0]);
            long secondFirst = Long.parseLong(line[1]);
            long secondSecond = Long.parseLong(line[2]);
            secondSecond *= pow(100, mod - 2, mod);
            secondSecond %= mod;
            orig[i] = new Pair<>(first, new Pair<>(secondFirst, secondSecond));
        }

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
                all_info[l][cate] = new ArrayList<>();
                all_info[l][cate].add(new Info(new Pair<>(orig[r].first - orig[l].first, dv), p));
                all_size++;
            }
        }
        for (int i = 0; (1 << i) < (n - 1); i++) {
            for (int j = 0; j * (1 << (i + 1)) < n - 1; j++) {
                int no_a = j * (1 << (i + 1)), no_b = no_a + (1 << i);
                if (no_b >= n - 1) continue;
                for (int f1 = 0; f1 < 2; f1++) {
                    for (int f2 = 0; f2 < 2; f2++) {
                        ArrayList<Info> rans1 = MergeDp(all_info[no_a][f1], all_info[no_b][f2 << 1]);
                        long p1 = pow(mod + 1 - orig[no_b].second.second, mod - 2, mod);
                        for (Info it : rans1) {
                            it.p *= p1;
                            it.p %= mod;
                        }
                        ArrayList<Info> rans2 = MergeDp(all_info[no_a][f1 + 2], all_info[no_b][(f2 << 1) + 1]);
                        long p2 = pow(orig[no_b].second.second, mod - 2, mod);
                        for (Info it : rans2) {
                            it.p *= p2;
                            it.p %= mod;
                        }
                        temp_info[f1 + (f2 << 1)] = Merge(rans1, rans2);
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
                    ans += it.p * it.time.first % mod * pow(it.time.second, mod - 2, mod);
                    ans %= mod;
                }
            }
        }
        System.out.println(ans);
    }

    static long pow(long n, long m, long mod) {
        if (m < 0) return 0;
        long ans = 1;
        long k = n;
        while (m > 0) {
            if ((m & 1) == 1) {
                ans *= k;
                if (mod > 0) ans %= mod;
            }
            k *= k;
            if (mod > 0) k %= mod;
            m >>= 1;
        }
        return ans;
    }
}
