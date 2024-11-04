import java.util.*;

class MCMF_CS2 {
    private int n;
    private int m;
    private int[] cap;
    private Node[] nodes;
    private Node sentinelNode;
    private Arc[] arcs;
    private Arc sentinelArc;
    private BUCKET[] buckets;
    private BUCKET[] l_bucket;
    private long linf;
    private int time_for_price_in;
    private long epsilon;
    private long dn;
    private long price_min;
    private long mmc;
    private double f_scale;
    private double cut_off_factor;
    private double cut_on;
    private double cut_off;
    private long total_excess;
    private int flag_price;
    private int flag_updt;
    private int snc_max;
    private Arc d_arc;
    private Node d_node;
    private Node dummyNode;
    private Node dnode;
    private long n_rel;
    private long n_ref;
    private long n_src;
    private long n_push;
    private long n_relabel;
    private long n_discharge;
    private long n_refine;
    private long n_update;
    private long n_scan;
    private long n_prscan;
    private long n_prscan1;
    private long n_prscan2;
    private long n_bad_pricein;
    private long n_bad_relabel;
    private long n_prefine;
    private boolean no_zero_cycles;
    private boolean check_solution;
    private boolean comp_duals;
    private boolean cost_restart;
    private boolean print_ans;
    private long[] node_balance;
    private long node_min;
    private long node_max;
    private long[] arc_first;
    private long[] arc_tail;
    private long pos_current;
    private Arc arc_current;
    private Arc arc_new;
    private Arc arc_tmp;
    private long max_cost;
    private long total_p;
    private long total_n;
    private Node i_node;
    private Node j_node;

    public MCMF_CS2(int num_nodes, int num_arcs) {
        n = num_nodes;
        m = num_arcs;

        flag_price = 0;
        flag_updt = 0;
        n_push = 0;
        n_relabel = 0;
        n_discharge = 0;
        n_refine = 0;
        n_update = 0;
        n_scan = 0;
        n_prscan = 0;
        n_prscan1 = 0;
        n_prscan2 = 0;
        n_bad_pricein = 0;
        n_bad_relabel = 0;
        n_prefine = 0;
        no_zero_cycles = false;
        check_solution = false;
        comp_duals = false;
        cost_restart = false;
        print_ans = true;

        allocateArrays();
    }

    private void errEnd(int cc) {
        System.exit(cc);
    }

    private void allocateArrays() {
        nodes = new Node[n + 2];
        arcs = new Arc[2 * m + 1];
        cap = new int[2 * m];
        arc_tail = new long[2 * m];
        arc_first = new long[n + 2];

        for (int i = 0; i < nodes.length; i++) {
            nodes[i] = new Node();
        }

        if (nodes == null || arcs == null || arc_first == null || arc_tail == null) {
            errEnd(1);
        }

        pos_current = 0;
        arc_current = arcs;

        node_max = 0;
        node_min = n;
        max_cost = 0;
        total_p = 0;
        total_n = 0;
    }

    private void setArc(long tail_node_id, long head_node_id, long low_bound, long up_bound, long cost) {
        if (tail_node_id < 0 || tail_node_id > n || head_node_id < 0 || head_node_id > n) {
            errEnd(1);
        }
        if (up_bound < 0) {
            up_bound = Integer.MAX_VALUE;
        }
        if (low_bound < 0 || low_bound > up_bound) {
            errEnd(1);
        }

        arc_first[(int) (tail_node_id + 1)]++;
        arc_first[(int) (head_node_id + 1)]++;
        i_node = nodes[(int) tail_node_id];
        j_node = nodes[(int) head_node_id];

        arc_tail[(int) pos_current] = tail_node_id;
        arc_tail[(int) (pos_current + 1)] = head_node_id;
        arc_current.setHead(j_node);
        arc_current.setRezCapacity(up_bound - low_bound);
        cap[(int) pos_current] = (int) up_bound;
        arc_current.setCost(cost);
        arc_current.setSister(arc_current + 1);
        (arc_current + 1).setHead(nodes[(int) tail_node_id]);
        (arc_current + 1).setRezCapacity(0);
        cap[(int) (pos_current + 1)] = 0;
        (arc_current + 1).setCost(-cost);
        (arc_current + 1).setSister(arc_current);

        i_node.decExcess(low_bound);
        j_node.incExcess(low_bound);

        if (head_node_id < node_min) {
            node_min = head_node_id;
        }
        if (tail_node_id < node_min) {
            node_min = tail_node_id;
        }
        if (head_node_id > node_max) {
            node_max = head_node_id;
        }
        if (tail_node_id > node_max) {
            node_max = tail_node_id;
        }

        if (cost < 0) {
            cost = -cost;
        }
        if (cost > max_cost && up_bound > 0) {
            max_cost = cost;
        }

        arc_current += 2;
        pos_current += 2;
    }

    private void setSupplyDemandOfNode(long id, long excess) {
        if (id < 0 || id > n) {
            errEnd(1);
        }
        nodes[(int) id].setExcess(excess);
        if (excess > 0) {
            total_p += excess;
        }
        if (excess < 0) {
            total_n -= excess;
        }
    }

    private void preProcessing() {
        long i;
        long last, arc_num, arc_new_num;
        long tail_node_id;
        Node head_p;
        Arc arc_new, arc_tmp;
        long up_bound;
        long cost;

        long cap_out;
        long cap_in;

        if (Math.abs(total_p - total_n) > 0.5) {
            System.out.println(total_p + " " + total_n);
            errEnd(1);
        }

        nodes[node_min].setFirst(arcs);

        for (i = node_min + 1; i <= node_max + 1; i++) {
            arc_first[(int) i] += arc_first[(int) (i - 1)];
            nodes[(int) i].setFirst(arcs + arc_first[(int) i]);
        }

        for (i = node_min; i < node_max; i++) {
            last = nodes[(int) (i + 1)].getFirst() - arcs;

            for (arc_num = arc_first[(int) i]; arc_num < last; arc_num++) {
                tail_node_id = arc_tail[(int) arc_num];

                while (tail_node_id != i) {
                    arc_new_num = arc_first[(int) tail_node_id];
                    arc_current = arcs + arc_num;
                    arc_new = arcs + arc_new_num;

                    head_p = arc_new.getHead();
                    arc_new.setHead(arc_current.getHead());
                    arc_current.setHead(head_p);

                    up_bound = cap[(int) arc_new_num];
                    cap[(int) arc_new_num] = cap[(int) arc_num];
                    cap[(int) arc_num] = up_bound;

                    up_bound = arc_new.getRezCapacity();
                    arc_new.setRezCapacity(arc_current.getRezCapacity());
                    arc_current.setRezCapacity(up_bound);

                    cost = arc_new.getCost();
                    arc_new.setCost(arc_current.getCost());
                    arc_current.setCost(cost);

                    if (arc_new != arc_current.getSister()) {
                        arc_tmp = arc_new.getSister();
