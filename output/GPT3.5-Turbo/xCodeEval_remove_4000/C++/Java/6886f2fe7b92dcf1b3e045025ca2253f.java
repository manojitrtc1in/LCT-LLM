import java.util.*;
import java.io.*;
import java.math.*;

class Main {
    static final int MAX_MOD = (int)1e9 + 7;
    static final int MOD = (int)1e9 + 9;

    static class modint {
        long value;

        modint(long a) {
            value = ((a % MOD) + 2 * MOD) % MOD;
        }

        modint add(modint rhs) {
            return new modint((value + rhs.value) % MOD);
        }

        modint subtract(modint rhs) {
            return new modint((value - rhs.value + MOD) % MOD);
        }

        modint multiply(modint rhs) {
            return new modint((value * rhs.value) % MOD);
        }

        modint divide(modint rhs) {
            long rem = MOD - 2;
            modint ans = new modint(1);
            modint val = new modint(value);
            while (rem > 0) {
                if (rem % 2 == 1) {
                    ans = ans.multiply(val);
                }
                val = val.multiply(val);
                rem /= 2;
            }
            return ans;
        }

        public String toString() {
            return Long.toString(value);
        }
    }

    static class Point {
        long x;
        long y;

        Point(long x, long y) {
            this.x = x;
            this.y = y;
        }
    }

    static class Line {
        Point a;
        Point b;

        Line(Point a, Point b) {
            this.a = a;
            this.b = b;
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

    static double dot(Point a, Point b) {
        return (a.x * b.x + a.y * b.y);
    }

    static double cross(Point a, Point b) {
        return (a.x * b.y - a.y * b.x);
    }

    static double id3(Line a, Point b) {
        double eps = 1e-9;
        if (dot(new Point(a.b.x - a.a.x, a.b.y - a.a.y), new Point(b.x - a.a.x, b.y - a.a.y)) < eps) return Math.abs(Math.sqrt(Math.pow(b.x - a.a.x, 2) + Math.pow(b.y - a.a.y, 2)));
        if (dot(new Point(a.a.x - a.b.x, a.a.y - a.b.y), new Point(b.x - a.b.x, b.y - a.b.y)) < eps) return Math.abs(Math.sqrt(Math.pow(b.x - a.b.x, 2) + Math.pow(b.y - a.b.y, 2)));
        return Math.abs(cross(new Point(a.b.x - a.a.x, a.b.y - a.a.y), new Point(b.x - a.a.x, b.y - a.a.y))) / Math.abs(Math.sqrt(Math.pow(a.b.x - a.a.x, 2) + Math.pow(a.b.y - a.a.y, 2))));
    }

    static int id0(Line a, Line b) {
        double eps = 1e-9;
        return (cross(new Point(a.b.x - a.a.x, a.b.y - a.a.y), new Point(b.a.x - a.a.x, b.a.y - a.a.y)) * cross(new Point(a.b.x - a.a.x, a.b.y - a.a.y), new Point(b.b.x - a.a.x, b.b.y - a.a.y)) < eps) &&
            (cross(new Point(b.b.x - b.a.x, b.b.y - b.a.y), new Point(a.a.x - b.a.x, a.a.y - b.a.y)) * cross(new Point(b.b.x - b.a.x, b.b.y - b.a.y), new Point(a.b.x - b.a.x, a.b.y - b.a.y)) < eps);
    }

    static Point intersection_l(Line a, Line b) {
        Point da = new Point(a.b.x - a.a.x, a.b.y - a.a.y);
        Point db = new Point(b.b.x - b.a.x, b.b.y - b.a.y);
        return new Point(a.a.x + da.x * cross(db, new Point(b.a.x - a.a.x, b.a.y - a.a.y)) / cross(db, da),
            a.a.y + da.y * cross(db, new Point(b.a.x - a.a.x, b.a.y - a.a.y)) / cross(db, da));
    }

    static double id8(Line a, Line b) {
        double eps = 1e-9;
        if (id0(a, b) == 1) {
            return 0;
        }
        return Math.min(Math.min(id3(a, b.a), id3(a, b.b)), Math.min(id3(b, a.a), id3(b, a.b)));
    }

