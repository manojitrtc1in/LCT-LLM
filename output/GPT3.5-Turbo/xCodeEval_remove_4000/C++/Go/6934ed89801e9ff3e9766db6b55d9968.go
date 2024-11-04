package main

import (
	"fmt"
)

type id32 struct {
	n, m, _n, _m, _linf, id16, _epsilon, _max_cost int
	_nodes                                         []*NODE
	_arcs                                          []*ARC
	_cap                                           []int
	_arc_tail                                      []int
	_arc_first                                     []int
	_dummy_node                                    *NODE
	_buckets                                       []*BUCKET
	_l_bucket                                      *BUCKET
	_flag_price, id29, id0                         int
	_price_min, _mmc, _f_scale, id18, _cut_on       float64
	id23                                           int
	_n_rel, _n_ref, _n_src, _n_push, id24, id17     int
	_n_update, _n_scan, id6, id34, id27, id15, id7   int
	id3                                            int
	id2, _check_solution, id1, _cost_restart        bool
	_node_balance                                  []int
	_node_min, _node_max                           int
	_pos_current                                   int
	_arc_current, _arc_new, _arc_tmp                *ARC
	_max_cost, _total_p, _total_n                   int
	_i_node, _j_node                               *NODE
}

type NODE struct {
	_excess   int
	_price    float64
	_first    *ARC
	_current  *ARC
	_suspended *ARC
	_q_next   *NODE
	_b_next   *NODE
	_b_prev   *NODE
	_rank     int
	_inp      int
}

type ARC struct {
	id5     int
	_cost   float64
	_head   *NODE
	_sister *ARC
}

type BUCKET struct {
	_p_first *NODE
}

func (id8 *id32) err_end(cc int) {
	fmt.Println(cc)
}

func (id8 *id32) allocate_arrays() {
	_nodes = make([]*NODE, _n+2)
	_arcs = make([]*ARC, 2*_m+1)
	_cap = make([]int, 2*_m)
	_arc_tail = make([]int, 2*_m)
	_arc_first = make([]int, _n+2)

	for i := range _nodes {
		_nodes[i] = &NODE{}
		_nodes[i].set_excess(0)
	}
	if _nodes == nil || _arcs == nil || _arc_first == nil || _arc_tail == nil {
		id8.err_end(1)
	}
	_pos_current = 0
	_arc_current = _arcs
	_node_max = 0
	_node_min = _n
	_max_cost = 0
	_total_p = 0
	_total_n = 0
}

func (id8 *id32) deallocate_arrays() {
	if _arcs != nil {
		_arcs = nil
	}
	if _dnode != nil {
		_dnode = nil
	}
	if _cap != nil {
		_cap = nil
	}
	if _buckets != nil {
		_buckets = nil
	}
	if _check_solution == true {
		_node_balance = nil
	}
	if _nodes != nil {
		_nodes = _nodes - _node_min
		_nodes = nil
	}
}

func (id8 *id32) set_arc(id10, id28, low_bound, up_bound int, cost float64) {
	if id10 < 0 || id10 > _n || id28 < 0 || id28 > _n {
		id8.err_end(1)
	}
	if up_bound < 0 {
		up_bound = id9
	}
	if low_bound < 0 || low_bound > up_bound {
		id8.err_end(1)
	}

	_arc_first[id10+1]++
	_arc_first[id28+1]++
	_i_node = _nodes + id10
	_j_node = _nodes + id28

	_arc_tail[_pos_current] = id10
	_arc_tail[_pos_current+1] = id28
	_arc_current.set_head(_j_node)
	_arc_current.set_rez_capacity(up_bound - low_bound)
	_cap[_pos_current] = up_bound
	_arc_current.set_cost(cost)
	_arc_current.set_sister(_arc_current + 1)
	(_arc_current + 1).set_head(_nodes + id10)
	(_arc_current + 1).set_rez_capacity(0)
	_cap[_pos_current+1] = 0
	(_arc_current + 1).set_cost(-cost)
	(_arc_current + 1).set_sister(_arc_current)

	_i_node.dec_excess(low_bound)
	_j_node.inc_excess(low_bound)

	if id28 < _node_min {
		_node_min = id28
	}
	if id10 < _node_min {
		_node_min = id10
	}
	if id28 > _node_max {
		_node_max = id28
	}
	if id10 > _node_max {
		_node_max = id10
	}

	if cost < 0 {
		cost = -cost
	}
	if cost > _max_cost && up_bound > 0 {
		_max_cost = cost
	}

	_arc_current += 2
	_pos_current += 2
}

func (id8 *id32) set_supply_demand_of_node(id int, excess int) {
	if id < 0 || id > _n {
		id8.err_end(1)
	}
	(_nodes + id).set_excess(excess)
	if excess > 0 {
		_total_p += excess
	}
	if excess < 0 {
		_total_n -= excess
	}
}

func (id8 *id32) pre_processing() {
	_nodes = _nodes + _node_min
	_n = _node_max - _node_min + 1
}

func (id8 *id32) cs2_initialize() {
	_epsilon = _mmc
	_linf = (long)(_dn * ceil(_f_scale) + 2)
	_buckets = make([]*BUCKET, _linf)
	_l_bucket = _buckets + _linf
	_dnode = &NODE{}
	_n_rel = 0
	_flag_price = 0
	_dummy_node = &_d_node
	id14 = nil
}

func (id8 *id32) cs2_cost_restart(objective_cost *float64) {
	id8.cs_cost_reinit()
	id8.cs2(objective_cost)
}

func (id8 *id32) cs_cost_reinit() {
	_n_ref = 0
	id22 = 0
	id17 = 0
	_n_push = 0
	id24 = 0
	id27 = 0
	id15 = 0
	id7 = 0
	id3 = 0
	id6 = 0
	id34 = 0
	_flag_price = 0
	id14 = nil
}

func (id8 *id32) cs2(objective_cost *float64) {
	id8.run_cs2()
}

func (id8 *id32) run_cs2() {
	id8.pre_processing()
	id8.cs2_initialize()
	id8.cs2_cost_restart()
}

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	grid := make([][]int, n)
	for i := 0; i < n; i++ {
		grid[i] = make([]int, m)
		for j := 0; j < m; j++ {
			fmt.Scan(&grid[i][j])
		}
	}
	a, b, c := []int{}, []int{}, []int{}
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if (i+j)%2 == 1 {
				if i > 0 {
					a = append(a, f(i, j))
					b = append(b, f(i-1, j))
					c = append(c, grid[i][j] != grid[i-1][j])
				}
				if j > 0 {
					a = append(a, f(i, j))
					b = append(b, f(i, j-1))
					c = append(c, grid[i][j] != grid[i][j-1])
				}
				if i+1 < n {
					a = append(a, f(i, j))
					b = append(b, f(i+1, j))
					c = append(c, grid[i][j] != grid[i+1][j])
				}
				if j+1 < m {
					a = append(a, f(i, j))
					b = append(b, f(i, j+1))
					c = append(c, grid[i][j] != grid[i][j+1])
				}
			}
		}
	}
	numNodes := n * m * 4
	id13 := len(a)

	id8 := &id32{n: numNodes, m: id13}
	for i := 0; i < id13; i++ {
		id8.set_arc(a[i], b[i], 0, 1, float64(c[i]))
	}
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if (i+j)%2 == 1 {
				id8.set_supply_demand_of_node(f(i, j), 1)
			} else {
				id8.set_supply_demand_of_node(f(i, j), -1)
			}
		}
	}
	id8.run_cs2()
}
