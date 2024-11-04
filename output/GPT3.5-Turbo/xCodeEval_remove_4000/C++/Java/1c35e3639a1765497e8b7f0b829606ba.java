import java.util.*;
import java.io.*;

class Main {
    static class ModInt {
        static final int mod = 998244353;
        int v;

        ModInt() {
            v = 0;
        }

        ModInt(long _v) {
            v = normS((int)(_v % mod + mod));
        }

        static int normS(int x) {
            return (x < mod) ? x : x - mod;
        }

        static ModInt make(int x) {
            ModInt m = new ModInt();
            m.v = x;
            return m;
        }

        ModInt add(ModInt b) {
            return make(normS(v + b.v));
        }

        ModInt subtract(ModInt b) {
            return make(normS(v + mod - b.v));
        }

        ModInt negate() {
            return make(normS(mod - v));
        }

        ModInt multiply(ModInt b) {
            return make((int)((long)v * b.v % mod));
        }

        ModInt divide(ModInt b) {
            return multiply(b.inverse());
        }

        ModInt increment() {
            return add(make(1));
        }

        ModInt decrement() {
            return subtract(make(1));
        }

        long extgcd(long a, long b, long[] x, long[] y) {
            long[] p = {a, 1, 0};
            long[] q = {b, 0, 1};
            while (q[0] != 0) {
                long t = p[0] / q[0];
                for (int i = 0; i < 3; i++) {
                    long temp = p[i] - t * q[i];
                    p[i] = q[i];
                    q[i] = temp;
                }
            }
            if (p[0] < 0) {
                for (int i = 0; i < 3; i++) {
                    p[i] = -p[i];
                }
            }
            x[0] = p[1];
            y[0] = p[2];
            return p[0];
        }

        ModInt inverse() {
            long[] x = new long[1];
            long[] y = new long[1];
            extgcd(v, mod, x, y);
            return make(normS((int)(x[0] + mod)));
        }

        ModInt pow(long p) {
            if (p < 0) {
                return inverse().pow(-p);
            }
            ModInt a = make(1);
            ModInt x = make(v);
            while (p > 0) {
                if ((p & 1) == 1) {
                    a = a.multiply(x);
                }
                x = x.multiply(x);
                p >>= 1;
            }
            return a;
        }

        boolean equals(ModInt b) {
            return v == b.v;
        }

        boolean notEquals(ModInt b) {
            return v != b.v;
        }

        public String toString() {
            return Integer.toString(v);
        }
    }

    static class Poly<D> {
        ArrayList<D> v;

        Poly(int N) {
            v = new ArrayList<>(N);
        }

        Poly(ArrayList<D> v) {
            this.v = v;
            shrink();
        }

        int size() {
            return v.size();
        }

        Poly shrink() {
            while (!v.isEmpty() && v.get(v.size() - 1).equals(0)) {
                v.remove(v.size() - 1);
            }
            return this;
        }

        D at(int i) {
            return (i < size()) ? v.get(i) : 0;
        }

        void set(int i, D x) {
            if (i >= size() && x.equals(0)) {
                return;
            }
            while (i >= size()) {
                v.add(0);
            }
            v.set(i, x);
            shrink();
            return;
        }

        Poly add(Poly r) {
            int N = Math.max(size(), r.size());
            ArrayList<D> ret = new ArrayList<>(N);
            for (int i = 0; i < N; i++) {
                ret.add((D)at(i).add(r.at(i)));
            }
            return new Poly(ret);
        }

        Poly subtract(Poly r) {
            int N = Math.max(size(), r.size());
            ArrayList<D> ret = new ArrayList<>(N);
            for (int i = 0; i < N; i++) {
                ret.add((D)at(i).subtract(r.at(i)));
            }
            return new Poly(ret);
        }

