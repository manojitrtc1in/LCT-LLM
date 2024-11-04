import java.util.*;

class LinkedListNodeBase {
    LinkedListNodeBase prev;
    LinkedListNodeBase next;

    public LinkedListNodeBase() {
        this.prev = null;
        this.next = null;
    }

    public LinkedListNodeBase connect(LinkedListNodeBase node) {
        this.next = node;
        node.prev = this;
        return node;
    }

    public LinkedListNodeBase splice(LinkedListNodeBase fragment) {
        if (fragment.prev != null) fragment.prev.next = null;

        LinkedListNodeBase u = this;
        LinkedListNodeBase v = fragment;
        LinkedListNodeBase w = this.next;

        u.connect(v);
        while (v.next != null) v = v.next;
        v.connect(w);

        return v;
    }

    public void splice1(LinkedListNodeBase node) {
        node.connect(this.next);
        this.connect(node);
    }

    public void eject() {
        this.prev.connect(this.next);
    }

    public Iterable<LinkedListNodeBase> iterate() {
        LinkedListNodeBase u = this;
        return new Iterable<LinkedListNodeBase>() {
            public Iterator<LinkedListNodeBase> iterator() {
                return new Iterator<LinkedListNodeBase>() {
                    boolean first = true;

                    public boolean hasNext() {
                        return first || u != null;
                    }

                    public LinkedListNodeBase next() {
                        if (first) {
                            first = false;
                        } else {
                            u = u.next;
                        }
                        return u;
                    }
                };
            }
        };
    }
}

abstract class AbstractHeap {
    public abstract boolean isEmpty();
    public abstract int size();
    public abstract boolean contains(Object value);
    public abstract Object get(Object value);
    public abstract void push(Object key, Object value);
    public abstract Object pop();
    public abstract void decreaseKey(Object value, Object key);
    public abstract void merge(AbstractHeap other);
}

class _FibHeapNode extends LinkedListNodeBase {
    Object key;
    Object value;
    _FibHeapNode parent;
    _FibHeapNode child;
    int degree;
    boolean mark;

    public _FibHeapNode(Object key, Object value) {
        super();
        this.key = key;
        this.value = value;
        this.parent = null;
        this.child = null;
        this.degree = 0;
        this.mark = false;
    }
}

class FibonacciHeap extends AbstractHeap {
    private int n;
    private _FibHeapNode root;
    private Map<Object, _FibHeapNode> index;

    public FibonacciHeap(Iterable<Object[]> iterable) {
        this.n = 0;
        this.root = null;
        this.index = new HashMap<>();

        for (Object[] kv : iterable) {
            push(kv[0], kv[1]);
        }
    }

    public boolean isEmpty() {
        return n == 0;
    }

    public int size() {
        return n;
    }

    public boolean contains(Object value) {
        return index.containsKey(value);
    }

    public Object get(Object value) {
        return index.get(value).key;
    }

    public String toString() {
        return "[" + (root != null ? chainStr(root) : "") + "]";
    }

    private String chainStr(_FibHeapNode c) {
        StringBuilder sb = new StringBuilder();
        for (LinkedListNodeBase x : c.iterate()) {
            sb.append(x.key);
            if (x.child != null) sb.append(" (").append(chainStr(x.child)).append(")");
        }
        return sb.toString();
    }

    public void push(Object key, Object value) {
        _FibHeapNode node = new _FibHeapNode(key, value);
        index.put(value, node);

        if (root == null) {
            node.connect(node);
            root = node;
            n = 1;
        } else {
            root.splice1(node);
            if (((Comparable) key).compareTo(root.key) < 0) root = node;
            n++;
        }
    }

    public Object[] pop() {
        _FibHeapNode z = root;

        if (z.child != null) {
            for (LinkedListNodeBase c : z.child.iterate()) c.parent = null;
            z.splice(z.child);
        }

        if (z.next == z) {
            root = null;
        } else {
            root = z.next;
            z.eject();
            consolidate();
        }

        n--;
        index.remove(z.value);
        return new Object[]{z.key, z.value};
    }

    private void consolidate() {
        Map<Integer, _FibHeapNode> A = new HashMap<>();
        for (_FibHeapNode x : new ArrayList<>(root.iterate())) {
            int d = x.degree;
            while (A.containsKey(d)) {
                _FibHeapNode y = A.get(d);
                if (((Comparable) x.key).compareTo(y.key) > 0) {
                    _FibHeapNode temp = x;
                    x = y;
                    y = temp;
                }
                link(y, x);
                A.remove(d);
                d++;
            }
            A.put(d, x);
        }

        Iterator<_FibHeapNode> i = A.values().iterator();
        root = i.next();
        root.connect(root);
        while (i.hasNext()) {
            _FibHeapNode x = i.next();
            root.splice1(x);
            if (((Comparable) x.key).compareTo(root.key) < 0) root = x;
        }
    }

