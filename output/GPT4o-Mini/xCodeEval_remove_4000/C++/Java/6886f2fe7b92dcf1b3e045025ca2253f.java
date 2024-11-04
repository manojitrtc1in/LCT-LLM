import java.util.*;
import java.util.function.Function;

public class 6886f2fe7b92dcf1b3e045025ca2253fxcodeeval_processed_4000.json {
    static final long MAX_MOD = 1000000007;
    static final long MOD = 1000000009;
    static final double eps = 1e-9;

    static class Point {
        double real, imag;

        Point(double real, double imag) {
            this.real = real;
            this.imag = imag;
        }

        Point subtract(Point other) {
            return new Point(this.real - other.real, this.imag - other.imag);
        }

        double abs() {
            return Math.sqrt(real * real + imag * imag);
        }

        double dot(Point other) {
            return this.real * other.real + this.imag * other.imag;
        }

        double cross(Point other) {
            return this.real * other.imag - this.imag * other.real;
        }
    }

    static class Line {
        Point first, second;

        Line(Point first, Point second) {
            this.first = first;
            this.second = second;
        }
    }

    static class Circle {
        Point center;
        double r;

        Circle(Point center, double r) {
            this.center = center;
            this.r = r;
        }
    }

    static double id3(Line a, Point b) {
        if (a.second.subtract(a.first).dot(b.subtract(a.first)) < eps) return b.subtract(a.first).abs();
        if (a.first.subtract(a.second).dot(b.subtract(a.second)) < eps) return b.subtract(a.second).abs();
        return Math.abs(a.second.subtract(a.first).cross(b.subtract(a.first))) / a.second.subtract(a.first).abs();
    }

    static boolean id0(Line a, Line b) {
        return (a.second.subtract(a.first).cross(b.first.subtract(a.first)) * a.second.subtract(a.first).cross(b.second.subtract(a.first)) < eps) &&
                (b.second.subtract(b.first).cross(a.first.subtract(b.first)) * b.second.subtract(b.first).cross(a.second.subtract(b.first)) < eps);
    }

    static Point intersection_l(Line a, Line b) {
        Point da = a.second.subtract(a.first);
        Point db = b.second.subtract(b.first);
        return new Point(a.first.real + da.cross(db) / da.cross(db), a.first.imag + da.cross(db) / da.cross(db));
    }

    static double id8(Line a, Line b) {
        if (id0(a, b)) {
            return 0;
        }
        return Math.min(Math.min(id3(a, b.first), id3(a, b.second)), Math.min(id3(b, a.first), id3(b, a.second)));
    }

    static Pair<Point, Point> id9(Circle a, Circle b) {
        double dist = a.center.subtract(b.center).abs();
        assert dist <= eps + a.r + b.r;
        assert dist + eps >= Math.abs(a.r - b.r);
        Point target = b.center.subtract(a.center);
        double pointer = target.real * target.real + target.imag * target.imag;
        double aa = (pointer + a.r * a.r - b.r * b.r) / 2.0;
        Point l = new Point((aa * target.real + target.imag * Math.sqrt(pointer * a.r * a.r - aa * aa)) / pointer,
                (aa * target.imag - target.real * Math.sqrt(pointer * a.r * a.r - aa * aa)) / pointer);
        Point r = new Point((aa * target.real - target.imag * Math.sqrt(pointer * a.r * a.r - aa * aa)) / pointer,
                (aa * target.imag + target.real * Math.sqrt(pointer * a.r * a.r - aa * aa)) / pointer);
        r = new Point(r.real + a.center.real, r.imag + a.center.imag);
        l = new Point(l.real + a.center.real, l.imag + a.center.imag);
        return new Pair<>(l, r);
    }

    static long gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    static <A> A pows(A val, long b) {
        assert b >= 1;
        A ans = val;
        b--;
        while (b > 0) {
            if (b % 2 == 1) {
                ans = multiply(ans, val);
            }
            val = multiply(val, val);
            b /= 2;
        }
        return ans;
    }

    static class Compressor<A> {
        boolean id6 = false;
        Map<A, Long> zipper = new HashMap<>();
        Map<Long, A> unzipper = new HashMap<>();
        Queue<A> fetcher = new LinkedList<>();

