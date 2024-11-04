import java.util.*;
import java.io.*;

public class b3fffc8cb6ef550c2d3de05045f65096_nc {
    static final int MOD = 998244353;
    static final int UNDEF = -1;
    static final int INF = 1 << 30;
    static final int mn = (int) (1e5) + 4;
    static final int L = 0, R = 1;

    static long[] vpos = new long[mn], v = new long[mn];
    static Mint[][] probBallDir = new Mint[mn][2];
    static GroupSet gs = new GroupSet();
    static MulSegTree seg = new MulSegTree();

    static class Mint {
        long x;

        Mint() {
            this.x = 0;
        }

        Mint(long sig) {
            sig = _norm(sig);
            this.x = sig;
        }

        int _norm(long x) {
            if (x < 0) x += MOD;
            return (int) (x % MOD);
        }

        Mint add(Mint that) {
            return new Mint(this.x + that.x >= MOD ? this.x + that.x - MOD : this.x + that.x);
        }

        Mint subtract(Mint that) {
            return new Mint(this.x + MOD - that.x >= MOD ? this.x + MOD - that.x - MOD : this.x + MOD - that.x);
        }

        Mint multiply(Mint that) {
            return new Mint((this.x * that.x) % MOD);
        }

        Mint divide(Mint that) {
            return this.multiply(that.inverse());
        }

        Mint inverse() {
            long a = x, b = MOD, u = 1, v = 0;
            while (b != 0) {
                long t = a / b;
                a -= t * b; 
                long temp = a; a = b; b = temp;
                u -= t * v; 
                temp = u; u = v; v = temp;
            }
            if (u < 0) u += MOD;
            return new Mint(u);
        }

        @Override
        public boolean equals(Object obj) {
            if (this == obj) return true;
            if (!(obj instanceof Mint)) return false;
            Mint that = (Mint) obj;
            return this.x == that.x;
        }

        @Override
        public String toString() {
            return String.valueOf(x);
        }
    }

    static class Rational {
        long nu, de;

        Rational(long n, long d) {
            nu = n; 
            de = d;
            if (de < 0) {
                nu = -nu; 
                de = -de; 
            }
        }

        Rational add(Rational b) {
            return new Rational(nu * b.de + de * b.nu, de * b.de);
        }

        Rational subtract(Rational b) {
            return new Rational(nu * b.de - de * b.nu, de * b.de);
        }

        Rational multiply(Rational b) {
            return new Rational(nu * b.nu, de * b.de);
        }

        Rational divide(Rational b) {
            return new Rational(nu * b.de, de * b.nu);
        }

        boolean equals(Rational b) {
            return nu * b.de == b.nu * de;
        }

        boolean lessThan(Rational b) {
            return nu * b.de < b.nu * de;
        }
    }

    static class SegNode {
        Mint[] prod = new Mint[2];
        Mint sumlr;
        boolean ident;

        SegNode() {
            prod[L] = new Mint(1);
            prod[R] = new Mint(1);
            sumlr = new Mint(1);
            ident = true;
        }
    }

    static class MulSegTree {
        static final int SEGSZ = mn;
        int segn = SEGSZ;
        SegNode[] t = new SegNode[2 * SEGSZ];
        SegNode identity = new SegNode();

        MulSegTree() {
            for (int i = 0; i < 2 * SEGSZ; i++) {
                t[i] = new SegNode();
            }
        }

        SegNode combine(SegNode x, SegNode y) {
            if (x.ident) return y;
            if (y.ident) return x;
            SegNode ans = new SegNode();
            for (int d = 0; d < 2; d++) {
                ans.prod[d] = x.prod[d].multiply(y.prod[d]);
            }
            ans.sumlr = x.sumlr.multiply(y.prod[R]).add(x.prod[L].multiply(y.sumlr)).subtract(x.prod[L].multiply(y.prod[R]));
            ans.ident = false;
            return ans;
        }

        void init(int n) {
            segn = n;
        }