    private void link(_FibHeapNode y, _FibHeapNode x) {
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

    public void decreaseKey(Object value, Object key) {
        _FibHeapNode x = index.get(value);

        x.key = key;
        index.remove(value);
        index.put(value, x);

        _FibHeapNode y = x.parent;
        if (y != null && ((Comparable) x.key).compareTo(y.key) < 0) {
            cut(x, y);
            cascadingCut(y);
        }

        if (((Comparable) x.key).compareTo(root.key) < 0) root = x;
    }

    private void cut(_FibHeapNode x, _FibHeapNode y) {
        if (x.next == x) {
            y.child = null;
        } else {
            y.child = x.next;
        }
        x.parent = null;
        x.eject();
        y.degree--;

        root.splice1(x);
        x.mark = false;
    }

    private void cascadingCut(_FibHeapNode y) {
        _FibHeapNode z = y.parent;
        if (z != null) {
            if (!y.mark) {
                y.mark = true;
            } else {
                cut(y, z);
                cascadingCut(z);
            }
        }
    }

    public void merge(AbstractHeap other) {
        if (other == null) return;

        if (this != null) {
            root.splice(((FibonacciHeap) other).root);
            if (((FibonacciHeap) other).root.key < root.key) root = ((FibonacciHeap) other).root;
            index.putAll(((FibonacciHeap) other).index);
        } else {
            root = ((FibonacciHeap) other).root;
            index = ((FibonacciHeap) other).index;
        }

        n += ((FibonacciHeap) other).n;
        ((FibonacciHeap) other).root = null;
        ((FibonacciHeap) other).n = 0;
        ((FibonacciHeap) other).index.clear();
    }
}

class _InfKey {
    public boolean isGreaterThan(Object other) { return true; }
    public boolean isLessThan(Object other) { return false; }
}

class Implicit2Heap extends AbstractHeap {
    private List<Object[]> tree;
    private Map<Object, Integer> index;

    public Implicit2Heap(Iterable<Object[]> iterable) {
        tree = new ArrayList<>();
        index = new HashMap<>();
        buildHeap(iterable);
    }

    public boolean isEmpty() {
        return tree.isEmpty();
    }

    public int size() {
        return tree.size();
    }

    public boolean contains(Object value) {
        return index.containsKey(value);
    }

    public Object get(Object value) {
        return tree.get(index.get(value))[0];
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < tree.size(); i++) {
            if (Math.log(i + 1) % 1 == 0) sb.append("[");
            sb.append(tree.get(i)[0]);
            if (Math.log(i + 2) % 1 == 0) sb.append("]");
            sb.append(", ");
        }
        return sb.toString();
    }

    private void buildHeap(Iterable<Object[]> iterable) {
        for (Object[] kv : iterable) {
            tree.add(kv);
        }
        int size = tree.size();
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapify(i);
        }
    }

    private void heapify(int i) {
        int size = tree.size();
        int left = (i + 1) * 2 - 1;
        int right = (i + 1) * 2;

        int z = i;
        if (left < size && ((Comparable) tree.get(left)[0]).compareTo(tree.get(i)[0]) < 0) {
            z = left;
        }
        if (right < size && ((Comparable) tree.get(right)[0]).compareTo(tree.get(z)[0]) < 0) {
            z = right;
        }

        if (z != i) {
            Collections.swap(tree, i, z);
            heapify(z);
        }

        index.put(tree.get(i)[1], i);
    }

    public void decreaseKey(Object value, Object key) {
        int i = index.get(value);
        while (i > 0) {
            int p = (i + 1) / 2 - 1;
            if (!((Comparable) key).compareTo(tree.get(p)[0]) < 0) break;
            tree.set(i, tree.get(p));
            index.put(tree.get(i)[1], i);
            i = p;
        }
        tree.set(i, new Object[]{key, value});
        index.put(value, i);
    }

    public void push(Object key, Object value) {
        index.put(value, tree.size());
        tree.add(new Object[]{new _InfKey(), value});
        decreaseKey(value, key);
    }

    public Object[] pop() {
        Object[] z = tree.get(0);
        tree.set(0, tree.remove(tree.size() - 1));
        if (!tree.isEmpty()) heapify(0);
        index.remove(z[1]);
        return z;
    }

    public void merge(AbstractHeap other) {
        if (other == null) return;

        buildHeap(new ArrayList<>(tree));
        other = null;
    }
}