        void add(A now) {
            assert !id6;
            zipper.put(now, 1L);
            fetcher.add(now);
        }

        void exec() {
            assert !id6;
            int cnt = 0;
            for (Map.Entry<A, Long> entry : zipper.entrySet()) {
                entry.setValue((long) cnt);
                unzipper.put((long) cnt, entry.getKey());
                cnt++;
            }
            id6 = true;
        }

        long fetch() {
            assert id6;
            A hoge = fetcher.poll();
            return zipper.get(hoge);
        }

        long zip(A now) {
            assert id6;
            assert zipper.containsKey(now);
            return zipper.get(now);
        }

        A unzip(long a) {
            assert id6;
            assert a < unzipper.size();
            return unzipper.get(a);
        }

        long next(A now) {
            Map.Entry<A, Long> x = zipper.higherEntry(now);
            if (x == null) return zipper.size();
            return x.getValue();
        }

        long back(A now) {
            Map.Entry<A, Long> x = zipper.lowerEntry(now);
            if (x == null) return -1;
            return x.getValue();
        }
    }

    static class Matrix<A> {
        List<List<A>> data;

        Matrix(List<List<A>> a) {
            this.data = a;
        }

        Matrix<A> add(Matrix<A> obj) {
            List<List<A>> ans = new ArrayList<>();
            assert obj.data.size() == this.data.size();
            assert obj.data.get(0).size() == this.data.get(0).size();
            for (int i = 0; i < obj.data.size(); i++) {
                ans.add(new ArrayList<>());
                for (int q = 0; q < obj.data.get(i).size(); q++) {
                    A hoge = add(this.data.get(i).get(q), obj.data.get(i).get(q));
                    ans.get(ans.size() - 1).add(hoge);
                }
            }
            return new Matrix<>(ans);
        }

        Matrix<A> subtract(Matrix<A> obj) {
            List<List<A>> ans = new ArrayList<>();
            assert obj.data.size() == this.data.size();
            assert obj.data.get(0).size() == this.data.get(0).size();
            for (int i = 0; i < obj.data.size(); i++) {
                ans.add(new ArrayList<>());
                for (int q = 0; q < obj.data.get(i).size(); q++) {
                    A hoge = subtract(this.data.get(i).get(q), obj.data.get(i).get(q));
                    ans.get(ans.size() - 1).add(hoge);
                }
            }
            return new Matrix<>(ans);
        }

        Matrix<A> multiply(Matrix<A> obj) {
            List<List<A>> ans = new ArrayList<>();
            assert obj.data.size() == this.data.get(0).size();
            for (int i = 0; i < this.data.size(); i++) {
                ans.add(new ArrayList<>());
                for (int q = 0; q < obj.data.get(0).size(); q++) {
                    A hoge = multiply(this.data.get(i).get(0), obj.data.get(0).get(q));
                    for (int t = 1; t < obj.data.get(i).size(); t++) {
                        hoge = add(hoge, multiply(this.data.get(i).get(t), obj.data.get(t).get(q)));
                    }
                    ans.get(ans.size() - 1).add(hoge);
                }
            }
            return new Matrix<>(ans);
        }

        Matrix<A> multiplyAssign(Matrix<A> obj) {
            return this.multiply(obj);
        }

        Matrix<A> addAssign(Matrix<A> obj) {
            return this.add(obj);
        }

        Matrix<A> subtractAssign(Matrix<A> obj) {
            return this.subtract(obj);
        }
    }

    static class Fraction {
        long a;
        long b;

        Fraction() {
            this.a = 0;
            this.b = 1;
        }

        Fraction(long c, long d) {
            long hoge = gcd(Math.abs(c), Math.abs(d));
            c /= hoge;
            d /= hoge;
            if (d < 0) {
                d *= -1;
                c *= -1;
            }
            this.a = c;
            this.b = d;
        }

        boolean lessThan(Fraction rhs) {
            return a * rhs.b < rhs.a * b;
        }
    }

    static class ModInt {
        long value = 0;

        ModInt() {
            this.value = 0;
        }

