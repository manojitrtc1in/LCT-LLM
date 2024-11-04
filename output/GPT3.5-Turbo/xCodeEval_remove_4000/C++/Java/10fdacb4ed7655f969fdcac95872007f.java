import java.util.*;
import java.io.*;

class Main {
    static final int maxq = 5010;
    static final int maxn = 100100;

    static class segment_node<T> {
        int be, en;
        T maxv, add, sum;
    }

    static class segment_tree<T> {
        int l;
        segment_node<T>[] tree;

        segment_tree() {
            l = 0;
        }

        int gleft(int no) {
            return no << 1;
        }

        int gright(int no) {
            return (no << 1) + 1;
        }

        int gfa(int no) {
            return no >> 1;
        }

        void build(int no, int l, int r, T orig, T[] a) {
            if (l > r) r = l;
            if (l == r) {
                tree[no].be = tree[no].en = l;
                tree[no].add = 0;
                if (a == null) tree[no].maxv = orig;
                else tree[no].maxv = a[l];
                tree[no].add = 0;
                tree[no].sum = tree[no].maxv;
                return;
            }
            tree[no].be = l;
            tree[no].en = r;
            int mid = (l + r) / 2;
            build(gleft(no), l, mid, orig, a);
            build(gright(no), mid + 1, r, orig, a);
            tree[no].sum = tree[gleft(no)].sum + tree[gright(no)].sum;
            tree[no].add = 0;
            tree[no].maxv = max1(tree[gleft(no)].maxv, tree[gright(no)].maxv);
        }

        void relax(int no) {
            int le = gleft(no), ri = gright(no);
            tree[le].add += tree[no].add;
            tree[le].sum += tree[no].add * (tree[le].en - tree[le].be + 1);
            tree[le].maxv += tree[no].add;
            tree[ri].add += tree[no].add;
            tree[ri].sum += tree[no].add * (tree[ri].en - tree[ri].be + 1);
            tree[ri].maxv += tree[no].add;
            tree[no].add = 0;
        }

        void down(int l, int r, int no, T ranadd) {
            if (l <= tree[no].be && r >= tree[no].en) {
                tree[no].add += ranadd;
                tree[no].sum += ranadd * (tree[no].en - tree[no].be + 1);
                tree[no].maxv += ranadd;
                return;
            }
            if (tree[no].add != 0 && tree[no].be != tree[no].en) relax(no);
            int mid = (tree[no].be + tree[no].en) >> 1;
            if (r >= tree[no].be && l <= mid) down(l, r, gleft(no), ranadd);
            if (r >= mid + 1 && l <= tree[no].en) down(l, r, gright(no), ranadd);
            tree[no].sum = tree[gleft(no)].sum + tree[gright(no)].sum;
            tree[no].maxv = max1(tree[gleft(no)].maxv, tree[gright(no)].maxv);
        }

        T getmax(int l, int r, int no) {
            if (l > r) return 0;
            if (l <= tree[no].be && r >= tree[no].en)
                return tree[no].maxv;
            if (tree[no].add != 0 && tree[no].be != tree[no].en) relax(no);
            T ans = 0;
            int mid = (tree[no].be + tree[no].en) >> 1;
            if (r >= tree[no].be && l <= mid) ans = max1(ans, getmax(l, r, gleft(no)));
            if (r >= mid + 1 && l <= tree[no].en) ans = max1(ans, getmax(l, r, gright(no)));
            return ans;
        }
    }

    static segment_tree<Integer> sgt;
    static class q {
        int l, r, maxv, deep;
        double p;
    }
    static q[] que = new q[maxq];
    static ArrayList<Integer>[] son = new ArrayList[maxq];
    static int[] arr = new int[maxn];
    static int[] fa = new int[maxq];
    static ArrayList<Pair<Double, Integer>>[] dp = new ArrayList[maxq];
    static int n, nq, be, en;

    static int abs1(int a) {
        return a < 0 ? -a : a;
    }

    static int max1(int a, int b) {
        return b < a ? a : b;
    }

    static int max1(int a, int b, int c) {
        return max1(max1(a, b), c);
    }

    static int max1(int a, int b, int c, int d) {
        return max1(max1(a, b, c), d);
    }

    static int max1(int a, int b, int c, int d, int e) {
        return max1(max1(a, b, c, d), e);
    }

    static int min1(int a, int b) {
        return a < b ? a : b;
    }

    static int min1(int a, int b, int c) {
        return min1(min1(a, b), c);
    }

    static int min1(int a, int b, int c, int d) {
        return min1(min1(a, b, c), d);
    }

    static int min1(int a, int b, int c, int d, int e) {
        return min1(min1(a, b, c, d), e);
    }

    static int jud(double a, double b) {
        if (abs(a) < eps && abs(b) < eps) return 0;
        else if (abs1(a - b) / abs1(a) < eps) return 0;
        if (a < b) return -1;
        return 1;
    }