    static Pair<Point, Point> id9(Circle a, Circle b) {
        double eps = 1e-9;
        double dist = Math.abs(Math.sqrt(Math.pow(a.center.x - b.center.x, 2) + Math.pow(a.center.y - b.center.y, 2)));
        assert(dist <= eps + a.r + b.r);
        assert(dist + eps >= Math.abs(a.r - b.r));
        Point target = new Point(b.center.x - a.center.x, b.center.y - a.center.y);
        double pointer = target.x * target.x + target.y * target.y;
        double aa = pointer + a.r * a.r - b.r * b.r;
        aa /= 2.0;
        Point l = new Point((aa * target.x + target.y * Math.sqrt(pointer * a.r * a.r - aa * aa)) / pointer,
            (aa * target.y - target.x * Math.sqrt(pointer * a.r * a.r - aa * aa)) / pointer);
        Point r = new Point((aa * target.x - target.y * Math.sqrt(pointer * a.r * a.r - aa * aa)) / pointer,
            (aa * target.y + target.x * Math.sqrt(pointer * a.r * a.r - aa * aa)) / pointer);
        r.x += a.center.x;
        r.y += a.center.y;
        l.x += a.center.x;
        l.y += a.center.y;
        return new Pair<>(l, r);
    }

    static long gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    static <A> A pows(A val, long b) {
        assert(b >= 1);
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

    static <A> class Compressor {
        boolean id6;
        Map<A, Long> zipper;
        Map<Long, A> unzipper;
        Queue<A> fetcher;

        Compressor() {
            id6 = false;
            zipper = new HashMap<>();
            unzipper = new HashMap<>();
            fetcher = new LinkedList<>();
        }

        void add(A now) {
            assert(id6 == false);
            zipper.put(now, 1L);
            fetcher.add(now);
        }

        void exec() {
            assert(id6 == false);
            int cnt = 0;
            for (Map.Entry<A, Long> entry : zipper.entrySet()) {
                entry.setValue((long)cnt);
                unzipper.put((long)cnt, entry.getKey());
                cnt++;
            }
            id6 = true;
        }

        long fetch() {
            assert(id6 == true);
            A hoge = fetcher.poll();
            return zipper.get(hoge);
        }

        long zip(A now) {
            assert(id6 == true);
            assert(zipper.containsKey(now));
            return zipper.get(now);
        }

        A unzip(long a) {
            assert(id6 == true);
            assert(a < unzipper.size());
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

    static <A> class Matrix {
        List<List<A>> data;

        Matrix(List<List<A>> a) {
            data = a;
        }

        Matrix add(Matrix obj) {
            List<List<A>> ans = new ArrayList<>();
            assert(obj.data.size() == data.size());
            assert(obj.data.get(0).size() == data.get(0).size());
            for (int i = 0; i < obj.data.size(); i++) {
                ans.add(new ArrayList<>());
                for (int q = 0; q < obj.data.get(i).size(); q++) {
                    A hoge = add(obj.data.get(i).get(q), data.get(i).get(q));
                    ans.get(i).add(hoge);
                }
            }
            return new Matrix(ans);
        }

        Matrix subtract(Matrix obj) {
            List<List<A>> ans = new ArrayList<>();
            assert(obj.data.size() == data.size());
            assert(obj.data.get(0).size() == data.get(0).size());
            for (int i = 0; i < obj.data.size(); i++) {
                ans.add(new ArrayList<>());
                for (int q = 0; q < obj.data.get(i).size(); q++) {
                    A hoge = subtract(data.get(i).get(q), obj.data.get(i).get(q));
                    ans.get(i).add(hoge);
                }
            }
            return new Matrix(ans);
        }

        Matrix multiply(Matrix obj) {
            List<List<A>> ans = new ArrayList<>();
            assert(obj.data.size() == data.get(0).size());
            for (int i = 0; i < data.size(); i++) {
                ans.add(new ArrayList<>());
                for (int q = 0; q < obj.data.get(0).size(); q++) {
                    A hoge = multiply(data.get(i).get(0), obj.data.get(0).get(q));
                    for (int t = 1; t < obj.data.get(i).size(); ++t) {
                        hoge = add(hoge, multiply(data.get(i).get(t), obj.data.get(t).get(q)));
                    }
                    ans.get(i).add(hoge);
                }
            }
            return new Matrix(ans);
        }

        Matrix multiplyAssign(Matrix obj) {
            this = multiply(obj);
            return this;
        }

        Matrix addAssign(Matrix obj) {
            this = add(obj);
            return this;
        }

        Matrix subtractAssign(Matrix obj) {
            this = subtract(obj);
            return this;
        }
    }

    static class Fraction {
        long a;
        long b;

        Fraction() {
            a = 0;
            b = 1;
        }

        Fraction(long c, long d) {
            long hoge = gcd(Math.abs(c), Math.abs(d));
            c /= hoge;
            d /= hoge;
            if (d < 0) {
                d *= -1;
                c *= -1;
            }
            a = c;
            b = d;
        }

        boolean lessThan(Fraction rhs) {
            return a * rhs.b < rhs.a * b;
        }
    }

    static class modintPair {
        modint a;
        modint b;

        modintPair(modint a, modint b) {
            this.a = a;
            this.b = b;
        }
    }

    static class Dice {
        List<Long> vertexs;

        Dice(List<Long> init) {
            vertexs = init;
        }

        void RtoL() {
            for (int q = 1; q < 4; ++q) {
                Collections.swap(vertexs, q, q + 1);
            }
        }

        void LtoR() {
            for (int q = 3; q >= 1; --q) {
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

        public boolean equals(Object obj) {
            if (this == obj) {
                return true;
            }
            if (obj == null || getClass() != obj.getClass()) {
                return false;
            }
            Dice dice = (Dice) obj;
            return vertexs.equals(dice.vertexs);
        }

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
        return new Pair<>(new Dice(Arrays.asList((long)up, (long)target, (long)center, (long)(7 - target), (long)(7 - center), (long)(7 - up))),
            new Dice(Arrays.asList((long)up, (long)(7 - target), (long)center, (long)target, (long)(7 - center), (long)(7 - up))));
    }

    static Tuple<Dice, Dice, Dice, Dice> id2(int center) {
        int bo = Math.min(center, 7 - center);
        Pair<Integer, Integer> goa;
        if (bo == 1) {
            goa = new Pair<>(2, 3);
        }
        else if (bo == 2) {
            goa = new Pair<>(1, 3);
        }
        else if (bo == 3) {
            goa = new Pair<>(1, 2);
        }
        else {
            goa = new Pair<>(0, 0);
        }
        Tuple<Dice, Dice, Dice, Dice> now = new Tuple<>(new Dice(Arrays.asList((long)goa.first, (long)goa.second, (long)center, (long)(7 - goa.second), (long)(7 - center), (long)(7 - goa.first))),
            new Dice(Arrays.asList((long)goa.first, (long)(7 - goa.second), (long)center, (long)goa.second, (long)(7 - center), (long)(7 - goa.first))),
            new Dice(Arrays.asList((long)(7 - goa.first), (long)goa.second, (long)center, (long)(7 - goa.second), (long)(7 - center), (long)goa.first)),
            new Dice(Arrays.asList((long)(7 - goa.first), (long)(7 - goa.second), (long)center, (long)goa.second, (long)(7 - center), (long)goa.first)));
        return now;
    }

    static class Dijkstra<A> {
        List<List<Pair<Integer, A>>> vertexs;
        Function<A, Integer> costFunction;

        Dijkstra(int n, Function<A, Integer> cost) {
            vertexs = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                vertexs.add(new ArrayList<>());
            }
            costFunction = cost;
        }

        void add_edge(int a, int b, A c) {
            vertexs.get(a).add(new Pair<>(b, c));
        }

        List<Long> build_result(int StartPoint) {
            List<Long> dist = new ArrayList<>(Collections.nCopies(vertexs.size(), (long)2e18));
            dist.set(StartPoint, 0L);
            PriorityQueue<Pair<Long, Integer>> next = new PriorityQueue<>(Comparator.comparingLong(Pair::getKey));
            next.add(new Pair<>(0L, StartPoint));
            while (!next.isEmpty()) {
                Pair<Long, Integer> now = next.poll();
                if (!now.getKey().equals(dist.get(now.getValue()))) continue;
                for (Pair<Integer, A> x : vertexs.get(now.getValue())) {
                    long now_cost = now.getKey() + costFunction.apply(x.getValue());
                    if (dist.get(x.getKey()) > now_cost) {
                        dist.set(x.getKey(), now_cost);
                        next.add(new Pair<>(now_cost, x.getKey()));
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
            Graph = new ArrayList<>();
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
            for (int i = itr.get(now); i < Graph.get(now).size(); ++i) {
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
            int f = 0;
            while (true) {
                bfs(s);
                if (level.get(t) < 0) {
                    return ans;
                }
                itr = new ArrayList<>(Collections.nCopies(Graph.size(), 0));
                while ((f = dfs(s, t, Integer.MAX_VALUE)) > 0) {
                    ans += f;
                }
            }
        }
    }

    static class id7 {
        List<List<Integer>> vertexs;
        List<Integer> depth;
        List<Integer> backs;
        List<Integer> connections;
        List<Integer> zip, unzip;

        id7(int n) {
            vertexs = new ArrayList<>();
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
            return;
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
                    ans.add(new Pair<>(backs.get(a), a + 1));
                }
                else {
                    ans.add(new Pair<>(backs.get(a), a - 1));
                }
                a = connections.get(a);
            }
            if (a > b) {
                ans.add(new Pair<>(a, b + 1));
            }
            else {
                ans.add(new Pair<>(a, b - 1));
            }
            return ans;
        }

        int lca(int a, int b) {
            a = zip.get(a);
            b = zip.get(b);
            while (backs.get(a) != backs.get(b)) {
                if (a < b) {
                    a = connections.get(a);
                }
                else {
                    b = connections.get(b);
                }
            }
            return unzip.get(Math.min(a, b));
        }
    }

    static class SegmentTree<Monoid> {
        int sz;
        List<Monoid> seg;
        Function<Pair<Monoid, Monoid>, Monoid> f;
        Monoid M1;

        SegmentTree(int n, Function<Pair<Monoid, Monoid>, Monoid> f, Monoid M1) {
            this.f = f;
            this.M1 = M1;
            sz = 1;
            while (sz < n) sz <<= 1;
            seg = new ArrayList<>(2 * sz + 1);
            for (int i = 0; i < 2 * sz + 1; i++) {
                seg.add(M1);
            }
        }

        void set(int k, Monoid x) {
            seg.set(k + sz, x);
        }

        void build() {
            for (int k = sz - 1; k > 0; k--) {
                seg.set(k, f.apply(new Pair<>(seg.get(2 * k + 0), seg.get(2 * k + 1))));
            }
        }

        void update(int k, Monoid x) {
            k += sz;
            seg.set(k, x);
            while ((k >>= 1) > 0) {
                seg.set(k, f.apply(new Pair<>(seg.get(2 * k + 0), seg.get(2 * k + 1))));
            }
        }

        Monoid query(int a, int b) {
            Monoid L = M1, R = M1;
            for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
                if ((a & 1) == 1) L = f.apply(new Pair<>(L, seg.get(a++)));
                if ((b & 1) == 1) R = f.apply(new Pair<>(seg.get(--b), R));
            }
            return f.apply(new Pair<>(L, R));
        }

        Monoid get(int k) {
            return seg.get(k + sz);
        }

        <C> int id4(int a, Function<C, Boolean> check, Monoid M, boolean type) {
            while (a < sz) {
                Monoid nxt = type ? f.apply(new Pair<>(seg.get(2 * a + (type ? 1 : 0)), M)) : f.apply(new Pair<>(M, seg.get(2 * a + (type ? 1 : 0))));
                if (check.apply(nxt)) a = 2 * a + (type ? 1 : 0);
                else {
                    M = nxt;
                    a = 2 * a + (type ? 0 : 1);
                }
            }
            return a - sz;
        }

        <C> int find_first(int a, Function<C, Boolean> check) {
            Monoid L = M1;
            if (a <= 0) {
                if (check.apply(f.apply(new Pair<>(L, seg.get(1))))) return id4(1, check, L, false);
                return -1;
            }
            int b = sz;
            for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
                if ((a & 1) == 1) {
                    Monoid nxt = f.apply(new Pair<>(L, seg.get(a)));
                    if (check.apply(nxt)) return id4(a, check, L, false);
                    L = nxt;
                    ++a;
                }
            }
            return -1;
        }

        <C> int find_last(int b, Function<C, Boolean> check) {
            Monoid R = M1;
            if (b >= sz) {
                if (check.apply(f.apply(new Pair<>(seg.get(1), R)))) return id4(1, check, R, true);
                return -1;
            }
            int a = sz;
            for (b += sz; a < b; a >>= 1, b >>= 1) {
                if ((b & 1) == 1) {
                    Monoid nxt = f.apply(new Pair<>(seg.get(--b), R));
                    if (check.apply(nxt)) return id4(b, check, R, true);
                    R = nxt;
                }
            }
            return -1;
        }
    }

    static class id5<Monoid, OperatorMonoid> {
        Function<Pair<Monoid, Monoid>, Monoid> f;
        Function<Triple<Monoid, OperatorMonoid, Integer>, Monoid> g;
        Function<Pair<OperatorMonoid, OperatorMonoid>, OperatorMonoid> h;
        int sz, height;
        List<Monoid> data;
        List<OperatorMonoid> lazy;
        Monoid M1;
        OperatorMonoid OM0;

        id5(int n, Function<Pair<Monoid, Monoid>, Monoid> f, Function<Triple<Monoid, OperatorMonoid, Integer>, Monoid> g, Function<Pair<OperatorMonoid, OperatorMonoid>, OperatorMonoid> h,
            Monoid M1, OperatorMonoid OM0) {
            this.f = f;
            this.g = g;
            this.h = h;
            this.M1 = M1;
            this.OM0 = OM0;
            sz = 1;
            height = 0;
            while (sz < n) sz <<= 1, height++;
            data = new ArrayList<>(2 * sz);
            for (int i = 0; i < 2 * sz; i++) {
                data.add(M1);
            }
            lazy = new ArrayList<>(2 * sz);
            for (int i = 0; i < 2 * sz; i++) {
                lazy.add(OM0);
            }
        }

        void set(int k, Monoid x) {
            data.set(k + sz, x);
        }

        void build() {
            for (int k = sz - 1; k > 0; k--) {
                data.set(k, f.apply(new Pair<>(data.get(2 * k + 0), data.get(2 * k + 1))));
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
                    return g.apply(new Triple<>(data.get(k), lazy.get(k), sz / q));
                }
            }
            return null;
        }

        void recalc(int k) {
            while ((k >>= 1) > 0) data.set(k, f.apply(new Pair<>(reflect(2 * k + 0), reflect(2 * k + 1))));
        }

        void thrust(int k) {
            for (int i = height; i > 0; i--) propagate(k >> i);
        }

        void update(int a, int b, OperatorMonoid x) {
            thrust(a += sz);
            thrust(b += sz - 1);
            for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
                if ((l & 1) == 1) lazy.set(l, h.apply(lazy.get(l), x)), ++l;
                if ((r & 1) == 1) --r, lazy.set(r, h.apply(lazy.get(r), x));
            }
            recalc(a);
            recalc(b);
        }

        Monoid query(int a, int b) {
            thrust(a += sz);
            thrust(b += sz - 1);
            Monoid L = M1, R = M1;
            for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
                if ((l & 1) == 1) L = f.apply(new Pair<>(L, reflect(l++)));
                if ((r & 1) == 1) R = f.apply(new Pair<>(reflect(--r), R));
            }
            return f.apply(new Pair<>(L, R));
        }

        Monoid get(int k) {
            return query(k, k + 1);
        }

        <C> int id4(int a, Function<C, Boolean> check, Monoid M, boolean type) {
            while (a < sz) {
                propagate(a);
                Monoid nxt = type ? f.apply(new Pair<>(reflect(2 * a + (type ? 1 : 0)), M)) : f.apply(new Pair<>(M, reflect(2 * a + (type ? 1 : 0))));
                if (check.apply(nxt)) a = 2 * a + (type ? 1 : 0);
                else {
                    M = nxt;
                    a = 2 * a + (type ? 0 : 1);
                }
            }
            return a - sz;
        }

        <C> int find_first(int a, Function<C, Boolean> check) {
            Monoid L = M1;
            if (a <= 0) {
                if (check.apply(f.apply(new Pair<>(L, reflect(1))))) return id4(1, check, L, false);
                return -1;
            }
            thrust(a + sz);
            int b = sz;
            for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
                if ((a & 1) == 1) {
                    Monoid nxt = f.apply(new Pair<>(L, reflect(a)));
                    if (check.apply(nxt)) return id4(a, check, L, false);
                    L = nxt;
                    ++a;
                }
            }
            return -1;
        }

        <C> int find_last(int b, Function<C, Boolean> check) {
            Monoid R = M1;
            if (b >= sz) {
                if (check.apply(f.apply(new Pair<>(reflect(1), R)))) return id4(1, check, R, true);
                return -1;
            }
            thrust(b + sz - 1);
            int a = sz;
            for (b += sz; a < b; a >>= 1, b >>= 1) {
                if ((b & 1) == 1) {
                    Monoid nxt = f.apply(new Pair<>(reflect(--b), R));
                    if (check.apply(nxt)) return id4(b, check, R, true);
                    R = nxt;
                }
            }
            return -1;
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
            table = new ArrayList<>(a.size() + 1);
            for (int i = 0; i < a.size() + 1; i++) {
                table.add(-1);
            }
            int j = -1;
            for (int i = 0; i < a.size(); ++i) {
                while (j >= 0 && !Objects.equals(a.get(i), a.get(j))) {
                    j = table.get(j);
                }
                table.set(i + 1, ++j);
            }
        }

        List<Integer> search(List<Integer> a) {
            List<Integer> ans = new ArrayList<>();
            for (int i = 0, k = 0; i < a.size(); ++i) {
                while (k >= 0 && !Objects.equals(a.get(i), Pattern.get(k))) k = table.get(k);
                ++k;
                if (k >= Pattern.size()) {
                    ans.add(i - Pattern.size() + 1);
                    k = table.get(k);
                }
            }
            return ans;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String t = sc.next();
        List<Integer> cnter = new ArrayList<>();
        for (int i = 0; i < t.length(); ++i) {
            if (t.charAt(i) == '0') {
                cnter.add(i * 2 + i % 2);
            }
        }
        modintPair[] hoge = new modintPair[300000];
        modintPair[] rev = new modintPair[300000];
        modintPair nexts = new modintPair(new modint(1), new modint(1));
        for (int i = 0; i < cnter.size(); ++i) {
            hoge[i + 1] = hoge[i];
            hoge[i + 1].a = hoge[i + 1].a.add(nexts.a.multiply(new modint(cnter.get(i) % 2)));
            hoge[i + 1].b = hoge[i + 1].b.add(nexts.b.multiply(new modint(cnter.get(i) % 2)));
            rev[i + 1] = rev[i];
            rev[i + 1].a = rev[i + 1].a.add(nexts.a.multiply(new modint((cnter.get(i) + 1) % 2)));
            rev[i + 1].b = rev[i + 1].b.add(nexts.b.multiply(new modint((cnter.get(i) + 1) % 2)));
            nexts.a = nexts.a.multiply(new modint(2));
            nexts.b = nexts.b.multiply(new modint(2));
        }
        int query = sc.nextInt();
        for (int i = 0; i < query; ++i) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int c = sc.nextInt();
            a--; b--;
            Pair<Integer, Integer> Left = new Pair<>(Collections.binarySearch(cnter, a * 2), Collections.binarySearch(cnter, (a + c) * 2));
            Pair<Integer, Integer> Right = new Pair<>(Collections.binarySearch(cnter, b * 2), Collections.binarySearch(cnter, (b + c) * 2));
            if (Left.b - Left.a != Right.b - Right.a) {
                System.out.println("No");
                continue;
            }
            int ok = 1;
            modintPair aa, bb;
            aa = hoge[Left.b];
            aa.a = aa.a.subtract(hoge[Left.a].a);
            aa.b = aa.b.subtract(hoge[Left.a].b);
            if (a % 2 == b % 2) {
                bb = hoge[Right.b];
                bb.a = bb.a.subtract(hoge[Right.a].a);
                bb.b = bb.b.subtract(hoge[Right.a].b);
            }
            else {
                bb = rev[Right.b];
                bb.a = bb.a.subtract(rev[Right.a].a);
                bb.b = bb.b.subtract(rev[Right.a].b);
            }
            if (Left.a != 0) {
                aa.a = aa.a.divide(pows(new modint(2), Left.a));
                aa.b = aa.b.divide(pows(new modint(2), Left.a));
            }
            if (Right.a != 0) {
                bb.a = bb.a.divide(pows(new modint(2), Right.a));
                bb.b = bb.b.divide(pows(new modint(2), Right.a));
            }
            if (!aa.a.equals(bb.a) || !aa.b.equals(bb.b)) {
                ok = 0;
            }
            if (ok == 1) {
                System.out.println("Yes");
            }
            else {
                System.out.println("No");
            }
        }
    }
}
