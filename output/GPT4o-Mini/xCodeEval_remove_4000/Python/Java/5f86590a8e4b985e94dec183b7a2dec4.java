import java.util.*;

class Id17 {
    Id17 prev;
    Id17 next;

    public Id17() {
        this.prev = null;
        this.next = null;
    }

    public Id17 connect(Id17 node) {
        this.next = node;
        node.prev = this;
        return node;
    }

    public Id17 splice(Id17 fragment) {
        if (fragment.prev != null) fragment.prev.next = null;

        Id17 u = this;
        Id17 v = fragment;
        Id17 w = this.next;

        u.connect(v);
        while (v.next != null) v = v.next;
        v.connect(w);

        return v;
    }

    public void splice1(Id17 node) {
        node.connect(this.next);
        this.connect(node);
    }

    public void eject() {
        this.prev.connect(this.next);
    }

    public Iterable<Id17> iterate() {
        return new Iterable<Id17>() {
            public Iterator<Id17> iterator() {
                return new Iterator<Id17>() {
                    Id17 u = Id17.this;

                    public boolean hasNext() {
                        return u != null && u != Id17.this;
                    }

                    public Id17 next() {
                        Id17 temp = u;
                        u = u.next;
                        return temp;
                    }
                };
            }
        };
    }
}

abstract class AbstractHeap {
    public AbstractHeap() {}

    public abstract boolean id6();
    public abstract int id18();
    public abstract boolean id14(Object value);
    public abstract Object id21(Object value);
    public abstract void push(Object key, Object value);
    public abstract Object pop();
    public abstract void id28(Object value, Object key);
    public abstract void merge(AbstractHeap other);
}

class Id13 extends Id17 {
    Object key;
    Object value;
    Id13 parent;
    Id13 child;
    int degree;
    boolean mark;

    public Id13(Object key, Object value) {
        super();
        this.key = key;
        this.value = value;
        this.parent = null;
        this.child = null;
        this.degree = 0;
        this.mark = false;
    }
}

class Id0 extends AbstractHeap {
    int _n;
    Id13 _root;
    Map<Object, Id13> _index;

    public Id0(Iterable<Object[]> iterable) {
        super();
        this._n = 0;
        this._root = null;
        this._index = new HashMap<>();

        for (Object[] kv : iterable) {
            push(kv[0], kv[1]);
        }
    }

    public boolean id6() {
        return _n > 0;
    }

    public int id18() {
        return _n;
    }

    public boolean id14(Object value) {
        return _index.containsKey(value);
    }

    public Object id21(Object value) {
        return _index.get(value).key;
    }

    public void push(Object key, Object value) {
        Id13 node = new Id13(key, value);
        _index.put(value, node);

        if (_root == null) {
            node.connect(node);
            _root = node;
            _n = 1;
        } else {
            _root.splice1(node);
            if (((Comparable) key).compareTo(_root.key) < 0) _root = node;
            _n++;
        }
    }

    public Object pop() {
        Id13 z = _root;

        if (z.child != null) {
            for (Id17 c : z.child.iterate()) c.parent = null;
            z.splice(z.child);
        }

        if (z.next == z) {
            _root = null;
        } else {
            _root = z.next;
            z.eject();
            id31();
        }

        _n--;
        _index.remove(z.value);
        return new Object[]{z.key, z.value};
    }

    public void id31() {
        Map<Integer, Id13> A = new HashMap<>();
        for (Id13 x : _root.iterate()) {
            int d = x.degree;
            while (A.containsKey(d)) {
                Id13 y = A.get(d);
                if (((Comparable) x.key).compareTo(y.key) > 0) {
                    Id13 temp = y;
                    y = x;
                    x = temp;
                }
                _link(y, x);
                A.remove(d);
                d++;
            }
            A.put(d, x);
        }

        Iterator<Id13> i = A.values().iterator();
        _root = i.next();
        _root.connect(_root);
        while (i.hasNext()) {
            Id13 x = i.next();
            _root.splice1(x);
            if (((Comparable) x.key).compareTo(_root.key) < 0) _root = x;
        }
    }

    private void _link(Id13 y, Id13 x) {
        y.eject();
        y.parent = x;
        if (x.child != null) {
            x.child.splice1(y);
        } else {
            x.child = y;
            y.connect(y);
        }
        x.degree++;
        y.mark = false;
    }

