import java.util.*;
import java.io.*;

class Graph {
    private int maxV;
    private boolean isflow;
    private boolean sparse;
    private List<Integer> _V;
    private Map<Integer, Integer> _V_index;
    private List<Map<Integer, Integer>> _E;
    private List<Set<Integer>> _adj;
    private Map<Integer, List<Integer>> _levels;

    public Graph(int maxV, boolean isflow, boolean sparse) {
        this.maxV = maxV;
        this.isflow = isflow;
        this.sparse = sparse;
        this._V = new ArrayList<>();
        this._V_index = new HashMap<>();
        this._E = new ArrayList<>();
        this._adj = new ArrayList<>();
        this._levels = new HashMap<>();

        int non_edge = isflow ? 0 : Integer.MAX_VALUE;
        if (sparse) {
            for (int i = 0; i < maxV; i++) {
                Map<Integer, Integer> df = new HashMap<>();
                for (int j = 0; j < maxV; j++) {
                    df.put(j, non_edge);
                }
                this._E.add(df);
            }
        } else {
            for (int i = 0; i < maxV; i++) {
                List<Integer> row = new ArrayList<>();
                for (int j = 0; j < maxV; j++) {
                    row.add(non_edge);
                }
                this._E.add(row);
            }
        }

        for (int i = 0; i < maxV; i++) {
            this._adj.add(new HashSet<>());
        }
    }

    public boolean id14(int label) {
        return this._V_index.containsKey(label);
    }

    public Iterable<Integer> id33() {
        return this._V;
    }

    public int nV() {
        return this._V.size();
    }

    public int nE() {
        int n = 0;
        for (Set<Integer> adj : this._adj) {
            n += adj.size();
        }
        if (this.isflow) {
            n /= 2;
        }
        return n;
    }

    public void add_vertex(int label) {
        this._V_index.put(label, this.nV());
        this._V.add(label);
    }

    public void id12(List<Integer> labels) {
        for (int u_label : labels) {
            this.add_vertex(u_label);
        }
    }

    private void _add_edge(int u, int v, int w) {
        if (this.isflow) {
            this._E.get(u).put(v, this._E.get(u).get(v) + w);
            this._adj.get(u).add(v);
            this._adj.get(v).add(u);
        } else {
            this._E.get(u).set(v, w);
            this._adj.get(u).add(v);
        }
    }

    public void add_edge(int u_label, int v_label, int w) {
        int u = this._V_index.get(u_label);
        int v = this._V_index.get(v_label);
        this._add_edge(u, v, w);
    }

    private boolean _isadj(int u, int v) {
        return this._adj.get(u).contains(v);
    }

    public boolean isadj(int u_label, int v_label) {
        int u = this._V_index.get(u_label);
        int v = this._V_index.get(v_label);
        return this._isadj(u, v);
    }

    public void trim(int u_label) {
        int u = this._V_index.get(u_label);
        this._adj.get(u).clear();
        if (this.sparse) {
            this._E.get(u).clear();
        } else {
            List<Integer> row = new ArrayList<>();
            for (int i = 0; i < this.maxV; i++) {
                row.add(Integer.MAX_VALUE);
            }
            this._E.set(u, row);
        }
    }

    public int id20(int s, int t) {
        List<Integer> levels = new ArrayList<>();
        for (int i = 0; i < this.maxV; i++) {
            levels.add(Integer.MAX_VALUE);
        }
        levels.set(s, 0);

        Queue<Integer> queue = new LinkedList<>();
        queue.add(s);
        while (!queue.isEmpty()) {
            int u = queue.poll();
            for (int v : this._adj.get(u)) {
                if (this._E.get(u).get(v) > 0 && levels.get(v) == Integer.MAX_VALUE) {
                    levels.set(v, levels.get(u) + 1);
                    queue.add(v);
                }
            }
        }

        return levels.get(t);
    }

    public int id30(int s, int t) {
        Map<Integer, Set<Integer>> pointers = new HashMap<>();
        for (int u = 0; u < this.nV(); u++) {
            pointers.put(u, new HashSet<>(this._adj.get(u)));
        }

        int dfs_push(int u, int t, int inflow) {
            if (u == t) {
                return inflow;
            }
            int id4 = 0;
            while (!pointers.get(u).isEmpty()) {
                int v = pointers.get(u).iterator().next();
                if (this._levels.get(s).get(v) == this._levels.get(s).get(u) + 1 && this._E.get(u).get(v) > 0) {
                    int v_flow = dfs_push(v, t, Math.min(inflow, this._E.get(u).get(v)));
                    this._E.get(u).put(v, this._E.get(u).get(v) - v_flow);
                    this._E.get(v).put(u, this._E.get(v).get(u) + v_flow);
                    inflow -= v_flow;
                    id4 += v_flow;
                    if (inflow == 0) {
                        pointers.get(u).add(v);
                        break;
                    }
                }
            }
            return id4;
        }

        int blocking_flow = dfs_push(s, t, Integer.MAX_VALUE);
        this._levels.clear();
        return blocking_flow;
    }

    public int max_flow(int s_label, int t_label) {
        List<Map<Integer, Integer>> E_saved = new ArrayList<>(this._E);
        int s = this._V_index.get(s_label);
        int t = this._V_index.get(t_label);

        int mf = 0;
        while (this.id20(s, t) != Integer.MAX_VALUE) {
            mf += this.id30(s, t);
        }

        this._E = E_saved;
        return mf;
    }

