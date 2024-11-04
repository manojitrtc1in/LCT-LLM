import java.util.*;

class Main {
    static class LCA {
        private long N;
        private long n;
        private List<List<Long>> up;
        private List<List<Long>> g;
        private List<Long> lvl;

        private void dfs(long v, long h) {
            lvl.set((int) v, h);
            for (long u : g.get((int) v)) {
                dfs(u, h + 1);
            }
        }

        public LCA(List<Long> parent) {
            n = parent.size();
            N = (long) (Math.log(n) / Math.log(2)) + 1;
            g = new ArrayList<>(Collections.nCopies((int) n, new ArrayList<>()));
            lvl = new ArrayList<>(Collections.nCopies((int) n, 0L));
            long core = -1;
            for (int i = 0; i < n; i++) {
                if (parent.get(i) != -1L) {
                    g.get((int) (long) parent.get(i)).add((long) i);
                } else {
                    core = i;
                }
            }
            dfs(core, 0);
            up = new ArrayList<>(Collections.nCopies((int) N, new ArrayList<>(Collections.nCopies((int) n, -1L))));
            up.get(0).addAll(parent);
            for (int i = 1; i < N; i++) {
                for (int j = 0; j < n; j++) {
                    long parentVal = up.get(i - 1).get(j);
                    if (parentVal == -1) {
                        up.get(i).add(-1L);
                    } else {
                        up.get(i).add(up.get(i - 1).get((int) parentVal));
                    }
                }
            }
        }

        public long getParent(long v, long needUp) {
            for (int i = (int) (N - 1); i >= 0; i--) {
                if (up.get(i).get((int) v) != -1 && lvl.get((int) v) - lvl.get((int) up.get(i).get((int) v)) <= needUp) {
                    needUp -= lvl.get((int) v) - lvl.get((int) up.get(i).get((int) v));
                    v = up.get(i).get((int) v);
                }
            }
            return needUp != 0 ? -1 : v;
        }

        public long getLCA(long a, long b) {
            if (lvl.get((int) a) > lvl.get((int) b)) {
                long del = Math.abs(lvl.get((int) a) - lvl.get((int) b));
                a = getParent(a, del);
            }
            if (lvl.get((int) a) < lvl.get((int) b)) {
                long del = Math.abs(lvl.get((int) a) - lvl.get((int) b));
                b = getParent(b, del);
            }
            if (a == b) {
                return a;
            }
            for (int i = (int) (N - 1); i >= 0; i--) {
                if (!up.get(i).get((int) a).equals(up.get(i).get((int) b))) {
                    a = up.get(i).get((int) a);
                    b = up.get(i).get((int) b);
                }
            }
            return up.get(0).get((int) a);
        }

        public long getLvl(long v) {
            return lvl.get((int) v);
        }
    }

    static class Node {
        private long a;
        private long del;
        private LCA lca;
        private long l;
        private long r;
        private Node lChildren;
        private Node rChildren;

        private static final long[] zero = {-1, -1};