class _PairingHeapNode {
    Object key;
    Object value;
    _PairingHeapNode parent;
    _PairingHeapNode left;
    _PairingHeapNode right;

    public _PairingHeapNode(Object key, Object value) {
        this.key = key;
        this.value = value;
        this.parent = null;
        this.left = null;
        this.right = null;
    }

    public _PairingHeapNode link(_PairingHeapNode other) {
        if (((Comparable) other.key).compareTo(this.key) < 0) {
            _PairingHeapNode temp = this;
            this = other;
            other = temp;
        }
        if (this.left == null) {
            this.left = other;
            other.parent = this;
        } else {
            _PairingHeapNode r = this.left;
            while (r.right != null) r = r.right;
            r.right = other;
            other.parent = r;
        }
        return this;
    }
}

class PairingHeap extends AbstractHeap {
    private _PairingHeapNode root;
    private Map<Object, _PairingHeapNode> index;

    public PairingHeap(Iterable<Object[]> iterable) {
        this.root = null;
        this.index = new HashMap<>();

        for (Object[] kv : iterable) {
            push(kv[0], kv[1]);
        }
    }

    public boolean isEmpty() {
        return root == null;
    }

    public int size() {
        return index.size();
    }

    public boolean contains(Object value) {
        return index.containsKey(value);
    }

    public Object get(Object value) {
        return index.get(value).key;
    }

    public String toString() {
        return "[" + (root != null ? treeStr(root) : "") + "]";
    }

    private String treeStr(_PairingHeapNode t) {
        StringBuilder sb = new StringBuilder();
        _PairingHeapNode i = t;
        while (i != null) {
            sb.append(i.key);
            i = i.right;
        }
        if (t.left != null) sb.append(" (").append(treeStr(t.left)).append(")");
        return sb.toString();
    }

    public void push(Object key, Object value) {
        _PairingHeapNode node = new _PairingHeapNode(key, value);
        index.put(value, node);

        if (root == null) {
            root = node;
        } else {
            root = root.link(node);
        }
    }

    public void decreaseKey(Object value, Object key) {
        _PairingHeapNode x = index.get(value);
        x.key = key;
        index.remove(value);
        index.put(value, x);
        if (x.parent == null) return;

        if (x.parent.left == x) {
            x.parent.left = x.right;
        } else {
            x.parent.right = x.right;
        }
        if (x.right != null) x.right.parent = x.parent;

        x.parent = null;
        x.right = null;
        root = root.link(x);
    }

    public Object[] pop() {
        _PairingHeapNode z = root;
        if (z.left == null) {
            root = null;
        } else {
            List<_PairingHeapNode> pass0 = new ArrayList<>();
            _PairingHeapNode i = z.left;
            while (i != null) {
                _PairingHeapNode j = i.right;
                i.parent = null;
                i.right = null;
                pass0.add(i);
                i = j;
            }

            List<_PairingHeapNode> pass1 = new ArrayList<>();
            for (int j = 0; j < pass0.size() - 1; j += 2) {
                pass1.add(pass0.get(j).link(pass0.get(j + 1)));
            }
            if (pass0.size() % 2 == 1) pass1.add(pass0.get(pass0.size() - 1));

            _PairingHeapNode y = pass1.remove(pass1.size() - 1);
            while (!pass1.isEmpty()) {
                y = y.link(pass1.remove(pass1.size() - 1));
            }

            root = y;
        }

        index.remove(z.value);
        return new Object[]{z.key, z.value};
    }

    public void merge(AbstractHeap other) {
        if (other == null) return;

        if (this != null) {
            root = root.link(((PairingHeap) other).root);
            index.putAll(((PairingHeap) other).index);
        } else {
            root = ((PairingHeap) other).root;
            index = ((PairingHeap) other).index;
        }

        ((PairingHeap) other).root = null;
        ((PairingHeap) other).index.clear();
    }
}

class Graph {
    private int maxV;
    private boolean isflow;
    private boolean sparse;
    private List<Object> V;
    private Map<Object, Integer> V_index;
    private List<Map<Integer, Integer>> E;
    private List<Set<Integer>> adj;
    private Map<Integer, Integer> levels;

