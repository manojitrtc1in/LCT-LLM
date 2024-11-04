import java.util.*;
import java.io.*;

class Mint {
    static final int MOD = 998244353;
    private long x;

    public Mint() {
        this.x = 0;
    }

    public Mint(long sig) {
        sig = norm(sig);
        this.x = sig;
    }

    private int norm(int x) {
        if (x < 0) x += MOD;
        return x;
    }

    public int get() {
        return (int) x;
    }

    public Mint add(Mint that) {
        return new Mint(this.x + that.x >= MOD ? this.x + that.x - MOD : this.x + that.x);
    }

    public Mint subtract(Mint that) {
        return new Mint(this.x + MOD - that.x >= MOD ? this.x + MOD - that.x - MOD : this.x + MOD - that.x);
    }

    public Mint multiply(Mint that) {
        return new Mint((this.x * that.x) % MOD);
    }

    public Mint divide(Mint that) {
        return this.multiply(that.inverse());
    }

    public Mint inverse() {
        long a = x, b = MOD, u = 1, v = 0;
        while (b != 0) {
            long t = a / b;
            a -= t * b; 
            long temp = a; 
            a = b; 
            b = temp;
            u -= t * v; 
            temp = u; 
            u = v; 
            v = temp;
        }
        if (u < 0) u += MOD;
        return new Mint(u);
    }

    public boolean equals(Mint that) {
        return this.x == that.x;
    }

    public Mint pow(long k) {
        Mint a = this;
        Mint r = new Mint(1);
        while (k > 0) {
            if ((k & 1) == 1) r = r.multiply(a);
            a = a.multiply(a);
            k >>= 1;
        }
        return r;
    }
}

class Id5 {
    long nu, de;

    public Id5(long n, long d) {
        nu = n; 
        de = d;
        if (de < 0) { nu = -nu; de = -de; }
    }

    public Id5 add(Id5 b) {
        return new Id5(nu * b.de + de * b.nu, de * b.de);
    }

    public Id5 subtract(Id5 b) {
        return new Id5(nu * b.de - de * b.nu, de * b.de);
    }

    public Id5 multiply(Id5 b) {
        return new Id5(nu * b.nu, de * b.de);
    }

    public Id5 divide(Id5 b) {
        return new Id5(nu * b.de, de * b.nu);
    }

    public boolean equals(Id5 b) {
        return nu * b.de == b.nu * de;
    }

    public boolean equals(long k) {
        return nu == k * de;
    }

    public boolean lessThan(Id5 b) {
        return nu * b.de < b.nu * de;
    }
}

class SegNode {
    Mint[] prod = new Mint[2];
    Mint sumlr;
    boolean ident;

    public SegNode() {
        prod[0] = new Mint(1);
        prod[1] = new Mint(1);
        sumlr = new Mint(1);
        ident = true;
    }
}

class MulSegTree {
    static final int SEGSZ = 100004;
    int segn;
    SegNode[] t = new SegNode[2 * SEGSZ];
    SegNode identity = new SegNode();

    public void init(int n) {
        this.segn = n;
    }

    public void build() {
        for (int i = segn - 1; i > 0; --i) {
            t[i] = combine(t[i << 1], t[i << 1 | 1]);
        }
    }

    public void setBeforeBuild(int p, SegNode value) {
        t[segn + p] = value;
    }

    public void set(int p, SegNode value) {
        for (t[p += segn] = value; p >>= 1; ) {
            t[p] = combine(t[p << 1], t[p << 1 | 1]);
        }
    }

    public SegNode query(int l, int r) {
        if (l > r) return identity;
        r++;
        SegNode resl = identity, resr = identity;
        for (l += segn, r += segn; l < r; l >>= 1, r >>= 1) {
            if ((l & 1) == 1) resl = combine(resl, t[l++]);
            if ((r & 1) == 1) resr = combine(t[--r], resr);
        }
        return combine(resl, resr);
    }