    public void id28(Object value, Object key) {
        Id13 x = _index.get(value);
        x.key = key;
        _index.remove(value);
        _index.put(value, x);

        Id13 y = x.parent;
        if (y != null && ((Comparable) x.key).compareTo(y.key) < 0) {
            _cut(x, y);
            id2(y);
        }

        if (((Comparable) x.key).compareTo(_root.key) < 0) _root = x;
    }

    private void _cut(Id13 x, Id13 y) {
        if (x.next == x) {
            y.child = null;
        } else {
            y.child = x.next;
        }
        x.parent = null;
        x.eject();
        y.degree--;

        _root.splice1(x);
        x.mark = false;
    }

    private void id2(Id13 y) {
        Id13 z = y.parent;
        if (z != null) {
            if (!y.mark) {
                y.mark = true;
            } else {
                _cut(y, z);
                id2(z);
            }
        }
    }

    public void merge(AbstractHeap other) {
        if (other == null) return;

        if (_root != null) {
            _root.splice(other._root);
            if (((Comparable) other._root.key).compareTo(_root.key) < 0) _root = other._root;
            _index.putAll(other._index);
        } else {
            _root = other._root;
            _index = other._index;
        }

        _n += other._n;
        other._root = null;
        other._n = 0;
        other._index.clear();
    }
}

class Id5 extends AbstractHeap {
    List<Object[]> _tree;
    Map<Object, Integer> _index;

    public Id5(Iterable<Object[]> iterable) {
        super();
        _build_heap(iterable);
    }

    public boolean id6() {
        return !_tree.isEmpty();
    }

    public int id18() {
        return _tree.size();
    }

    public boolean id14(Object value) {
        return _index.containsKey(value);
    }

    public Object id21(Object value) {
        return _tree.get(_index.get(value))[0];
    }

    public void push(Object key, Object value) {
        _index.put(value, _tree.size());
        _tree.add(new Object[]{Id7._inf_key, value});
        id28(value, key);
    }

    public Object pop() {
        Object[] tree = _tree.get(0);
        _tree.set(0, _tree.get(_tree.size() - 1));
        _tree.remove(_tree.size() - 1);
        if (!_tree.isEmpty()) _heapify(0);

        _index.remove(tree[1]);
        return tree;
    }

    public void merge(AbstractHeap other) {
        if (other == null) return;

        _build_heap(new ArrayList<>(_tree).addAll(other._tree));
        other._tree.clear();
        other._index.clear();
    }

    private void _build_heap(Iterable<Object[]> iterable) {
        _tree = new ArrayList<>();
        for (Object[] kv : iterable) {
            _tree.add(kv);
        }
        int size = _tree.size();
        _index = new HashMap<>();
        for (int i = size / 2; i < size; i++) {
            _index.put(_tree.get(i)[1], i);
        }
        for (int i = size / 2 - 1; i >= 0; i--) {
            _heapify(i);
        }
    }

    private void _heapify(int i) {
        int size = _tree.size();
        int left = (i + 1) * 2 - 1;
        int right = (i + 1) * 2;

        int z = i;
        if (left < size && ((Comparable) _tree.get(left)[0]).compareTo(_tree.get(i)[0]) < 0) {
            z = left;
        }
        if (right < size && ((Comparable) _tree.get(right)[0]).compareTo(_tree.get(z)[0]) < 0) {
            z = right;
        }

        if (z != i) {
            Collections.swap(_tree, i, z);
            _heapify(z);
        }

        _index.put(_tree.get(i)[1], i);
    }

    public void id28(Object value, Object key) {
        int i = _index.get(value);
        while (i > 0) {
            int p = (i + 1) / 2 - 1;
            if (!((Comparable) key).compareTo(_tree.get(p)[0]) < 0) break;
            _tree.set(i, _tree.get(p));
            _index.put(_tree.get(i)[1], i);
            i = p;
        }
        _tree.set(i, new Object[]{key, value});
        _index.put(value, i);
    }
}

class Id3 extends Id17 {
    Object key;
    Object value;

    public Id3(Object key, Object value) {
        super();
        this.key = key;
        this.value = value;
        this.parent = null;
        this.left = null;
        this.right = null;
    }