        Poly negate() {
            int N = size();
            ArrayList<D> ret = new ArrayList<>(N);
            for (int i = 0; i < N; i++) {
                ret.add((D)at(i).negate());
            }
            return new Poly(ret);
        }

        Poly multiply(Poly r) {
            if (size() == 0 || r.size() == 0) {
                return new Poly(0);
            }
            return mul_fft(r);
        }

        Poly multiply(D r) {
            int N = size();
            ArrayList<D> ret = new ArrayList<>(N);
            for (int i = 0; i < N; i++) {
                ret.add((D)at(i).multiply(r));
            }
            return new Poly(ret);
        }

        Poly divide(Poly y) {
            return div_fast(y);
        }

        Poly remainder(Poly y) {
            return rem_fast(y);
        }

        Poly shiftLeft(int n) {
            assert n >= 0;
            int N = size();
            ArrayList<D> ret = new ArrayList<>(N + n);
            for (int i = 0; i < N; i++) {
                ret.add((D)at(i));
            }
            for (int i = 0; i < n; i++) {
                ret.add(0);
            }
            return new Poly(ret);
        }

        Poly shiftRight(int n) {
            assert n >= 0;
            int N = size();
            if (N <= n) {
                return new Poly(0);
            }
            ArrayList<D> ret = new ArrayList<>(N - n);
            for (int i = 0; i < N - n; i++) {
                ret.add((D)at(i + n));
            }
            return new Poly(ret);
        }

        boolean equals(Poly y) {
            return v.equals(y.v);
        }

        boolean notEquals(Poly y) {
            return !v.equals(y.v);
        }

        Poly addAssign(Poly r) {
            return this = add(r);
        }

        Poly subtractAssign(Poly r) {
            return this = subtract(r);
        }

        Poly multiplyAssign(Poly r) {
            return this = multiply(r);
        }

        Poly multiplyAssign(D r) {
            return this = multiply(r);
        }

        Poly remainderAssign(Poly y) {
            return this = remainder(y);
        }

        Poly shiftLeftAssign(int n) {
            return this = shiftLeft(n);
        }

        Poly shiftRightAssign(int n) {
            return this = shiftRight(n);
        }