    private SegNode combine(SegNode x, SegNode y) {
        if (x.ident) return y;
        if (y.ident) return x;
        SegNode ans = new SegNode();
        for (int d = 0; d < 2; d++) {
            ans.prod[d] = x.prod[d].multiply(y.prod[d]);
        }
        ans.sumlr = x.sumlr.multiply(y.prod[1]).add(x.prod[0].multiply(y.sumlr)).subtract(x.prod[0].multiply(y.prod[1]));
        ans.ident = false;
        return ans;
    }
}

class Group {
    int l, r, forceDir;

    public boolean lessThan(Group other) {
        return (r < other.r) || (r == other.r && l < other.l) || (r == other.r && l == other.l && forceDir < other.forceDir);
    }
}

class GroupSet {
    Set<Group> s = new HashSet<>();

    public Group combine(Group x, Group y) {
        if (Math.min(x.forceDir, y.forceDir) >= 0) {
            assert x.forceDir == y.forceDir;
        }
        return new Group(Math.min(x.l, y.l), Math.max(x.r, y.r), Math.max(x.forceDir, y.forceDir));
    }

    public Group getInitialValue(int x) {
        return new Group(x, x, -1);
    }

    public void ufreset(int x) {
        s.add(getInitialValue(x));
    }

    public void init(int n) {
        for (int x = 0; x < n; x++) {
            ufreset(x);
        }
    }

    public Group lb(int x) {
        for (Group group : s) {
            if (group.l <= x && group.r >= x) {
                return group;
            }
        }
        return null;
    }

    public void funion(int x, int y) {
        Group it1 = lb(x);
        Group it2 = lb(y);
        if (it1 != it2) {
            Group combined = combine(it1, it2);
            s.remove(it1);
            s.remove(it2);
            s.add(combined);
        }
    }

    public Group getData(int x) {
        return lb(x);
    }

    public void setData(int x, Group dat) {
        Group it = lb(x);
        s.remove(it);
        s.add(dat);
    }

    public void split(int pl, int pr, int dl, int dr) {
        assert dl >= -1 && dl < 2;
        assert dr >= -1 && dr < 2;
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

    public int getDir(int x) {
        return getData(x).forceDir;
    }
}

public class b3fffc8cb6ef550c2d3de05045f65096xcodeeval_processed_4000.json {
    static final int mn = 100004;
    static int[] vpos = new int[mn], v = new int[mn];
    static Mint[][] probBallDir = new Mint[mn][2];
    static GroupSet gs = new GroupSet();
    static MulSegTree seg = new MulSegTree();
    static Mint id10 = new Mint(1);

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            vpos[i] = Integer.parseInt(br.readLine());
            v[i] = Integer.parseInt(br.readLine());
            probBallDir[i][1] = new Mint(Integer.parseInt(br.readLine())).divide(new Mint(100));
            probBallDir[i][0] = new Mint(1).subtract(probBallDir[i][1]);
        }
        gs.init(n);
        seg.init(n);
        for (int pos = 0; pos < n; pos++) {
            seg.setBeforeBuild(pos, new SegNode() {{
                prod[0] = probBallDir[pos][0];
                prod[1] = probBallDir[pos][1];
                sumlr = probBallDir[pos][0].add(probBallDir[pos][1]);
                ident = false;
            }});
        }
        seg.build();

