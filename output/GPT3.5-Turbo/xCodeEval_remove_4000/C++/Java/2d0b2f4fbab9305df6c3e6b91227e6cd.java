import java.util.*;

class ScopeTimer {
    private long tic;
    private String msg;

    public ScopeTimer(String msg) {
        this.tic = System.currentTimeMillis();
        this.msg = msg;
    }

    public void finalize() {
        long toc = System.currentTimeMillis();
        long dt = toc - tic;

        long mil = dt % 1000L;
        long sec = (dt / 1000L) % 60L;
        long min = (dt / 60000L) % 60L;
        long hrs = (dt / 3600000L);

        System.out.println("\n" + msg + "\n\telapsed time: " + hrs + " hrs, " + min + " min, " + sec + " sec, " + mil + " mil-sec");
    }
}

class RandInt {
    private int m;
    private double f;

    public RandInt(int a, int b) {
        this.m = a;
        this.f = (double)(b - a) / Integer.MAX_VALUE;
    }

    public int nextInt() {
        return m + (int)Math.ceil(f * Math.random());
    }
}

class RandDouble {
    private double m;
    private double f;

    public RandDouble(double a, double b) {
        this.m = a;
        this.f = (b - a) / Integer.MAX_VALUE;
    }

    public double nextDouble() {
        return m + f * Math.random();
    }
}

class Noisy {
    private String msg;

    public Noisy(String str) {
        this.msg = str;
        System.out.println("Noisy ( " + msg + " )\t@ " + this);
    }

    public void finalize() {
        System.out.println("~Noisy ( " + msg + " )\t@ " + this);
    }

    public void beep() {
        System.out.println("beep ( " + msg + " )\t@ " + this);
    }

    public void beep() {
        System.out.println("const beep ( " + msg + " )\t@ " + this);
    }
}

class UnionFind {
    private int[] parent;
    private int[] rank;

    public UnionFind(int n) {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    public int find(int s) {
        int p = parent[s];
        return parent[p] == p ? p : parent[s] = find(p);
    }

    public void lazyUnion(int i, int j) {
        i = find(i);
        j = find(j);

        if (i != j) {
            if (rank[i] < rank[j]) {
                parent[i] = j;
            } else {
                parent[j] = i;
                rank[i] += rank[i] == rank[j] ? 1 : 0;
            }
        }
    }
}

class Heap<T> {
    private List<T> val;
    private Comparator<T> comp;

    public Heap() {
        this.val = new ArrayList<>();
        this.comp = Comparator.naturalOrder();
    }

    public Heap(Comparator<T> comp) {
        this.val = new ArrayList<>();
        this.comp = comp;
    }

    public Heap(Collection<T> collection, Comparator<T> comp) {
        this.val = new ArrayList<>(collection);
        this.comp = comp;
        makeHeap();
    }

    public T front() {
        return val.get(0);
    }

    public boolean empty() {
        return val.isEmpty();
    }

    public int size() {
        return val.size();
    }

    public void push(T a) {
        val.add(a);
        pushHeap();
    }

    public void pop() {
        popHeap();
    }

    private void makeHeap() {
        for (int i = val.size() / 2 - 1; i >= 0; i--) {
            downHeap(i, val.size());
        }
    }

    private void pushHeap() {
        int i = val.size() - 1;
        while (i > 0) {
            int p = (i - 1) / 2;
            if (comp.compare(val.get(p), val.get(i)) <= 0) {
                break;
            }
            swap(i, p);
            i = p;
        }
    }

    private void popHeap() {
        int n = val.size();
        if (n == 0) {
            return;
        }
        swap(0, n - 1);
        downHeap(0, n - 1);
    }

    private void downHeap(int i, int n) {
        while (true) {
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            if (l >= n) {
                break;
            }
            int j = l;
            if (r < n && comp.compare(val.get(l), val.get(r)) > 0) {
                j = r;
            }
            if (comp.compare(val.get(i), val.get(j)) <= 0) {
                break;
            }
            swap(i, j);
            i = j;
        }
    }

