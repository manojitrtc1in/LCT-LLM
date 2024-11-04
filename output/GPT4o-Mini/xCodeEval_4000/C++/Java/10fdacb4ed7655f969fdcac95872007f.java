import java.util.*;
import java.io.*;

public class 10fdacb4ed7655f969fdcac95872007f_nc {
    static final int maxq = 5010;
    static final int maxn = 100100;
    static final int MOD = 1000000007;
    static int N = 200100;
    static int[] arr = new int[maxn];
    static int[] fa = new int[maxq];
    static List<Pair<Double, Integer>>[] dp = new ArrayList[maxq];
    static SegmentTree sgt = new SegmentTree();
    static Query[] que = new Query[maxq];
    static List<Integer>[] son = new ArrayList[maxq];
    static int n, nq, be, en;

    static {
        for (int i = 0; i < maxq; i++) {
            dp[i] = new ArrayList<>();
            son[i] = new ArrayList<>();
        }
    }

    static class Pair<A, B> {
        A first;
        B second;

        Pair(A first, B second) {
            this.first = first;
            this.second = second;
        }

        Pair<Double, Integer> add(Pair<Double, Integer> other) {
            return new Pair<>(this.first + other.first, Math.max(this.second, other.second));
        }
    }

    static class Query {
        int l, r, maxv, deep;
        double p;
    }

    static class SegmentNode<T> {
        int be, en;
        T maxv, add, sum;
    }

    static class SegmentTree {
        int l;
        SegmentNode<Integer>[] tree;

        SegmentTree() {
            tree = new SegmentNode[N * 4];
            for (int i = 0; i < tree.length; i++) {
                tree[i] = new SegmentNode<>();
            }
        }

