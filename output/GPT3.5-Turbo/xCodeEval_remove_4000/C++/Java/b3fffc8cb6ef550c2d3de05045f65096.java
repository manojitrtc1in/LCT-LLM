import java.util.*;
import java.io.*;

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

    static class mint {
        int x;

        private int _norm(int x) {
            if (x < 0) x += MOD;
            return x;
        }

        public mint() {
            x = 0;
        }

        public mint(int sig) {
            sig = _norm(sig);
            x = sig;
        }

        public mint(long sig) {
            sig = _norm(sig % MOD);
            x = (int) sig;
        }

        public int get() {
            return x;
        }

        public mint add(mint that) {
            if ((x += that.x) >= MOD) x -= MOD;
            return this;
        }

        public mint subtract(mint that) {
            if ((x += MOD - that.x) >= MOD) x -= MOD;
            return this;
        }

        public mint multiply(mint that) {
            x = (int) ((long) x * that.x % MOD);
            return this;
        }

        public mint divide(mint that) {
            return this.multiply(that.inverse());
        }

        public mint add(int that) {
            that = _norm(that);
            if ((x += that) >= MOD) x -= MOD;
            return this;
        }

        public mint subtract(int that) {
            that = _norm(that);
            if ((x += MOD - that) >= MOD) x -= MOD;
            return this;
        }

        public mint multiply(int that) {
            that = _norm(that);
            x = (int) ((long) x * that % MOD);
            return this;
        }

        public mint divide(int that) {
            that = _norm(that);
            return this.multiply(new mint(that).inverse());
        }

        public mint add(long that) {
            that = _norm(that);
            if ((x += that) >= MOD) x -= MOD;
            return this;
        }

        public mint subtract(long that) {
            that = _norm(that);
            if ((x += MOD - that) >= MOD) x -= MOD;
            return this;
        }

        public mint multiply(long that) {
            that = _norm(that);
            x = (int) ((long) x * that % MOD);
            return this;
        }

        public mint divide(long that) {
            that = _norm(that);
            return this.multiply(new mint(that).inverse());
        }

        public mint inverse() {
            int a = x, b = MOD, u = 1, v = 0;
            while (b != 0) {
                int t = a / b;
                a -= t * b;
                int temp = a;
                a = b;
                b = temp;
                u -= t * v;
                int temp2 = u;
                u = v;
                v = temp2;
            }
            if (u < 0) u += MOD;
            mint res = new mint();
            res.x = u;
            return res;
        }

        public boolean equals(mint that) {
            return x == that.x;
        }

        public boolean notEquals(mint that) {
            return x != that.x;
        }

        public mint negate() {
            mint t = new mint();
            t.x = x == 0 ? 0 : MOD - x;
            return t;
        }

        public mint power(long k) {
            mint a = new mint(this.x);
            mint r = new mint(1);
            while (k != 0) {
                if ((k & 1) == 1) r.multiply(a);
                a.multiply(a);
                k >>= 1;
            }
            return r;
        }
    }

    static class id5 {
        long nu, de;

        public id5(long n, long d) {
            nu = n;
            de = d;
            if (de < 0) {
                nu = -nu;
                de = -de;
            }
        }

        public id5 add(id5 b) {
            return new id5(nu * b.de + de * b.nu, de * b.de);
        }

        public id5 subtract(id5 b) {
            return new id5(nu * b.de - de * b.nu, de * b.de);
        }

        public id5 negate() {
            return new id5(-nu, de);
        }

        public id5 multiply(id5 b) {
            return new id5(nu * b.nu, de * b.de);
        }

        public id5 divide(id5 b) {
            return new id5(nu * b.de, de * b.nu);
        }

        public boolean equals(id5 b) {
            return nu * b.de == b.nu * de;
        }

        public boolean equals(long k) {
            return nu == k * de;
        }

        public boolean lessThan(id5 b) {
            return nu * b.de < b.nu * de;
        }

        public boolean lessThanOrEqual(id5 b) {
            return nu * b.de <= b.nu * de;
        }

        public boolean greaterThan(id5 b) {
            return nu * b.de > b.nu * de;
        }

        public boolean greaterThanOrEqual(id5 b) {
            return nu * b.de >= b.nu * de;
        }
    }

    static class SegNode {
        mint[] prod;
        mint sumlr;
        boolean ident;

        public SegNode() {
            prod = new mint[2];
            sumlr = new mint();
            ident = true;
        }
    }

    static class MulSegTree {
        static final int SEGSZ = 100004;
        int segn;
        SegNode[] t;
        SegNode identity;

        public MulSegTree() {
            segn = SEGSZ;
            t = new SegNode[2 * SEGSZ];
            identity = new SegNode();
        }

        public SegNode combine(SegNode x, SegNode y) {
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

        public void init(int n) {
            segn = n;
        }

        public void build() {
            int n = segn;
            for (int i = n - 1; i > 0; --i) t[i] = combine(t[i << 1], t[i << 1 | 1]);
        }

        public void setBeforeBuild(int p, SegNode value) {
            t[segn + p] = value;
        }

        public void sset(int p, SegNode value) {
            int n = segn;
            for (t[p += n] = value; p >>= 1; ) t[p] = combine(t[p << 1], t[p << 1 | 1]);
        }

        public SegNode query(int l, int r) {
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

        public Group(int l, int r, int forceDir) {
            this.l = l;
            this.r = r;
            this.forceDir = forceDir;
        }

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

    static int MOD = 998244353;
    static int UNDEF = -1;
    static int INF = 1 << 30;
    static int L = 0;
    static int R = 1;

    static int rint(FastReader in) {
        return in.nextInt();
    }

    static char rch(FastReader in) {
        return in.next().charAt(0);
    }

    static long rlong(FastReader in) {
        return in.nextLong();
    }

    static mint probForce(int dir, int l, int r, MulSegTree seg) {
        assert (0 <= dir && dir < 2);
        return seg.query(l, r).prod[dir];
    }

    static mint id1(int l, int r, MulSegTree seg) {
        return seg.query(l, r).sumlr;
    }

    static mint id2(int l, int r, GroupSet gs, MulSegTree seg) {
        int lo = INF, hi = -INF;
        mint ans = new mint(1);
        gs.check();
        for (int pos = l; pos <= r; ) {
            Group dat = gs.getData(pos);
            chkmin(lo, dat.l);
            chkmax(hi, dat.r);
            mint mult;
            if (dat.forceDir == UNDEF) {
                mult = seg.query(dat.l, dat.r).sumlr;
            } else {
                mult = seg.query(dat.l, dat.r).prod[dat.forceDir];
            }
            ans.multiply(mult);
            pos = dat.r + 1;
        }
        return ans;
    }

    static void id12(int l, int r, GroupSet gs, mint id10, mint id2) {
        Group dl = gs.getData(l);
        Group dr = gs.getData(r);
        if ((dl.forceDir == R && dr.forceDir == -1) ||
                (dl.forceDir == -1 && dr.forceDir == L) ||
                (dl.forceDir == -1 && dr.forceDir == -1)) {
            mint den = id2(dl.l, dr.r, gs, seg);
            gs.funion(l, r);
            mint num = id2(dl.l, dr.r, gs, seg);
            id10.multiply(num.divide(den));
        } else if (dl.forceDir == L && dr.forceDir == -1) {

        } else if (dl.forceDir == -1 && dr.forceDir == R) {

        } else if (dl.forceDir >= 0 && dr.forceDir >= 0) {
            if (dl.forceDir == dr.forceDir) {

            } else {
                id10.x = 0;
            }
        } else {
            assert (false);
        }
    }

    static mint id3(id5 r) {
        return new mint((int) r.nu).divide(new mint((int) r.de));
    }

    static void chkmin(int[] aa, int bb) {
        aa[0] = Math.min(aa[0], bb);
    }

    static void chkmax(int[] aa, int bb) {
        aa[0] = Math.max(aa[0], bb);
    }

    static void chkmin(int aa[], int bb[]) {
        aa[0] = Math.min(aa[0], bb[0]);
    }

    static void chkmax(int aa[], int bb[]) {
        aa[0] = Math.max(aa[0], bb[0]);
    }

    static void chkmin(int aa[], int bb[], int cc[]) {
        aa[0] = Math.min(aa[0], Math.min(bb[0], cc[0]));
    }

    static void chkmax(int aa[], int bb[], int cc[]) {
        aa[0] = Math.max(aa[0], Math.max(bb[0], cc[0]));
    }

    static void chkmin(int aa[], int bb[], int cc[], int dd[]) {
        aa[0] = Math.min(aa[0], Math.min(bb[0], Math.min(cc[0], dd[0])));
    }

    static void chkmax(int aa[], int bb[], int cc[], int dd[]) {
        aa[0] = Math.max(aa[0], Math.max(bb[0], Math.max(cc[0], dd[0])));
    }

    static void chkmin(long aa[], long bb) {
        aa[0] = Math.min(aa[0], bb);
    }

    static void chkmax(long aa[], long bb) {
        aa[0] = Math.max(aa[0], bb);
    }

    static void chkmin(long aa[], long bb[]) {
        aa[0] = Math.min(aa[0], bb[0]);
    }

    static void chkmax(long aa[], long bb[]) {
        aa[0] = Math.max(aa[0], bb[0]);
    }

    static void chkmin(long aa[], long bb[], long cc[]) {
        aa[0] = Math.min(aa[0], Math.min(bb[0], cc[0]));
    }

    static void chkmax(long aa[], long bb[], long cc[]) {
        aa[0] = Math.max(aa[0], Math.max(bb[0], cc[0]));
    }

    static void chkmin(long aa[], long bb[], long cc[], long dd[]) {
        aa[0] = Math.min(aa[0], Math.min(bb[0], Math.min(cc[0], dd[0])));
    }

    static void chkmax(long aa[], long bb[], long cc[], long dd[]) {
        aa[0] = Math.max(aa[0], Math.max(bb[0], Math.max(cc[0], dd[0])));
    }

    static void chkmin(double aa[], double bb) {
        aa[0] = Math.min(aa[0], bb);
    }

    static void chkmax(double aa[], double bb) {
        aa[0] = Math.max(aa[0], bb);
    }

    static void chkmin(double aa[], double bb[]) {
        aa[0] = Math.min(aa[0], bb[0]);
    }

    static void chkmax(double aa[], double bb[]) {
        aa[0] = Math.max(aa[0], bb[0]);
    }

    static void chkmin(double aa[], double bb[], double cc[]) {
        aa[0] = Math.min(aa[0], Math.min(bb[0], cc[0]));
    }

    static void chkmax(double aa[], double bb[], double cc[]) {
        aa[0] = Math.max(aa[0], Math.max(bb[0], cc[0]));
    }

    static void chkmin(double aa[], double bb[], double cc[], double dd[]) {
        aa[0] = Math.min(aa[0], Math.min(bb[0], Math.min(cc[0], dd[0])));
    }

    static void chkmax(double aa[], double bb[], double cc[], double dd[]) {
        aa[0] = Math.max(aa[0], Math.max(bb[0], Math.max(cc[0], dd[0])));
    }

    static void chkmin(mint aa, mint bb) {
        if (aa.x > bb.x) aa.x = bb.x;
    }

    static void chkmax(mint aa, mint bb) {
        if (aa.x < bb.x) aa.x = bb.x;
    }

    static void chkmin(mint aa, int bb) {
        if (aa.x > bb) aa.x = bb;
    }

    static void chkmax(mint aa, int bb) {
        if (aa.x < bb) aa.x = bb;
    }

    static void chkmin(mint aa, long bb) {
        if (aa.x > bb) aa.x = bb;
    }

    static void chkmax(mint aa, long bb) {
        if (aa.x < bb) aa.x = bb;
    }

    static void chkmin(mint aa, double bb) {
        if (aa.x > bb) aa.x = (int) bb;
    }

    static void chkmax(mint aa, double bb) {
        if (aa.x < bb) aa.x = (int) bb;
    }

    static void chkmin(mint aa, mint bb, mint cc) {
        chkmin(aa, bb);
        chkmin(aa, cc);
    }

    static void chkmax(mint aa, mint bb, mint cc) {
        chkmax(aa, bb);
        chkmax(aa, cc);
    }

    static void chkmin(mint aa, mint bb, mint cc, mint dd) {
        chkmin(aa, bb);
        chkmin(aa, cc);
        chkmin(aa, dd);
    }

    static void chkmax(mint aa, mint bb, mint cc, mint dd) {
        chkmax(aa, bb);
        chkmax(aa, cc);
        chkmax(aa, dd);
    }

    static void chkmin(int aa[], int bb, int cc) {
        chkmin(aa, bb);
        chkmin(aa, cc);
    }

    static void chkmax(int aa[], int bb, int cc) {
        chkmax(aa, bb);
        chkmax(aa, cc);
    }

    static void chkmin(int aa[], int bb, int cc, int dd) {
        chkmin(aa, bb);
        chkmin(aa, cc);
        chkmin(aa, dd);
    }

    static void chkmax(int aa[], int bb, int cc, int dd) {
        chkmax(aa, bb);
        chkmax(aa, cc);
        chkmax(aa, dd);
    }

    static void chkmin(long aa[], long bb, long cc) {
        chkmin(aa, bb);
        chkmin(aa, cc);
    }

    static void chkmax(long aa[], long bb, long cc) {
        chkmax(aa, bb);
        chkmax(aa, cc);
    }

    static void chkmin(long aa[], long bb, long cc, long dd) {
        chkmin(aa, bb);
        chkmin(aa, cc);
        chkmin(aa, dd);
    }

    static void chkmax(long aa[], long bb, long cc, long dd) {
        chkmax(aa, bb);
        chkmax(aa, cc);
        chkmax(aa, dd);
    }

    static void chkmin(double aa[], double bb, double cc) {
        chkmin(aa, bb);
        chkmin(aa, cc);
    }

    static void chkmax(double aa[], double bb, double cc) {
        chkmax(aa, bb);
        chkmax(aa, cc);
    }

    static void chkmin(double aa[], double bb, double cc, double dd) {
        chkmin(aa, bb);
        chkmin(aa, cc);
        chkmin(aa, dd);
    }

    static void chkmax(double aa[], double bb, double cc, double dd) {
        chkmax(aa, bb);
        chkmax(aa, cc);
        chkmax(aa, dd);
    }

    static void chkmin(mint aa[], mint bb) {
        for (int i = 0; i < aa.length; i++) {
            chkmin(aa[i], bb);
        }
    }

    static void chkmax(mint aa[], mint bb) {
        for (int i = 0; i < aa.length; i++) {
            chkmax(aa[i], bb);
        }
    }

    static void chkmin(mint aa[], int bb) {
        for (int i = 0; i < aa.length; i++) {
            chkmin(aa[i], bb);
        }
    }

    static void chkmax(mint aa[], int bb) {
        for (int i = 0; i < aa.length; i++) {
            chkmax(aa[i], bb);
        }
    }

    static void chkmin(mint aa[], long bb) {
        for (int i = 0; i < aa.length; i++) {
            chkmin(aa[i], bb);
        }
    }

    static void chkmax(mint aa[], long bb) {
        for (int i = 0; i < aa.length; i++) {
            chkmax(aa[i], bb);
        }
    }

    static void chkmin(mint aa[], double bb) {
        for (int i = 0; i < aa.length; i++) {
            chkmin(aa[i], bb);
        }
    }

    static void chkmax(mint aa[], double bb) {
        for (int i = 0; i < aa.length; i++) {
            chkmax(aa[i], bb);
        }
    }

    static void chkmin(mint aa[], mint bb, mint cc) {
        chkmin(aa, bb);
        chkmin(aa, cc);
    }

    static void chkmax(mint aa[], mint bb, mint cc) {
        chkmax(aa, bb);
        chkmax(aa, cc);
    }

    static void chkmin(mint aa[], mint bb, mint cc, mint dd) {
        chkmin(aa, bb);
        chkmin(aa, cc);
        chkmin(aa, dd);
    }

    static void chkmax(mint aa[], mint bb, mint cc, mint dd) {
        chkmax(aa, bb);
        chkmax(aa, cc);
        chkmax(aa, dd);
    }

    static void chkmin(int aa[], int bb, int cc[]) {
        chkmin(aa, bb);
        chkmin(aa, cc);
    }

    static void chkmax(int aa[], int bb, int cc[]) {
        chkmax(aa, bb);
        chkmax(aa, cc);
    }

    static void chkmin(int aa[], int bb, int cc[], int dd[]) {
        chkmin(aa, bb);
        chkmin(aa, cc);
        chkmin(aa, dd);
    }

    static void chkmax(int aa[], int bb, int cc[], int dd[]) {
        chkmax(aa, bb);
        chkmax(aa, cc);
        chkmax(aa, dd);
    }

    static void chkmin(long aa[], long bb, long cc[]) {
        chkmin(aa, bb);
        chkmin(aa, cc);
    }

    static void chkmax(long aa[], long bb, long cc[]) {
        chkmax(aa, bb);
        chkmax(aa, cc);
    }

    static void chkmin(long aa[], long bb, long cc[], long dd[]) {
        chkmin(aa, bb);
        chkmin(aa, cc);
        chkmin(aa, dd);
    }

    static void chkmax(long aa[], long bb, long cc[], long dd[]) {
        chkmax(aa, bb);
        chkmax(aa, cc);
        chkmax(aa, dd);
    }

    static void chkmin(double aa[], double bb, double cc[]) {
        chkmin(aa, bb);
        chkmin(aa, cc);
    }

    static void chkmax(double aa[], double bb, double cc[]) {
        chkmax(aa, bb);
        chkmax(aa, cc);
    }

    static void chkmin(double aa[], double bb, double cc[], double dd[]) {
        chkmin(aa, bb);
        chkmin(aa, cc);
        chkmin(aa, dd);
    }

    static void chkmax(double aa[], double bb, double cc[], double dd[]) {
        chkmax(aa, bb);
        chkmax(aa, cc);
        chkmax(aa, dd);
    }

    static void chkmin(mint aa[], mint bb[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmin(aa[i], bb[i]);
        }
    }

    static void chkmax(mint aa[], mint bb[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmax(aa[i], bb[i]);
        }
    }

    static void chkmin(mint aa[], int bb[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmin(aa[i], bb[i]);
        }
    }

    static void chkmax(mint aa[], int bb[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmax(aa[i], bb[i]);
        }
    }

    static void chkmin(mint aa[], long bb[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmin(aa[i], bb[i]);
        }
    }

    static void chkmax(mint aa[], long bb[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmax(aa[i], bb[i]);
        }
    }

    static void chkmin(mint aa[], double bb[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmin(aa[i], bb[i]);
        }
    }

    static void chkmax(mint aa[], double bb[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmax(aa[i], bb[i]);
        }
    }

    static void chkmin(mint aa[], mint bb[], mint cc[]) {
        chkmin(aa, bb);
        chkmin(aa, cc);
    }

    static void chkmax(mint aa[], mint bb[], mint cc[]) {
        chkmax(aa, bb);
        chkmax(aa, cc);
    }

    static void chkmin(mint aa[], mint bb[], mint cc[], mint dd[]) {
        chkmin(aa, bb);
        chkmin(aa, cc);
        chkmin(aa, dd);
    }

    static void chkmax(mint aa[], mint bb[], mint cc[], mint dd[]) {
        chkmax(aa, bb);
        chkmax(aa, cc);
        chkmax(aa, dd);
    }

    static void chkmin(int aa[], int bb[], int cc[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmin(aa[i], bb[i], cc[i]);
        }
    }

    static void chkmax(int aa[], int bb[], int cc[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmax(aa[i], bb[i], cc[i]);
        }
    }

    static void chkmin(int aa[], int bb[], int cc[], int dd[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmin(aa[i], bb[i], cc[i], dd[i]);
        }
    }

    static void chkmax(int aa[], int bb[], int cc[], int dd[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmax(aa[i], bb[i], cc[i], dd[i]);
        }
    }

    static void chkmin(long aa[], long bb[], long cc[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmin(aa[i], bb[i], cc[i]);
        }
    }

    static void chkmax(long aa[], long bb[], long cc[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmax(aa[i], bb[i], cc[i]);
        }
    }

    static void chkmin(long aa[], long bb[], long cc[], long dd[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmin(aa[i], bb[i], cc[i], dd[i]);
        }
    }

    static void chkmax(long aa[], long bb[], long cc[], long dd[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmax(aa[i], bb[i], cc[i], dd[i]);
        }
    }

    static void chkmin(double aa[], double bb[], double cc[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmin(aa[i], bb[i], cc[i]);
        }
    }

    static void chkmax(double aa[], double bb[], double cc[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmax(aa[i], bb[i], cc[i]);
        }
    }

    static void chkmin(double aa[], double bb[], double cc[], double dd[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmin(aa[i], bb[i], cc[i], dd[i]);
        }
    }

    static void chkmax(double aa[], double bb[], double cc[], double dd[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmax(aa[i], bb[i], cc[i], dd[i]);
        }
    }

    static void chkmin(mint aa[], mint bb[], mint cc[], mint dd[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmin(aa[i], bb[i], cc[i], dd[i]);
        }
    }

    static void chkmax(mint aa[], mint bb[], mint cc[], mint dd[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmax(aa[i], bb[i], cc[i], dd[i]);
        }
    }

    static void chkmin(int aa[], int bb[], int cc[], int dd[], int ee[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmin(aa[i], bb[i], cc[i], dd[i], ee[i]);
        }
    }

    static void chkmax(int aa[], int bb[], int cc[], int dd[], int ee[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmax(aa[i], bb[i], cc[i], dd[i], ee[i]);
        }
    }

    static void chkmin(long aa[], long bb[], long cc[], long dd[], long ee[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmin(aa[i], bb[i], cc[i], dd[i], ee[i]);
        }
    }

    static void chkmax(long aa[], long bb[], long cc[], long dd[], long ee[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmax(aa[i], bb[i], cc[i], dd[i], ee[i]);
        }
    }

    static void chkmin(double aa[], double bb[], double cc[], double dd[], double ee[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmin(aa[i], bb[i], cc[i], dd[i], ee[i]);
        }
    }

    static void chkmax(double aa[], double bb[], double cc[], double dd[], double ee[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmax(aa[i], bb[i], cc[i], dd[i], ee[i]);
        }
    }

    static void chkmin(mint aa[], mint bb[], mint cc[], mint dd[], mint ee[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmin(aa[i], bb[i], cc[i], dd[i], ee[i]);
        }
    }

    static void chkmax(mint aa[], mint bb[], mint cc[], mint dd[], mint ee[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmax(aa[i], bb[i], cc[i], dd[i], ee[i]);
        }
    }

    static void chkmin(int aa[], int bb[], int cc[], int dd[], int ee[], int ff[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmin(aa[i], bb[i], cc[i], dd[i], ee[i], ff[i]);
        }
    }

    static void chkmax(int aa[], int bb[], int cc[], int dd[], int ee[], int ff[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmax(aa[i], bb[i], cc[i], dd[i], ee[i], ff[i]);
        }
    }

    static void chkmin(long aa[], long bb[], long cc[], long dd[], long ee[], long ff[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmin(aa[i], bb[i], cc[i], dd[i], ee[i], ff[i]);
        }
    }

    static void chkmax(long aa[], long bb[], long cc[], long dd[], long ee[], long ff[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmax(aa[i], bb[i], cc[i], dd[i], ee[i], ff[i]);
        }
    }

    static void chkmin(double aa[], double bb[], double cc[], double dd[], double ee[], double ff[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmin(aa[i], bb[i], cc[i], dd[i], ee[i], ff[i]);
        }
    }

    static void chkmax(double aa[], double bb[], double cc[], double dd[], double ee[], double ff[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmax(aa[i], bb[i], cc[i], dd[i], ee[i], ff[i]);
        }
    }

    static void chkmin(mint aa[], mint bb[], mint cc[], mint dd[], mint ee[], mint ff[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmin(aa[i], bb[i], cc[i], dd[i], ee[i], ff[i]);
        }
    }

    static void chkmax(mint aa[], mint bb[], mint cc[], mint dd[], mint ee[], mint ff[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmax(aa[i], bb[i], cc[i], dd[i], ee[i], ff[i]);
        }
    }

    static void chkmin(int aa[], int bb[], int cc[], int dd[], int ee[], int ff[], int gg[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmin(aa[i], bb[i], cc[i], dd[i], ee[i], ff[i], gg[i]);
        }
    }

    static void chkmax(int aa[], int bb[], int cc[], int dd[], int ee[], int ff[], int gg[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmax(aa[i], bb[i], cc[i], dd[i], ee[i], ff[i], gg[i]);
        }
    }

    static void chkmin(long aa[], long bb[], long cc[], long dd[], long ee[], long ff[], long gg[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmin(aa[i], bb[i], cc[i], dd[i], ee[i], ff[i], gg[i]);
        }
    }

    static void chkmax(long aa[], long bb[], long cc[], long dd[], long ee[], long ff[], long gg[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmax(aa[i], bb[i], cc[i], dd[i], ee[i], ff[i], gg[i]);
        }
    }

    static void chkmin(double aa[], double bb[], double cc[], double dd[], double ee[], double ff[], double gg[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmin(aa[i], bb[i], cc[i], dd[i], ee[i], ff[i], gg[i]);
        }
    }

    static void chkmax(double aa[], double bb[], double cc[], double dd[], double ee[], double ff[], double gg[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmax(aa[i], bb[i], cc[i], dd[i], ee[i], ff[i], gg[i]);
        }
    }

    static void chkmin(mint aa[], mint bb[], mint cc[], mint dd[], mint ee[], mint ff[], mint gg[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmin(aa[i], bb[i], cc[i], dd[i], ee[i], ff[i], gg[i]);
        }
    }

    static void chkmax(mint aa[], mint bb[], mint cc[], mint dd[], mint ee[], mint ff[], mint gg[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmax(aa[i], bb[i], cc[i], dd[i], ee[i], ff[i], gg[i]);
        }
    }

    static void chkmin(int aa[], int bb[], int cc[], int dd[], int ee[], int ff[], int gg[], int hh[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmin(aa[i], bb[i], cc[i], dd[i], ee[i], ff[i], gg[i], hh[i]);
        }
    }

    static void chkmax(int aa[], int bb[], int cc[], int dd[], int ee[], int ff[], int gg[], int hh[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmax(aa[i], bb[i], cc[i], dd[i], ee[i], ff[i], gg[i], hh[i]);
        }
    }

    static void chkmin(long aa[], long bb[], long cc[], long dd[], long ee[], long ff[], long gg[], long hh[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmin(aa[i], bb[i], cc[i], dd[i], ee[i], ff[i], gg[i], hh[i]);
        }
    }

    static void chkmax(long aa[], long bb[], long cc[], long dd[], long ee[], long ff[], long gg[], long hh[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmax(aa[i], bb[i], cc[i], dd[i], ee[i], ff[i], gg[i], hh[i]);
        }
    }

    static void chkmin(double aa[], double bb[], double cc[], double dd[], double ee[], double ff[], double gg[], double hh[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmin(aa[i], bb[i], cc[i], dd[i], ee[i], ff[i], gg[i], hh[i]);
        }
    }

    static void chkmax(double aa[], double bb[], double cc[], double dd[], double ee[], double ff[], double gg[], double hh[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmax(aa[i], bb[i], cc[i], dd[i], ee[i], ff[i], gg[i], hh[i]);
        }
    }

    static void chkmin(mint aa[], mint bb[], mint cc[], mint dd[], mint ee[], mint ff[], mint gg[], mint hh[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmin(aa[i], bb[i], cc[i], dd[i], ee[i], ff[i], gg[i], hh[i]);
        }
    }

    static void chkmax(mint aa[], mint bb[], mint cc[], mint dd[], mint ee[], mint ff[], mint gg[], mint hh[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmax(aa[i], bb[i], cc[i], dd[i], ee[i], ff[i], gg[i], hh[i]);
        }
    }

    static void chkmin(int aa[], int bb[], int cc[], int dd[], int ee[], int ff[], int gg[], int hh[], int ii[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmin(aa[i], bb[i], cc[i], dd[i], ee[i], ff[i], gg[i], hh[i], ii[i]);
        }
    }

    static void chkmax(int aa[], int bb[], int cc[], int dd[], int ee[], int ff[], int gg[], int hh[], int ii[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmax(aa[i], bb[i], cc[i], dd[i], ee[i], ff[i], gg[i], hh[i], ii[i]);
        }
    }

    static void chkmin(long aa[], long bb[], long cc[], long dd[], long ee[], long ff[], long gg[], long hh[], long ii[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmin(aa[i], bb[i], cc[i], dd[i], ee[i], ff[i], gg[i], hh[i], ii[i]);
        }
    }

    static void chkmax(long aa[], long bb[], long cc[], long dd[], long ee[], long ff[], long gg[], long hh[], long ii[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmax(aa[i], bb[i], cc[i], dd[i], ee[i], ff[i], gg[i], hh[i], ii[i]);
        }
    }

    static void chkmin(double aa[], double bb[], double cc[], double dd[], double ee[], double ff[], double gg[], double hh[], double ii[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmin(aa[i], bb[i], cc[i], dd[i], ee[i], ff[i], gg[i], hh[i], ii[i]);
        }
    }

    static void chkmax(double aa[], double bb[], double cc[], double dd[], double ee[], double ff[], double gg[], double hh[], double ii[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmax(aa[i], bb[i], cc[i], dd[i], ee[i], ff[i], gg[i], hh[i], ii[i]);
        }
    }

    static void chkmin(mint aa[], mint bb[], mint cc[], mint dd[], mint ee[], mint ff[], mint gg[], mint hh[], mint ii[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmin(aa[i], bb[i], cc[i], dd[i], ee[i], ff[i], gg[i], hh[i], ii[i]);
        }
    }

    static void chkmax(mint aa[], mint bb[], mint cc[], mint dd[], mint ee[], mint ff[], mint gg[], mint hh[], mint ii[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmax(aa[i], bb[i], cc[i], dd[i], ee[i], ff[i], gg[i], hh[i], ii[i]);
        }
    }

    static void chkmin(int aa[], int bb[], int cc[], int dd[], int ee[], int ff[], int gg[], int hh[], int ii[], int jj[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmin(aa[i], bb[i], cc[i], dd[i], ee[i], ff[i], gg[i], hh[i], ii[i], jj[i]);
        }
    }

    static void chkmax(int aa[], int bb[], int cc[], int dd[], int ee[], int ff[], int gg[], int hh[], int ii[], int jj[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmax(aa[i], bb[i], cc[i], dd[i], ee[i], ff[i], gg[i], hh[i], ii[i], jj[i]);
        }
    }

    static void chkmin(long aa[], long bb[], long cc[], long dd[], long ee[], long ff[], long gg[], long hh[], long ii[], long jj[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmin(aa[i], bb[i], cc[i], dd[i], ee[i], ff[i], gg[i], hh[i], ii[i], jj[i]);
        }
    }

    static void chkmax(long aa[], long bb[], long cc[], long dd[], long ee[], long ff[], long gg[], long hh[], long ii[], long jj[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmax(aa[i], bb[i], cc[i], dd[i], ee[i], ff[i], gg[i], hh[i], ii[i], jj[i]);
        }
    }

    static void chkmin(double aa[], double bb[], double cc[], double dd[], double ee[], double ff[], double gg[], double hh[], double ii[], double jj[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmin(aa[i], bb[i], cc[i], dd[i], ee[i], ff[i], gg[i], hh[i], ii[i], jj[i]);
        }
    }

    static void chkmax(double aa[], double bb[], double cc[], double dd[], double ee[], double ff[], double gg[], double hh[], double ii[], double jj[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmax(aa[i], bb[i], cc[i], dd[i], ee[i], ff[i], gg[i], hh[i], ii[i], jj[i]);
        }
    }

    static void chkmin(mint aa[], mint bb[], mint cc[], mint dd[], mint ee[], mint ff[], mint gg[], mint hh[], mint ii[], mint jj[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmin(aa[i], bb[i], cc[i], dd[i], ee[i], ff[i], gg[i], hh[i], ii[i], jj[i]);
        }
    }

    static void chkmax(mint aa[], mint bb[], mint cc[], mint dd[], mint ee[], mint ff[], mint gg[], mint hh[], mint ii[], mint jj[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmax(aa[i], bb[i], cc[i], dd[i], ee[i], ff[i], gg[i], hh[i], ii[i], jj[i]);
        }
    }

    static void chkmin(int aa[], int bb[], int cc[], int dd[], int ee[], int ff[], int gg[], int hh[], int ii[], int jj[], int kk[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmin(aa[i], bb[i], cc[i], dd[i], ee[i], ff[i], gg[i], hh[i], ii[i], jj[i], kk[i]);
        }
    }

    static void chkmax(int aa[], int bb[], int cc[], int dd[], int ee[], int ff[], int gg[], int hh[], int ii[], int jj[], int kk[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmax(aa[i], bb[i], cc[i], dd[i], ee[i], ff[i], gg[i], hh[i], ii[i], jj[i], kk[i]);
        }
    }

    static void chkmin(long aa[], long bb[], long cc[], long dd[], long ee[], long ff[], long gg[], long hh[], long ii[], long jj[], long kk[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmin(aa[i], bb[i], cc[i], dd[i], ee[i], ff[i], gg[i], hh[i], ii[i], jj[i], kk[i]);
        }
    }

    static void chkmax(long aa[], long bb[], long cc[], long dd[], long ee[], long ff[], long gg[], long hh[], long ii[], long jj[], long kk[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmax(aa[i], bb[i], cc[i], dd[i], ee[i], ff[i], gg[i], hh[i], ii[i], jj[i], kk[i]);
        }
    }

    static void chkmin(double aa[], double bb[], double cc[], double dd[], double ee[], double ff[], double gg[], double hh[], double ii[], double jj[], double kk[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmin(aa[i], bb[i], cc[i], dd[i], ee[i], ff[i], gg[i], hh[i], ii[i], jj[i], kk[i]);
        }
    }

    static void chkmax(double aa[], double bb[], double cc[], double dd[], double ee[], double ff[], double gg[], double hh[], double ii[], double jj[], double kk[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmax(aa[i], bb[i], cc[i], dd[i], ee[i], ff[i], gg[i], hh[i], ii[i], jj[i], kk[i]);
        }
    }

    static void chkmin(mint aa[], mint bb[], mint cc[], mint dd[], mint ee[], mint ff[], mint gg[], mint hh[], mint ii[], mint jj[], mint kk[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmin(aa[i], bb[i], cc[i], dd[i], ee[i], ff[i], gg[i], hh[i], ii[i], jj[i], kk[i]);
        }
    }

    static void chkmax(mint aa[], mint bb[], mint cc[], mint dd[], mint ee[], mint ff[], mint gg[], mint hh[], mint ii[], mint jj[], mint kk[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmax(aa[i], bb[i], cc[i], dd[i], ee[i], ff[i], gg[i], hh[i], ii[i], jj[i], kk[i]);
        }
    }

    static void chkmin(int aa[], int bb[], int cc[], int dd[], int ee[], int ff[], int gg[], int hh[], int ii[], int jj[], int kk[], int ll[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmin(aa[i], bb[i], cc[i], dd[i], ee[i], ff[i], gg[i], hh[i], ii[i], jj[i], kk[i], ll[i]);
        }
    }

    static void chkmax(int aa[], int bb[], int cc[], int dd[], int ee[], int ff[], int gg[], int hh[], int ii[], int jj[], int kk[], int ll[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmax(aa[i], bb[i], cc[i], dd[i], ee[i], ff[i], gg[i], hh[i], ii[i], jj[i], kk[i], ll[i]);
        }
    }

    static void chkmin(long aa[], long bb[], long cc[], long dd[], long ee[], long ff[], long gg[], long hh[], long ii[], long jj[], long kk[], long ll[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmin(aa[i], bb[i], cc[i], dd[i], ee[i], ff[i], gg[i], hh[i], ii[i], jj[i], kk[i], ll[i]);
        }
    }

    static void chkmax(long aa[], long bb[], long cc[], long dd[], long ee[], long ff[], long gg[], long hh[], long ii[], long jj[], long kk[], long ll[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmax(aa[i], bb[i], cc[i], dd[i], ee[i], ff[i], gg[i], hh[i], ii[i], jj[i], kk[i], ll[i]);
        }
    }

    static void chkmin(double aa[], double bb[], double cc[], double dd[], double ee[], double ff[], double gg[], double hh[], double ii[], double jj[], double kk[], double ll[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmin(aa[i], bb[i], cc[i], dd[i], ee[i], ff[i], gg[i], hh[i], ii[i], jj[i], kk[i], ll[i]);
        }
    }

    static void chkmax(double aa[], double bb[], double cc[], double dd[], double ee[], double ff[], double gg[], double hh[], double ii[], double jj[], double kk[], double ll[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmax(aa[i], bb[i], cc[i], dd[i], ee[i], ff[i], gg[i], hh[i], ii[i], jj[i], kk[i], ll[i]);
        }
    }

    static void chkmin(mint aa[], mint bb[], mint cc[], mint dd[], mint ee[], mint ff[], mint gg[], mint hh[], mint ii[], mint jj[], mint kk[], mint ll[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmin(aa[i], bb[i], cc[i], dd[i], ee[i], ff[i], gg[i], hh[i], ii[i], jj[i], kk[i], ll[i]);
        }
    }

    static void chkmax(mint aa[], mint bb[], mint cc[], mint dd[], mint ee[], mint ff[], mint gg[], mint hh[], mint ii[], mint jj[], mint kk[], mint ll[]) {
        for (int i = 0; i < aa.length; i++) {
            chkmax(aa[i], bb[i], cc[i], dd[i], ee[i], ff[i], gg[i], hh[i], ii[i], jj[i], kk[i], ll[i]);
        }
    }

    static int[] vpos;
    static int[] v;
    static mint[][] probBallDir;
    static GroupSet gs;
    static MulSegTree seg;

    static class Collision implements Comparable<Collision> {
        id5 id7;
        int pos;
        int dirL;
        int dirR;

        public int compareTo(Collision other) {
            if (id7.nu * other.id7.de < other.id7.nu * id7.de) return -1;
            if (id7.nu * other.id7.de > other.id7.nu * id7.de) return 1;
            return 0;
        }
    }

    static mint id10 = new mint(1);

    static mint probForce(int dir, int l, int r) {
        assert (0 <= dir && dir < 2);
        return seg.query(l, r).prod[dir];
    }

    static mint id1(int l, int r) {
        return seg.query(l, r).sumlr;
    }

    static mint id2(int l, int r) {
        int lo = INF, hi = -INF;
        mint ans = new mint(1);
        gs.check();
        for (int pos = l; pos <= r; ) {
            Group dat = gs.getData(pos);
            chkmin(lo, dat.l);
            chkmax(hi, dat.r);
            mint mult;
            if (dat.forceDir == UNDEF) {
                mult = seg.query(dat.l, dat.r).sumlr;
            } else {
                mult = seg.query(dat.l, dat.r).prod[dat.forceDir];
            }
            ans.multiply(mult);
            pos = dat.r + 1;
        }
        return ans;
    }

    static void id12(int l, int r) {
        Group dl = gs.getData(l);
        Group dr = gs.getData(r);
        if ((dl.forceDir == R && dr.forceDir == -1) ||
                (dl.forceDir == -1 && dr.forceDir == L) ||
                (dl.forceDir == -1 && dr.forceDir == -1)) {
            mint den = id2(dl.l, dr.r);
            gs.funion(l, r);
            mint num = id2(dl.l, dr.r);
            id10.multiply(num.divide(den));
        } else if (dl.forceDir == L && dr.forceDir == -1) {

