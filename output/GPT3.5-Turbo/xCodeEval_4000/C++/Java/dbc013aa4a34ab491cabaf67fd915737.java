import java.util.*;

class HopcroftKarp {
    private List<List<Integer>> adj;
    private List<Boolean> tag;
    private int npair;
    private int NIL;
    private int INF;
    private List<Integer> g1;
    private List<Integer> dist;
    private List<Integer> pair;

    public HopcroftKarp(List<List<Integer>> adj, List<Boolean> tag) {
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
        String pat = scanner.next();

        List<Integer> loc = findSubstrMatch(str, pat);
        List<Boolean> tag = new ArrayList<>(Collections.nCopies(str.length(), false));
        for (int i : loc) {
            tag.set(i, true);
        }

        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < str.length(); i++) {
            adj.add(new ArrayList<>());
        }

        for (int i = 0; i < str.length(); i++) {
            if (!tag.get(i)) {
                for (int j = 1; j <= pat.length(); j++) {
                    if (i + j < str.length() && str.charAt(i + j) != pat.charAt(j - 1)) {
                        adj.get(i).add(i + j);
                    }
                }
            }
        }

        HopcroftKarp hopcroftKarp = new HopcroftKarp(adj, tag);
        System.out.println(hopcroftKarp.getNpair());
    }

    private static List<Integer> findSubstrMatch(String str, String pat) {
        List<Integer> out = new ArrayList<>();
        Map<Character, List<Integer>> loc = new HashMap<>();

        for (int i = pat.length() - 1; i < pat.length(); i--) {
            List<Integer> a = loc.get(pat.charAt(i));
            if (a == null) {
                a = new ArrayList<>();
                loc.put(pat.charAt(i), a);
            }
            a.add(i);
        }

        List<Map<Integer, Integer>> cache = new ArrayList<>();
        for (int i = 0; i < str.length(); i++) {
            cache.add(new HashMap<>());
        }

        int i = 0;
        for (int j = 0; j < str.length(); i++, j++) {
            if (i == pat.length()) {
                out.add(j - 1);
                i = cache.get(i - 1).get(j);
            }

            int first = i;
            while (i < pat.length() && j < str.length() && str.charAt(j) == pat.charAt(i)) {
                i++;
                j++;
            }

            if (i == pat.length()) {
                out.add(j - 1);
                i = cache.get(first - 1).get(j);
            } else {
                int last = cache.get(i).get(j);
                if (last != -1) {
                    i = last;
                } else {
                    i = cache.get(first).get(j);
                }
            }
        }

        return out;
    }
}
