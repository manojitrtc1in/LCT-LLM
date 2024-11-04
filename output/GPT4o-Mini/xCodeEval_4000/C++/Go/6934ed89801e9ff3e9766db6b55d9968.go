package main

import (
	"fmt"
	"math"
)

const (
	MAX_64          = 0x7fffffffffffffff
	MAX_32          = 0x7fffffff
	PRICE_MAX       = MAX_64
	ARC_FIELDS      = 5
	NODE_FIELDS     = 2
	P_FIELDS        = 3
	PROBLEM_TYPE    = "min"
	UNFEASIBLE      = 2
	ALLOCATION_FAULT = 5
	PRICE_OFL       = 6
	UPDT_FREQ       = 0.4
	UPDT_FREQ_S     = 30
	SCALE_DEFAULT    = 12.0
	PRICE_OUT_START = 1
	CUT_OFF_POWER   = 0.44
	CUT_OFF_COEF    = 1.5
	CUT_OFF_POWER2  = 0.75
	CUT_OFF_COEF2   = 1
	CUT_OFF_GAP     = 0.8
	CUT_OFF_MIN     = 12
	CUT_OFF_INCREASE = 4
	TIME_FOR_PRICE_IN1 = 2
	TIME_FOR_PRICE_IN2 = 4
	TIME_FOR_PRICE_IN3 = 6
	MAX_CYCLES_CANCELLED = 0
	START_CYCLE_CANCEL = 100
)

type excess_t int64
type price_t int64

type ARC struct {
	rez_capacity int64
	cost         price_t
	head         *NODE
	sister       *ARC
}

func (a *ARC) set_rez_capacity(rez_capacity int64) { a.rez_capacity = rez_capacity }
func (a *ARC) dec_rez_capacity(delta int64)        { a.rez_capacity -= delta }
func (a *ARC) inc_rez_capacity(delta int64)        { a.rez_capacity += delta }
func (a *ARC) set_cost(cost price_t)                { a.cost = cost }
func (a *ARC) multiply_cost(mult price_t)          { a.cost *= mult }
func (a *ARC) set_head(head *NODE)                  { a.head = head }
func (a *ARC) set_sister(sister *ARC)               { a.sister = sister }

func (a *ARC) rez_capacity() int64 { return a.rez_capacity }
func (a *ARC) cost() price_t        { return a.cost }
func (a *ARC) head() *NODE          { return a.head }
func (a *ARC) sister() *ARC          { return a.sister }

type NODE struct {
	excess     excess_t
	price      price_t
	first      *ARC
	current    *ARC
	suspended  *ARC
	q_next     *NODE
	b_next     *NODE
	b_prev     *NODE
	rank       int64
	inp        int64
}

func (n *NODE) set_excess(excess excess_t) { n.excess = excess }
func (n *NODE) dec_excess(delta int64)      { n.excess -= excess_t(delta) }
func (n *NODE) inc_excess(delta int64)      { n.excess += excess_t(delta) }
func (n *NODE) set_price(price price_t)     { n.price = price }
func (n *NODE) dec_price(delta int64)       { n.price -= price_t(delta) }
func (n *NODE) set_first(first *ARC)        { n.first = first }
func (n *NODE) set_current(current *ARC)    { n.current = current }
func (n *NODE) inc_current()                 { n.current = n.current.sister() }
func (n *NODE) set_suspended(suspended *ARC) { n.suspended = suspended }
func (n *NODE) set_q_next(q_next *NODE)     { n.q_next = q_next }
func (n *NODE) set_b_next(b_next *NODE)     { n.b_next = b_next }
func (n *NODE) set_b_prev(b_prev *NODE)     { n.b_prev = b_prev }
func (n *NODE) set_rank(rank int64)          { n.rank = rank }
func (n *NODE) set_inp(inp int64)            { n.inp = inp }

func (n *NODE) excess() excess_t { return n.excess }
func (n *NODE) price() price_t    { return n.price }
func (n *NODE) first() *ARC       { return n.first }
func (n *NODE) current() *ARC      { return n.current }
func (n *NODE) suspended() *ARC    { return n.suspended }
func (n *NODE) q_next() *NODE      { return n.q_next }
func (n *NODE) b_next() *NODE      { return n.b_next }
func (n *NODE) b_prev() *NODE      { return n.b_prev }
func (n *NODE) rank() int64        { return n.rank }
func (n *NODE) inp() int64         { return n.inp }

type BUCKET struct {
	p_first *NODE
}

func (b *BUCKET) set_p_first(p_first *NODE) { b.p_first = p_first }
func (b *BUCKET) p_first() *NODE             { return b.p_first }

type MCMF_CS2 struct {
	n, m                     int64
	cap                      []int64
	nodes                    []*NODE
	sentinel_node            *NODE
	excq_first, excq_last    *NODE
	arcs                     []*ARC
	sentinel_arc             *ARC
	buckets                  []*BUCKET
	l_bucket                 *BUCKET
	linf                     int64
	time_for_price_in        int
	epsilon                  price_t
	dn                       price_t
	price_min                price_t
	mmc                      price_t
	f_scale                  float64
	cut_off_factor           float64
	cut_on                   float64
	cut_off                  float64
	total_excess             excess_t
	flag_price               int
	flag_updt                int
	snc_max                  int
	d_arc                    ARC
	d_node                   NODE
	dummy_node               *NODE
	dnode                    *NODE
	n_rel, n_ref, n_src      int64
	n_push, n_relabel        int64
	n_discharge, n_refine    int64
	n_update, n_scan         int64
	n_prscan, n_prscan1      int64
	n_prscan2, n_bad_pricein int64
	n_bad_relabel            int64
	n_prefine                int64
	no_zero_cycles           bool
	check_solution           bool
	comp_duals               bool
	cost_restart             bool
	print_ans                bool
	node_balance             []int64
	node_min, node_max       int64
	arc_first                []int64
	arc_tail                 []int64
	pos_current              int64
	arc_current, arc_new     *ARC
	arc_tmp                  *ARC
	max_cost                 price_t
	total_p, total_n         excess_t
	i_node, j_node           *NODE
}

func (m *MCMF_CS2) err_end(cc int) {
	// Handle error
}

func (m *MCMF_CS2) allocate_arrays() {
	m.nodes = make([]*NODE, m.n+2)
	m.arcs = make([]*ARC, 2*m.m+1)
	m.cap = make([]int64, 2*m.m)

	m.arc_tail = make([]int64, 2*m.m)
	m.arc_first = make([]int64, m.n+2)

	for in := m.nodes; in < m.nodes+m.n; in++ {
		in.set_excess(0)
	}
	if m.nodes == nil || m.arcs == nil || m.arc_first == nil || m.arc_tail == nil {
		// Handle allocation failure
	}

	m.pos_current = 0
	m.arc_current = m.arcs[0]
	m.node_max = 0
	m.node_min = m.n
	m.max_cost = 0
	m.total_p = 0
	m.total_n = 0
}

func (m *MCMF_CS2) deallocate_arrays() {
	// Free allocated arrays
}

func (m *MCMF_CS2) set_arc(tail_node_id, head_node_id int64, low_bound, up_bound int64, cost price_t) {