    public Id3 link(Id3 other) {
        if (((Comparable) other.key).compareTo(this.key) < 0) {
            Id3 temp = other;
            other = this;
            this = temp;
        }
        if (this.left == null) {
            this.left = other;
            other.parent = this;
        } else {
            Id3 r = this.left;
            while (r.right != null) r = r.right;
            r.right = other;
            other.parent = r;
        }
        return this;
    }
}

class Id16 extends AbstractHeap {
    Id3 _root;
    Map<Object, Id3> _index;

    public Id16(Iterable<Object[]> iterable) {
        super();
        this._root = null;
        this._index = new HashMap<>();

        for (Object[] kv : iterable) {
            push(kv[0], kv[1]);
        }
    }

    public boolean id6() {
        return _root != null;
    }

    public int id18() {
        return _index.size();
    }

    public boolean id14(Object value) {
        return _index.containsKey(value);
    }

    public Object id21(Object value) {
        return _index.get(value).key;
    }

    public void push(Object key, Object value) {
        Id3 node = new Id3(key, value);
        _index.put(value, node);

        if (_root == null) {
            _root = node;
        } else {
            _root = _root.link(node);
        }
    }

    public void id28(Object value, Object key) {
        Id3 x = _index.get(value);
        x.key = key;
        _index.remove(value);
        _index.put(value, x);
        if (x.parent == null) return;

        if (x.parent.left == x) {
            x.parent.left = x.right;
        } else {
            x.parent.right = x.right;
        }
        if (x.right != null) x.right.parent = x.parent;

        x.parent = null;
        x.right = null;
        _root = _root.link(x);
    }

    public Object pop() {
        Id3 z = _root;
        if (z.left == null) {
            _root = null;
        } else {
            List<Id3> pass0 = new ArrayList<>();
            Id3 i = z.left;
            while (i != null) {
                Id3 j = i.right;
                i.parent = null;
                i.right = null;
                pass0.add(i);
                i = j;
            }

            List<Id3> pass1 = new ArrayList<>();
            for (int i = 0; i < pass0.size() - 1; i += 2) {
                pass1.add(pass0.get(i).link(pass0.get(i + 1)));
            }
            if (pass0.size() % 2 == 1) pass1.add(pass0.get(pass0.size() - 1));

            Id3 y = pass1.remove(pass1.size() - 1);
            while (!pass1.isEmpty()) {
                y = y.link(pass1.remove(pass1.size() - 1));
            }

            _root = y;
        }

        _index.remove(z.value);
        return new Object[]{z.key, z.value};
    }

    public void merge(AbstractHeap other) {
        if (other == null) return;

        if (_root != null) {
            _root = _root.link(other._root);
            _index.putAll(other._index);
        } else {
            _root = other._root;
            _index = other._index;
        }

        other._root = null;
        other._index.clear();
    }
}

class Graph {
    int maxV;
    boolean isflow;
    boolean sparse;
    List<Object> _V;
    Map<Object, Integer> _V_index;
    List<Map<Integer, Integer>> _E;
    List<Set<Integer>> _adj;
    Map<Integer, int[]> _levels;

    public Graph(int maxV, boolean isflow, boolean sparse) {
        this.maxV = maxV;
        this.isflow = isflow;
        this.sparse = sparse;

        _V = new ArrayList<>();
        _V_index = new HashMap<>();

        int non_edge = isflow ? 0 : Integer.MAX_VALUE;
        if (sparse) {
            _E = new ArrayList<>(maxV);
            for (int i = 0; i < maxV; i++) {
                _E.add(new HashMap<>());
            }
        } else {
            _E = new ArrayList<>(maxV);
            for (int i = 0; i < maxV; i++) {
                _E.add(new ArrayList<>(Collections.nCopies(maxV, non_edge)));
            }
        }

        _adj = new ArrayList<>(maxV);
        for (int i = 0; i < maxV; i++) {
            _adj.add(new HashSet<>());
        }
        _levels = new HashMap<>();
    }

    public boolean id14(Object label) {
        return _V_index.containsKey(label);
    }

    public Iterator<Object> id33() {
        return _V.iterator();
    }

    public int nV() {
        return _V.size();
    }

    public int nE() {
        int n = 0;
        for (Set<Integer> a : _adj) {
            n += a.size();
        }
        if (isflow) n /= 2;
        return n;
    }

