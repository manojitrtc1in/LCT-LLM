import java.util.*;

class Main {
    static long INF = Long.MAX_VALUE;
    static long MOD1 = 1000000007;
    static long[] factors[] = new long[2];
    static long fac_cnt = 0, id27 = 0;

    static void swap(long[] a, long[] b) {
        long c = b[0];
        b[0] = a[0];
        a[0] = c;
    }

    static void cin(long[] n) {
        Scanner sc = new Scanner(System.in);
        n[0] = sc.nextLong();
    }

    static void id28(long[] a, long n) {
        for (int i = 0; i < n; i++) {
            System.out.print(a[i]);
            if (i != n - 1) System.out.print(" ");
        }
        System.out.println();
    }

    static long min(long a, long b) {
        return a < b ? a : b;
    }

    static long max(long a, long b) {
        return a < b ? b : a;
    }

    static long min3(long a, long b, long c) {
        return (a <= b && a <= c) ? a : (b <= c ? b : c);
    }

    static long max3(long a, long b, long c) {
        return (a >= b && a >= c) ? a : (b >= c ? b : c);
    }

    static long minn(long n, long[] a) {
        long b = INF;
        for (int i = 0; i < n; i++) {
            b = min(b, a[i]);
        }
        return b;
    }

    static long maxn(long n, long[] a) {
        long b = -INF;
        for (int i = 0; i < n; i++) {
            b = max(b, a[i]);
        }
        return b;
    }

    static long POW(long a, long b) {
        long c = 1;
        for (int i = 0; i < b; i++) {
            c *= a;
        }
        return c;
    }

    static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    static long lcm(long a, long b) {
        return a / gcd(a, b) * b;
    }

    static long id34(long n) {
        n += n < 0 ? ((-n) / MOD1 + 1) * MOD1 : 0;
        return n %= MOD1;
    }

    static long mod_p(long n, long p) {
        n += n < 0 ? ((-n) / p + 1) * p : 0;
        return n %= p;
    }

    static long id31(char[] s, long len, long p) {
        return p == 0 ? 0 : POW(10, p - 1) * (s[(int) (len - p)] - '0') + id31(s, len, p - 1);
    }

    static long digits(long a, long b) {
        return a / b == 0 ? 1 : 1 + digits(a / b, b);
    }

    static long base(long n, long a, long i) {
        return i == 1 ? n % a : base(n / a, a, i - 1);
    }

    static long id16(long x, long n) {
        return (x < 0 || x >= n) ? 0 : 1;
    }

    static long id2(long y, long x, long h, long w) {
        return (y < 0 || y >= h || x < 0 || x >= w) ? 0 : 1;
    }

    static void lr_lower(int[] l, int[] r, long am, long val, int type) {
        if (type < 3) {
            if (am < val) l[0] = (l[0] + r[0]) / 2;
            else r[0] = (l[0] + r[0]) / 2;
        } else {
            if (am <= val) l[0] = (l[0] + r[0]) / 2;
            else r[0] = (l[0] + r[0]) / 2;
        }
    }

    static void lr_upper(int[] l, int[] r, long am, long val, int type) {
        if (type < 3) {
            if (am <= val) l[0] = (l[0] + r[0]) / 2;
            else r[0] = (l[0] + r[0]) / 2;
        } else {
            if (am < val) l[0] = (l[0] + r[0]) / 2;
            else r[0] = (l[0] + r[0]) / 2;
        }
    }

    static int cmp_lower(long a, long b, int type) {
        return (type == 1) ? (a == b ? 1 : 0) : (type == 2) ? (a >= b ? 1 : 0) : (a > b ? 1 : 0);
    }

    static int cmp_upper(long a, long b, int type) {
        return (type == 1) ? (a == b ? 1 : 0) : (type == 2) ? (a <= b ? 1 : 0) : (a < b ? 1 : 0);
    }

    static long lower_bound(long[] a, int l, int r, long val, int type) {
        while (r - l > 1) lr_lower(new int[]{l}, new int[]{r}, a[(l + r) / 2], val, type);
        return cmp_lower(a[l], val, type) != 0 ? l : (cmp_lower(a[r], val, type) != 0 ? r : -1);
    }

