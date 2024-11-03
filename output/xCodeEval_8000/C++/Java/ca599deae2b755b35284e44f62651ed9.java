import java.util.*;

class HopcroftKarp {
    private final List<List<Integer>> adj;
    private final List<Boolean> tag;
    private int npair;
    private final int NIL;
    private final int INF;
    private List<Integer> g1;
    private List<Integer> dist;
    private List<Integer> pair;

    public HopcroftKarp(List<List<Integer>> adj, List<Boolean> tag) {
        this.adj = adj;
        this.tag = tag;
        npair = 0;
        NIL = adj.size();
        INF = adj.size() + 1;
        dist = new ArrayList<>(Collections.nCopies(adj.size() + 1, INF));
        pair = new ArrayList<>(Collections.nCopies(adj.size(), NIL));

        g1 = new ArrayList<>();
        for (int j = 0; j < tag.size(); j++) {
            if (tag.get(j)) {
                g1.add(j);
            }
        }

        while (mfBreadthFirstSearch()) {
            for (int v : g1) {
                if (pair.get(v) == NIL && mfDepthFirstSearch(v)) {
                    npair++;
                }
            }
        }
    }

    public int getNpair() {
        return npair;
    }

    public Map<Integer, Integer> getMap() {
        Map<Integer, Integer> m = new HashMap<>();
        for (int j = 0; j < pair.size(); j++) {
            if (pair.get(j) != NIL && tag.get(j)) {
                m.put(j, pair.get(j));
            }
        }
        return m;
    }

    private boolean mfBreadthFirstSearch() {
        Queue<Integer> bfsQueue = new LinkedList<>();

        for (int v : g1) {
            if (pair.get(v) == NIL) {
                dist.set(v, 0);
                bfsQueue.add(v);
            } else {
                dist.set(v, INF);
            }
        }
        dist.set(NIL, INF);

        while (!bfsQueue.isEmpty()) {
            int v = bfsQueue.poll();
            if (dist.get(v) < dist.get(NIL)) {
                for (int u : adj.get(v)) {
                    if (dist.get(pair.get(u)) == INF) {
                        dist.set(pair.get(u), dist.get(v) + 1);
                        bfsQueue.add(pair.get(u));
                    }
                }
            }
        }

        return dist.get(NIL) != INF;
    }

    private boolean mfDepthFirstSearch(int v) {
        if (v == NIL) {
            return true;
        } else {
            for (int u : adj.get(v)) {
                if (dist.get(pair.get(u)) == dist.get(v) + 1 && mfDepthFirstSearch(pair.get(u))) {
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

class AllPairsTreeShortestPath {
    private static final int INF = Integer.MAX_VALUE;
    private final int n;
    private final List<Integer> depth;
    private final List<Integer> parent;
    private final List<List<Integer>> dist;

    public AllPairsTreeShortestPath(List<List<Integer>> adj) {
        n = adj.size();
        depth = new ArrayList<>(Collections.nCopies(n, INF));
        parent = new ArrayList<>(n);
        dist = new ArrayList<>(n);

        for (int j = 0; j < n; j++) {
            parent.add(j);
            dist.add(new ArrayList<>(j));
        }

        Queue<Integer> bfsQueue = new LinkedList<>();
        bfsQueue.add(0);
        depth.set(0, 0);
        parent.set(0, 0);

        while (!bfsQueue.isEmpty()) {
            int u = bfsQueue.poll();
            for (int j : adj.get(u)) {
                if (depth.get(u) + 1 < depth.get(j)) {
                    depth.set(j, depth.get(u) + 1);
                    parent.set(j, u);
                    bfsQueue.add(j);
                }
            }
        }
    }

    public int getDistance(int u, int v) {
        if (u == v) {
            return 0;
        } else if (u < v) {
            return getDistance(v, u);
        } else if (dist.get(u).get(v) == INF) {
            if (depth.get(u) < depth.get(v)) {
                dist.get(u).set(v, 1 + getDistance(u, parent.get(v)));
            } else if (depth.get(v) < depth.get(u)) {
                dist.get(u).set(v, 1 + getDistance(parent.get(u), v));
            } else {
                dist.get(u).set(v, 2 + getDistance(parent.get(u), parent.get(v)));
            }
        }
        return dist.get(u).get(v);
    }
}

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String str = scanner.next();
        int n = scanner.nextInt();

        int[][] soln = new int[2][n + 1];
        int[][] xsoln = new int[2][n + 1];

        if (str.charAt(str.length() - 1) == 'F') {
            for (int j = 0; j < n + 1; j++) {
                soln[0][j] = j % 2 == 1 ? 0 : 1;
            }
        } else {
            for (int j = 0; j < n + 1; j++) {
                soln[0][j] = j % 2 == 1 ? 1 : 0;
            }
        }

        System.arraycopy(soln[0], 0, soln[1], 0, n + 1);

        for (int i = str.length() - 2; i >= 0; i--) {
            int[][] temp = soln;
            soln = xsoln;
            xsoln = temp;

            if (str.charAt(i) == 'F') {
                soln[0][0] = 1 + xsoln[0][0];
                soln[1][0] = 1 + xsoln[1][0];

                for (int j = 1; j < n + 1; j++) {
                    soln[0][j] = Math.max(1 + xsoln[0][j], -xsoln[1][j - 1]);
                    soln[1][j] = Math.min(1 + xsoln[1][j], -xsoln[0][j - 1]);
                }
            } else {
                soln[0][0] = -xsoln[1][0];
                soln[1][0] = -xsoln[0][0];

                for (int j = 1; j < n + 1; j++) {
                    soln[0][j] = Math.max(-xsoln[1][j], 1 + xsoln[0][j - 1]);
                    soln[1][j] = Math.min(-xsoln[0][j], 1 + xsoln[1][j - 1]);
                }
            }
        }

        System.out.println(Math.max(soln[0][n], -soln[1][n]));
    }
}
