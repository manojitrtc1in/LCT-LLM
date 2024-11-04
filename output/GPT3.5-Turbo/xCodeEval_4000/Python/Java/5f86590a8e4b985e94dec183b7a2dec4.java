import java.util.*;

class LinkedListNodeBase {
    /**
     * Doubly Linked List node
     *
     * Methods assume that the overall list has head/tail sentinels or is circular
     * Subclasses should add attributes and/or __dict__ to __slots__
     * Multiple inheritance is not supported due to __slots__ limitation
     */
    private LinkedListNodeBase prev;
    private LinkedListNodeBase next;

    public LinkedListNodeBase() {
        this.prev = null;
        this.next = null;
    }

    public LinkedListNodeBase getPrev() {
        return prev;
    }

    public void setPrev(LinkedListNodeBase prev) {
        this.prev = prev;
    }

    public LinkedListNodeBase getNext() {
        return next;
    }

    public void setNext(LinkedListNodeBase next) {
        this.next = next;
    }

    public LinkedListNodeBase connect(LinkedListNodeBase node) {
        this.next = node;
        node.prev = this;
        return node;
    }

    public LinkedListNodeBase splice(LinkedListNodeBase fragment) {
        if (fragment.getPrev() != null) fragment.getPrev().setNext(null);

        LinkedListNodeBase u = this;
        LinkedListNodeBase v = fragment;
        LinkedListNodeBase w = this.next;

        u.connect(v);
        while (v.getNext() != null) v = v.getNext();
        v.connect(w);

        return v;
    }

    public void splice1(LinkedListNodeBase node) {
        node.connect(this.getNext());
        this.connect(node);
    }

    public void eject() {
        this.getPrev().connect(this.getNext());
    }

    public Iterator<LinkedListNodeBase> iterate() {
        LinkedListNodeBase u = this;
        return new Iterator<LinkedListNodeBase>() {
            LinkedListNodeBase current = u;

            @Override
            public boolean hasNext() {
                return current != null && current != u;
            }

            @Override
            public LinkedListNodeBase next() {
                LinkedListNodeBase temp = current;
                current = current.getNext();
                return temp;
            }
        };
    }
}

abstract class AbstractHeap {
    public abstract void push(int key, int value);
    public abstract int pop();
    public abstract void decreaseKey(int value, int key);
    public abstract void merge(AbstractHeap other);
}

class _FibHeapNode extends LinkedListNodeBase {
    private int key;
    private int value;
    private _FibHeapNode parent;
    private _FibHeapNode child;
    private int degree;
    private boolean mark;

    public _FibHeapNode(int key, int value) {
        super();
        this.key = key;
        this.value = value;
        this.parent = null;
        this.child = null;
        this.degree = 0;
        this.mark = false;
    }

    public int getKey() {
        return key;
    }

    public int getValue() {
        return value;
    }

    public _FibHeapNode getParent() {
        return parent;
    }

    public void setParent(_FibHeapNode parent) {
        this.parent = parent;
    }

    public _FibHeapNode getChild() {
        return child;
    }

    public void setChild(_FibHeapNode child) {
        this.child = child;
    }

    public int getDegree() {
        return degree;
    }

    public void setDegree(int degree) {
        this.degree = degree;
    }

    public boolean isMark() {
        return mark;
    }

    public void setMark(boolean mark) {
        this.mark = mark;
    }
}

class FibonacciHeap extends AbstractHeap {
    private int n;
    private _FibHeapNode root;
    private Map<Integer, _FibHeapNode> index;

    public FibonacciHeap() {
        super();
        this.n = 0;
        this.root = null;
        this.index = new HashMap<>();
    }

    @Override
    public void push(int key, int value) {
        _FibHeapNode node = new _FibHeapNode(key, value);
        index.put(value, node);

        if (root == null) {
            node.connect(node);
            root = node;
            n = 1;
        } else {
            root.splice1(node);
            if (key < root.getKey()) root = node;
            n++;
        }
    }

