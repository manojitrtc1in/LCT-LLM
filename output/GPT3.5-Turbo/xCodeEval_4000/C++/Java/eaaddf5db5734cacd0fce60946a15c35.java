import java.io.*;
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

    static class Field<N extends Number> {
        private final int N;
        private final int MOD;
        private final int INV;
        private final int[] POW;

        public Field(int n) {
            N = n;
            MOD = (int) 1e9 + 7;
            INV = pow(N, MOD - 2);
            POW = new int[N + 1];
            POW[0] = 1;
            for (int i = 1; i <= N; i++) {
                POW[i] = mul(POW[i - 1], N);
            }
        }

        private int pow(int a, int p) {
            int r = 1, e = a;
            while (p > 0) {
                if ((p & 1) == 1) {
                    r = mul(r, e);
                }
                e = mul(e, e);
                p >>= 1;
            }
            return r;
        }

        private int mul(int a, int b) {
            return (int) ((1L * a * b) % MOD);
        }

        private int inv(int a) {
            return pow(a, MOD - 2);
        }

        public int add(int a, int b) {
            int sum = a + b;
            if (sum >= MOD) {
                sum -= MOD;
            }
            return sum;
        }

        public int sub(int a, int b) {
            int diff = a - b;
            if (diff < 0) {
                diff += MOD;
            }
            return diff;
        }

        public int mul(int a, int b) {
            return mul(a, b);
        }

        public int div(int a, int b) {
            return mul(a, inv(b));
        }

        public int pow(int a, int p) {
            return pow(a, p);
        }

        public int[] fact(int t) {
            int[] F = new int[t + 1];
            F[0] = 1;
            for (int i = 1; i <= t; i++) {
                F[i] = mul(F[i - 1], i);
            }
            return F;
        }

        public int[] invfact(int t) {
            int[] F = new int[t + 1];
            int X = 1;
            for (int i = 2; i <= t; i++) {
                X = mul(X, i);
            }
            F[t] = inv(X);
            for (int i = t - 1; i >= 2; i--) {
                F[i] = mul(F[i + 1], i + 1);
            }
            return F;
        }
    }

    static class Pair<T, U> {
        T first;
        U second;

        Pair(T first, U second) {
            this.first = first;
            this.second = second;
        }
    }

    static class LSegTree<ValueType, TagType> {
        private final int N;
        private final ValueType NULL_VALUE;
        private final TagType NULL_TAG;
        private final List<Pair<ValueType, TagType>> T;
        private final BiConsumer<TagType, TagType> COMBINE_TAG;
        private final TriConsumer<ValueType, TagType, Integer> APPLY_TAG;
        private final BiFunction<ValueType, ValueType, ValueType> COMBINE_VALUES;

        public LSegTree(List<ValueType> data, ValueType nullValue, TagType nullTag,
                        BiConsumer<TagType, TagType> combineTag,
                        TriConsumer<ValueType, TagType, Integer> applyTag,
                        BiFunction<ValueType, ValueType, ValueType> combineValues) {
            N = 1 << logceil(data.size());
            NULL_VALUE = nullValue;
            NULL_TAG = nullTag;
            COMBINE_TAG = combineTag;
            APPLY_TAG = applyTag;
            COMBINE_VALUES = combineValues;
            T = new ArrayList<>(2 * N);
            for (int i = 0; i < 2 * N; i++) {
                T.add(new Pair<>(nullValue, nullTag));
            }
            for (int i = 0; i < data.size(); i++) {
                T.set(N + i, new Pair<>(data.get(i), nullTag));
            }
            for (int i = N - 1; i > 0; i--) {
                T.set(i, new Pair<>(combineValues.apply(T.get(i << 1).first, T.get(i << 1 | 1).first), nullTag));
            }
        }

        public LSegTree(int size, ValueType nullValue, TagType nullTag,
                        BiConsumer<TagType, TagType> combineTag,
                        TriConsumer<ValueType, TagType, Integer> applyTag,
                        BiFunction<ValueType, ValueType, ValueType> combineValues) {
            N = 1 << logceil(size);
            NULL_VALUE = nullValue;
            NULL_TAG = nullTag;
            COMBINE_TAG = combineTag;
            APPLY_TAG = applyTag;
            COMBINE_VALUES = combineValues;
            T = new ArrayList<>(2 * N);
            for (int i = 0; i < 2 * N; i++) {
                T.add(new Pair<>(nullValue, nullTag));
            }
            for (int i = N - 1; i > 0; i--) {
                T.set(i, new Pair<>(combineValues.apply(T.get(i << 1).first, T.get(i << 1 | 1).first), nullTag));
            }
        }

        public void put(int x, TagType v) {
            put(x, x, v);
        }

        public void put(int from, int to, TagType v) {
            putInner(from, to, v, 1, N);
        }

        public ValueType get(int x) {
            return get(x, x);
        }

        public ValueType get(int from, int to) {
            return getInner(from, to, 1, N);
        }

        private void putInner(int from, int to, TagType v, int i, int s) {
            List<Integer> Q = new ArrayList<>();
            int r = i;
            while (true) {
                if (from == 0 && to == s - 1) {
                    APPLY_TAG.accept(T.get(i).first, v, s);
                    COMBINE_TAG.accept(T.get(i).second, v);
                    break;
                }
                pushTagDown(i, s);
                s >>= 1;
                i <<= 1;
                if ((from & s) != 0) {
                    from ^= s;
                    to ^= s;
                    i ^= 1;
                } else if ((to & s) != 0) {
                    putInner(0, to ^ s, v, i | 1, s);
                    to = s - 1;
                }
            }

            while (i != r) {
                T.set(i >> 1, new Pair<>(COMBINE_VALUES.apply(T.get(i).first, T.get(i ^ 1).first), T.get(i >> 1).second));
                i >>= 1;
            }
        }

        private ValueType getInner(int from, int to, int i, int s) {
            while (true) {
                if (from == 0 && to == s - 1) {
                    return T.get(i).first;
                }
                pushTagDown(i, s);
                s >>= 1;
                i <<= 1;
                if ((to & s) != 0) {
                    to ^= s;
                    if ((from & s) != 0) {
                        from ^= s;
                        i |= 1;
                    } else {
                        ValueType a = getInner(from, s - 1, i, s);
                        ValueType b = getInner(0, to, i | 1, s);
                        return COMBINE_VALUES.apply(a, b);
                    }
                }
            }
        }

        private void pushTagDown(int i, int s) {
            APPLY_TAG.accept(T.get(i << 1).first, T.get(i).second, s >> 1);
            APPLY_TAG.accept(T.get(i << 1 | 1).first, T.get(i).second, s >> 1);
            COMBINE_TAG.accept(T.get(i << 1).second, T.get(i).second);
            COMBINE_TAG.accept(T.get(i << 1 | 1).second, T.get(i).second);
            T.set(i, new Pair<>(T.get(i << 1).first, NULL_TAG));
        }

        private int logceil(int x) {
            return 32 - Integer.numberOfLeadingZeros(x - 1);
        }
    }

    static class LAddOp<F> {
        void accept(F a, F b) {
            a += b;
        }
    }

    static class LAddOp2<F> {
        void accept(F a, F b, int s) {
            a += b;
        }
    }

    static class LMinOp<F> {
        F apply(F a, F b) {
            return Math.min(a, b);
        }
    }

    static class LMaxOp<F> {
        F apply(F a, F b) {
            return Math.max(a, b);
        }
    }

    static class LSumOp<T> {
        T apply(T a, T b) {
            return a + b;
        }
    }

    static class LAssignOp<T> {
        void accept(T a, T b) {
            if (b != 0) {
                a = b;
            }
        }
    }

    static class LAssignOp2<T> {
        void accept(T a, T b, int s) {
            if (b != 0) {
                a = b;
            }
        }
    }

    static class LAssignMultOp<T> {
        void accept(T a, T b, int s) {
            if (b != 0) {
                a = b * s;
            }
        }
    }

    static class DDostizhimieStroki {
        public void solve(FastReader in, PrintWriter out) {
            int n = in.nextInt();
            String s = in.next();
            n = s.length();

            s = "0" + s + "0";

            List<Integer> st = new ArrayList<>();
            List<Integer> p = new ArrayList<>();
            List<Integer> f = new ArrayList<>();
            String t = "";

            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == '1' && s.charAt(i + 1) == '1') {
                    i++;
                    continue;
                }

                t += s.charAt(i);
                st.add(t.length() - 1);
            }

            p.add(0);
            if (s.charAt(0) == '1') {
                p.add(1);
            }

            for (int i = 1; i < s.length(); i++) {
                if (s.charAt(i) == '0') {
                    p.add(0);
                } else {
                    p.add(p.get(i - 1) + 1);
                }
            }

            f.add(0);
            for (int i = s.length() - 2; i >= 0; i--) {
                if (s.charAt(i) == '0') {
                    f.add(0);
                } else {
                    f.add(f.get(f.size() - 1) + 1);
                }
            }

            List<Integer> h1 = new ArrayList<>();
            List<Integer> h2 = new ArrayList<>();

            buildHash(t, h1, h2);

            int q = in.nextInt();

            for (int i = 0; i < q; i++) {
                int a = in.nextInt();
                int b = in.nextInt();
                int c = in.nextInt();

                Pair<Pair<Integer, Integer>, Integer> h1a = getH(a, a + c - 1, st, p, f, h1, h2);
                Pair<Pair<Integer, Integer>, Integer> h1b = getH(b, b + c - 1, st, p, f, h1, h2);

                if (h1a.first.equals(h1b.first)) {
                    out.println("Yes");
                } else {
                    out.println("No");
                }
            }
        }

        private void buildHash(String t, List<Integer> h1, List<Integer> h2) {
            int p1 = 7;
            int p2 = 13;

            int[] pow1 = new int[t.length() + 1];
            int[] pow2 = new int[t.length() + 1];
            pow1[0] = 1;
            pow2[0] = 1;

            for (int i = 1; i <= t.length(); i++) {
                pow1[i] = pow1[i - 1] * p1;
                pow2[i] = pow2[i - 1] * p2;
            }

            int h1Val = 0;
            int h2Val = 0;

            for (int i = 0; i < t.length(); i++) {
                h1Val += t.charAt(i) * pow1[i];
                h2Val += t.charAt(i) * pow2[i];
                h1.add(h1Val);
                h2.add(h2Val);
            }
        }

        private Pair<Pair<Integer, Integer>, Integer> getH(int l, int r, List<Integer> st, List<Integer> p, List<Integer> f, List<Integer> h1, List<Integer> h2) {
            if (l + f.get(l) - 1 >= r) {
                return new Pair<>(new Pair<>(-1, -1), -1);
            }

            int b = st.get(l + f.get(l));
            int e = st.get(r - p.get(r));

            int len = e - b + 1;

            int hm1 = (h1.get(e) - h1.get(b - 1)) / pow1(b);
            if (p.get(r) % 2 == 1) {
                len++;
                hm1 += pow1(e - b + 1);
            }

            if (f.get(l) % 2 == 1) {
                len++;
                hm1 = 1 + hm1 * pow1(b);
            }

            int hm2 = (h2.get(e) - h2.get(b - 1)) / pow2(b);
            if (p.get(r) % 2 == 1) {
                hm2 += pow2(e - b + 1);
            }

            if (f.get(l) % 2 == 1) {
                hm2 = 1 + hm2 * pow2(b);
            }

            return new Pair<>(new Pair<>(hm1, hm2), len);
        }

        private int pow1(int b) {
            return pow(p1, b);
        }

        private int pow2(int b) {
            return pow(p2, b);
        }

        private int pow(int a, int b) {
            int res = 1;
            while (b > 0) {
                if ((b & 1) == 1) {
                    res *= a;
                }
                a *= a;
                b >>= 1;
            }
            return res;
        }
    }

    public static void main(String[] args) {
        FastReader in = new FastReader();
        PrintWriter out = new PrintWriter(System.out);
        DDostizhimieStroki solver = new DDostizhimieStroki();
        solver.solve(in, out);
        out.close();
    }
}