        private long[] merge(long[] x, long[] y, long len1, long len2) {
            if (len1 > 2 && len2 > 2) {
                long a = x[0];
                long b = x[1];
                long c = y[0];
                long d = y[1];

                long ac = lca.getLCA(a, c);
                long acb = lca.getLCA(ac, b);
                long acd = lca.getLCA(ac, d);
                if (lca.getLvl(acb) > lca.getLvl(acd)) {
                    return new long[]{acb, d};
                } else {
                    return new long[]{acd, b};
                }
            }
            if (len1 == 0) {
                return y;
            }
            if (len2 == 0) {
                return x;
            }
            long a = x[0];
            long b = x[1];
            long c = y[0];
            long d = y[1];

            if (len1 == 1 && len2 == 1) {
                return lca.getLvl(b) > lca.getLvl(d) ? new long[]{b, d} : new long[]{d, b};
            }

            if (len1 == 1) {
                if (len2 == 2) {
                    long bc = lca.getLCA(b, c);
                    long bd = lca.getLCA(b, d);
                    long cd = lca.getLCA(c, d);
                    long lbc = lca.getLvl(bc);
                    long lbd = lca.getLvl(bd);
                    long lcd = lca.getLvl(cd);
                    if (lbc > lbd && lbc > lcd) {
                        return new long[]{bc, d};
                    }
                    if (lbd > lcd) {
                        return new long[]{bd, c};
                    }
                    return new long[]{cd, b};
                }

                long bc = lca.getLCA(b, c);
                long cd = lca.getLCA(c, d);
                long lbc = lca.getLvl(bc);
                long lcd = lca.getLvl(cd);
                return lbc > lcd ? new long[]{bc, d} : new long[]{cd, b};
            }
            if (len2 == 1) {
                if (len1 == 2) {
                    long ab = lca.getLCA(a, b);
                    long ad = lca.getLCA(a, d);
                    long bd = lca.getLCA(b, d);
                    long lab = lca.getLvl(ab);
                    long lad = lca.getLvl(ad);
                    long lbd = lca.getLvl(bd);
                    if (lab > lad && lab > lbd) {
                        return new long[]{ab, d};
                    }
                    if (lad > lbd) {
                        return new long[]{ad, b};
                    }
                    return new long[]{bd, a};
                }

                long ab = lca.getLCA(b, a);
                long ad = lca.getLCA(a, d);
                long lab = lca.getLvl(ab);
                long lad = lca.getLvl(ad);
                return lab > lad ? new long[]{ab, d} : new long[]{ad, b};
            }
            if (len1 == 2 && len2 > 2) {
                long abc = lca.getLCA(a, lca.getLCA(b, c));
                long acd = lca.getLCA(a, lca.getLCA(c, d));
                long bcd = lca.getLCA(b, lca.getLCA(c, d));

                long labc = lca.getLvl(abc);
                long lacd = lca.getLvl(acd);
                long lbcd = lca.getLvl(bcd);
                long ans = Math.max(Math.max(labc, lacd), lbcd);
                if (labc == ans) {
                    return new long[]{abc, d};
                }
                if (lacd == ans) {
                    return new long[]{acd, b};
                }
                if (lbcd == ans) {
                    return new long[]{bcd, a};
                }
            }
            if (len2 == 2 && len1 > 2) {
                long abc = lca.getLCA(a, lca.getLCA(b, c));
                long abd = lca.getLCA(a, lca.getLCA(b, d));
                long acd = lca.getLCA(a, lca.getLCA(c, d));

                long labc = lca.getLvl(abc);
                long labd = lca.getLvl(abd);
                long lacd = lca.getLvl(acd);
                long ans = Math.max(Math.max(labc, labd), lacd);
                if (labc == ans) {
                    return new long[]{abc, d};
                }
                if (labd == ans) {
                    return new long[]{abd, c};
                }
                if (lacd == ans) {
                    return new long[]{acd, b};
                }
            }

            long abc = lca.getLCA(a, lca.getLCA(b, c));
            long abd = lca.getLCA(a, lca.getLCA(b, d));
            long acd = lca.getLCA(a, lca.getLCA(c, d));
            long bcd = lca.getLCA(b, lca.getLCA(c, d));

            long labc = lca.getLvl(abc);
            long labd = lca.getLvl(abd);
            long lacd = lca.getLvl(acd);
            long lbcd = lca.getLvl(bcd);
            long ans = Math.max(Math.max(Math.max(labc, labd), lacd), lbcd);
            if (labc == ans) {
                return new long[]{abc, d};
            }
            if (labd == ans) {
                return new long[]{abd, c};
            }
            if (lacd == ans) {
                return new long[]{acd, b};
            }
            if (lbcd == ans) {
                return new long[]{bcd, a};
            }

            return zero;
        }

        public Node(long l, long r, List<Long> arr, LCA lca) {
            this.lca = lca;
            this.l = l;
            this.r = r;
            if (l == r) {
                a = -1;
                del = arr.get((int) l);
            } else {
                long mid = (l + r) / 2;
                lChildren = new Node(l, mid, arr, lca);
                rChildren = new Node(mid + 1, r, arr, lca);
                long len1 = mid - l + 1;
                long len2 = r - mid;
                long[] p = merge(lChildren.getValue(), rChildren.getValue(), len1, len2);
                a = p[0];
                del = p[1];
            }
        }