    static long upper_bound(long[] a, int l, int r, long val, int type) {
        while (r - l > 1) lr_upper(new int[]{l}, new int[]{r}, a[(l + r) / 2], val, type);
        return cmp_upper(a[r], val, type) != 0 ? r : (cmp_upper(a[l], val, type) != 0 ? l : -1);
    }

    static long count(long[] a, int l, int r, long x) {
        int p = (int) lower_bound(a, l, r, x, 1);
        return p == -1 ? 0 : upper_bound(a, p, r, x, 1) - p + 1;
    }

    static long factor_pre() {
        for (int i = 0; i < 1; i++) {
            if (id27++ > 0) return 0;
        }
        long tmp = (long) (1e6) / 2 + 1;
        long[] fac_tmp = new long[(int) tmp];
        for (int i = 0; i < tmp; i++) {
            fac_tmp[i] = i != 0 ? 2 * i + 1 : 2;
        }
        for (int i = 1; i < tmp; i++) {
            if (fac_tmp[i] != 0) {
                for (int j = 3; j < tmp / (2 * i + 1) + 1; j += 2) {
                    if (j * (2 * i + 1) < tmp) fac_tmp[(j * (2 * i + 1) - 1) / 2] = 0;
                }
            }
        }
        for (int i = 0; i < tmp; i++) {
            if (fac_tmp[i] != 0) {
                for (int j = 0; j < 2; j++) {
                    factors[j] = Arrays.copyOf(factors[j], (int) (fac_cnt + 1));
                    factors[j][j != 0 ? (int) fac_cnt++ : (int) fac_cnt] = j != 0 ? 0 : fac_tmp[i];
                }
            }
        }
        return 0;
    }

    static long factor(long n, long id29) {
        factor_pre();
        for (int i = 0; i < fac_cnt; i++) {
            long cnt = 0;
            for (int j = 0; j < 1; j++) {
                while ((cnt += n % factors[0][i] == 0 ? 1 : 0) != 0 && (n /= factors[0][i]) % factors[0][i] == 0) continue;
            }
            factors[1][i] = id29 == 1 ? cnt : id29 == 2 ? max(factors[1][i], cnt) : factors[1][i] + cnt;
            if (factors[0][i] > n) break;
        }
        return n;
    }

    static long judge_prime(long n) {
        factor_pre();
        for (int i = 0; i < fac_cnt; i++) {
            if (n < factors[0][i] * factors[0][i] || n == factors[0][i]) break;
            else if (n % factors[0][i] == 0) n /= n;
        }
        return n == 1 ? 0 : 1;
    }

    static long[] mf_arr, inv_arr, id33;
    static long id10 = 0, id3 = 0, id8 = 3 * (long) 1e5 + 10;

    static void makeinv(long n, long mod) {
        if (id10++ > 0) return;
        inv_arr = new long[(int) (n + 1)];
        id33 = new long[(int) (n + 1)];
        inv_arr[1] = id33[0] = id33[1] = 1;
        for (int i = 2; i <= n + 1; i++) {
            inv_arr[i] = mod - inv_arr[(int) (mod % i)] * (mod / i) % mod;
            id33[i] = id33[i - 1] * inv_arr[i] % mod;
        }
    }

    static void id30(long n, long mod) {
        if (id3++ > 0) return;
        mf_arr = new long[(int) (n + 1)];
        long x = mf_arr[0] = mf_arr[1] = 1;
        for (int i = 2; i <= n + 1; i++) {
            x = x * i % mod;
            mf_arr[i] = x;
        }
    }

    static long m_inv(long x, long mod, long is_fac) {
        makeinv(id8, mod);
        return is_fac != 0 ? id33[(int) x] : inv_arr[(int) x];
    }

    static long m_f(long x, long mod) {
        id30(id8, mod);
        return mf_arr[(int) x];
    }

    static long id20(long n, long k, long mod) {
        return m_f(n, mod) * m_inv(k, mod, 1) % mod * m_inv(n - k, mod, 1) % mod;
    }

    static long m_p(long r, long n, long mod) {
        long t = 1, s = r;
        while (n > 0) {
            t = (n & 1) != 0 ? t * s % mod : t;
            s = s * s % mod;
            n >>= 1;
        }
        return r != 0 ? t : 0;
    }

    static int upll(Object a, Object b) {
        return (Long) a < (Long) b ? -1 : (Long) a > (Long) b ? 1 : 0;
    }

    static int downll(Object a, Object b) {
        return (Long) a < (Long) b ? 1 : (Long) a > (Long) b ? -1 : 0;
    }

