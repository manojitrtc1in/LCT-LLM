import java.util.*;
import java.io.*;
import java.math.BigInteger;

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
        int first, second;

        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    static class Fraction {
        long numerator, denominator;

        public Fraction(long numerator, long denominator) {
            long gcd = gcd(numerator, denominator);
            this.numerator = numerator / gcd;
            this.denominator = denominator / gcd;
        }

        long gcd(long a, long b) {
            if (b == 0)
                return a;
            return gcd(b, a % b);
        }

        public Fraction add(Fraction f) {
            long num = this.numerator * f.denominator + f.numerator * this.denominator;
            long den = this.denominator * f.denominator;
            return new Fraction(num, den);
        }

        public Fraction subtract(Fraction f) {
            long num = this.numerator * f.denominator - f.numerator * this.denominator;
            long den = this.denominator * f.denominator;
            return new Fraction(num, den);
        }

        public Fraction multiply(Fraction f) {
            long num = this.numerator * f.numerator;
            long den = this.denominator * f.denominator;
            return new Fraction(num, den);
        }

        public Fraction divide(Fraction f) {
            long num = this.numerator * f.denominator;
            long den = this.denominator * f.numerator;
            return new Fraction(num, den);
        }

        public double toDouble() {
            return (double) numerator / denominator;
        }

        public long floor() {
            return numerator / denominator - ((numerator < 0) && (numerator % denominator != 0) ? 1 : 0);
        }

        public long ceil() {
            return numerator / denominator + ((numerator > 0) && (numerator % denominator != 0) ? 1 : 0);
        }

        public List<Long> toContinuedFraction() {
            if (denominator == 0)
                return Collections.singletonList(Long.MAX_VALUE);
            List<Long> cont = new ArrayList<>();
            for (long n = numerator, d = denominator;;) {
                long f = (n >= 0 ? n : n - d + 1) / d;
                cont.add(f);
                n -= f * d;
                if (n == 0)
                    break;
                long temp = n;
                n = d;
                d = temp;
            }
            return cont;
        }

        public static Fraction fromContinuedFraction(List<Long> cont) {
            long n = 1, d = 0;
            for (int i = cont.size() - 1; i >= 0; i--) {
                long temp = n;
                n = cont.get(i) * n + d;
                d = temp;
            }
            return new Fraction(n, d);
        }

        public static Fraction bestIn(Fraction x, Fraction y) {
            assert x.compareTo(y) < 0;

            List<Long> x1 = x.toContinuedFraction(), y1 = y.toContinuedFraction();
            List<Long> x2 = new ArrayList<>(x1);
            x2.set(x2.size() - 1, x2.get(x2.size() - 1) - 1);
            x2.add(1L);
            List<Long> y2 = new ArrayList<>(y1);
            y2.set(y2.size() - 1, y2.get(y2.size() - 1) - 1);
            y2.add(1L);

            Function<List<Long>, Fraction> z = (a, b) -> {
                List<Long> c = new ArrayList<>();
                for (int i = 0;; i++) {
                    long ai = i < a.size() ? a.get(i) : Long.MAX_VALUE;
                    long bi = i < b.size() ? b.get(i) : Long.MAX_VALUE;
                    if (ai != bi) {
                        c.add(Math.min(ai, bi) + 1);
                        return Fraction.fromContinuedFraction(c);
                    }
                    c.add(ai);
                }
            };

            Fraction ans = new Fraction(1, 0);
            for (Fraction f : Arrays.asList(z.apply(x1, y1), z.apply(x1, y2), z.apply(x2, y1), z.apply(x2, y2))) {
                if (x.compareTo(f) < 0 && f.compareTo(y) < 0 && (ans.denominator == 0 || f.denominator < ans.denominator))
                    ans = f;
            }
            return ans;
        }

        @Override
        public boolean equals(Object obj) {
            if (this == obj)
                return true;
            if (obj == null || getClass() != obj.getClass())
                return false;
            Fraction fraction = (Fraction) obj;
            return numerator == fraction.numerator && denominator == fraction.denominator;
        }

        @Override
        public int hashCode() {
            return Objects.hash(numerator, denominator);
        }

        @Override
        public String toString() {
            return numerator + "/" + denominator;
        }
    }

    static class ModNum {
        static int MOD;
        int value;

        public ModNum(int value) {
            this.value = value;
        }

        public ModNum add(ModNum num) {
            int sum = this.value + num.value;
            if (sum >= MOD)
                sum -= MOD;
            return new ModNum(sum);
        }

        public ModNum subtract(ModNum num) {
            int diff = this.value - num.value;
            if (diff < 0)
                diff += MOD;
            return new ModNum(diff);
        }

        public ModNum multiply(ModNum num) {
            return new ModNum((int) ((long) this.value * num.value % MOD));
        }

        public ModNum divide(ModNum num) {
            return this.multiply(num.inverse());
        }

        public ModNum inverse() {
            return new ModNum(BigInteger.valueOf(value).modInverse(BigInteger.valueOf(MOD)).intValue());
        }

        public ModNum pow(int exp) {
            ModNum result = new ModNum(1);
            ModNum base = new ModNum(value);
            while (exp > 0) {
                if ((exp & 1) == 1)
                    result = result.multiply(base);
                base = base.multiply(base);
                exp >>= 1;
            }
            return result;
        }

        public static ModNum factorial(int n) {
            ModNum result = new ModNum(1);
            for (int i = 2; i <= n; i++)
                result = result.multiply(new ModNum(i));
            return result;
        }

        public static ModNum inverseFactorial(int n) {
            ModNum result = new ModNum(1);
            for (int i = 2; i <= n; i++)
                result = result.multiply(result.inverse());
            return result;
        }

        public static ModNum smallInverse(int n) {
            return factorial(n - 1).multiply(inverseFactorial(n));
        }

        public static ModNum nCr(int n, int r) {
            return factorial(n).multiply(inverseFactorial(r)).multiply(inverseFactorial(n - r));
        }

        @Override
        public boolean equals(Object obj) {
            if (this == obj)
                return true;
            if (obj == null || getClass() != obj.getClass())
                return false;
            ModNum modNum = (ModNum) obj;
            return value == modNum.value;
        }

        @Override
        public int hashCode() {
            return Objects.hash(value);
        }

        @Override
        public String toString() {
            return String.valueOf(value);
        }
    }

    static class SegmentTree<T> {
        int size;
        T[] tree;
        T identity;
        BiFunction<T, T, T> merge;

        public SegmentTree(int size, T identity, BiFunction<T, T, T> merge) {
            this.size = size;
            this.identity = identity;
            this.merge = merge;
            tree = (T[]) new Object[2 * size];
            Arrays.fill(tree, identity);
        }

        public void setLeaves(Function<Integer, T> create) {
            for (int i = 0; i < size; i++)
                tree[size + i] = create.apply(i);
            for (int i = size - 1; i > 0; i--)
                tree[i] = merge.apply(tree[2 * i], tree[2 * i + 1]);
        }

        public void replace(int index, T value) {
            tree[size + index] = value;
            for (index = (size + index) / 2; index > 0; index /= 2)
                tree[index] = merge.apply(tree[2 * index], tree[2 * index + 1]);
        }

        public T query(int left, int right) {
            T result = identity;
            for (left += size, right += size; left < right; left /= 2, right /= 2) {
                if ((left & 1) == 1)
                    result = merge.apply(result, tree[left++]);
                if ((right & 1) == 1)
                    result = merge.apply(result, tree[--right]);
            }
            return result;
        }

        public T get(int index) {
            return tree[size + index];
        }
    }

    static int MOD = 998244353;

    public static void main(String[] args) {
        FastReader reader = new FastReader();

        int N = reader.nextInt();
        Pair[] pipes = new Pair[N];
        for (int i = 0; i < N; i++) {
            int x = reader.nextInt();
            int v = reader.nextInt();
            int p = reader.nextInt();
            pipes[i] = new Pair(x, v, p);
        }

        List<Pair> evs = new ArrayList<>();

        for (int i = 0; i < N - 1; i++) {
            int dx = pipes[i + 1].first - pipes[i].first;
            int dv = pipes[i + 1].second - pipes[i].second;

            evs.add(new Pair(i, dir.RL, new Fraction(dx, pipes[i + 1].second + pipes[i].second)));

            if (dv > 0)
                evs.add(new Pair(i, dir.LL, new Fraction(dx, dv)));
            if (dv < 0)
                evs.add(new Pair(i, dir.RR, new Fraction(dx, -dv)));
        }

        Collections.sort(evs, (a, b) -> a.t.compareTo(b.t));

        class Node {
            ModNum[] p = new ModNum[4];
            boolean noLL, noRR, noRL, none;

            public Node() {
                for (int i = 0; i < 4; i++)
                    p[i] = new ModNum(0);
                noLL = noRR = noRL = false;
                none = true;
            }
        }

        BiFunction<Node, Node, Node> nn = (a, b) -> {
            if (a.none)
                return b;
            if (b.none)
                return a;
            Node r = new Node();
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++) {
                    boolean iF = (i & 1) != 0, iB = (i & 2) != 0;
                    boolean jF = (j & 1) != 0, jB = (j & 2) != 0;
                    if (a.noLL && !iB && !jF)
                        continue;
                    if (a.noRR && iB && jF)
                        continue;
                    if (a.noRL && iB && !jF)
                        continue;
                    r.p[iF + 2 * jB] = r.p[iF + 2 * jB].add(a.p[i].multiply(b.p[j]));
                }
            return r;
        };

        SegmentTree<Node> st = new SegmentTree<>(N, new Node(), nn);
        st.setLeaves(i -> {
            ModNum pR = new ModNum(pipes[i].third).multiply(ModNum.smallInverse(100));
            Node r = new Node();
            r.p[0] = new ModNum(1).subtract(pR);
            r.p[3] = pR;
            r.none = false;
            return r;
        });

        ModNum ans = new ModNum(0), prob = new ModNum(1);
        for (Pair e : evs) {
            Node c = st.get(e.first);
            switch (e.second) {
                case LL:
                    c.noLL = true;
                    break;
                case RR:
                    c.noRR = true;
                    break;
                case RL:
                    c.noRL = true;
                    break;
            }
            st.replace(e.first, c);

            Node u = st.query(0, st.size);
            ModNum PROB = Arrays.stream(u.p).reduce(new ModNum(0), ModNum::add);
            ans = ans.add(prob.subtract(PROB).multiply(e.t.n).multiply(ModNum.smallInverse(e.t.d)));
            prob = PROB;
        }

        System.out.println(ans);
    }
}
