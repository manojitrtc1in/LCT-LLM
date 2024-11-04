import java.util.*;

class MCMF_CS2 {
    // Define constants
    static final long MAX_64 = 0x7fffffffffffffffL;
    static final long MAX_32 = 0x7fffffff;
    static final double UPDT_FREQ = 0.4;
    static final int UPDT_FREQ_S = 30;
    static final double SCALE_DEFAULT = 12.0;
    static final int MAXLINE = 100;
    static final int ARC_FIELDS = 5;
    static final int NODE_FIELDS = 2;
    static final int P_FIELDS = 3;
    static final String PROBLEM_TYPE = "min";
    
    // Define classes for NODE, ARC, and BUCKET
    class ARC {
        long _rez_capacity;
        long _cost;
        NODE _head;
        ARC _sister;

        ARC() {}

        void set_rez_capacity(long rez_capacity) { _rez_capacity = rez_capacity; }
        void dec_rez_capacity(long delta) { _rez_capacity -= delta; }
        void inc_rez_capacity(long delta) { _rez_capacity += delta; }
        void set_cost(long cost) { _cost = cost; }
        void multiply_cost(long mult) { _cost *= mult; }
        void set_head(NODE head) { _head = head; }
        void set_sister(ARC sister) { _sister = sister; }
        long rez_capacity() { return _rez_capacity; }
        long cost() { return _cost; }
        NODE head() { return _head; }
        ARC sister() { return _sister; }
    }

    class NODE {
        long _excess;
        long _price;
        ARC _first;
        ARC _current;
        ARC _suspended;
        NODE _q_next;
        NODE _b_next;
        NODE _b_prev;
        long _rank;
        long _inp;

        NODE() {}

        void set_excess(long excess) { _excess = excess; }
        void dec_excess(long delta) { _excess -= delta; }
        void inc_excess(long delta) { _excess += delta; }
        void set_price(long price) { _price = price; }
        void dec_price(long delta) { _price -= delta; }
        void set_first(ARC first) { _first = first; }
        void set_current(ARC current) { _current = current; }
        void inc_current() { _current++; }
        void set_suspended(ARC suspended) { _suspended = suspended; }
        void set_q_next(NODE q_next) { _q_next = q_next; }
        void set_b_next(NODE b_next) { _b_next = b_next; }
        void set_b_prev(NODE b_prev) { _b_prev = b_prev; }
        void set_rank(long rank) { _rank = rank; }
        void set_inp(long inp) { _inp = inp; }
        long excess() { return _excess; }
        long price() { return _price; }
        ARC first() { return _first; }
        void dec_first() { _first--; }
        void inc_first() { _first++; }
        ARC current() { return _current; }
        ARC suspended() { return _suspended; }
        NODE q_next() { return _q_next; }
        NODE b_next() { return _b_next; }
        NODE b_prev() { return _b_prev; }
        long rank() { return _rank; }
        long inp() { return _inp; }
    }

    class BUCKET {
        NODE _p_first;

        BUCKET(NODE p_first) { _p_first = p_first; }
        BUCKET() {}
        void set_p_first(NODE p_first) { _p_first = p_first; }
        NODE p_first() { return _p_first; }
    }

    // Class variables
    long _n;
    long _m;
    long[] _cap;
    NODE _nodes;
    NODE _sentinel_node;
    NODE _excq_first;
    NODE _excq_last;
    ARC _arcs;
    ARC _sentinel_arc;
    BUCKET[] _buckets;
    BUCKET _l_bucket;
    long _linf;
    long _epsilon;
    long _dn;
    long _price_min;
    long _mmc;
    double _f_scale;
    double _cut_off_factor;
    double _cut_on;
    double _cut_off;
    long _total_excess;
    int _flag_price;
    int _flag_updt;
    long _node_min;
    long _node_max;
    long _pos_current;
    ARC _arc_current;
    ARC _arc_new;
    ARC _arc_tmp;
    long _max_cost;
    long _total_p;
    long _total_n;
    NODE _d_node;
    NODE _dummy_node;

    // Constructor
    MCMF_CS2(long num_nodes, long num_arcs) {
        _n = num_nodes;
        _m = num_arcs;
        allocate_arrays();
    }

    void allocate_arrays() {
        _nodes = new NODE[(int)(_n + 2)];
        _arcs = new ARC[(int)(2 * _m + 1)];
        _cap = new long[(int)(2 * _m)];
        // Initialize nodes
        for (int i = 0; i <= _n; i++) {
            _nodes[i].set_excess(0);
        }
        // Check for allocation failure
        if (_nodes == null || _arcs == null || _cap == null) {
            System.exit(1);
        }
        _pos_current = 0;
        _arc_current = _arcs[0];
        _node_max = 0;
        _node_min = _n;
        _max_cost = 0;
        _total_p = _total_n = 0;
    }

    void set_arc(long tail_node_id, long head_node_id, long low_bound, long up_bound, long cost) {
        // Implementation of set_arc
    }

    void set_supply_demand_of_node(long id, long excess) {
        // Implementation of set_supply_demand_of_node
    }

    void run_cs2() {
        // Implementation of run_cs2
    }

    // Other methods...

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int[][] grid = new int[n][m];
        List<Integer> a = new ArrayList<>();
        List<Integer> b = new ArrayList<>();
        List<Integer> c = new ArrayList<>();

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                grid[i][j] = scanner.nextInt();

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if ((i + j) % 2 == 1) {
                    if (i > 0) {
                        a.add(f(i, j));
                        b.add(f(i - 1, j));
                        c.add(grid[i][j] != grid[i - 1][j] ? 1 : 0);
                    }
                    if (j > 0) {
                        a.add(f(i, j));
                        b.add(f(i, j - 1));
                        c.add(grid[i][j] != grid[i][j - 1] ? 1 : 0);
                    }
                    if (i + 1 < n) {
                        a.add(f(i, j));
                        b.add(f(i + 1, j));
                        c.add(grid[i][j] != grid[i + 1][j] ? 1 : 0);
                    }
                    if (j + 1 < m) {
                        a.add(f(i, j));
                        b.add(f(i, j + 1));
                        c.add(grid[i][j] != grid[i][j + 1] ? 1 : 0);
                    }
                }

        int num_nodes = n * m * 4;
        int num_arcs = a.size();
        MCMF_CS2 my_mcmf_problem = new MCMF_CS2(num_nodes, num_arcs);