        void build(int no, int l, int r, int orig, int[] a) {
            if (l > r) r = l;
            if (l == r) {
                tree[no].be = tree[no].en = l;
                tree[no].add = 0;
                tree[no].maxv = (a == null) ? orig : a[l];
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
            tree[no].maxv = Math.max(tree[gleft(no)].maxv, tree[gright(no)].maxv);
        }

        int gleft(int no) {
            return no << 1;
        }

        int gright(int no) {
            return (no << 1) + 1;
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

        void down(int l, int r, int no, int ranadd) {
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
            tree[no].maxv = Math.max(tree[gleft(no)].maxv, tree[gright(no)].maxv);
        }

        int getmax(int l, int r, int no) {
            if (l > r) return 0;
            if (l <= tree[no].be && r >= tree[no].en)
                return tree[no].maxv;
            if (tree[no].add != 0 && tree[no].be != tree[no].en) relax(no);
            int ans = 0;
            int mid = (tree[no].be + tree[no].en) >> 1;
            if (r >= tree[no].be && l <= mid) ans = Math.max(ans, getmax(l, r, gleft(no)));
            if (r >= mid + 1 && l <= tree[no].en) ans = Math.max(ans, getmax(l, r, gright(no)));
            return ans;
        }
    }

    static void dfs(int no, int deep) {
        que[no].maxv = sgt.getmax(que[no].l, que[no].r, 1);
        be = Math.max(be, que[no].maxv);
        en = Math.max(en, que[no].maxv + deep + 1);
        que[no].deep = deep;
        for (int i : son[no]) {
            dfs(i, deep + 1);
        }
    }

    static void dfsdp(int no) {
        dp[no].add(new Pair<>(1.0, (double) que[no].maxv));
        for (int rno : son[no]) {
            dfsdp(rno);
            List<Pair<Double, Integer>> rdp = new ArrayList<>();
            List<Pair<Double, Integer>> rdp1 = new ArrayList<>();
            double sum1 = dp[no].get(0).first;
            double sum2 = dp[rno].get(0).first;
            double p = que[rno].p;

            for (int link1 = 0, link2 = 0; link1 < dp[no].size() || link2 < dp[rno].size(); ) {
                rdp.add(new Pair<>(sum1 * sum2 * (1 - p), Math.max(dp[no].get(link1).second, dp[rno].get(link2).second)));
                if (link1 == dp[no].size() - 1) {
                    link2++;
                    if (link2 == dp[rno].size()) break;
                    sum2 += dp[rno].get(link2).first;
                } else if (link2 == dp[rno].size() - 1) {
                    link1++;
                    sum1 += dp[no].get(link1).first;
                } else if (dp[no].get(link1 + 1).second > dp[rno].get(link2 + 1).second) {
                    link2++;
                    sum2 += dp[rno].get(link2).first;
                } else {
                    link1++;
                    sum1 += dp[no].get(link1).first;
                }
            }

            for (int i = rdp.size() - 1; i > 0; i--) {
                rdp.get(i).first -= rdp.get(i - 1).first;
            }

            int rsz = 1;
            for (int i = 1; i < rdp.size(); i++) {
                if (rdp.get(i).second.equals(rdp.get(i - 1).second)) {
                    rdp.get(rsz - 1).first += rdp.get(i).first;
                } else {
                    rdp.add(rdp.get(i));
                    rsz++;
                }
            }
            rdp = rdp.subList(0, rsz);

            sum1 = dp[no].get(0).first;
            sum2 = dp[rno].get(0).first;

            for (int link1 = 0, link2 = 0; link1 < dp[no].size() || link2 < dp[rno].size(); ) {
                if (sum1 * sum2 > 1e-10)
                    rdp1.add(new Pair<>(sum1 * sum2 * p, Math.max(dp[no].get(link1).second, dp[rno].get(link2).second + 1)));
                if (link1 == dp[no].size() - 1) {
                    link2++;
                    if (link2 == dp[rno].size()) break;
                    sum2 += dp[rno].get(link2).first;
                } else if (link2 == dp[rno].size() - 1) {
                    link1++;
                    sum1 += dp[no].get(link1).first;
                } else if (dp[no].get(link1 + 1).second > dp[rno].get(link2 + 1).second + 1) {
                    link2++;
                    sum2 += dp[rno].get(link2).first;
                } else {
                    link1++;
                    sum1 += dp[no].get(link1).first;
                }
            }

            for (int i = rdp1.size() - 1; i > 0; i--) {
                rdp1.get(i).first -= rdp1.get(i - 1).first;
            }

            rsz = 1;
            for (int i = 1; i < rdp1.size(); i++) {
                if (rdp1.get(i).second.equals(rdp1.get(i - 1).second)) {
                    rdp1.get(rsz - 1).first += rdp1.get(i).first;
                } else {
                    rdp1.add(rdp1.get(i));
                    rsz++;
                }
            }
            rdp1 = rdp1.subList(0, rsz);

            dp[no].clear();
            for (int link1 = 0, link2 = 0; link1 < rdp.size() || link2 < rdp1.size(); ) {
                if (link2 == rdp1.size()) {
                    dp[no].add(rdp.get(link1));
                    link1++;
                } else if (link1 == rdp.size()) {
                    dp[no].add(rdp1.get(link2));
                    link2++;
                } else if (rdp.get(link1).second > rdp1.get(link2).second) {
                    dp[no].add(rdp1.get(link2));
                    link2++;
                } else if (rdp.get(link1).second.equals(rdp1.get(link2).second)) {
                    dp[no].add(rdp.get(link1).add(rdp1.get(link2)));
                    link2++;
                    link1++;
                } else {
                    dp[no].add(rdp.get(link1));
                    link1++;
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        nq = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = 0; i < nq; i++) {
            st = new StringTokenizer(br.readLine());
            que[i] = new Query();
            que[i].l = Integer.parseInt(st.nextToken()) - 1;
            que[i].r = Integer.parseInt(st.nextToken()) - 1;
            que[i].p = Double.parseDouble(st.nextToken());
        }

        Arrays.fill(fa, -1);
        for (int i = 0; i < nq; i++) {
            for (int j = 0; j < i; j++) {
                if (j != i && que[j].r - que[j].l == que[i].r - que[i].l && que[j].r == que[i].r) {
                    fa[i] = j;
                }
            }
            if (fa[i] != -1) continue;
            for (int j = 0; j < nq; j++) {
                if (j != i && que[j].r - que[j].l != que[i].r - que[i].l && que[j].l <= que[i].l && que[j].r >= que[i].r) {
                    if (fa[i] == -1 || (que[j].r - que[j].l <= que[fa[i]].r - que[fa[i]].l)) {
                        fa[i] = j;
                    }
                }
            }
        }

        for (int i = 0; i < nq; i++) {
            if (fa[i] != -1) {
                son[fa[i]].add(i);
            } else {
                fa[i] = nq;
                son[nq].add(i);
            }
        }

        que[nq] = new Query();
        que[nq].l = 0;
        que[nq].r = n - 1;
        sgt.build(1, 0, n - 1, 0, arr);

        dfs(nq, 0);
        dfsdp(nq);
        double ans = 0;
        for (Pair<Double, Integer> pair : dp[nq]) {
            ans += pair.first * pair.second;
        }
        System.out.printf("%.10f\n", ans);
    }
}
