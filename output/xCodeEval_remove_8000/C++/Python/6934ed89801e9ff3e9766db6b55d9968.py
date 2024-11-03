import sys

class id32:
    def __init__(self, num_nodes, id13):
        self._n = num_nodes
        self._m = id13
        self._nodes = []
        self._arcs = []
        self._cap = []
        self._arc_tail = []
        self._arc_first = []
        self._pos_current = 0
        self._arc_current = None
        self._node_max = 0
        self._node_min = num_nodes
        self._max_cost = 0
        self._total_p = 0
        self._total_n = 0
        self._i_node = None
        self._j_node = None
        self._buckets = []
        self._l_bucket = []
        self._epsilon = 0
        self._price_min = 0
        self._mmc = 0
        self._f_scale = 0
        self._cut_on = 0
        self._cut_off = 0
        self._node_balance = []
        self._node_min = 0
        self._node_max = 0
        self._arc_first = []
        self._arc_tail = []
        self._pos_current = 0
        self._arc_current = None
        self._arc_new = None
        self._arc_tmp = None
        self._max_cost = 0
        self._total_p = 0
        self._total_n = 0
        self._i_node = None
        self._j_node = None
        self._n_rel = 0
        self._n_ref = 0
        self._n_src = 0
        self._n_push = 0
        self._n_update = 0
        self._n_scan = 0
        self._n_rel = 0
        self._n_ref = 0
        self._n_src = 0
        self._n_push = 0
        self._n_update = 0
        self._n_scan = 0
        self._flag_price = 0
        self._check_solution = False
        self._cost_restart = False
        self._print_ans = True
        self._d_arc = None
        self._d_node = None
        self._dummy_node = None
        self._n_rel = 0
        self._n_ref = 0
        self._n_src = 0
        self._n_push = 0
        self._n_update = 0
        self._n_scan = 0
        self._flag_price = 0
        self._check_solution = False
        self._cost_restart = False
        self._print_ans = True
        self._node_balance = []
        self._node_min = 0
        self._node_max = 0
        self._arc_first = []
        self._arc_tail = []
        self._pos_current = 0
        self._arc_current = None
        self._arc_new = None
        self._arc_tmp = None
        self._max_cost = 0
        self._total_p = 0
        self._total_n = 0
        self._i_node = None
        self._j_node = None

    def err_end(self, cc):
        sys.exit(cc)

    def allocate_arrays(self):
        self._nodes = [None] * (self._n + 2)
        self._arcs = [None] * (2 * self._m + 1)
        self._cap = [0] * (2 * self._m)
        self._arc_tail = [0] * (2 * self._m)
        self._arc_first = [0] * (self._n + 2)
        for i in range(self._n + 2):
            self._nodes[i] = self.NODE()
        self._d_arc = self.ARC()
        self._d_node = self.NODE()
        self._dummy_node = self.NODE()
        self._n_rel = 0
        self._n_ref = 0
        self._n_src = 0
        self._n_push = 0
        self._n_update = 0
        self._n_scan = 0
        self._flag_price = 0
        self._check_solution = False
        self._cost_restart = False
        self._print_ans = True
        self._node_balance = []
        self._node_min = 0
        self._node_max = 0
        self._arc_first = []
        self._arc_tail = []
        self._pos_current = 0
        self._arc_current = None
        self._arc_new = None
        self._arc_tmp = None
        self._max_cost = 0
        self._total_p = 0
        self._total_n = 0
        self._i_node = None
        self._j_node = None

    def deallocate_arrays(self):
        self._nodes = []
        self._arcs = []
        self._cap = []
        self._arc_tail = []
        self._arc_first = []
        self._buckets = []
        self._l_bucket = []
        self._node_balance = []

    def set_arc(self, id10, id28, low_bound, up_bound, cost):
        if id10 < 0 or id10 > self._n or id28 < 0 or id28 > self._n:
            self.err_end(1)
        if up_bound < 0:
            up_bound = self.id9
        if low_bound < 0 or low_bound > up_bound:
            self.err_end(1)
        self._arc_first[id10 + 1] += 1
        self._arc_first[id28 + 1] += 1
        self._i_node = self._nodes[id10]
        self._j_node = self._nodes[id28]
        self._arc_tail[self._pos_current] = id10
        self._arc_tail[self._pos_current + 1] = id28
        self._arc_current.set_head(self._j_node)
        self._arc_current.set_rez_capacity(up_bound - low_bound)
        self._cap[self._pos_current] = up_bound
        self._arc_current.set_cost(cost)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
        self._arc_current.set_sister(self._arc_current + 1)