        ModInt(long a) {
            this.value = ((a % MAX_MOD) + 2 * MAX_MOD) % MAX_MOD;
        }

        ModInt add(ModInt rhs) {
            return new ModInt(this.value + rhs.value);
        }

        ModInt subtract(ModInt rhs) {
            return new ModInt(this.value - rhs.value);
        }

        ModInt multiply(ModInt rhs) {
            return new ModInt((this.value * rhs.value) % MAX_MOD);
        }

        ModInt divide(ModInt rhs) {
            long rem = MAX_MOD - 2;
            while (rem > 0) {
                if (rem % 2 == 1) {
                    this.multiply(rhs);
                }
                rhs.multiply(rhs);
                rem /= 2;
            }
            return this;
        }

        boolean lessThan(ModInt rhs) {
            return this.value < rhs.value;
        }

        @Override
        public String toString() {
            return String.valueOf(value);
        }
    }

    static class Dice {
        List<Long> vertexs;

        Dice(List<Long> init) {
            this.vertexs = init;
        }

        void RtoL() {
            for (int q = 1; q < 4; q++) {
                Collections.swap(vertexs, q, q + 1);
            }
        }

        void LtoR() {
            for (int q = 3; q >= 1; q--) {
                Collections.swap(vertexs, q, q + 1);
            }
        }

        void UtoD() {
            Collections.swap(vertexs, 5, 4);
            Collections.swap(vertexs, 2, 5);
            Collections.swap(vertexs, 0, 2);
        }

        void DtoU() {
            Collections.swap(vertexs, 0, 2);
            Collections.swap(vertexs, 2, 5);
            Collections.swap(vertexs, 5, 4);
        }

        boolean ReachAble(Dice now) {
            Set<Dice> hoge = new HashSet<>();
            Queue<Dice> next = new LinkedList<>();
            next.add(now);
            hoge.add(now);
            while (!next.isEmpty()) {
                Dice seeing = next.poll();
                if (seeing.equals(this)) return true;
                seeing.RtoL();
                if (!hoge.contains(seeing)) {
                    hoge.add(seeing);
                    next.add(seeing);
                }
                seeing.LtoR();
                seeing.LtoR();
                if (!hoge.contains(seeing)) {
                    hoge.add(seeing);
                    next.add(seeing);
                }
                seeing.RtoL();
                seeing.UtoD();
                if (!hoge.contains(seeing)) {
                    hoge.add(seeing);
                    next.add(seeing);
                }
                seeing.DtoU();
                seeing.DtoU();
                if (!hoge.contains(seeing)) {
                    hoge.add(seeing);
                    next.add(seeing);
                }
            }
            return false;
        }

        @Override
        public boolean equals(Object obj) {
            if (this == obj) return true;
            if (!(obj instanceof Dice)) return false;
            Dice a = (Dice) obj;
            for (int q = 0; q < 6; q++) {
                if (!a.vertexs.get(q).equals(this.vertexs.get(q))) {
                    return false;
                }
            }
            return true;
        }

        @Override
        public int hashCode() {
            return Objects.hash(vertexs);
        }
    }

    static Pair<Dice, Dice> id1(int center, int up) {
        int target = 1;
        while (true) {
            if (center != target && 7 - center != target && up != target && 7 - up != target) {
                break;
            }
            target++;
        }
        return new Pair<>(new Dice(Arrays.asList((long) up, (long) target, (long) center, (long) (7 - target), (long) (7 - center), (long) (7 - up))),
                new Dice(Arrays.asList((long) up, (long) (7 - target), (long) center, (long) target, (long) (7 - center), (long) (7 - up))));
    }

    static Tuple<Dice, Dice, Dice, Dice> id2(int center) {
        int bo = Math.min(center, 7 - center);
        Pair<Integer, Integer> goa;
        if (bo == 1) {
            goa = new Pair<>(2, 3);
        } else if (bo == 2) {
            goa = new Pair<>(1, 3);
        } else if (bo == 3) {
            goa = new Pair<>(1, 2);
        }
        return new Tuple<>(new Dice(Arrays.asList((long) goa.first, (long) goa.second, (long) center, (long) (7 - goa.second), (long) (7 - center), (long) (7 - goa.first))),
                new Dice(Arrays.asList((long) goa.first, (long) (7 - goa.second), (long) center, (long) goa.second, (long) (7 - center), (long) (7 - goa.first))),
                new Dice(Arrays.asList((long) (7 - goa.first), (long) goa.second, (long) center, (long) (7 - goa.second), (long) (7 - center), (long) goa.first)),
                new Dice(Arrays.asList((long) (7 - goa.first), (long) (7 - goa.second), (long) center, (long) goa.second, (long) (7 - center), (long) goa.first)));
    }