    public void add_vertex(Object label) {
        _V_index.put(label, nV());
        _V.add(label);
    }

    public void id12(Iterable<Object> labels) {
        for (Object u_label : labels) {
            add_vertex(u_label);
        }
    }

    public void _add_edge(int u, int v, int w) {
        if (isflow) {
            _E.get(u).put(v, _E.get(u).getOrDefault(v, 0) + w);
            _adj.get(u).add(v);
            _adj.get(v).add(u);
        } else {
            _E.get(u).set(v, w);
            _adj.get(u).add(v);
        }
    }

    public void add_edge(Object u_label, Object v_label, int w) {
        _add_edge(_V_index.get(u_label), _V_index.get(v_label), w);
    }

    public boolean _isadj(int u, int v) {
        return _adj.get(u).contains(v);
    }

    public boolean isadj(Object u_label, Object v_label) {
        return _isadj(_V_index.get(u_label), _V_index.get(v_label));
    }

    public void trim(Object u_label) {
        int u = _V_index.get(u_label);
        _adj.get(u).clear();
        if (sparse) {
            _E.get(u).clear();
        } else {
            Collections.fill(_E.get(u), Integer.MAX_VALUE);
        }
    }

    public int id20(int s, int t) {
        Arrays.fill(_levels.get(s), Integer.MAX_VALUE);
        _levels.get(s)[s] = 0;

        Queue<Integer> queue = new LinkedList<>();
        queue.add(s);
        while (!queue.isEmpty()) {
            int u = queue.poll();
            for (int v : _adj.get(u)) {
                if (_E.get(u).get(v) > 0 && _levels.get(s)[v] == Integer.MAX_VALUE) {
                    _levels.get(s)[v] = _levels.get(s)[u] + 1;
                    queue.add(v);
                }
            }
        }

        return _levels.get(s)[t];
    }

    public int id30(int s, int t) {
        List<Set<Integer>> pointers = new ArrayList<>();
        for (int i = 0; i < nV(); i++) {
            pointers.add(new HashSet<>(_adj.get(i)));
        }

        return dfs_push(s, t, Integer.MAX_VALUE, pointers);
    }

    private int dfs_push(int u, int t, int inflow, List<Set<Integer>> pointers) {
        if (u == t) return inflow;
        int id4 = 0;
        Iterator<Integer> it = pointers.get(u).iterator();
        while (it.hasNext()) {
            int v = it.next();
            if (_levels.get(u)[v] == _levels.get(u)[u] + 1 && _E.get(u).get(v) > 0) {
                int v_flow = dfs_push(v, t, Math.min(inflow, _E.get(u).get(v)));
                _E.get(u).put(v, _E.get(u).get(v) - v_flow);
                _E.get(v).put(u, _E.get(v).getOrDefault(u, 0) + v_flow);
                inflow -= v_flow;
                id4 += v_flow;
                if (inflow == 0) {
                    it.remove();
                    break;
                }
            }
        }
        return id4;
    }

    public int max_flow(Object s_label, Object t_label) {
        int[] E_saved = new int[nV()];
        int s = _V_index.get(s_label);
        int t = _V_index.get(t_label);

        int mf = 0;
        while (id20(s, t) != Integer.MAX_VALUE) {
            mf += id30(s, t);
        }

        return mf;
    }

    public Map<Object, Map<Object, Integer>> id1() {
        int[][] fw = new int[nV()][nV()];
        for (int k = 0; k < nV(); k++) {
            for (int i = 0; i < nV(); i++) {
                for (int j = 0; j < nV(); j++) {
                    fw[i][j] = Math.min(fw[i][j], fw[i][k] + fw[k][j]);
                }
            }
        }

        Map<Object, Map<Object, Integer>> id10 = new HashMap<>();
        for (int u = 0; u < nV(); u++) {
            Map<Object, Integer> innerMap = new HashMap<>();
            for (int v = 0; v < nV(); v++) {
                innerMap.put(_V.get(v), fw[u][v]);
            }
            id10.put(_V.get(u), innerMap);
        }
        return id10;
    }

