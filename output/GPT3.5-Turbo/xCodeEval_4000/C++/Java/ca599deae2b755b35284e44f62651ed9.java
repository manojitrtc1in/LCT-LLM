import java.util.*;

class HopcroftKarp {
    private final List<List<Integer>> adj;
    private final List<Boolean> tag;
    private final int npair;
    private final int NIL;
    private final int INF;
    private final List<Integer> g1;
    private final List<Integer> dist;
    private final List<Integer> pair;

    public HopcroftKarp(List<List<Integer>> adj, List<Boolean> tag) {
        this.adj = adj;
        this.tag = tag;
        this.npair = 0;
        this.NIL = adj.size();
        this.INF = adj.size() + 1;
        this.dist = new ArrayList<>(Collections.nCopies(adj.size() + 1, INF));
        this.pair = new ArrayList<>(Collections.nCopies(adj.size(), NIL));
        this.g1 = new ArrayList<>();

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

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String str = scanner.next();
        int n = scanner.nextInt();

        List<List<Integer>> soln = new ArrayList<>();
        soln.add(new ArrayList<>());
        soln.add(new ArrayList<>());

        if (str.charAt(str.length() - 1) == 'F') {
            for (int j = 0; j < n + 1; j++) {
                soln.get(0).add(j % 2 == 1 ? 0 : 1);
            }
        } else {
            for (int j = 0; j < n + 1; j++) {
                soln.get(0).add(j % 2 == 1 ? 1 : 0);
            }
        }

        soln.get(1).addAll(soln.get(0));

        for (int i = str.length() - 2; i >= 0; i--) {
            List<List<Integer>> xsoln = new ArrayList<>();
            xsoln.addAll(soln);
            soln.get(0).clear();
            soln.get(1).clear();
            if (str.charAt(i) == 'F') {
                soln.get(0).add(1 + xsoln.get(0).get(0));
                soln.get(1).add(1 + xsoln.get(1).get(0));
                for (int j = 1; j < n + 1; j++) {
                    soln.get(0).add(Math.max(1 + xsoln.get(0).get(j), -xsoln.get(1).get(j - 1)));
                    soln.get(1).add(Math.min(1 + xsoln.get(1).get(j), -xsoln.get(0).get(j - 1)));
                }
            } else {
                soln.get(0).add(-xsoln.get(1).get(0));
                soln.get(1).add(-xsoln.get(0).get(0));
                for (int j = 1; j < n + 1; j++) {
                    soln.get(0).add(Math.max(-xsoln.get(1).get(j), 1 + xsoln.get(0).get(j - 1)));
                    soln.get(1).add(Math.min(-xsoln.get(0).get(j), 1 + xsoln.get(1).get(j - 1)));
                }
            }
        }

        System.out.println(Math.max(soln.get(0).get(n), -soln.get(1).get(n)));
    }
}