    private void swap(int i, int j) {
        T tmp = val.get(i);
        val.set(i, val.get(j));
        val.set(j, tmp);
    }
}

class UnionFind {
    private int[] parent;
    private int[] rank;

    public UnionFind(int n) {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    public int find(int s) {
        int p = parent[s];
        return parent[p] == p ? p : parent[s] = find(p);
    }

    public void lazyUnion(int i, int j) {
        i = find(i);
        j = find(j);

        if (i != j) {
            if (rank[i] < rank[j]) {
                parent[i] = j;
            } else {
                parent[j] = i;
                rank[i] += rank[i] == rank[j] ? 1 : 0;
            }
        }
    }
}

class UnionFind {
    private int[] parent;
    private int[] rank;

    public UnionFind(int n) {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    public int find(int s) {
        int p = parent[s];
        return parent[p] == p ? p : parent[s] = find(p);
    }

    public void lazyUnion(int i, int j) {
        i = find(i);
        j = find(j);

        if (i != j) {
            if (rank[i] < rank[j]) {
                parent[i] = j;
            } else {
                parent[j] = i;
                rank[i] += rank[i] == rank[j] ? 1 : 0;
            }
        }
    }
}

class UnionFind {
    private int[] parent;
    private int[] rank;

    public UnionFind(int n) {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    public int find(int s) {
        int p = parent[s];
        return parent[p] == p ? p : parent[s] = find(p);
    }

    public void lazyUnion(int i, int j) {
        i = find(i);
        j = find(j);

        if (i != j) {
            if (rank[i] < rank[j]) {
                parent[i] = j;
            } else {
                parent[j] = i;
                rank[i] += rank[i] == rank[j] ? 1 : 0;
            }
        }
    }
}

class UnionFind {
    private int[] parent;
    private int[] rank;

    public UnionFind(int n) {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    public int find(int s) {
        int p = parent[s];
        return parent[p] == p ? p : parent[s] = find(p);
    }

    public void lazyUnion(int i, int j) {
        i = find(i);
        j = find(j);

        if (i != j) {
            if (rank[i] < rank[j]) {
                parent[i] = j;
            } else {
                parent[j] = i;
                rank[i] += rank[i] == rank[j] ? 1 : 0;
            }
        }
    }
}

class UnionFind {
    private int[] parent;
    private int[] rank;

    public UnionFind(int n) {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    public int find(int s) {
        int p = parent[s];
        return parent[p] == p ? p : parent[s] = find(p);
    }

    public void lazyUnion(int i, int j) {
        i = find(i);
        j = find(j);

        if (i != j) {
            if (rank[i] < rank[j]) {
                parent[i] = j;
            } else {
                parent[j] = i;
                rank[i] += rank[i] == rank[j] ? 1 : 0;
            }
        }
    }
}

class UnionFind {
    private int[] parent;
    private int[] rank;

    public UnionFind(int n) {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    public int find(int s) {
        int p = parent[s];
        return parent[p] == p ? p : parent[s] = find(p);
    }

    public void lazyUnion(int i, int j) {
        i = find(i);
        j = find(j);

        if (i != j) {
            if (rank[i] < rank[j]) {
                parent[i] = j;
            } else {
                parent[j] = i;
                rank[i] += rank[i] == rank[j] ? 1 : 0;
            }
        }
    }
}

class UnionFind {
    private int[] parent;
    private int[] rank;

    public UnionFind(int n) {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    public int find(int s) {
        int p = parent[s];
        return parent[p] == p ? p : parent[s] = find(p);
    }

    public void lazyUnion(int i, int j) {
        i = find(i);
        j = find(j);

        if (i != j) {
            if (rank[i] < rank[j]) {
                parent[i] = j;
            } else {
                parent[j] = i;
                rank[i] += rank[i] == rank[j] ? 1 : 0;
            }
        }
    }
}

class UnionFind {
    private int[] parent;
    private int[] rank;

    public UnionFind(int n) {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    public int find(int s) {
        int p = parent[s];
        return parent[p] == p ? p : parent[s] = find(p);
    }

    public void lazyUnion(int i, int j) {
        i = find(i);
        j = find(j);

        if (i != j) {
            if (rank[i] < rank[j]) {
                parent[i] = j;
            } else {
                parent[j] = i;
                rank[i] += rank[i] == rank[j] ? 1 : 0;
            }
        }
    }
}

class UnionFind {
    private int[] parent;
    private int[] rank;