        void build() {
            for (int i = segn - 1; i > 0; --i) {
                t[i] = combine(t[i << 1], t[i << 1 | 1]);
            }
        }

        void setBeforeBuild(int p, SegNode value) {
            t[segn + p] = value;
        }

        void set(int p, SegNode value) {
            for (t[p += segn] = value; p >>= 1; ) {
                t[p] = combine(t[p << 1], t[p << 1 | 1]);
            }
        }

        SegNode query(int l, int r) {
            if (l > r) return identity;
            r++;
            SegNode resl = identity, resr = identity;
            for (l += segn, r += segn; l < r; l >>= 1, r >>= 1) {
                if (l & 1) resl = combine(resl, t[l++]);
                if (r & 1) resr = combine(t[--r], resr);
            }
            return combine(resl, resr);
        }
    }

    static class Group {
        int l, r, forceDir;

        Group(int l, int r, int forceDir) {
            this.l = l;
            this.r = r;
            this.forceDir = forceDir;
        }

        @Override
        public boolean equals(Object obj) {
            if (this == obj) return true;
            if (!(obj instanceof Group)) return false;
            Group other = (Group) obj;
            return this.l == other.l && this.r == other.r && this.forceDir == other.forceDir;
        }

        @Override
        public int hashCode() {
            return Objects.hash(l, r, forceDir);
        }
    }

    static class GroupSet {
        Set<Group> s = new HashSet<>();

        void init(int n) {
            for (int x = 0; x < n; x++) {
                ufreset(x);
            }
        }

        void ufreset(int x) {
            s.add(new Group(x, x, -1));
        }

        Group getData(int x) {
            for (Group g : s) {
                if (g.l <= x && g.r >= x) {
                    return g;
                }
            }
            return null;
        }

        void funion(int x, int y) {
            Group g1 = getData(x);
            Group g2 = getData(y);
            if (g1 != null && g2 != null && !g1.equals(g2)) {
                Group combined = new Group(Math.min(g1.l, g2.l), Math.max(g1.r, g2.r), Math.max(g1.forceDir, g2.forceDir));
                s.remove(g1);
                s.remove(g2);
                s.add(combined);
            }
        }

        void split(int pl, int pr, int dl, int dr) {
            Group g = getData(pl);
            s.remove(g);
            s.add(new Group(g.l, pl, dl));
            s.add(new Group(pr, g.r, dr));
        }

        int getDir(int x) {
            return getData(x).forceDir;
        }
    }

    static class Collision implements Comparable<Collision> {
        Rational collideTime;
        int pos;
        int dirL;
        int dirR;

        Collision(Rational collideTime, int pos, int dirL, int dirR) {
            this.collideTime = collideTime;
            this.pos = pos;
            this.dirL = dirL;
            this.dirR = dirR;
        }

        @Override
        public int compareTo(Collision other) {
            return this.collideTime.lessThan(other.collideTime) ? -1 : 1;
        }
    }

    static Mint probNoCollide = new Mint(1);

    static Mint probForce(int dir, int l, int r) {
        return seg.query(l, r).prod[dir];
    }

    static Mint probSumlr(int l, int r) {
        return seg.query(l, r).sumlr;
    }

    static Mint getProdOfRange(int l, int r) {
        int lo = INF, hi = -INF;
        Mint ans = new Mint(1);
        for (int pos = l; pos <= r;) {
            Group dat = gs.getData(pos);
            lo = Math.min(lo, dat.l);
            hi = Math.max(hi, dat.r);
            Mint mult;
            if (dat.forceDir == UNDEF) {
                mult = seg.query(dat.l, dat.r).sumlr;
            } else {
                mult = seg.query(dat.l, dat.r).prod[dat.forceDir];
            }
            ans = ans.multiply(mult);
            pos = dat.r + 1;
        }
        return ans;
    }