        List<Collision> collisions = new ArrayList<>();
        for (int i = 0; i < n - 1; i++) {
            int dist = vpos[i + 1] - vpos[i];
            Id5 id8 = new Id5(dist, v[i + 1] + v[i]);
            collisions.add(new Collision(id8, i, 1, 0));

            if (v[i] > v[i + 1]) {
                Id5 id6 = new Id5(dist, v[i] - v[i + 1]);
                collisions.add(new Collision(id6, i, 1, 1));
            }

            if (v[i] < v[i + 1]) {
                Id5 id11 = new Id5(dist, v[i + 1] - v[i]);
                collisions.add(new Collision(id11, i, 0, 0));
            }
        }
        Collections.sort(collisions);
        Mint finalSum = new Mint(0);
        for (Collision c : collisions) {
            int pos = c.pos;
            Mint id9 = id10;

            int dl = gs.getDir(c.pos);
            int dr = gs.getDir(c.pos + 1);

            if (dl != -1 && dl != c.dirL) continue;
            if (dr != -1 && dr != c.dirR) continue;
            if (c.dirL == 1 && c.dirR == 0) {
                id12(pos, pos + 1);
            } else if (c.dirL == 1 && c.dirR == 1) {
                if (dl == 1) {
                    id10 = new Mint(0);
                } else {
                    Mint den = id2(pos, pos + 1);
                    gs.split(c.pos, c.pos + 1, 0, -1);
                    Mint num = id2(pos, pos + 1);
                    id10 = id10.multiply(num.divide(den));
                }
            } else if (c.dirL == 0 && c.dirR == 0) {
                if (dr == 0) {
                    id10 = new Mint(0);
                } else {
                    Mint den = id2(pos, pos + 1);
                    gs.split(c.pos, c.pos + 1, -1, 1);
                    Mint num = id2(pos, pos + 1);
                    id10 = id10.multiply(num.divide(den));
                }
            } else {
                assert false;
            }
            gs.check();
            Mint id7 = id3(c.id7);
            finalSum = finalSum.add(id7.multiply(id9.subtract(id10)));
            if (id10.equals(new Mint(0))) break;
        }
        System.out.println(finalSum.get());
    }

    static class Collision implements Comparable<Collision> {
        Id5 id7;
        int pos;
        int dirL;
        int dirR;

        public Collision(Id5 id7, int pos, int dirL, int dirR) {
            this.id7 = id7;
            this.pos = pos;
            this.dirL = dirL;
            this.dirR = dirR;
        }

        @Override
        public int compareTo(Collision other) {
            return this.id7.lessThan(other.id7) ? -1 : 1;
        }
    }

    static Mint probForce(int dir, int l, int r) {
        assert dir >= 0 && dir < 2;
        return seg.query(l, r).prod[dir];
    }

    static Mint id1(int l, int r) {
        return seg.query(l, r).sumlr;
    }

    static Mint id2(int l, int r) {
        int lo = Integer.MAX_VALUE, hi = Integer.MIN_VALUE;
        Mint ans = new Mint(1);
        gs.check();
        for (int pos = l; pos <= r; ) {
            Group dat = gs.getData(pos);
            lo = Math.min(lo, dat.l);
            hi = Math.max(hi, dat.r);
            Mint mult;
            if (dat.forceDir == -1) {
                mult = seg.query(dat.l, dat.r).sumlr;
            } else {
                mult = seg.query(dat.l, dat.r).prod[dat.forceDir];
            }
            ans = ans.multiply(mult);
            pos = dat.r + 1;
        }
        return ans;
    }

    static void id12(int l, int r) {
        Group dl = gs.getData(l);
        Group dr = gs.getData(r);
        if ((dl.forceDir == 1 && dr.forceDir == -1) ||
            (dl.forceDir == -1 && dr.forceDir == 0) ||
            (dl.forceDir == -1 && dr.forceDir == -1)) {
            Mint den = id2(dl.l, dr.r);
            gs.funion(l, r);
            Mint num = id2(dl.l, dr.r);
            id10 = id10.multiply(num.divide(den));
        } else if (dl.forceDir == 0 && dr.forceDir == -1) {
            // Do nothing
        } else if (dl.forceDir == -1 && dr.forceDir == 1) {
            // Do nothing
        } else if (dl.forceDir >= 0 && dr.forceDir >= 0) {
            if (dl.forceDir == dr.forceDir) {
                // Do nothing
            } else {
                id10 = new Mint(0);
            }
        } else {
            assert false;
        }
    }

    static Mint id3(Id5 r) {
        return new Mint(r.nu).divide(new Mint(r.de));
    }
}
