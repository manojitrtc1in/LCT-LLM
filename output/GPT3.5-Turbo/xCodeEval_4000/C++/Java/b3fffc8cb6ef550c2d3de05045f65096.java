import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    static class Pair {
        long first;
        long second;

        Pair(long first, long second) {
            this.first = first;
            this.second = second;
        }
    }

    static class SegNode {
        Pair[] prod;
        long sumlr;
        boolean ident;

        SegNode() {
            prod = new Pair[2];
            sumlr = 0;
            ident = true;
        }
    }

    static class MulSegTree {
        static final int SEGSZ = (int) (1e5) + 4;
        int segn;
        SegNode[] t;
        SegNode identity;

        MulSegTree() {
            segn = SEGSZ;
            t = new SegNode[2 * SEGSZ];
            identity = new SegNode();
        }

        SegNode combine(SegNode x, SegNode y) {
            if (x.ident) return y;
            if (y.ident) return x;
            SegNode ans = new SegNode();
            for (int d = 0; d < 2; d++) {
                ans.prod[d] = new Pair(x.prod[d].first * y.prod[d].first, x.prod[d].second * y.prod[d].second);
            }
            ans.sumlr = (x.sumlr * y.prod[1].second) + (x.prod[0].first * y.sumlr) - (x.prod[0].first * y.prod[1].second);
            ans.ident = false;
            return ans;
        }

        void init(int n) {
            segn = n;
        }

        void build() {
            int n = segn;
            for (int i = n - 1; i > 0; --i) t[i] = combine(t[i << 1], t[i << 1 | 1]);
        }

        void setBeforeBuild(int p, SegNode value) {
            t[segn + p] = value;
        }

        void sset(int p, SegNode value) {
            int n = segn;
            for (t[p += n] = value; p >>= 1; ) t[p] = combine(t[p << 1], t[p << 1 | 1]);
        }

        SegNode query(int l, int r) {
            if (l > r) return identity;
            r++;
            int n = segn;
            SegNode resl = identity, resr = identity;
            for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
                if ((l & 1) == 1) resl = combine(resl, t[l++]);
                if ((r & 1) == 1) resr = combine(t[--r], resr);
            }
            return combine(resl, resr);
        }
    }

    static class Group implements Comparable<Group> {
        int l;
        int r;
        int forceDir;

        Group(int l, int r, int forceDir) {
            this.l = l;
            this.r = r;
            this.forceDir = forceDir;
        }

        @Override
        public int compareTo(Group other) {
            if (r < other.r) return -1;
            if (r > other.r) return 1;
            if (l < other.l) return -1;
            if (l > other.l) return 1;
            if (forceDir < other.forceDir) return -1;
            if (forceDir > other.forceDir) return 1;
            return 0;
        }
    }

    static class GroupSet {
        static final int mx = (int) (1e5);
        TreeSet<Group> s;

        GroupSet() {
            s = new TreeSet<>();
        }

        Group combine(Group x, Group y) {
            if (Math.min(x.forceDir, y.forceDir) >= 0) {
                assert x.forceDir == y.forceDir;
            }
            return new Group(Math.min(x.l, y.l), Math.max(x.r, y.r), Math.max(x.forceDir, y.forceDir));
        }

        Group getInitialValue(int x) {
            return new Group(x, x, -1);
        }

        void init(int n) {
            for (int x = 0; x < n; x++) {
                ufreset(x);
            }
        }

        Group lb(int x) {
            Group g = new Group(-2, x, -2);
            return s.ceiling(g);
        }

        void ufreset(int x) {
            s.add(getInitialValue(x));
        }

        void funion(int x, int y) {
            Group it1 = lb(x);
            Group it2 = lb(y);
            if (!it1.equals(it2)) {
                Group combined = combine(it1, it2);
                s.remove(it1);
                it2 = lb(y);
                s.remove(it2);
                s.add(combined);
            }
        }

        Group getData(int x) {
            Group it = lb(x);
            return it;
        }

        void setData(int x, Group dat) {
            Group it = lb(x);
            s.remove(it);
            s.add(dat);
        }

        void split(int pl, int pr, int dl, int dr) {
            assert -1 <= dl && dl < 2;
            assert -1 <= dr && dr < 2;
            assert pl + 1 == pr;
            Group itl = lb(pl);
            Group itr = lb(pr);
            assert itl.forceDir == -1;
            assert itr.forceDir == -1;
            if (itl.equals(itr)) {
                Group g = itl;
                s.remove(itl);
                s.add(new Group(g.l, pl, dl));
                s.add(new Group(pr, g.r, dr));
            } else {
                assert false;
            }
        }

        void check() {
        }

        int getDir(int x) {
            return getData(x).forceDir;
        }
    }

    static int[] vpos;
    static int[] v;
    static Pair[][] probBallDir;
    static GroupSet gs;
    static MulSegTree seg;

    static Pair probForce(int dir, int l, int r) {
        assert 0 <= dir && dir < 2;
        Pair[] prod = seg.query(l, r).prod;
        return new Pair(prod[dir].first, prod[dir].second);
    }

    static long probSumlr(int l, int r) {
        return seg.query(l, r).sumlr;
    }

    static long getProdOfRange(int l, int r) {
        int lo = Integer.MAX_VALUE, hi = Integer.MIN_VALUE;
        long ans = 1;
        gs.check();
        for (int pos = l; pos <= r; ) {
            Group dat = gs.getData(pos);
            lo = Math.min(lo, dat.l);
            hi = Math.max(hi, dat.r);
            long mult;
            if (dat.forceDir == -1) {
                mult = seg.query(dat.l, dat.r).sumlr;
            } else {
                mult = seg.query(dat.l, dat.r).prod[dat.forceDir].first;
            }
            ans *= mult;
            pos = dat.r + 1;
        }
        return ans;
    }

    static void mergeFates(int l, int r) {
        Group dl = gs.getData(l);
        Group dr = gs.getData(r);
        if ((dl.forceDir == 1 && dr.forceDir == -1) ||
                (dl.forceDir == -1 && dr.forceDir == 0) ||
                (dl.forceDir == -1 && dr.forceDir == -1)) {
            long den = getProdOfRange(dl.l, dr.r);
            gs.funion(l, r);
            long num = getProdOfRange(dl.l, dr.r);
            probNoCollide *= num / den;
        } else if (dl.forceDir == 0 && dr.forceDir == -1) {

        } else if (dl.forceDir == -1 && dr.forceDir == 1) {

        } else if (dl.forceDir >= 0 && dr.forceDir >= 0) {
            if (dl.forceDir == dr.forceDir) {

            } else {
                probNoCollide = 0;
            }
        } else {
            assert false;
        }
    }

    static long rat2Mint(Pair r) {
        return r.first / r.second;
    }

    public static void main(String[] args) {
        FastReader sc = new FastReader();
        int n = sc.nextInt();
        int alln = n;
        vpos = new int[mx];
        v = new int[mx];
        probBallDir = new Pair[mx][2];
        gs = new GroupSet();
        seg = new MulSegTree();
        for (int i = 0; i < n; i++) {
            vpos[i] = sc.nextInt();
            v[i] = sc.nextInt();
            probBallDir[i][1] = new Pair(sc.nextInt(), 100);
            probBallDir[i][0] = new Pair(1 - probBallDir[i][1].first, probBallDir[i][1].second);
        }
        gs.init(n);
        seg.init(n);
        for (int pos = 0; pos < n; pos++) {
            seg.setBeforeBuild(pos, new SegNode());
            seg.t[seg.segn + pos].prod[0] = probBallDir[pos][0];
            seg.t[seg.segn + pos].prod[1] = probBallDir[pos][1];
            seg.t[seg.segn + pos].sumlr = probBallDir[pos][0].first + probBallDir[pos][1].first;
            seg.t[seg.segn + pos].ident = false;
        }
        seg.build();

        List<Pair> collisions = new ArrayList<>();
        for (int i = 0; i < (n - 1); i++) {
            int dist = vpos[i + 1] - vpos[i];
            Pair rlCollideTime = new Pair(dist, v[i + 1] + v[i]);
            collisions.add(new Pair(rlCollideTime.first, i));
            collisions.add(new Pair(rlCollideTime.first, i));
            if (v[i] > v[i + 1]) {
                Pair rrCollideTime = new Pair(dist, v[i] - v[i + 1]);
                collisions.add(new Pair(rrCollideTime.first, i));
            }
            if (v[i] < v[i + 1]) {
                Pair llCollideTime = new Pair(dist, v[i + 1] - v[i]);
                collisions.add(new Pair(llCollideTime.first, i));
            }
        }
        Collections.sort(collisions, new Comparator<Pair>() {
            @Override
            public int compare(Pair o1, Pair o2) {
                if (o1.first < o2.first) return -1;
                if (o1.first > o2.first) return 1;
                return 0;
            }
        });

        long finalSum = 0;
        long probNoCollide = 1;
        for (Pair c : collisions) {
            int pos = (int) c.second;
            long prevProbNoCollide = probNoCollide;
            int dl = gs.getDir(pos);
            int dr = gs.getDir(pos + 1);
            if (dl != -1 && dl != 1) continue;
            if (dr != -1 && dr != 0) continue;
            if (c.first == 1 && c.second == 0) {
                mergeFates(pos, pos + 1);
            } else if (c.first == 1 && c.second == 1) {
                if (dl == 1) {
                    probNoCollide = 0;
                } else {
                    long den = getProdOfRange(pos, pos + 1);
                    gs.split(pos, pos + 1, 0, -1);
                    long num = getProdOfRange(pos, pos + 1);
                    probNoCollide *= num / den;
                }
            } else if (c.first == 1 && c.second == 0) {
                if (dr == 0) {
                    probNoCollide = 0;
                } else {
                    long den = getProdOfRange(pos, pos + 1);
                    gs.split(pos, pos + 1, -1, 1);
                    long num = getProdOfRange(pos, pos + 1);
                    probNoCollide *= num / den;
                }
            } else {
                assert false;
            }
            gs.check();
            long collideTime = rat2Mint(c);

            finalSum += collideTime * (prevProbNoCollide - probNoCollide);
            if (probNoCollide == 0) break;
        }
        System.out.println(finalSum);
    }
}