    static int cmp_string(Object a, Object b) {
        return ((String) a).compareTo((String) b);
    }

    static int cmp_char(Object a, Object b) {
        return (char) a - (char) b;
    }

    static void sortup(long[] a, int n) {
        Arrays.sort(a, 0, n);
    }

    static void sortdown(long[] a, int n) {
        Arrays.sort(a, 0, n);
        for (int i = 0; i < n / 2; i++) {
            long temp = a[i];
            a[i] = a[n - 1 - i];
            a[n - 1 - i] = temp;
        }
    }

    static long compare(long a, long b) {
        return a < b ? -1 : a > b ? 1 : 0;
    }

    static class fr {
        long a, b;
    }

    static int cmp1(Object p, Object q) {
        long pa = ((fr) p).a;
        long qa = ((fr) q).a;
        return (int) compare(pa, qa);
    }

    static int cmp2(Object p, Object q) {
        long pa = ((fr) p).a;
        long qa = ((fr) q).a;
        return (int) compare(qa, pa);
    }

    static void id41(fr[] a, int n) {
        Arrays.sort(a, 0, n, Main::cmp1);
    }

    static void id5(fr[] a, int n) {
        Arrays.sort(a, 0, n, Main::cmp2);
    }

    static void sort_partial(long[] a, int begin, int end, int id19) {
        long[] b = new long[end - begin];
        System.arraycopy(a, begin, b, 0, end - begin);
        if (id19 != 0) sortup(b, end - begin);
        else sortdown(b, end - begin);
        System.arraycopy(b, 0, a, begin, end - begin);
    }

    static class AVL_set {
        long val;
        int diff;
        int cnt;
        AVL_set[] child = new AVL_set[2];
    }

    static void id32(AVL_set[] node, int is_right) {
        int l = is_right == 0 ? 0 : 1;
        int r = is_right == 1 ? 1 : 0;
        int sign = is_right == 1 ? 1 : -1;
        if (node[0].child[l] != null) {
            AVL_set left = node[0].child[l];
            int a = node[0].diff * sign;
            int b = left.diff * sign;
            int na, nb;
            if (b + 1 != 0) {
                na = a - 1 - b;
                nb = (a - b) != 0 ? b - 1 : a - 2;
            } else {
                na = a - 1;
                nb = a != 0 ? b - 1 : a + b - 2;
            }
            node[0].diff = na * sign;
            left.diff = nb * sign;

            node[0].child[l] = node[0].child[l].child[r];
            left.child[r] = node[0];
            node[0] = left;
        }
    }

    static int id13(AVL_set[] node, long data, int add) {
        if (node[0] == null) {
            if (add == 2) {
                node[0] = new AVL_set();
                node[0].val = data;
                node[0].cnt = 1;
                node[0].diff = 0;
                node[0].child[0] = null;
                node[0].child[1] = null;
            }
            return add == 2 ? (node[0] != null ? 1 : 0) : 0;
        } else {
            int l, delta, delta_sign;
            AVL_set next_node;
            if (data == node[0].val) {
                if (add == 2) {
                    node[0].cnt++;
                    return 0;
                } else {
                    if (add != 0 && node[0].cnt > 1) {
                        node[0].cnt--;
                        return 0;
                    } else {
                        if (node[0].child[1] == null) {
                            next_node = node[0].child[0];
                            node[0] = next_node;
                            return -1;
                        } else if (node[0].child[0] == null) {
                            next_node = node[0].child[1];
                            node[0] = next_node;
                            return -1;
                        } else {
                            for (next_node = node[0].child[0]; next_node.child[1] != null; next_node = next_node.child[1]) ;
                            node[0].val = next_node.val;
                            l = 0;
                            delta_sign = 1;
                            delta = id13(new AVL_set[]{node[0].child[l]}, next_node.val, add);
                        }
                    }
                }
            } else {
                l = data >= node[0].val ? 1 : 0;
                delta_sign = data < node[0].val ? 1 : -1;
                delta = id13(new AVL_set[]{node[0].child[l]}, data, add);
            }
            if (delta != 0) {
                int orig_diff = node[0].diff;
                int do_rotate = 0, rotate_l, diff_sign, rotate_right;
                node[0].diff += delta * delta_sign;
                if (node[0].diff > 1) {
                    do_rotate = 1;
                    rotate_l = 0;
                    diff_sign = 1;
                    rotate_right = 1;
                } else if (node[0].diff < -1) {
                    do_rotate = 1;
                    rotate_l = 1;
                    diff_sign = -1;
                    rotate_right = 0;
                }
                if (do_rotate != 0) {
                    int child_diff = node[0].child[rotate_l].diff;
                    if (node[0].child[rotate_l].diff * diff_sign < 0) {
                        id32(new AVL_set[]{node[0].child[rotate_l]}, rotate_right == 1 ? 1 : 0);
                    }
                    id32(node, rotate_right);
                    return delta < 0 && child_diff != 0 ? -1 : 0;
                }
                if (delta > 0 && orig_diff == 0) return 1;
                else if (delta < 0 && orig_diff != 0) return -1;
                else return 0;
            } else {
                return 0;
            }
        }
    }

