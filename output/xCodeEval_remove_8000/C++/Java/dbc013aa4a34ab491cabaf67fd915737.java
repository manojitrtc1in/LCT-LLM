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

        System.out.println("\n" + msg + "\n\telapsed time: ");

        if (hrs > 0) System.out.print(hrs + " hrs, ");
        if (min > 0) System.out.print(min + " min, ");
        if (sec > 0) System.out.print(sec + " sec, ");
        System.out.println(mil + " mil-sec");
    }
}

class RandInt {
    private int m;
    private double f;

    public RandInt(int a, int b) {
        this.m = a;
        this.f = (double) (b - a) / Integer.MAX_VALUE;
    }

    public int nextInt() {
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

    public double nextDouble() {
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

    public void lazyUnion(int i, int j) {
        i = find(i);
        j = find(j);

        if (i != j) {
            if (rank[i] < rank[j]) {
                parent[i] = j;
            } else {
                parent[j] = i;
                rank[i] += (rank[i] == rank[j]) ? 1 : 0;
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
        this.dist = new ArrayList<>(Collections.nCopies(adj.size() + 1, INF));
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
    private int[] depth;
    private int[] parent;
    private int[][] dist;

    public id3(List<List<Integer>> adj) {
        this.n = adj.size();
        this.depth = new int[n];
        this.parent = new int[n];
        this.dist = new int[n][n];

        Queue<Integer> id12 = new LinkedList<>();
        id12.add(0);
        depth[0] = 0;
        parent[0] = 0;

        while (!id12.isEmpty()) {
            int u = id12.poll();

            for (int j : adj.get(u)) {
                if (depth[u] + 1 < depth[j]) {
                    depth[j] = depth[u] + 1;
                    parent[j] = u;
                    id12.add(j);
                }
            }
        }

        for (int j = 1; j < n; j++) {
            for (int k = 0; k < j; k++) {
                dist[j][k] = INF;
            }
        }
    }

    public int getDistance(int u, int v) {
        if (u == v) {
            return 0;
        } else if (u < v) {
            return getDistance(v, u);
        } else if (dist[u][v] == INF) {
            if (depth[u] < depth[v]) {
                dist[u][v] = 1 + getDistance(u, parent[v]);
            } else if (depth[v] < depth[u]) {
                dist[u][v] = 1 + getDistance(parent[u], v);
            } else {
                dist[u][v] = 2 + getDistance(parent[u], parent[v]);
            }
        }

        return dist[u][v];
    }
}

class id5 {
    public static List<Integer> findOccurrences(String str, String pat) {
        List<Integer> out = new ArrayList<>();
        Map<Character, List<Integer>> loc = new HashMap<>();

        for (int i = pat.length() - 1; i >= 0; i--) {
            char c = pat.charAt(i);
            if (!loc.containsKey(c)) {
                loc.put(c, new ArrayList<>());
            }
            loc.get(c).add(i);
        }

        List<Map<Integer, Integer>> cache = new ArrayList<>(pat.length());
        for (int i = 0; i < pat.length(); i++) {
            cache.add(new HashMap<>());
        }

        int i = 0;
        for (int j = 0; j < str.length(); i++, j++) {
            if (i == pat.length() || pat.charAt(i) != str.charAt(j)) {
                if (i == pat.length()) {
                    out.add(j - 1);
                }

                int first = i - 1;
                int last = i - 1;
                while (first >= 0 && pat.charAt(first) != str.charAt(j)) {
                    first--;
                    last--;
                }

                if (first >= 0) {
                    int k = cache.get(first).getOrDefault(last, -1);
                    if (k != -1) {
                        i = k;
                    }
                }
            }

            if (i < pat.length()) {
                int k = loc.get(pat.charAt(i)).stream().filter(x -> x <= j).findFirst().orElse(-1);
                cache.get(i).put(j, k);
            }
        }

        if (i == pat.length()) {
            out.add(str.length() - 1);
        }

        return out;
    }
}

class b494 {
    public static long solve() {
        Scanner scanner = new Scanner(System.in);
        String str = scanner.next();
        String pat = scanner.next();

        List<Integer> loc = id5.findOccurrences(str, pat);
        List<Boolean> tag = new ArrayList<>(str.length());
        for (int i = 0; i < str.length(); i++) {
            tag.add(false);
        }
        for (int i : loc) {
            tag.set(i, true);
        }

        List<Long> soln = new ArrayList<>(str.length());
        List<Long> cum = new ArrayList<>(str.length());

        soln.add(tag.get(0) ? 1L : 0L);
        cum.add(soln.get(0));

        long last = -1L;
        long carry = 0L;

        for (int i = 1; i < str.length(); i++) {
            if (!tag.get(i)) {
                soln.add(soln.get(i - 1) + (last < i ? carry : 0));
                soln.set(i, soln.get(i) % 1000000007L);
                cum.add((soln.get(i) + cum.get(i - 1)) % 1000000007L);
            } else {
                last = i;
                int j = 1 + i - pat.length();

                soln.add(soln.get(i - 1) + 1 + j);
                if (j > 0) {
                    soln.set(i, soln.get(i) + cum.get(j - 1));
                }
                soln.set(i, soln.get(i) % 1000000007L);
                cum.add((soln.get(i) + cum.get(i - 1)) % 1000000007L);

                carry = (soln.get(i) - soln.get(i - 1) + 1000000007L) % 1000000007L;
            }
        }

        return (soln.get(str.length() - 1) + 1000000007L) % 1000000007L;
    }
}

public class dbc013aa4a34ab491cabaf67fd915737xcodeeval_processed_8000.json {
    public static void main(String[] args) {
        System.out.println(b494.solve());
    }
}
