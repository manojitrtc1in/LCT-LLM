import java.util.*;
import java.io.*;

class SegmentNode<T> {
    int be, en;
    T maxv, add, sum;
}

class SegmentTree<T> {
    int l;
    SegmentNode<T>[] tree;

    @SuppressWarnings("unchecked")
    SegmentTree(int N) {
        l = 0;
        tree = new SegmentNode[N * 4];
        for (int i = 0; i < tree.length; i++) {
            tree[i] = new SegmentNode<>();
        }
    }

    int gleft(int no) {
        return no << 1;
    }

    int gright(int no) {
        return (no << 1) + 1;
    }

    void build(int no, int l, int r, T orig, T[] a) {
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
        tree[no].sum = (Integer) tree[gleft(no)].sum + (Integer) tree[gright(no)].sum;
        tree[no].add = 0;
        tree[no].maxv = Math.max((Integer) tree[gleft(no)].maxv, (Integer) tree[gright(no)].maxv);
    }

    void relax(int no) {
        int le = gleft(no), ri = gright(no);
        tree[le].add += tree[no].add;
        tree[le].sum += (Integer) tree[no].add * (tree[le].en - tree[le].be + 1);
        tree[le].maxv += tree[no].add;
        tree[ri].add += tree[no].add;
        tree[ri].sum += (Integer) tree[no].add * (tree[ri].en - tree[ri].be + 1);
        tree[ri].maxv += tree[no].add;
        tree[no].add = 0;
    }

    void down(int l, int r, int no, T ranadd) {
        if (l <= tree[no].be && r >= tree[no].en) {
            tree[no].add += ranadd;
            tree[no].sum += (Integer) ranadd * (tree[no].en - tree[no].be + 1);
            tree[no].maxv += ranadd;
            return;
        }
        if (tree[no].add != null && tree[no].be != tree[no].en) relax(no);
        int mid = (tree[no].be + tree[no].en) >> 1;
        if (r >= tree[no].be && l <= mid) down(l, r, gleft(no), ranadd);
        if (r >= mid + 1 && l <= tree[no].en) down(l, r, gright(no), ranadd);
        tree[no].sum = (Integer) tree[gleft(no)].sum + (Integer) tree[gright(no)].sum;
        tree[no].maxv = Math.max((Integer) tree[gleft(no)].maxv, (Integer) tree[gright(no)].maxv);
    }

    T getmax(int l, int r, int no) {
        if (l > r) return (T) Integer.valueOf(0);
        if (l <= tree[no].be && r >= tree[no].en)
            return tree[no].maxv;
        if (tree[no].add != null && tree[no].be != tree[no].en) relax(no);
        T ans = (T) Integer.valueOf(0);
        int mid = (tree[no].be + tree[no].en) >> 1;
        if (r >= tree[no].be && l <= mid) ans = Math.max((Integer) ans, (Integer) getmax(l, r, gleft(no)));
        if (r >= mid + 1 && l <= tree[no].en) ans = Math.max((Integer) ans, (Integer) getmax(l, r, gright(no)));
        return ans;
    }
}

class Query {
    int l, r, maxv, deep;
    double p;
}

public class 10fdacb4ed7655f969fdcac95872007fxcodeeval_processed_4000.json {
    static final int maxq = 5010;
    static final int maxn = 100100;
    static SegmentTree<Integer> sgt = new SegmentTree<>(maxn);
    static Query[] que = new Query[maxq];
    static List<Integer>[] son = new ArrayList[maxq];
    static int[] arr = new int[maxn];
    static int[] fa = new int[maxq];
    static List<Pair<Double, Integer>>[] dp = new ArrayList[maxq];
    static int n, nq, be, en;

    static {
        for (int i = 0; i < maxq; i++) {
            son[i] = new ArrayList<>();
            dp[i] = new ArrayList<>();
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

    static Pair<Double, Integer> add(Pair<Double, Integer> a, Pair<Double, Integer> b) {
        return new Pair<>(a.first + b.first, a.second);
    }

    static void dfsdp(int no) {
        dp[no].add(new Pair<>(1.0, (double) que[no].maxv));
        for (int rno : son[no]) {
            dfsdp(rno);
            List<Pair<Double, Integer>> rdp = new ArrayList<>();
            List<Pair<Double, Integer>> id1 = new ArrayList<>();
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
                    rdp.set(rsz++, rdp.get(i));
                }
            }
            rdp = rdp.subList(0, rsz);

            sum1 = dp[no].get(0).first;
            sum2 = dp[rno].get(0).first;
            for (int link1 = 0, link2 = 0; link1 < dp[no].size() || link2 < dp[rno].size(); ) {
                if (sum1 * sum2 > 1e-10) {
                    id1.add(new Pair<>(sum1 * sum2 * p, Math.max(dp[no].get(link1).second, dp[rno].get(link2).second + 1)));
                }
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
            for (int i = id1.size() - 1; i > 0; i--) {
                id1.get(i).first -= id1.get(i - 1).first;
            }
            rsz = 1;
            for (int i = 1; i < id1.size(); i++) {
                if (id1.get(i).second.equals(id1.get(i - 1).second)) {
                    id1.get(rsq - 1).first += id1.get(i).first;
                } else {
                    id1.set(rsz++, id1.get(i));
                }
            }
            id1 = id1.subList(0, rsz);

            dp[no].clear();
            for (int link1 = 0, link2 = 0; link1 < rdp.size() || link2 < id1.size(); ) {
                if (link2 == id1.size()) {
                    dp[no].add(rdp.get(link1));
                    link1++;
                } else if (link1 == rdp.size()) {
                    dp[no].add(id1.get(link2));
                    link2++;
                } else if (rdp.get(link1).second > id1.get(link2).second) {
                    dp[no].add(id1.get(link2));
                    link2++;
                } else if (rdp.get(link1).second.equals(id1.get(link2).second)) {
                    dp[no].add(add(rdp.get(link1), id1.get(link2)));
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
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        nq = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = 0; i < nq; i++) {
            que[i] = new Query();
            st = new StringTokenizer(br.readLine());
            que[i].l = Integer.parseInt(st.nextToken()) - 1;
            que[i].r = Integer.parseInt(st.nextToken()) - 1;
            que[i].p = Double.parseDouble(st.nextToken());
        }

        Arrays.fill(fa, -1);
        for (int i = 0; i < nq; i++) {
            for (int j = 0; j < i; j++) {
                if (j != i) {
                    if (que[j].r - que[j].l == que[i].r - que[i].l && que[j].r == que[i].r) {
                        fa[i] = j;
                    }
                }
            }
            if (fa[i] != -1) continue;
            for (int j = 0; j < nq; j++) {
                if (j != i) {
                    if (que[j].r - que[j].l == que[i].r - que[i].l) continue;
                    if (que[j].l <= que[i].l && que[j].r >= que[i].r) {
                        if (fa[i] == -1) {
                            fa[i] = j;
                        } else if (que[j].r - que[j].l <= que[fa[i]].r - que[fa[i]].l) {
                            fa[i] = j;
                        }
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

class Pair<F, S> {
    public F first;
    public S second;

    public Pair(F first, S second) {
        this.first = first;
        this.second = second;
    }
}