    static void id18(AVL_set node, int depth) {
        if (node == null) return;
        id18(node.child[1], depth + 1);
        System.out.println(node.val + " " + node.cnt);
        id18(node.child[0], depth + 1);
    }

    static void id7(AVL_set node) {
        if (node == null) return;
        id7(node.child[0]);
        id7(node.child[1]);
        node = null;
    }

    static long id9(AVL_set root, long val) {
        AVL_set node = root;
        while (node != null) {
            if (val < node.val) node = node.child[0];
            else if (val > node.val) node = node.child[1];
            else return node.cnt;
        }
        return 0;
    }

    static int id24(long node, long val, int type) {
        if (node == val) {
            if (type != 3) return 0;
            else return 1;
        }
        if (node < val) return 1;
        if (node > val) return -1;
        return 0;
    }

    static AVL_set id39(AVL_set root, long val, int type) {
        AVL_set node = root;
        while (node != null) {
            int com = id24(node.val, val, type);
            if (com == 0) return node;
            if (com == 1) node = node.child[1];
            if (com == -1) {
                AVL_set small = id39(node.child[0], val, type);
                if (type == 1) {
                    return small;
                } else {
                    if (small != null) return small;
                    else return node;
                }
            }
        }
        return node;
    }

    static int id42(long node, long val, int type) {
        if (node == val) {
            if (type != 3) return 0;
            else return -1;
        }
        if (node < val) return 1;
        if (node > val) return -1;
        return 0;
    }

    static AVL_set id4(AVL_set root, long val, int type) {
        AVL_set node = root;
        while (node != null) {
            int com = id42(node.val, val, type);
            if (com == 0) return node;
            if (com == -1) node = node.child[0];
            if (com == 1) {
                AVL_set big = id4(node.child[1], val, type);
                if (type == 1) {
                    return big;
                } else {
                    if (big != null) return big;
                    else return node;
                }
            }
        }
        return node;
    }

    static long id15(AVL_set root, int type) {
        while (root.child[type] != null) root = root.child[type];
        return root.val;
    }

    static void id14(AVL_set[] node1, AVL_set[] node2) {
        AVL_set tmp = node1[0];
        node1[0] = node2[0];
        node2[0] = tmp;
    }

    static long set_main(int command, int set_num, long val, long option) {
        static boolean id12 = false;
        static AVL_set[] set_pointer = new AVL_set[100];
        static long[] id1 = new long[100];
        if (!id12) {
            id12 = true;
            for (int i = 0; i < 100; i++) {
                set_pointer[i] = null;
                id1[i] = 0;
            }
        }
        if (command == -1) {
            id18(set_pointer[set_num], 0);
        }
        if (command == 1) {
            id9(set_pointer[set_num], val) != 0 ? 1 : id1[set_num]++;
            id13(new AVL_set[]{set_pointer[set_num]}, val, 2);
        }
        if (command == 2) {
            return id9(set_pointer[set_num], val);
        }
        if (command == 3) {
            (id9(set_pointer[set_num], val) > 1) ? 1 : id1[set_num]--;
            id13(new AVL_set[]{set_pointer[set_num]}, val, 1);
        }
        if (command == 4) {
            id1[set_num]--;
            id13(new AVL_set[]{set_pointer[set_num]}, val, 0);
        }
        if (command == 5) {
            id1[set_num] = 0;
            id7(set_pointer[set_num]);
            set_pointer[set_num] = null;
        }
        if (command == 6) {
            return id1[set_num];
        }
        if (command == 7) {
            return id15(set_pointer[set_num], 1);
        }
        if (command == 8) {
            return id15(set_pointer[set_num], 0);
        }
        if (command == 9) {
            id14(new AVL_set[]{set_pointer[set_num]}, new AVL_set[]{set_pointer[(int) val]});
        }
        if (10 <= command && command <= 12) {
            AVL_set lowbound = id39(set_pointer[set_num], val, command - 9);
            if (lowbound == null) return option;
            else return lowbound.val;
        }
        if (13 <= command && command <= 15) {
            AVL_set upbound = id4(set_pointer[set_num], val, command - 12);
            if (upbound == null) return option;
            else return upbound.val;
        }
        return 0;
    }

