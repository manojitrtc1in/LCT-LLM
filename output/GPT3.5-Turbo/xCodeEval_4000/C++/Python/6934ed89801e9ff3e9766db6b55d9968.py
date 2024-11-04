import sys

class MCMF_CS2:
    def __init__(self, num_nodes, num_arcs):
        self.n = num_nodes
        self.m = num_arcs
        self.cap = [0] * (2 * self.m)
        self.nodes = [None] * (self.n + 2)
        self.sentinel_node = None
        self.sentinel_arc = None
        self.arcs = [None] * (2 * self.m + 1)
        self.buckets = None
        self.l_bucket = None
        self.linf = 0
        self.time_for_price_in = 0
        self.epsilon = 0
        self.dn = 0
        self.price_min = 0
        self.mmc = 0
        self.f_scale = 0
        self.cut_off_factor = 0
        self.cut_on = 0
        self.cut_off = 0
        self.total_excess = 0
        self.flag_price = 0
        self.flag_updt = 0
        self.snc_max = 0
        self.d_arc = None
        self.d_node = None
        self.dummy_node = None
        self.n_rel = 0
        self.n_ref = 0
        self.n_src = 0
        self.n_push = 0
        self.n_relabel = 0
        self.n_discharge = 0
        self.n_refine = 0
        self.n_update = 0
        self.n_scan = 0
        self.n_prscan = 0
        self.n_prscan1 = 0
        self.n_prscan2 = 0
        self.n_bad_pricein = 0
        self.n_bad_relabel = 0
        self.n_prefine = 0
        self.no_zero_cycles = False
        self.check_solution = False
        self.comp_duals = False
        self.cost_restart = False
        self.print_ans = True
        self.node_balance = None
        self.node_min = 0
        self.node_max = 0
        self.arc_first = None
        self.arc_tail = None
        self.pos_current = 0
        self.arc_current = None
        self.arc_new = None
        self.arc_tmp = None
        self.max_cost = 0
        self.total_p = 0
        self.total_n = 0
        self.i_node = None
        self.j_node = None

    class NODE:
        def __init__(self):
            self.excess = 0
            self.price = 0
            self.first = None
            self.current = None
            self.suspended = None
            self.q_next = None
            self.b_next = None
            self.b_prev = None
            self.rank = 0
            self.inp = 0

    class ARC:
        def __init__(self):
            self.rez_capacity = 0
            self.cost = 0
            self.head = None
            self.sister = None

    class BUCKET:
        def __init__(self):
            self.p_first = None

    def err_end(self, cc):
        sys.exit(cc)

    def allocate_arrays(self):
        self.nodes = [self.NODE() for _ in range(self.n + 2)]
        self.arcs = [self.ARC() for _ in range(2 * self.m + 1)]
        self.cap = [0] * (2 * self.m)
        self.arc_tail = [0] * (2 * self.m)
        self.arc_first = [0] * (self.n + 2)
        self.buckets = [self.BUCKET() for _ in range(self.linf)]
        self.l_bucket = self.buckets + self.linf
        self.d_arc = self.ARC()
        self.d_node = self.NODE()
        self.dummy_node = self.NODE()
        self.node_balance = [0] * (self.n + 1)
        self.arc_current = self.arcs
        self.arc_new = None
        self.arc_tmp = None

    def deallocate_arrays(self):
        self.nodes = None
        self.arcs = None
        self.cap = None
        self.arc_tail = None
        self.arc_first = None
        self.buckets = None
        self.l_bucket = None
        self.node_balance = None

    def set_arc(self, tail_node_id, head_node_id, low_bound, up_bound, cost):
        if tail_node_id < 0 or tail_node_id > self.n or head_node_id < 0 or head_node_id > self.n:
            self.err_end(1)
        if up_bound < 0:
            up_bound = sys.maxsize
        if low_bound < 0 or low_bound > up_bound:
            self.err_end(1)
        self.arc_first[tail_node_id + 1] += 1
        self.arc_first[head_node_id + 1] += 1
        i_node = self.nodes[tail_node_id]
        j_node = self.nodes[head_node_id]
        self.arc_tail[self.pos_current] = tail_node_id
        self.arc_tail[self.pos_current + 1] = head_node_id
        self.arc_current.rez_capacity = up_bound - low_bound
        self.cap[self.pos_current] = up_bound
        self.arc_current.cost = cost
        self.arc_current.sister = self.arc_current + 1
        self.arc_current.head = j_node
        self.arc_current.sister.rez_capacity = 0
        self.cap[self.pos_current + 1] = 0
        self.arc_current.sister.cost = -cost
        self.arc_current.sister.sister = self.arc_current
        i_node.excess -= low_bound
        j_node.excess += low_bound
        if head_node_id < self.node_min:
            self.node_min = head_node_id
        if tail_node_id < self.node_min:
            self.node_min = tail_node_id
        if head_node_id > self.node_max:
            self.node_max = head_node_id
        if tail_node_id > self.node_max:
            self.node_max = tail_node_id
        if cost < 0:
            cost = -cost
        if cost > self.max_cost and up_bound > 0:
            self.max_cost = cost
        self.arc_current += 2
        self.pos_current += 2

    def set_supply_demand_of_node(self, id, excess):
        if id < 0 or id > self.n:
            self.err_end(1)
        self.nodes[id].excess = excess
        if excess > 0:
            self.total_p += excess
        if excess < 0:
            self.total_n -= excess

    def pre_processing(self):
        self.arc_first = [0] * (self.n + 2)
        self.arc_tail = [0] * (2 * self.m)
        for i_node in self.nodes:
            i_node.excess = 0
        if self.nodes is None or self.arcs is None or self.arc_first is None or self.arc_tail is None:
            self.err_end(1)
        for i_node in self.nodes:
            i_node.first = self.arcs
        if self.nodes is None or self.arcs is None or self.arc_first is None or self.arc_tail is None:
            self.err_end(1)
        for i_node in self.nodes:
            i_node.current = i_node.first
            i_node.suspended = i_node.first
            i_node.q_next = self.sentinel_node
        self.sentinel_node.first = self.sentinel_arc
        self.sentinel_node.suspended = self.sentinel_arc
        self.sentinel_node.q_next = self.sentinel_node
        for i_node in self.nodes:
            for a in i_node.first:
                a.rez_capacity = 0
                a.cost = 0
                a.head = None
                a.sister = None
        for i_node in self.nodes:
            for a in i_node.first:
                a.rez_capacity = 0
                a.cost = 0
                a.head = None
                a.sister = None
        for i_node in self.nodes:
            for a in i_node.first:
                a.rez_capacity = 0
                a.cost = 0
                a.head = None
                a.sister = None