    static int jud(int a, int b) {
        if (a < b) return -1;
        if (a == b) return 0;
        return 1;
    }

    static <T> int find(T val, T[] a, int na, boolean f_small, boolean f_lb) {
        int be = 0, en = na - 1;
        if (a[0] <= a[na - 1]) {
            if (!f_lb) {
                while (be < en) {
                    int mid = (be + en + 1) / 2;
                    if (jud(a[mid], val) != 1) be = mid;
                    else en = mid - 1;
                }
            } else {
                while (be < en) {
                    int mid = (be + en) / 2;
                    if (jud(a[mid], val) != -1) en = mid;
                    else be = mid + 1;
                }
            }
            if (f_small && jud(a[be], val) == 1) be--;
            if (!f_small && jud(a[be], val) == -1) be++;
        } else {
            if (f_lb) {
                while (be < en) {
                    int mid = (be + en + 1) / 2;
                    if (jud(a[mid], val) != -1) be = mid;
                    else en = mid - 1;
                }
            } else {
                while (be < en) {
                    int mid = (be + en) / 2;
                    if (jud(a[mid], val) != 1) en = mid;
                    else be = mid + 1;
                }
            }
            if (!f_small && jud(a[be], val) == -1) be--;
            if (f_small && jud(a[be], val) == 1) be++;
        }
        return be;
    }

    static <T> T lowb(T num) {
        return num & (-num);
    }

    static int bitnum(int nValue) {
        return Integer.bitCount(nValue);
    }

    static int bitnum(long nValue) {
        return Long.bitCount(nValue) + Long.bitCount(nValue >> 32);
    }

    static int id2(int a) {
        if (a == 0) return 0;
        return 32 - Integer.numberOfLeadingZeros(a);
    }

    static int id2(long a) {
        int temp = (int) (a >> 32);
        if (temp != 0) return 32 - Integer.numberOfLeadingZeros(temp) + 32;
        return id2((int) a);
    }

    static long pow(long n, long m, long mod) {
        if (m < 0) return 0;
        long ans = 1;
        long k = n;
        while (m != 0) {
            if ((m & 1) != 0) {
                ans *= k;
                if (mod != 0) ans %= mod;
            }
            k *= k;
            if (mod != 0) k %= mod;
            m >>= 1;
        }
        return ans;
    }

    static <T> void add(T[] a, int b, int mod) {
        int n = a.length;
        a[b] += mod;
        while (a[b] >= mod) a[b] -= mod;
        while (a[b] < 0) a[b] += mod;
    }

    static <T> void output1(T[] arr) {
        for (int i = 0; i < arr.length; i++)
            System.err.print(arr[i].first + "|" + arr[i].second + " ");
        System.err.println();
    }

    static <T> void output2(T[] arr) {
        for (int i = 0; i < arr.length; i++)
            output1(arr[i]);
    }

    static final double pi = Math.acos(0.0) * 2.0;
    static final double eps = 1e-10;
    static final int[][] step = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        nq = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) arr[i] = Integer.parseInt(st.nextToken());
        for (int i = 0; i < nq; i++) {
            st = new StringTokenizer(br.readLine());
            que[i] = new q();
            que[i].l = Integer.parseInt(st.nextToken());
            que[i].r = Integer.parseInt(st.nextToken());
            que[i].p = Double.parseDouble(st.nextToken());
            que[i].l--;
            que[i].r--;
        }
        for (int i = 0; i < maxq; i++) son[i] = new ArrayList<>();
        Arrays.fill(fa, -1);
        for (int i = 0; i < nq; i++) {
            for (int j = 0; j < i; j++) {
                if (j != i && que[j].r - que[j].l == que[i].r - que[i].l && que[j].r == que[i].r)
                    fa[i] = j;
            }
            if (fa[i] != -1) continue;
            for (int j = 0; j < nq; j++) {
                if (j != i && que[j].r - que[j].l == que[i].r - que[i].l)
                    continue;
                if (que[j].l <= que[i].l && que[j].r >= que[i].r) {
                    if (fa[i] == -1) {
                        fa[i] = j;
                        continue;
                    }
                    if (que[j].r - que[j].l <= que[fa[i]].r - que[fa[i]].l) {
                        fa[i] = j;
                        continue;
                    }
                }
            }
        }
        for (int i = 0; i < nq; i++) {
            if (fa[i] != -1) son[fa[i]].add(i);
            else {
                fa[i] = nq;
                son[nq].add(i);
            }
        }
        que[nq] = new q();
        que[nq].l = 0;
        que[nq].r = n - 1;
        sgt = new segment_tree<>();
        sgt.tree = new segment_node[n * 4];
        sgt.build(1, 0, n - 1, 0, arr);

        dfs(nq);
        dfsdp(nq);
        double ans = 0;
        for (int i = 0; i < dp[nq].size(); i++) {
            ans += dp[nq].get(i).first * dp[nq].get(i).second;
        }
        System.out.printf("%.10f\n", ans);
    }
}