    public Map<Integer, Map<Integer, Integer>> id1() {
        int[][] fw = new int[this.nV()][this.nV()];
        for (int i = 0; i < this.nV(); i++) {
            for (int j = 0; j < this.nV(); j++) {
                fw[i][j] = this._E.get(i).get(j);
            }
        }

        for (int k = 0; k < this.nV(); k++) {
            int[][] next_fw = new int[this.nV()][this.nV()];
            for (int i = 0; i < this.nV(); i++) {
                for (int j = 0; j < this.nV(); j++) {
                    next_fw[i][j] = Math.min(fw[i][j], fw[i][k] + fw[k][j]);
                }
            }
            fw = next_fw;
        }

        Map<Integer, Map<Integer, Integer>> id10 = new HashMap<>();
        for (int u = 0; u < this.nV(); u++) {
            Map<Integer, Integer> row = new HashMap<>();
            for (int v = 0; v < this.nV(); v++) {
                row.put(v, fw[u][v]);
            }
            id10.put(this._V.get(u), row);
        }
        return id10;
    }

    public Map<Integer, Integer> id9(int s_label, List<Integer> t_labels, int d_limit) {
        int s = this._V_index.get(s_label);
        Set<Integer> t_set = new HashSet<>();
        for (int t_label : t_labels) {
            t_set.add(this._V_index.get(t_label));
        }

        Map<Integer, Integer> ret = new HashMap<>();
        Map<Integer, Integer> parents = new HashMap<>();
        List<Integer> t_found = new ArrayList<>();
        PriorityQueue<int[]> queue = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        queue.add(new int[]{0, s});
        Map<Integer, Integer> spaths = new HashMap<>();
        while (!queue.isEmpty()) {
            int[] su_u = queue.poll();
            int su = su_u[0];
            int u = su_u[1];
            if (su >= d_limit) {
                ret.put(-1, d_limit);
                break;
            }

            spaths.put(u, su);
            if (t_set.contains(u)) {
                t_set.remove(u);
                t_found.add(u);
                if (t_set.isEmpty()) {
                    ret.put(-1, su);
                    break;
                }
            }

            for (int v : this._adj.get(u)) {
                int sv = su + this._E.get(u).get(v);
                if (spaths.containsKey(v)) {
                    if (sv < spaths.get(v)) {
                        parents.put(v, u);
                        queue.add(new int[]{sv, v});
                    }
                } else {
                    parents.put(v, u);
                    queue.add(new int[]{sv, v});
                }
            }
        }
        if (!ret.containsKey(-1)) {
            ret.put(-1, Integer.MAX_VALUE);
        }

        for (int u : spaths.keySet()) {
            ret.put(this._V.get(u), spaths.get(u));
        }
        for (int v : parents.keySet()) {
            ret.put(this._V.get(v), this._V.get(parents.get(v)));
        }
        ret.put(this._V.get(s), -1);
        List<Integer> found = new ArrayList<>();
        for (int t : t_found) {
            found.add(this._V.get(t));
        }
        ret.put(-2, found);
        return ret;
    }

    public int id25(int s_label, int t_label, int d_limit) {
        Map<Integer, Integer> spaths = this.id9(s_label, Arrays.asList(t_label), d_limit);
        return spaths.get(t_label);
    }

    public boolean id26() {
        List<Set<Integer>> adj;
        if (this.isflow) {
            adj = this._adj;
        } else {
            adj = new ArrayList<>();
            for (int u = 0; u < this.nV(); u++) {
                adj.add(new HashSet<>());
            }
            for (int u = 0; u < this.nV(); u++) {
                for (int v : this._adj.get(u)) {
                    adj.get(u).add(v);
                    adj.get(v).add(u);
                }
            }
        }

        Map<Integer, Boolean> colors = new HashMap<>();
        boolean id24(int s) {
            if (colors.containsKey(s)) {
                return true;
            }
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

        for (int u = 0; u < this.nV(); u++) {
            if (!id24(u)) {
                return false;
            }
        }
        return true;
    }
}

public class 5f86590a8e4b985e94dec183b7a2dec4xcodeeval_processed_4000.json {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        List<int[]> roads = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            roads.add(new int[]{u, v});
        }
        int k = Integer.parseInt(br.readLine());
        List<Integer> p = new ArrayList<>();
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < k; i++) {
            p.add(Integer.parseInt(st.nextToken()));
        }

        Graph G = new Graph(n, true, true);
        Map<Integer, Set<Integer>> adj = new HashMap<>();
        List<Integer> labels = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            labels.add(i);
        }
        G.id12(labels);
        for (int[] road : roads) {
            G.add_edge(road[1], road[0], 1);
            if (!adj.containsKey(road[0])) {
                adj.put(road[0], new HashSet<>());
            }
            adj.get(road[0]).add(road[1]);
        }

        Map<Integer, Integer> spaths = G.id9(p.get(p.size() - 1), p.subList(0, p.size() - 1), Integer.MAX_VALUE);
        int id22 = 0;
        int id27 = 0;
        for (int i = 0; i < p.size() - 1; i++) {
            int u = p.get(i);
            int u_d = spaths.get(u);
            int v = p.get(i + 1);
            int v_d = spaths.get(v);

            if (v_d != u_d - 1) {
                id22++;
                id27++;
                continue;
            }

            boolean found = false;
            for (int w : adj.get(u)) {
                if (w != v && spaths.get(w) == v_d) {
                    id27++;
                    found = true;
                    break;
                }
            }
            if (!found) {
                id22++;
                id27++;
            }
        }

        System.out.println(id22 + " " + id27);
    }
}