        Poly mul_naive(Poly r) {
            int N = size(), M = r.size();
            ArrayList<D> ret = new ArrayList<>(N + M - 1);
            for (int i = 0; i < N + M - 1; i++) {
                ret.add(0);
            }
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    ret.set(i + j, (D)ret.get(i + j).add(at(i).multiply(r.at(j))));
                }
            }
            return new Poly(ret);
        }

        Poly mul_ntt(Poly r) {
            return new Poly(multiply_ntt(v, r.v));
        }

        Poly mul_fft(Poly r) {
            ArrayList<D> ret = multiply_fft(v, r.v);
            return new Poly(ret);
        }

        Poly div_fast_with_inv(Poly inv, int B) {
            return multiply(inv).shiftRight(B - 1);
        }

        Poly div_fast(Poly y) {
            if (size() < y.size()) {
                return new Poly(0);
            }
            int n = size();
            return div_fast_with_inv(y.inv(n), n);
        }

        Poly rem_naive(Poly y) {
            Poly x = new Poly(v);
            while (y.size() <= x.size()) {
                int N = x.size(), M = y.size();
                D coef = x.at(N - 1).divide(y.at(M - 1));
                x = x.subtract(y.shiftLeft(N - M).multiply(coef));
            }
            return x;
        }

        Poly rem_fast(Poly y) {
            return subtract(y.multiply(div_fast(y)));
        }

        Poly strip(int n) {
            ArrayList<D> res = new ArrayList<>(v);
            while (res.size() > n) {
                res.remove(res.size() - 1);
            }
            return new Poly(res);
        }

        Poly rev(int n) {
            ArrayList<D> res = new ArrayList<>(v);
            if (n != -1) {
                while (res.size() < n) {
                    res.add(0);
                }
            }
            Collections.reverse(res);
            return new Poly(res);
        }

        Poly inv(int n) {
            int N = size();
            assert N >= 1;
            assert n >= N - 1;
            D coef = at(N - 1).inverse();
            Poly a = rev();
            Poly g = new Poly(new ArrayList<>(Collections.singletonList(coef)));
            for (int i = 1; i + N - 2 < n; i *= 2) {
                g = g.multiply(new Poly(new ArrayList<>(Arrays.asList(2))));
                g = g.subtract(a.multiply(g).strip(2 * i));
            }
            return g.rev(n + 1 - N);
        }

        public String toString() {
            if (size() == 0) {
                return "0";
            }
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < size(); i++) {
                if (!at(i).equals(0)) {
                    sb.append(at(i)).append("x^").append(i);
                    if (i != size() - 1) {
                        sb.append(" + ");
                    }
                }
            }
            return sb.toString();
        }
    }

    static ArrayList<ModInt> fact, ifact;

    static ModInt Choose(int a, int b) {
        if (b < 0 || a < b) {
            return new ModInt(0);
        }
        return fact.get(a).multiply(ifact.get(b)).multiply(ifact.get(a - b));
    }

    static void InitFact(int N) {
        fact = new ArrayList<>(N);
        ifact = new ArrayList<>(N);
        fact.add(new ModInt(1));
        for (int i = 1; i < N; i++) {
            fact.add(fact.get(i - 1).multiply(new ModInt(i)));
        }
        ifact.set(N - 1, fact.get(N - 1).inverse());
        for (int i = N - 2; i >= 0; i--) {
            ifact.set(i, ifact.get(i + 1).multiply(new ModInt(i + 1)));
        }
    }

    static <Mint extends ModInt> Poly<Mint> id0(ArrayList<Mint> u) {
        int N = u.size();
        ArrayList<Mint> b = new ArrayList<>(Collections.singletonList(new ModInt(-1)));
        ArrayList<Mint> c = new ArrayList<>(Collections.singletonList(new ModInt(-1)));
        Mint y = new ModInt(1);
        for (int n = 1; n <= N; n++) {
            int L = c.size(), M = b.size();
            Mint x = new ModInt(0);
            for (int i = 0; i < L; i++) {
                x = x.add(c.get(i).multiply(u.get(n - L + i)));
            }
            b.add(new ModInt(0));
            M++;
            if (x.equals(0)) {
                continue;
            }
            Mint coef = x.divide(y);
            if (L < M) {
                ArrayList<Mint> tmp = new ArrayList<>(c);
                c.clear();
                for (int i = 0; i < M; i++) {
                    c.add(new ModInt(0));
                }
                for (int i = 0; i < M; i++) {
                    c.set(M - 1 - i, tmp.get(i).subtract(coef.multiply(b.get(M - 1 - i))));
                }
                b = tmp;
                y = x;
            } else {
                for (int i = 0; i < M; i++) {
                    c.set(L - 1 - i, c.get(L - 1 - i).subtract(coef.multiply(b.get(M - 1 - i))));
                }
            }
        }
        return new Poly<>(c);
    }

    static <Mint extends ModInt> ArrayList<ArrayList<Mint>> id3(ArrayList<Mint> terms, int deg, int ord, boolean verify) {
        if (ord != -1) {
            int n = (deg + 1) * (ord + 1) + ord - 1;
            while (terms.size() > n) {
                terms.remove(terms.size() - 1);
            }
        }

        int n = terms.size();
        int B = (n + 2) / (deg + 2);
        int C = B * (deg + 1);
        int R = n - (B - 1);

        assert B >= 2;
        assert R >= C - 1;

        ArrayList<ArrayList<Mint>> mat = new ArrayList<>(R);
        for (int y = 0; y < R; y++) {
            mat.add(new ArrayList<>(C));
            for (int i = 0; i < C; i++) {
                mat.get(y).add(terms.get(y + i));
            }
        }

        int rank = 0;
        for (int x = 0; x < C; x++) {
            int pivot = -1;
            for (int y = rank; y < R; y++) {
                if (!mat.get(y).get(x).equals(0)) {
                    pivot = y;
                    break;
                }
            }
            if (pivot < 0) {
                break;
            }
            if (pivot != rank) {
                Collections.swap(mat, rank, pivot);
            }
            Mint inv = mat.get(rank).get(x).inverse();
            for (int x2 = x; x2 < C; x2++) {
                mat.get(rank).set(x2, mat.get(rank).get(x2).multiply(inv));
            }
            for (int y = rank + 1; y < R; y++) {
                if (!mat.get(y).get(x).equals(0)) {
                    Mint c = mat.get(y).get(x).negate();
                    for (int x2 = x; x2 < C; x2++) {
                        mat.get(y).set(x2, mat.get(y).get(x2).add(mat.get(rank).get(x2).multiply(c)));
                    }
                }
            }
            rank++;
        }

        if (rank == C) {
            error(B - 1, deg);
        }

        for (int y = rank - 1; y >= 0; y--) {
            if (!mat.get(y).get(rank).equals(0)) {
                assert mat.get(y).get(y).equals(1);
                Mint c = mat.get(y).get(rank).negate();
                for (int y2 = 0; y2 < y; y2++) {
                    mat.get(y2).set(rank, mat.get(y2).get(rank).add(mat.get(y2).get(y).multiply(c)));
                }
            }
        }

        int order = rank / (deg + 1);

        ArrayList<ArrayList<Mint>> ret = new ArrayList<>(order + 1);
        for (int i = 0; i <= order; i++) {
            ret.add(new ArrayList<>(deg + 1));
            for (int j = 0; j <= deg; j++) {
                ret.get(i).add(mat.get(i).get(j));
            }
        }

        if (verify) {
            ArrayList<Mint> extended_terms = extended(n - 1, ret, terms.subList(0, order));
            for (int i = 0; i < terms.size(); i++) {
                if (!terms.get(i).equals(extended_terms.get(i))) {
                    error(B - 1, deg);
                }
            }
        }

        return ret;
    }

    static <Mint extends ModInt> void id1(int n, ArrayList<Mint> terms, int degree, int order) {
        ArrayList<ArrayList<Mint>> coeffs = id3(terms, degree, order, true);
        ArrayList<Mint> extended_terms = extended(n - 1, coeffs, terms.subList(0, order));
        for (int i = 0; i < extended_terms.size(); i++) {
            System.out.println(i + " " + extended_terms.get(i));
        }
        System.out.println();
    }

    static <Mint extends ModInt> ArrayList<Mint> id2(int n, ArrayList<Mint> terms, int degree, int order) {
        ArrayList<ArrayList<Mint>> coeffs = id3(terms, degree, order, true);
        return extended(n, coeffs, terms);
    }

    static void main() {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        System.out.println(solve(N));
    }

    static ModInt solve(long N) {
        ModInt res = new ModInt(0);
        for (int i = 0; i <= N; i++) {
            if (i == 0) {
                for (int j = 1; j <= N; j++) {
                    res = res.add(new ModInt(-1).pow(i + j).multiply(Choose(N, j)).multiply(new ModInt(3).pow(j + N * (N - j))));
                }
            } else {
                res = res.add(new ModInt(-1).pow(i).multiply(Choose(N, i)).multiply(new ModInt(3).pow(N - i).subtract(new ModInt(1)).pow(N).subtract(new ModInt(3).pow((N - i) * N))).multiply(new ModInt(3)));
                res = res.add(new ModInt(-1).pow(i).multiply(Choose(N, i)).multiply(new ModInt(3).pow(i + N * (N - i))));
            }
        }
        return res.negate();
    }

    public static void main(String[] args) {
        InitFact(2000010);
        main();
    }
}