        public Node(List<Long> arr, LCA lca) {
            this(0, arr.size() - 1, arr, lca);
        }

        public long[] getValue() {
            return new long[]{a, del};
        }

        public long[] getValue(long left, long right) {
            if (l == left && r == right) {
                return getValue();
            }
            long mid = (l + r) / 2;
            long[] p1, p2;
            long len1 = 0;
            long len2 = 0;
            p1 = p2 = zero;
            if (left <= mid) {
                p1 = lChildren.getValue(left, Math.min(right, mid));
                len1 = Math.min(right, mid) - left + 1;
            }
            if (right > mid) {
                p2 = rChildren.getValue(Math.max(mid + 1, left), right);
                len2 = right - Math.max(mid + 1, left) + 1;
            }
            return merge(p1, p2, len1, len2);
        }

        public void update(long l, long r, long value) {
            if (l == this.l && r == this.r) {
                return;
            }
            long mid = (this.l + this.r) / 2;
            if (l <= mid) {
                lChildren.update(l, Math.min(mid, r), value);
            }
            if (r > mid) {
                rChildren.update(Math.max(mid + 1, l), r, value);
            }
        }
    }

    static long gcd(long a, long b) {
        if (a < b) {
            long temp = a;
            a = b;
            b = temp;
        }
        return b == 0 ? a : gcd(b, a % b);
    }

    static long gcd(long a, long b, long[] x, long[] y) {
        if (a == 0) {
            x[0] = 0;
            y[0] = 1;
            return b;
        }
        long[] x1 = new long[1];
        long[] y1 = new long[1];
        long d = gcd(b % a, a, x1, y1);
        x[0] = y1[0] - (b / a) * x1[0];
        y[0] = x1[0];
        return d;
    }

    static long nok(long a, long b) {
        long nnod = gcd(a, b);
        return a / nnod * b;
    }

    static long divup(long a, long b) {
        return a % b == 0 ? a / b : a / b + 1;
    }

    static class SNM {
        private List<Long> parent;
        private List<Long> size;

        public SNM(long n) {
            parent = new ArrayList<>(Collections.nCopies((int) n, 0L));
            size = new ArrayList<>(Collections.nCopies((int) n, 1L));
            for (int i = 0; i < n; i++) {
                parent.set(i, (long) i);
            }
        }

        public void make_set(int v) {
            parent.set(v, (long) v);
        }

        public long find_set(int v) {
            if (v == parent.get(v)) {
                return v;
            }
            long ans = find_set((int) (long) parent.get(v));
            parent.set(v, ans);
            return ans;
        }

        public void union_sets(int a, int b) {
            a = (int) find_set(a);
            b = (int) find_set(b);
            if (a != b) {
                parent.set(b, (long) a);
                size.set(a, size.get(a) + size.get(b));
            }
        }

        public long getSize(int v) {
            v = (int) find_set(v);
            return size.get(v);
        }
    }

    static boolean chec(long day, Set<long[]> pr, List<Long> arr) {
        List<long[]> bue = new ArrayList<>();
        long sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            long[] p = {i, -day};
            Optional<long[]> it = pr.stream().filter(x -> x[0] == p[0]).findFirst();
            if (!it.isPresent()) {
                sum += arr.get(i);
            } else {
                bue.add(new long[]{-it.get()[1], i});
            }
        }
        bue.sort(Comparator.comparingLong(x -> x[0]));

        long moneyDelete = 0;
        for (long[] p : bue) {
            long money = p[0] - moneyDelete;
            long need = arr.get((int) p[1]);
            if (need <= money) {
                moneyDelete += need;
            } else {
                moneyDelete += money;
                sum += need - money;
            }
        }
        return (moneyDelete + sum * 2 <= day);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long m = sc.nextLong();
        List<Long> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            arr.add(sc.nextLong());
        }
        Set<long[]> pr = new HashSet<>();
        for (int i = 0; i < m; i++) {
            long a = sc.nextLong();
            long b = sc.nextLong();
            pr.add(new long[]{b - 1, -a});
        }
        long l = 0;
        long r = (long) 1e18;
        while (l < r) {
            long mid = (l + r) / 2;
            if (chec(mid, pr, arr)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        System.out.println(l);
    }
}