    static class Dijkstra<A, B> {
        List<List<Pair<Integer, A>>> vertexs;
        B Cost_Function;

        Dijkstra(int n, B cost) {
            this.Cost_Function = cost;
            vertexs = new ArrayList<>(n);
            for (int i = 0; i < n; i++) {
                vertexs.add(new ArrayList<>());
            }
        }

        void add_edge(int a, int b, A c) {
            vertexs.get(a).add(new Pair<>(b, c));
        }

        List<Long> build_result(int StartPoint) {
            List<Long> dist = new ArrayList<>(Collections.nCopies(vertexs.size(), 2e18));
            dist.set(StartPoint, 0L);
            PriorityQueue<Pair<Long, Integer>> next = new PriorityQueue<>(Comparator.comparingLong(pair -> pair.first));
            next.add(new Pair<>(0L, StartPoint));
            while (!next.isEmpty()) {
                Pair<Long, Integer> now = next.poll();
                if (!dist.get(now.second).equals(now.first)) continue;
                for (Pair<Integer, A> x : vertexs.get(now.second)) {
                    long now_cost = now.first + Cost_Function.apply(x.second);
                    if (dist.get(x.first) > now_cost) {
                        dist.set(x.first, now_cost);
                        next.add(new Pair<>(now_cost, x.first));
                    }
                }
            }
            return dist;
        }
    }

    static class Dinic {
        static class Edge {
            int to;
            int cap;
            int rev;

            Edge(int to, int cap, int rev) {
                this.to = to;
                this.cap = cap;
                this.rev = rev;
            }
        }

        List<List<Edge>> Graph;
        List<Integer> level;
        List<Integer> itr;

        Dinic(int n) {
            Graph = new ArrayList<>(n);
            for (int i = 0; i < n; i++) {
                Graph.add(new ArrayList<>());
            }
        }

        void add_edge(int a, int b, int cap) {
            Graph.get(a).add(new Edge(b, cap, Graph.get(b).size()));
            Graph.get(b).add(new Edge(a, 0, Graph.get(a).size() - 1));
        }

        void bfs(int s) {
            level = new ArrayList<>(Collections.nCopies(Graph.size(), -1));
            level.set(s, 0);
            Queue<Integer> next = new LinkedList<>();
            next.add(s);
            while (!next.isEmpty()) {
                int now = next.poll();
                for (Edge x : Graph.get(now)) {
                    if (x.cap == 0) continue;
                    if (level.get(x.to) == -1) {
                        level.set(x.to, level.get(now) + 1);
                        next.add(x.to);
                    }
                }
            }
        }

        int dfs(int now, int goal, int val) {
            if (goal == now) return val;
            for (int i = itr.get(now); i < Graph.get(now).size(); i++) {
                Edge target = Graph.get(now).get(i);
                if (target.cap > 0 && level.get(now) < level.get(target.to)) {
                    int d = dfs(target.to, goal, Math.min(val, target.cap));
                    if (d > 0) {
                        target.cap -= d;
                        Graph.get(target.to).get(target.rev).cap += d;
                        return d;
                    }
                }
            }
            return 0;
        }

        int run(int s, int t) {
            int ans = 0;
            int f;
            while (true) {
                bfs(s);
                if (level.get(t) < 0) break;
                itr = new ArrayList<>(Collections.nCopies(Graph.size(), 0));
                while ((f = dfs(s, t, Integer.MAX_VALUE)) > 0) {
                    ans += f;
                }
            }
            return ans;
        }
    }

    static class Id7 {
        List<List<Integer>> vertexs;
        List<Integer> depth;
        List<Integer> backs;
        List<Integer> connections;
        List<Integer> zip, unzip;

