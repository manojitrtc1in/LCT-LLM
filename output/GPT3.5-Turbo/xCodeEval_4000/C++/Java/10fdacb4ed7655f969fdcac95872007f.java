import java.util.*;
import java.io.*;

class Main {
    static class SegmentNode<T> {
        int be, en;
        T maxv, add, sum;
    }

    static class SegmentTree<T> {
        int l;
        SegmentNode<T>[] tree;

        public SegmentTree(int n) {
            l = 0;
            tree = new SegmentNode[n * 4];
            for (int i = 0; i < n * 4; i++) {
                tree[i] = new SegmentNode<>();
            }
        }

        private int gleft(int no) {
            return no << 1;
        }

        private int gright(int no) {
            return (no << 1) + 1;
        }

        private int gfa(int no) {
            return no >> 1;
        }

        public void build(int no, int l, int r, T orig, T[] a) {
            if (l > r) {
                r = l;
            }
            if (l == r) {
                tree[no].be = tree[no].en = l;
                tree[no].add = null;
                if (a == null) {
                    tree[no].maxv = orig;
                } else {
                    tree[no].maxv = a[l];
                }
                tree[no].add = null;
                tree[no].sum = tree[no].maxv;
                return;
            }
            tree[no].be = l;
            tree[no].en = r;
            int mid = (l + r) / 2;
            build(gleft(no), l, mid, orig, a);
            build(gright(no), mid + 1, r, orig, a);
            tree[no].sum = tree[gleft(no)].sum + tree[gright(no)].sum;
            tree[no].add = null;
            tree[no].maxv = max1(tree[gleft(no)].maxv, tree[gright(no)].maxv);
        }

        private void relax(int no) {
            int le = gleft(no), ri = gright(no);
            tree[le].add = add(tree[le].add, tree[no].add);
            tree[le].sum = add(tree[le].sum, multiply(tree[no].add, tree[le].en - tree[le].be + 1));
            tree[le].maxv = add(tree[le].maxv, tree[no].add);
            tree[ri].add = add(tree[ri].add, tree[no].add);
            tree[ri].sum = add(tree[ri].sum, multiply(tree[no].add, tree[ri].en - tree[ri].be + 1));
            tree[ri].maxv = add(tree[ri].maxv, tree[no].add);
            tree[no].add = null;
        }

        private void down(int l, int r, int no, T ranadd) {
            if (l <= tree[no].be && r >= tree[no].en) {
                tree[no].add = add(tree[no].add, ranadd);
                tree[no].sum = add(tree[no].sum, multiply(ranadd, tree[no].en - tree[no].be + 1));
                tree[no].maxv = add(tree[no].maxv, ranadd);
                return;
            }
            if (tree[no].add != null && tree[no].be != tree[no].en) {
                relax(no);
            }
            int mid = (tree[no].be + tree[no].en) >> 1;
            if (r >= tree[no].be && l <= mid) {
                down(l, r, gleft(no), ranadd);
            }
            if (r >= mid + 1 && l <= tree[no].en) {
                down(l, r, gright(no), ranadd);
            }
            tree[no].sum = add(tree[gleft(no)].sum, tree[gright(no)].sum);
            tree[no].maxv = max1(tree[gleft(no)].maxv, tree[gright(no)].maxv);
        }

        public T getmax(int l, int r, int no) {
            if (l > r) {
                return null;
            }
            if (l <= tree[no].be && r >= tree[no].en) {
                return tree[no].maxv;
            }
            if (tree[no].add != null && tree[no].be != tree[no].en) {
                relax(no);
            }
            T ans = null;
            int mid = (tree[no].be + tree[no].en) >> 1;
            if (r >= tree[no].be && l <= mid) {
                ans = max1(ans, getmax(l, r, gleft(no)));
            }
            if (r >= mid + 1 && l <= tree[no].en) {
                ans = max1(ans, getmax(l, r, gright(no)));
            }
            return ans;
        }

        private T add(T a, T b) {
            // Add implementation here
            return null;
        }

        private T multiply(T a, int b) {
            // Multiply implementation here
            return null;
        }

        private T max1(T a, T b) {
            // Max implementation here
            return null;
        }
    }

    static class Query {
        int l, r, maxv, deep;
        double p;

        public Query(int l, int r, double p) {
            this.l = l;
            this.r = r;
            this.p = p;
        }
    }

    static int be, en;
    static Query[] que;
    static List<Integer>[] son;
    static int[] arr, fa;
    static List<Pair<Double, Integer>>[] dp;
    static int n, nq;

    static void dfs(int no, int deep) {
        que[no].maxv = sgt.getmax(que[no].l, que[no].r, 1);
        be = Math.max(be, que[no].maxv);
        en = Math.max(en, que[no].maxv + deep + 1);
        que[no].deep = deep;
        for (int i = 0; i < son[no].size(); i++) {
            dfs(son[no].get(i), deep + 1);
        }
    }

