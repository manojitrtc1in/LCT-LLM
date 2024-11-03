import java.util.*;

class ScopeTimer {
    private final long tic;
    private final String msg;

    public ScopeTimer(String msg) {
        this.tic = System.currentTimeMillis();
        this.msg = msg;
    }

    @Override
    protected void finalize() throws Throwable {
        long toc = System.currentTimeMillis();
        long dt = toc - tic;

        long mil = dt % 1000L;
        long sec = (dt / 1000L) % 60L;
        long min = (dt / 60000L) % 60L;
        long hrs = (dt / 3600000L);

        System.out.println("\n" + msg + "\n\telapsed time: " + hrs + " hrs, " + min + " min, " + sec + " sec, " + mil + " mil-sec");
    }
}

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
        this.dist = new ArrayList<>(Collections.nCopies(adj.size(), INF));
        this.pair = new ArrayList<>(Collections.nCopies(adj.size(), NIL));
        this.g1 = new ArrayList<>();

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

    private boolean mf_breadth_first_search() {
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

class Main {
    private static int b494() {
        Scanner scanner = new Scanner(System.in);
        String str = scanner.next();
        String pat = scanner.next();

        List<Integer> loc = findSubstrMatch(str, pat);

        List<Boolean> tag = new ArrayList<>(Collections.nCopies(str.length(), false));
        for (int i : loc) {
            tag.set(i, true);
        }

        List<Long> soln = new ArrayList<>(Collections.nCopies(str.length(), 0L));
        List<Long> cum = new ArrayList<>(Collections.nCopies(str.length(), 0L));

        soln.set(0, tag.get(0) ? 1L : 0L);
        cum.set(0, soln.get(0));

        final long mod = 1000000000L + 7L;
        int last = -1;
        long carry = 0;

        for (int i = 1; i < str.length(); i++) {
            if (!tag.get(i)) {
                soln.set(i, soln.get(i - 1) + (last < i ? carry : 0));
                soln.set(i, soln.get(i) % mod);
                cum.set(i, (soln.get(i) + cum.get(i - 1)) % mod);
            } else {
                last = i;
                int j = 1 + i - pat.length();

                soln.set(i, soln.get(i - 1) + 1 + j);

                if (0 < j) {
                    soln.set(i, soln.get(i) + cum.get(j - 1));
                }

                soln.set(i, soln.get(i) % mod);
                cum.set(i, (soln.get(i) + cum.get(i - 1)) % mod);

                carry = (soln.get(i) - soln.get(i - 1) + mod) % mod;
            }
        }

        return (int) ((soln.get(soln.size() - 1) + mod) % mod);
    }

    public static void main(String[] args) {
        System.out.println(b494());
    }

    private static List<Integer> findSubstrMatch(String str, String pat) {
        List<Integer> out = new ArrayList<>();
        Map<Character, List<Integer>> loc = new HashMap<>();

        for (int i = pat.length() - 1; i < pat.length(); i--) {
            char chr = pat.charAt(i);
            if (!loc.containsKey(chr)) {
                loc.put(chr, new ArrayList<>());
            }
            loc.get(chr).add(i);
        }

        List<Map<Long, Long>> cache = new ArrayList<>(pat.length());
        for (int i = 0; i < pat.length(); i++) {
            cache.add(new HashMap<>());
        }

        int i = 0;
        for (int j = 0; j < str.length(); i++, j++) {
            if (i == pat.length()) {
                out.add(j - 1);
                i = 0;
            }

            if (!loc.containsKey(str.charAt(j))) {
                continue;
            }

            List<Integer> a = loc.get(str.charAt(j));
            List<Integer> b = new ArrayList<>(a);

            for (int k = 0; k < a.size(); k++) {
                int idx = a.get(k);
                if (idx <= i) {
                    b.remove((Integer) idx);
                }
            }

            if (b.isEmpty()) {
                continue;
            }

            int first = b.get(0);
            if (i < first) {
                continue;
            }

            if (i > first) {
                out.add(j - 1);
                i = 0;
            }

            if (i == first) {
                Map<Long, Long> rest = cache.get(i);
                String aStr = str.charAt(i) + rest.getOrDefault(j + 1L, "");
                String bStr = str.charAt(i) + rest.getOrDefault(j + 1L, "");

                for (int k = 0; k < aStr.length(); k++) {
                    if (aStr.startsWith(pat)) {
                        aStr = aStr.substring(1);
                    }
                    if (bStr.startsWith(pat)) {
                        bStr = bStr.substring(1);
                    }
                }

                if (aStr.length() < bStr.length()) {
                    String temp = aStr;
                    aStr = bStr;
                    bStr = temp;
                }

                String restStr = revmatch(i + 1, j + 1, str, pat, cache);
                if (restStr.length() < aStr.length()) {
                    aStr = restStr;
                }

                if (restStr.length() < bStr.length()) {
                    bStr = restStr;
                }

                if (aStr.startsWith(pat)) {
                    aStr = "";
                }
                if (bStr.startsWith(pat)) {
                    bStr = "";
                }

                if (aStr.length() < bStr.length()) {
                    String temp = aStr;
                    aStr = bStr;
                    bStr = temp;
                }

                if (aStr.length() < bStr.length()) {
                    out.add(j);
                }
            }
        }

        if (i == pat.length()) {
            out.add(str.length() - 1);
        }

        return out;
    }
}