        Id7(int n) {
            vertexs = new ArrayList<>(n);
            for (int i = 0; i < n; i++) {
                vertexs.add(new ArrayList<>());
            }
            depth = new ArrayList<>(Collections.nCopies(n, 0));
            zip = new ArrayList<>(Collections.nCopies(n, 0));
            unzip = new ArrayList<>(Collections.nCopies(n, 0));
        }

        void add_edge(int a, int b) {
            vertexs.get(a).add(b);
            vertexs.get(b).add(a);
        }

        int depth_dfs(int now, int back) {
            depth.set(now, 0);
            for (int x : vertexs.get(now)) {
                if (x == back) continue;
                depth.set(now, Math.max(depth.get(now), 1 + depth_dfs(x, now)));
            }
            return depth.get(now);
        }

        void dfs(int now, int backing) {
            zip.set(now, backs.size());
            unzip.set(backs.size(), now);
            backs.add(backing);
            int now_max = -1;
            int itr = -1;
            for (int x : vertexs.get(now)) {
                if (depth.get(x) > depth.get(now)) continue;
                if (now_max < depth.get(x)) {
                    now_max = depth.get(x);
                    itr = x;
                }
            }
            if (itr == -1) return;
            connections.add(connections.get(connections.size() - 1));
            dfs(itr, backing);
            for (int x : vertexs.get(now)) {
                if (depth.get(x) > depth.get(now)) continue;
                if (x == itr) continue;
                connections.add(zip.get(now));
                dfs(x, backs.size());
            }
        }

        void build() {
            depth_dfs(0, -1);
            connections.add(-1);
            dfs(0, -1);
        }

        List<Pair<Integer, Integer>> query(int a, int b) {
            a = zip.get(a);
            b = zip.get(b);
            List<Pair<Integer, Integer>> ans = new ArrayList<>();
            while (backs.get(a) != backs.get(b)) {
                if (a < b) {
                    int temp = a;
                    a = b;
                    b = temp;
                }
                ans.add(new Pair<>(backs.get(a), a + 1));
                a = connections.get(a);
            }
            if (a > b) {
                int temp = a;
                a = b;
                b = temp;
            }
            ans.add(new Pair<>(a, b + 1));
            return ans;
        }

        int lca(int a, int b) {
            a = zip.get(a);
            b = zip.get(b);
            while (backs.get(a) != backs.get(b)) {
                if (a < b) {
                    int temp = a;
                    a = b;
                    b = temp;
                }
                a = connections.get(a);
            }
            return unzip.get(Math.min(a, b));
        }
    }

    static class SegmentTree<Monoid> {
        int sz;
        List<Monoid> seg;
        Function<Monoid, Monoid> f;
        Monoid M1;

        SegmentTree(int n, Function<Monoid, Monoid> f, Monoid M1) {
            this.f = f;
            this.M1 = M1;
            sz = 1;
            while (sz < n) sz <<= 1;
            seg = new ArrayList<>(Collections.nCopies(2 * sz + 1, M1));
        }

        void set(int k, Monoid x) {
            seg.set(k + sz, x);
        }

        void build() {
            for (int k = sz - 1; k > 0; k--) {
                seg.set(k, f.apply(seg.get(2 * k + 0), seg.get(2 * k + 1)));
            }
        }

        void update(int k, Monoid x) {
            k += sz;
            seg.set(k, x);
            while (k >>= 1) {
                seg.set(k, f.apply(seg.get(2 * k + 0), seg.get(2 * k + 1)));
            }
        }

        Monoid query(int a, int b) {
            Monoid L = M1, R = M1;
            for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
                if ((a & 1) == 1) L = f.apply(L, seg.get(a++));
                if ((b & 1) == 1) R = f.apply(seg.get(--b), R);
            }
            return f.apply(L, R);
        }

