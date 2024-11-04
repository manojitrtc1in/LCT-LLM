import java.util.*;

class Idx2<T> {
    T i, j;
    Idx2(T i, T j) {
        this.i = i;
        this.j = j;
    }
    Idx2() {
        this.i = null;
        this.j = null;
    }
    void _write() {
        System.out.print("(" + i + ", " + j + ")");
    }
    void _read(int idx) {
        // Read values for i and j from input
    }
    boolean equals(Idx2<T> other) {
        return i.equals(other.i) && j.equals(other.j);
    }
}

class SepComma {
    static void Print() {
        System.out.print(", ");
    }
}

class Range<T> implements Iterable<T> {
    T a, b;
    Range(T a, T b) {
        this.a = a;
        this.b = b;
    }
    public Iterator<T> iterator() {
        return new Iterator<T>() {
            private T current = a;
            public boolean hasNext() {
                return current < b;
            }
            public T next() {
                return current++;
            }
            public void remove() {
                throw new UnsupportedOperationException();
            }
        };
    }
    int size(int mx) {
        return b < a ? 0 : b - a;
    }
    T get(int i) {
        return a + i;
    }
    void process(Consumer<T> f) {
        for (T i = a; i < b; i++) {
            if (!f.accept(i)) {
                break;
            }
        }
    }
}

class _null<T> {
    static T value() {
        return null;
    }
}

class cmap<T> {
    static <K, V> void write(T a, K i, V value) {
        // Write value to a at index i
    }
    static <K, V> V read(T a, K i) {
        // Read value from a at index i
        return null;
    }
}

class ANMap<T1, T2> {
    Map<T1, T2> m;
    ANMap() {
        m = new HashMap<>();
    }
    T2 get(T1 idx) {
        return m.get(idx);
    }
    void set(T1 idx, T2 value) {
        m.put(idx, value);
    }
    void _write() {
        System.out.print(m);
    }
}

class ArrWrapper<T> implements Iterable<T> {
    T[] a;
    int n;
    ArrWrapper(T[] a, int n) {
        this.a = a;
        this.n = n;
    }
    public Iterator<T> iterator() {
        return new Iterator<T>() {
            private int current = 0;
            public boolean hasNext() {
                return current < n;
            }
            public T next() {
                return a[current++];
            }
            public void remove() {
                throw new UnsupportedOperationException();
            }
        };
    }
    int size(int mx) {
        return n;
    }
    T get(int i) {
        return a[i];
    }
    void erase(int p) {
        for (int i = p + 1; i < n; i++) {
            a[i - 1] = a[i];
        }
        n--;
    }
    void process(Consumer<T> f) {
        for (int i = 0; i < n; i++) {
            if (!f.accept(a[i])) {
                break;
            }
        }
    }
}

class Dfs<
    GraphType,
    VertOrderType,
    NewTreeFunctor,
    EnterVertexFunctor,
    LeaveVertexFunctor,
    BeforeTraverseFunctor,
    AfterTraverseFunctor,
    BackEdgeFunctor,
    MarkersType
> {
    GraphType g;
    VertOrderType order;
    NewTreeFunctor new_tree;
    EnterVertexFunctor enter_vertex;
    LeaveVertexFunctor leave_vertex;
    BeforeTraverseFunctor id8;
    AfterTraverseFunctor id10;
    BackEdgeFunctor back_edge;
    MarkersType markers;
    Dfs(
        GraphType g,
        VertOrderType order,
        NewTreeFunctor new_tree,
        EnterVertexFunctor enter_vertex,
        LeaveVertexFunctor leave_vertex,
        BeforeTraverseFunctor id8,
        AfterTraverseFunctor id10,
        BackEdgeFunctor back_edge,
        MarkersType markers
    ) {
        this.g = g;
        this.order = order;
        this.new_tree = new_tree;
        this.enter_vertex = enter_vertex;
        this.leave_vertex = leave_vertex;
        this.id8 = id8;
        this.id10 = id10;
        this.back_edge = back_edge;
        this.markers = markers;
    }
    void Do() {
        for (Object v : order) {
            if (markers.get(v) == 0) {
                new_tree.accept(v);
                DfsRec(v, _null.value());
            }
        }
    }
    void DfsRec(Object v, Object parent) {
        markers.put(v, 1);
        enter_vertex.accept(v);
        for (Object e : g.v_edges(v)) {
            if (markers.get(e.v) == 0) {
                if (id8.accept(v, e)) {
                    DfsRec(e.v, v);
                    id10.accept(v, e);
                }
            } else {
                if (!parent.equals(e.v)) {
                    back_edge.accept(v, e);
                }
            }
        }
        leave_vertex.accept(v);
    }
}

class Idx2Comparator<T> implements Comparator<Idx2<T>> {
    public int compare(Idx2<T> a, Idx2<T> b) {
        if (a.i.equals(b.i)) {
            return a.j.compareTo(b.j);
        }
        return a.i.compareTo(b.i);
    }
}

class Idx2Set<T> extends TreeSet<Idx2<T>> {
    Idx2Set() {
        super(new Idx2Comparator<T>());
    }
}