    public Map<Object, Object> id9(Object s_label, List<Object> t_labels, int d_limit, Class<? extends AbstractHeap> Heap) {
        class Id19 extends HashMap<Object, Object> {}
        Id19 ret = new Id19();

        int s = _V_index.get(s_label);
        Set<Integer> t_set = new HashSet<>();
        if (t_labels == null) {
            for (int i = 0; i < nV(); i++) {
                t_set.add(i);
            }
        } else {
            for (Object t_label : t_labels) {
                t_set.add(_V_index.get(t_label));
            }
        }

        AbstractHeap queue = null; // Initialize your heap here
        Map<Integer, Integer> spaths = new HashMap<>();
        Map<Integer, Integer> parents = new HashMap<>();
        List<Integer> t_found = new ArrayList<>();
        while (queue != null) { // Replace with your heap's condition
            Object[] su_u = (Object[]) queue.pop();
            int su = (int) su_u[0];
            int u = (int) su_u[1];
            if (su >= d_limit) {
                ret.put("stop", d_limit);
                break;
            }

            spaths.put(u, su);
            if (t_set.contains(u)) {
                t_set.remove(u);
                t_found.add(u);
                if (t_set.isEmpty()) {
                    ret.put("stop", su);
                    break;
                }
            }

            for (int v : _adj.get(u)) {
                int sv = su + _E.get(u).get(v);
                if (queue.contains(v)) {
                    if (sv < (int) queue.get(v)) {
                        parents.put(v, u);
                        queue.id28(v, sv);
                    }
                } else if (!spaths.containsKey(v)) {
                    parents.put(v, u);
                    queue.push(sv, v);
                }
            }
        }

        ret.put("found", t_found);
        return ret;
    }

    public int id25(Object s_label, Object t_label) {
        Map<Object, Object> spaths = id9(s_label, Collections.singletonList(t_label), Integer.MAX_VALUE, Id5.class);
        return (int) spaths.get(t_label);
    }

    public boolean id26() {
        List<Set<Integer>> adj = isflow ? _adj : new ArrayList<>();
        if (!isflow) {
            for (int u = 0; u < nV(); u++) {
                for (int v : _adj.get(u)) {
                    adj.get(u).add(v);
                    adj.get(v).add(u);
                }
            }
        }

        Map<Integer, Boolean> colors = new HashMap<>();
        for (int s = 0; s < nV(); s++) {
            if (!colors.containsKey(s) && !id24(s, colors, adj)) {
                return false;
            }
        }
        return true;
    }

    private boolean id24(int s, Map<Integer, Boolean> colors, List<Set<Integer>> adj) {
        if (colors.containsKey(s)) return true;
        colors.put(s, true);
        Queue<Integer> queue = new LinkedList<>();
        queue.add(s);
        while (!queue.isEmpty()) {
            int u = queue.poll();
            for (int v : adj.get(u)) {
                if (!colors.containsKey(v)) {
                    colors.put(v, !colors.get(u));
                    queue.add(v);
                } else if (colors.get(v) == colors.get(u)) {
                    return false;
                }
            }
        }
        return true;
    }
}

public class 5f86590a8e4b985e94dec183b7a2dec4xcodeeval_processed_4000.json {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        List<int[]> roads = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            roads.add(new int[]{scanner.nextInt(), scanner.nextInt()});
        }
        int k = scanner.nextInt();
        List<Integer> p = new ArrayList<>();
        for (int i = 0; i < k; i++) {
            p.add(scanner.nextInt());
        }

        Graph G = new Graph(n, false, true);
        Map<Integer, Set<Integer>> adj = new HashMap<>();
        G.id12(IntStream.range(1, n + 1).boxed().collect(Collectors.toList()));
        for (int[] road : roads) {
            G.add_edge(road[1], road[0]);
            adj.computeIfAbsent(road[0], x -> new HashSet<>()).add(road[1]);
        }

        Map<Object, Object> spaths = G.id9(p.get(p.size() - 1), null, Integer.MAX_VALUE, Id0.class);

        int id22 = 0;
        int id27 = 0;
        for (int i = 0; i < p.size() - 1; i++) {
            int u = p.get(i);
            int u_d = (int) spaths.get(u);
            int v = p.get(i + 1);
            int v_d = (int) spaths.get(v);

            if (v_d != u_d - 1) {
                id22++;
                id27++;
                continue;
            }

            for (int w : adj.get(u)) {
                if (w != v && (int) spaths.get(w) == v_d) {
                    id27++;
                    break;
                }
            }
        }

        System.out.println(id22 + " " + id27);
    }
}