    static void mergeFates(int l, int r) {
        Group dl = gs.getData(l);
        Group dr = gs.getData(r);
        if ((dl.forceDir == R && dr.forceDir == -1) ||
            (dl.forceDir == -1 && dr.forceDir == L) ||
            (dl.forceDir == -1 && dr.forceDir == -1)) {
            Mint den = getProdOfRange(dl.l, dr.r);
            gs.funion(l, r);
            Mint num = getProdOfRange(dl.l, dr.r);
            probNoCollide = probNoCollide.multiply(num.divide(den));
        } else if (dl.forceDir == L && dr.forceDir == -1) {
            // Handle case
        } else if (dl.forceDir == -1 && dr.forceDir == R) {
            // Handle case
        } else if (dl.forceDir >= 0 && dr.forceDir >= 0) {
            if (dl.forceDir == dr.forceDir) {
                // Handle case
            } else {
                probNoCollide = new Mint(0);
            }
        } else {
            throw new AssertionError();
        }
    }

    static Mint rat2Mint(Rational r) {
        return new Mint(r.nu).divide(new Mint(r.de));
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        for (int i = 0; i < n; i++) {
            vpos[i] = Long.parseLong(br.readLine());
            v[i] = Long.parseLong(br.readLine());
            probBallDir[i][R] = new Mint(Long.parseLong(br.readLine())).divide(new Mint(100));
            probBallDir[i][L] = new Mint(1).subtract(probBallDir[i][R]);
        }
        gs.init(n);
        seg.init(n);
        for (int pos = 0; pos < n; pos++) {
            seg.setBeforeBuild(pos, new SegNode() {{
                prod[L] = probBallDir[pos][L];
                prod[R] = probBallDir[pos][R];
                sumlr = probBallDir[pos][L].add(probBallDir[pos][R]);
                ident = false;
            }});
        }
        seg.build();

        List<Collision> collisions = new ArrayList<>();
        for (int i = 0; i < n - 1; i++) {
            long dist = vpos[i + 1] - vpos[i];
            Rational rlCollideTime = new Rational(dist, v[i + 1] + v[i]);
            collisions.add(new Collision(rlCollideTime, i, R, L));

            if (v[i] > v[i + 1]) {
                Rational rrCollideTime = new Rational(dist, v[i] - v[i + 1]);
                collisions.add(new Collision(rrCollideTime, i, R, R));
            }

            if (v[i] < v[i + 1]) {
                Rational llCollideTime = new Rational(dist, v[i + 1] - v[i]);
                collisions.add(new Collision(llCollideTime, i, L, L));
            }
        }
        Collections.sort(collisions);
        Mint finalSum = new Mint(0);
        for (Collision c : collisions) {
            int pos = c.pos;
            Mint prevProbNoCollide = probNoCollide;

            int dl = gs.getDir(c.pos);
            int dr = gs.getDir(c.pos + 1);

            if (dl != UNDEF && dl != c.dirL) continue;
            if (dr != UNDEF && dr != c.dirR) continue;
            if (c.dirL == R && c.dirR == L) {
                mergeFates(pos, pos + 1);
            } else if (c.dirL == R && c.dirR == R) {
                if (dl == R) {
                    probNoCollide = new Mint(0);
                } else {
                    Mint den = getProdOfRange(pos, pos + 1);
                    gs.split(c.pos, c.pos + 1, L, UNDEF);
                    Mint num = getProdOfRange(pos, pos + 1);
                    probNoCollide = probNoCollide.multiply(num.divide(den));
                }
            } else if (c.dirL == L && c.dirR == L) {
                if (dr == L) {
                    probNoCollide = new Mint(0);
                } else {
                    Mint den = getProdOfRange(pos, pos + 1);
                    gs.split(c.pos, c.pos + 1, UNDEF, R);
                    Mint num = getProdOfRange(pos, pos + 1);
                    probNoCollide = probNoCollide.multiply(num.divide(den));
                }
            } else {
                throw new AssertionError();
            }

            Mint collideTime = rat2Mint(c.collideTime);
            finalSum = finalSum.add(collideTime.multiply(prevProbNoCollide.subtract(probNoCollide)));
            if (probNoCollide.equals(new Mint(0))) break;
        }
        System.out.println(finalSum);
    }
}