    public UnionFind(int n) {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    public int find(int s) {
        int p = parent[s];
        return parent[p] == p ? p : parent[s] = find(p);
    }

    public void lazyUnion(int i, int j) {
        i = find(i);
        j = find(j);

        if (i != j) {
            if (rank[i] < rank[j]) {
                parent[i] = j;
            } else {
                parent[j] = i;
                rank[i] += rank[i] == rank[j] ? 1 : 0;
            }
        }
    }
}

class UnionFind {
    private int[] parent;
    private int[] rank;

    public UnionFind(int n) {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    public int find(int s) {
        int p = parent[s];
        return parent[p] == p ? p : parent[s] = find(p);
    }

    public void lazyUnion(int i, int j) {
        i = find(i);
        j = find(j);

        if (i != j) {
            if (rank[i] < rank[j]) {
                parent[i] = j;
            } else {
                parent[j] = i;
                rank[i] += rank[i] == rank[j] ? 1 : 0;
            }
        }
    }
}

class UnionFind {
    private int[] parent;
    private int[] rank;

    public UnionFind(int n) {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    public int find(int s) {
        int p = parent[s];
        return parent[p] == p ? p : parent[s] = find(p);
    }

    public void lazyUnion(int i, int j) {
        i = find(i);
        j = find(j);

        if (i != j) {
            if (rank[i] < rank[j]) {
                parent[i] = j;
            } else {
                parent[j] = i;
                rank[i] += rank[i] == rank[j] ? 1 : 0;
            }
        }
    }
}

class UnionFind {
    private int[] parent;
    private int[] rank;

    public UnionFind(int n) {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    public int find(int s) {
        int p = parent[s];
        return parent[p] == p ? p : parent[s] = find(p);
    }

    public void lazyUnion(int i, int j) {
        i = find(i);
        j = find(j);

        if (i != j) {
            if (rank[i] < rank[j]) {
                parent[i] = j;
            } else {
                parent[j] = i;
                rank[i] += rank[i] == rank[j] ? 1 : 0;
            }
        }
    }
}

class UnionFind {
    private int[] parent;
    private int[] rank;

    public UnionFind(int n) {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    public int find(int s) {
        int p = parent[s];
        return parent[p] == p ? p : parent[s] = find(p);
    }

    public void lazyUnion(int i, int j) {
        i = find(i);
        j = find(j);

        if (i != j) {
            if (rank[i] < rank[j]) {
                parent[i] = j;
            } else {
                parent[j] = i;
                rank[i] += rank[i] == rank[j] ? 1 : 0;
            }
        }
    }
}

class UnionFind {
    private int[] parent;
    private int[] rank;

    public UnionFind(int n) {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    public int find(int s) {
        int p = parent[s];
        return parent[p] == p ? p : parent[s] = find(p);
    }

    public void lazyUnion(int i, int j) {
        i = find(i);
        j = find(j);

        if (i != j) {
            if (rank[i] < rank[j]) {
                parent[i] = j;
            } else {
                parent[j] = i;
                rank[i] += rank[i] == rank[j] ? 1 : 0;
            }
        }
    }
}

class UnionFind {
    private int[] parent;
    private int[] rank;

    public UnionFind(int n) {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    public int find(int s) {
        int p = parent[s];
        return parent[p] == p ? p : parent[s] = find(p);
    }

    public void lazyUnion(int i, int j) {
        i = find(i);
        j = find(j);

        if (i != j) {
            if (rank[i] < rank[j]) {
                parent[i] = j;
            } else {
                parent[j] = i;
                rank[i] += rank[i] == rank[j] ? 1 : 0;
            }
        }
    }
}

class UnionFind {
    private int[] parent;
    private int[] rank;