    public Graph(int maxV, boolean isflow, boolean sparse) {
        this.maxV = maxV;
        this.isflow = isflow;
        this.sparse = sparse;

        this.V = new ArrayList<>();
        this.V_index = new HashMap<>();

        int non_edge = isflow ? 0 : Integer.MAX_VALUE;
        if (sparse) {
            E = new ArrayList<>(maxV);
            for (int i = 0; i < maxV; i++) {
                E.add(new HashMap<>());
            }
        } else {
            E = new ArrayList<>(maxV);
            for (int i = 0; i < maxV; i++) {
                List<Integer> row = new ArrayList<>(Collections.nCopies(maxV, non_edge));
                E.add(row);
            }
        }

        adj = new ArrayList<>(maxV);
        for (int i = 0; i < maxV; i++) {
            adj.add(new HashSet<>());
        }
        levels = new HashMap<>();
    }

    public boolean contains(Object label) {
        return V_index.containsKey(label);
    }

    public Iterable<Object> iterator() {
        return V;
    }

    public int nV() {
        return V.size();
    }

    public int nE() {
        int n = 0;
        for (Set<Integer> a : adj) {
            n += a.size();
        }
        if (isflow) n /= 2;
        return n;
    }

    public void addVertex(Object label) {
        V_index.put(label, nV());
        V.add(label);
    }

    public void addVertexes(Iterable<Object> labels) {
        for (Object u_label : labels) {
            addVertex(u_label);
        }
    }

    private void addEdge(int u, int v, int w) {
        if (isflow) {
            E.get(u).put(v, E.get(u).getOrDefault(v, 0) + w);
            adj.get(u).add(v);
            adj.get(v).add(u);
        } else {
            E.get(u).put(v, w);
            adj.get(u).add(v);
        }
    }

    public void addEdge(Object u_label, Object v_label, int w) {
        addEdge(V_index.get(u_label), V_index.get(v_label), w);
    }

    private boolean isAdj(int u, int v) {
        return adj.get(u).contains(v);
    }

    public boolean isAdj(Object u_label, Object v_label) {
        return isAdj(V_index.get(u_label), V_index.get(v_label));
    }

    public void trim(Object u_label) {
        int u = V_index.get(u_label);
        adj.get(u).clear();
        if (sparse) {
            E.get(u).clear();
        } else {
            Collections.fill(E.get(u), Integer.MAX_VALUE);
        }
    }

    private int bfsLevels(int s, int t) {
        levels.put(s, Integer.MAX_VALUE);
        levels.put(s, 0);

        Queue<Integer> queue = new LinkedList<>();
        queue.add(s);
        while (!queue.isEmpty()) {
            int u = queue.poll();
            for (int v : adj.get(u)) {
                if (E.get(u).get(v) > 0 && levels.get(v) == Integer.MAX_VALUE) {
                    levels.put(v, levels.get(u) + 1);
                    queue.add(v);
                }
            }
        }

        return levels.getOrDefault(t, Integer.MAX_VALUE);
    }

    private int pushBlockingFlow(int s, int t) {
        List<Set<Integer>> pointers = new ArrayList<>();
        for (int i = 0; i < nV(); i++) {
            pointers.add(new HashSet<>(adj.get(i)));
        }

        return dfsPush(s, t, Integer.MAX_VALUE, pointers);
    }

    private int dfsPush(int u, int t, int inflow, List<Set<Integer>> pointers) {
        if (u == t) return inflow;
        int u_outflow = 0;
        while (!pointers.get(u).isEmpty()) {
            int v = pointers.get(u).iterator().next();
            pointers.get(u).remove(v);
            if (levels.get(v) == levels.get(u) + 1 && E.get(u).get(v) > 0) {
                int v_flow = dfsPush(v, t, Math.min(inflow, E.get(u).get(v)));
                E.get(u).put(v, E.get(u).get(v) - v_flow);
                E.get(v).put(u, E.get(v).getOrDefault(u, 0) + v_flow);
                inflow -= v_flow;
                u_outflow += v_flow;
                if (inflow == 0) {
                    pointers.get(u).add(v);
                    break;
                }
            }
        }
        return u_outflow;
    }

    public int maxFlow(Object s_label, Object t_label) {
        int s = V_index.get(s_label);
        int t = V_index.get(t_label);
        int mf = 0;

        while (bfsLevels(s, t) != Integer.MAX_VALUE) {
            mf += pushBlockingFlow(s, t);
        }

        return mf;
    }

