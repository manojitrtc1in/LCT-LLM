import java.util.*;
import java.io.*;
import java.math.*;

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

    static class Pair<T1, T2> {
        T1 first;
        T2 second;

        public Pair(T1 first, T2 second) {
            this.first = first;
            this.second = second;
        }
    }

    static class Fraction<T extends Number> {
        T n, d;

        public Fraction(T _n, T _d) {
            n = _n;
            d = _d;
            if (d.intValue() < 0) {
                n = (T) (Integer) (-1 * n.intValue());
                d = (T) (Integer) (-1 * d.intValue());
            }
            T g = gcd(Math.abs(n.intValue()), d.intValue());
            n = (T) (Integer) (n.intValue() / g.intValue());
            d = (T) (Integer) (d.intValue() / g.intValue());
        }

        public static <T extends Number> T gcd(T a, T b) {
            if (b.intValue() == 0) {
                return a;
            }
            return gcd(b, a.intValue() % b.intValue());
        }

        public static <T extends Number> T min(T a, T b) {
            if (a.doubleValue() < b.doubleValue()) {
                return a;
            }
            return b;
        }

        public static <T extends Number> T max(T a, T b) {
            if (a.doubleValue() > b.doubleValue()) {
                return a;
            }
            return b;
        }

        public Fraction<T> add(Fraction<T> b) {
            return new Fraction<T>((T) (Integer) (n.intValue() * b.d.intValue() + b.n.intValue() * d.intValue()), (T) (Integer) (d.intValue() * b.d.intValue()));
        }

        public Fraction<T> subtract(Fraction<T> b) {
            return new Fraction<T>((T) (Integer) (n.intValue() * b.d.intValue() - b.n.intValue() * d.intValue()), (T) (Integer) (d.intValue() * b.d.intValue()));
        }

        public Fraction<T> multiply(Fraction<T> b) {
            return new Fraction<T>((T) (Integer) (n.intValue() * b.n.intValue()), (T) (Integer) (d.intValue() * b.d.intValue()));
        }

        public Fraction<T> divide(Fraction<T> b) {
            return new Fraction<T>((T) (Integer) (n.intValue() * b.d.intValue()), (T) (Integer) (d.intValue() * b.n.intValue()));
        }

        @Override
        public String toString() {
            return n + "/" + d;
        }
    }

    static class ModNum<T extends Number> {
        T v;
        int MOD = 998244353;

        public ModNum() {
            v = (T) (Integer) 0;
        }

        public ModNum(T _v) {
            v = (T) (Integer) (_v.intValue() % MOD);
            if (v.intValue() < 0) {
                v = (T) (Integer) (v.intValue() + MOD);
            }
        }

        public static <T extends Number> T fastMod(long x, int m) {
            return (T) (Long) (x % m);
        }

        public ModNum<T> add(ModNum<T> o) {
            return new ModNum<T>((T) (Integer) (v.intValue() + o.v.intValue() % MOD));
        }

        public ModNum<T> subtract(ModNum<T> o) {
            return new ModNum<T>((T) (Integer) (v.intValue() - o.v.intValue() % MOD + MOD));
        }

        public ModNum<T> multiply(ModNum<T> o) {
            return new ModNum<T>((T) (Integer) (v.intValue() * o.v.intValue() % MOD));
        }

        public ModNum<T> divide(ModNum<T> o) {
            return new ModNum<T>((T) (Integer) (v.intValue() * o.inverse().v.intValue() % MOD));
        }

        public ModNum<T> inverse() {
            int g = MOD, x = 0, y = 1;
            int r = v.intValue();
            while (r != 0) {
                int q = g / r;
                g %= r;
                int temp = x - q * y;
                x = y;
                y = temp;
                temp = g;
                g = r;
                r = temp;
            }
            if (g == 1) {
                return new ModNum<T>((T) (Integer) (x < 0 ? x + MOD : x));
            }
            return null;
        }

        public ModNum<T> pow(int e) {
            if (e < 0) {
                return inverse().pow(-e);
            }
            if (e == 0) {
                return new ModNum<T>((T) (Integer) 1);
            }
            if ((e & 1) == 1) {
                return multiply(pow(e - 1));
            }
            return multiply(multiply()).pow(e / 2);
        }

        @Override
        public String toString() {
            return v.toString();
        }
    }

    static class SegmentTree<T, F> {
        int SZ;
        T id;
        F tt;
        ArrayList<T> table;

        public SegmentTree(int _SZ, T _id, F _tt) {
            SZ = _SZ;
            id = _id;
            tt = _tt;
            table = new ArrayList<T>(2 * SZ);
            for (int i = 0; i < 2 * SZ; i++) {
                table.add(id);
            }
        }

        public <L> void id1(L create) {
            for (int i = 0; i < SZ; i++) {
                table.set(SZ + i, create.create(i));
            }
            for (int i = SZ - 1; i > 0; i--) {
                table.set(i, tt.combine(table.get(2 * i), table.get(2 * i + 1)));
            }
        }

        public void replace(int i, T v) {
            table.set(i += SZ, v);
            for (i /= 2; i > 0; i /= 2) {
                table.set(i, tt.combine(table.get(2 * i), table.get(2 * i + 1)));
            }
        }

        public T query(int i, int j) {
            T left = id;
            T right = id;
            for (i += SZ, j += SZ; i < j; i /= 2, j /= 2) {
                if ((i & 1) == 1) {
                    left = tt.combine(left, table.get(i++));
                }
                if ((j & 1) == 1) {
                    right = tt.combine(table.get(--j), right);
                }
            }
            return tt.combine(left, right);
        }

        public T get(int i) {
            return table.get(SZ + i);
        }
    }

    static class Node {
        ArrayList<ModNum<Integer>> p;
        boolean noLL, noRR, noRL, none;

        public Node() {
            p = new ArrayList<ModNum<Integer>>(4);
            for (int i = 0; i < 4; i++) {
                p.add(new ModNum<Integer>((int) 0));
            }
            noLL = false;
            noRR = false;
            noRL = false;
            none = true;
        }
    }

    public static void main(String[] args) {
        FastReader sc = new FastReader();

        int N = sc.nextInt();
        ArrayList<Pair<Integer, Pair<Integer, Integer>>> pipes = new ArrayList<Pair<Integer, Pair<Integer, Integer>>>();
        for (int i = 0; i < N; i++) {
            int x = sc.nextInt();
            int v = sc.nextInt();
            int p = sc.nextInt();
            pipes.add(new Pair<Integer, Pair<Integer, Integer>>(x, new Pair<Integer, Integer>(v, p)));
        }

        ArrayList<Pair<Integer, Pair<Integer, Fraction<Long>>>> evs = new ArrayList<Pair<Integer, Pair<Integer, Fraction<Long>>>>();

        for (int i = 0; i < N - 1; i++) {
            int dx = pipes.get(i + 1).first - pipes.get(i).first;
            int dv = pipes.get(i + 1).second.first - pipes.get(i).second.first;

            evs.add(new Pair<Integer, Pair<Integer, Fraction<Long>>>(i, new Pair<Integer, Fraction<Long>>(2, new Fraction<Long>((long) dx, (long) (pipes.get(i + 1).second.first + pipes.get(i).second.first)))));
            if (dv > 0) {
                evs.add(new Pair<Integer, Pair<Integer, Fraction<Long>>>(i, new Pair<Integer, Fraction<Long>>>(0, new Fraction<Long>((long) dx, (long) dv))));
            }
            if (dv < 0) {
                evs.add(new Pair<Integer, Pair<Integer, Fraction<Long>>>(i, new Pair<Integer, Fraction<Long>>>(1, new Fraction<Long>((long) dx, (long) (-dv)))));
            }
        }

        Collections.sort(evs, new Comparator<Pair<Integer, Pair<Integer, Fraction<Long>>>>() {
            @Override
            public int compare(Pair<Integer, Pair<Integer, Fraction<Long>>> a, Pair<Integer, Pair<Integer, Fraction<Long>>> b) {
                return a.second.second.compareTo(b.second.second);
            }
        });

        SegmentTree<Node, SegmentTree.Combine<Node>> st = new SegmentTree<Node, SegmentTree.Combine<Node>>(N, new Node(), new SegmentTree.Combine<Node>());
        st.id1(new SegmentTree.Create<Node>() {
            @Override
            public Node create(int i) {
                Node r = new Node();
                r.p.set(3, new ModNum<Integer>(pipes.get(i).second.second).multiply(new ModNum<Integer>(ModNum.smallInv(100))));
                r.none = false;
                return r;
            }
        });

        ModNum<Integer> ans = new ModNum<Integer>((int) 0);
        ModNum<Integer> prob = new ModNum<Integer>((int) 1);
        for (Pair<Integer, Pair<Integer, Fraction<Long>>> e : evs) {
            Node c = st.get(e.first);
            switch (e.second.first) {
                case 0:
                    c.noLL = true;
                    break;
                case 1:
                    c.noRR = true;
                    break;
                case 2:
                    c.noRL = true;
                    break;
            }
            st.replace(e.first, c);

            Node u = st.query(0, st.SZ);
            ModNum<Integer> PROB = new ModNum<Integer>((int) 0);
            for (ModNum<Integer> p : u.p) {
                PROB = PROB.add(p);
            }
            ans = ans.add(prob.subtract(PROB).multiply(e.second.second.n).multiply(new ModNum<Integer>(ModNum.smallInv(e.second.second.d))));
            prob = PROB;
        }

        System.out.println(ans);
    }
}
