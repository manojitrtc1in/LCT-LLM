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
        this.f = (double) (b - a) / Integer.MAX_VALUE;
    }

    public int next() {
        return m + (int) Math.ceil(f * Math.random());
    }
}

class RandDouble {
    private double m;
    private double f;

    public RandDouble(double a, double b) {
        this.m = a;
        this.f = (b - a) / Integer.MAX_VALUE;
    }

    public double next() {
        return m + f * Math.random();
    }
}

class Noisy {
    private String msg;

    public Noisy(String str) {
        this.msg = str;
        System.out.println(" Noisy ( " + msg + " )\t@ " + this);
    }

    public void finalize() {
        System.out.println("~Noisy ( " + msg + " )\t@ " + this);
    }

    public void beep() {
        System.out.println(" beep ( " + msg + " )\t@ " + this);
    }

    public void beep() {
        System.out.println(" const beep ( " + msg + " )\t@ " + this);
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
        if (parent[s] == s) {
            return s;
        } else {
            parent[s] = find(parent[s]);
            return parent[s];
        }
    }

    public void union(int i, int j) {
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

class id1 {
    private List<List<Integer>> adj;
    private List<Boolean> tag;
    private int npair;
    private int NIL;
    private int INF;
    private List<Integer> g1;
    private List<Integer> dist;
    private List<Integer> pair;

    public id1(List<List<Integer>> adj, List<Boolean> tag) {
        this.adj = adj;
        this.tag = tag;
        this.npair = 0;
        this.NIL = adj.size();
        this.INF = adj.size() + 1;
        this.dist = new ArrayList<>(Collections.nCopies(adj.size(), INF));
        this.pair = new ArrayList<>(Collections.nCopies(adj.size(), NIL));

        for (int j = 0; j < tag.size(); j++) {
            if (tag.get(j)) {
                g1.add(j);
            }
        }

        while (mf_breadth_first_search()) {
            for (int v : g1) {
                if (pair.get(v) == NIL && mf_depth_first_search(v)) {
                    npair++;
                }
            }
        }
    }

    public int get_npair() {
        return npair;
    }

    public Map<Integer, Integer> get_map() {
        Map<Integer, Integer> m = new HashMap<>();

        for (int j = 0; j < pair.size(); j++) {
            if (pair.get(j) != NIL && tag.get(j)) {
                m.put(j, pair.get(j));
            }
        }

        return m;
    }

    private boolean mf_breadth_first_search() {
        Queue<Integer> id12 = new LinkedList<>();

        for (int v : g1) {
            if (pair.get(v) == NIL) {
                dist.set(v, 0);
                id12.add(v);
            } else {
                dist.set(v, INF);
            }
        }

        dist.set(NIL, INF);

        while (!id12.isEmpty()) {
            int v = id12.poll();

            if (dist.get(v) < dist.get(NIL)) {
                for (int u : adj.get(v)) {
                    if (dist.get(pair.get(u)) == INF) {
                        dist.set(pair.get(u), dist.get(v) + 1);
                        id12.add(pair.get(u));
                    }
                }
            }
        }

        return dist.get(NIL) != INF;
    }

    private boolean mf_depth_first_search(int v) {
        if (v == NIL) {
            return true;
        } else {
            for (int u : adj.get(v)) {
                if (dist.get(pair.get(u)) == dist.get(v) + 1 && mf_depth_first_search(pair.get(u))) {
                    pair.set(u, v);
                    pair.set(v, u);
                    return true;
                }
            }

            dist.set(v, INF);
            return false;
        }
    }
}

class id3 {
    private static final int INF = Integer.MAX_VALUE;
    private int n;
    private List<Integer> depth;
    private List<Integer> parent;
    private List<List<Integer>> dist;

    public id3(List<List<Integer>> adj) {
        this.n = adj.size();
        this.depth = new ArrayList<>(Collections.nCopies(n, INF));
        this.parent = new ArrayList<>(n);
        this.dist = new ArrayList<>(n);

        for (int j = 0; j < n; j++) {
            parent.add(j);
            dist.add(new ArrayList<>(j));
        }

        Queue<Integer> id12 = new LinkedList<>();
        id12.add(0);
        depth.set(0, 0);
        parent.set(0, 0);

        while (!id12.isEmpty()) {
            int u = id12.poll();

            for (int j : adj.get(u)) {
                if (depth.get(u) + 1 < depth.get(j)) {
                    depth.set(j, depth.get(u) + 1);
                    parent.set(j, u);
                    id12.add(j);
                }
            }
        }
    }

    public int get_distance(int u, int v) {
        if (u == v) {
            return 0;
        } else if (u < v) {
            return get_distance(v, u);
        } else if (dist.get(u).get(v) == INF) {
            if (depth.get(u) < depth.get(v)) {
                dist.get(u).set(v, 1 + get_distance(u, parent.get(v)));
            } else if (depth.get(v) < depth.get(u)) {
                dist.get(u).set(v, 1 + get_distance(parent.get(u), v));
            } else {
                dist.get(u).set(v, 2 + get_distance(parent.get(u), parent.get(v)));
            }
        }

        return dist.get(u).get(v);
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
        if (parent[s] == s) {
            return s;
        } else {
            parent[s] = find(parent[s]);
            return parent[s];
        }
    }

    public void union(int i, int j) {
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

class id6 {
    private List<List<Integer>> adj;
    private List<Boolean> tag;

    public id6(List<List<Integer>> adj, List<Boolean> tag) {
        this.adj = adj;
        this.tag = tag;
    }

    public List<Integer> solve() {
        UnionFind uf = new UnionFind(adj.size());

        for (int u = 0; u < adj.size(); u++) {
            if (tag.get(u)) {
                for (int v : adj.get(u)) {
                    if (tag.get(v)) {
                        uf.union(u, v);
                    }
                }
            }
        }

        List<Integer> result = new ArrayList<>();
        for (int u = 0; u < adj.size(); u++) {
            if (tag.get(u)) {
                result.add(uf.find(u));
            }
        }

        return result;
    }
}

class id7 {
    private List<List<Integer>> adj;
    private List<Boolean> tag;
    private List<Integer> result;

    public id7(List<List<Integer>> adj, List<Boolean> tag) {
        this.adj = adj;
        this.tag = tag;
        this.result = new ArrayList<>();
    }

    public List<Integer> solve() {
        for (int u = 0; u < adj.size(); u++) {
            if (tag.get(u)) {
                dfs(u);
            }
        }

        return result;
    }

    private void dfs(int u) {
        result.add(u);

        for (int v : adj.get(u)) {
            if (tag.get(v)) {
                dfs(v);
            }
        }
    }
}

class id8 {
    private List<List<Integer>> adj;
    private List<Boolean> tag;
    private List<Integer> result;

    public id8(List<List<Integer>> adj, List<Boolean> tag) {
        this.adj = adj;
        this.tag = tag;
        this.result = new ArrayList<>();
    }

    public List<Integer> solve() {
        for (int u = 0; u < adj.size(); u++) {
            if (tag.get(u)) {
                dfs(u);
            }
        }

        return result;
    }

    private void dfs(int u) {
        result.add(u);

        for (int v : adj.get(u)) {
            if (tag.get(v)) {
                dfs(v);
            }
        }
    }
}

class id9 {
    private List<List<Integer>> adj;
    private List<Boolean> tag;
    private List<Integer> result;

    public id9(List<List<Integer>> adj, List<Boolean> tag) {
        this.adj = adj;
        this.tag = tag;
        this.result = new ArrayList<>();
    }

    public List<Integer> solve() {
        for (int u = 0; u < adj.size(); u++) {
            if (tag.get(u)) {
                dfs(u);
            }
        }

        return result;
    }

    private void dfs(int u) {
        result.add(u);

        for (int v : adj.get(u)) {
            if (tag.get(v)) {
                dfs(v);
            }
        }
    }
}

class id10 {
    private List<List<Integer>> adj;
    private List<Boolean> tag;
    private List<Integer> result;

    public id10(List<List<Integer>> adj, List<Boolean> tag) {
        this.adj = adj;
        this.tag = tag;
        this.result = new ArrayList<>();
    }

    public List<Integer> solve() {
        for (int u = 0; u < adj.size(); u++) {
            if (tag.get(u)) {
                dfs(u);
            }
        }

        return result;
    }

    private void dfs(int u) {
        result.add(u);

        for (int v : adj.get(u)) {
            if (tag.get(v)) {
                dfs(v);
            }
        }
    }
}

class id11 {
    private List<List<Integer>> adj;
    private List<Boolean> tag;
    private List<Integer> result;

    public id11(List<List<Integer>> adj, List<Boolean> tag) {
        this.adj = adj;
        this.tag = tag;
        this.result = new ArrayList<>();
    }

    public List<Integer> solve() {
        for (int u = 0; u < adj.size(); u++) {
            if (tag.get(u)) {
                dfs(u);
            }
        }

        return result;
    }

    private void dfs(int u) {
        result.add(u);

        for (int v : adj.get(u)) {
            if (tag.get(v)) {
                dfs(v);
            }
        }
    }
}

class id12 {
    private List<List<Integer>> adj;
    private List<Boolean> tag;
    private List<Integer> result;

    public id12(List<List<Integer>> adj, List<Boolean> tag) {
        this.adj = adj;
        this.tag = tag;
        this.result = new ArrayList<>();
    }

    public List<Integer> solve() {
        for (int u = 0; u < adj.size(); u++) {
            if (tag.get(u)) {
                dfs(u);
            }
        }

        return result;
    }

    private void dfs(int u) {
        result.add(u);

        for (int v : adj.get(u)) {
            if (tag.get(v)) {
                dfs(v);
            }
        }
    }
}

class id13 {
    private List<List<Integer>> adj;
    private List<Boolean> tag;
    private List<Integer> result;

    public id13(List<List<Integer>> adj, List<Boolean> tag) {
        this.adj = adj;
        this.tag = tag;
        this.result = new ArrayList<>();
    }

    public List<Integer> solve() {
        for (int u = 0; u < adj.size(); u++) {
            if (tag.get(u)) {
                dfs(u);
            }
        }

        return result;
    }

    private void dfs(int u) {
        result.add(u);

        for (int v : adj.get(u)) {
            if (tag.get(v)) {
                dfs(v);
            }
        }
    }
}

class id14 {
    private List<List<Integer>> adj;
    private List<Boolean> tag;
    private List<Integer> result;

    public id14(List<List<Integer>> adj, List<Boolean> tag) {
        this.adj = adj;
        this.tag = tag;
        this.result = new ArrayList<>();
    }

    public List<Integer> solve() {
        for (int u = 0; u < adj.size(); u++) {
            if (tag.get(u)) {
                dfs(u);
            }
        }

        return result;
    }

    private void dfs(int u) {
        result.add(u);

        for (int v : adj.get(u)) {
            if (tag.get(v)) {
                dfs(v);
            }
        }
    }
}

class id15 {
    private List<List<Integer>> adj;
    private List<Boolean> tag;
    private List<Integer> result;

    public id15(List<List<Integer>> adj, List<Boolean> tag) {
        this.adj = adj;
        this.tag = tag;
        this.result = new ArrayList<>();
    }

    public List<Integer> solve() {
        for (int u = 0; u < adj.size(); u++) {
            if (tag.get(u)) {
                dfs(u);
            }
        }

        return result;
    }

    private void dfs(int u) {
        result.add(u);

        for (int v : adj.get(u)) {
            if (tag.get(v)) {
                dfs(v);
            }
        }
    }
}

class id16 {
    private List<List<Integer>> adj;
    private List<Boolean> tag;
    private List<Integer> result;

    public id16(List<List<Integer>> adj, List<Boolean> tag) {
        this.adj = adj;
        this.tag = tag;
        this.result = new ArrayList<>();
    }

    public List<Integer> solve() {
        for (int u = 0; u < adj.size(); u++) {
            if (tag.get(u)) {
                dfs(u);
            }
        }

        return result;
    }

    private void dfs(int u) {
        result.add(u);

        for (int v : adj.get(u)) {
            if (tag.get(v)) {
                dfs(v);
            }
        }
    }
}

class id17 {
    private List<List<Integer>> adj;
    private List<Boolean> tag;
    private List<Integer> result;

    public id17(List<List<Integer>> adj, List<Boolean> tag) {
        this.adj = adj;
        this.tag = tag;
        this.result = new ArrayList<>();
    }

    public List<Integer> solve() {
        for (int u = 0; u < adj.size(); u++) {
            if (tag.get(u)) {
                dfs(u);
            }
        }

        return result;
    }

    private void dfs(int u) {
        result.add(u);