    public Map<Object, Map<Object, Integer>> allPairsShortestPaths() {
        List<List<Integer>> fw = new ArrayList<>(E);
        for (int k = 0; k < nV(); k++) {
            List<List<Integer>> next_fw = new ArrayList<>();
            for (int i = 0; i < nV(); i++) {
                next_fw.add(new ArrayList<>());
                for (int j = 0; j < nV(); j++) {
                    next_fw.get(i).add(Math.min(fw.get(i).get(j), fw.get(i).get(k) + fw.get(k).get(j)));
                }
            }
            fw = next_fw;
        }

        Map<Object, Map<Object, Integer>> fw_labeled = new HashMap<>();
        for (int u = 0; u < nV(); u++) {
            Map<Object, Integer> innerMap = new HashMap<>();
            for (int v = 0; v < nV(); v++) {
                innerMap.put(V.get(v), fw.get(u).get(v));
            }
            fw_labeled.put(V.get(u), innerMap);
        }
        return fw_labeled;
    }

    public Map<Object, Object> singleSourceShortestPaths(Object s_label, Iterable<Object> t_labels, int d_limit, Class<? extends AbstractHeap> Heap) {
        class SPathsObject extends HashMap<Object, Integer> {
            Map<Object, Object> parents = new HashMap<>();
            List<Object> found = new ArrayList<>();
            int stop = Integer.MAX_VALUE;
        }

        SPathsObject ret = new SPathsObject();
        int s = V_index.get(s_label);
        Set<Integer> t_set = new HashSet<>();
        if (t_labels == null) {
            for (int i = 0; i < nV(); i++) {
                t_set.add(i);
            }
        } else {
            for (Object t_label : t_labels) {
                t_set.add(V_index.get(t_label));
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
                ret.stop = d_limit;
                break;
            }

            spaths.put(u, su);
            if (t_set.contains(u)) {
                t_set.remove(u);
                t_found.add(u);
                if (t_set.isEmpty()) {
                    ret.stop = su;
                    break;
                }
            }

            for (int v : adj.get(u)) {
                int sv = su + E.get(u).get(v);
                if (queue.contains(v)) {
                    if (sv < queue.get(v)) {
                        parents.put(v, u);
                        queue.decreaseKey(v, sv);
                    }
                } else if (!spaths.containsKey(v)) {
                    parents.put(v, u);
                    queue.push(sv, v);
                }
            }
        }

        ret.putAll(spaths);
        for (Map.Entry<Integer, Integer> entry : parents.entrySet()) {
            ret.parents.put(V.get(entry.getKey()), V.get(entry.getValue()));
        }
        ret.parents.put(s_label, null);
        ret.found = new ArrayList<>();
        for (int t : t_found) {
            ret.found.add(V.get(t));
        }
        return ret;
    }

    public int shortestPath(Object s_label, Object t_label) {
        Map<Object, Object> spaths = singleSourceShortestPaths(s_label, Collections.singletonList(t_label), Integer.MAX_VALUE, Implicit2Heap.class);
        return (int) spaths.getOrDefault(t_label, Integer.MAX_VALUE);
    }

    public boolean isBipartite() {
        List<Set<Integer>> adj = isflow ? this.adj : new ArrayList<>();
        for (int u = 0; u < nV(); u++) {
            for (int v : this.adj.get(u)) {
                adj.get(u).add(v);
                adj.get(v).add(u);
            }
        }

        Map<Integer, Boolean> colors = new HashMap<>();
        for (int u = 0; u < nV(); u++) {
            if (!bfsBicolor(u, colors, adj)) return false;
        }
        return true;
    }

    private boolean bfsBicolor(int s, Map<Integer, Boolean> colors, List<Set<Integer>> adj) {
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

public class 5f86590a8e4b985e94dec183b7a2dec4_nc {
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
        for (int i = 1; i <= n; i++) {
            G.addVertex(i);
            adj.put(i, new HashSet<>());
        }
        for (int[] road : roads) {
            G.addEdge(road[1], road[0]);
            adj.get(road[0]).add(road[1]);
        }

        Map<Object, Object> spaths = G.singleSourceShortestPaths(p.get(p.size() - 1), null, Integer.MAX_VALUE, FibonacciHeap.class);

        int minRebuild = 0;
        int maxRebuild = 0;
        for (int i = 0; i < p.size() - 1; i++) {
            int u = p.get(i);
            int u_d = (int) spaths.get(u);
            int v = p.get(i + 1);
            int v_d = (int) spaths.get(v);

            if (v_d != u_d - 1) {
                minRebuild++;
                maxRebuild++;
                continue;
            }

            for (int w : adj.get(u)) {
                if (w != v && (int) spaths.get(w) == v_d) {
                    maxRebuild++;
                    break;
                }
            }
        }

        System.out.println(minRebuild + " " + maxRebuild);
    }
}