    static void set_print(int set_num) {
        set_main(-1, set_num, 0, 0);
    }

    static void set_insert(int set_num, long val) {
        set_main(1, set_num, val, 0);
    }

    static long set_count(int set_num, long val) {
        return set_main(2, set_num, val, 0);
    }

    static void id17(int set_num, long val, int is_all) {
        if (is_all) set_main(4, set_num, val, 0);
        else set_main(3, set_num, val, 0);
    }

    static void set_clear(int set_num) {
        set_main(5, set_num, 0, 0);
    }

    static long set_size(int set_num) {
        return set_main(6, set_num, 0, 0);
    }

    static long set_max(int set_num) {
        return set_main(7, set_num, 0, 0);
    }

    static long set_min(int set_num) {
        return set_main(8, set_num, 0, 0);
    }

    static void set_swap(int id26, int id21) {
        set_main(9, id26, id21, 0);
    }

    static long id11(int set_num, long val, int type, long error) {
        return set_main(9 + type, set_num, val, error);
    }

    static long id35(int set_num, long val, int type, long error) {
        return set_main(12 + type, set_num, val, error);
    }

    static class vector {
        int n, max, data_size;
        Object data;
        void push(vector v, Object x) {
            if (v.n == v.max) {
                v.max *= 2;
                v.data = Arrays.copyOf((Object[]) v.data, v.max * v.data_size);
            }
            if (x == null) {
                Arrays.fill((Object[]) v.data, v.data_size * v.n, v.data_size * (v.n + 1), 0);
            } else {
                System.arraycopy(x, 0, (Object[]) v.data, v.data_size * v.n, v.data_size);
            }
            v.n++;
        }

        void set(vector v, int idx, Object x) {
            if (x == null) {
                Arrays.fill((Object[]) v.data, v.data_size * idx, v.data_size * (idx + 1), 0);
            } else {
                System.arraycopy(x, 0, (Object[]) v.data, v.data_size * idx, v.data_size);
            }
        }

        Object id25(vector v, int idx) {
            return (Object) ((Object[]) v.data)[v.data_size * idx];
        }

        long get(vector v, int idx) {
            long ret = 0;
            if (v.data_size == 8) ret = (long) id25(v, idx);
            if (v.data_size == 4) ret = (int) id25(v, idx);
            if (v.data_size == 2) ret = (boolean) id25(v, idx) ? 1 : 0;
            return ret;
        }

        double id22(vector v, int idx) {
            return (double) id25(v, idx);
        }

        int size(vector v) {
            return v.n;
        }

        vector vector_init(int n, int data_size) {
            if (n == 0) throw new IllegalArgumentException();
            vector ret = new vector();
            ret.n = 0;
            ret.max = n;
            ret.data_size = data_size;
            ret.data = new Object[n * data_size];

            ret.push = this::push;
            ret.set = this::set;
            ret.size = this::size;
            ret.get = this::get;
            ret.get_double = this::id22;

            Arrays.fill((Object[]) ret.data, 0, n * ret.data_size, 0);
            return ret;
        }
    }

    static class Dinic {
        int n;
        vector[] to;
        vector[] cap;
        vector[] rev;
        vector min_cost;
        vector iter;
        void add(Dinic d, int from, int to, long cap) {
            d.rev[from].push(d.rev[from], (Object) d.to[to].n);
            d.rev[to].push(d.rev[to], (Object) d.to[from].n);
            d.to[from].push(d.to[from], (Object) to);
            d.to[to].push(d.to[to], (Object) from);
            d.cap[from].push(d.cap[from], (Object) cap);
            d.cap[to].push(d.cap[to], null);
        }