    public UnionFind(int n) {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    public int find(int s) {
        int p = parent[s];
        return parent[p] == p ? p : parent[s] = find(p);
    }

    public void lazyUnion(int i, int j) {
        i = find(i);
        j = find(j);

        if (i != j) {
            if (rank[i] < rank[j]) {
                parent[i] = j;
            } else {
                parent[j] = i;
                rank[i] += rank[i] == rank[j] ? 1 : 0;
            }
        }
    }
}

class UnionFind {
    private int[] parent;
    private int[] rank;

    public UnionFind(int n) {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    public int find(int s) {
        int p = parent[s];
        return parent[p] == p ? p : parent[s] = find(p);
    }

    public void lazyUnion(int i, int j) {
        i = find(i);
        j = find(j);

        if (i != j) {
            if (rank[i] < rank[j]) {
                parent[i] = j;
            } else {
                parent[j] = i;
                rank[i] += rank[i] == rank[j] ? 1 : 0;
            }
        }
    }
}

class UnionFind {
    private int[] parent;
    private int[] rank;

    public UnionFind(int n) {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    public int find(int s) {
        int p = parent[s];
        return parent[p] == p ? p : parent[s] = find(p);
    }

    public void lazyUnion(int i, int j) {
        i = find(i);
        j = find(j);

        if (i != j) {
            if (rank[i] < rank[j]) {
                parent[i] = j;
            } else {
                parent[j] = i;
                rank[i] += rank[i] == rank[j] ? 1 : 0;
            }
        }
    }
}

class UnionFind {
    private int[] parent;
    private int[] rank;

    public UnionFind(int n) {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    public int find(int s) {
        int p = parent[s];
        return parent[p] == p ? p : parent[s] = find(p);
    }

    public void lazyUnion(int i, int j) {
        i = find(i);
        j = find(j);

        if (i != j) {
            if (rank[i] < rank[j]) {
                parent[i] = j;
            } else {
                parent[j] = i;
                rank[i] += rank[i] == rank[j] ? 1 : 0;
            }
        }
    }
}

class UnionFind {
    private int[] parent;
    private int[] rank;

    public UnionFind(int n) {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    public int find(int s) {
        int p = parent[s];
        return parent[p] == p ? p : parent[s] = find(p);
    }

    public void lazyUnion(int i, int j) {
        i = find(i);
        j = find(j);

        if (i != j) {
            if (rank[i] < rank[j]) {
                parent[i] = j;
            } else {
                parent[j] = i;
                rank[i] += rank[i] == rank[j] ? 1 : 0;
            }
        }
    }
}

class UnionFind {
    private int[] parent;
    private int[] rank;

    public UnionFind(int n) {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    public int find(int s) {
        int p = parent[s];
        return parent[p] == p ? p : parent[s] = find(p);
    }

    public void lazyUnion(int i, int j) {
        i = find(i);
        j = find(j);

        if (i != j) {
            if (rank[i] < rank[j]) {
                parent[i] = j;
            } else {
                parent[j] = i;
                rank[i] += rank[i] == rank[j] ? 1 : 0;
            }
        }
    }
}

class UnionFind {
    private int[] parent;
    private int[] rank;

    public UnionFind(int n) {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    public int find(int s) {
        int p = parent[s];
        return parent[p] == p ? p : parent[s] = find(p);
    }

    public void lazyUnion(int i, int j) {
        i = find(i);
        j = find(j);

        if (i != j) {
            if (rank[i] < rank[j]) {
                parent[i] = j;
            } else {
                parent[j] = i;
                rank[i] += rank[i] == rank[j] ? 1 : 0;
            }
        }
    }
}

class UnionFind {
    private int[] parent;
    private int[] rank;

    public UnionFind(int n) {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    public int find(int s) {
        int p = parent[s];
        return parent[p] == p ? p : parent[s] = find(p);
    }

    public void lazyUnion(int i, int j) {
        i = find(i);
        j = find(j);

        if (i != j) {
            if (rank[i] < rank[j]) {
                parent[i] = j;
            } else {
                parent[j] = i;
                rank[i] += rank[i] == rank[j] ? 1 : 0;
            }
        }
    }
}

class UnionFind {
    private int[] parent;
    private int[] rank;

    public UnionFind(int n) {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = i;