        Monoid get(int k) {
            return seg.get(k + sz);
        }
    }

    static class Id5<Monoid, OperatorMonoid> {
        int sz, height;
        List<Monoid> data;
        List<OperatorMonoid> lazy;
        Function<Monoid, Monoid> f;
        Function<Monoid, OperatorMonoid, Integer> g;
        Function<OperatorMonoid, OperatorMonoid> h;
        Monoid M1;
        OperatorMonoid OM0;

        Id5(int n, Function<Monoid, Monoid> f, Function<Monoid, OperatorMonoid, Integer> g, Function<OperatorMonoid, OperatorMonoid> h,
            Monoid M1, OperatorMonoid OM0) {
            this.f = f;
            this.g = g;
            this.h = h;
            this.M1 = M1;
            this.OM0 = OM0;
            sz = 1;
            height = 0;
            while (sz < n) sz <<= 1;
            data = new ArrayList<>(Collections.nCopies(2 * sz, M1));
            lazy = new ArrayList<>(Collections.nCopies(2 * sz, OM0));
        }

        void set(int k, Monoid x) {
            data.set(k + sz, x);
        }

        void build() {
            for (int k = sz - 1; k > 0; k--) {
                data.set(k, f.apply(data.get(2 * k + 0), data.get(2 * k + 1)));
            }
        }

        void propagate(int k) {
            if (!lazy.get(k).equals(OM0)) {
                lazy.set(2 * k + 0, h.apply(lazy.get(2 * k + 0), lazy.get(k)));
                lazy.set(2 * k + 1, h.apply(lazy.get(2 * k + 1), lazy.get(k)));
                data.set(k, reflect(k));
                lazy.set(k, OM0);
            }
        }

        Monoid reflect(int k) {
            if (lazy.get(k).equals(OM0)) return data.get(k);
            for (int q = sz; q >= 0; q /= 2) {
                if ((q & k) != 0) {
                    return g.apply(data.get(k), lazy.get(k), sz / q);
                }
            }
            return null;
        }

        void recalc(int k) {
            while (k >>= 1) data.set(k, f.apply(reflect(2 * k + 0), reflect(2 * k + 1)));
        }

        void thrust(int k) {
            for (int i = height; i > 0; i--) propagate(k >> i);
        }

        void update(int a, int b, OperatorMonoid x) {
            thrust(a += sz);
            thrust(b += sz - 1);
            for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
                if ((l & 1) == 1) {
                    lazy.set(l, h.apply(lazy.get(l), x));
                    l++;
                }
                if ((r & 1) == 1) {
                    r--;
                    lazy.set(r, h.apply(lazy.get(r), x));
                }
            }
            recalc(a);
            recalc(b);
        }

        Monoid query(int a, int b) {
            thrust(a += sz);
            thrust(b += sz - 1);
            Monoid L = M1, R = M1;
            for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
                if ((l & 1) == 1) L = f.apply(L, reflect(l++));
                if ((r & 1) == 1) R = f.apply(reflect(--r), R);
            }
            return f.apply(L, R);
        }

        Monoid get(int k) {
            return query(k, k + 1);
        }
    }

    static class KMP {
        List<Integer> table;
        List<Integer> Pattern;

        KMP(List<Integer> a) {
            build(a);
        }

        void build(List<Integer> a) {
            Pattern = a;
            table = new ArrayList<>(Collections.nCopies(a.size() + 1, -1));
            int j = -1;
            for (int i = 0; i < a.size(); i++) {
                while (j >= 0 && Pattern.get(i) != Pattern.get(j)) {
                    j = table.get(j);
                }
                table.set(i + 1, ++j);
            }
        }

        List<Integer> search(List<Integer> a) {
            List<Integer> ans = new ArrayList<>();
            for (int i = 0, k = 0; i < a.size(); i++) {
                while (k >= 0 && a.get(i) != Pattern.get(k)) k = table.get(k);
                k++;
                if (k >= Pattern.size()) {
                    ans.add(i - Pattern.size() + 1);
                    k = table.get(k);
                }
            }
            return ans;
        }
    }

    static long xor128() {
        long x = 123456789, y = 362436069, z = 521288629, w = 88675123;
        long t = (x ^ (x << 11));
        x = y; y = z; z = w;
        return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
    }

    static void init() {
        // No direct equivalent in Java for iostream::sync_with_stdio(false);
        // Set precision is not needed in Java as we can control it during output.
    }

    static List<Integer> cnter = new ArrayList<>();
    static Pair<ModInt, ModInt>[] hoge = new Pair[300000];
    static Pair<ModInt, ModInt>[] rev = new Pair[300000];

    static void solve() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        String t = scanner.next();
        for (int i = 0; i < t.length(); i++) {
            if (t.charAt(i) == '0') {
                cnter.add(i * 2 + i % 2);
            }
        }
        Pair<ModInt, ModInt> nexts = new Pair<>(new ModInt(1), new ModInt(1));
        for (int i = 0; i < cnter.size(); i++) {
            hoge[i + 1] = hoge[i];
            hoge[i + 1].first = add(hoge[i + 1].first, multiply(nexts.first, cnter.get(i) % 2));
            hoge[i + 1].second = add(hoge[i + 1].second, multiply(nexts.second, cnter.get(i) % 2));
            rev[i + 1] = rev[i];
            rev[i + 1].first = add(rev[i + 1].first, multiply(nexts.first, (cnter.get(i) + 1) % 2));
            rev[i + 1].second = add(rev[i + 1].second, multiply(nexts.second, (cnter.get(i) + 1) % 2));
            nexts.first = multiply(nexts.first, new ModInt(2));
            nexts.second = multiply(nexts.second, new ModInt(2));
        }
        int query = scanner.nextInt();
        for (int i = 0; i < query; i++) {
            int a = scanner.nextInt() - 1;
            int b = scanner.nextInt() - 1;
            int c = scanner.nextInt();
            Pair<Integer, Integer> Left = new Pair<>(lowerBound(cnter, a * 2), lowerBound(cnter, (a + c) * 2));
            Pair<Integer, Integer> Right = new Pair<>(lowerBound(cnter, b * 2), lowerBound(cnter, (b + c) * 2));
            if (Left.second - Left.first != Right.second - Right.first) {
                System.out.println("No");
                continue;
            }
            int ok = 1;
            Pair<ModInt, ModInt> aa = hoge[Left.second];
            aa.first = subtract(aa.first, hoge[Left.first].first);
            aa.second = subtract(aa.second, hoge[Left.first].second);
            Pair<ModInt, ModInt> bb;
            if (a % 2 == b % 2) {
                bb = hoge[Right.second];
                bb.first = subtract(bb.first, hoge[Right.first].first);
                bb.second = subtract(bb.second, hoge[Right.first].second);
            } else {
                bb = rev[Right.second];
                bb.first = subtract(bb.first, rev[Right.first].first);
                bb.second = subtract(bb.second, rev[Right.first].second);
            }
            if (Left.first != 0) {
                aa.first = divide(aa.first, pows(new ModInt(2), Left.first));
                aa.second = divide(aa.second, pows(new ModInt(2), Left.first));
            }
            if (Right.first != 0) {
                bb.first = divide(bb.first, pows(new ModInt(2), Right.first));
                bb.second = divide(bb.second, pows(new ModInt(2), Right.first));
            }
            if (aa.first.value != bb.first.value || aa.second.value != bb.second.value) {
                ok = 0;
            }
            if (ok == 1) {
                System.out.println("Yes");
            } else {
                System.out.println("No");
            }
        }
    }

    public static void main(String[] args) {
        init();
        solve();
    }

    // Helper methods for operations
    static ModInt add(ModInt a, ModInt b) {
        return a.add(b);
    }

    static ModInt subtract(ModInt a, ModInt b) {
        return a.subtract(b);
    }

    static ModInt multiply(ModInt a, ModInt b) {
        return a.multiply(b);
    }

    static ModInt divide(ModInt a, ModInt b) {
        return a.divide(b);
    }

    static int lowerBound(List<Integer> list, int value) {
        int low = 0, high = list.size();
        while (low < high) {
            int mid = (low + high) / 2;
            if (list.get(mid) < value) low = mid + 1;
            else high = mid;
        }
        return low;
    }

    static ModInt pows(ModInt val, long b) {
        assert b >= 1;
        ModInt ans = val;
        b--;
        while (b > 0) {
            if (b % 2 == 1) {
                ans = multiply(ans, val);
            }
            val = multiply(val, val);
            b /= 2;
        }
        return ans;
    }
}