class Graph {
    int n;
    List<Integer>[] edges;
    Graph(int n, List<int_uv> edges) {
        this.n = n;
        this.edges = new List[n];
        for (int i = 0; i < n; i++) {
            this.edges[i] = new ArrayList<>();
        }
        for (int_uv e : edges) {
            this.edges[e.u].add(e.v);
            this.edges[e.v].add(e.u);
        }
    }
    List<Integer> v_edges(int v) {
        return edges[v];
    }
    Range<Integer> vertices() {
        return new Range<>(0, n);
    }
}

class PathFinder<
    G,
    MarkersType,
    F,
    ListType
> {
    G g;
    F f;
    ListType path;
    MarkersType markers;
    Object v0;
    PathFinder(G g, Object v0, F f, ListType path, MarkersType markers) {
        this.g = g;
        this.v0 = v0;
        this.f = f;
        this.path = path;
        this.markers = markers;
    }
    boolean dfs(Object v) {
        if (f.accept(v)) {
            path.add(v);
            return true;
        }
        markers.put(v, 1);
        boolean res = false;
        for (Object e : g.v_edges(v)) {
            if (markers.get(e) == 0 && dfs(e)) {
                path.add(v);
                res = true;
                break;
            }
        }
        return res;
    }
    boolean Do() {
        for (Object v : g.vertices()) {
            markers.put(v, 0);
        }
        return dfs(v0);
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int vol = sc.nextInt();
        int e = sc.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        for (int i = 0; i < n; i++) {
            b[i] = sc.nextInt();
        }
        List<int_uv> ee = new ArrayList<>();
        for (int i = 0; i < e; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            ee.add(new int_uv(u, v));
        }

        Graph G = new Graph(n, ee);

        List<int_uv> ee2 = new ArrayList<>();
        ANMap<Integer, Integer> markers = new ANMap<>();
        for (int u = 0; u < n; u++) {
            for (int v : G.v_edges(u)) {
                ee2.add(new int_uv(u + 1, v + 1));
                markers.set(u + 1, 0);
                markers.set(v + 1, 0);
            }
        }

        Graph G2 = new Graph(n, ee2);

        List<int_abc> res = new ArrayList<>();
        for (int q = 0; q < n; q++) {
            for (int i = 0; i < n; i++) {
                if (a[i] != b[i]) {
                    List<Integer> path = new ArrayList<>();
                    if (!path_from(G2, i, v -> (a[v] - b[v]) % (a[i] - b[i]) < 0, path, markers)) {
                        System.out.println("NO");
                        return;
                    }
                    if (a[path.get(0)] < b[path.get(0)]) {
                        Collections.reverse(path);
                    }

                    int src = path.get(0);
                    int tgt = path.get(path.size() - 1);
                    int diff = Math.min(Math.abs(a[src] - b[src]), Math.abs(a[tgt] - b[tgt]));
                    doit(a, b, path, res, 0, vol, diff);
                    a[src] -= diff;
                    a[tgt] += diff;
                }
            }
        }

        System.out.print(res.size());
        for (int_abc x : res) {
            System.out.print(" " + x.a + " " + x.b + " " + x.c);
        }
    }

    static <T1, T2, T3, T4> void doit(
        final T1[] a,
        final T2[] b,
        final List<T3> path,
        final List<T4> res,
        final int pos,
        final int vol,
        final int diff
    ) {
        if (pos + 1 >= path.size()) {
            return;
        }
        int tgt = path.get(pos + 1);
        int before = Math.min(diff, vol - a[tgt]);
        int src = path.get(pos);
        if (before > 0) {
            res.add(new int_abc(src + 1, tgt + 1, before));
        }
        doit(a, b, path, res, pos + 1, vol, diff);
        int after = diff - before;
        if (after > 0) {
            res.add(new int_abc(src + 1, tgt + 1, after));
        }
    }

    static class int_uv {
        int u, v;
        int_uv(int u, int v) {
            this.u = u;
            this.v = v;
        }
    }

    static class int_abc {
        int a, b, c;
        int_abc(int a, int b, int c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }
    }

    static class Range2<T> implements Iterable<Idx2<T>> {
        T a, b, c, d;
        Range2(T a, T b, T c, T d) {
            this.a = a;
            this.b = b;
            this.c = c;
            this.d = d;
        }
        public Iterator<Idx2<T>> iterator() {
            return new Iterator<Idx2<T>>() {
                private T i = a;
                private T j = c;
                public boolean hasNext() {
                    return i < b;
                }
                public Idx2<T> next() {
                    Idx2<T> res = new Idx2<>(i, j);
                    if (j + 1 < d) {
                        j++;
                    } else {
                        i++;
                        j = c;
                    }
                    return res;
                }
                public void remove() {
                    throw new UnsupportedOperationException();
                }
            };
        }
        int size(int mx) {
            return (b - a) * (d - c);
        }
    }

    static class Mul {
        static int Do(int a, int b) {
            return a * b;
        }
    }

    static <T> _mul<T> mul(T a) {
        return new _mul<>(a);
    }

    static class _mul<T> {
        T a;
        _mul(T a) {
            this.a = a;
        }
        int operator%(int b) {
            return Mul.Do(a, b);
        }
    }

    static int _abs(int x) {
        return x < 0 ? -x : x;
    }

    static class MainComparator<T> implements Comparator<T> {
        public int compare(T a, T b) {
            return 0;
        }
    }

    static class MainSet<T> extends TreeSet<T> {
        MainSet() {
            super(new MainComparator<T>());
        }
    }
}
