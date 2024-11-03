package main

import (
	"fmt"
)

type id32 struct {
	n, m         int
	cap          []int
	nodes        []*node
	id31, id14   *node
	id30         *node
	arcs         []*arc
	id26         *arc
	buckets      []*bucket
	l_bucket     *bucket
	linf         int
	id16         int
	epsilon      int
	dn           int
	price_min    int
	mmc          int
	f_scale      float64
	id18         float64
	cut_on       float64
	cut_off      float64
	id23         int
	flag_price   int
	id29         int
	id0          int
	d_arc        arc
	d_node       node
	dummy_node   *node
	dnode        *node
	n_rel        int
	n_ref        int
	n_src        int
	n_push       int
	id24         int
	id17         int
	id22         int
	n_update     int
	n_scan       int
	id6          int
	id34         int
	id27         int
	id15         int
	id7          int
	id3          int
	id2          bool
	check_solution bool
	id1          bool
	cost_restart bool
	print_ans    bool
	node_balance []int
	node_min     int
	node_max     int
	arc_first    []int
	arc_tail     []int
	pos_current  int
	arc_current  *arc
	arc_new      *arc
	arc_tmp      *arc
	max_cost     int
	total_p      int
	total_n      int
	i_node       *node
	j_node       *node
}

type node struct {
	excess   int
	price    int
	first    *arc
	current  *arc
	suspended *arc
	q_next   *node
	b_next   *node
	b_prev   *node
	rank     int
	inp      int
}

type arc struct {
	id5     int
	cost    int
	head    *node
	sister  *arc
}

type bucket struct {
	p_first *node
}

func (g *id32) err_end(cc int) {
	fmt.Println(cc)
}

func (g *id32) allocate_arrays() {
	g.nodes = make([]*node, g.n+2)
	g.arcs = make([]*arc, 2*g.m+1)
	g.cap = make([]int, 2*g.m)
	g.arc_tail = make([]int, 2*g.m)
	g.arc_first = make([]int, g.n+2)

	for i := 0; i <= g.n; i++ {
		g.nodes[i] = &node{}
		g.nodes[i].excess = 0
	}

	if g.nodes == nil || g.arcs == nil || g.arc_first == nil || g.arc_tail == nil {
		g.err_end(1)
	}

	g.pos_current = 0
	g.arc_current = g.arcs

	g.node_max = 0
	g.node_min = g.n
	g.max_cost = 0
	g.total_p = 0
	g.total_n = 0
}

func (g *id32) deallocate_arrays() {
	if g.arcs != nil {
		g.arcs = nil
	}
	if g.dnode != nil {
		g.dnode = nil
	}
	if g.cap != nil {
		g.cap = nil
	}
	if g.buckets != nil {
		g.buckets = nil
	}
	if g.check_solution == true {
		g.node_balance = nil
	}
	if g.nodes != nil {
		g.nodes = g.nodes[g.node_min:]
		g.nodes = nil
	}
}

func (g *id32) set_arc(id10, id28, low_bound, up_bound, cost int) {
	if id10 < 0 || id10 > g.n || id28 < 0 || id28 > g.n {
		g.err_end(1)
	}
	if up_bound < 0 {
		up_bound = id9
	}
	if low_bound < 0 || low_bound > up_bound {
		g.err_end(1)
	}

	g.arc_first[id10+1]++
	g.arc_first[id28+1]++
	g.i_node = g.nodes[id10]
	g.j_node = g.nodes[id28]

	g.arc_tail[g.pos_current] = id10
	g.arc_tail[g.pos_current+1] = id28
	g.arc_current.head = g.j_node
	g.arc_current.rez_capacity = up_bound - low_bound
	g.cap[g.pos_current] = up_bound
	g.arc_current.cost = cost
	g.arc_current.sister = g.arc_current + 1
	g.arc_current.sister.head = g.nodes[id10]
	g.arc_current.sister.rez_capacity = 0
	g.cap[g.pos_current+1] = 0
	g.arc_current.sister.cost = -cost
	g.arc_current.sister.sister = g.arc_current

	g.i_node.excess -= low_bound
	g.j_node.excess += low_bound

	if id28 < g.node_min {
		g.node_min = id28
	}
	if id10 < g.node_min {
		g.node_min = id10
	}
	if id28 > g.node_max {
		g.node_max = id28
	}
	if id10 > g.node_max {
		g.node_max = id10
	}

	if cost < 0 {
		cost = -cost
	}
	if cost > g.max_cost && up_bound > 0 {
		g.max_cost = cost
	}

	g.arc_current += 2
	g.pos_current += 2
}

func (g *id32) set_supply_demand_of_node(id, excess int) {
	if id < 0 || id > g.n {
		g.err_end(1)
	}
	g.nodes[id].excess = excess
	if excess > 0 {
		g.total_p += excess
	}
	if excess < 0 {
		g.total_n -= excess
	}
}

func (g *id32) pre_processing() {
	g.arc_first[0] = 0

	for i := 0; i < g.n; i++ {
		g.arc_first[i+1] += g.arc_first[i]
		g.nodes[i+1].first = g.arcs + g.arc_first[i]
	}

	for i := 0; i < g.node_max; i++ {
		last := g.nodes[i+1].first - g.arcs
		for arc_num := g.arc_first[i]; arc_num < last; arc_num++ {
			id10 := g.arc_tail[arc_num]

			for id10 != i {
				id20 := g.arc_first[id10]
				g.arc_current = g.arcs + arc_num
				arc_new := g.arcs + id20

				head_p := arc_new.head
				arc_new.head = g.arc_current.head
				g.arc_current.head = head_p

				up_bound := g.cap[id20]
				g.cap[id20] = g.cap[arc_num]
				g.cap[arc_num] = up_bound

				up_bound = arc_new.rez_capacity
				arc_new.rez_capacity = g.arc_current.rez_capacity
				g.arc_current.rez_capacity = up_bound

				cost := arc_new.cost
				arc_new.cost = g.arc_current.cost
				g.arc_current.cost = cost

				if arc_new != g.arc_current.sister {
					arc_tmp := arc_new.sister
					arc_new.sister = g.arc_current.sister
					g.arc_current.sister = arc_tmp

					g.arc_current.sister.sister = g.arc_current
					arc_new.sister.sister = arc_new
				}

				g.arc_tail[arc_num] = g.arc_tail[id20]
				g.arc_tail[id20] = id10

				g.arc_first[id10]++

				id10 = g.arc_tail[arc_num]
			}
		}
	}

	g.n = g.node_max - g.node_min + 1
	g.nodes = g.nodes[g.node_min:]

	g.deallocate_arrays()
}

func (g *id32) run_cs2() {
	g.pre_processing()
	g.cs2_initialize()
	g.cs2_cost_restart(nil)
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
	a, b, c := make([]int, 0), make([]int, 0), make([]int, 0)
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

	id8 := id32{n: numNodes, m: id13}
	for i := 0; i < id13; i++ {
		id8.set_arc(a[i], b[i], 0, 1, c[i])
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