    static Pair<Double, Integer> add(Pair<Double, Integer> a, Pair<Double, Integer> b) {
        return new Pair<>(a.first + b.first, a.second);
    }

    static void dfsdp(int no) {
        dp[no].add(new Pair<>(1.0, que[no].maxv));
        for (int i = 0; i < son[no].size(); i++) {
            int rno = son[no].get(i);
            dfsdp(rno);
            List<Pair<Double, Integer>> rdp = new ArrayList<>();
            List<Pair<Double, Integer>> rdp1 = new ArrayList<>();
            double sum1 = dp[no].get(0).first, sum2 = dp[rno].get(0).first, p = que[rno].p;
            for (int link1 = 0, link2 = 0; link1 < dp[no].size() || link2 < dp[rno].size(); ) {
                rdp.add(new Pair<>(sum1 * sum2 * (1 - p), Math.max(dp[no].get(link1).second, dp[rno].get(link2).second)));
                if (link1 == dp[no].size() - 1) {
                    link2++;
                    if (link2 == dp[rno].size()) {
                        break;
                    }
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
            for (int j = rdp.size() - 1; j > 0; j--) {
                rdp.get(j).first -= rdp.get(j - 1).first;
            }
            int rsz = 1;
            for (int j = 1; j < rdp.size(); j++) {
                if (rdp.get(j).second == rdp.get(j - 1).second) {
                    rdp.get(rsz - 1).first += rdp.get(j).first;
                } else {
                    rdp.set(rsz++, rdp.get(j));
                }
            }
            rdp.subList(rsz, rdp.size()).clear();

            sum1 = dp[no].get(0).first;
            sum2 = dp[rno].get(0).first;
            for (int link1 = 0, link2 = 0; link1 < dp[no].size() || link2 < dp[rno].size(); ) {
                if (sum1 * sum2 > 1e-10) {
                    rdp1.add(new Pair<>(sum1 * sum2 * p, Math.max(dp[no].get(link1).second, dp[rno].get(link2).second + 1)));
                }
                if (link1 == dp[no].size() - 1) {
                    link2++;
                    if (link2 == dp[rno].size()) {
                        break;
                    }
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
            for (int j = rdp1.size() - 1; j > 0; j--) {
                rdp1.get(j).first -= rdp1.get(j - 1).first;
            }
            rsz = 1;
            for (int j = 1; j < rdp1.size(); j++) {
                if (rdp1.get(j).second == rdp1.get(j - 1).second) {
                    rdp1.get(rsz - 1).first += rdp1.get(j).first;
                } else {
                    rdp1.set(rsz++, rdp1.get(j));
                }
            }
            rdp1.subList(rsz, rdp1.size()).clear();

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
                } else if (rdp.get(link1).second == rdp1.get(link2).second) {
                    dp[no].add(add(rdp.get(link1), rdp1.get(link2)));
                    link2++;
                    link1++;
                } else if (rdp.get(link1).second < rdp1.get(link2).second) {
                    dp[no].add(rdp.get(link1));
                    link1++;
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        n = Integer.parseInt(line[0]);
        nq = Integer.parseInt(line[1]);
        arr = new int[n];
        que = new Query[nq + 1];
        son = new List[nq + 1];
        dp = new List[nq + 1];
        fa = new int[nq];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }
        for (int i = 0; i <= nq; i++) {
            son[i] = new ArrayList<>();
            dp[i] = new ArrayList<>();
        }
        for (int i = 0; i < nq; i++) {
            line = br.readLine().split(" ");
            int l = Integer.parseInt(line[0]) - 1;
            int r = Integer.parseInt(line[1]) - 1;
            double p = Double.parseDouble(line[2]);
            que[i] = new Query(l, r, p);
        }
        Arrays.fill(fa, -1);
        for (int i = 0; i < nq; i++) {
            for (int j = 0; j < i; j++) {
                if (j != i && que[j].r - que[j].l == que[i].r - que[i].l && que[j].r == que[i].r) {
                    fa[i] = j;
                }
            }
            if (fa[i] != -1) {
                continue;
            }
            for (int j = 0; j < nq; j++) {
                if (j != i) {
                    if (que[j].r - que[j].l == que[i].r - que[i].l) {
                        continue;
                    }
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
        }
        for (int i = 0; i < nq; i++) {
            if (fa[i] != -1) {
                son[fa[i]].add(i);
            } else {
                fa[i] = nq;
                son[nq].add(i);
            }
        }
        que[nq] = new Query(0, n - 1, 0);
        SegmentTree<Integer> sgt = new SegmentTree<>(n);
        sgt.build(1, 0, n - 1, 0, arr);
        dfs(nq, 0);
        dfsdp(nq);
        double ans = 0;
        for (int i = 0; i < dp[nq].size(); i++) {
            ans += dp[nq].get(i).first * dp[nq].get(i).second;
        }
        System.out.printf("%.10f\n", ans);
    }
}