        boolean id6(Dinic d, int s, int t) {
            int init = -1;
            for (int i = 0; i < d.n; i++) d.min_cost.set(d.min_cost, i, (Object) init);
            vector q = new vector().vector_init(1, sizeof(int));
            d.min_cost.set(d.min_cost, s, null);
            int head = 0;
            q.push(q, (Object) s);
            while (head != q.n && d.min_cost.get(d.min_cost, t) == -1) {
                int p = (int) q.get(q, head);
                head++;
                for (int i = 0; i < d.to[p].n; i++) {
                    int to = (int) d.to[p].get(d.to[p], i);
                    if (d.cap[p].get(d.cap[p], i) > 0 && d.min_cost.get(d.min_cost, to) == -1) {
                        long cost = d.min_cost.get(d.min_cost, p) + 1;
                        d.min_cost.set(d.min_cost, to, (Object) cost);
                        q.push(q, (Object) to);
                    }
                }
            }
            return d.min_cost.get(d.min_cost, t) != -1;
        }

        long id0(Dinic d, int idx, int t, long flow) {
            if (idx == t) return flow;
            for (int i = (int) d.iter.get(d.iter, idx); i < d.cap[idx].n; i++) {
                d.iter.set(d.iter, idx, (Object) i);
                long cap = d.cap[idx].get(d.cap[idx], i);
                int to = (int) d.to[idx].get(d.to[idx], i);
                if (cap > 0 && d.min_cost.get(d.min_cost, idx) < d.min_cost.get(d.min_cost, to)) {
                    long delta = id0(d, to, t, Math.min(flow, cap));
                    if (delta > 0) {
                        cap -= delta;
                        d.cap[idx].set(d.cap[idx], i, (Object) cap);
                        int rev = (int) d.rev[idx].get(d.rev[idx], i);
                        long rev_cap = d.cap[to].get(d.cap[to], rev) + delta;
                        d.cap[to].set(d.cap[to], rev, (Object) rev_cap);
                        return delta;
                    }
                }
            }
            return 0;
        }

        long id36(Dinic d, int s, int t) {
            long flow = 0;
            while (id6(d, s, t)) {
                for (int i = 0; i < d.n; i++) d.iter.set(d.iter, i, null);
                long f = 0;
                while ((f = id0(d, s, t, INF)) > 0) flow += f;
            }
            return flow;
        }

        Dinic id38(int n) {
            Dinic ret = new Dinic();
            ret.n = n;
            ret.to = new vector[n];
            ret.cap = new vector[n];
            ret.rev = new vector[n];
            for (int i = 0; i < n; i++) {
                ret.to[i] = new vector().vector_init(1, sizeof(int));
                ret.cap[i] = new vector().vector_init(1, sizeof(long));
                ret.rev[i] = new vector().vector_init(1, sizeof(int));
            }
            ret.min_cost = new vector().vector_init(n, sizeof(int));
            ret.iter = new vector().vector_init(n, sizeof(int));
            ret.add = this::add;
            ret.max_flow = this::id36;
            return ret;
        }
    }

    static char[] s = new char[1151154];

    static void solve() {
        long n;
        long ans = 0;
        long[] nArr = new long[1];
        cin(nArr);
        n = nArr[0];

        long[] a = new long[3];
        long[] b = new long[3];
        for (int i = 0; i < 3; i++) {
            cin(new long[]{a[i]});
        }
        for (int i = 0; i < 3; i++) {
            cin(new long[]{b[i]});
        }
        long ma = 0;

        ma = min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[0]);
        Dinic d = id38(8);
        d.add(d, 6, 0, a[0]);
        d.add(d, 6, 1, a[1]);
        d.add(d, 6, 2, a[2]);

        d.add(d, 0, 3, INF);
        d.add(d, 0, 5, INF);
        d.add(d, 1, 3, INF);
        d.add(d, 1, 4, INF);
        d.add(d, 2, 4, INF);
        d.add(d, 2, 5, INF);

        d.add(d, 3, 7, b[0]);
        d.add(d, 4, 7, b[1]);
        d.add(d, 5, 7, b[2]);
        System.out.printf("%d %d\n", n - d.max_flow(d, 6, 7), ma);
    }

    public static void main(String[] args) {
        long T = 1;
        for (int i = 0; i < T; i++) {
            solve();
        }
    }
}