    @Override
    public int pop() {
        _FibHeapNode z = root;

        if (z.getChild() != null) {
            for (_FibHeapNode c : z.getChild().iterate()) c.setParent(null);
            z.splice(z.getChild());
        }

        if (z.getNext() == z) {
            root = null;
        } else {
            root = z.getNext();
            z.eject();
            consolidate();
        }

        n--;
        index.remove(z.getValue());
        return z.getKey();
    }

    private void consolidate() {
        Map<Integer, _FibHeapNode> A = new HashMap<>();
        for (_FibHeapNode x : new ArrayList<>(root.iterate())) {
            int d = x.getDegree();
            while (A.containsKey(d)) {
                _FibHeapNode y = A.get(d);
                if (x.getKey() > y.getKey()) {
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
            if (x.getKey() < root.getKey()) root = x;
        }
    }

    private void link(_FibHeapNode y, _FibHeapNode x) {
        y.eject();
        y.setParent(x);
        if (x.getChild() != null) {
            x.getChild().splice1(y);
        } else {
            x.setChild(y);
            y.connect(y);
        }
        x.setDegree(x.getDegree() + 1);
        y.setMark(false);
    }

    @Override
    public void decreaseKey(int value, int key) {
        _FibHeapNode x = index.get(value);

        x.setKey(key);
        index.remove(value);
        index.put(value, x);

        _FibHeapNode y = x.getParent();
        if (y != null && x.getKey() < y.getKey()) {
            cut(x, y);
            cascadingCut(y);
        }

        if (x.getKey() < root.getKey()) root = x;
    }

    private void cut(_FibHeapNode x, _FibHeapNode y) {
        if (x.getNext() == x) {
            y.setChild(null);
        } else {
            y.setChild(x.getNext());
        }
        x.setParent(null);
        x.eject();
        y.setDegree(y.getDegree() - 1);

        root.splice1(x);
        x.setMark(false);
    }

    private void cascadingCut(_FibHeapNode y) {
        _FibHeapNode z = y.getParent();
        if (z != null) {
            if (!y.isMark()) {
                y.setMark(true);
            } else {
                cut(y, z);
                cascadingCut(z);
            }
        }
    }

    @Override
    public void merge(AbstractHeap other) {
        if (!(other instanceof FibonacciHeap)) return;

        FibonacciHeap o = (FibonacciHeap) other;
        if (o.n == 0) return;

        if (n > 0) {
            root.splice(o.root);
            if (o.root.getKey() < root.getKey()) root = o.root;
            index.putAll(o.index);
        } else {
            root = o.root;
            index = o.index;
        }

        n += o.n;
        o.root = null;
        o.n = 0;
        o.index = new HashMap<>();
    }
}

class _InfKey implements Comparable<_InfKey> {
    @Override
    public int compareTo(_InfKey other) {
        return 1;
    }
}

class Implicit2Heap extends AbstractHeap {
    private List<Pair<Integer, Integer>> tree;
    private Map<Integer, Integer> index;

    public Implicit2Heap() {
        super();
        this.tree = new ArrayList<>();
        this.index = new HashMap<>();
    }

    @Override
    public void push(int key, int value) {
        index.put(value, tree.size());
        tree.add(new Pair<>(Integer.MAX_VALUE, value));
        decreaseKey(value, key);
    }

    @Override
    public int pop() {
        Pair<Integer, Integer> z = tree.get(0);
        tree.set(0, tree.get(tree.size() - 1));
        tree.remove(tree.size() - 1);
        if (!tree.isEmpty()) heapify(0);

        index.remove(z.getValue());
        return z.getKey();
    }

    @Override
    public void decreaseKey(int value, int key) {
        int i = index.get(value);

        while (i > 0) {
            int p = (i + 1) / 2 - 1;
            if (!(key < tree.get(p).getKey())) break;
            tree.set(i, tree.get(p));
            index.put(tree.get(i).getValue(), i);
            i = p;
        }

        tree.set(i, new Pair<>(key, value));
        index.put(value, i);
    }

    private void heapify(int i) {
        int left = (i + 1) * 2 - 1;
        int right = (i + 1) * 2 + 1 - 1;
        int size = tree.size();

        int z = i;
        if (left < size && tree.get(left).getKey() < tree.get(i).getKey()) {
            z = left;
        }
        if (right < size && tree.get(right).getKey() < tree.get(z).getKey()) {
            z = right;
        }

        if (z != i) {
            Collections.swap(tree, i, z);
            index.put(tree.get(i).getValue(), i);
            index.put(tree.get(z).getValue(), z);
            heapify(z);
        }
    }

    @Override
    public void merge(AbstractHeap other) {
        if (!(other instanceof Implicit2Heap)) return;

        Implicit2Heap o = (Implicit2Heap) other;
        if (o.tree.isEmpty()) return;

        tree.addAll(o.tree);
        index.putAll(o.index);
        buildHeap(tree.size() / 2 - 1);
        o.tree = new ArrayList<>();
        o.index = new HashMap<>();
    }

    private void buildHeap(int size) {
        for (int i = size; i >= 0; i--) {
            heapify(i);
        }
    }
}

class _PairingHeapNode {
    private int key;
    private int value;
    private _PairingHeapNode parent;
    private _PairingHeapNode left;
    private _PairingHeapNode right;

    public _PairingHeapNode(int key, int value) {
        this.key = key;
        this.value = value;
        this.parent = null;
        this.left = null;
        this.right = null;
    }

    public int getKey() {
        return key;
    }

    public int getValue() {
        return value;
    }

    public _PairingHeapNode getParent() {
        return parent;
    }

    public void setParent(_PairingHeapNode parent) {
        this.parent = parent;
    }

    public _PairingHeapNode getLeft() {
        return left;
    }

    public void setLeft(_PairingHeapNode left) {
        this.left = left;
    }

    public _PairingHeapNode getRight() {
        return right;
    }

    public void setRight(_PairingHeapNode right) {
        this.right = right;
    }

    public _PairingHeapNode link(_PairingHeapNode other) {
        if (other.getKey() < this.getKey()) {
            _PairingHeapNode temp = this;
            this = other;
            other = temp;
        }
        if (this.getLeft() == null) {
            this.setLeft(other);
            other.setParent(this);
        } else {
            _PairingHeapNode r = this.getLeft();
            while (r.getRight() != null) r = r.getRight();
            r.setRight(other);
            other.setParent(r);
        }
        return this;
    }
}

class PairingHeap extends AbstractHeap {
    private _PairingHeapNode root;
    private Map<Integer, _PairingHeapNode> index;

    public PairingHeap() {
        super();
        this.root = null;
        this.index = new HashMap<>();
    }

    @Override
    public void push(int key, int value) {
        _PairingHeapNode node = new _PairingHeapNode(key, value);
        index.put(value, node);

        if (root == null) {
            root = node;
        } else {
            root = root.link(node);
        }
    }

    @Override
    public int pop() {
        _PairingHeapNode z = root;
        if (z.getLeft() == null) {
            root = null;
        } else {
            List<_PairingHeapNode> pass0 = new ArrayList<>();
            _PairingHeapNode i = z.getLeft();
            while (i != null) {
                _PairingHeapNode j = i.getRight();
                i.setParent(null);
                i.setRight(null);
                pass0.add(i);
                i = j;
            }

            List<_PairingHeapNode> pass1 = new ArrayList<>();
            for (int k = 0; k < pass0.size() - 1; k += 2) {
                pass1.add(pass0.get(k).link(pass0.get(k + 1)));
            }
            if (pass0.size() % 2 == 1) pass1.add(pass0.get(pass0.size() - 1));

            _PairingHeapNode y = pass1.remove(pass1.size() - 1);
            while (!pass1.isEmpty()) {
                y = y.link(pass1.remove(pass1.size() - 1));
            }

            root = y;
        }

        index.remove(z.getValue());
        return z.getKey();
    }

    @Override
    public void decreaseKey(int value, int key) {
        _PairingHeapNode x = index.get(value);

        x.setKey(key);
        index.remove(value);
        index.put(value, x);
        if (x.getParent() == null) return;

        if (x.getParent().getLeft() == x) {
            x.getParent().setLeft(x.getRight());
        } else {
            x.getParent().setRight(x.getRight());
        }
        if (x.getRight() != null) x.getRight().setParent(x.getParent());

        x.setParent(null);
        x.setRight(null);
        root = root.link(x);
    }

    @Override
    public void merge(AbstractHeap other) {
        if (!(other instanceof PairingHeap)) return;

        PairingHeap o = (PairingHeap) other;
        if (o.root == null) return;

        root = root.link(o.root);
        index.putAll(o.index);
        o.root = null;
        o.index = new HashMap<>();
    }
}

class Graph {
    private int maxV;
    private boolean isflow;
    private boolean sparse;
    private List<Integer> V;
    private Map<Integer, Integer> V_index;
    private List<Map<Integer, Integer>> E;
    private List<Set<Integer>> adj;
    private Map<Integer, List<Integer>> levels;

    public Graph(int maxV, boolean isflow, boolean sparse) {
        this.maxV = maxV;
        this.isflow = isflow;
        this.sparse = sparse;
        this.V = new ArrayList<>();
        this.V_index = new HashMap<>();
        this.E = new ArrayList<>();
        this.adj = new ArrayList<>();
        this.levels = new HashMap<>();
    }

    public void addVertex(int label) {
        V_index.put(label, V.size());
        V.add(label);
    }

    public void addVertexes(List<Integer> labels) {
        for (int u_label : labels) {
            addVertex(u_label);
        }
    }

    private void addEdge(int u, int v, int w) {
        if (isflow) {
            E.get(u).put(v, E.get(u).getOrDefault(v, 0) + w);
            adj.get(u).add(v);
            adj.get(v).add(u);
        } else {
            E.get(u).set(v, w);
            adj.get(u).add(v);
        }
    }

    public void addEdge(int u_label, int v_label, int w) {
        addEdge(V_index.get(u_label), V_index.get(v_label), w);
    }

    private boolean isadj(int u, int v) {
        return adj.get(u).contains(v);
    }

    public boolean isadj(int u_label, int v_label) {
        return isadj(V_index.get(u_label), V_index.get(v_label));
    }

    public void trim(int u_label) {
        int u = V_index.get(u_label);
        adj.get(u).clear();

        if (sparse) {
            E.get(u).clear();
        } else {
            E.get(u).replaceAll((k, v) -> Integer.MAX_VALUE);
        }
    }

    private int bfsLevels(int s, int t) {
        List<Integer> level = new ArrayList<>(Collections.nCopies(maxV, Integer.MAX_VALUE));
        level.set(s, 0);

        Queue<Integer> queue = new LinkedList<>();
        queue.add(s);
        while (!queue.isEmpty()) {
            int u = queue.poll();
            for (int v : adj.get(u)) {
                if (E.get(u).get(v) > 0 && level.get(v) == Integer.MAX_VALUE) {
                    level.set(v, level.get(u) + 1);
                    queue.add(v);
                }
            }
        }

        levels.put(s, level);
        return level.get(t);
    }

    private int pushBlockingFlow(int s, int t) {
        Map<Integer, Iterator<Integer>> pointers = new HashMap<>();
        for (int u = 0; u < maxV; u++) {
            pointers.put(u, adj.get(u).iterator());
        }

        int dfsPush(int u, int t, int inflow) {
            if (u == t) return inflow;
            int u_outflow = 0;
            while (pointers.get(u).hasNext()) {
                int v = pointers.get(u).next();
                if (levels.get(s).get(v) == levels.get(s).get(u) + 1 && E.get(u).get(v) > 0) {
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

        int blocking_flow = dfsPush(s, t, Integer.MAX_VALUE);
        levels.clear();
        return blocking_flow;
    }

    public int maxFlow(int s_label, int t_label) {
        int[][] E_saved = new int[maxV][maxV];
        for (int i = 0; i < maxV; i++) {
            E_saved[i] = E.get(i).clone();
        }

        int s = V_index.get(s_label);
        int t = V_index.get(t_label);

        int mf = 0;
        while (bfsLevels(s, t) != Integer.MAX_VALUE) {
            mf += pushBlockingFlow(s, t);
        }

        for (int i = 0; i < maxV; i++) {
            E.set(i, E_saved[i]);
        }
        return mf;
    }

    public Map<Integer, Map<Integer, Integer>> allPairsShortestPaths() {
        int[][] fw = new int[maxV][maxV];
        for (int i = 0; i < maxV; i++) {
            fw[i] = E.get(i).values().stream().mapToInt(Integer::intValue).toArray();
        }

        for (int k = 0; k < maxV; k++) {
            int[][] next_fw = new int[maxV][maxV];
            for (int i = 0; i < maxV; i++) {
                next_fw[i] = new int[maxV];
                for (int j = 0; j < maxV; j++) {
                    next_fw[i][j] = Math.min(fw[i][j], fw[i][k] + fw[k][j]);
                }
            }
            fw = next_fw;
        }

        Map<Integer, Map<Integer, Integer>> fw_labeled = new HashMap<>();
        for (int u = 0; u < maxV; u++) {
            Map<Integer, Integer> fw_row = new HashMap<>();
            for (int v = 0; v < maxV; v++) {
                fw_row.put(V.get(v), fw[u][v]);
            }
            fw_labeled.put(V.get(u), fw_row);
        }
        return fw_labeled;
    }

    public SPathsObject singleSourceShortestPaths(int s_label, List<Integer> t_labels, int d_limit) {
        class SPathsObject extends HashMap<Integer, Integer> {
            private Map<Integer, Integer> parents;
            private List<Integer> found;
            private int stop;
        }

        SPathsObject ret = new SPathsObject();

        int s = V_index.get(s_label);
        Set<Integer> t_set;
        if (t_labels == null) {
            t_set = new HashSet<>(V_index.values());
        } else {
            t_set = new HashSet<>();
            for (int t_label : t_labels) {
                t_set.add(V_index.get(t_label));
            }
        }

        Implicit2Heap queue = new Implicit2Heap();
        queue.push(0, s);
        Map<Integer, Integer> spaths = new HashMap<>();
        Map<Integer, Integer> parents = new HashMap<>();
        List<Integer> t_found = new ArrayList<>();
        while (!queue.isEmpty()) {
            int su = queue.pop();
            int u = queue.pop();
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
        ret.parents = new HashMap<>();
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

    public int shortestPath(int s_label, int t_label, int d_limit) {
        SPathsObject spaths = singleSourceShortestPaths(s_label, Collections.singletonList(t_label), d_limit);
        return spaths.get(t_label);
    }

    public boolean isBipartite() {
        Set<Integer> colors = new HashMap<>();
        boolean bfsBicolor(int s) {
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

        for (int u = 0; u < maxV; u++) {
            if (!bfsBicolor(u)) {
                return false;
            }
        }
        return true;
    }
}

class Main {
    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        List<Pair<Integer, Integer>> roads = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            roads.add(new Pair<>(u, v));
        }
        int k = scanner.nextInt();
        List<Integer> p = new ArrayList<>();
        for (int i = 0; i < k; i++) {
            p.add(scanner.nextInt());
        }

        Graph G = new Graph(n, false, true);
        Set<Integer> adj = new HashSet<>();
        G.addVertexes(p.subList(0, p.size() - 1));
        for (Pair<Integer, Integer> road : roads) {
            G.addEdge(road.getValue(), road.getKey());
            adj.add(road.getKey());
        }

        Map<Integer, Integer> spaths = G.singleSourceShortestPaths(p.get(p.size() - 1), null, Integer.MAX_VALUE);
        int min_rebuild = 0;
        int max_rebuild = 0;
        for (int i = 0; i < p.size() - 1; i++) {
            int u = p.get(i);
            int u_d = spaths.get(u);
            int v = p.get(i + 1);
            int v_d = spaths.get(v);

            if (v_d != u_d - 1) {
                min_rebuild++;
                max_rebuild++;
                continue;
            }

            boolean found = false;
            for (int w : adj) {
                if (w != v && spaths.get(w) == v_d) {
                    max_rebuild++;
                    found = true;
                    break;
                }
            }
            if (!found) min_rebuild++;
        }

        System.out.println(min_rebuild + " " + max_rebuild);
    }
}
