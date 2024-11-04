import java.util.*;

class Main {
    static class Pair {
        long first;
        long second;

        Pair(long first, long second) {
            this.first = first;
            this.second = second;
        }
    }

    static class LCA {
        private long N;
        private long n;
        private long[][] up;
        private List<List<Long>> g;
        private List<Long> lvl;

        private void dfs(long v, long h) {
            lvl.set((int) v, h);
            for (long u : g.get((int) v)) {
                dfs(u, h + 1);
            }
        }

        LCA(List<Long> parent) {
            n = parent.size();
            N = (long) (Math.log(n) / Math.log(2)) + 1;
            g = new ArrayList<>();
            lvl = new ArrayList<>();
            long core = -1;
            for (int i = 0; i < n; i++) {
                g.add(new ArrayList<>());
                lvl.add((long) 0);
                if (parent.get(i) != -1) {
                    g.get(parent.get(i).intValue()).add((long) i);
                } else {
                    core = i;
                }
            }
            dfs(core, 0);
            up = new long[(int) N][(int) n];
            for (int i = 0; i < N; i++) {
                up[i] = new long[(int) n];
            }
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < n; j++) {
                    long parentVal = up[i - 1][(int) j];
                    if (parentVal == -1) {
                        up[i][(int) j] = -1;
                    } else {
                        up[i][(int) j] = up[i - 1][(int) parentVal];
                    }
                }
            }
        }

        long getParent(long v, long needUp) {
            for (int i = (int) N - 1; i >= 0; i--) {
                if (up[i][(int) v] != -1 && lvl.get((int) v) - lvl.get((int) up[i][(int) v]) <= needUp) {
                    needUp -= lvl.get((int) v) - lvl.get((int) up[i][(int) v]);
                    v = up[i][(int) v];
                }
            }
            if (needUp != 0) {
                return -1;
            } else {
                return v;
            }
        }

        long getLCA(long a, long b) {
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
            for (int i = (int) N - 1; i >= 0; i--) {
                if (up[i][(int) a] != up[i][(int) b]) {
                    a = up[i][(int) a];
                    b = up[i][(int) b];
                }
            }
            return up[0][(int) a];
        }

        long getLvl(long v) {
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
        private Pair zero = new Pair(-1, -1);

        Node(long l, long r, List<Long> arr, LCA lca) {
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
                Pair p = merge(lChildren.getValue(), rChildren.getValue(), len1, len2);
                a = p.first;
                del = p.second;
            }
        }

        Pair getValue() {
            return new Pair(a, del);
        }

        Pair getValue(long left, long right) {
            if (l == left && r == right) {
                return getValue();
            }
            long mid = (l + r) / 2;
            Pair p1, p2;
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
            Pair p = merge(p1, p2, len1, len2);
            return p;
        }

        void update(long l, long r, long value) {
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

        private Pair merge(Pair x, Pair y, long len1, long len2) {
            if (len1 > 2 && len2 > 2) {
                long a = x.first;
                long b = x.second;
                long c = y.first;
                long d = y.second;
                long ac = lca.getLCA(a, c);
                long acb = lca.getLCA(ac, b);
                long acd = lca.getLCA(ac, d);
                if (lca.getLvl(acb) > lca.getLvl(acd)) {
                    return new Pair(acb, d);
                } else {
                    return new Pair(acd, b);
                }
            }
            if (len1 == 0) {
                return y;
            }
            if (len2 == 0) {
                return x;
            }
            long a = x.first;
            long b = x.second;
            long c = y.first;
            long d = y.second;
            if (len1 == 1 && len2 == 1) {
                if (lca.getLvl(b) > lca.getLvl(d)) {
                    return new Pair(b, d);
                } else {
                    return new Pair(d, b);
                }
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
                        return new Pair(bc, d);
                    }
                    if (lbd > lcd) {
                        return new Pair(bd, c);
                    }
                    return new Pair(cd, b);
                }
                long bc = lca.getLCA(b, c);
                long cd = lca.getLCA(c, d);
                long lbc = lca.getLvl(bc);
                long lcd = lca.getLvl(cd);
                if (lbc > lcd) {
                    return new Pair(bc, d);
                } else {
                    return new Pair(cd, b);
                }
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
                        return new Pair(ab, d);
                    }
                    if (lad > lbd) {
                        return new Pair(ad, b);
                    }
                    return new Pair(bd, a);
                }
                long ab = lca.getLCA(b, a);
                long ad = lca.getLCA(a, d);
                long lab = lca.getLvl(ab);
                long lad = lca.getLvl(ad);
                if (lab > lad) {
                    return new Pair(ab, d);
                } else {
                    return new Pair(ad, b);
                }
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
                    return new Pair(abc, d);
                }
                if (lacd == ans) {
                    return new Pair(acd, b);
                }
                if (lbcd == ans) {
                    return new Pair(bcd, a);
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
                    return new Pair(abc, d);
                }
                if (labd == ans) {
                    return new Pair(abd, c);
                }
                if (lacd == ans) {
                    return new Pair(acd, b);
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
                return new Pair(abc, d);
            }
            if (labd == ans) {
                return new Pair(abd, c);
            }
            if (lacd == ans) {
                return new Pair(acd, b);
            }
            if (lbcd == ans) {
                return new Pair(bcd, a);
            }
            return zero;
        }
    }

    static long gcd(long a, long b) {
        if (a < b) {
            long temp = a;
            a = b;
            b = temp;
        }
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
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
        if (a % b == 0) {
            return a / b;
        } else {
            return a / b + 1;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        long n = sc.nextLong();
        long m = sc.nextLong();
        List<Long> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            arr.add(sc.nextLong());
        }
        SortedSet<Pair> pr = new TreeSet<>(Comparator.comparingLong(p -> p.first));
        for (int i = 0; i < m; i++) {
            long a = sc.nextLong();
            long b = sc.nextLong();
            pr.add(new Pair(b - 1, -a));
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

    static boolean chec(long day, SortedSet<Pair> pr, List<Long> arr) {
        List<Pair> bue = new ArrayList<>();
        long sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            Pair p = new Pair(i, -day);
            Pair it = pr.floor(p);
            if (it == null || it.first != i) {
                sum += arr.get(i);
            } else {
                bue.add(new Pair(-it.second, (long) i));
            }
        }
        bue.sort(Comparator.comparingLong(p -> p.first));

        long moneyDelete = 0;
        for (Pair p : bue) {
            long money = p.first - moneyDelete;
            long need = arr.get((int) (long) p.second);
            if (need <= money) {
                moneyDelete += need;
            } else {
                moneyDelete += money;
                sum += need - money;
            }
        }
        return (moneyDelete + sum * 2 <= day);
    }
}
